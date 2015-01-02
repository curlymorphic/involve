#ifndef DEMO1MODULECONTROLS_H
#define DEMO1MODULECONTROLS_H

#include <QObject>
#include "ModuleControls.h"
#include "Model.h"

class Demo1ModuleControls : public ModuleControls
{
	Q_OBJECT
public:
	explicit Demo1ModuleControls( QObject *parent = 0 );

	~Demo1ModuleControls()
	{

	}


	Model freqModel;
	Model gainModel;
};

#endif // DEMO1MODULECONTROLS_H
