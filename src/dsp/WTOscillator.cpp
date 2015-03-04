/*
 * Copyright (c) 2014-2015 Dave French <contact/dot/dave/dot/french3/at/googlemail/dot/com>
 *
 * This file is part of Involve - http://github.com/curlymorphic/involve
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */

#include "WTOscillator.h"
#include "Interpolation.h"



WTOscillator::WTOscillator(int sampleRate) :
	AudioProcess( sampleRate ),
	m_index( 0 ),
	m_increment( 0.001 ),
	m_currentTable( 0 ),
	sineTable( 0 ),
	squareTable( 0 ),
	triTable( 0 ),
	sawTable( 0 ),
	m_currentShape (WT_SQUARE)
{
	m_bandFreq = new float[8] { 32.073, 65.4, 103.81, 261.63, 523.25, 1046.5, 2093.5, 4186.0 };
	m_tableCount = 8;
	setFrequency( 440.0 );
	sineTables = new sample_t*[ m_tableCount ];
	for(int i = 0 ; i < m_tableCount; ++i)
	{
		generateSineTable( m_sampleRate / m_bandFreq[i] * 0.5 );
		sineTables[i] = sineTable;
	}

	sawTables = new sample_t*[ m_tableCount ];
	for(int i = 0 ; i < m_tableCount; ++i)
	{
		generateSawTable( m_sampleRate / m_bandFreq[i] * 0.5 );
		sawTables[i] = sawTable;
	}

	squareTables = new sample_t*[ m_tableCount ];
	for( int i = 0; i < m_tableCount; ++i)
	{
		generateSquareTable( m_sampleRate / m_bandFreq[i] * 0.5 );
		squareTables[i] = squareTable;
	}

	triTables = new sample_t*[ m_tableCount ];
	for( int i = 0; i < m_tableCount; ++i )
	{
		generateTriTable( m_sampleRate / m_bandFreq[i] * 0.5 );
		triTables[i] = triTable;
	}

	setShape( m_currentShape );
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
	return linearInterpolate( m_currentTable[ index ] , m_currentTable[ nextIndex ], frac );
}

sample_t sample;
void WTOscillator::tick(sampleFrame *frame)
{
	sample = tick();
	frame[0][0] = sample;
	frame[0][1] = sample;
}

float WTOscillator::uniTick()
{
	return (tick()/2)+ 0.5;
}

void WTOscillator::setFrequency(float freq)
{
	freq = bound(0.0f, freq, 4186.0f );
	m_increment = TABLE_LEN * ( freq / m_sampleRate );
	m_freq = freq;
}

void WTOscillator::setShape(WTWaveShape shape)
{
	int band = bandFromFreq( m_freq );
	switch ( shape )
	{
	case WT_SINE:
		m_currentTable = sineTables[ band ];
		break;
	case WT_SAW:
		m_currentTable = sawTables[ band ];
		break;
	case WT_SQUARE:
		m_currentTable = squareTables[ band ];
		break;
	case WT_TRIANGLE:
		m_currentTable = triTables[ band ];
		break;
	default:
		break;
	}
	m_currentShape = shape;
	return;
}

void WTOscillator::setUserShape(float *table)
{
	m_currentTable = table;
}

void WTOscillator::generateSineTable( int bands )
{
	bands = bands;
	sineTable = new sample_t[ TABLE_LEN ];
	for(int i = 0; i < TABLE_LEN; i++)
	{
		sineTable[i] = sinf( ((float)i/(float)TABLE_LEN) * F_2PI );
	}
}

void WTOscillator::generateSawTable(int bands)
{
	float max = 0;
	sawTable = new sample_t[ TABLE_LEN ];
	for(int i = 0 ; i < TABLE_LEN; i++)
	{
		sawTable[i] = 0.0;
		for(int g = 1; g <= bands; g++)
		{
			double n = double(g);
			sawTable[i] +=powf((float)-1.0, (float) ( g + 1 ) ) *
					(1.0 /n ) * sinf( F_2PI * i * n / (float)TABLE_LEN );
		}
		max = fmax( max, sawTable[i] );
	}

	for( int i = 0; i < TABLE_LEN; i++ )
	{
		sawTable[i] /= max;
	}
}

void WTOscillator::generateTriTable(int bands)
{
	float max = 0;
	triTable = new sample_t[ TABLE_LEN ];
	for(int i = 0 ; i < TABLE_LEN; i++)
	{
		triTable[i] = 0.0;
		for(int g = 0; g <= bands * 0.5; g ++)
		{
			double n = double(g);
			triTable[i] += powf((float)-1.0, (float) n ) *
					(1.0/ powf(( float )( 2 * n +1 ),
							   ( float )2.0 )) *
					sinf(F_2PI * ( 2.0 * n + 1) * i/(float)TABLE_LEN);
		}
		max = fmax( max, triTable[i] );
	}

	for( int i = 0; i < TABLE_LEN; i++ )
	{
		triTable[i] /= max;
	}
}

void WTOscillator::generateSquareTable(int bands)
{
	float max = 0;
	squareTable = new sample_t[ TABLE_LEN ];
	for(int i = 0 ; i < TABLE_LEN; i++)
	{
		squareTable[i] = 0.0;
		for(int g = 1; g <= bands; g += 2)
		{
			double n = double(g);
			squareTable[i] += (1.0/n) * sinf(F_2PI * i * n / TABLE_LEN );
		}
		max = fmax( max, squareTable[i] );
	}

	for( int i = 0; i < TABLE_LEN; i++ )
	{
		squareTable[i] /= max;
	}
}

int WTOscillator::bandFromFreq(float freq)
{
	int i;
	for( i = 0; i < m_tableCount; ++i )
	{
		if (m_bandFreq[i] > freq) return i;
	}
	return i;
}

