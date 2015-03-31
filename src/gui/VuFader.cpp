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
	m_peaks( peaks ),
	m_xScale( 1 ),
	m_backgroundImage( 0 ),
	m_scaledBackgroundImage( 0 ),
	m_faderImage( 0 ),
	m_scaledFaderImage( 0 )
{
	setAutoFillBackground( true );
	QPalette* palette = new QPalette();
	m_backgroundImage = new QPixmap(":/new/prefix1/images/HFaderBack.png");
	m_scaledBackgroundImage = new QPixmap( *m_backgroundImage );
	palette->setBrush(QPalette::Background, *( new QBrush( *m_scaledBackgroundImage )));
	setPalette(*palette);
	m_faderImage = new QPixmap(":/new/prefix1/images/HFaderKnob.png");
	m_scaledFaderImage = new QPixmap(  ":/new/prefix1/images/HFaderKnob.png" );
}

VuFader::~VuFader()
{

}

void VuFader::paintEvent(QPaintEvent *event)
{
	m_pixelPerX = width()  / (m_maxX - m_minX );
	Q_UNUSED( event );
	QPainter painter( this );
	painter.setPen( QPen ( QColor ( 0, 0, 0, 255), 1 ,
						   Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
//	painter.drawLine( 0 , height() * 0.5 , width(), height() * 0.5 );
	painter.setPen( QPen ( QColor ( 0, 255, 0, 255), 1 ,
						   Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.drawLine( 0, (height() * 0.5 ) - 2,  m_peaks[0][0]*m_pixelPerX , (height() * 0.5 ) - 2 ) ;
	painter.drawLine( 0, (height() * 0.5 ) + 1,  m_peaks[0][1]*m_pixelPerX , (height() * 0.5 ) + 1 );
	painter.setPen( QPen ( QColor ( 0, 0, 0, 255), m_dotSize ,
						   Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
//	painter.drawPoint( m_xModel->value()*m_pixelPerX, height() * 0.5 );
	painter.drawPixmap( (int)((((  width() * 0.15 ) + m_xModel->value()*m_pixelPerX) ) - ( height() * 1.5 )  ),
						0, *m_scaledFaderImage);
	//draw vu lines

}

void VuFader::resizeEvent(QResizeEvent *event)
{
	m_dotSize = width () / 10;
	TouchController::resizeEvent( event );

	if(m_scaledBackgroundImage && m_backgroundImage->size() != event->size() )
	{
		*m_scaledBackgroundImage = m_backgroundImage->scaled( event->size() );
	}
	QPalette* palette = new QPalette();
	palette->setBrush(QPalette::Background, *( new QBrush( *m_scaledBackgroundImage )));
	setPalette(*palette);
	if( m_scaledFaderImage && m_scaledFaderImage->width() != event->size().height() )
	{
		*m_scaledFaderImage = m_faderImage->scaled( event->size().height(), event->size().height() );
	}
	m_xScale =  (float) event->size().width() / (float)m_backgroundImage->width() ;
}

