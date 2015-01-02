#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Types.h"
#include "AudioDevice.h"
#include "Fader.h"
#include "AudioDeviceControls.h"
#include "AudioDeviceView.h"
#include "AudioThread.h"


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

	Controls *m_controls;
	AudioDeviceControls *m_audioDeviceControls;
	AudioDeviceView *m_audioDeviceView;
	AudioThread *m_audioThread;




};

#endif // MAINWINDOW_H
