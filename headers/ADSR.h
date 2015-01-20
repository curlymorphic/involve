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

#ifndef ADSR
#define ADSR

#include <QtCore>
#include "ControlGenerator.h"
#include "Interpolation.h"

///
/// \brief The Adsr class
/// Envelope Generator
class Adsr : ControlGenerator
{
public:
	Adsr( qint64 sampleRate ) :
		ControlGenerator( sampleRate ),
		m_attackTime( 20000 ),
		m_decayTime( 35000 ),
		m_sustainLevel( 0.5 ),
		m_releaseTime( 65000 ),
		m_phase( release ),
		m_samplesSincePhaseChanged( 999999 ),
		m_lastValue( 0 )
	{

	}

	///
	/// \brief setAttackTime
	/// \param time Seconds
	///
	inline void setAttackTime( float time )
	{
		m_attackTime = time * m_sampleRate;
	}

	///
	/// \brief setDecayTime
	/// \param time Seconds
	///
	inline void setDecayTime( float time )
	{
		m_decayTime = time * m_sampleRate;
	}

	///
	/// \brief setSustainLevel
	/// \param level 0.0 1.0
	///
	inline void setSustainLevel( float level )
	{
		m_sustainLevel = level;
	}

	///
	/// \brief setReleaseTime
	/// \param time Seconds
	///
	inline void setReleaseTime( qint64 time )
	{
		m_releaseTime = time * m_sampleRate;
	}

	///
	/// \brief noteOn
	/// Retriggers the generator to the attack phase
	inline void noteOn()
	{
		m_phase = attack;
		m_samplesSincePhaseChanged = 0;
	}

	///
	/// \brief noteRelease
	///Puts the generator into the release phase
	inline void noteRelease()
	{
		m_phase = release;
		m_samplesSincePhaseChanged = 0;
	}

	///
	/// \brief tick
	/// \return
	///returns the next multiplyer to use 0.0 - 1.0
	/// only call once per frame
	virtual inline float tick( )
	{
		m_samplesSincePhaseChanged++;
		if( m_phase == attack )
		{
			if ( m_samplesSincePhaseChanged > m_attackTime )
			{
				m_phase = decay;
				m_samplesSincePhaseChanged = 0;
			}
			m_lastValue = linearInterpolate( 0, 1, (float)m_samplesSincePhaseChanged /
											 (float)m_attackTime );
			return m_lastValue;
		}
		if( m_phase == decay )
		{
			if ( m_lastValue <= m_sustainLevel )
			{
				m_phase = sustain;
				m_samplesSincePhaseChanged = 0;
			}
			m_lastValue = linearInterpolate( 1, m_sustainLevel, (float)m_samplesSincePhaseChanged /
											 (float)m_decayTime );
			return m_lastValue;
		}

		if( m_phase == sustain )
		{
			//			m_phase=release;
			m_lastValue = m_sustainLevel;
			return m_lastValue;
		}

		if ( m_phase == release )
		{
			if( m_samplesSincePhaseChanged >= m_releaseTime )
			{
				return 0;
			}
			return linearInterpolate( m_lastValue, 0,
									  (float)m_samplesSincePhaseChanged / (float)m_releaseTime );
		}

		return 0;

	}


private:
	qint64 m_attackTime;
	qint64 m_decayTime;
	float m_sustainLevel;
	qint64 m_releaseTime;
	enum Phase { attack, decay, sustain, release, count };
	Phase m_phase;
	qint64 m_samplesSincePhaseChanged;
	float m_lastValue;
};


#endif // ADSR

