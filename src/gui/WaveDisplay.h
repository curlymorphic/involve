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

#ifndef WAVEDISPLAY_H
#define WAVEDISPLAY_H

#include <QWidget>

///
/// \brief The WaveDisplay class
/// A widget that displays wave forms, the data is an array of floats
/// in the range -1.0 1.0
/// the display is scaled to fill widget in lenght
class WaveDisplay : public QWidget
{
	Q_OBJECT
public:
	explicit WaveDisplay(QWidget *parent = 0);
	~WaveDisplay();

	void setData( float *data, int len );
	void setColor( QColor color );

signals:

public slots:

protected:

	virtual void paintEvent( QPaintEvent *event );

private:

	float* m_data;
	float m_dataLength;

	QColor m_lineColor;
	float m_lineWidth;
};

#endif // WAVEDISPLAY_H
