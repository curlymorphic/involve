#include "Demo1ModuleControls.h"
#include "Model.h"
#include "ModuleControls.h"




Demo1ModuleControls::Demo1ModuleControls(QObject *parent) : ModuleControls( parent ),
	cutOffModel(1000, 50, 10000,1, tr( "Cutoff" ) ),
	resModel(1, 1, 4, 0.1, tr( "Res" ) ),
	waveShapeModel( 2, 0 , 4 , 1, tr( "WaveShape" ) ),
	attackModel(0.1, 0.01 , 5 , 0.01, tr( "attack" ) ),
	decayModel(0.1, 0.01 , 5 , 0.01, tr( "decay" ) ),
	sustainModel(0.5, 0, 1 , 0.01, tr( "sustain" ) ),
	releaseModel(0.1, 0.01 , 5 , 0.01, tr( "release" ) ),
	lfoSpeedModel(0.01, 0.01, 10, 0.01, tr( "lfo speed" ) ),
	lfoShapeModel( 2, 0 , 4 , 1, tr( "LfoShape" ) ),
	lfoGainModel(0.0, 0.0, 1.0, 0.01, tr( "Lfo > Vol " ) ),
	lfoFilterModel(1.0, 0.0, 1.0, 0.01, tr( "Lfo > cutoff " ) ),
	delayAmmountModel(0.00, 0.0, 1, 0.01, tr( "Delay Ammount" ) ),
	delayTimeModel(0.05, 0.01, 1, 0.01, tr( " Delay time " ) ),
	delayRegenModel(0.0, 0.0, 0.99, 0.01, tr( "regen" ) )
{

}
