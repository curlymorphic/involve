#ifndef STEREODELAY_H
#define STEREODELAY_H

#include "AudioMath.h"
#include "AudioProcess.h"

///
/// \brief The StereoDelay class
/// Stereo delay module
class StereoDelay : public AudioProcess
{
public:
	StereoDelay( int maxLength, int sampleRate );
	~StereoDelay();
	inline void setLength( float length )
	{
		length *= m_sampleRate;
		if( length <= m_maxLength && length >= 0 )
		{
			m_length = length;
		}
	}

	inline void setFeedback( float feedback )
	{
		m_feedback = feedback;
	}

	void tick( sampleFrame frame );
	void setSampleRate( int sampleRate );

private:
	sampleFrame* m_buffer;
	int m_maxLength;
	float m_length;
	int m_index;
	float m_feedback;
	float m_maxTime;
};

#endif // STEREODELAY_H
