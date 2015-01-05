#ifndef ADSR
#define ADSR

#include <QtCore>
#include "ControlGenerator.h"
#include "Interpolation.h"

class Adsr : ControlGenerator
{
public:
	Adsr( qint64 sampleRate ) :
		ControlGenerator( sampleRate ),
		m_attackTime( 20000 ),
		m_decayTime( 35000 ),
		m_sustainLevel( 0.5 ),
		m_releaseTime( 65000 ),
		m_phase( Phase::release ),
		m_samplesSincePhaseChanged( 999999 ),
		m_lastValue( 0 )
	{

	}

	inline void setAttackTime( float time )
	{
		m_attackTime = time * m_sampleRate;
	}

	inline void setDecayTime( float time )
	{
		m_decayTime = time * m_sampleRate;
	}

	inline void setSustainLevel( float level )
	{
		m_sustainLevel = level;
	}

	inline void setReleaseTime( qint64 time )
	{
		m_releaseTime = time;
	}

	virtual inline float tick( bool noteOn, bool noteOff )
	{
		m_samplesSincePhaseChanged++;
		if ( noteOn )
		{
			m_phase = attack;
			m_samplesSincePhaseChanged = 0;
		}
		if( noteOff )
		{
			m_phase = release;
			m_samplesSincePhaseChanged = 0;
		}
		if( m_phase == attack )
		{
			if ( m_samplesSincePhaseChanged > m_attackTime )
			{
				m_phase = decay;
				m_samplesSincePhaseChanged = 0;
			}
			m_lastValue = linearInterpolate( 0, 1, (float)m_samplesSincePhaseChanged /
											 (float)m_attackTime );
			return m_lastValue;
		}
		if( m_phase == decay )
		{
			if ( m_lastValue <= m_sustainLevel )
			{
				m_phase = sustain;
				m_samplesSincePhaseChanged = 0;
			}
			m_lastValue = linearInterpolate( 1, 0, (float)m_samplesSincePhaseChanged /
									  (float)m_decayTime );
			return m_lastValue;
		}

		if( m_phase == sustain )
		{
//			m_phase=release;
			m_lastValue = m_sustainLevel;
			return m_lastValue;
		}

		if ( m_phase == release )
		{
			if( m_samplesSincePhaseChanged >= m_releaseTime )
			{
				return 0;
			}
			return linearInterpolate( m_lastValue, 0,
									  (float)m_samplesSincePhaseChanged / (float)m_releaseTime );
		}

		return 0;

	}


private:
	qint64 m_attackTime;
	qint64 m_decayTime;
	float m_sustainLevel;
	qint64 m_releaseTime;
	enum Phase { attack, decay, sustain, release, count };
	Phase m_phase;
	qint64 m_samplesSincePhaseChanged;
	float m_lastValue;
};


#endif // ADSR

