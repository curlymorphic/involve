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

#ifndef RIBBON_H
#define RIBBON_H

#include <QWidget>
#include "Model.h"
#include "TouchController.h"

///
/// \brief The Ribbon class
/// The ribbon controller, used for note input
class Ribbon : public TouchController
{
	Q_OBJECT
public:
	explicit Ribbon( Model *xModel = 0, Model *yModel = 0, QWidget *parent = 0 );
	~Ribbon();

	void setModels (Model *xModel = 0, Model *yModel = 0 );


protected:
	virtual void paintEvent( QPaintEvent *event );
	virtual void resizeEvent( QResizeEvent *event);

private:

	void initilizeNotes();


	qint64 m_dotSize;
	float *m_notes;
};

#endif // RIBBON_H
