#ifndef AUDIOMATH_H
#define AUDIOMATH_H

#include <qmath.h>

const long double LD_PI = 3.14159265358979323846264338327950288419716939937510;
const float F_PI = (float) LD_PI;
const float f_2PI = F_PI + F_PI;

const float base_a4 = 440.0;


inline float midiNoteFreq( qint64 note )
{
	return 440.0 * qPow(2.0, (note - 69.0)/12.0);
}

//qint64 freqNeariestMidiNote( float freq )
//{
//	return round(12*log( freq / base_a4))+57;
//}


#endif // AUDIOMATH

