#ifndef AUDIOTHREAD_H
#define AUDIOTHREAD_H

#include <QObject>
#include "AudioDeviceControls.h"
#include "AudioDevice.h"
#include <QThread>

///
/// \brief The AudioThread class
/// The Audio Thread. This has an event loop, and hosts all the dsp
class AudioThread : public QThread
{
	Q_OBJECT
public:
	AudioThread(AudioDeviceControls *adc = 0, AudioModule *audioModule = 0 , ModuleControls *controls = 0, QWidget *parent = 0);
	~AudioThread();

protected:
	virtual void run();

private:
	QAudioFormat m_format;
	void initializeAudio();
	AudioDevice *m_audioDevice;
	AudioDeviceControls *m_audioDeviceControls;
	ModuleControls *m_controls;
	AudioModule *m_audioModule;

};

#endif // AUDIOTHREAD_H
