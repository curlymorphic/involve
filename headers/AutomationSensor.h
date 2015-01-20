#ifndef AUTOMATIONSENSOR_H
#define AUTOMATIONSENSOR_H

#include <QObject>
#include <QtSensors/QAccelerometer>
#include "QtSensors/QAccelerometerReading"
#include "Model.h"

///
/// \brief The AutomationSensor class
/// Uses acceloremter data to automate provided models
class AutomationSensor : public QObject
{
	Q_OBJECT
public:
	explicit AutomationSensor(QObject *parent = 0);
	~AutomationSensor();

	Model *m_xModel;
	Model *m_yModel;
	Model *m_zModel;

signals:

public slots:
	void update();


private:

	QAccelerometer *m_sensor;
	QAccelerometerReading *m_reading;
};

#endif // AUTOMATIONSENSOR_H
