#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include <QtCore>
#include "AudioProcess.h"


class Oscillator : public AudioProcess
{
public:
	Oscillator( qint64 sampleRate );
	~Oscillator();
	void setFrequency( float frequency );
	virtual inline void tick( sampleFrame *frame );
	virtual inline float tick();


private:
	float m_phaze;
	float m_phase_increment;
	float m_current;

};

#endif // OSCILLATOR_H
