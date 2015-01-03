#include "Demo1AudioModule.h"

Demo1AudioModule::Demo1AudioModule(qint64 samplerate, Demo1ModuleControls *controls) :
	AudioModule( samplerate, controls ),
	m_controls( controls )
{
	m_osc = new Oscillator( samplerate  );
	m_osc->setFrequency( 80 );
}

Demo1AudioModule::~Demo1AudioModule()
{
	delete m_osc;
}

void Demo1AudioModule::processAudio(sampleFrame *buffer, qint64 len)
{
	if(m_controls)
	{
		m_osc->setFrequency( m_controls->freqModel.value());
	}
	m_osc->processAudio( buffer, len );
}

