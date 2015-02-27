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

#ifndef LFO_H
#define LFO_H

#include <QtCore>
#include "ControlGenerator.h"


///
/// \brief The Lfo class
/// cheep and nasty saw wave, will aliase
class Lfo : public ControlGenerator
{
public:
	Lfo( int sampleRate );
	~Lfo();
	void setFrequency( float freq );
	virtual inline float tick()
	{
		m_currentValue += m_increment;
		if( m_currentValue > 0.5 ) { m_currentValue -= 1.0; }
		return m_currentValue;
	}

protected:
	float m_increment;
	float m_currentValue;
};

#endif // LFO_H
