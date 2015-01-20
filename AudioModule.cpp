#include "AudioModule.h"

AudioModule::AudioModule(qint64 samplerate, ModuleControls *controls ) :
	AudioProcess( samplerate ),
	m_controls( controls )
{
	connect( &controls->noteOnModel, SIGNAL(dataChanged( float ) ), this, SLOT( notePressed( float ) ) );
}

AudioModule::~AudioModule()
{

}

void AudioModule::processAudio(sampleFrame *buffer, qint64 len)
{
	memset( buffer, 0, sizeof(sampleFrame) * len );

}

void AudioModule::notePressed(float val)
{
	if( val ) { noteOn(); }
	else { noteOff(); }
}

void AudioModule::noteOn()
{

}

void AudioModule::noteOff()
{

}

