#ifndef MODULECONTROLS
#define MODULECONTROLS

#include "Controls.h"

class ModuleControls : public Controls
{
public:
	explicit ModuleControls( QObject *parent = 0) :
		Controls( parent ),
		noteOn( false ),
		noteOff( false ),
		freqModel(100.0, 65.4, 130.8, 0.1, tr ( "Frequency" ) , this ),
		gainModel(0.5, 0.0, 1.0, 0.1, tr( "Gain" ), this )
	{

	}

	~ModuleControls()
	{

	}

	bool noteOn;
	bool noteOff;
	Model freqModel;
	Model gainModel;
};

#endif // MODULECONTROLS

