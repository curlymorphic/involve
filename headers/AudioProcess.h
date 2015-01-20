#ifndef AUDIOPROCESS_H
#define AUDIOPROCESS_H

#include <QtCore>
#include "Types.h"
//#include "AudioMath.h"


///
/// \brief The AudioProcess class
/// The bass class for audio processes that operate on periods of data
///

class AudioProcess : public QObject
{
	Q_OBJECT
public:
	AudioProcess(qint64 sampleRate);
	~AudioProcess();
	///
	/// \brief processAudio
	/// \param buffer
	/// \param len
	/// process the period data
	virtual void processAudio( sampleFrame *buffer, qint64 len );
	void setSampleRate( qint64 sampleRate );
	qint64 getSampleRate();
	///
	/// \brief tick
	/// \param frame
	/// process single frame
	virtual void tick( sampleFrame *frame );



protected:
	qint64 m_sampleRate;
};

#endif // AUDIOPROCESS_H
