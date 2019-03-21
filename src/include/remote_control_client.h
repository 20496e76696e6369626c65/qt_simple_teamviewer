#ifndef REMOTE_CONTROL_CLIENT_H_
#define REMOTE_CONTROL_CLIENT_H_

#include <QWidget>
#include <QxtRPCPeer>
#include <QTimer>

namespace Ui{
class RemoteControlClientWidget;
}

class RemoteControlClient : public QWidget
{
    Q_OBJECT
public:
    explicit RemoteControlClient(QWidget* parent = 0);
    ~RemoteControlClient();

private:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

    QPoint ToRealPos(const QPoint&);

private slots:
    void OnStartStop();
    void OnFrameAvailable(const QByteArray&, const QSize&);

    void OnConnectedToServer();
    void OnDisconnectedFromServer();
    void OnServerError( const QAbstractSocket::SocketError&);
    void RefreshConnection();

    void OnMouseMoveTimeOut();

private:
    Ui::RemoteControlClientWidget * ui_;
    QxtRPCPeer peer_;
    bool connected_;
    QSize real_frame_size_;
    QPoint mouse_pos_;
    bool mouse_moved_;
    QTimer mouse_move_timer_;
};

#endif // REMOTE_CONTROL_CLIENT_H_
