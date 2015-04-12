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


#include "Demo2AudioModule.h"



Demo2AudioModule::Demo2AudioModule(qint64 samplerate, ModuleControls *controls) :
	AudioModule( samplerate, controls ),
	m_controls( (Demo2ModuleControls*)controls )
{
	m_oscA = new ExtendableSegementOscillator( 2, samplerate );
	m_oscB = new WTOscillator( samplerate );
	m_gain = new Gain( samplerate );
	m_oscA->setCycleHalf( 0,0, WT_SAW );
	m_oscA->setCycleHalf( 0, 1, WT_SAW );
	m_oscA->setCycleHalf( 1, 0, WT_SAW );
	m_oscA->setCycleHalf( 1, 1, WT_SAW );
}

Demo2AudioModule::~Demo2AudioModule()
{
	delete m_oscA;
	delete m_oscB;
	delete m_gain;
}

void Demo2AudioModule::processAudio(sampleFrame *buffer, int len)
{
	if( m_controls )
	{
		for( int f = 0 ; f < len; ++f )
		{
			m_oscA->setFrequency( m_controls->freqModel.value() );
//			m_oscB->setFrequency( m_controls->freqModel.value() + 100 );
//			m_oscA->setShape( (WTWaveShape)(int)m_controls->waveShapeAModel.value() );
//			m_oscB->setShape( (WTWaveShape)(int)m_controls->waveShapeBModel.value() );
			m_gain->setGain( m_controls->velocityModel.value() );
			m_oscA->tick( &buffer[f] );
			m_gain->tick( &buffer[f] );
		}
	}
}

void Demo2AudioModule::noteOn()
{

}

void Demo2AudioModule::noteOff()
{

}

