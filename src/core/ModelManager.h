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

#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <QList>
#include "AutomationSensor.h"

#include "Model.h"

/**
 * @brief The ModelManager class
 *
 * Kepps tracks of the models
 */
class ModelManager : QObject
{
	Q_OBJECT
public:
	ModelManager( QObject *parent = 0 );
	~ModelManager();

	void registerModel( Model *model );
	void assignX();
	void assignY();

	static ModelManager *instance()
	{
		return m_instance;
	}

private slots:
	void ModelChanging( Model* );


private:


	Model *m_lastChangedModel;
	Model *m_lastNonAssignedChangedModel;
	AutomationSensor *m_automationSensor;

	static ModelManager *m_instance;

};

#endif // MODELMANAGER_H
