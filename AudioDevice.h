#ifndef AUDIODEVICE_H
#define AUDIODEVICE_H

#include <qiodevice.h>
#include <QAudioFormat>
#include "Types.h"
#include "AudioModule.h"
#include "AudioDeviceControls.h"
#include <QAudioOutput>
#include <QByteArray>
#include <QIODevice>


class AudioDevice: public QIODevice
{
	Q_OBJECT

public:
	AudioDevice(const QAudioFormat &format, Controls *controls, AudioDeviceControls * adc, QObject *parent = 0 );
	virtual ~AudioDevice();

	void start();
	void stop();

	void sampleFrameToBuffer(sampleFrame *buf, int frames, QAudioFormat &format);
	void createAudioOutput();

	qint64 readData(char *data, qint64 maxlen);
	qint64 writeData(const char *data, qint64 len);
	qint64 bytesAvailable() const;

private:


//	void startAudio();

	qint64 m_pos;
	QByteArray m_buffer;
	sampleFrame *m_frameBuffer;
	QAudioFormat m_format;
	AudioModule m_module;
	QAudioDeviceInfo m_device;
	AudioDevice *m_audioDevice;
	QAudioOutput *m_audioOutput;
	QIODevice *m_output;
	AudioDeviceControls *m_audioDeviceControls;



};

#endif // AUDIODEVICE_H
