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

#include "AudioDeviceView.h"
#include <QTimer>
#include <QApplication>
#include <QScreen>



AudioDeviceView::AudioDeviceView(QWidget *parent, AudioDeviceControls *controls) :
	QWidget( parent ),
	m_audioDeviceControls( controls ),
	m_gainFader(0)
{


//	resize( parent->width() , 50 );
	const int height8 = QApplication::screens().at( 0 )->size().height() / 8;
	m_gainFader = new VuFader( &controls->m_gainModel , this , &m_audioDeviceControls->peaks );



	QTimer *t = new QTimer( this );
	t->setSingleShot( false );
	t->start( 200 );

	connect( t, SIGNAL( timeout() ), this, SLOT( updateText() ) );


}

AudioDeviceView::~AudioDeviceView()
{

}

void AudioDeviceView::resizeEvent(QResizeEvent *ev)
{
	m_gainFader->resize(QApplication::screens().at( 0 )->size().width()* 0.5 , height() );
	m_gainFader->move( 0, 0 );

}

void AudioDeviceView::updateText()
{
	m_audioDeviceControls->peaks[0] -= qMax (m_audioDeviceControls->peaks[0] -  0.000001, 0.0 );
	m_audioDeviceControls->peaks[1] -= qMax( m_audioDeviceControls->peaks[1] -  0.000001, 0.0 );

}

