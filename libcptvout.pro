#-------------------------------------------------
#
# Project created by QtCreator 2011-01-15T21:53:53
#
#-------------------------------------------------

QT       += core gui maemo5

TARGET = libcptvout
TEMPLATE = app
target.path=/usr/local/bin
INSTALLS=target


SOURCES += main.cpp\
        tvoutdialog.cpp \
    tvoutformatpicker.cpp

HEADERS  += tvoutdialog.h \
    tvoutformatpicker.h

FORMS    += tvoutdialog.ui

CONFIG += mobility link_pkgconfig
MOBILITY = 
PKGCONFIG += gq-gconf

symbian {
    TARGET.UID3 = 0xec2877be
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
