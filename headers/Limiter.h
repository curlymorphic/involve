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

#ifndef LIMITER_H
#define LIMITER_H

#include "AudioProcess.h"
#include "EnvelopeDetector.h"

///
/// \brief The Limiter class
/// Dynamic limiter
///
class Limiter : public AudioProcess
{
public:
	Limiter( qint64 sampleRate );
	~Limiter();
	virtual void tick( sampleFrame *frame );
	void setInGain( float dB )
	{
		m_inGain_dB = dB;
		m_inGain = powf( 10.0, m_inGain_dB / 20.0 );
	}

	void setOutGain( float dB )
	{
		m_outGain_dB = dB;
		m_outGain = powf( 10.0, m_outGain_dB/ 20.0 );
	}

	void setThreshold(float threshold )
	{
		m_threshold = threshold;
	}

private:
	EnvelopeDetector m_leftDetector;
	EnvelopeDetector m_rightDetector;
	float m_inGain_dB;
	float m_outGain_dB;
	float m_threshold;
	float m_inGain ;
	float m_outGain;

	///
	/// \brief calcCompressorGain
	/// \param dectortValue
	/// \param threshold
	/// \param ration
	/// \param kneeWidth
	/// \param limit
	/// \return
	/// calculate the gain value from the detector output

	float calcCompressorGain( float dectortValue, float threshold );
};

#endif // LIMITER_H
