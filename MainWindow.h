#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Types.h"
#include "AudioDevice.h"
#include "Fader.h"
#include "AudioDeviceControls.h"
#include "AudioDeviceView.h"
#include "AudioThread.h"
#include "Demo1ModuleControls.h"
#include "ModuleView.h"
#include "QResizeEvent"
#include "QApplication"
#include "QScreen"
#include "Ribbon.h"
#include "VFader.h"
#include "UiControls.h"
#include "AutomationSensor.h"


namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow( QWidget *parent = 0 );
	~MainWindow();



private:
	Ui::MainWindow *ui;

	Demo1ModuleControls *m_controls;
	AudioDeviceControls *m_audioDeviceControls;
	AudioDeviceView *m_audioDeviceView;
	AudioThread *m_audioThread;
	AudioModule *m_audioModule;
	ModuleView *m_moduleView;
	QTimer *periodicUpdate;
	Ribbon *m_ribbon;
	VFader *m_startOctaveFader;
	VFader *m_ocatveRangeFader;
	UiControls *m_uiControls;
	AutomationSensor *m_automationSensor;

protected:
	 virtual void resizeEvent(QResizeEvent * event)
	{
		const int height8 = QApplication::screens().at( 0 )->size().height() / 8;
		const int height = QApplication::screens().at( 0 )->size().height();
		const int width = QApplication::screens().at( 0 )->size().width();

		(void) event;

		if (m_ribbon)
		{
			m_ribbon->resize( width , height8 * 2);
			m_ribbon->move( 0, height- 50  - (height8 *2) );
		}

		if(m_ocatveRangeFader)
		{
			m_ocatveRangeFader->resize( width * 0.05 , height8 * 2 );
			m_ocatveRangeFader->move( width - ( width * 0.05 ) , 0);

			m_startOctaveFader->resize( width * 0.05 , height8 * 2 );
			m_startOctaveFader->move( width - ( width * 0.05 ) , height8*3 );
		}
		if(m_moduleView)
		{
			m_moduleView->resize( width * 0.95 ,
								  height - 50 - m_ribbon->height() );
//			m_moduleView->layout();
		}
		QMainWindow::resizeEvent( event );
	}

private slots:
	virtual void updateRibbon();




};

#endif // MAINWINDOW_H
