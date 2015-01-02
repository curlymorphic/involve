#include "AudioThread.h"
#include <QAudioDeviceInfo>


AudioThread::AudioThread(AudioDeviceControls *adc, Controls *controls, QWidget *parent):
	QThread( 0 ),
	m_audioDevice( 0 ),
	m_audioDeviceControls( adc ),
	m_controls( controls )
{
	start();
	QObject::moveToThread( this );
}

AudioThread::~AudioThread()
{
	if(m_audioDevice)
	{
		delete m_audioDevice;
		m_audioDevice = 0;
	}
}

void AudioThread::run()
{
	initializeAudio();
	exec();
}

void AudioThread::initializeAudio()
{
	m_format.setSampleRate( 44100 );
	m_format.setChannelCount(2);
	m_format.setSampleSize(16);
	m_format.setCodec("audio/pcm");
	m_format.setByteOrder(QAudioFormat::LittleEndian);
	m_format.setSampleType(QAudioFormat::SignedInt);

	QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
	if (!info.isFormatSupported(m_format)) {
		qWarning() << "Default format not supported - trying to use nearest";
		m_format = info.nearestFormat(m_format);
	}
	m_audioDeviceControls->m_sampleRate = m_format.sampleRate();
	m_audioDevice = new AudioDevice( m_format, m_controls, m_audioDeviceControls );
	m_audioDevice->createAudioOutput();


}

