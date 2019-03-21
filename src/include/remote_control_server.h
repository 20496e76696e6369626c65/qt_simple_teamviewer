#ifndef REMOTE_CONTROL_SERVER_H
#define REMOTE_CONTROL_SERVER_H

#include <QObject>
#include <QxtRPCPeer>
#include <desktop_recorder.h>

class RemoteControlServer :public QObject
{
    Q_OBJECT
public:
    explicit RemoteControlServer(QObject* parent = 0);

    bool Start();

private slots:
    void OnClientConnected(quint64);
    void OnClientDisconnected( quint64 );

    void OnEnableCursorCapture( quint64, bool);

    void OnMouseMoveRequest( quint64, const QPoint& );
    void OnMousePressRequest( quint64, const QPoint& , int );
    void OnMouseReleaseRequest( quint64, const QPoint&, int);
    void OnMouseWheelRequest( quint64, int);
    void OnKeyPressRequest( quint64, int , const QString&);
    void OnKeyReleaseRequest( quint64, int , const QString&);

    void OnFrameAvailable( const QImage&);

private:
    QxtRPCPeer peer_;
    DesktopRecorder recorder_;
};

#endif // REMOTE_CONTROL_SERVER_H
