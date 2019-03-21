#include "../include/remote_control_client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RemoteControlClient w;
    w.show();

    return a.exec();
}
