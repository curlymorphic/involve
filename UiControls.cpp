#include "UiControls.h"



UiControls::UiControls(QObject *parent) : Controls( parent ),
	startOctave( 4.0, 1.0, 8.0, 1, tr( "Start Octave" ) ),
	octaves(1.0, 1.0, 8.0, 1.0, tr( "Octave Range" ) )

{

}



