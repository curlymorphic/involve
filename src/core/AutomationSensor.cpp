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

#include "AutomationSensor.h"
#include <QtSensors/QRotationSensor>
#include "QtSensors/QRotationReading"

AutomationSensor::AutomationSensor(QObject *parent) : QObject(parent),
	m_xModel( 0 ),
	m_yModel( 0 ),
	m_zModel( 0 )
{
	m_sensor = new QAccelerometer;
	connect( m_sensor, SIGNAL( readingChanged() ), this, SLOT( update() ) );
	m_sensor->setDataRate( 20 );
	m_sensor->start();
}

AutomationSensor::~AutomationSensor()
{
	delete m_sensor;
}

void AutomationSensor::update()
{
	m_reading = m_sensor->reading();
	if(m_xModel)
	{
		m_xModel->setValue(qBound(m_xModel->getMin(),(float)qAbs (m_reading->x()*0.2*m_xModel->getMax() )
						   + m_xModel->getMin(), m_xModel->getMax() ));
	}
	if(m_yModel)
	{
		m_yModel->setValue(qBound(m_yModel->getMin(),(float)qAbs ( m_reading->y()*0.2)*m_yModel->getMax()
						   + m_yModel->getMin()  , m_yModel->getMax() ) - 1.1 );
	}
	if(m_zModel)
	{
		m_zModel->setValue(qBound(m_zModel->getMin(),(float)qAbs (m_reading->z()*0.2*m_zModel->getMax() )
						   + m_zModel->getMin(), m_zModel->getMax() ));
	}
}

