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
	cutOffModel(1000, 50, 10000,1, tr( "Cutoff" ) ),
	resModel(1, 1, 4, 0.1, tr( "Res" ) ),
	waveShapeModel( 2, 0 , 4 , 1, tr( "WaveShape" ) ),
	attackModel(0.1, 0.01 , 5 , 0.01, tr( "attack" ) ),
	decayModel(0.1, 0.01 , 5 , 0.01, tr( "decay" ) ),
	sustainModel(0.5, 0, 1 , 0.01, tr( "sustain" ) ),
	releaseModel(0.1, 0.01 , 5 , 0.01, tr( "release" ) ),
	lfoSpeedModel(0.01, 0.01, 10, 0.01, tr( "lfo speed" ) ),
	lfoShapeModel( 2, 0 , 4 , 1, tr( "LfoShape" ) ),
	lfoGainModel(0.0, 0.0, 1.0, 0.01, tr( "Lfo > Vol " ) ),
	lfoFilterModel(1.0, 0.0, 1.0, 0.01, tr( "Lfo > cutoff " ) ),
	delayAmmountModel(0.00, 0.0, 1, 0.01, tr( "Delay Ammount" ) ),
	delayTimeModel(0.05, 0.01, 1, 0.01, tr( " Delay time " ) ),
	delayRegenModel(0.0, 0.0, 0.99, 0.01, tr( "regen" ) )
{

}
