#include "Demo1ModuleControls.h"
#include "Model.h"
#include "ModuleControls.h"




Demo1ModuleControls::Demo1ModuleControls(QObject *parent) : ModuleControls( parent ),
	cutOffModel(1000, 35, 3000,1, tr( "Cutoff" ) ),
	resModel(1, 0.55, 7, 0.1, tr( "Res" ) ),
	waveShapeModel( 2, 0 , 4 , 1, tr( "WaveShape" ) )
{

}
