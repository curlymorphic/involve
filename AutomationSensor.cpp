#include "AutomationSensor.h"
#include <QtSensors/QRotationSensor>
#include "QtSensors/QRotationReading"

AutomationSensor::AutomationSensor(QObject *parent) : QObject(parent),
	m_xModel( 0 ),
	m_yModel( 0 ),
	m_zModel( 0 )
{
	m_sensor = new QRotationSensor;
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
		m_xModel->setValue(qBound(m_xModel->getMin(),(float)qAbs (m_reading->x()*0.02*m_xModel->getMax() )
						   + m_xModel->getMin(), m_xModel->getMax() ));
	}
	if(m_yModel)
	{
		m_yModel->setValue(qBound(m_yModel->getMin(),(float)qAbs (m_reading->y()*0.02*m_yModel->getMax() )
						   + m_yModel->getMin(), m_yModel->getMax() ));
	}
	if(m_zModel)
	{
		m_zModel->setValue(qBound(m_zModel->getMin(),(float)qAbs (m_reading->z()*0.02*m_zModel->getMax() )
						   + m_zModel->getMin(), m_zModel->getMax() ));
	}
}

