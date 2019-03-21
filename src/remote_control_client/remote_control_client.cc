#include "../include/remote_control_client.h"
#include "ui_remote_control_client_widget.h"
#include "../include/shared_defs.h"

#include <QMouseEvent>
#include <QWheelEvent>

static const int kConnectionRetryTimeOutMSec = 2000;
static const int kMouseFPS = 10;

RemoteControlClient::RemoteControlClient(QWidget *parent): QWidget(parent),
                                                           ui_(new Ui::RemoteControlClientWidget),
                                                           connected_(false),
                                                           mouse_moved_(false)
{
    ui_->setupUi(this);
    ui_->stop_btn->hide();

    connect(ui_->start_btn, SIGNAL( clicked(bool)), SLOT(OnStartStop()));
    connect(ui_->stop_btn, SIGNAL( clicked(bool)), SLOT(OnStartStop()));

    connect(&peer_, SIGNAL(connectedToServer()), SLOT(OnConnectedToServer()));
    connect(&peer_, SIGNAL(disconnectedFromServer()), SLOT(OnDisconnectedFromServer()));
    connect(&peer_, SIGNAL(serverError(QAbstractSocket::SocketError&)),
                    SLOT(OnServerError(QAbstractSocket::SocketError&)));

    peer_.attachSlot(FRAME_AVAILABLE_SIG, this, SLOT(OnFrameAvailable(QByteArray,QSize)));
    peer_.attachSignal(ui_->capture_cursor_chk_box, SIGNAL(clicked(bool)), ENABLE_CURSOR_CAPTURE_SIG);

    setMouseTracking(true);

    ui_->view_lbl->setMouseTracking(true);

    connect(&mouse_move_timer_, SIGNAL(timeout()), SLOT(OnMouseMoveTimeOut()));
    mouse_move_timer_.start(1000/ kMouseFPS);

    setFocusPolicy(Qt::StrongFocus);

}

RemoteControlClient::~RemoteControlClient()
{
    delete ui_;
}

void RemoteControlClient::mouseMoveEvent(QMouseEvent *event)
{
    if(connected_)
    {
        auto pos = ToRealPos( event->pos());
        mouse_moved_ = (mouse_pos_ != pos);
        mouse_pos_ = pos;
    }
}

void RemoteControlClient::mousePressEvent(QMouseEvent *event)
{
    if(connected_)
    {
        mouse_pos_ = ToRealPos( event->pos());
        peer_.call(MOUSE_PRESS_SIG, mouse_pos_, event->button());
    }
}

void RemoteControlClient::mouseReleaseEvent(QMouseEvent *event)
{
    if(connected_)
    {
        mouse_pos_ = ToRealPos( event->pos());
        peer_.call(MOUSE_RELEASE_SIG, mouse_pos_, event->button());
    }
}

void RemoteControlClient::wheelEvent(QWheelEvent *event)
{
    if(connected_)
    {
        peer_.call(MOUSE_WHEEL_SIG, event->delta());
    }
}

void RemoteControlClient::keyPressEvent(QKeyEvent *event)
{
    if(connected_)
    {
        peer_.call(KEY_PRESS_SIG, event->key(), event->text());
    }
}

void RemoteControlClient::keyReleaseEvent(QKeyEvent *event)
{
    if(connected_)
    {
        peer_.call(KEY_RELEASE_SIG, event->key(), event->text());
    }
}

QPoint RemoteControlClient::ToRealPos(const QPoint& mouse_pos)
{
    auto real_pos = ui_->view_lbl->mapFromParent(mouse_pos);

        if( ui_->view_lbl->pixmap() ) {
            auto view_rect = ui_->view_lbl->rect();
            auto img_rect =  ui_->view_lbl->pixmap()->rect();

            auto xOffset = ( view_rect.width() - img_rect.width() ) / 2;
            auto yOffset = ( view_rect.height() - img_rect.height() ) / 2;

            real_pos = QPoint( real_pos.x() - xOffset,  real_pos.y() - yOffset );

            if( real_pos.x() < 0 )  real_pos.setX( 0 );
            if( real_pos.y() < 0 )  real_pos.setY( 0 );

            if( img_rect.width() != 0 ) {
                auto ratio = real_frame_size_.width() / static_cast< double >( img_rect.width() );
                real_pos.setX( real_pos.x() * ratio );
                real_pos.setY( real_pos.y() * ratio );

                if( real_frame_size_.width() < real_pos.x() )  real_pos.setX( real_frame_size_.width() );
                if( real_frame_size_.height() < real_pos.y() )  real_pos.setY( real_frame_size_.height() );
            }
        }

        return real_pos;
}

void RemoteControlClient::OnStartStop()
{
    if( ui_->start_btn->isVisible() ) {
           RefreshConnection();
       } else {
           peer_.disconnectServer();
           connected_ = false;
       }

       ui_->start_btn->setVisible( !ui_->start_btn->isVisible() );
       ui_->stop_btn->setVisible( !ui_->stop_btn->isVisible() );
       ui_->ip_ed->setEnabled( !ui_->stop_btn->isVisible() );
}

void RemoteControlClient::OnFrameAvailable(const QByteArray &img_data, const QSize &real_size)
{
    real_frame_size_ = real_size;
    auto img = QImage::fromData(qUncompress(img_data), "JPG");
    ui_->view_lbl->setPixmap( QPixmap::fromImage( img ).scaled( ui_->view_lbl->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation ));
}

void RemoteControlClient::OnConnectedToServer()
{
    qDebug() << "Connected to server";
        connected_ = true;

        ui_->start_btn->setVisible( false );
        ui_->stop_btn->setVisible( true );
        ui_->ip_ed->setEnabled( false );

        peer_.call( ENABLE_CURSOR_CAPTURE_SIG, ui_->capture_cursor_chk_box->isChecked() );
}

void RemoteControlClient::OnDisconnectedFromServer()
{
    connected_ = false;
}


void RemoteControlClient::OnServerError(const QAbstractSocket::SocketError &error)
{
    qDebug() << "Server error:" << QString::number( error, 16 );
    connected_ = false;
    if(ui_->stop_btn->isVisible())
    {
        QTimer::singleShot(kConnectionRetryTimeOutMSec, this, SLOT(RefreshConnection()));
    }
}

void RemoteControlClient::RefreshConnection()
{
    if(!connected_)
    {
        peer_.connect(ui_->ip_ed->text(), PORT);
    }
}

void RemoteControlClient::OnMouseMoveTimeOut()
{
    if(mouse_moved_)
    {
        peer_.call(MOUSE_MOVE_SIG, mouse_pos_);
        mouse_moved_ = false;
    }
}



