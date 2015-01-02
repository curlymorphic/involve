#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QAudioDeviceInfo>
#include <QAudioOutput>
#include <qmath.h>
#include <qendian.h>
#include <QDebug>
#include "Types.h"
#include "AudioDeviceView.h"


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
	m_controls = new Controls( this );
	m_audioDeviceControls = new AudioDeviceControls;
	ui->setupUi(this);

	m_audioDeviceView = new AudioDeviceView( this, m_audioDeviceControls );
	m_audioDeviceView->show();
	//	m_audioThread = new AudioThread( this );
	//	m_audioThread->start();
	initializeAudio();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::initializeAudio()
{
	m_format.setSampleRate( 44100 );
	m_format.setChannelCount(2);
	m_format.setSampleSize(16);
	m_format.setCodec("audio/pcm");
	m_format.setByteOrder(QAudioFormat::LittleEndian);
	m_format.setSampleType(QAudioFormat::SignedInt);

	QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
	if (!info.isFormatSupported(m_format)) {
		qWarning() << "Default format not supported - trying to use nearest";
		m_format = info.nearestFormat(m_format);
	}
	m_audioDeviceControls->m_sampleRate = m_format.sampleRate();
	m_audioDevice = new AudioDevice(m_format, m_controls, m_audioDeviceControls, this);
	m_audioDevice->createAudioOutput();

	Fader *f = new Fader( &m_controls->m_freqModel, this );
	f->move(50,50);
	f->setOrientation(Qt::Horizontal);
	f->show();
}




