#include "TouchController.h"
#include <QTouchEvent>



TouchController::TouchController(Model *xModel, Model *yModel, QWidget *parent) :
	QWidget( parent ),
	m_xModel( xModel ),
	m_yModel( yModel ),
	m_minX( 0 ),
	m_maxX( 0 ),
	m_minY( 0 ),
	m_maxY( 0 ),
	m_pixelPerX( 1 ),
	m_pixelPerY( 0 )
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

TouchController::~TouchController()
{

}

void TouchController::setMinX(float x)
{
	m_minX = x;
	recalculatePixelMultipliers();
}

float TouchController::getMinX()
{
	return m_minX;
}

void TouchController::setMaxX(float x)
{
	m_maxX = x;
	recalculatePixelMultipliers();
}

float TouchController::getMaxX()
{
	return m_maxX;
}

void TouchController::setMinY(float y)
{
	m_minY = y;
	recalculatePixelMultipliers();
}

float TouchController::getMinY()
{
	return m_minY;
}

void TouchController::setMaxY(float y)
{
	m_maxY = y;
	recalculatePixelMultipliers();
}

float TouchController::getMaxY()
{
	return m_maxY;
}

void TouchController::resizeEvent(QResizeEvent *event)
{
	recalculatePixelMultipliers();
	QWidget::resizeEvent( event );
}

bool TouchController::event(QEvent *event)
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
		if( m_xModel && x > 0 && x < width() ) { m_xModel->setValue( x / m_pixelPerX ); }
		if( m_yModel && y > 0 && y < height() ) { m_yModel->setValue( ( height() - y )/ m_pixelPerY ); }
		return true;
		break;
	}

	default:
		return QWidget::event( event );
	}
}

void TouchController::recalculatePixelMultipliers()
{
	m_pixelPerX = width() / (m_maxX - m_minX );
	m_pixelPerY = height() / (m_maxY - m_minY );

}

