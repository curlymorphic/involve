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

#include "WaveDisplay.h"
#include <QPainter>

WaveDisplay::WaveDisplay(QWidget *parent) : QWidget(parent),
	m_data( 0 ),
	m_dataLength( 0 ),
	m_lineColor( 255, 255, 255, 255 ),
	m_lineWidth( 0 )
{

}

WaveDisplay::~WaveDisplay()
{

}

void WaveDisplay::setData(float *data, int len)
{
	m_data = data;
	m_dataLength = len;
	update();
}

void WaveDisplay::setColor(QColor color)
{
	m_lineColor = color;
}

void WaveDisplay::paintEvent(QPaintEvent *event)
{
	Q_UNUSED( event );
	if( m_dataLength <= 0 )
	{
		return;
	}
	if( m_data )
	{
		float pixelPerX = width() / m_dataLength;
		float pixelPerY = height() * 0.45;
		float mid = height() / 2;
		float lastX = 0;
		float lastY = mid;
		QPainter painter( this );
		painter.setPen( QPen ( m_lineColor, m_lineWidth,
						Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ) );
		for( int i = 0; i < m_dataLength-1; ++i )
		{
			float x = pixelPerX * i;
			float y = ( m_data[i] * pixelPerY * -1 ) + mid;
//			painter.drawPoint( pixelPerX * i, ( m_data[i] * pixelPerY ) + mid );
			painter.drawLine( lastX, lastY, x, y );
			lastX = x;
			lastY = y;
		}
	}
}

