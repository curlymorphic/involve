#ifndef MINISEGAUDIOMODULE_H
#define MINISEGAUDIOMODULE_H

#include "Demo2/Demo2AudioModule.h"


class MiniSegAudioModule :  public  Demo2AudioModule
{
public:
	MiniSegAudioModule(qint64 samplerate, ModuleControls *controls);
	~MiniSegAudioModule();
};

#endif // MINISEGAUDIOMODULE_H
