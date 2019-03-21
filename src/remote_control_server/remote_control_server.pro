QT += core gui widgets winextras network

CONFIG += c++11

TARGET = remote_control_server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    remote_control_server.cc \
    main.cc

HEADERS += \
    ../include/shared_defs.h \
    ../include/remote_control_server.h \
    ../include/key_mapper.h

include( ../../common.pri )
include( ../../app.pri )

LIBS += -ldesktop_recorder$${LIB_SUFFIX}
LIBS += -L$${LIBS_PATH}/LibQxt/ -lQxtCore -lQxtNetwork
win32 {
    LIBS += -lUser32
    SOURCES += key_mapper_win32.cc
}
linux-g++ {
    LIBS += -lQxtCore -lQxtNetwork
    LIBS += -lX11 -lXtst
    QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/../../lib.$${OS_SUFFIX}/LibQxt/
    SOURCES += key_mapper_x11.cc
}
