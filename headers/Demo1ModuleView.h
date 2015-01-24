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
#include "ModuleFader.h"

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


	ModuleFader *m_cutOffFader;
	ModuleFader *m_resFader;
	ModuleFader *m_waveShapeFader;

	ModuleFader *m_attackFader;
	ModuleFader *m_decayFader;
	ModuleFader *m_sustainFader;
	ModuleFader *m_releaseFader;

	ModuleFader *m_adsrGainFader;
	ModuleFader *m_adsrFilterFader;
	ModuleFader *m_lfoSpeedFader;
	ModuleFader *m_lfoShapeFader;
	ModuleFader *m_lfoGainFader;
	ModuleFader *m_lfoFilterFader;

	ModuleFader *m_delayAmmountFader;
	ModuleFader *m_delayTimeFader;
	ModuleFader *m_delayRegenFader;

};

#endif // DEMO1MODULEVIEW_H
