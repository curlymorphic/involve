#include "Analyser.h"
#include "AudioMath.h"
#include <QDebug>


Analyser::Analyser(int size, int sampleRate) :
	AudioProcess( sampleRate )
{
	m_bands = new float[ size * 2 ];
	m_audioBuffer = new float[ size ];

	m_sinTable = new float*[ size ];
	for( int i = 0; i < size; ++i )
	{
		m_sinTable[ i ] = new float[ size ];
	}

	m_cosTable = new float*[ size ];
	for( int i = 0; i < size; ++i )
	{
		m_cosTable[ i ] = new float[ size ];
	}
	for( int n = 0; n < size; ++n )
	{
		for( int k = 0; k < size; ++k )
		{
			m_sinTable[ k ][ n ] = sin( k * n * F_2PI / size );
			m_cosTable[ k ][ n ] = cos( k * n * F_2PI / size );
		}
	}
}

Analyser::~Analyser()
{

}

void Analyser::dft( float *in, float *out, int N )
{
	for( int i = 0, k = 0; k < N; i +=2, k++)
	{
		out[ i ] = out[ i + 1 ] = 0.f;
		for( int n = 0; n < N; n++ )
		{
//			out[ i ] += in[ n ] * m_cosTable[ k ][ n ];
			out[ i + 1 ] -= in[ n ] * m_sinTable[ k ][ n ];
		}
		out[ i ] /= N;
		out[ i + 1 ] /= N;
	}
	m_bandCount = N;
}

void Analyser::idft( float *in, float *out, int N )
{
	for( int n = 0; n < N ; ++n)
	{
		out[ n ] = 0.f;
		for( int k = 0, i = 0; k < N; k++, i += 2 )
		{
			out[ n ] += in[ i ] * m_cosTable[ k ][ n ] - in[ i + 1 ] * m_sinTable[ k ][ n ];
		}
	}
}

void Analyser::processAudio(sampleFrame *buffer, int len)
{
	if ( len != bandCount() )
	{
		qDebug( "requested buffer size and band count are not the same \n" );
		return;
	}
	idft( m_bands, m_audioBuffer, bandCount() );
	for( int f = 0; f < len; ++f )
	{
		buffer[ f ][ 0 ] = m_audioBuffer[ f ];
		buffer[ f ][ 1 ] = m_audioBuffer[ f ];
	}
}

void Analyser::analyseAudio(sampleFrame *buffer, int len)
{
	for( int f = 0; f < len; ++f)
	{
		m_audioBuffer[ f ] = buffer[ f ][ 0 ];
	}
	dft( m_audioBuffer, m_bands, len );
}

