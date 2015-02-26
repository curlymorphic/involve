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

#ifndef WTOSCILLATOR_H
#define WTOSCILLATOR_H

#include "AudioMath.h"
#include "AudioProcess.h"

///
/// \brief The WTWaveShape enum
///The Diffrent Wave Tables.
enum WTWaveShape { WT_SINE, WT_TRIANGLE, WT_SQUARE, WT_SAW,  WT_USER, WT_WAVESHAPECOUNT };


///
/// \brief The WTOscillator class
///A Wave Table oscillator , all wave tables are 1024 samples
/// Sine Square Saw and Triangle generated using addith synthasys, with 5 harmonics
/// These wont alias when played at c8, but will sound flat for bass notes
///
///
class WTOscillator : public AudioProcess
{
public:

	const int TABLE_LEN = 1024;
	WTOscillator( int sampleRate );
	~WTOscillator();

	///
	/// \brief tick
	/// \return
	///Returns the next sample

	sample_t tick();

	///
	/// \brief tick
	/// \param frame
	/// places the next sample in frame, as a stereo signal
	void tick( sampleFrame *frame );

	float uniTick();

	///
	/// \brief setFrequency
	/// \param freq
	/// sets the frequency. limited to 0- 4186   c1 - c8
	void setFrequency( float freq );

	///
	/// \brief setShape
	/// \param shape
	///Sets the wave table to use
	void setShape( WTWaveShape shape );

	///
	/// \brief setUserShape
	/// \param table
	/// sets the wavetable to use, the table must be 1024 samples
	void setUserShape( float *table );

	///
	/// \brief noteOn
	/// Retriggers the generator to the attack phase
	inline void noteOn()
	{
		setShape( m_currentShape );
	}

	///
	/// \brief noteRelease
	///Puts the generator into the release phase
	inline void noteRelease()
	{

	}

protected:
	///
	/// \brief m_index
	/// The current into into the table
	float m_index;
	///
	/// \brief m_increment
	///The ammount to increase the index by each frame, this is set in setFrequency
	float m_increment;

	///
	/// \brief m_currentTable
	///pointer to the currently selected table;
	sample_t *m_currentTable;

	///
	/// \brief SineTable
	/// the calculated Sine Wave Table
	sample_t *sineTable;
	///
	/// \brief SquareTable
	///the calculated Square Wave Table
	sample_t *squareTable;
	///
	/// \brief TriTable
	/// the calculated Triangle Wave Table
	sample_t *triTable;
	///
	/// \brief SawTable
	/// the calculated Saw tooth Wave Table
	sample_t *sawTable;

	/// \brief sinTables
	/// array of SineWaveTables
	sample_t **sineTables;
	///
	/// \brief squareTables
	///arry of Square wave tables
	sample_t **squareTables;
	///
	/// \brief triTables
	///array of triangle wave tables
	sample_t **triTables;
	///
	/// \brief sawTables
	///array of sawWaveTables
	sample_t **sawTables;
	///
	/// \brief m_bandFreq
	///array containing base frequency for each band
	float *m_bandFreq;
	///
	/// \brief m_tableCount
	///The number of tables the audio spectrum is split into.
	int m_tableCount;
	///
	/// \brief m_freq
	/// Current Frequency
	float m_freq;

	WTWaveShape m_currentShape;


private:

	void generateSineTable( int bands );
	void generateSawTable( int bands );
	void generateTriTable( int bands );
	void generateSquareTable( int bands );

	int bandFromFreq( float freq );

};

#endif // WTOSCILLATOR_H
