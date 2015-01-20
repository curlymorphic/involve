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

#include "AudioProcess.h"
#include <QtCore>

AudioProcess::AudioProcess(qint64 sampleRate) :
	m_sampleRate( sampleRate )
{

}

AudioProcess::~AudioProcess()
{

}

void AudioProcess::processAudio(sampleFrame *buffer, qint64 len)
{
	for( int i =0; i < len; i++)
	{
		tick( &buffer[i] );
	}

}

void AudioProcess::setSampleRate(qint64 sampleRate)
{
	m_sampleRate = sampleRate;
}

qint64 AudioProcess::getSampleRate()
{
	return m_sampleRate;
}

void AudioProcess::tick(sampleFrame *frame)
{
	frame[0][0] = 0.0;
	frame[0][1] = 0.0;
}
