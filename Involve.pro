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

TARGET = Involve
TEMPLATE = app

INCLUDEPATH += ./headers
INCLUDEPATH += $$PWD/modules
INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/core
INCLUDEPATH += ./src/gui
INCLUDEPATH += $$PWD/src/dsp
#INCLUDEPATH += /usr/local/lib/libfftw3.a

#	LIBS +=-lm \
#	-lstdc++ \
#	-lfftw3

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
	modules/base/AudioModule.cpp \
	modules/Demo1/Demo1ModuleControls.cpp \
	modules/Demo1/Demo1AudioModule.cpp \
	modules/base/ModuleView.cpp \
	modules/Demo1/Demo1ModuleView.cpp \
	src/gui/ModuleFader.cpp \
	modules/Demo2/Demo2AudioModule.cpp \
	modules/Demo2/Demo2ModuleControls.cpp \
	modules/Demo2/Demo2ModuleView.cpp \
    modules/ModuleManager.cpp \
    src/gui/MenuDialog.cpp \
    src/gui/About.cpp \
    src/gui/SynthSelector.cpp \
    src/gui/ModuleListWidget.cpp \
    src/core/ModelManager.cpp \
    modules/SuperSawer/SuperSawerModuleControls.cpp \
    modules/SuperSawer/SuperSawModuleView.cpp \
    modules/SuperSawer/SuperSawAudioModule.cpp \
    src/dsp/SegementOscillator.cpp
#	src/Analyser.cpp

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
	modules/Demo1/Demo1ModuleControls.h \
	modules/Demo1/Demo1AudioModule.h \
	headers/ModuleView.h \
	modules/Demo1/Demo1ModuleView.h \
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
    src/gui/ModuleFader.h \
#	headers/Analyser.h \
	modules/Demo2/Demo2AudioModule.h \
	modules/Demo2/Demo2ModuleControls.h \
	modules/Demo2/Demo2ModuleView.h \
    modules/ModuleManager.h \
    modules/Demo1ModuleData.h \
    src/gui/MenuDialog.h \
    src/gui/About.h \
    src/gui/SynthSelector.h \
    src/gui/ModuleListWidget.h \
    src/core/ModelManager.h \
    modules/SuperSawer/SuperSawerModuleControls.h \
    modules/SuperSawer/SuperSawModuleView.h \
    modules/SuperSawer/SuperSawAudioModule.h \
    src/dsp/SegementOscillator.h



FORMS    += MainWindow.ui

DISTFILES += \
    TODO.txt \
    License.txt \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/AndroidManifest.xml \
    android/gradlew.bat \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew

RESOURCES += \
    ImageResources.qrc

#LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lfftw3

#INCLUDEPATH += $$PWD/../../../../../../usr/local/include
#DEPENDPATH += $$PWD/../../../../../../usr/local/include

#PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/lib/libfftw3.a

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
