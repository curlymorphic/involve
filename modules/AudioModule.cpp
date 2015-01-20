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

#include "AudioModule.h"

AudioModule::AudioModule(qint64 samplerate, ModuleControls *controls ) :
	AudioProcess( samplerate ),
	m_controls( controls )
{
	connect( &controls->noteOnModel, SIGNAL(dataChanged( float ) ), this, SLOT( notePressed( float ) ) );
}

AudioModule::~AudioModule()
{

}

void AudioModule::processAudio(sampleFrame *buffer, qint64 len)
{
	memset( buffer, 0, sizeof(sampleFrame) * len );

}

void AudioModule::notePressed(float val)
{
	if( val ) { noteOn(); }
	else { noteOff(); }
}

void AudioModule::noteOn()
{

}

void AudioModule::noteOff()
{

}

