QT += core gui  widgets network

TARGET = remote_control_client
TEMPLATE = app

include (../../common.pri)
include (../../app.pri)

HEADERS += \
    ../include/remote_control_client.h \
    ../include/shared_defs.h

SOURCES += \
    remote_control_client.cc \
    main.cc

FORMS += \
    remote_control_client_widget.ui


LIBS += -L$${LIBS_PATH}/LibQxt/
win32: LIBS += -lQxtCore$${LIB_SUFFIX} -lQxtNetwork$${LIB_SUFFIX}
linux-g++: LIBS += -lQxtCore -lQxtNetwork

linux-g++: QMAKE_LFLAGS += -Wl, --rpath=\\\$\$ORIGIN/../../lib.$${OS_SUFFIX}/LibQxt/
