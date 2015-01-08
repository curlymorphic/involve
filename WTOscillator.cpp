#include "WTOscillator.h"
#include "Interpolation.h"



WTOscillator::WTOscillator(qint64 sampleRate) :
	AudioProcess( sampleRate ),
	m_index( 0 ),
	m_increment( 0.001 ),
	m_currentTable( 0 ),
	sineTable( 0 ),
	squareTable( 0 ),
	sawTable( 0 ),
	triTable( 0 )
{
	setFrequency(440.0);
	generateSineTable(100);
	generateSawTable(100);
	generateSquareTable(100);
	generateTriTable(100);
	setShape(WT_SINE);
}

WTOscillator::~WTOscillator()
{
	if(sineTable) { delete[] sineTable; }
	if(sawTable) { delete[] sawTable; }
	if(squareTable) { delete[] squareTable; }
	if(triTable) { delete[] triTable; }
}




sample_t WTOscillator::tick()
{
	int nextIndex;
	int index;
	float frac;
	m_index += m_increment;
	if(m_index > TABLE_LEN)
	{
		m_index -= TABLE_LEN;
	}
	nextIndex = m_index < TABLE_LEN - 1 ?
				m_index + 1 :
				0;
	index = m_index;
	frac = m_index - index;
	return linearInterpolate( m_currentTable[ index] , m_currentTable[ nextIndex ], frac );
}

sample_t sample;
void WTOscillator::tick(sampleFrame *frame)
{
	sample = tick();
	frame[0][0] = sample;
	frame[0][1] = sample;
}

void WTOscillator::setFrequency(float freq)
{
	freq = qBound(32.7f, freq, 4186.0f );
	m_increment = TABLE_LEN * ( freq / m_sampleRate );
}

void WTOscillator::setShape(WTWaveShape shape)
{
	switch ( shape )
	{
	case WT_SINE:
		m_currentTable = sineTable;
		break;
	case WT_SAW:
		m_currentTable = sawTable;
		break;
	case WT_SQUARE:
		m_currentTable = squareTable;
		break;
	case WT_TRIANGLE:
		m_currentTable = triTable;
		break;
	default:
		break;
	}
	return;
}

void WTOscillator::setUserShape(float *table)
{
	m_currentTable = table;
}

void WTOscillator::generateSineTable( qint64 bands )
{
	sineTable = new sample_t[ TABLE_LEN ];
	for(int i = 0; i < TABLE_LEN; i++)
	{
		sineTable[i] = qSin( ((float)i/(float)TABLE_LEN) * f_2PI );
	}
}

void WTOscillator::generateSawTable(qint64 bands)
{
	float max = 0;
	sawTable = new sample_t[ TABLE_LEN ];
	for(int i = 0 ; i < TABLE_LEN; i++)
	{
		sawTable[i] = 0.0;
		for(int g = 1; g <= bands; g++)
		{
			double n = double(g);
			sawTable[i] += qPow((float)-1.0, (float) ( g + 1 ) ) *
					(1.0 /n ) * qSin( f_2PI * i * n / (float)TABLE_LEN );
		}
		max = qMax( max, sawTable[i] );
	}

	for( int i = 0; i < TABLE_LEN; i++ )
	{
		sawTable[i] /= max;
	}
}

void WTOscillator::generateTriTable(qint64 bands)
{
	float max = 0;
	triTable = new sample_t[ TABLE_LEN ];
	for(int i = 0 ; i < TABLE_LEN; i++)
	{
		triTable[i] = 0.0;
		for(int g = 0; g <= bands * 0.5; g ++)
		{
			double n = double(g);
			triTable[i] += qPow((float)-1.0, (float) n ) *
					(1.0/ qPow(( float )( 2 * n +1 ),
							   ( float )2.0 )) *
					qSin(f_2PI * ( 2.0 * n + 1) * i/(float)TABLE_LEN);
		}
		max = qMax( max, triTable[i] );
	}

	for( int i = 0; i < TABLE_LEN; i++ )
	{
		triTable[i] /= max;
	}
}

void WTOscillator::generateSquareTable(qint64 bands)
{
	float max = 0;
	squareTable = new sample_t[ TABLE_LEN ];
	for(int i = 0 ; i < TABLE_LEN; i++)
	{
		squareTable[i] = 0.0;
		for(int g = 1; g <= bands; g += 2)
		{
			double n = double(g);
			squareTable[i] += (1.0/n) * qSin(f_2PI * i * n / TABLE_LEN );
		}
		max = qMax( max, squareTable[i] );
	}

	for( int i = 0; i < TABLE_LEN; i++ )
	{
		squareTable[i] /= max;
	}
}

