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

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QAudioDeviceInfo>
#include <QAudioOutput>
#include <qmath.h>
#include <qendian.h>
#include <QDebug>
#include "Types.h"
#include "AudioDeviceView.h"
#include "AudioThread.h"
#include <QThread>
#include "Demo1ModuleControls.h"
#include "Demo1ModuleView.h"
#include <QApplication>
#include "QScreen"
#include "VFader.h"
#include <QPalette>
#include <QDesktopWidget>
#include <QGridLayout>


const int DurationSeconds = 1;
const int ToneSampleRateHz = 600;
const int DataSampleRateHz = 44100;
const int BufferSize      = 32768;




MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	m_controls( 0 ),
	m_audioDeviceControls( 0 ),
	m_gridLayout( 0 )
{
	m_controls = new Demo1ModuleControls( this );
	m_audioDeviceControls = new AudioDeviceControls;
	m_uiControls = new UiControls( this );
//	ui->setupUi(this);

//	showNormal();

	QPalette* palette = new QPalette();
	QPixmap *gb = new QPixmap(":/new/prefix1/images/Box.png");
	*gb = gb->scaled(QApplication::screens().at( 0 )->size().width(),
					 QApplication::screens().at( 0 )->size().height() );

	palette->setBrush(QPalette::Background, *( new QBrush( *gb )));
	setPalette(*palette);

	m_gridLayout = new QGridLayout( );

	m_audioDeviceView = new AudioDeviceView( this, m_audioDeviceControls );
	m_audioDeviceView->show();
	m_ocatveRangeFader = new ModuleFader( &m_uiControls->octaves, this);
	m_ocatveRangeFader->show();

	m_startOctaveFader = new ModuleFader( &m_uiControls->startOctave, this ) ;
	m_startOctaveFader->show();


	m_moduleView = new Demo1ModuleView( m_controls, this );
	m_moduleView->show();

	m_ribbon = new Ribbon( &m_controls->freqModel, &m_controls->velocityModel, this );
	connect( m_ribbon, SIGNAL( noteOn() ), m_moduleView, SLOT( notePressed() ) ) ;
	connect( m_ribbon, SIGNAL( noteOff() ), m_moduleView, SLOT( noteRelease() ) );

	m_audioModule = new Demo1AudioModule( 44100, m_controls );
	m_audioThread = new AudioThread(m_audioDeviceControls, m_audioModule, m_controls, this );
	m_audioThread->start(QThread::HighestPriority);


	periodicUpdate = new QTimer( this );
	periodicUpdate->start( 50 );

	connect( periodicUpdate, SIGNAL( timeout() ), this, SLOT( updateRibbon() ));
		connect( periodicUpdate, SIGNAL( timeout() ), this, SLOT( update() ));

	m_automationSensor = new AutomationSensor( this );
	m_automationSensor->m_xModel = &m_controls->cutOffModel;
	m_automationSensor->m_yModel = &m_controls->resModel;

}

MainWindow::~MainWindow()
{
//	delete ui;
	if ( m_startOctaveFader ) { delete m_startOctaveFader; }
	if( m_ocatveRangeFader ) { delete m_ocatveRangeFader; }

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
	const int height8 = QApplication::screens().at( 0 )->size().height() / 8;
	const int height = QApplication::screens().at( 0 )->size().height();
	const int width = QApplication::screens().at( 0 )->size().width();

	(void) event;

	if (m_ribbon)
	{
		m_ribbon->resize( width , height8 * 2);
		m_ribbon->move( 0, height- 50  - (height8 *2) );
	}

	if(m_ocatveRangeFader)
	{
		m_ocatveRangeFader->resize( width * 0.1 , height8 * 2 );
		m_ocatveRangeFader->move( width - ( width * 0.1 ) , ( height * 0.05 ));

		m_startOctaveFader->resize( width * 0.1 , height8 * 2 );
		m_startOctaveFader->move( width - ( width * 0.1 ) , height8*3 );
	}
	if(m_moduleView)
	{
		m_moduleView->resize( width * 0.90 ,
							  height - ( height * 0.05 ) - m_ribbon->height() - 50 );
		m_moduleView->layout();
		m_moduleView->move( 0, height * 0.05 );
	}
	if( m_audioDeviceView )
	{
		m_audioDeviceView->resize( width * 0.90, height * 0.05 );
	}

	QMainWindow::resizeEvent( event );
}



void MainWindow::updateRibbon()
{
	m_controls->freqModel.setMin( midiNoteFreq( (int)m_uiControls->startOctave.value()*12 ) );
	m_controls->freqModel.setMax(  midiNoteFreq( ((int) m_uiControls->startOctave.value() * 12 ) +
												 m_uiControls->octaves.value() * 12 ) );
	m_ribbon->recalculatePixelMultipliers();
	m_moduleView->layout();
	QMainWindow::update();
}






