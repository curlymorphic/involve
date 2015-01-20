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

#ifndef DEMO1MODULECONTROLS_H
#define DEMO1MODULECONTROLS_H

#include <QObject>
#include "ModuleControls.h"
#include "Model.h"

///
/// \brief The Demo1ModuleControls class
/// A simple single oscillator ADSR LFO Filter Delay example
class Demo1ModuleControls : public ModuleControls
{
	Q_OBJECT
public:
	explicit Demo1ModuleControls( QObject *parent = 0 );

	~Demo1ModuleControls()
	{

	}



	Model cutOffModel;
	Model resModel;
	Model waveShapeModel;
	Model attackModel;
	Model decayModel;
	Model sustainModel;
	Model releaseModel;

	Model lfoSpeedModel;
	Model lfoShapeModel;
	Model lfoGainModel;
	Model lfoFilterModel;

	Model delayAmmountModel;
	Model delayTimeModel;
	Model delayRegenModel;


};

#endif // DEMO1MODULECONTROLS_H
