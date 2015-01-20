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

#ifndef DEMO1MODULEVIEW_H
#define DEMO1MODULEVIEW_H

#include <QObject>
#include <QWidget>
#include "ModuleView.h"
#include "Demo1ModuleControls.h"
#include "Fader.h"
#include "VFader.h"

///
/// \brief The Demo1ModuleView class
/// A simple single oscillator ADSR LFO Filter Delay example
class Demo1ModuleView : public ModuleView
{
	Q_OBJECT
public:
	Demo1ModuleView( Demo1ModuleControls *controls, QWidget *parent = 0 , Qt::WindowFlags flags = 0);
	~Demo1ModuleView();
	virtual void layout();




private:
	Demo1ModuleControls *m_controls;


	VFader *m_cutOffFader;
	VFader *m_resFader;
	VFader *m_waveShapeFader;

	VFader *m_attackFader;
	VFader *m_decayFader;
	VFader *m_sustainFader;
	VFader *m_releaseFader;

	VFader *m_adsrGainFader;
	VFader *m_adsrFilterFader;
	VFader *m_lfoSpeedFader;
	VFader *m_lfoShapeFader;
	VFader *m_lfoGainFader;
	VFader *m_lfoFilterFader;

	VFader *m_delayAmmountFader;
	VFader *m_delayTimeFader;
	VFader *m_delayRegenFader;

};

#endif // DEMO1MODULEVIEW_H
