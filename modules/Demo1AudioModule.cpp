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

#include "Demo1AudioModule.h"

Demo1AudioModule::Demo1AudioModule(qint64 sampleRate, Demo1ModuleControls *controls) :
	AudioModule( sampleRate, controls ),
	m_controls( controls )
{
	m_osc = new WTOscillator( sampleRate );
	m_osc->setFrequency( 80 );
	m_gain = new Gain( sampleRate );
	m_volLfo = new WTOscillator( sampleRate );
	m_volLfo->setFrequency( 1 );
	m_lp = new Lp12( sampleRate );
	m_lp2 = new Lp12( sampleRate ),
	m_ad = new Adsr( sampleRate );
	m_delay = new StereoDelay(2.0, sampleRate );
	delayedFrame = new sampleFrame[1];
}

Demo1AudioModule::~Demo1AudioModule()
{
	delete m_osc;
}

void Demo1AudioModule::processAudio(sampleFrame *buffer, qint64 len)
{
	if(m_controls)
	{
		for(int i = 0; i < len; i++)
		{
			m_volLfo->setShape( (WTWaveShape )m_controls->lfoShapeModel.value() );
			m_volLfo->setFrequency( m_controls->lfoSpeedModel.value() );

			m_ad->setAttackTime( m_controls->attackModel.value() );
			m_ad->setDecayTime( m_controls->decayModel.value() );
			m_ad->setSustainLevel( m_controls->sustainModel.value() );
			m_ad->setReleaseTime( m_controls->releaseModel.value() );
			m_osc->setFrequency( m_controls->freqModel.value() );
			m_osc->setShape( (WTWaveShape)(int)m_controls->waveShapeModel.value() );
			m_gain->setGain( m_controls->velocityModel.value() *
							  ( 1.0 - ( m_volLfo->uniTick() * m_controls->lfoGainModel.value() ) )
							 * ( m_ad->tick()  ));
			m_lp->setParameters(m_controls->cutOffModel.value() *
								( 1.0 - ( m_volLfo->uniTick() * m_controls->lfoFilterModel.value() )  ),
								  m_controls->resModel.value()  );
			m_lp2->setParameters( m_controls->cutOffModel.value(), m_controls->resModel.value() );
			m_delay->setLength( m_controls->delayTimeModel.value() );
			m_delay->setFeedback( m_controls->delayRegenModel.value() );



			m_osc->tick( &buffer[i] );
			m_lp->tick( &buffer[i] );
			m_lp2->tick( &buffer[i] );


			m_gain->tick( &buffer[i] );



			delayedFrame[0][0] = buffer[i][0];
			delayedFrame[0][1] = buffer[i][1];

			m_delay->tick( delayedFrame[0] );

			buffer[i][0] = ((1.0 - m_controls->delayAmmountModel.value()) * buffer[i][0] ) +
					(m_controls->delayAmmountModel.value() * delayedFrame[0][0] );
			buffer[i][1] = ((1.0 - m_controls->delayAmmountModel.value()) * buffer[i][1] ) +
					(m_controls->delayAmmountModel.value() * delayedFrame[0][1] );
		}
	}
}

void Demo1AudioModule::noteOn()
{
	m_ad->noteOn();
}

void Demo1AudioModule::noteOff()
{
	m_ad->noteRelease();
}

