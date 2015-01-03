#include "Gain.h"



Gain::Gain(qint64 sampleRate) :
	AudioProcess( sampleRate ),
	m_gain( 1.0 )
{

}

Gain::~Gain()
{

}



inline void Gain::tick(sampleFrame *frame)
{
	frame[0][0] *= m_gain;
	frame[0][1] *= m_gain;
}

