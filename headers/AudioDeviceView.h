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

#ifndef AUDIODEVICEVIEW_H
#define AUDIODEVICEVIEW_H

#include <QWidget>
#include "AudioDeviceControls.h"
#include <QLabel>
#include "VuFader.h"

///
/// \brief The AudioDeviceView class
/// Audio Device GUI
///
class AudioDeviceView : public QWidget
{
	Q_OBJECT
public:
	explicit AudioDeviceView(QWidget *parent = 0, AudioDeviceControls *controls = 0 );
	~AudioDeviceView();

protected:
	virtual void resizeEvent( QResizeEvent *ev);

signals:

public slots:
	void updateText();

private:
	AudioDeviceControls *m_audioDeviceControls;
	VuFader *m_gainFader;

};

#endif // AUDIODEVICEVIEW_H
