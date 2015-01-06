#include "Ribbon.h"
#include <QPainter>
#include <QTouchEvent>
#include "AudioMath.h"



Ribbon::Ribbon(Model *xModel, Model *yModel, QWidget *parent) :
	TouchController( xModel, yModel, parent ),
	m_dotSize( 10 ),
	m_notes( 0 )
{
	initilizeNotes();
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
	painter.drawPoint( getXPixel( m_xModel->value() ) ,height() - ( m_yModel->value()*m_pixelPerY) );
	painter.setPen( QPen( QColor( 200,200,200,255), 6 ,
						  Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	for(int i = 12 ; i < 120 ; i += 12 )
	{
		painter.drawLine(getXPixel( m_notes[i] ) , 0 , getXPixel( m_notes[i] ), height() );
	}
	painter.setPen( QPen( QColor( 200,200,200,255), 3 ,
						  Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin ));
	for(int i = 12; i < 120 ; i++)
	{
		painter.drawLine(getXPixel(m_notes[i]) , 0 , getXPixel( m_notes[i]), height() );
	}
}

void Ribbon::resizeEvent(QResizeEvent *event)
{
	m_dotSize = height() / 10;
	TouchController::resizeEvent( event );

}

void Ribbon::initilizeNotes()
{
	if(m_notes) { delete m_notes; }
	m_notes = new float[120];

	for(int i =0 ; i < 120; i++)
	{
		m_notes[i] = midiNoteFreq( i );
	}
}







