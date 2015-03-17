/*
 * Copyright (c) 2014-2015 Dave French <contact/dot/dave/dot/french3/at/googlemail/dot/com>
 *
 * This file is part of Involve - http://github.com/curlymorphic/involve
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


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
#include "ModuleFader.h"
#include <QGridLayout>
#include <QPushButton>

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow( QWidget *parent = 0 );
	~MainWindow();

private slots:
	void menuBtnPressed();
	void xBtnPressed();
	void yBtnPressed();



private:
	Ui::MainWindow *ui;

	ModuleControls *m_controls;
	AudioDeviceControls *m_audioDeviceControls;
	AudioDeviceView *m_audioDeviceView;
	AudioThread *m_audioThread;
	AudioModule *m_audioModule;
	ModuleView *m_moduleView;
	QTimer *periodicUpdate;
	Ribbon *m_ribbon;
	ModuleFader *m_startOctaveFader;
	ModuleFader *m_ocatveRangeFader;
	UiControls *m_uiControls;
	AutomationSensor *m_automationSensor;
	QGridLayout *m_gridLayout;
	QPushButton *m_menuBtn;
	QPushButton *m_xBtn;
	QPushButton *m_yBtn;

protected:
	 virtual void resizeEvent(QResizeEvent * event);

private slots:
	virtual void updateRibbon();




};

#endif // MAINWINDOW_H
