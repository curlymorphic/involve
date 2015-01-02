#include "Controls.h"

Controls::Controls(QObject *parent) : QObject(parent),
  m_freqModel(200.0,40.0,400.0,0.1, tr ( "Frequency" ) , this ),
  m_gainModel(1.0,0.0,2.0, 0.1, tr( "Gain" ), this )
{

}

Controls::~Controls()
{

}

