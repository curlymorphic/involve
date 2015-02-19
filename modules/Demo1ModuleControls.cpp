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

#include "Demo1ModuleControls.h"
#include "Model.h"
#include "ModuleControls.h"




Demo1ModuleControls::Demo1ModuleControls(QObject *parent) : ModuleControls( parent ),
	cutOffModel(1000, 50, 10000,1, tr( "Cut" ) ),
	resModel(1, 1, 4, 0.1, tr( "Res" ) ),
	waveShapeModel( 2, 0 , 4 , 1, tr( "Wave" ) ),
	attackModel(0.5, 0.01 , 5 , 0.01, tr( "Atk" ) ),
	decayModel(0.5, 0.01 , 5 , 0.01, tr( "Dcy" ) ),
	sustainModel(0.9, 0, 1 , 0.01, tr( "Sus" ) ),
	releaseModel(1.2, 0.01 , 5 , 0.01, tr( "Rel" ) ),
	lfoSpeedModel(0.1, 0.01, 10, 0.01, tr( "Spd lfo" ) ),
	lfoShapeModel( 2, 0 , 4 , 1, tr( "Wave lfo" ) ),
	lfoGainModel(0.0, 0.0, 1.0, 0.01, tr( "Vol lfo " ) ),
	lfoFilterModel(0.0, 0.0, 1.0, 0.01, tr( "Filt lfo" ) ),
	delayAmmountModel(0.1, 0.0, 1, 0.01, tr( "Amt Delay" ) ),
	delayTimeModel(0.2, 0.01, 1, 0.01, tr( "Time Delay" ) ),
	delayRegenModel(0.5, 0.0, 0.99, 0.01, tr( "Fb  Delay" ) )
{

}
