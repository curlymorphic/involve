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

#ifndef DEMO1AUDIOMODULE_H
#define DEMO1AUDIOMODULE_H

//#include <QObject>
#include "AudioModule.h"
#include "Demo1ModuleControls.h"
#include "Gain.h"
#include "Lfo.h"
#include "Filters.h"
#include "AD.h"
#include "ADSR.h"
#include "WTOscillator.h"
#include "StereoDelay.h"

///
/// \brief The Demo1AudioModule class
/// A simple single oscillator ADSR LFO Filter Delay example
class Demo1AudioModule : public AudioModule
{
public:
	Demo1AudioModule(qint64 samplerate, Demo1ModuleControls *controls);
	~Demo1AudioModule();
	virtual void processAudio(sampleFrame *buffer, int len );

protected:

	virtual void noteOn();
	virtual void noteOff();



private:
	WTOscillator *m_osc;
	Gain *m_gain;
	WTOscillator *m_volLfo;
	Lp12 *m_lp;
	Lp12 *m_lp2;
	Adsr *m_ad;
	StereoDelay *m_delay;
	Demo1ModuleControls *m_controls;
	sampleFrame *delayedFrame;


};

#endif // DEMO1AUDIOMODULE_H
