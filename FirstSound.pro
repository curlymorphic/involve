#-------------------------------------------------
#
# Project created by QtCreator 2014-12-25T06:36:28
#
#-------------------------------------------------

QT       += multimedia widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FirstSound
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    AudioDevice.cpp \
    AudioProcess.cpp \
    Oscillator.cpp \
    AudioModule.cpp \
    Model.cpp \
    Fader.cpp \
    Controls.cpp \
    AudioDeviceControls.cpp \
    AudioDeviceView.cpp \
    AudioThread.cpp \
    Demo1ModuleControls.cpp \
    Demo1AudioModule.cpp \
    ModuleView.cpp \
    Demo1ModuleView.cpp \
    Gain.cpp \
    Lfo.cpp \
    Filters.cpp \
    Ribbon.cpp

HEADERS  += MainWindow.h \
    Types.h \
    AudioDevice.h \
    AudioProcess.h \
    Oscillator.h \
    AudioModule.h \
    Model.h \
    Fader.h \
    Controls.h \
    AudioDeviceControls.h \
    AudioDeviceView.h \
    AudioThread.h \
    ModuleControls.h \
    Demo1ModuleControls.h \
    Demo1AudioModule.h \
    ModuleView.h \
    Demo1ModuleView.h \
    Gain.h \
    Lfo.h \
    Filters.h \
    Ribbon.h

FORMS    += MainWindow.ui
