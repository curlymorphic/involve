#ifndef MINISEGMODULEVIEW_H
#define MINISEGMODULEVIEW_H

#include "Demo2/Demo2ModuleView.h"

class MiniSegModuleView : public  Demo2ModuleView
{
public:
	MiniSegModuleView(ModuleControls *controls, QWidget *parent = 0 , Qt::WindowFlags flags = 0 ) ;
	~MiniSegModuleView();
};

#endif // MINISEGMODULEVIEW_H
