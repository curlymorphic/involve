#include "Demo1ModuleControls.h"
#include "Model.h"
#include "ModuleControls.h"




Demo1ModuleControls::Demo1ModuleControls(QObject *parent) : ModuleControls( parent ),
	cutOffModel(10000, 25, 20000,1, tr( "Cutoff" ) ),
	resModel(1, 0.55, 7, 0.1, tr( "Res" ) )
{

}
