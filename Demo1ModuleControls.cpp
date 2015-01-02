#include "Demo1ModuleControls.h"
#include "Model.h"
#include "ModuleControls.h"




Demo1ModuleControls::Demo1ModuleControls(QObject *parent) : ModuleControls( parent ),
	freqModel(200.0,40.0,400.0,0.1, tr ( "Frequency" ) , this ),
	gainModel(1.0,0.0,2.0, 0.1, tr( "Gain" ), this )
{

}
