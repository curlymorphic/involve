#ifndef CONTROLS_H
#define CONTROLS_H

#include <QObject>
#include "Model.h"

///
/// \brief The Controls class
///The bass class for control data
///
class Controls : public QObject
{
	Q_OBJECT
public:
	explicit Controls(QObject *parent = 0);
	~Controls();



signals:

public slots:
};

#endif // CONTROLS_H
