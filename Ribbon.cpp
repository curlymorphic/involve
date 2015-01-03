#include "Ribbon.h"
#include <QPainter>



Ribbon::Ribbon(Model *freqModel, Model *velocityModel, QWidget *parent) :
	QWidget( parent ),
	m_freqModel( freqModel ),
	m_velocityModel( velocityModel ),
	m_minFreq( 30 ),
	m_maxFreq( 20000 )
{

}

Ribbon::~Ribbon()
{

}

void Ribbon::paintEvent(QPaintEvent *event)
{
	QPainter painter( this );
	painter.setPen( QPen( QColor( 100,100,100,100), 1,
						  Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	painter.fillRect(0, 0, width(), height() , QBrush( QColor( 100,100,100,100), Qt::SolidPattern ));
}

void Ribbon::resizeEvent(QResizeEvent *event)
{
	//todo calculate hz per pixel
	QWidget::resizeEvent( event );
}

