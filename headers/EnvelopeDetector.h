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

#ifndef ENVELOPEDETECTOR_H
#define ENVELOPEDETECTOR_H

#include "AudioMath.h"

///
/// \brief The EnvelopeDetector class
/// Envelope follower
/// use tick(current sample) will return envelope val.

class EnvelopeDetector
{
public:
	EnvelopeDetector( int sampleRate )
	{
		m_currentValue = 0.0;
		m_sampleRate = sampleRate;
		setAttack( 0.0001 );
		setRelease( 0.05 );
	}

	~EnvelopeDetector()
	{
	}

	float tick( float in )
	{
		float tmp = fabsf( in );
		if( tmp > m_currentValue )
		{
//			m_currentValue = m_attack_coef * ( m_currentValue - tmp ) + tmp;
			m_currentValue *= m_attack_coef;
			m_currentValue += (1-m_attack_coef) * tmp;
		}
		else
		{
//			m_currentValue = m_release_coef * (m_currentValue - tmp ) + tmp;/
			m_currentValue *= m_release_coef;
			m_currentValue += ( 1 - m_release_coef ) * tmp;
		}
		return m_currentValue;
	}

	void setAttack( float seconds )
	{
		m_attack_coef = expf(-1 /( m_sampleRate *  seconds ) );
	}

	void setRelease( float seconds )
	{
		m_release_coef = expf(-1 /( m_sampleRate * seconds ) );
	}

private:
	float m_attack_coef;
	float m_release_coef;
	int m_sampleRate;
	float m_currentValue;
};

#endif // ENVELOPEDETECTOR_H
