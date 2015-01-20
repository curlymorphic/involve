#include "ModuleView.h"
#include "MainWindow.h"

ModuleView::ModuleView( QWidget *parent, ModuleControls *controls, Qt::WindowFlags flags) :
	QWidget( parent, flags )
{
	m_moduleControls = controls;
}



ModuleView::~ModuleView()
{

}

void ModuleView::layout()
{

}

void ModuleView::notePressed()
{
	m_moduleControls->noteOnModel.setValue( 1.0 );
}

void ModuleView::noteRelease()
{
	m_moduleControls->noteOnModel.setValue( 0.0 );
}


