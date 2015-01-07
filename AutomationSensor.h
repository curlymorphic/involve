#ifndef AUTOMATIONSENSOR_H
#define AUTOMATIONSENSOR_H

#include <QObject>
#include <QtSensors/QRotationSensor>
#include "QtSensors/QRotationReading"
#include "Model.h"


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

	QRotationSensor *m_sensor;
	QRotationReading *m_reading;
};

#endif // AUTOMATIONSENSOR_H
