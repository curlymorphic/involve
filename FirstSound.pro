#-------------------------------------------------
#
# Project created by QtCreator 2014-12-25T06:36:28
#
#-------------------------------------------------

QT += multimedia widgets
QT += sensors

CONFIG += mobility
MOBILITY += sensors

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FirstSound
TEMPLATE = app

INCLUDEPATH += ./headers
INCLUDEPATH += $$PWD/modules
INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/core
INCLUDEPATH += ./src/gui
INCLUDEPATH += $$PWD/src/dsp


SOURCES += main.cpp\
	src/Model.cpp \
	src/Controls.cpp \
	src/UiControls.cpp \
	src/core/AutomationSensor.cpp \
	src/core/AudioDevice.cpp \
	src/core/AudioDeviceControls.cpp \
	src/core/AudioThread.cpp \
	src/gui/MainWindow.cpp \
	src/gui/AudioDeviceView.cpp \
	src/gui/Fader.cpp \
	src/gui/Ribbon.cpp \
	src/gui/TouchController.cpp \
	src/gui/VFader.cpp \
	src/gui/VuFader.cpp \
	src/dsp/Gain.cpp \
	src/dsp/Lfo.cpp \
	src/dsp/Filters.cpp \
	src/dsp/ControlGenerator.cpp \
	src/dsp/WTOscillator.cpp \
	src/dsp/StereoDelay.cpp \
	src/dsp/AudioProcess.cpp \
	src/dsp/Oscillator.cpp \
	src/dsp/Limiter.cpp \
	src/dsp/EnvelopeDetector.cpp \
	modules/AudioModule.cpp \
	modules/Demo1ModuleControls.cpp \
	modules/Demo1AudioModule.cpp \
	modules/ModuleView.cpp \
	modules/Demo1ModuleView.cpp \
    src/gui/ModuleFader.cpp

HEADERS  += headers/MainWindow.h \
	headers/Types.h \
	headers/AudioDevice.h \
	headers/AudioProcess.h \
	headers/Oscillator.h \
	headers/AudioModule.h \
	headers/Model.h \
	headers/Fader.h \
	headers/Controls.h \
	headers/AudioDeviceControls.h \
	headers/AudioDeviceView.h \
	headers/AudioThread.h \
	headers/ModuleControls.h \
	headers/Demo1ModuleControls.h \
	headers/Demo1AudioModule.h \
	headers/ModuleView.h \
	headers/Demo1ModuleView.h \
	headers/Gain.h \
	headers/Lfo.h \
	headers/Filters.h \
	headers/Ribbon.h \
	headers/TouchController.h \
	headers/VFader.h \
	headers/ControlGenerator.h \
	headers/AD.h \
	headers/Interpolation.h \
	headers/ADSR.h \
	headers/AudioMath.h \
	headers/UiControls.h \
	headers/AutomationSensor.h \
	headers/WTOscillator.h \
	headers/VuFader.h \
	headers/StereoDelay.h \
	headers/Limiter.h \
    headers/EnvelopeDetector.h \
    src/gui/ModuleFader.h

FORMS    += MainWindow.ui

DISTFILES += \
    TODO.txt \
    License.txt

RESOURCES += \
    ImageResources.qrc
