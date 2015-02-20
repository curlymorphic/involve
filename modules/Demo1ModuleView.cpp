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

#include "Demo1ModuleView.h"
#include "Fader.h"
#include <QApplication>
#include "QScreen"
#include "Ribbon.h"
#include <QVBoxLayout>
#include <QGroupBox>



Demo1ModuleView::Demo1ModuleView(Demo1ModuleControls *controls, QWidget *parent,
								 Qt::WindowFlags flags) :
	ModuleView( parent, controls, flags ),
	m_controls( controls )
{

	m_waveShapeFader = new ModuleFader( &m_controls->waveShapeModel, this );
	m_attackFader = new ModuleFader( &m_controls->attackModel, this );
	m_decayFader = new ModuleFader( &m_controls->decayModel, this );
	m_sustainFader = new ModuleFader( &m_controls->sustainModel, this );
	m_releaseFader = new ModuleFader( &m_controls->releaseModel, this );
	m_lfoSpeedFader = new ModuleFader( &m_controls->lfoSpeedModel, this );
	m_lfoShapeFader = new ModuleFader( &m_controls->lfoShapeModel, this );
	m_lfoGainFader = new ModuleFader( &m_controls->lfoGainModel, this );
	m_lfoFilterFader = new ModuleFader ( &m_controls->lfoFilterModel, this );
	m_delayAmmountFader = new ModuleFader ( &m_controls->delayAmmountModel, this );
	m_delayTimeFader = new ModuleFader( &m_controls->delayTimeModel, this  );
	m_delayRegenFader = new ModuleFader( &m_controls->delayRegenModel, this );

	m_cutOffFader = new ModuleFader( &m_controls->cutOffModel, this );
	m_resFader = new ModuleFader( &m_controls->resModel, this );

	QVBoxLayout *vlayout = new QVBoxLayout( this );

	QGroupBox *lfoGroup = new QGroupBox( tr ( "LFO" ), this );
	QHBoxLayout *lfoLayout = new QHBoxLayout( lfoGroup );
	lfoLayout->addWidget( m_lfoSpeedFader );
	lfoLayout->addWidget( m_lfoShapeFader );
	lfoLayout->addWidget( m_lfoGainFader );
	lfoLayout->addWidget( m_lfoFilterFader );
	vlayout->addWidget ( lfoGroup );

	QGroupBox *adsrGroup = new QGroupBox( tr( "ADSR" ), this );
	QHBoxLayout *adsrLayout = new QHBoxLayout( adsrGroup );
	adsrLayout->addWidget( m_attackFader );
	adsrLayout->addWidget( m_decayFader );
	adsrLayout->addWidget( m_sustainFader );
	adsrLayout->addWidget( m_releaseFader );
	adsrLayout->addWidget( m_waveShapeFader );
	vlayout->addWidget( adsrGroup );

	QHBoxLayout *bottomRow = new QHBoxLayout( this );

	QGroupBox *filterGroup = new QGroupBox( tr( "FILTER" ), this );
	QHBoxLayout  *filterLayout = new QHBoxLayout ( filterGroup );
	filterLayout->addWidget( m_cutOffFader );
	filterLayout->addWidget( m_resFader );
	bottomRow->addWidget( filterGroup );

	QGroupBox *delayGroup = new QGroupBox( tr( "DELAY" ), this );
	QHBoxLayout *delayLayout = new QHBoxLayout( delayGroup);
	delayLayout->addWidget( m_delayAmmountFader );
	delayLayout->addWidget( m_delayTimeFader );
	delayLayout->addWidget( m_delayRegenFader );
	bottomRow->addWidget( delayGroup);

	vlayout->addLayout( bottomRow );

	m_waveShapeFader->show();
	m_attackFader->show();
	m_decayFader->show();
	m_sustainFader->show();
	m_releaseFader->show();
	m_lfoSpeedFader->show();
	m_lfoShapeFader->show();
	m_lfoGainFader->show();
	m_lfoFilterFader->show();
	m_delayAmmountFader->show();
	m_delayTimeFader->show();
	m_delayRegenFader->show();

	layout();
}

Demo1ModuleView::~Demo1ModuleView()
{

}

void Demo1ModuleView::layout()
{
	const int height8 = height() / 9;
	const int wwidth = width();
	const int wDivide = wwidth / 12;




	m_waveShapeFader->resize( wwidth * 0.1 , height8 * 2 );
	m_attackFader->resize( wwidth * 0.1 , height8 * 2 );
	m_decayFader->resize( wwidth * 0.1 , height8 * 2 );
	m_sustainFader->resize( wwidth * 0.1 , height8 * 2 );
	m_releaseFader->resize( wwidth * 0.1 , height8 * 2 );
	m_lfoSpeedFader->resize( wwidth * 0.1 , height8 * 2 );
	m_lfoShapeFader->resize( wwidth * 0.1 , height8 * 2 );
	m_lfoGainFader->resize( wwidth * 0.1 , height8 * 2 );
	m_lfoFilterFader->resize( wwidth * 0.1 , height8 * 2 );
	m_delayAmmountFader->resize( wwidth * 0.1 , height8 * 2 );
	m_delayTimeFader->resize( wwidth * 0.1 , height8 * 2 );
	m_delayRegenFader->resize( wwidth * 0.1 , height8 * 2 );

	m_cutOffFader->resize( wwidth * 0.1 , height8 * 2 );
	m_resFader->resize(  wwidth * 0.1 , height8 * 2 );
}






