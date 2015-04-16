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
enum WTWaveShape { WT_SINE, WT_TRIANGLE, WT_SQUARE, WT_SAW, WT_SINE2,
				   WT_DOUBLE_SINE, WT_DOUBLE_TRIANGLE, WT_DOUBLE_SQUARE, WT_DOUBLE_SAW,
				   WT_WAVESHAPECOUNT };


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

	static const int TABLE_LEN = 1024;
	WTOscillator( int sampleRate = 44100 );
	virtual ~WTOscillator();

	///
	/// \brief tick
	/// \return
	///Returns the next sample

	virtual sample_t monoTick();

	///
	/// \brief tick
	/// \param frame
	/// places the next sample in frame, as a stereo signal
	virtual void tick( sampleFrame *frame );

	float uniTick();

	///
	/// \brief setFrequency
	/// \param freq
	/// sets the frequency. limited to 0- 4186   c1 - c8
	virtual void setFrequency( float freq );

	///
	/// \brief setShape
	/// \param shape
	///Sets the wave table to use
	virtual void setShape( WTWaveShape shape );

	///
	/// \brief setUserShape
	/// \param table
	/// sets the wavetable to use, the table must be 1024 samples
	virtual void setUserShape( float *table );

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

	virtual void restart()
	{
		m_index = 0;
	}

	void generateWaveTables();
	void allocTables();



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

	/// \brief sinTables
	/// array of SineWaveTables
	static sample_t **sineTables;
	///
	/// \brief squareTables
	///arry of Square wave tables
	static sample_t **squareTables;
	///
	/// \brief triTables
	///array of triangle wave tables
	static sample_t **triTables;
	///
	/// \brief sawTables
	///array of sawWaveTables
	static sample_t **sawTables;

	static sample_t **sin2Tables;
	static sample_t **doubleSineTables;
	static sample_t **doubleTriangleTables;
	static sample_t **doubleSquareTables;
	static sample_t **doubleSawTables;

private:

	void generateSineTable( int bands );
	void generateSine2Table( int bands );
	void generateSawTable( int bands );
	void generateTriTable( int bands );
	void generateSquareTable( int bands );

	void generateDoubleTables( sample_t **origin, sample_t **destination );


	int bandFromFreq( float freq );

};

#endif // WTOSCILLATOR_H
