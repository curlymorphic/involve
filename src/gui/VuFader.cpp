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

#include "VuFader.h"
#include <QPainter>
#include <QTouchEvent>


VuFader::VuFader(Model *xModel, QWidget *parent, sampleFrame *peaks) :
	TouchController( xModel , 0, parent ),
	m_dotSize( 10 ),
	m_peaks( peaks )
{

}

VuFader::~VuFader()
{

}

void VuFader::paintEvent(QPaintEvent *event)
{
	Q_UNUSED( event );
	QPainter painter( this );
	painter.setPen( QPen ( QColor ( 0, 0, 0, 255), 1 ,
						   Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.drawLine( 0 , height() * 0.5 , width(), height() * 0.5 );
	painter.setPen( QPen ( QColor ( 0, 255, 0, 255), 10 ,
						   Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.drawLine( 0, height() * 0.25, m_peaks[0][0]*m_pixelPerX , height() * 0.25 );
	painter.drawLine( 0, height() * 0.75, m_peaks[0][1]*m_pixelPerX , height() * 0.75 );
	painter.setPen( QPen ( QColor ( 0, 0, 0, 255), m_dotSize ,
						   Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.drawPoint( m_xModel->value()*m_pixelPerX, height() * 0.5 );

	//draw vu lines

}

void VuFader::resizeEvent(QResizeEvent *event)
{
	m_dotSize = width () / 10;
	TouchController::resizeEvent( event );
}

