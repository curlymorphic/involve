#include "VuFader.h"
#include <QPainter>
#include <QTouchEvent>


VuFader::VuFader(Model *xModel, QWidget *parent) :
	TouchController( xModel , 0, parent ),
	m_dotSize( 10 )
{

}

VuFader::~VuFader()
{

}

void VuFader::paintEvent(QPaintEvent *event)
{
	Q_UNUSED( event );
	QPainter painter( this );
	painter.setPen( QPen ( QColor ( 0, 0, 0, 255), 1 ,
						   Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.drawLine( 0 , height() * 0.5 , width(), height() * 0.5 );
	painter.setPen( QPen ( QColor ( 0, 0, 0, 255), m_dotSize ,
						   Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.drawPoint( m_xModel->value()*m_pixelPerX, height() * 0.5 );
}

void VuFader::resizeEvent(QResizeEvent *event)
{
	m_dotSize = width () / 10;
	TouchController::resizeEvent( event );
}

