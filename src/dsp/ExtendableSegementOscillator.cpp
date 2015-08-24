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

#include "ExtendableSegementOscillator.h"
#include "Interpolation.h"


ExtendableSegementOscillator::ExtendableSegementOscillator(int cycleLength, int sampleRate) :
	WTOscillator( sampleRate ),
	m_cycles( cycleLength ),
	m_cycleTables( 0 ),
	m_currentCycle( 0 )
{
	m_cycleTables = new CycleTable[ cycleLength ];
	setAllCycles( WT_SAW );
}

ExtendableSegementOscillator::~ExtendableSegementOscillator()
{
	if(m_cycleTables)
	{
		delete[] m_cycleTables;
	}

}

ExtendableSegementOscillator::ExtendableSegementOscillator() :
	ExtendableSegementOscillator( ExtendableSegementOscillator::maxSegmentCount )
{

}

sample_t ExtendableSegementOscillator::monoTick()
{
	if( !m_currentTable )
	{
		return 0;
	}
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


void ExtendableSegementOscillator::setCycleHalf(int cycle, int half, WTWaveShape shape)
{
	m_cycleTables[cycle][half] = shape;
}

void ExtendableSegementOscillator::setAllCycles(WTWaveShape shape)
{
	for( int i = 0; i < m_cycles; ++i )
	{
		m_cycleTables[i][0] = shape;
		m_cycleTables[i][1] = shape;
	}
}

