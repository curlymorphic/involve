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

#ifndef MODULECONTROLS
#define MODULECONTROLS

#include "Controls.h"

///
/// \brief The ModuleControls class
/// Base class for module controls
class ModuleControls : public Controls
{
public:
	explicit ModuleControls( QObject *parent = 0) :
		Controls( parent ),
		noteOnModel( 0, 0, 1 , 1 , tr( "Note Playing" ) ),
		freqModel(100.0, 65.4, 130.8, 0.1, tr ( "Frequency" ) , this ),
		velocityModel(0.5, 0.0, 1.0, 0.1, tr( "Gain" ), this )
	{

	}

	~ModuleControls()
	{

	}

	Model noteOnModel;
	Model freqModel;
	Model velocityModel;
};

#endif // MODULECONTROLS

