#include "AudioDevice.h"
#include <qendian.h>
#include <qmath.h>
#include <QIODevice>

AudioDevice::AudioDevice(const QAudioFormat &format, Controls *controls, AudioDeviceControls * adc, QObject *parent) :
	QIODevice(parent),
	m_pos(0),
	m_module( 44100 , controls),
	m_device(QAudioDeviceInfo::defaultOutputDevice()),
	m_audioDevice(0),
	m_audioOutput(0),
	m_output(0),
	m_audioDeviceControls( adc )
{
	m_format = format;

	m_frameBuffer = new sampleFrame[100000]; //to big !!!!
	for (int i = 0; i < 100000 ; ++i)
	{
		m_frameBuffer[i][0] = 0;
		m_frameBuffer[i][1] = 0;
	}

}



AudioDevice::~AudioDevice()
{

}



void AudioDevice::start()
{
	open(QIODevice::ReadOnly);
}



void AudioDevice::stop()
{
	m_pos=0;
	close();
}




void AudioDevice::sampleFrameToBuffer(sampleFrame *buf, int frames, QAudioFormat &format)
{
	const int channelBytes = format.sampleSize() / 8;
	const int sampleBytes = format.channelCount() * channelBytes;

	qint64 length = (frames * format.channelCount() * (format.sampleSize() / 8));


	Q_ASSERT(length % sampleBytes == 0);
	Q_UNUSED(sampleBytes); // suppress warning in release builds

	m_buffer.resize(length);
	unsigned char *ptr = reinterpret_cast<unsigned char *>(m_buffer.data());
	int sampleIndex = 0;

	const sampleFrame *x = buf;
	while (length) {
		for (int i=0; i<format.channelCount(); ++i) {
			if (format.sampleSize() == 8 && format.sampleType() == QAudioFormat::UnSignedInt) {
				const quint8 value = static_cast<quint8>((1.0 + x[0][i]) / 2 * 255);
				*reinterpret_cast<quint8*>(ptr) = value;
			} else if (format.sampleSize() == 8 && format.sampleType() == QAudioFormat::SignedInt) {
				const qint8 value = static_cast<qint8>(x[0][i] * 127);
				*reinterpret_cast<quint8*>(ptr) = value;
			} else if (format.sampleSize() == 16 && format.sampleType() == QAudioFormat::UnSignedInt) {
				quint16 value = static_cast<quint16>((1.0 + x[0][i]) / 2 * 65535);
				if (format.byteOrder() == QAudioFormat::LittleEndian)
					qToLittleEndian<quint16>(value, ptr);
				else
					qToBigEndian<quint16>(value, ptr);
			} else if (format.sampleSize() == 16 && format.sampleType() == QAudioFormat::SignedInt) {
				qint16 value = static_cast<qint16>(x[0][i] * 32767);
				if (format.byteOrder() == QAudioFormat::LittleEndian)
					qToLittleEndian<qint16>(value, ptr);
				else
					qToBigEndian<qint16>(value, ptr);
			}

			ptr += channelBytes;
			length -= channelBytes;
		}
		++sampleIndex;
		++x;
	}
}

void AudioDevice::createAudioOutput()
{
	if( m_audioOutput) { delete m_audioOutput; }
	m_audioOutput = 0;
	m_audioOutput = new QAudioOutput(m_device, m_format, this);
	//	m_audioOutput->setBufferSize(10000);

	start();
	m_audioOutput->start(this);
	//	m_audioDeviceControls->m_bufferSize = m_audioOutput->bufferSize();
}



qint64 AudioDevice::readData(char *data, qint64 len)
{
	if( len )
	{
		len = len > bytesAvailable() ? bytesAvailable() : len;
		m_module.processAudio( m_frameBuffer, len / 4 );
		sampleFrameToBuffer( m_frameBuffer, len, m_format );
		memcpy(data,m_buffer,len);
		m_audioDeviceControls->m_bufferSize = len;
	}
	return len;
}

qint64 AudioDevice::writeData(const char *data, qint64 len)
{
	Q_UNUSED(data);
	Q_UNUSED(len);

	return 0;
}

qint64 AudioDevice::bytesAvailable() const
{
	//	return m_buffer.size() + QIODevice::bytesAvailable();
	return 512;
}



