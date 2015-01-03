#ifndef DEMO1MODULEVIEW_H
#define DEMO1MODULEVIEW_H

#include <QObject>
#include <QWidget>
#include "ModuleView.h"
#include "Demo1ModuleControls.h"

class Demo1ModuleView : public ModuleView
{
	Q_OBJECT
public:
	Demo1ModuleView( Demo1ModuleControls *controls, QWidget *parent = 0 , Qt::WindowFlags flags = 0);
	~Demo1ModuleView();

private:
	Demo1ModuleControls *m_controls;
};

#endif // DEMO1MODULEVIEW_H
