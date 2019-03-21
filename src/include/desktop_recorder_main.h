#ifndef DESKTOP_RECORDER_MAIN_H_
#define DESKTOP_RECORDER_MAIN_H_

#include <QWidget>
#include "../include/desktop_recorder.h"

namespace Ui {
    class DesktopRecorderMain;
}

class DesktopRecorderMain : public QWidget
{
    Q_OBJECT

public:
    explicit DesktopRecorderMain(QWidget* parent = 0);
    ~DesktopRecorderMain();

private slots:
    void OnStartStop();
    void OnFrameAvailable(const QImage&);

private:
    Ui::DesktopRecorderMain* ui_;
    DesktopRecorder recorder_;
};

#endif // DESKTOP_RECORDER_MAIN_H
