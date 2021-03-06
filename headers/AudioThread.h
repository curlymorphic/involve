/*
 * Copyright (c) 2014-2015 Dave French <contact/dot/dave/dot/french3/at/googlemail/dot/com>
 *
 * This file is part of Involve - http://github.com/curlymorphic/involve
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */

#ifndef AUDIOTHREAD_H
#define AUDIOTHREAD_H

#include <QObject>
#include "AudioDeviceControls.h"
#include "AudioDevice.h"
#include "ModuleManager.h"
#include <QThread>

///
/// \brief The AudioThread class
/// The Audio Thread. This has an event loop, and hosts all the dsp
class AudioThread : public QThread
{
	Q_OBJECT
public:
	AudioThread(AudioDeviceControls *adc = 0, ModuleManager *moduleMannager = 0, QWidget *parent = 0);
	~AudioThread();


protected:
	virtual void run();

private:
	QAudioFormat m_format;
	void initializeAudio();
	AudioDevice *m_audioDevice;
	AudioDeviceControls *m_audioDeviceControls;
	ModuleManager *m_moduleManager;

};

#endif // AUDIOTHREAD_H
