#include "Ribbon.h"
#include <QPainter>
#include <QTouchEvent>



Ribbon::Ribbon(Model *xModel, Model *yModel, QWidget *parent) :
	TouchController( xModel, yModel, parent ),
	m_dotSize( 10 )
{
}


Ribbon::~Ribbon()
{

}




void Ribbon::paintEvent(QPaintEvent *event)
{
	Q_UNUSED( event );
	QPainter painter( this );
	painter.setPen( QPen( QColor( 200,200,200,255), m_dotSize,
						  Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.fillRect(0, 0, width(), height() , QBrush( QColor( 0, 0, 0, 255), Qt::SolidPattern ) );
	painter.drawPoint( m_pixelPerX * m_xModel->value(),height() - ( m_yModel->value()*m_pixelPerY) );
}

void Ribbon::resizeEvent(QResizeEvent *event)
{
	m_dotSize = height() / 10;
	TouchController::resizeEvent( event );

}







