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



Demo2ModuleView::Demo2ModuleView(ModuleControls *controls, QWidget *parent,
								 Qt::WindowFlags flags):
	ModuleView( parent, controls, flags ),
	m_controls( (Demo2ModuleControls*)controls )
{
	m_waveShapeAFader = new ModuleFader( &m_controls->waveShapeAModel, this );
	m_waveShapeBFader = new ModuleFader( &m_controls->waveShapeBModel, this );

	QHBoxLayout *shapeLayout = new QHBoxLayout( this );
	shapeLayout->addWidget( m_waveShapeAFader );
	shapeLayout->addWidget( m_waveShapeBFader );

	m_waveShapeAFader->show();
	m_waveShapeBFader->show();

	layout();

}

Demo2ModuleView::~Demo2ModuleView()
{

}

void Demo2ModuleView::layout()
{
	const int height8 = height() / 9;
	const int wwidth = width();

	m_waveShapeAFader->resize( wwidth * 0.1 , height8 * 2 );
	m_waveShapeBFader->resize( wwidth * 0.1 , height8 * 2 );
}

