#ifndef MODULEVIEW_H
#define MODULEVIEW_H

#include <QWidget>
#include "ModuleControls.h"

///
/// \brief The ModuleView class
/// base class for module GUI
class ModuleView : public QWidget
{
	Q_OBJECT
public:
	ModuleView( QWidget *parent = 0 , ModuleControls *controls = 0, Qt::WindowFlags flags = 0 );
	~ModuleView();
	virtual void layout();

private slots:
	void notePressed();
	void noteRelease();

protected:
	virtual void resizeEvent( QResizeEvent *event)
	{
		QWidget::resizeEvent( event );
		layout();
	}

private:

	ModuleControls *m_moduleControls;





};

#endif // MODULEVIEW_H
