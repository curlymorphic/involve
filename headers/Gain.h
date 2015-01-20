#ifndef GAIN_H
#define GAIN_H

#include "AudioProcess.h"

///
/// \brief The Gain class
/// Gain processor
class Gain : public AudioProcess
{
public:
	Gain( qint64 sampleRate );
	~Gain();
	inline void setGain( float gain )
	{
		m_gain = gain;
	}


	virtual inline void tick( sampleFrame *frame );

private:
	float m_gain;

};

#endif // GAIN_H
