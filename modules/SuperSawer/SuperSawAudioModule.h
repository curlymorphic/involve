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


#ifndef SUPERSAWAUDIOMODULE_H
#define SUPERSAWAUDIOMODULE_H

#include "AudioModule.h"
#include "SuperSawerModuleControls.h"
#include "Gain.h"
#include "Filters.h"
#include "ADSR.h"
#include "WTOscillator.h"

class SuperSawAudioModule : public AudioModule
{
public:
	SuperSawAudioModule( qint64 samplerate, SuperSawerModuleControls *controls );
	~SuperSawAudioModule();
	virtual void processAudio(sampleFrame *buffer, int len );
	
protected:

	virtual void noteOn();
	virtual void noteOff();

private:
	Gain *m_gain;
	Lp12 *m_lp;
	Lp12 *m_lp2;
	Adsr *m_ad;
	sampleFrame *m_oscFrames;
	sampleFrame m_subFrame;
	WTOscillator *m_oscillators;
	WTOscillator *m_subOscillator;
	SuperSawerModuleControls *m_controls;
	
	
};

#endif // SUPERSAWAUDIOMODULE_H
