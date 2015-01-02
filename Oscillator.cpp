#include "Oscillator.h"



Oscillator::Oscillator(qint64 sampleRate, Controls *controls) :
	AudioProcess( sampleRate ),
	m_phase_increment( 0.003 ),
	m_current( 0 ),
	m_controls( controls )
{

}

Oscillator::~Oscillator()
{

}

void Oscillator::setFrequency(float frequency)
{
	m_phase_increment = frequency / m_sampleRate;
}

void Oscillator::processAudio(sampleFrame *buffer, qint64 len)
{
	setFrequency( m_controls->m_freqModel.value() );
	for( int i = 0; i < len; ++i)
	{
		m_current += m_phase_increment;
		if( m_current > 0.5) { m_current -= 1.0; }
		buffer[i][0] = m_current;
		buffer[i][1] = m_current;
	}
}

