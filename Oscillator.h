#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include <QtCore>
#include "AudioProcess.h"
#include "Controls.h"


class Oscillator : public AudioProcess
{
public:
	Oscillator( qint64 sampleRate , Controls *controls);
	~Oscillator();
	void setFrequency( float frequency );
	virtual void processAudio( sampleFrame *buffer, qint64 len );

private:
	float m_phaze;
	float m_phase_increment;
	float m_current;
	Controls *m_controls;
};

#endif // OSCILLATOR_H
