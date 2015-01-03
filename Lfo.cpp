#include "Lfo.h"



Lfo::Lfo(qint64 sampleRate) :
	m_sampleRate( sampleRate ),
	m_currentValue( 0 )
{

}

Lfo::~Lfo()
{

}

void Lfo::setFrequency(float freq)
{
	m_increment = freq / m_sampleRate;
}



