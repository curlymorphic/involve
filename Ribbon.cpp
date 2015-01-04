#include "Ribbon.h"
#include <QPainter>
#include <QTouchEvent>



Ribbon::Ribbon(Model *freqModel, Model *velocityModel, QWidget *parent) :
	QWidget( parent ),
	m_freqModel( freqModel ),
	m_velocityModel( velocityModel ),
	m_minFreq( 60 ),
	m_maxFreq( 200 ),
	m_pixelPerHz( 1 ),
	m_pixelPerVel( 0 ),
	m_dotSize( 10 )
{
	setAttribute( Qt::WA_AcceptTouchEvents, true);
}

Ribbon::~Ribbon()
{

}

void Ribbon::setMinFreq(float freq)
{
	m_minFreq = freq;
	recalculatePixelMultipliers();
}

float Ribbon::getMinFreq()
{
	return m_minFreq;
}

void Ribbon::setMaxFreq(float freq)
{
	m_maxFreq = freq;
	recalculatePixelMultipliers();
}

float Ribbon::getMaxFreq()
{
	return m_maxFreq;
}

void Ribbon::paintEvent(QPaintEvent *event)
{
	QPainter painter( this );
	painter.setPen( QPen( QColor( 200,200,200,255), m_dotSize,
						  Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.fillRect(0, 0, width(), height() , QBrush( QColor( 0,0,0,255), Qt::SolidPattern ));
	painter.drawPoint( m_pixelPerHz * m_freqModel->value(),height() - ( m_velocityModel->value()*m_pixelPerVel));
}

void Ribbon::recalculatePixelMultipliers()
{
	m_pixelPerHz = width() / (m_maxFreq - m_minFreq );
	m_pixelPerVel = height();
	m_dotSize = height() / 10;
}

void Ribbon::resizeEvent(QResizeEvent *event)
{
	recalculatePixelMultipliers();
	QWidget::resizeEvent( event );
}

bool Ribbon::event(QEvent *event)
{
	switch (event->type())
	{
	case QEvent::TouchBegin:
	case QEvent::TouchEnd:
	case QEvent::TouchUpdate:

	{
		if(event->type() == QEvent::TouchBegin ) { emit noteOn(); }
		if(event->type() == QEvent::TouchEnd ) { emit noteOff(); }
		QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
		int x = touchEvent->touchPoints().at(0).pos().x();
		int y = touchEvent->touchPoints().at(0).pos().y();
		if( x > 0 && x < width() ) { m_freqModel->setValue( x / m_pixelPerHz ); }
		if( y > 0 && y < height() ) { m_velocityModel->setValue( ( height() - y )/ m_pixelPerVel ); }
		return true;
		break;
	}

	default:
		return QWidget::event( event );
	}
}

