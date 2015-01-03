#ifndef AUDIOPROCESS_H
#define AUDIOPROCESS_H

#include <QtCore>
#include "Types.h"


///
/// \brief The AudioProcess class
/// The bass class for audio processes that operate on periods of data
///

class AudioProcess : QObject
{
	Q_OBJECT
public:
	AudioProcess(qint64 sampleRate);
	~AudioProcess();
	virtual void processAudio( sampleFrame *buffer, qint64 len );
	void setSampleRate( qint64 sampleRate );
	qint64 getSampleRate();
	virtual void tick( sampleFrame *frame );



protected:
	qint64 m_sampleRate;
};

#endif // AUDIOPROCESS_H
