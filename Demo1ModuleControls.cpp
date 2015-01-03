#include "Demo1ModuleControls.h"
#include "Model.h"
#include "ModuleControls.h"




Demo1ModuleControls::Demo1ModuleControls(QObject *parent) : ModuleControls( parent ),
	freqModel(200.0,40.0,10000.0,0.1, tr ( "Frequency" ) , this ),
	gainModel(0.5,0.0,1.0, 0.1, tr( "Gain" ), this ),
	cutOffModel(10000,25,20000,1, tr( "Cutoff" ) ),
	resModel(1,0.55,7,0.1, tr( "Res" ) )
{

}
