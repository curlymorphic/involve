#include "Demo1AudioModule.h"

Demo1AudioModule::Demo1AudioModule(qint64 samplerate, ModuleControls *controls) :
	AudioModule( samplerate, controls )
{
	m_osc = new Oscillator( samplerate, controls );
	m_osc->setFrequency( 80 );
}

Demo1AudioModule::~Demo1AudioModule()
{
	delete m_osc;
}

void Demo1AudioModule::processAudio(sampleFrame *buffer, qint64 len)
{
	m_osc->processAudio( buffer, len );
}

