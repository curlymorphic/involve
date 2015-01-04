#include "Demo1ModuleView.h"
#include "Fader.h"
#include <QApplication>
#include "QScreen"
#include "Ribbon.h"



Demo1ModuleView::Demo1ModuleView(Demo1ModuleControls *controls, QWidget *parent,
								 Qt::WindowFlags flags) :
	ModuleView( parent, flags ),
	m_controls( controls )
{
	m_freqFader = new VFader( 0, &m_controls->freqModel , this );
	m_gainFader = new Fader( &m_controls->gainModel, this );
	m_cutOffFader = new Fader(&m_controls->cutOffModel, this );
	m_resFader = new Fader( &m_controls->resModel, this );
	m_ribbon = new Ribbon( &m_controls->freqModel, &m_controls->gainModel, this );

	m_freqFader->show( );
	m_gainFader->show();
	m_cutOffFader->show();
	m_resFader->show();
}

Demo1ModuleView::~Demo1ModuleView()
{

}

void Demo1ModuleView::layout()
{
	const int height8 = QApplication::screens().at( 0 )->size().height() / 8;
	const int height = QApplication::screens().at( 0 )->size().height();
	const int width = QApplication::screens().at( 0 )->size().width();
//	resize( height-50, width-50 );
	m_freqFader->move( width * 0.1 , height8  - 50  );
	m_freqFader->resize( width * 0.8 , 200 );
//	m_freqFader->setOrientation( Qt::Horizontal );
	m_gainFader->resize( width * 0.8 , m_gainFader->height() );
	m_gainFader->setOrientation( Qt::Horizontal );
	m_gainFader->move( width * 0.1 , height8 * 2 );
	m_cutOffFader->resize( width * 0.8 , m_cutOffFader->height() );
	m_cutOffFader->setOrientation( Qt::Horizontal );
	m_cutOffFader->move( width * 0.1 , height8 * 3 );
	m_resFader->resize( width * 0.8 , m_resFader->height() );
	m_resFader->setOrientation( Qt::Horizontal );
	m_resFader->move( width * 0.1 , height8 * 4 );

	m_ribbon->resize( width , height8 * 2);
	m_ribbon->move( 0, height - (height8 *3) );

}




