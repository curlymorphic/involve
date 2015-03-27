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

#include "SuperSawerModuleControls.h"

SuperSawerModuleControls::SuperSawerModuleControls( QObject *parent ) : ModuleControls( parent ),
	seperationModel( 0.01f, 0.0f, 0.02f, 0.001f, tr( "Spread" ) ),
	cutOffModel(10000.0f, 50.0f, 10000.0f ,1.0f, tr( "Cut" ) ),
	resModel(1.0f, 1.0f, 4.0f, 0.1f, tr( "Res" ) ),
	attackModel(1.0f, 0.01f , 5.0f , 0.01f, tr( "Atk" ) ),
	decayModel(1.0f, 0.01f , 5.0f , 0.01f, tr( "Dcy" ) ),
	sustainModel(0.9f, 0.0f, 1.0f , 0.01f, tr( "Sus" ) ),
	releaseModel(3.0f, 0.01f , 5.0f , 0.01f, tr( "Rel" ) ),
	subModel( 0.04f, 0.0f, 1.0f, 0.001f, tr( "Sub" ) )
{

}



