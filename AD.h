#ifndef AD_H
#define AD_H

#include <QtCore>
#include "ControlGenerator.h"
#include "Interpolation.h"

class AD : public ControlGenerator
{
public:
	AD( qint64 sampleRate ) :
		ControlGenerator( sampleRate ),
		m_attackTime( 20000 ),
		m_decayTime( 35000 ),
		m_phase( Phase::decay ),
		m_samplesSincePhaseChanged( 9999999 )
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

	virtual inline float tick( bool noteOn )
	{
		if( noteOn )
		{
			m_phase = attack;
			m_samplesSincePhaseChanged = 0;
		}
		m_samplesSincePhaseChanged++;
		if( m_phase == decay && m_samplesSincePhaseChanged > m_decayTime )
		{
			return 0;
		}
		if( m_phase == attack )
		{
			if ( m_samplesSincePhaseChanged > m_attackTime )
			{
				m_phase = decay;
				m_samplesSincePhaseChanged = 0;
			}
			return linearInterpolate( 0, 1, (float)m_samplesSincePhaseChanged / (float)m_attackTime );
		}
		if( m_phase == decay )
		{
			return linearInterpolate( 1, 0, (float)m_samplesSincePhaseChanged / (float)m_decayTime );
		}

		return 0;

	}




private:
	qint64 m_attackTime;
	qint64 m_decayTime;
	enum Phase { attack, decay, count };
	Phase m_phase;
	qint64 m_samplesSincePhaseChanged;


};

#endif // AD_H
