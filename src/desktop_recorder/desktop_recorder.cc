#include "../include/desktop_recorder.h"
#include "../include/cursor.h"

#include <QApplication>
#include <QImage>
#include <QDesktopWidget>
#include <QPainter>
#include <QDebug>
#include <QPixmap>
#include <QtWin>

#ifdef Q_OS_LINUX
#include <X11/extensions/Xfixes.h>
#include <QX11Info>
#elif defined Q_OS_WIN32
#include <windows.h>
#endif



DesktopRecorder::DesktopRecorder( QObject* parent ) : QObject( parent ),
                                                      cursor_capture_enable_( false )
{
    connect( &timer_, SIGNAL( timeout() ), SLOT( OnTimeOut() ) );
}


QImage DesktopRecorder::MakeScreenShot() const
{
    auto desktop = QApplication::desktop();
    auto geometry = desktop->screenGeometry();
    auto pix = QPixmap::grabWindow( desktop->winId(), geometry.x(), geometry.y(), geometry.width(), geometry.height());

    if(cursor_capture_enable_)
    {
        auto cursor = CaptureCursor();

        if(!cursor.img.isNull())
        {
            QPainter p;
            p.begin(&pix);
            p.drawImage( cursor.pos, cursor.img );
            p.end();
        }
    }
    return pix.toImage();

}
#ifdef Q_OS_LINUX

Cursor DesktopRecorder::CaptureCursor() const
{
    Cursor cursor;
    if(auto cur_image = XFixesGetCursorImage(QX11Ingo::display()))
    {
        cursor.buffer.resize( cur_image->width* cur_image->height);
        for(int i = 0; i< cursor.buffer.size(); ++i)
        {
            cursor.buffer[i] = cur_image->pixels[i] & 0xffffffff;
        }
        cursor.img = QImage(
                             reinterpret_cast< const uchar* >( cursor.buffer.data() ),
                             cur_image->width,
                             cur_image->height,
                             QImage::Format_ARGB32_Premultiplied
                           );
        cursor.pox = QCursor::pos() - QPoint(cur_image->xhot, cur_image->yhot);
        XFree(cur_image);
    }
    return cursor;
}
#elif defined Q_OS_WIN32

QPixmap BottomPart(const QPixmap& pixmap)
{
    QSize size( pixmap.width(), pixmap.height() / 2 );
    return pixmap.copy( QRect( QPoint( 0, size.height() ), size ) );
}

Cursor DesktopRecorder::CaptureCursor() const
{

    Cursor cursor;
    CURSORINFO cursor_info = {0};
    cursor_info.cbSize = sizeof (cursor_info);

    if(GetCursorInfo(&cursor_info))
    {
        ICONINFO ii = {0};
        if(GetIconInfo( cursor_info.hCursor, &ii))
        {
            cursor.pos = QCursor::pos() - QPoint( ii.xHotspot, ii.yHotspot );

            DIBSECTION ds_bitmap;
            DIBSECTION ds_mask;

            if(GetObject(ii.hbmColor, sizeof(DIBSECTION), &ds_bitmap))
            {
                cursor.img = QtWin::fromHBITMAP(ii.hbmColor, QtWin::HBitmapPremultipliedAlpha).toImage();
            }
            else if ( GetObject(ii.hbmMask, sizeof(DIBSECTION), &ds_mask))
            {
                auto mask = QtWin::fromHBITMAP(ii.hbmMask, QtWin::HBitmapAlpha);

                cursor.img = QImage(mask.width(), mask.height()/2, QImage::Format_ARGB4444_Premultiplied);
                cursor.img.fill(Qt::black);
                QPainter p;
                p.begin(&cursor.img);
                p.setCompositionMode(QPainter::CompositionMode_DestinationIn );
                p.drawPixmap(0, 0, BottomPart(mask));
                p.end();
             }
            DeleteObject(ii.hbmColor);
            DeleteObject(ii.hbmMask);
        }
    }
    return cursor;
}
#endif
void DesktopRecorder::Start(uint fps)
{
    if( fps <kMinFps || kMaxFps < fps )
    {
        fps = kDefaultFps;
    }
    timer_.start(1000/fps);
}

void DesktopRecorder::Stop()
{
    timer_.stop();
}

void DesktopRecorder::EnableCursorCpature(bool enable)
{
    cursor_capture_enable_ = enable;
}

void DesktopRecorder::OnTimeOut()
{
    emit FrameAvailable( MakeScreenShot() );
}


