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

#include "ModelManager.h"

ModelManager::ModelManager( QObject *parent ) :
	QObject( parent ),
	m_lastChangedModel( 0 ),
	m_lastNonAssignedChangedModel( 0 )

{
	m_automationSensor = new AutomationSensor( this );
}

ModelManager::~ModelManager()
{

}

void ModelManager::registerModel(Model *model)
{
	connect( model, SIGNAL( dataChanged( Model* ) ), this, SLOT( ModelChanging( Model* ) ) );
}

void ModelManager::ModelChanging(Model *model)
{
	m_lastChangedModel = model;
	if( !( model == m_automationSensor->m_xModel || model == m_automationSensor->m_yModel ) )
	{
		m_lastNonAssignedChangedModel = model;
	}
}



void ModelManager::assignX()
{

		m_automationSensor->m_xModel = m_lastNonAssignedChangedModel;

}

void ModelManager::assignY()
{

		m_automationSensor->m_yModel = m_lastNonAssignedChangedModel;

}

