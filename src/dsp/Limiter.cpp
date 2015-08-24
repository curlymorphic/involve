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

#include "Limiter.h"


Limiter::Limiter(int sampleRate) :
	AudioProcess( sampleRate ),
	m_leftDetector( sampleRate ),
	m_rightDetector( sampleRate ),
	m_threshold( 0.7 )
{
	setInGain( 0.0 );
	setOutGain( 0.0 );
}

Limiter::~Limiter()
{

}

void Limiter::tick(sampleFrame *frame)
{

	float leftDetector = m_leftDetector.tick( frame[0][0] );
	float rightDetector = m_rightDetector.tick( frame[0][1] );


	float Gl = calcCompressorGain( leftDetector, m_threshold );
	float Gr = calcCompressorGain( rightDetector, m_threshold );

	frame[0][0] *= Gl;
	frame[0][1] *= Gr;
}

float Limiter::calcCompressorGain(float dectortValue, float threshold )
{
	//compute gain
//	float yG = threshold - dectortValue;
	float yG = threshold / dectortValue ;
	yG = fmin( 1.0f, yG );
	return  yG;
//	return powf( 10.0, yG/20.0 );
}

