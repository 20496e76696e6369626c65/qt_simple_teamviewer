QT += core gui widgets winextras

TARGET = desktop_recorder_main
TEMPLATE = app

SOURCES += \ 
        main.cc \
        desktop_recorder_main.cc \

HEADERS += \
        ../include/desktop_recorder_main.h \


FORMS += \
       desktop_recorder_main.ui \


include(../../common.pri)
include(../../app.pri)

LIBS += -ldesktop_recorder$${LIB_SUFFIX}

