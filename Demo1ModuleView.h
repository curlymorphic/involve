#ifndef DEMO1MODULEVIEW_H
#define DEMO1MODULEVIEW_H

#include <QObject>
#include <QWidget>
#include "ModuleView.h"
#include "Demo1ModuleControls.h"
#include "Fader.h"
#include "VFader.h"

class Demo1ModuleView : public ModuleView
{
	Q_OBJECT
public:
	Demo1ModuleView( Demo1ModuleControls *controls, QWidget *parent = 0 , Qt::WindowFlags flags = 0);
	~Demo1ModuleView();
	virtual void layout();

private slots:
	void notePressed();
	void noteRelease();


private:
	Demo1ModuleControls *m_controls;


	VFader *m_cutOffFader;
	VFader *m_resFader;
	VFader *m_waveShapeFader;

	VFader *m_attackFader;
	VFader *m_decayFader;
	VFader *m_sustainFader;
	VFader *m_releaseFader;

};

#endif // DEMO1MODULEVIEW_H
