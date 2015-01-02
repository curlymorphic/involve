#ifndef AUDIOMODULE_H
#define AUDIOMODULE_H

#include "AudioProcess.h"
#include "Oscillator.h"
#include "Controls.h"

#include <QtCore>

///
/// \brief The AudioModule class
///
/// This is the bass class to be inherited from for making audio devices,
/// this is where the audio processing happens
/// There is only one per active application.
///

class AudioModule : AudioProcess
{
public:
	///
	/// \brief AudioModule
	/// \param samplerate Audio Sample rate
	/// \param controls	The data controls for this module
	///
	AudioModule( qint64 samplerate, Controls *controls );
	~AudioModule();
	///
	/// \brief processAudio
	/// \param buffer The audiobuffer to use
	/// \param len number of stereo frames in buffer
	///
	/// This is where the action happens
	///
	virtual void processAudio(sampleFrame *buffer, qint64 len );

private:
	Oscillator *m_osc;
	Controls *m_controls;

};

#endif // AUDIOMODULE_H
