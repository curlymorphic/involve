#include "AudioDeviceControls.h"

AudioDeviceControls::AudioDeviceControls() :
	m_gainModel( 0.5 , 0.0, 1.0 , 0.01, tr( "Gain " ) )
{
	peaks[0] = 0.0;
	peaks[0] = 0.0;
}

AudioDeviceControls::~AudioDeviceControls()
{

}

