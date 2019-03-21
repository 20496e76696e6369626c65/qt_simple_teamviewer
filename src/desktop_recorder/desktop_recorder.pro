
QT += core gui widgets winextras

include(../../common.pri)
include(../../lib.pri)

TARGET = desktop_recorder$${LIB_SUFFIX}

TEMPLATE = lib

DEFINES += DESTOPRECORDER_LIBRARY

SOURCES += \
    desktop_recorder.cc

HEADERS += \
    ../include/desktop_recorder.h \
    ../include/desktop_recorder_global.h \
    ../include/cursor.h

linux-g++: LIBS += -lX11 -lXfixes
win32: LIBS += -lUser32 -lGdi32

