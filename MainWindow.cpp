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


const int DurationSeconds = 1;
const int ToneSampleRateHz = 600;
const int DataSampleRateHz = 44100;
const int BufferSize      = 32768;




MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	m_controls( 0 ),
	m_audioDeviceControls( 0 )
{
	m_controls = new Demo1ModuleControls( this );
	m_audioDeviceControls = new AudioDeviceControls;
//	ui->setupUi(this);

//	showNormal();

	m_moduleView = new Demo1ModuleView( m_controls, this );
	m_moduleView->show();
	m_moduleView->resize( QApplication::screens().at( 0 )->size().width(),
						  QApplication::screens().at( 0 )->size().height() - 50 );
	m_moduleView->move( 0 , 50 );

	m_audioDeviceView = new AudioDeviceView( this, m_audioDeviceControls );
	m_audioDeviceView->show();
	m_audioModule = new Demo1AudioModule( 44100, m_controls );
		m_audioThread = new AudioThread(m_audioDeviceControls, m_audioModule, m_controls, this );
		m_audioThread->start(QThread::HighestPriority);
//	initializeAudio();

	periodicUpdate = new QTimer( this );
	periodicUpdate->start( 200 );

	connect( periodicUpdate, SIGNAL( timeout() ), this, SLOT( update() ));

}

MainWindow::~MainWindow()
{
	delete ui;

}






