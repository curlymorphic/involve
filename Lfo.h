#ifndef LFO_H
#define LFO_H

#include <QtCore>



class Lfo
{
public:
	Lfo( qint64 sampleRate );
	~Lfo();
	void setFrequency( float freq );
	inline float tick()
	{
		m_currentValue += m_increment;
		if( m_currentValue > 0.5 ) { m_currentValue -= 1.0; }
		return m_currentValue;
	}

protected:
	qint64 m_sampleRate;
	float m_increment;
	float m_currentValue;
};

#endif // LFO_H
