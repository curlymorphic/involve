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

#include "VFader.h"
#include <QPainter>
#include <QTouchEvent>
#include <QPalette>



VFader::VFader(  Model *yModel, QWidget *parent) :
	TouchController( 0, yModel, parent ),
	m_dotSize( 10 ),
	m_fader( 0 )
{
	setAttribute(Qt::WA_PaintUnclipped);
	QPalette *palette = new QPalette();
	palette->setBrush( QPalette::Background , *( new QBrush ( * (new QColor(0, 0, 0, 0 ) ) ) ) );
	setPalette( *palette );
}

VFader::~VFader()
{

}

void VFader::setFaderPixmap( QPixmap *pixamp )
{
	m_fader = pixamp;
}

void VFader::paintEvent(QPaintEvent *event)
{
	Q_UNUSED( event );
	QPainter painter( this );
	painter.setPen( QPen ( QColor ( 255, 0, 0, 255), 1 ,
						   Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.drawLine(width() * 0.5, 0, width() * 0.5 , height() );
	if( !m_fader )
	{
		painter.setPen( QPen ( QColor ( 255, 0, 0, 255), m_dotSize ,
							   Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
		painter.drawPoint( width() * 0.5 , height() - ( m_yModel->value()*m_pixelPerY) );
	}
	else
	{
		painter.drawPixmap(
					0 , height() - (int)(( ( m_yModel->value() - m_yModel->getMin() )* m_pixelPerY )
										 + ( m_fader->width() * 0.5 ) ), *m_fader  );
	}
}

void VFader::resizeEvent(QResizeEvent *event)
{
	m_dotSize = height() / 10;
	TouchController::resizeEvent( event );
}

