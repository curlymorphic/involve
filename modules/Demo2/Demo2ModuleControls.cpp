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

#include "Demo2ModuleControls.h"
#include "SegmentOscillator.h"
#include "ExtendableSegementOscillator.h"

Demo2ModuleControls::Demo2ModuleControls(QObject *parent)  : ModuleControls( parent ),
	oscASegmentCountModel( 4, 1, SegmentOscillator::maxSegmentCount + 0.9, 1, tr( "Segs" ) ),
	oscARetriggerModel( 1, 0, 1, 1, tr( "Retrig" ) ),
	oscAGainModel( 1, 0, 1 ,0.001 , tr( "Gain" ) ),
	oscACourseDetuneMode( 1, 0.125 , 3, 0.001, tr("Course" ) ),
	oscAFineDetuneMode( 1, 0.90 , 1.10, 0.001, tr("Course" ) ),
	oscBSegmentCountModel( 4, 1, SegmentOscillator::maxSegmentCount + 0.9, 1, tr( "Segs" ) ),
	oscBRetriggerModel( 1, 0, 1, 1, tr( "Retrig" ) ),
	oscBGainModel( 1, 0, 1 ,0.001 , tr( "Gain" ) ),
	oscBCourseDetuneMode( 1, 0.125 , 3, 0.001, tr("Course" ) ),
	oscBFineDetuneMode( 1, 0.90 , 1.10, 0.001, tr("Course" ) ),
	lfoSegmentCountModel( 4, 1, ExtendableSegementOscillator::maxSegmentCount, 1, tr( "Segs" ) ),
	lfoRetriggerModel( 1, 0, 1, 1, tr( "Retrig" ) ),
	mixModeModel( 0, 0, MIXMODE_COUNT + 0.9 , 0.5, tr( " Mode ") ),
	cutoffModel( 10000, 50, 10000,1, tr( "Cut" ) ),
	resModel( 0.707, 0.707, 5, 0.001, tr( "Res" ) ),
	attackModel(1.0, 0.01 , 5 , 0.01, tr( "Atk" ) ),
	decayModel(1.0, 0.01 , 5 , 0.01, tr( "Dcy" ) ),
	sustainModel(0.9, 0, 1 , 0.01, tr( "Sus" ) ),
	releaseModel(3.0, 0.01 , 5 , 0.01, tr( "Rel" ) ),
	lfoSpeedModel(0.1, 0.01, 3, 0.01, tr( "Spd lfo" ) ),
	lfoGainModel(0.0, 0.0, 1.0, 0.01, tr( "Amp lfo " ) ),
	lfoFilterModel(0.0, 0.0, 1.0, 0.01, tr( "Filt lfo" ) )

{
	oscAWaveShapeModels = new Model*[ SegmentOscillator::maxSegmentCount ];
	for(int i = 0; i < SegmentOscillator::maxSegmentCount ; ++i )
	{
		oscAWaveShapeModels[ i ] = new Model( 2, 0, WT_WAVESHAPECOUNT, 1, tr( "Wave" ) );
	}
	oscBWaveShapeModels = new Model*[ SegmentOscillator::maxSegmentCount ];
	for(int i = 0; i < SegmentOscillator::maxSegmentCount ; ++i )
	{
		oscBWaveShapeModels[ i ] = new Model( 2, 0, WT_WAVESHAPECOUNT, 1, tr( "Wave" ) );
	}
	lfoWaveShapeModels = new Model*[ SegmentOscillator::maxSegmentCount ];
	for(int i = 0; i < SegmentOscillator::maxSegmentCount ; ++i )
	{
		lfoWaveShapeModels[ i ] = new Model( 2, 0, WT_WAVESHAPECOUNT, 1, tr( "Wave" ) );
	}
}

Demo2ModuleControls::~Demo2ModuleControls()
{
	for(int i = 0; i < SegmentOscillator::maxSegmentCount ; ++i )
	{
		delete oscAWaveShapeModels[ i ];
		delete oscBWaveShapeModels[ i ];
		delete lfoWaveShapeModels[ i ];
	}
	delete[] oscAWaveShapeModels;
	delete[] oscBWaveShapeModels;
	delete[] lfoWaveShapeModels;
}

