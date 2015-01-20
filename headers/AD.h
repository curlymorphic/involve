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

#ifndef AD_H
#define AD_H

#include <QtCore>
#include "ControlGenerator.h"
#include "Interpolation.h"

class AD : public ControlGenerator
{
public:
	AD( qint64 sampleRate ) :
		ControlGenerator( sampleRate ),
		m_attackTime( 20000 ),
		m_decayTime( 35000 ),
		m_phase( decay ),
		m_samplesSincePhaseChanged( 9999999 )
	{

	}



	inline void setAttackTime( float time )
	{
		m_attackTime = time * m_sampleRate;
	}

	inline void setDecayTime( float time )
	{
		m_decayTime = time * m_sampleRate;
	}

	virtual inline float tick( bool noteOn )
	{
		if( noteOn )
		{
			m_phase = attack;
			m_samplesSincePhaseChanged = 0;
		}
		m_samplesSincePhaseChanged++;
		if( m_phase == decay && m_samplesSincePhaseChanged > m_decayTime )
		{
			return 0;
		}
		if( m_phase == attack )
		{
			if ( m_samplesSincePhaseChanged > m_attackTime )
			{
				m_phase = decay;
				m_samplesSincePhaseChanged = 0;
			}
			return linearInterpolate( 0, 1, (float)m_samplesSincePhaseChanged / (float)m_attackTime );
		}
		if( m_phase == decay )
		{
			return linearInterpolate( 1, 0, (float)m_samplesSincePhaseChanged / (float)m_decayTime );
		}

		return 0;

	}




private:
	qint64 m_attackTime;
	qint64 m_decayTime;
	enum Phase { attack, decay, count };
	Phase m_phase;
	qint64 m_samplesSincePhaseChanged;


};

#endif // AD_H
