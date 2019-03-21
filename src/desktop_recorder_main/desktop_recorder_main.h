#ifndef DESKTOP_RECORDER_MAIN_H
#define DESKTOP_RECORDER_MAIN_H

#include <QWidget>

#include "desktop_recorder.h"

namespace UI
{
 class DesktopRecorderMain;
}

class DesktopRecorderMain : public QWidget
{
    Q_OBJECT
public:
    explicit DesktopRecorderMain( QWidget* parent = nullptr);
    ~DesktopRecorderMain();

private slots:
    void OnStartStop();
    void OnFrameAvailable( const QImage*);

private:
    UI::DesktopRecorderMain* ui;
    DestopRecorder recorder_;
};

#endif // DESKTOP_RECORDER_MAIN_H
