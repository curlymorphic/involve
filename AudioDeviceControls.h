#ifndef AUDIODEVICECONTROLS_H
#define AUDIODEVICECONTROLS_H

#include "Controls.h"
#include "Model.h"
#include "AudioMath.h"


class AudioDeviceControls : public Controls
{
public:
	AudioDeviceControls();
	~AudioDeviceControls();

	qint64 m_sampleRate;
	qint64 m_bufferSize;
	Model m_gainModel;
	sampleFrame peaks;
};

#endif // AUDIODEVICECONTROLS_H
