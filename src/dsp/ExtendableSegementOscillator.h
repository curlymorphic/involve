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

#ifndef SEGEMENTOSCILLATOR_H
#define SEGEMENTOSCILLATOR_H

#include "WTOscillator.h"

typedef WTWaveShape CycleTable[2];

///
/// \brief The ExtendableSegementOscillator class
/// This is an oscillator that you select a wave type for each PI revolutions
/// This selection can be made to be many cycles long.
/// each cycles is made of two halves of CycleTable
///
class ExtendableSegementOscillator : public WTOscillator
{
public:
	///
	/// \brief ExtendableSegementOscillator
	/// \param cycleLength The nuber of cycles in sequence
	/// \param sampleRate
	///
	ExtendableSegementOscillator( int cycleLength, int sampleRate = 44100 );
	virtual ~ExtendableSegementOscillator();
	ExtendableSegementOscillator();

	///
	/// \brief maxSegmentCount
	/// maximum nuber of segemts in a single cycle
	static const int maxSegmentCount = 4;

	///
	/// \brief cycles
	/// \return
	/// the number of cycles in the sequence.
	int cycles()
	{
		return m_cycles;
	}

	void setCycles( int cycles )
	{
		m_cycles = cycles;
	}

	/// \brief monoTick Process the next cycle
	/// used as the base function of oscilator output
	/// must only be called once per sample
	/// \return
	///
	sample_t monoTick();

	///
	/// \brief setCycleHalf Sets the wave shapes of the half cycles
	/// \param cycle the cycle index
	/// \param half 0= first half, 1 = second
	/// \param shape
	///
	void setCycleHalf( int cycle, int half, WTWaveShape shape );

	///
	/// \brief setAllCycles sets all cycles to the same shape
	/// \param shape
	///
	void setAllCycles( WTWaveShape shape );

	virtual void restart()
	{
		WTOscillator::restart();
		m_currentCycle = 0;
		setShape( m_cycleTables[ 0 ][ 0 ] );
	}

protected:


	int m_cycles;
	CycleTable *m_cycleTables;
	int m_currentCycle;
};

#endif // SEGEMENTOSCILLATOR_H
