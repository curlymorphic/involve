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
	m_attackFader = new VFader( &m_controls->attackModel, this );
	m_decayFader = new VFader( &m_controls->decayModel, this );
	m_sustainFader = new VFader( &m_controls->sustainModel, this );
	m_releaseFader = new VFader( &m_controls->releaseModel, this );




	m_cutOffFader->show();
	m_resFader->show();
	m_waveShapeFader->show();
	m_attackFader->show();
	m_decayFader->show();
	m_sustainFader->show();
	m_releaseFader->show();
}

Demo1ModuleView::~Demo1ModuleView()
{

}

void Demo1ModuleView::layout()
{
	const int height8 = height() / 8;
	const int wheight = height();
	const int wwidth = width();
//	resize( height-50, width-50 );

	m_cutOffFader->resize( wwidth * 0.1 , height8 * 2 );
	m_cutOffFader->move( wwidth * 0.1 , 0 );
	m_resFader->resize( wwidth * 0.1 , height8 * 2 );
	m_resFader->move( wwidth * 0.3 , 0 );
	m_waveShapeFader->resize( wwidth * 0.1 , height8 * 2 );
	m_waveShapeFader->move( wwidth * 0.5 , 0 );

	m_attackFader->resize( wwidth * 0.1 , height8 * 2 );
	m_decayFader->resize( wwidth * 0.1 , height8 * 2 );
	m_sustainFader->resize( wwidth * 0.1 , height8 * 2 );
	m_releaseFader->resize( wwidth * 0.1 , height8 * 2 );

	m_attackFader->move( wwidth * 0.1, height8 * 3 );
	m_decayFader->move( wwidth * 0.3, height8 * 3 );
	m_sustainFader->move( wwidth * 0.5, height8 * 3 );
	m_releaseFader->move( wwidth * 0.7, height8 * 3 );



}

void Demo1ModuleView::notePressed()
{
	m_controls->noteOn = true;
}

void Demo1ModuleView::noteRelease()
{
	m_controls->noteOff = true;
}




