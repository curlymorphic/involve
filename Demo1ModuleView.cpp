#include "Demo1ModuleView.h"
#include "Fader.h"
#include <QApplication>
#include "QScreen"



Demo1ModuleView::Demo1ModuleView(Demo1ModuleControls *controls, QWidget *parent,
								 Qt::WindowFlags flags) :
	ModuleView( parent, flags ),
	m_controls( controls )
{
	const int height8 = QApplication::screens().at( 0 )->size().height() / 8;
	Fader *freqFader = new Fader( &m_controls->freqModel , this );
	freqFader->move( width() * 0.1 , height8  );
	freqFader->resize( width() * 0.8 , freqFader->height() );
	freqFader->setOrientation( Qt::Horizontal );
	freqFader->show();

	Fader *gainFader = new Fader( &m_controls->gainModel, this);
	gainFader->resize( width() * 0.8 , gainFader->height() );
	gainFader->setOrientation( Qt::Horizontal );
	gainFader->show();
	gainFader->move( width() * 0.1 , height8 * 2 );

	Fader *cutOffFader = new Fader (&m_controls->cutOffModel, this);
	cutOffFader->resize( width() * 0.8 , cutOffFader->height() );
	cutOffFader->setOrientation( Qt::Horizontal );
	cutOffFader->show();
	cutOffFader->move( width() * 0.1 , height8 * 3 );

	Fader *resFader = new Fader ( &m_controls->resModel, this );
	resFader->resize( width() * 0.8 , resFader->height() );
	resFader->setOrientation( Qt::Horizontal );
	resFader->show();
	resFader->move( width() * 0.1 , height8 * 4 );

}

Demo1ModuleView::~Demo1ModuleView()
{

}

