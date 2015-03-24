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

#include "SuperSawModuleView.h"
#include "Fader.h"
#include <QApplication>
#include "QScreen"
#include "Ribbon.h"
#include <QVBoxLayout>
#include <QGroupBox>



SuperSawModuleView::SuperSawModuleView(SuperSawerModuleControls *controls, QWidget *parent,
									   Qt::WindowFlags flags) :
	ModuleView( parent, controls, flags ),
	m_controls( controls )
{
	m_seperationFader = new ModuleFader( &m_controls->seperationModel, this );
	m_cutOffFader = new ModuleFader( &m_controls->cutOffModel, this );
	m_resFader = new ModuleFader( &m_controls->resModel, this );
	m_attackFader = new ModuleFader( &m_controls->attackModel, this );
	m_decayFader = new ModuleFader( &m_controls->decayModel, this );
	m_sustainFader = new ModuleFader( &m_controls->sustainModel, this );
	m_releaseFader = new ModuleFader( &m_controls->releaseModel, this );
	m_subFader = new ModuleFader( &m_controls->subModel, this );
	
	QVBoxLayout *vlayout = new QVBoxLayout( this );
	
	QGroupBox *oscillatorGroup = new QGroupBox( tr( "Oscillator" ), this );
	QHBoxLayout *oscillatorLayout = new QHBoxLayout( oscillatorGroup );
	oscillatorLayout->addWidget( m_seperationFader );
	oscillatorLayout->addWidget( m_subFader );
	vlayout->addWidget( oscillatorGroup );
	
	QGroupBox *adsrGroup = new QGroupBox( tr( "ADSR" ), this );
	QHBoxLayout *adsrLayout = new QHBoxLayout( adsrGroup );
	adsrLayout->addWidget( m_attackFader );
	adsrLayout->addWidget( m_decayFader );
	adsrLayout->addWidget( m_sustainFader );
	adsrLayout->addWidget( m_releaseFader );
	vlayout->addWidget( adsrGroup );
	
	QGroupBox *filterGroup = new QGroupBox( tr( "FILTER" ), this );
	QHBoxLayout  *filterLayout = new QHBoxLayout ( filterGroup );
	filterLayout->addWidget( m_cutOffFader );
	filterLayout->addWidget( m_resFader );
	vlayout->addWidget( filterGroup );
	
	m_seperationFader->show();
	m_subFader->show();
	m_cutOffFader->show();
	m_resFader->show();
	m_attackFader->show();
	m_decayFader->show();
	m_sustainFader->show();
	m_releaseFader->show();
	
	layout();
}

SuperSawModuleView::~SuperSawModuleView()
{
	
}

void SuperSawModuleView::layout()
{
	const int height8 = height() / 9;
	const int wwidth = width();
	const int wDivide = wwidth / 12;
	
	m_seperationFader->resize( wwidth * 0.1 , height8 * 2 );
	m_subFader->resize( wwidth * 0.1 , height8 * 2 );
	m_attackFader->resize( wwidth * 0.1 , height8 * 2 );
	m_decayFader->resize( wwidth * 0.1 , height8 * 2 );
	m_sustainFader->resize( wwidth * 0.1 , height8 * 2 );
	m_releaseFader->resize( wwidth * 0.1 , height8 * 2 );
	
	m_cutOffFader->resize( wwidth * 0.1 , height8 * 2 );
	m_resFader->resize(  wwidth * 0.1 , height8 * 2 );
}

