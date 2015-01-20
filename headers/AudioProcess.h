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
