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

#ifndef SUPERSAWMODULEVIEW_H
#define SUPERSAWMODULEVIEW_H

#include <QObject>
#include <QWidget>
#include "ModuleView.h"
#include "SuperSawerModuleControls.h"
#include "Fader.h"
#include "VFader.h"
#include "ModuleFader.h"

class SuperSawModuleView : public ModuleView
{
	Q_OBJECT
public:
	SuperSawModuleView( SuperSawerModuleControls *controls = 0, QWidget *parent = 0 , Qt::WindowFlags flags = 0 );
	~SuperSawModuleView();
	virtual void layout();
	
private:
	SuperSawerModuleControls *m_controls;
	
	ModuleFader *m_seperationFader;
	
	ModuleFader *m_cutOffFader;
	ModuleFader *m_resFader;
	
	ModuleFader *m_attackFader;
	ModuleFader *m_decayFader;
	ModuleFader *m_sustainFader;
	ModuleFader *m_releaseFader;
	
	ModuleFader *m_subFader;
	
	
};

#endif // SUPERSAWMODULEVIEW_H
