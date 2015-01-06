#ifndef UICONTROLS_H
#define UICONTROLS_H

#include <QObject>
#include "Controls.h"
#include "Model.h"

class UiControls : public Controls
{
	Q_OBJECT
public:
	UiControls( QObject *parent = 0 );
	~UiControls()
	{

	}

	Model startOctave;
	Model octaves;
};

#endif // UICONTROLS_H
