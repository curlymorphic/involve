#ifndef CONTROLGENERATOR_H
#define CONTROLGENERATOR_H

#include "QtCore"


class ControlGenerator
{
public:
	ControlGenerator( qint64 sampleRate );
	~ControlGenerator();

	virtual inline float tick()
	{
		return 1.0;
	}

protected:
	qint64 m_sampleRate;
};

#endif // CONTROLGENERATOR_H
