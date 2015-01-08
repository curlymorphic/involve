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

	m_cutOffFader = new VFader(&m_controls->cutOffModel, this );
	m_resFader = new VFader( &m_controls->resModel, this );
	m_waveShapeFader = new VFader( &m_controls->waveShapeModel, this );




	m_cutOffFader->show();
	m_resFader->show();
	m_waveShapeFader->show();
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

	m_cutOffFader->resize( width * 0.1 , height8 * 2 );
	m_cutOffFader->move( width * 0.1 , 0 );
	m_resFader->resize( width * 0.1 , height8 * 2 );
	m_resFader->move( width * 0.3 , 0 );
	m_waveShapeFader->resize( width * 0.1 , height8 * 2 );
	m_waveShapeFader->move( width * 0.5 , 0 );



}

void Demo1ModuleView::notePressed()
{
	m_controls->noteOn = true;
}

void Demo1ModuleView::noteRelease()
{
	m_controls->noteOff = true;
}




