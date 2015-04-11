#include "SegementOscillator.h"
#include "Interpolation.h"


SegementOscillator::SegementOscillator(int cycleLength, int sampleRate) :
	WTOscillator( sampleRate ),
	m_cycles( cycleLength ),
	m_cycleTables( 0 ),
	m_currentCycle( 0 )
{
	m_cycleTables = new CycleTable[ cycleLength ];
	setAllCycles( WTWaveShape::WT_SAW);

}

SegementOscillator::~SegementOscillator()
{
	if(m_cycleTables)
	{
		delete[] m_cycleTables;
	}

}

sample_t SegementOscillator::monoTick()
{
	int nextIndex;
	int index;
	float frac;
	m_index += m_increment;
	if(m_index > TABLE_LEN)
	{
		m_index -= TABLE_LEN;
		m_currentCycle = (m_currentCycle + 1) % m_cycles;
	}
	CycleTable *currentCycleTable = &m_cycleTables[ m_currentCycle ] ;
	WTWaveShape cycleShape = m_index <= (TABLE_LEN * 0.5) ? currentCycleTable[0][0] : currentCycleTable[0][1];
	setShape( cycleShape );
	nextIndex = m_index < TABLE_LEN - 1 ?
				m_index + 1 :
				0;
	index = m_index;
	frac = m_index - index;
	return linearInterpolate( m_currentTable[ index ] , m_currentTable[ nextIndex ], frac );
}

void SegementOscillator::setCycleHalf(int cycle, int half, WTWaveShape shape)
{
	m_cycleTables[cycle][half] = shape;
}

void SegementOscillator::setAllCycles(WTWaveShape shape)
{
	for( int i = 0; i < m_cycles; ++i )
	{
		m_cycleTables[i][0] = shape;
		m_cycleTables[i][1] = shape;
	}
}

