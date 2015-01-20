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
#include "Demo1AudioModule.h"

///
/// \brief The AudioDevice class
/// The main audio engine, pulls data and converts to audio buffer.
class AudioDevice: public QIODevice
{
	Q_OBJECT

public:
	AudioDevice(const QAudioFormat &format, AudioModule *module, ModuleControls *controls, AudioDeviceControls * adc, QObject *parent = 0 );
	virtual ~AudioDevice();

	void start();
	void stop();

	///
	/// \brief sampleFrameToBuffer
	/// \param buf
	/// \param frames
	/// \param format
	/// converts the sampleFrame bufer into the correct format for the audio card.
	void sampleFrameToBuffer(sampleFrame *buf, int frames, QAudioFormat &format);

	///
	/// \brief createAudioOutput
	/// initilise the audio
	void createAudioOutput();

	///
	/// \brief readData
	/// \param data
	/// \param maxlen
	/// \return
	/// Processes 1 period of audio data
	qint64 readData(char *data, qint64 maxlen);
	qint64 writeData(const char *data, qint64 len);
	///
	/// \brief bytesAvailable
	/// \return
	/// the frames size * 4
	qint64 bytesAvailable() const;

private:


//	void startAudio();

	qint64 m_pos;
	QByteArray m_buffer;
	sampleFrame *m_frameBuffer;
	QAudioFormat m_format;
	AudioModule *m_module;
	ModuleControls *m_moduleControls;
	QAudioDeviceInfo m_device;
	AudioDevice *m_audioDevice;
	QAudioOutput *m_audioOutput;
	QIODevice *m_output;
	AudioDeviceControls *m_audioDeviceControls;



};

#endif // AUDIODEVICE_H
