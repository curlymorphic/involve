#include "AudioModule.h"

AudioModule::AudioModule(qint64 samplerate, Controls *controls ) :
	AudioProcess( samplerate ),
	m_controls( controls )
{
	m_osc = new Oscillator( samplerate, controls );
	m_osc->setFrequency( 80 );
}

AudioModule::~AudioModule()
{
	delete m_osc;
}

void AudioModule::processAudio(sampleFrame *buffer, qint64 len)
{
	m_osc->processAudio( buffer, len );
}

