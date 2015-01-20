#ifndef MODULECONTROLS
#define MODULECONTROLS

#include "Controls.h"

///
/// \brief The ModuleControls class
/// Base class for module controls
class ModuleControls : public Controls
{
public:
	explicit ModuleControls( QObject *parent = 0) :
		Controls( parent ),
		noteOnModel( 0, 0, 1 , 1 , tr( "Note Playing" ) ),
		freqModel(100.0, 65.4, 130.8, 0.1, tr ( "Frequency" ) , this ),
		velocityModel(0.5, 0.0, 1.0, 0.1, tr( "Gain" ), this )
	{

	}

	~ModuleControls()
	{

	}

	Model noteOnModel;
	Model freqModel;
	Model velocityModel;
};

#endif // MODULECONTROLS

