#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include <QtCore>
#include "AudioProcess.h"
#include "Controls.h"
#include "Demo1ModuleControls.h"


class Oscillator : public AudioProcess
{
public:
	Oscillator( qint64 sampleRate );
	~Oscillator();
	void setFrequency( float frequency );
	virtual void processAudio( sampleFrame *buffer, qint64 len );

private:
	float m_phaze;
	float m_phase_increment;
	float m_current;

};

#endif // OSCILLATOR_H
