#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Types.h"
#include "AudioDevice.h"
#include "Fader.h"
#include "AudioDeviceControls.h"
#include "AudioDeviceView.h"


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
	QAudioFormat m_format;
	void initializeAudio();

private:
	Ui::MainWindow *ui;
	AudioDevice *m_audioDevice;
	Controls *m_controls;
	AudioDeviceControls *m_audioDeviceControls;
	AudioDeviceView *m_audioDeviceView;




};

#endif // MAINWINDOW_H
