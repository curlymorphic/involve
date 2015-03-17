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



#ifndef DEMO2MODULEVIEW_H
#define DEMO2MODULEVIEW_H

#include <QObject>
#include <QWidget>
#include "ModuleView.h"
#include "Demo2ModuleControls.h"
#include "Fader.h"
#include "VFader.h"
#include "ModuleFader.h"

class Demo2ModuleView : public ModuleView
{
	Q_OBJECT
public:
	Demo2ModuleView(ModuleControls *controls, QWidget *parent = 0 , Qt::WindowFlags flags = 0 );
	~Demo2ModuleView();
	virtual void layout();

	private:
		Demo2ModuleControls *m_controls;

		ModuleFader *m_waveShapeAFader;
		ModuleFader *m_waveShapeBFader;
};

#endif // DEMO2MODULEVIEW_H
