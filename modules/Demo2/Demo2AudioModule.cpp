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
	m_oscA = new SegmentOscillator( samplerate );
	m_oscB = new SegmentOscillator( samplerate );
	m_gain = new Gain( samplerate );
	m_lfo = new ExtendableSegementOscillator( 8, samplerate );
	m_filter = new Lp12( samplerate );
	m_adsr = new Adsr( samplerate );

	m_lfo->setShape( WT_SAW );
}

Demo2AudioModule::~Demo2AudioModule()
{
	delete m_oscA;
	delete m_oscB;
	delete m_gain;
	delete m_lfo;
	delete m_filter;
	delete m_adsr;
}

void Demo2AudioModule::processAudio(sampleFrame *buffer, int len)
{
	if( m_controls )
	{
//		m_oscA->setSegment( 0, ( WTWaveShape)( m_controls->oscAWaveShapeModels[0] ->value() ) );
//		m_oscA->setSegment( 1, ( WTWaveShape )( m_controls->oscAWaveShapeModels[1] ->value() ) );
		for( int i = 0; i < SegmentOscillator::maxSegmentCount; ++i )
		{
			m_oscA->setSegment( i, ( WTWaveShape)( m_controls->oscAWaveShapeModels[i] ->value() ) );
			m_oscB->setSegment( i, ( WTWaveShape)( m_controls->oscBWaveShapeModels[i] ->value() ) );

		}
		m_oscA->setSegmentCount( m_controls->oscASegmentCountModel.value() );
		m_oscB->setSegmentCount( m_controls->oscBSegmentCountModel.value() );

		m_lfo->setCycles( m_controls->lfoSegmentCountModel.value() );
		m_lfo->setCycleHalf(0, 0, (WTWaveShape) m_controls->lfoWaveShapeModels[0]->value());
		m_lfo->setCycleHalf(0, 1, (WTWaveShape) m_controls->lfoWaveShapeModels[1]->value());
		m_lfo->setCycleHalf(1, 0, (WTWaveShape) m_controls->lfoWaveShapeModels[2]->value());
		m_lfo->setCycleHalf(1, 1, (WTWaveShape) m_controls->lfoWaveShapeModels[3]->value());
		m_lfo->setCycleHalf(2, 0, (WTWaveShape) m_controls->lfoWaveShapeModels[4]->value());
		m_lfo->setCycleHalf(2, 1, (WTWaveShape) m_controls->lfoWaveShapeModels[5]->value());
		m_lfo->setCycleHalf(3, 0, (WTWaveShape) m_controls->lfoWaveShapeModels[6]->value());
		m_lfo->setCycleHalf(3, 1, (WTWaveShape) m_controls->lfoWaveShapeModels[7]->value());
		m_lfo->setShape( WT_SAW );

		m_adsr->setAttackTime( m_controls->attackModel.value() );
		m_adsr->setDecayTime( m_controls->decayModel.value() );
		m_adsr->setSustainLevel( m_controls->sustainModel.value() );
		m_adsr->setReleaseTime( m_controls->releaseModel.value() );

		sampleFrame sigA;
		sampleFrame sigB;

		for( int f = 0 ; f < len; ++f )
		{
//			sigA = sigB = 0;
			m_oscA->setFrequency( m_controls->freqModel.value() * m_controls->oscACourseDetuneMode.value() *
								  m_controls->oscAFineDetuneMode.value() );
			m_oscB->setFrequency( m_controls->freqModel.value() * m_controls->oscBCourseDetuneMode.value() *
								  m_controls->oscBFineDetuneMode.value() );
			m_lfo->setFrequency( m_controls->lfoSpeedModel.value() );
			m_gain->setGain( m_controls->velocityModel.value() *
							 ( 1.0 - ( m_lfo->uniTick() * m_controls->lfoGainModel.value() ) )
							* ( m_adsr->tick()  ));
//qDebug( "lfo :%f",m_lfo->uniTick());
			m_oscA->tick( &sigA );
			m_oscB->tick( &sigB );

			buffer[f][0] = m_controls->mixModeModel.value() < 0.5 ?
						sigA[0] + sigB[0] :
						sigA[0] * sigB[0];
			buffer[f][1] = m_controls->mixModeModel.value() < 0.5 ?
						sigA[1] + sigB[1] :
						sigA[1] * sigB[1];
			m_gain->tick( &buffer[f] );
			m_filter->setParameters( m_controls->cutoffModel.logValue() *
									 ( 1.0 - ( m_lfo->uniTick() * m_controls->lfoFilterModel.value() )  ),
									   m_controls->resModel.value()  );
			m_filter->tick( &buffer[f] );
		}
	}
}

void Demo2AudioModule::noteOn()
{
	if( m_controls->oscARetriggerModel.value() > 0.5 )
	{
		m_oscA->restart();
	}
	if( m_controls->oscBRetriggerModel.value() > 0.5 )
	{
		m_oscB->restart();
	}
	if( m_controls->oscARetriggerModel.value() > 0.5 )
	{
		m_oscA->restart();
	}
	m_adsr->noteOn();

}

void Demo2AudioModule::noteOff()
{
	m_adsr->noteRelease();
}

