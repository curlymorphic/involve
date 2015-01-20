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

#ifndef TOUCHCONTROLLER_H
#define TOUCHCONTROLLER_H

#include <QWidget>
#include "Model.h"

class TouchController : public QWidget
{
	Q_OBJECT
public:

	TouchController(Model *xModel = 0, Model *yModel = 0, QWidget *parent = 0);
	~TouchController();
	void recalculatePixelMultipliers();

	void setMinX( float x );
	float getMinX();
	void setMaxX( float x);
	float getMaxX();

	void setMinY( float y );
	float getMinY();
	void setMaxY( float y );
	float getMaxY();

	qint64 getXPixel( float val );
	qint64 getYPixel( float val );

signals:

	void noteOn();
	void noteOff();

protected:

	virtual void resizeEvent(QResizeEvent *event );
	virtual bool event( QEvent *event);
	Model *m_xModel;
	Model *m_yModel;
	float m_minX;
	float m_maxX;
	float m_minY;
	float m_maxY;

	float m_pixelPerX;
	float m_pixelPerY;


private:



};

#endif // TOUCHCONTROLLER_H
