#ifndef DEMO1MODULEVIEW_H
#define DEMO1MODULEVIEW_H

#include <QObject>
#include <QWidget>
#include "ModuleView.h"
#include "Demo1ModuleControls.h"
#include "Fader.h"
#include "VFader.h"

///
/// \brief The Demo1ModuleView class
/// A simple single oscillator ADSR LFO Filter Delay example
class Demo1ModuleView : public ModuleView
{
	Q_OBJECT
public:
	Demo1ModuleView( Demo1ModuleControls *controls, QWidget *parent = 0 , Qt::WindowFlags flags = 0);
	~Demo1ModuleView();
	virtual void layout();




private:
	Demo1ModuleControls *m_controls;


	VFader *m_cutOffFader;
	VFader *m_resFader;
	VFader *m_waveShapeFader;

	VFader *m_attackFader;
	VFader *m_decayFader;
	VFader *m_sustainFader;
	VFader *m_releaseFader;

	VFader *m_adsrGainFader;
	VFader *m_adsrFilterFader;
	VFader *m_lfoSpeedFader;
	VFader *m_lfoShapeFader;
	VFader *m_lfoGainFader;
	VFader *m_lfoFilterFader;

	VFader *m_delayAmmountFader;
	VFader *m_delayTimeFader;
	VFader *m_delayRegenFader;

};

#endif // DEMO1MODULEVIEW_H
