#include "Model.h"



Model::Model(float init, float min, float max, float interval, QString name, QObject *parent) :
	QObject( parent ),
	m_value( init ),
	m_initial( init ),
	m_min( min ),
	m_max( max ),
	m_interval( interval ),
	m_name( name ),
	m_initValueChanged(false)
{
	emit dataChanged(init);
}

Model::~Model()
{

}

void Model::setValue(float val)
{
	if( val < m_min ) { m_value = val; }
	else if( val > m_max ) { m_value = val; }
	else { m_value = val; }

	if( m_value != m_initial ) { m_initValueChanged = true; }

	emit dataChanged( m_value);

}

void Model::inc(float val)
{
	setValue( value() + val);
}

