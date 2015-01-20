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

#include "Oscillator.h"



Oscillator::Oscillator( qint64 sampleRate ) :
	AudioProcess( sampleRate ),
	m_phase_increment( 0.003 ),
	m_current( 0 )
{

}

Oscillator::~Oscillator()
{

}

void Oscillator::setFrequency(float frequency)
{
	m_phase_increment = frequency / m_sampleRate;
}


inline void Oscillator::tick(sampleFrame *frame)
{
	tick();
	frame[0][0] = m_current;
	frame[0][1] = m_current;
}

float Oscillator::tick()
{
	m_current += m_phase_increment;
	if( m_current > 0.5) { m_current -= 1.0; }
	return m_current;
}


