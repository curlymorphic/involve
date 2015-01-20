/*
 * Copyright (c) 2014-2015 Dave French <contact/dot/dave/dot/french3/at/googlemail/dot/com>
 *
 * This file is part of Involve - http://github.com/curlymorphic/involve
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */

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
