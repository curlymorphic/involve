#include "AudioModule.h"

AudioModule::AudioModule(qint64 samplerate, ModuleControls *controls ) :
	AudioProcess( samplerate ),
	m_controls( controls )
{

}

AudioModule::~AudioModule()
{

}

void AudioModule::processAudio(sampleFrame *buffer, qint64 len)
{
	memset( buffer, 0, sizeof(sampleFrame) * len );

}

