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
	ui->setupUi(this);

	Fader *f = new Fader( &m_controls->freqModel, this );
	f->move(50,50);
	f->setOrientation(Qt::Horizontal);
	f->show();

	m_audioDeviceView = new AudioDeviceView( this, m_audioDeviceControls );
	m_audioDeviceView->show();
	m_audioModule = new Demo1AudioModule( 44100, m_controls );
		m_audioThread = new AudioThread(m_audioDeviceControls, m_audioModule, m_controls, this );
		m_audioThread->start(m_audioThread->HighPriority);
//	initializeAudio();
}

MainWindow::~MainWindow()
{
	delete ui;

}






