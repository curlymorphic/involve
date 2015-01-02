#ifndef DEMO1AUDIOMODULE_H
#define DEMO1AUDIOMODULE_H

#include <QObject>
#include "AudioModule.h"

class Demo1AudioModule : public AudioModule
{
public:
	Demo1AudioModule(qint64 samplerate, ModuleControls *controls);
	~Demo1AudioModule();
	virtual void processAudio(sampleFrame *buffer, qint64 len );

private:
	Oscillator *m_osc;
	Controls *m_controls;
};

#endif // DEMO1AUDIOMODULE_H
