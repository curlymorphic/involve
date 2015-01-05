#include "VFader.h"
#include <QPainter>
#include <QTouchEvent>



VFader::VFader(  Model *yModel, QWidget *parent) :
	TouchController( 0, yModel, parent ),
	m_dotSize( 10 )
{

}

VFader::~VFader()
{

}

void VFader::paintEvent(QPaintEvent *event)
{
	Q_UNUSED( event );
	QPainter painter( this );
	painter.setPen( QPen ( QColor ( 0, 0, 0, 255), 1 ,
						   Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.drawLine(width() * 0.5, 0, width() * 0.5 , height() );
	painter.setPen( QPen ( QColor ( 0, 0, 0, 255), m_dotSize ,
						   Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.drawPoint( width() * 0.5 , height() - ( m_yModel->value()*m_pixelPerY) );
}

void VFader::resizeEvent(QResizeEvent *event)
{
	m_dotSize = height() / 10;
	TouchController::resizeEvent( event );
}

