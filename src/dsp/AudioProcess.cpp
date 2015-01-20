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
	for( int i =0; i < len; i++)
	{
		tick( &buffer[i] );
	}

}

void AudioProcess::setSampleRate(qint64 sampleRate)
{
	m_sampleRate = sampleRate;
}

qint64 AudioProcess::getSampleRate()
{
	return m_sampleRate;
}

void AudioProcess::tick(sampleFrame *frame)
{
	frame[0][0] = 0.0;
	frame[0][1] = 0.0;
}
