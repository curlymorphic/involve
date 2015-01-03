#ifndef MODULEVIEW_H
#define MODULEVIEW_H

#include <QWidget>
#include "ModuleControls.h"


class ModuleView : public QWidget
{
	Q_OBJECT
public:
	ModuleView( QWidget *parent = 0 , Qt::WindowFlags flags = 0 );
	~ModuleView();
	virtual void layout();





};

#endif // MODULEVIEW_H
