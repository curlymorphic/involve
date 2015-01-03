#include "AudioDeviceView.h"
#include <QTimer>



AudioDeviceView::AudioDeviceView(QWidget *parent, AudioDeviceControls *controls) :
	QWidget( parent ),
	m_audioDeviceControls( controls )
{


	resize( parent->width() , 50 );

	m_sampleRateLabel = new QLabel( this );
	m_sampleRateLabel->move ( 5, 5 );
	m_sampleRateLabel->resize( 200, m_sampleRateLabel->height() );

	m_bufferSizeLabel = new QLabel( this );
	m_bufferSizeLabel->move( 200, 5 );
	m_bufferSizeLabel->resize( 200, m_bufferSizeLabel->height() );

	QTimer *t = new QTimer( this );
	t->setSingleShot( false );
	t->start( 200 );

	connect( t, SIGNAL( timeout() ), this, SLOT( updateText() ) );


}

AudioDeviceView::~AudioDeviceView()
{

}

void AudioDeviceView::updateText()
{
	m_sampleRateLabel->setText( QString::number( m_audioDeviceControls->m_sampleRate ) );
	m_bufferSizeLabel->setText( QString::number( m_audioDeviceControls->m_bufferSize ) );
}

