#include "ModuleFader.h"
#include <QResizeEvent>


ModuleFader::ModuleFader(Model *model, QWidget *parent) : QWidget(parent) ,
  m_model( model ),
  m_vFader( 0 ),
  m_label( 0 ),
  m_backgroundImage( 0 ),
  m_scaledBackgroundImage( 0 ),
  m_faderImage( 0 ),
  m_scaledFaderImage( 0 ),
  m_yScale( 1 )
{
	QPalette* palette = new QPalette();
	m_backgroundImage = new QPixmap(":/new/prefix1/images/FaderBack.png");
	m_scaledBackgroundImage = new QPixmap( *m_backgroundImage );
	palette->setBrush(QPalette::Background, *( new QBrush( *m_scaledBackgroundImage )));
	setPalette(*palette);
	m_faderImage = new QPixmap(":/new/prefix1/images/Faderknob.png");
	m_scaledFaderImage = new QPixmap(  ":/new/prefix1/images/Faderknob.png" );

	m_vFader = new VFader( model, this );
	m_vFader->show();
	m_vFader->setFaderPixmap( m_scaledFaderImage );

	m_label = new QLabel(this);
	QString lableText = m_model->getName();
	lableText.truncate( 4 );
	m_label->setText( lableText );
//	m_label->setAttribute( Qt::WA_OpaquePaintEvent );
	m_label->setAutoFillBackground( true );
	QPalette *p = new QPalette();
	p->setBrush( QPalette::Background , *( new QBrush ( * (new QColor(0, 0, 0, 0 ) ) ) ) );
	p->setBrush( QPalette::Foreground, *( new QBrush ( * (new QColor(200, 200, 200, 255 ) ) ) )    );
	m_label->setPalette( *p );
	m_label->show();

}

ModuleFader::~ModuleFader()
{

}

void ModuleFader::resizeEvent(QResizeEvent *event)
{
	if(m_scaledBackgroundImage && m_backgroundImage->size() != event->size() )
	{
		*m_scaledBackgroundImage = m_backgroundImage->scaled( event->size() );
	}
	QPalette* palette = new QPalette();
	palette->setBrush(QPalette::Background, *( new QBrush( *m_scaledBackgroundImage )));
	setPalette(*palette);
	if( m_scaledFaderImage && m_scaledFaderImage->width() != event->size().width() )
	{
		*m_scaledFaderImage = m_faderImage->scaled( event->size().width(), event->size().width() );
	}
	m_vFader->setFaderPixmap( m_scaledFaderImage );

	m_yScale =  (float) event->size().height() / (float)m_backgroundImage->height() ;

	m_label->move( 0, ( m_yScale * 24 ) + ( 118 * m_yScale ) );
	m_label->resize( event->size().width(), (event->size().height()) - ( ( m_yScale * 24 ) + ( 118 * m_yScale ) ) );
	m_label->setAlignment( Qt::AlignCenter );
	m_vFader->move(0, m_yScale * 24 );
	m_vFader->resize(event->size().width(), 118 * m_yScale );
	QWidget::resizeEvent( event );
	if( event->size().width() > event->size().height() * 0.5 ) resize( event->size().height() * 0.5, event->size().height() );

}

