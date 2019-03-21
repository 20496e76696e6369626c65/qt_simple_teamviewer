#include "../include/desktop_recorder_main.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DesktopRecorderMain w;
    w.resize(800,600);
    w.show();
    return a.exec();
}
