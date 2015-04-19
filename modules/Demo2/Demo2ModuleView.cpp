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

#include "Demo2ModuleView.h"
#include <QGroupBox>
#include <QVBoxLayout>
#include <QTimer>
#include "SegmentOscillator.h"
#include "ExtendableSegementOscillator.h"


Demo2ModuleView::Demo2ModuleView(ModuleControls *controls, QWidget *parent,
								 Qt::WindowFlags flags):
	ModuleView( parent, controls, flags ),
	m_controls( (Demo2ModuleControls*)controls ),
	m_oscAWaveLength( SegmentOscillator::TABLE_LEN ),
	m_oscBWaveLength( SegmentOscillator::TABLE_LEN ),
	m_lfoWaveLength( ExtendableSegementOscillator::TABLE_LEN )
{

	// instansiate Oscillator A widgets
	m_waveAData = new float[ m_oscAWaveLength ];
	m_oscAWaveShapeFaders = new ModuleFader*[ SegmentOscillator::maxSegmentCount ];
	for(int i = 0; i < SegmentOscillator::maxSegmentCount ; ++i )
	{
		m_oscAWaveShapeFaders[ i ] = new ModuleFader(*( &m_controls->oscAWaveShapeModels[i] ), this );
		connect( m_controls->oscAWaveShapeModels[i], SIGNAL( dataChanged(Model*) ),
															this, SLOT( waveAChanged() ) );
	}

	m_oscASegmentCountFader = new ModuleFader( &m_controls->oscASegmentCountModel, this );
	connect( &m_controls->oscASegmentCountModel, SIGNAL( dataChanged( Model* ) ),
			 this, SLOT( waveAChanged() ) );
	m_oscAWaveDisplay = new WaveDisplay( this );
	m_oscAGainFader = new ModuleFader( &m_controls->oscAGainModel, this );
	m_oscACourseDetuneFader = new ModuleFader( &m_controls->oscACourseDetuneMode, this );
	m_oscAFineDetuneFader = new ModuleFader( &m_controls->oscAFineDetuneMode, this );
	m_oscARetriggerFader = new ModuleFader( &m_controls->oscARetriggerModel, this );

	// instansiate Oscillator B widgets
	m_waveBData = new float[ m_oscBWaveLength ];
	m_oscBWaveShapeFaders = new ModuleFader*[ SegmentOscillator::maxSegmentCount ];
	for(int i = 0; i < SegmentOscillator::maxSegmentCount ; ++i )
	{
		m_oscBWaveShapeFaders[ i ] = new ModuleFader(*( &m_controls->oscBWaveShapeModels[i] ), this );
		connect( m_controls->oscBWaveShapeModels[i], SIGNAL( dataChanged(Model*) ),
															this, SLOT( waveBChanged() ) );
	}


	m_oscBSegmentCountFader = new ModuleFader( &m_controls->oscBSegmentCountModel, this );
	connect( &m_controls->oscBSegmentCountModel, SIGNAL( dataChanged( Model* ) ),
			 this, SLOT( waveBChanged() ) );
	m_oscBWaveDisplay = new WaveDisplay( this );
	m_oscBGainFader = new ModuleFader( &m_controls->oscBGainModel, this );
	m_oscBCourseDetuneFader = new ModuleFader( &m_controls->oscBCourseDetuneMode, this );
	m_oscBFineDetuneFader = new ModuleFader( &m_controls->oscBFineDetuneMode, this );
	m_oscBRetriggerFader = new ModuleFader( &m_controls->oscBRetriggerModel, this );

	// instansiate lfo widgets
	m_waveLfoData = new float[ m_lfoWaveLength * ExtendableSegementOscillator::maxSegmentCount ];
	m_lfoWaveShapeFaders = new ModuleFader*[ ExtendableSegementOscillator::maxSegmentCount * 2 ];
	for(int i = 0; i < ExtendableSegementOscillator::maxSegmentCount * 2 ; ++i )
	{
		m_lfoWaveShapeFaders[ i ] = new ModuleFader(*( &m_controls->lfoWaveShapeModels[i] ), this );
		connect( m_controls->lfoWaveShapeModels[i], SIGNAL( dataChanged(Model*) ),
															this, SLOT( waveLfoChanged() ) );
	}

	m_lfoSegmentCountFader = new ModuleFader( &m_controls->lfoSegmentCountModel, this );
	connect( &m_controls->lfoSegmentCountModel, SIGNAL( dataChanged( Model* ) ),
			 this, SLOT( waveLfoChanged() ) );
	m_lfoWaveDisplay = new WaveDisplay( this );
	m_lfoGainFader = new ModuleFader( &m_controls->lfoGainModel, this );
	m_lfoFilterFader = new ModuleFader( &m_controls->lfoFilterModel, this );
	m_lfoRetriggerFader = new ModuleFader( &m_controls->lfoRetriggerModel, this );
	m_lfoSpeedFader = new ModuleFader( &m_controls->lfoSpeedModel, this );

	m_mixModeFader = new ModuleFader( &m_controls->mixModeModel, this );

	m_attackFader = new ModuleFader( &m_controls->attackModel, this );
	m_decayFader = new ModuleFader( &m_controls->decayModel, this );
	m_sustainFader = new ModuleFader( &m_controls->sustainModel, this );
	m_releaseFader = new ModuleFader( &m_controls->releaseModel, this );

	m_cutoffFader = new ModuleFader( &m_controls->cutoffModel, this );
	m_resFader = new ModuleFader( &m_controls->resModel, this );
	m_filterStagesFader = new ModuleFader( &m_controls->filterStagesModel, this );


	waveAChanged();
	waveBChanged();
	waveLfoChanged();

	QVBoxLayout *vlayout = new QVBoxLayout( this );

	QGroupBox *oscAShapeBox = new QGroupBox( tr( "Oscillator A" ), this );
	QHBoxLayout *shapeALayout = new QHBoxLayout( oscAShapeBox );
	for(int i = 0; i < SegmentOscillator::maxSegmentCount ; ++i )
	{
		shapeALayout->addWidget( m_oscAWaveShapeFaders[i], 1 );
		m_oscAWaveShapeFaders[i]->show();
	}
	shapeALayout->addWidget( m_oscASegmentCountFader, 1);
	shapeALayout->addWidget( m_oscAWaveDisplay, 4 );
	shapeALayout->addWidget( m_oscAGainFader, 1 );
	shapeALayout->addWidget( m_oscARetriggerFader, 1 );
	shapeALayout->addWidget( m_oscACourseDetuneFader, 1 );
	shapeALayout->addWidget( m_oscAFineDetuneFader, 1 );
	vlayout->addWidget( oscAShapeBox );

	QGroupBox *oscBShapeBox = new QGroupBox( tr( "Oscillator B" ), this );
	QHBoxLayout *shapeBLayout = new QHBoxLayout( oscBShapeBox );
	for(int i = 0; i < SegmentOscillator::maxSegmentCount ; ++i )
	{
		shapeBLayout->addWidget( m_oscBWaveShapeFaders[i], 1 );
		m_oscBWaveShapeFaders[i]->show();
	}
	shapeBLayout->addWidget( m_oscBSegmentCountFader, 1);
	shapeBLayout->addWidget( m_oscBWaveDisplay, 4 );
	shapeBLayout->addWidget( m_oscBGainFader, 1 );
	shapeBLayout->addWidget( m_oscBRetriggerFader, 1 );
	shapeBLayout->addWidget( m_oscBCourseDetuneFader, 1 );
	shapeBLayout->addWidget( m_oscBFineDetuneFader, 1 );
	vlayout->addWidget( oscBShapeBox );

	QGroupBox *lfoShapeBox = new QGroupBox( tr( "Lfo" ), this );
	QHBoxLayout *shapeLfoLayout = new QHBoxLayout( lfoShapeBox );
	for(int i = 0; i < ExtendableSegementOscillator::maxSegmentCount * 2; ++i )
	{
		shapeLfoLayout->addWidget( m_lfoWaveShapeFaders[i], 1 );
		m_lfoWaveShapeFaders[i]->show();
	}
	shapeLfoLayout->addWidget( m_lfoSegmentCountFader, 1);
	shapeLfoLayout->addWidget( m_lfoWaveDisplay, 4 );
	shapeLfoLayout->addWidget( m_lfoRetriggerFader, 1 );
	shapeLfoLayout->addWidget( m_lfoSpeedFader, 1 );
	shapeLfoLayout->addWidget( m_lfoGainFader, 1 );
	shapeLfoLayout->addWidget( m_lfoFilterFader, 1 );
	shapeLfoLayout->addWidget( m_lfoSpeedFader, 1 );

	vlayout->addWidget( lfoShapeBox );


	QGroupBox *generalBox = new QGroupBox( tr( "General" ), this );
	QHBoxLayout *generalLayout = new QHBoxLayout ( generalBox );

	generalLayout->addWidget( m_cutoffFader, 1 );
	generalLayout->addWidget( m_resFader, 1 );
	generalLayout->addWidget( m_filterStagesFader, 1 );

	generalLayout->addWidget( new QWidget( this ), 1 );


	generalLayout->addWidget( m_attackFader, 1 );
	generalLayout->addWidget( m_decayFader, 1 );
	generalLayout->addWidget( m_sustainFader, 1 );
	generalLayout->addWidget( m_releaseFader, 1 );
	generalLayout->addWidget( new QWidget( this ), 1 );
	generalLayout->addWidget( m_mixModeFader, 1 );

//	m_cutoffFader->show();
//	m_resFader->show();
	vlayout->addWidget( generalBox );

	layout();

	//initial update of wave displays, allows time for initilization
	QTimer::singleShot( 1000, this, SLOT( waveAChanged() ) );
	QTimer::singleShot( 1000, this, SLOT( waveBChanged() ) );
	QTimer::singleShot( 1000, this, SLOT( waveLfoChanged() ) );

}

Demo2ModuleView::~Demo2ModuleView()
{
	delete[] m_waveAData;
}

void Demo2ModuleView::layout()
{
	const int height8 = height() / 11;
	const int wwidth = width();
	for(int i = 0; i < SegmentOscillator::maxSegmentCount ; ++i )
	{
//		m_waveShapeFaders[i]->resize( wwidth * 0.05 , height8 * 2 );
	}
//	m_cutoffFader->resize( wwidth * 0.05 , height8 * 2 );
	//	m_resFader->resize( wwidth * 0.05 , height8 * 2 );
//	m_oscWaveDisplay->resize( width() * 0.25, m_oscWaveDisplay->height() );
}

void Demo2ModuleView::waveAChanged()
{
	m_oscA.setSampleRate( SegmentOscillator::TABLE_LEN );
	m_oscA.setFrequency( 1 );
	m_oscA.setSegmentCount( m_controls->oscASegmentCountModel.value() );

	for(int i = 0; i < SegmentOscillator::maxSegmentCount; ++i)
	{
		m_oscA.setSegment( i, (WTWaveShape) m_controls->oscAWaveShapeModels[i]->value() );
	}
	m_oscA.restart();
	for( int f = 0; f < m_oscAWaveLength; ++f)
	{
		m_waveAData[f] = m_oscA.monoTick();
	}
//	m_osc.processAudio( m_waveData, m_oscWaveLength );
	m_oscAWaveDisplay->setData( m_waveAData, m_oscAWaveLength );

}

void Demo2ModuleView::waveBChanged()
{
	m_oscB.setSampleRate( SegmentOscillator::TABLE_LEN );
	m_oscB.setFrequency( 1 );
	m_oscB.setSegmentCount( m_controls->oscBSegmentCountModel.value() );

	for(int i = 0; i < SegmentOscillator::maxSegmentCount; ++i)
	{
		m_oscB.setSegment( i, (WTWaveShape) m_controls->oscBWaveShapeModels[i]->value() );
	}
	m_oscB.restart();
	for( int f = 0; f < m_oscBWaveLength; ++f)
	{
		m_waveBData[f] = m_oscB.monoTick();
	}
//	m_osc.processAudio( m_waveData, m_oscWaveLength );
	m_oscBWaveDisplay->setData( m_waveBData, m_oscBWaveLength );
}

void Demo2ModuleView::waveLfoChanged()
{
	m_lfo.setSampleRate( SegmentOscillator::TABLE_LEN );
	m_lfo.setFrequency( 1 );
	m_lfo.setCycles( m_controls->lfoSegmentCountModel.value() );
	m_lfo.setCycleHalf(0, 0, (WTWaveShape) m_controls->lfoWaveShapeModels[0]->value());
	m_lfo.setCycleHalf(0, 1, (WTWaveShape) m_controls->lfoWaveShapeModels[1]->value());
	m_lfo.setCycleHalf(1, 0, (WTWaveShape) m_controls->lfoWaveShapeModels[2]->value());
	m_lfo.setCycleHalf(1, 1, (WTWaveShape) m_controls->lfoWaveShapeModels[3]->value());
	m_lfo.setCycleHalf(2, 0, (WTWaveShape) m_controls->lfoWaveShapeModels[4]->value());
	m_lfo.setCycleHalf(2, 1, (WTWaveShape) m_controls->lfoWaveShapeModels[5]->value());
	m_lfo.setCycleHalf(3, 0, (WTWaveShape) m_controls->lfoWaveShapeModels[6]->value());
	m_lfo.setCycleHalf(3, 1, (WTWaveShape) m_controls->lfoWaveShapeModels[7]->value());

//	for(int i = 0; i < SegmentOscillator::maxSegmentCount; ++i)
//	{
//		m_lfo.setSegment( i, (WTWaveShape) m_controls->lfoWaveShapeModels[i]->value() );
//	}
	m_lfo.restart();
	for( int f = 0; f < ( int )(m_lfoWaveLength * m_controls->lfoSegmentCountModel.value() ); ++f)
	{
		m_waveLfoData[f] = m_lfo.monoTick();
	}
//	m_osc.processAudio( m_waveData, m_oscWaveLength );
	m_lfoWaveDisplay->setData( m_waveLfoData, ( int )( m_lfoWaveLength * ( int )m_controls->lfoSegmentCountModel.value()  ) );
}

