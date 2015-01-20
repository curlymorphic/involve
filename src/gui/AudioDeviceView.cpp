#include "AudioDeviceView.h"
#include <QTimer>
#include <QApplication>
#include <QScreen>



AudioDeviceView::AudioDeviceView(QWidget *parent, AudioDeviceControls *controls) :
	QWidget( parent ),
	m_audioDeviceControls( controls ),
	m_gainFader(0)
{


	resize( parent->width() , 50 );
	const int height8 = QApplication::screens().at( 0 )->size().height() / 8;
	const int screenHeight = QApplication::screens().at( 0 )->size().height();
	const int ScreenWidth = QApplication::screens().at( 0 )->size().width();
	m_gainFader = new VuFader( &controls->m_gainModel , this , &m_audioDeviceControls->peaks );
	m_gainFader->resize(height8 * 2, height() );
	m_gainFader->move( 0, 0 );



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
	m_audioDeviceControls->peaks[0] -= qMax (m_audioDeviceControls->peaks[0] -  0.000001, 0.0 );
	m_audioDeviceControls->peaks[1] -= qMax( m_audioDeviceControls->peaks[1] -  0.000001, 0.0 );

}

