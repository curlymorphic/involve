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

#ifndef AUDIOMATH_H
#define AUDIOMATH_H

#include <math.h>
#include "Types.h"

const long double LD_PI = 3.14159265358979323846264338327950288419716939937510;
const float F_PI = (float) LD_PI;
const float F_2PI = F_PI + F_PI;

const float base_a4 = 440.0;


inline float midiNoteFreq( int note )
{
	return 440.0 * powf(2.0, (note - 69.0)/12.0);
}

inline float fraction(float val){
	return val - (int)val;
}

inline float bound(float minval, float val, float maxval )
{
	return fmax( minval, fmin( val, maxval ) );
}

//qint64 freqNeariestMidiNote( float freq )
//{
//	return round(12*log( freq / base_a4))+57;
//}


#endif // AUDIOMATH

