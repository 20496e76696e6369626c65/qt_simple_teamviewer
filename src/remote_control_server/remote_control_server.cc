#include "../include/remote_control_server.h"
#include "../include/key_mapper.h"
#include "../include/shared_defs.h"

#include <QBuffer>
#include <QCursor>
#include <QKeyEvent>
#include <QEvent>
#include <QDesktopWidget>
#include <string>

#ifdef Q_OS_LINUX
#   include <X11/extensions/XTest.h>
#elif defined Q_OS_WIN32
#   include <windows.h>
#endif

static const QSize kScaledFrameSize = QSize( 900, 550 );


RemoteControlServer::RemoteControlServer(QObject *parent) : QObject (parent)
{
    connect( &peer_, SIGNAL( clientConnected( quint64 ) ), SLOT( OnClientConnected( quint64 ) ) );
    connect( &peer_, SIGNAL( clientDisconnected( quint64 ) ), SLOT( OnClientDisconnected( quint64 ) ) );

    connect( &recorder_, SIGNAL( FrameAvailable( QImage ) ), SLOT( OnFrameAvailable( QImage ) ) );
    peer_.attachSlot( ENABLE_CURSOR_CAPTURE_SIG, this, SLOT( OnEnableCursorCapture( quint64, bool ) ) );
    peer_.attachSlot( MOUSE_MOVE_SIG, this, SLOT( OnMouseMoveRequest( quint64, QPoint ) ) );
    peer_.attachSlot( MOUSE_PRESS_SIG, this, SLOT( OnMousePressRequest( quint64, QPoint, int ) ) );
    peer_.attachSlot( MOUSE_RELEASE_SIG, this, SLOT( OnMouseReleaseRequest( quint64, QPoint, int ) ) );
    peer_.attachSlot( MOUSE_WHEEL_SIG, this, SLOT( OnMouseWheelRequest( quint64, int ) ) );
    peer_.attachSlot( KEY_PRESS_SIG, this, SLOT( OnKeyPressRequest( quint64, int , const QString&) ) );
    peer_.attachSlot( KEY_RELEASE_SIG, this, SLOT( OnKeyReleaseRequest( quint64, int, QString ) ) );
}

bool RemoteControlServer::Start()
{
    return peer_.listen( QHostAddress::Any, PORT );
}

void RemoteControlServer::OnClientConnected(quint64 client_id)
{
    qDebug() << "Client connected" << client_id;
    recorder_.Start(10);
}

void RemoteControlServer::OnClientDisconnected(quint64 client_id)
{
    qDebug() << "Client disconnected" << client_id;
    recorder_.Stop();
}

void RemoteControlServer::OnEnableCursorCapture(quint64, bool enable)
{
    recorder_.EnableCursorCpature(enable);
}

void RemoteControlServer::OnMouseMoveRequest(quint64, const QPoint &pos)
{
    QCursor::setPos(pos);
}


#ifdef Q_OS_LINUX

void OnMouseAction( const QPoint& pos, Bool pressed, uint mouse_btn ) {
    QCursor::setPos( pos );

    Display* display = XOpenDisplay( nullptr );
    if( display == nullptr ) {
        return;
    }

    uint btn = 0;
    switch( mouse_btn ) {
    case Qt::LeftButton:
        btn = Button1;
        break;
    case Qt::RightButton:
        btn = Button3;
        break;
    case Qt::MiddleButton:
        btn = Button2;
        break;
    }

    XTestFakeButtonEvent( display, btn, pressed, CurrentTime );

    XFlush( display );
    XCloseDisplay( display );
}

void RemoteControlServer::OnMousePressRequest( quint64, const QPoint& pos, int mouse_btn )
{
    OnMouseAction( pos, True, mouse_btn );
}

void RemoteControlServer::OnMouseReleaseRequest( quint64, const QPoint& pos, int mouse_btn )
{
    OnMouseAction( pos, False, mouse_btn );
}

void RemoteControlServer::OnMouseWheelRequest( quint64, int delta )
{
    Display* display = XOpenDisplay( nullptr );
    if( display == nullptr ) {
        return;
    }

    auto btn = ( 0 <= delta ) ? Button4 : Button5;

    XTestFakeButtonEvent( display, btn, True, 0 );
    XTestFakeButtonEvent( display, btn, False, 0 );

    XFlush( display );
    XCloseDisplay( display );
}

void OnKeyAction( bool pressed, int keyCode, const QString& text )
{
    static KeyMapper key_mapper;
    static bool shiftPressed = false;

    if( keyCode == Qt::Key_Shift ) shiftPressed = pressed;

    Display* display = XOpenDisplay( nullptr );
    if( display == nullptr )
    {
        return;
    }

    uint vKeyCode = 0;
    if( ( vKeyCode = key_mapper.FindNativeVirtualKeyCode( Qt::Key( keyCode ) ) ) == 0 && !text.isEmpty() ) {
        if( shiftPressed ) onKeyAction( false, Qt::Key_Shift, "" );

        QString uSym = QString().sprintf( "U%04X", text.at( 0 ).unicode() );
        auto keySym = XStringToKeysym( uSym.toStdString().c_str() );

        int min, max, numcodes;
        XDisplayKeycodes( display, &min, &max );
        if( KeySym* keySyms = XGetKeyboardMapping( display, min, max - min + 1, &numcodes ) ) {
            keySyms[ ( max - min - 1 ) * numcodes ] = keySym;
            XChangeKeyboardMapping( display, min, numcodes, keySyms, max - min );
            XFree( keySyms );
            XFlush( display );

            vKeyCode = XKeysymToKeycode( display, keySym );
        }

        if( shiftPressed ) onKeyAction( true, Qt::Key_Shift, "" );
    }

    XTestFakeKeyEvent( display, vKeyCode, pressed, 0 );

    XFlush( display );
    XCloseDisplay( display );
}


#elif defined Q_OS_WIN32

void OnMouseAction( const QPoint& pos, int flags ) {
    QCursor::setPos( pos );

    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.mouseData = 0;
    input.mi.dwFlags = flags;
    SendInput( 1, &input, sizeof( input ) );
}

void RemoteControlServer::OnMousePressRequest( quint64, const QPoint& pos, int mouse_btn ) {
    int flags = MOUSEEVENTF_ABSOLUTE;
    switch ( mouse_btn ) {
    case Qt::LeftButton:
        flags |= MOUSEEVENTF_LEFTDOWN;
        break;
    case Qt::RightButton:
        flags |= MOUSEEVENTF_RIGHTDOWN;
        break;
    case Qt::MiddleButton:
        flags |= MOUSEEVENTF_MIDDLEDOWN;
        break;
    default:
        return;
    }
    OnMouseAction( pos, flags );
}

void RemoteControlServer::OnMouseReleaseRequest( quint64, const QPoint& pos, int mouse_btn ) {
    int flags = MOUSEEVENTF_ABSOLUTE;
    switch ( mouse_btn ) {
    case Qt::LeftButton:
        flags |= MOUSEEVENTF_LEFTUP;
        break;
    case Qt::RightButton:
        flags |= MOUSEEVENTF_RIGHTUP;
        break;
    case Qt::MiddleButton:
        flags |= MOUSEEVENTF_MIDDLEUP;
        break;
    default:
        return;
    }
    OnMouseAction( pos, flags );
}

void RemoteControlServer::OnMouseWheelRequest( quint64, int delta ) {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.mouseData = delta;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    SendInput( 1, &input, sizeof( input ) );
}

void OnKeyAction( bool pressed, int key_code, const QString& text ) {
    static KeyMapper key_mapper;

    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = pressed ? 0 : KEYEVENTF_KEYUP;
    input.ki.time = 0;
    input.ki.dwExtraInfo = static_cast< ULONG_PTR >( 0 );
    if( ( input.ki.wVk = key_mapper.FindNativeVirtualKeyCode( Qt::Key( key_code ) ) ) != 0 )
    {
        input.ki.wScan = 0;
    }
    else if( !text.isEmpty() )
    {
        input.ki.dwFlags |= KEYEVENTF_UNICODE;
        input.ki.wScan = static_cast< WORD >( text.at( 0 ).unicode() );
    }

    SendInput( 1, &input, sizeof( input ) );
}
#endif


void RemoteControlServer::OnKeyPressRequest(quint64, int key_code, const QString & text)
{
    OnKeyAction(true, key_code, text);
}

void RemoteControlServer::OnKeyReleaseRequest(quint64, int key_code, const QString &text)
{
    OnKeyAction(true, key_code, text);
}

void RemoteControlServer::OnFrameAvailable(const QImage & frame)
{
    QByteArray ba;
      QBuffer buffer( &ba );
      frame.scaled( kScaledFrameSize, Qt::KeepAspectRatio, Qt::SmoothTransformation ).save( &buffer, "JPG" );

      peer_.call( FRAME_AVAILABLE_SIG, qCompress( ba, 9 ), frame.size() );
}


