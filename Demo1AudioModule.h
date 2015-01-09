#ifndef DEMO1AUDIOMODULE_H
#define DEMO1AUDIOMODULE_H

#include <QObject>
#include "AudioModule.h"
#include "Demo1ModuleControls.h"
#include "Gain.h"
#include "Lfo.h"
#include "Filters.h"
#include "AD.h"
#include "ADSR.h"
#include "WTOscillator.h"
#include "StereoDelay.h"


class Demo1AudioModule : public AudioModule
{
public:
	Demo1AudioModule(qint64 samplerate, Demo1ModuleControls *controls);
	~Demo1AudioModule();
	virtual void processAudio(sampleFrame *buffer, qint64 len );


private:
	WTOscillator *m_osc;
	Gain *m_gain;
	WTOscillator *m_volLfo;
	Lp12 *m_lp;
	Lp12 *m_lp2;
	Adsr *m_ad;
	StereoDelay *m_delay;
	Demo1ModuleControls *m_controls;


};

#endif // DEMO1AUDIOMODULE_H
