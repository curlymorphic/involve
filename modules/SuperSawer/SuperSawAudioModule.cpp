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


#include "SuperSawAudioModule.h"


SuperSawAudioModule::SuperSawAudioModule(qint64 samplerate, SuperSawerModuleControls *controls) :
	AudioModule( samplerate, controls ),
	m_controls( controls )
{
	m_oscillators = new WTOscillator[5];
	for( int i = 0; i < 5; ++i )
	{
//		m_oscillators[i] = new WTOscillator( samplerate );
		m_oscillators[i].setShape( WT_SAW );
	}
	m_oscFrames = new sampleFrame[5];
	for( int i = 0; i < 5; ++i )
	{
//		m_oscFrames[i] = new sampleFrame;
	}
//	m_subFrame = new sampleFrame();

	m_gain = new Gain( samplerate );
	m_lp = new Lp12( samplerate );
	m_lp2 = new Lp12( samplerate );
	m_ad = new Adsr( samplerate );
	m_subOscillator = new WTOscillator( samplerate );
	m_subOscillator->setShape( WT_SINE );

}

SuperSawAudioModule::~SuperSawAudioModule()
{
	delete[] m_oscillators;
	delete[] m_oscFrames;
	delete m_subFrame;
	delete m_gain;
	delete m_lp2;
	delete m_lp;
	delete m_ad;
	delete m_subOscillator;
}

void SuperSawAudioModule::processAudio(sampleFrame *buffer, int len)
{
	if(m_controls )
	{
		for( int f = 0; f < len; ++f )
		{
			float pitchOffset = m_controls->freqModel.value() * m_controls->seperationModel.value();
			m_subOscillator->setFrequency( m_controls->freqModel.value() * 0.5 );
			m_oscillators[0].setFrequency( m_controls->freqModel.value() );
			m_oscillators[1].setFrequency( m_controls->freqModel.value() + pitchOffset );
			m_oscillators[2].setFrequency( m_controls->freqModel.value() + pitchOffset + pitchOffset );
			m_oscillators[3].setFrequency( m_controls->freqModel.value() - pitchOffset );
			m_oscillators[4].setFrequency( m_controls->freqModel.value() - pitchOffset - pitchOffset );

			m_ad->setAttackTime( m_controls->attackModel.value() );
			m_ad->setDecayTime( m_controls->decayModel.value() );
			m_ad->setSustainLevel( m_controls->sustainModel.value() );
			m_ad->setReleaseTime( m_controls->releaseModel.value() );

			m_gain->setGain( m_controls->velocityModel.value() * m_ad->tick() );
			m_lp->setParameters(m_controls->cutOffModel.logValue() , m_controls->resModel.value() );
			m_lp2->setParameters(m_controls->cutOffModel.logValue() , m_controls->resModel.value() );

			m_subOscillator->tick( &m_subFrame );
			for( int i = 0 ; i < 5; ++i )
			{
				m_oscillators[i].tick( &m_oscFrames [ i ] );
			}

			//mix TODO improve

			buffer[f][0] = m_subFrame[0];
			buffer[f][1] = m_subFrame[1];

			for( int i = 0; i < 5; ++i )
			{
				buffer[f][0] += m_oscFrames[i][0] * 0.2;
				buffer[f][1] += m_oscFrames[i][1] * 0.2;
			}

			m_lp->tick( &buffer[f] );
//			m_lp2->tick( &buffer[f] );

			m_gain->tick( &buffer[f] );



		}
	}
}

void SuperSawAudioModule::noteOn()
{
	m_ad->noteOn();
	for( int i = 0; i < 5; ++i )
	{
		m_oscillators[i].noteOn();
	}

}

void SuperSawAudioModule::noteOff()
{
	m_ad->noteRelease();
}

