#ifndef SEGEMENTOSCILLATOR_H
#define SEGEMENTOSCILLATOR_H

#include "WTOscillator.h"

typedef WTWaveShape CycleTable[2];

class ExtendableSegementOscillator : public WTOscillator
{
public:
	ExtendableSegementOscillator( int cycleLength, int sampleRate = 44100 );
	virtual ~ExtendableSegementOscillator();



	int cycles()
	{
		return m_cycles;
	}

	sample_t monoTick();

	void setCycleHalf( int cycle, int half, WTWaveShape shape );


protected:

	void setAllCycles( WTWaveShape shape );

	int m_cycles;
	CycleTable *m_cycleTables;
	int m_currentCycle;
};

#endif // SEGEMENTOSCILLATOR_H
