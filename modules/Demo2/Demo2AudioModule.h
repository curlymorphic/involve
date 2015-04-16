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

#ifndef DEMO2AUDIOMODULE_H
#define DEMO2AUDIOMODULE_H

#include <QObject>
#include "AudioModule.h"
#include "Demo2ModuleControls.h"
#include "Gain.h"
#include "WTOscillator.h"
#include "SegmentOscillator.h"
#include "ExtendableSegementOscillator.h"
#include "Filters.h"
#include "ADSR.h"


class Demo2AudioModule : public AudioModule
{
public:
	Demo2AudioModule(qint64 samplerate, ModuleControls *controls);
	virtual ~Demo2AudioModule();
	virtual void processAudio(sampleFrame *buffer, int len );

protected:

	virtual void noteOn();
	virtual void noteOff();

private:
	SegmentOscillator *m_oscA;
	SegmentOscillator *m_oscB;
	Gain *m_gain;
	ExtendableSegementOscillator *m_lfo;
	Lp12 *m_filter;
	Adsr *m_adsr;




	Demo2ModuleControls *m_controls;

};

#endif // DEMO2AUDIOMODULE_H
