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

protected:
	 virtual void resizeEvent(QResizeEvent * event)
	{
		(void) event;
		if(m_moduleView)
		{
			m_moduleView->resize( QApplication::screens().at( 0 )->size().width(),
								  QApplication::screens().at( 0 )->size().height() - 50 );
			m_moduleView->layout();
		}
		QMainWindow::resizeEvent( event );
	}





};

#endif // MAINWINDOW_H
