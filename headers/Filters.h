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

#ifndef FILTERS_H
#define FILTERS_H

#include "AudioProcess.h"
#include "AudioMath.h"

///
/// \brief The BiQuad class
/// Standard BiQuad implementation. base class for filters
class BiQuad
{
public:
	BiQuad()
	{
		clear();
	}
	virtual ~BiQuad() {}

	inline void setCoeffs( float a1, float a2, float b0, float b1, float b2 )
	{
		m_a1 = a1;
		m_a2 = a2;
		m_b0 = b0;
		m_b1 = b1;
		m_b2 = b2;
	}
	inline void clear()
	{
		if( isnanf( m_z1[ 0 ] ) )
		{
			for( int i = 0; i < 2; ++i )
			{
				m_z1[i] = 0.0f;
				m_z2[i] = 0.0f;
			}
		}
	}
	inline float update( float in, int ch )
	{
		// biquad filter in transposed form
		const float out = m_z1[ch] + m_b0 * in;
		m_z1[ch] = m_b1 * in + m_z2[ch] - m_a1 * out;
		m_z2[ch] = m_b2 * in - m_a2 * out;
		return out;
	}
private:
	float m_a1, m_a2, m_b0, m_b1, m_b2;
	float m_z1 [2], m_z2 [2];

};




///
/// \brief The EqFilter class.
/// A wrapper for the StereoBiQuad class, giving it freq, res, and gain controls.
/// It is designed to process periods in one pass, with recalculation of coefficents
/// upon parameter changes. The intention is to use this as a bass class, children override
/// the calcCoefficents() function, providing the coefficents a1, a2, b0, b1, b2.
///
class Filter : public BiQuad, public AudioProcess
{
public:
	Filter( int samplerate ) :
		BiQuad(),
		AudioProcess( samplerate )
	{

	}





	virtual inline void setFrequency( float freq ){
		if ( freq != m_freq )
		{
			m_freq = qBound( 35.0f , freq, 20000.0f );
			calcCoefficents();
		}
	}




	virtual void setQ( float res )
	{
		if ( res != m_res )
		{
			m_res = res;
			calcCoefficents();
		}
	}




	virtual void setGain( float gain )
	{
		if ( gain != m_gain )
		{
			m_gain = gain;
			calcCoefficents();
		}
	}



	virtual inline void setParameters( float freq, float res, float gain = 1.0 )
	{
		bool hasChanged = false;
		if ( freq != m_freq )
		{
			m_freq = qBound( 55.0f , freq, 20000.0f );
			hasChanged = true;
		}
		if ( res != m_res )
		{
			m_res = qBound( 0.6f , res, 5.0f );
			hasChanged = true;
		}
		if ( gain != m_gain )
		{
			m_gain = gain;
			hasChanged = true;
		}

		if ( hasChanged ) { calcCoefficents(); }
	}




	///
	/// \brief processBuffer
	/// \param buf Audio Buffer
	/// \param frames Count of sampleFrames in Audio Buffer
	///
	virtual void processBuffer( sampleFrame* buf, int frames )
	{
		for ( int f = 0 ; f < frames ; ++f)
		{
			tick( &buf[f] );
		}
	}

	virtual inline void tick(sampleFrame *frame)
	{
		frame[0][0] = update( frame[0][0] , 0);
		frame[0][1] = update( frame[0][1] , 1);
	}

protected:
	///
	/// \brief calcCoefficents
	///  Override this in child classes to provide the coefficents, based on
	///  Freq, Res and Gain
	virtual void calcCoefficents(){
		setCoeffs( 0, 0, 0, 0, 0 );

	}

	float m_freq;
	float m_res;
	float m_gain;
};




///
/// \brief The EqHp12Filter class
/// A 2 pole High Pass Filter
/// Coefficent calculations from http://www.musicdsp.org/files/Audio-EQ-Cookbook.txt
class Hp12 : public Filter
{
	Hp12( int samplerate) :
			Filter( samplerate )
		{
		}
public :
	virtual void calcCoefficents()
	{

		// calc intermediate
		float w0 = f_2PI * m_freq / m_sampleRate;
		float c = cosf( w0 );
		float s = sinf( w0 );
		float alpha = s / ( 2 * m_res );

		float a0, a1, a2, b0, b1, b2; // coeffs to calculate

		//calc coefficents
		b0 = ( 1 + c ) * 0.5;
		b1 = ( -( 1 + c ) );
		b2 = ( 1 + c ) * 0.5;
		a0 = 1 + alpha;
		a1 = ( -2 * c );
		a2 = 1 - alpha;

		//normalise
		b0 /= a0;
		b1 /= a0;
		b2 /= a0;
		a1 /= a0;
		a2 /= a0;

		a0 = 1;

		setCoeffs( a1, a2, b0, b1, b2 );


	}
};




///
/// \brief The EqLp12Filter class.
/// A 2 pole low pass filter
/// Coefficent calculations from http://www.musicdsp.org/files/Audio-EQ-Cookbook.txt
///
class Lp12 : public Filter
{
public :
	explicit Lp12( int samplerate = 44100 ) :
		Filter( samplerate )
	{
	}
	virtual void calcCoefficents()
	{

		// calc intermediate
		float w0 = f_2PI * m_freq / m_sampleRate;
		float c = cosf( w0 );
		float s = sinf( w0 );
		float alpha = s / ( 2 * m_res );

		float a0, a1, a2, b0, b1, b2; // coeffs to calculate

		//calc coefficents
		b0 = ( 1 - c ) * 0.5;
		b1 = 1 - c;
		b2 = ( 1 - c ) * 0.5;
		a0 = 1 + alpha;
		a1 = -2 * c;
		a2 = 1 - alpha;

		//normalise
		b0 /= a0;
		b1 /= a0;
		b2 /= a0;
		a1 /= a0;
		a2 /= a0;

		a0 = 1;

		setCoeffs( a1, a2, b0, b1, b2 );
	}
};



///
/// \brief The EqPeakFilter class
/// A Peak Filter
/// Coefficent calculations from http://www.musicdsp.org/files/Audio-EQ-Cookbook.txt
///
class PeakFilter : public Filter
{
public:
	PeakFilter( int samplerate) :
		Filter( samplerate )
	{
	}


	virtual void calcCoefficents()
	{
		// calc intermediate
		float w0 = f_2PI * m_freq / m_sampleRate;
		float c = cosf( w0 );
		float s = sinf( w0 );
		float A =  pow( 10, m_gain * 0.025);
		float alpha = s / ( 2 * m_res );

		float a0, a1, a2, b0, b1, b2; // coeffs to calculate

		//calc coefficents
		b0 =   1 + alpha*A;
		b1 =  -2*c;
		b2 =   1 - alpha*A;
		a0 =   1 + alpha/A;
		a1 =  -2*c;
		a2 =   1 - alpha/A;

		//normalise
		b0 /= a0;
		b1 /= a0;
		b2 /= a0;
		a1 /= a0;
		a2 /= a0;
		a0 = 1;

		setCoeffs( a1, a2, b0, b1, b2 );
	}
};




class LowShelf : public Filter
{
public :
	LowShelf( int samplerate) :
		Filter( samplerate )
	{
	}
	virtual void calcCoefficents()
	{

		// calc intermediate
		float w0 = f_2PI * m_freq / m_sampleRate;
		float c = cosf( w0 );
		float s = sinf( w0 );
		float A =  pow( 10, m_gain * 0.025);
		//        float alpha = s / ( 2 * m_res );
		float beta = sqrt( A ) / m_res;

		float a0, a1, a2, b0, b1, b2; // coeffs to calculate

		//calc coefficents
		b0 = A * ( ( A+1 ) - ( A-1 ) * c + beta * s );
		b1 = 2  * A * ( ( A - 1 ) - ( A + 1 ) * c) ;
		b2 = A * ( ( A + 1 ) - ( A - 1 ) * c - beta * s);
		a0 = ( A + 1 ) + ( A - 1 ) * c + beta * s;
		a1 = -2 * ( ( A - 1 ) + ( A + 1 ) * c );
		a2 = ( A + 1 ) + ( A - 1) * c - beta * s;

		//normalise
		b0 /= a0;
		b1 /= a0;
		b2 /= a0;
		a1 /= a0;
		a2 /= a0;

		a0 = 1;

		setCoeffs( a1, a2, b0, b1, b2 );


	}
};

class HighShelf : public Filter
{
public :
	HighShelf( int samplerate) :
		Filter( samplerate )
	{
	}
	virtual void calcCoefficents()
	{

		// calc intermediate
		float w0 = f_2PI * m_freq / m_sampleRate;
		float c = cosf( w0 );
		float s = sinf( w0 );
		float A =  pow( 10, m_gain * 0.025 );
		float beta = sqrt( A ) / m_res;

		float a0, a1, a2, b0, b1, b2; // coeffs to calculate

		//calc coefficents
		b0 = A *( ( A +1 ) + ( A - 1 ) * c + beta * s);
		b1 = -2 * A * ( ( A - 1 ) + ( A + 1 ) * c );
		b2 = A * ( ( A + 1 ) + ( A - 1 ) * c - beta * s);
		a0 = ( A + 1 ) - ( A - 1 ) * c + beta * s;
		a1 = 2 * ( ( A - 1 ) - ( A + 1 ) * c );
		a2 = ( A + 1) - ( A - 1 ) * c - beta * s;
		//normalise
		b0 /= a0;
		b1 /= a0;
		b2 /= a0;
		a1 /= a0;
		a2 /= a0;
		a0 = 1;

		setCoeffs( a1, a2, b0, b1, b2 );
	}
};




#endif // FILTERS_H
