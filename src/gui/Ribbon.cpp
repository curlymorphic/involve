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

#include "Ribbon.h"
#include <QPainter>
#include <QTouchEvent>
#include "AudioMath.h"



Ribbon::Ribbon(Model *xModel, Model *yModel, QWidget *parent) :
	TouchController( xModel, yModel, parent ),
	m_dotSize( 10 ),
	m_notes( 0 )
{
	initilizeNotes();
}


Ribbon::~Ribbon()
{

}

void Ribbon::setModels(Model *xModel, Model *yModel)
{
	m_xModel = xModel;
	m_yModel = yModel;
}




void Ribbon::paintEvent(QPaintEvent *event)
{
	Q_UNUSED( event );
	QPainter painter( this );
	painter.setPen( QPen( QColor( 200,200,200,255), m_dotSize,
						  Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.fillRect(0, 0, width(), height() , QBrush( QColor( 0, 0, 0, 255), Qt::SolidPattern ) );
	painter.drawPoint( getXPixel( m_xModel->value() ) ,height() - ( m_yModel->value()*m_pixelPerY) );
	painter.setPen( QPen( QColor( 200,200,200,255), 6 ,
						  Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	for(int i = 12 ; i < 120 ; i += 12 )
	{
		painter.drawLine(getXPixel( m_notes[i] ) , 0 , getXPixel( m_notes[i] ), height() );
	}
	painter.setPen( QPen( QColor( 200,200,200,255), 3 ,
						  Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	for(int i = 12; i < 120 ; i++)
	{
		painter.drawLine(getXPixel(m_notes[i]) , 0 , getXPixel( m_notes[i]), height() );
	}
}

void Ribbon::resizeEvent(QResizeEvent *event)
{
	m_dotSize = height() / 10;
	TouchController::resizeEvent( event );

}

void Ribbon::initilizeNotes()
{
	if(m_notes) { delete m_notes; }
	m_notes = new float[120];

	for(int i =0 ; i < 120; i++)
	{
		m_notes[i] = midiNoteFreq( i );
	}
}







