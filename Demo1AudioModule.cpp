#include "Demo1AudioModule.h"

Demo1AudioModule::Demo1AudioModule(qint64 sampleRate, Demo1ModuleControls *controls) :
	AudioModule( sampleRate, controls ),
	m_controls( controls )
{
	m_osc = new WTOscillator( sampleRate );
	m_osc->setFrequency( 80 );
	m_gain = new Gain( sampleRate );
	m_volLfo = new Lfo( sampleRate );
	m_volLfo->setFrequency( 1 );
	m_lp = new Lp12( sampleRate );
	m_lp2 = new Lp12( sampleRate ),
	m_ad = new Adsr( sampleRate );
}

Demo1AudioModule::~Demo1AudioModule()
{
	delete m_osc;
}

void Demo1AudioModule::processAudio(sampleFrame *buffer, qint64 len)
{
	if(m_controls)
	{
		for(int i = 0; i < len; i++)
		{
			m_ad->setAttackTime( m_controls->attackModel.value() );
			m_ad->setDecayTime( m_controls->decayModel.value() );
			m_ad->setSustainLevel( m_controls->sustainModel.value() );
			m_ad->setReleaseTime( m_controls->releaseModel.value() );
			m_osc->setFrequency( m_controls->freqModel.value() );
			m_osc->setShape( (WTWaveShape)(int)m_controls->waveShapeModel.value() );
			m_gain->setGain( m_controls->velocityModel.value() *
							 ( m_volLfo->tick() + 1.0 ) * m_ad->tick(m_controls->noteOn ,
																	 m_controls->noteOff) );
			m_lp->setParameters(m_controls->cutOffModel.value(), m_controls->resModel.value() );
			m_lp2->setParameters( m_controls->cutOffModel.value(), m_controls->resModel.value() );
			m_osc->tick( &buffer[i] );
			m_lp->tick( &buffer[i] );
			m_lp2->tick( &buffer[i] );
			m_gain->tick( &buffer[i] );
		}
	}
}

