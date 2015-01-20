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

#ifndef FADER_H
#define FADER_H

#include <QWidget>
#include <QSlider>
#include "Model.h"


///
/// \brief The Fader class
/// Model compatable ui component
///
class Fader : public QSlider
{
	Q_OBJECT
public:
	explicit Fader( Model *model = 0, QWidget *parent = 0 );
	~Fader();
	void setModel(Model *model);
	inline int multipler()
	{
		return 1000;
	}

signals:

public slots:
	void modelValueChanged( int val);
	void UiComponentValueChanged( int );

private:
	Model *m_model;
};


#endif // FADER_H
