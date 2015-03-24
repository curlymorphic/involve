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

#ifndef AUDIODEVICE_H
#define AUDIODEVICE_H

#include <qiodevice.h>
#include <QAudioFormat>
#include "Types.h"
#include "AudioModule.h"
#include "AudioDeviceControls.h"
#include <QAudioOutput>
#include <QByteArray>
#include <QIODevice>
#include "Limiter.h"
//#include "Analyser.h"
#include "ModuleManager.h"

///
/// \brief The AudioDevice class
/// The main audio engine, pulls data and converts to audio buffer.
class AudioDevice: public QIODevice
{
	Q_OBJECT

public:
	AudioDevice(const QAudioFormat &format, ModuleManager *mm, AudioDeviceControls * adc, QObject *parent = 0 );
	virtual ~AudioDevice();
	
	static const int bufferSize = 256;

	void start();
	void stop();

	///
	/// \brief sampleFrameToBuffer
	/// \param buf
	/// \param frames
	/// \param format
	/// converts the sampleFrame bufer into the correct format for the audio card.
	void sampleFrameToBuffer(sampleFrame *buf, int frames, QAudioFormat &format);

	///
	/// \brief createAudioOutput
	/// initilise the audio
	void createAudioOutput();

	///
	/// \brief readData
	/// \param data
	/// \param maxlen
	/// \return
	/// Processes 1 period of audio data
	qint64 readData(char *data, qint64 maxlen);
	qint64 writeData(const char *data, qint64 len);
	///
	/// \brief bytesAvailable
	/// \return
	/// the frames size * 4
	qint64 bytesAvailable() const;

private slots:
	void moduleChanged( ModuleData* );

private:


//	void startAudio();

	qint64 m_pos;
	QByteArray m_buffer;
	sampleFrame *m_frameBuffer;
	QAudioFormat m_format;
	AudioModule *m_module;
	ModuleControls *m_moduleControls;
	QAudioDeviceInfo m_device;
	AudioDevice *m_audioDevice;
	QAudioOutput *m_audioOutput;
	QIODevice *m_output;
	AudioDeviceControls *m_audioDeviceControls;
	Limiter m_limiter;
//	Analyser m_analyser;



};

#endif // AUDIODEVICE_H
