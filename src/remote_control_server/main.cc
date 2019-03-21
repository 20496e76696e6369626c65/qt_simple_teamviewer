#include <QApplication>

#include "../include/remote_control_server.h"

int main( int argc, char* argv[] ) {
    QApplication a( argc, argv );

    RemoteControlServer server;
    if( !server.Start() ) {
        qDebug() << "Server failed to start";
        return 1;
    }

    qDebug() << "Server started";

    return a.exec();
}
