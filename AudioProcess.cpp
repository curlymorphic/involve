#include "AudioProcess.h"
#include <QtCore>

AudioProcess::AudioProcess(qint64 sampleRate) :
	m_sampleRate( sampleRate )
{

}

AudioProcess::~AudioProcess()
{

}

void AudioProcess::processAudio(sampleFrame *buffer, qint64 len)
{
	memset(buffer, 0, sizeof(sampleFrame) * len );
}

void AudioProcess::setSampleRate(qint64 sampleRate)
{
	m_sampleRate = sampleRate;
}

qint64 AudioProcess::getSampleRate()
{
	return m_sampleRate;
}
