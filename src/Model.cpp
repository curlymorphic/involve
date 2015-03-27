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

#include "Model.h"
#include "MainWindow.h"
//#include



Model::Model(float init, float min, float max, float interval, QString name, QObject *parent) :
	QObject( parent ),
	m_value( init ),
	m_initial( init ),
	m_min( min ),
	m_max( max ),
	m_interval( interval ),
	m_name( name ),
	m_initValueChanged(false)
{
	emit dataChanged( this );
//	MainWindow *mw = 0;
//	while( !mw)
//	{
//		mw = (qobject_cast<MainWindow*> (QApplication::topLevelWidgets().at( 0 )));
//	}
//	mw->modelManager()->registerModel( this );
	ModelManager::instance()->registerModel( this );
}

Model::~Model()
{

}

void Model::setValue(float val)
{
	if( val < m_min ) { m_value = val; }
	else if( val > m_max ) { m_value = val; }
	else { m_value = val; }

	if( m_value != m_initial ) { m_initValueChanged = true; }

	emit dataChanged( this );

}

void Model::inc(float val)
{
	setValue( value() + val);
}

