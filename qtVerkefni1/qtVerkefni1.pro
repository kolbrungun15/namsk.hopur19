QT += core
QT -= gui

TARGET = qtVerkefni1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    famouspersons.cpp \
    database.cpp

HEADERS += \
    famouspersons.h \
    database.h

