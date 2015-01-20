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

#include "AudioThread.h"
#include <QAudioDeviceInfo>


AudioThread::AudioThread(AudioDeviceControls *adc, AudioModule *audioModule, ModuleControls *controls, QWidget *parent):
	QThread( 0 ),
	m_audioDevice( 0 ),
	m_audioDeviceControls( adc ),
	m_controls( controls ),
	m_audioModule( audioModule )
{
	start();
	QObject::moveToThread( this );
}

AudioThread::~AudioThread()
{
	if(m_audioDevice)
	{
		delete m_audioDevice;
		m_audioDevice = 0;
	}
}

void AudioThread::run()
{
	initializeAudio();
	exec();
}

void AudioThread::initializeAudio()
{
	m_format.setSampleRate( 44100 );
	m_format.setChannelCount(2);
	m_format.setSampleSize(16);
	m_format.setCodec("audio/pcm");
	m_format.setByteOrder(QAudioFormat::LittleEndian);
	m_format.setSampleType(QAudioFormat::SignedInt);

	QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
	if (!info.isFormatSupported(m_format)) {
		qWarning() << "Default format not supported - trying to use nearest";
		m_format = info.nearestFormat(m_format);
	}
	m_audioDeviceControls->m_sampleRate = m_format.sampleRate();
	m_audioDevice = new AudioDevice( m_format, m_audioModule, m_controls, m_audioDeviceControls );
	m_audioDevice->createAudioOutput();


}

