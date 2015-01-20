#ifndef AUDIOMODULE_H
#define AUDIOMODULE_H

#include "AudioProcess.h"
#include "Oscillator.h"
#include "ModuleControls.h"

#include <QtCore>

///
/// \brief The AudioModule class
///
/// This is the bass class to be inherited from for making audio devices,
/// this is where the audio processing happens
/// There is only one per active application.
///

class AudioModule : public AudioProcess
{
	Q_OBJECT
public:
	///
	/// \brief AudioModule
	/// \param samplerate Audio Sample rate
	/// \param controls	The data controls for this module
	///
	AudioModule( qint64 samplerate, ModuleControls *controls );
	~AudioModule();
	///
	/// \brief processAudio
	/// \param buffer The audiobuffer to use
	/// \param len number of stereo frames in buffer
	///
	/// This is where the action happens
	///
	virtual void processAudio(sampleFrame *buffer, qint64 len );

protected slots:
	///
	/// \brief notePressed
	/// \param val
	/// called upon change to note on off status
	void notePressed( float val );

protected:

	///
	/// \brief noteOn
	/// To be overridden, called when there is a new note
	virtual void noteOn();
	///
	/// \brief noteOff
	///To be overridden, called when the note is released
	virtual void noteOff();
	ModuleControls m_controls;


};

#endif // AUDIOMODULE_H
