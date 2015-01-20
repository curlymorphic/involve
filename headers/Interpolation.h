#ifndef INTERPOLATION
#define INTERPOLATION


inline float linearInterpolate( float v0, float v1, float x )
{
	return x * (v1 - v0 ) + v0;
}

#endif // INTERPOLATION

