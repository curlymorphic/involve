#ifndef MODULECONTROLS
#define MODULECONTROLS

#include "Controls.h"

class ModuleControls : public Controls
{
public:
	explicit ModuleControls( QObject *parent = 0) :
		Controls( parent ),
		noteOn( false ),
		noteOff( false )
	{

	}

	~ModuleControls()
	{

	}

	bool noteOn;
	bool noteOff;
};

#endif // MODULECONTROLS

