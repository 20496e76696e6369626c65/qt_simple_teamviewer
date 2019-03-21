#ifndef DESKTOPRECORDER_H_
#define DESKTOPRECORDER_H_


#include <QObject>
#include <QTimer>

#include "desktop_recorder_global.h"

class QImage;
class QPoint;
struct Cursor;

static const uint kMinFps = 1;
static const uint kMaxFps = 100;
static const uint kDefaultFps = 20;

class DESKTOPRECORDERAPI DesktopRecorder : public QObject
{
    Q_OBJECT

public:    
    explicit DesktopRecorder( QObject* parent = 0 );

    QImage MakeScreenShot() const;
    Cursor CaptureCursor() const;

signals:
    void FrameAvailable( const QImage& );

public slots:
    void Start( uint = kDefaultFps );
    void Stop();
    void EnableCursorCpature (bool enable = true);

private slots:
    void OnTimeOut();
private:
    QTimer timer_;
    bool cursor_capture_enable_;

};

#endif // DESKTOPRECORDER_H_

