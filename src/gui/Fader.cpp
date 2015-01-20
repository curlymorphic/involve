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

#include "Fader.h"


Fader::Fader(Model *model, QWidget *parent) : QSlider(parent)
{
	if( model ) { setModel( model ); }
	connect( this, SIGNAL( valueChanged( int ) ), this, SLOT( UiComponentValueChanged( int ) ) );
	setMinimumSize( 800, 100 );
}

Fader::~Fader()
{

}

void Fader::setModel(Model *model)
{
	m_model = model;
	connect( m_model, SIGNAL( dataChanged(int)) , this, SLOT( modelValueChanged( int ) ) );
	setMinimum( m_model->getMin() * multipler() );
	setMaximum( m_model->getMax() * multipler() );
	setValue( m_model->value() * multipler() );
	setTickInterval( 1 );
}

void Fader::modelValueChanged( int val )
{
	if(value() / multipler() != val )
	{
		setValue((float)val * multipler());
	}
}

void Fader::UiComponentValueChanged( int val )
{
	if(m_model->value() * multipler() != val )
	{
		m_model->setValue( (float)val / (float)multipler() );
	}
}

