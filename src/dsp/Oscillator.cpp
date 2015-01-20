#include "Oscillator.h"



Oscillator::Oscillator( qint64 sampleRate ) :
	AudioProcess( sampleRate ),
	m_phase_increment( 0.003 ),
	m_current( 0 )
{

}

Oscillator::~Oscillator()
{

}

void Oscillator::setFrequency(float frequency)
{
	m_phase_increment = frequency / m_sampleRate;
}


inline void Oscillator::tick(sampleFrame *frame)
{
	tick();
	frame[0][0] = m_current;
	frame[0][1] = m_current;
}

float Oscillator::tick()
{
	m_current += m_phase_increment;
	if( m_current > 0.5) { m_current -= 1.0; }
	return m_current;
}


