#include "Fader.h"


Fader::Fader(Model *model, QWidget *parent) : QSlider(parent)
{
	if( model ) { setModel( model ); }
	connect( this, SIGNAL( valueChanged( int ) ), this, SLOT( UiComponentValueChanged( int ) ) );
	setMinimumSize( 800, 100 );
}

Fader::~Fader()
{

}

void Fader::setModel(Model *model)
{
	m_model = model;
	connect( m_model, SIGNAL( dataChanged(int)) , this, SLOT( modelValueChanged( int ) ) );
	setMinimum( m_model->getMin() * multipler() );
	setMaximum( m_model->getMax() * multipler() );
	setValue( m_model->value() * multipler() );
	setTickInterval( 100 );
}

void Fader::modelValueChanged( int val )
{
	if(value() / multipler() != val )
	{
		setValue(val * multipler());
	}
}

void Fader::UiComponentValueChanged( int val )
{
	if(m_model->value() * multipler() != val )
	{
		m_model->setValue( (float)val / (float)multipler() );
	}
}


