#include "Ribbon.h"
#include <QPainter>
#include <QTouchEvent>



Ribbon::Ribbon(Model *xModel, Model *yModel, QWidget *parent) :
	QWidget( parent ),
	m_xModel( xModel ),
	m_yModel( yModel ),
	m_minX( 0 ),
	m_maxX( 0 ),
	m_minY( 0 ),
	m_maxY( 0 ),
	m_pixelPerX( 1 ),
	m_pixelPerY( 0 ),
	m_dotSize( 10 )
{
	setAttribute( Qt::WA_AcceptTouchEvents, true);
	if(m_xModel)
	{
		m_minX = m_xModel->getMin();
		m_maxX = m_xModel->getMax();
	}
	if(m_yModel)
	{
		m_minY = m_yModel->getMin();
		m_maxY = m_yModel->getMax();
	}
}

Ribbon::~Ribbon()
{

}

void Ribbon::setMinX(float freq)
{
	m_minX = freq;
	recalculatePixelMultipliers();
}

float Ribbon::getMinX()
{
	return m_minX;
}

void Ribbon::setMaxX(float freq)
{
	m_maxX = freq;
	recalculatePixelMultipliers();
}

float Ribbon::getMaxX()
{
	return m_maxX;
}

void Ribbon::setMinY(float y)
{
	m_minY = y;
	recalculatePixelMultipliers();
}

float Ribbon::getMinY()
{
	return m_minY;
}

void Ribbon::setMaxY(float y)
{
	m_maxY = y;
	recalculatePixelMultipliers();
}

float Ribbon::getMaxY()
{
	return m_maxY;
}

void Ribbon::paintEvent(QPaintEvent *event)
{
	QPainter painter( this );
	painter.setPen( QPen( QColor( 200,200,200,255), m_dotSize,
						  Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.fillRect(0, 0, width(), height() , QBrush( QColor( 0,0,0,255), Qt::SolidPattern ));
	painter.drawPoint( m_pixelPerX * m_xModel->value(),height() - ( m_yModel->value()*m_pixelPerY));
}

void Ribbon::recalculatePixelMultipliers()
{
	m_pixelPerX = width() / (m_maxX - m_minX );
	m_pixelPerY = height() / (m_maxY - m_minY );
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
		if( x > 0 && x < width() ) { m_xModel->setValue( x / m_pixelPerX ); }
		if( y > 0 && y < height() ) { m_yModel->setValue( ( height() - y )/ m_pixelPerY ); }
		return true;
		break;
	}

	default:
		return QWidget::event( event );
	}
}

