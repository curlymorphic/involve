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

#ifndef SIMPLESEQUENCER_H
#define SIMPLESEQUENCER_H

#include <QObject>
#include "Model.h"


class SimpleSequencer : public QObject
{
	Q_OBJECT
public:
	explicit SimpleSequencer(Model *x, Model *y, QObject *parent = 0);
	virtual ~SimpleSequencer(){};
	void setModels(Model *xModel, Model *yModel);

public slots:
	void tick();

signals:

	void noteOn();
	void noteOff();

private:
	Model *m_freqModel;
	Model *m_volumeModel;
	int m_step;
	int m_noteSquence[]  { 60,62,64,66,68,72,56,55,44,77,65,67,34,56,75,44};

};

#endif // SIMPLESEQUENCER_H
