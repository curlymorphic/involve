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



#ifndef DEMO2MODULEVIEW_H
#define DEMO2MODULEVIEW_H

#include <QObject>
#include <QWidget>
#include "ModuleView.h"
#include "Demo2ModuleControls.h"
#include "Fader.h"
#include "VFader.h"
#include "ModuleFader.h"
#include "WaveDisplay.h"
#include "SegmentOscillator.h"
#include "ExtendableSegementOscillator.h"
#include "QGroupBox"

class Demo2ModuleView : public ModuleView
{
	Q_OBJECT
public:
	Demo2ModuleView(ModuleControls *controls, QWidget *parent = 0 , Qt::WindowFlags flags = 0 );
	~Demo2ModuleView();
	virtual void layout();

public slots:
	void waveAChanged();
	void waveBChanged();
	void waveLfoChanged();
	void smallUi();
	void largeUi();

	private:
		Demo2ModuleControls *m_controls;

		ModuleFader **m_oscAWaveShapeFaders;
		ModuleFader *m_oscASegmentCountFader;
		WaveDisplay *m_oscAWaveDisplay;
		ModuleFader *m_oscAGainFader;
		ModuleFader *m_oscACourseDetuneFader;
		ModuleFader *m_oscAFineDetuneFader;
		ModuleFader *m_oscARetriggerFader;

		ModuleFader **m_oscBWaveShapeFaders;
		ModuleFader *m_oscBSegmentCountFader;
		WaveDisplay *m_oscBWaveDisplay;
		ModuleFader *m_oscBGainFader;
		ModuleFader *m_oscBCourseDetuneFader;
		ModuleFader *m_oscBFineDetuneFader;
		ModuleFader *m_oscBRetriggerFader;

		ModuleFader **m_lfoWaveShapeFaders;
		ModuleFader *m_lfoSegmentCountFader;
		ModuleFader *m_lfoRetriggerFader;
		ModuleFader *m_lfoSpeedFader;
		ModuleFader *m_lfoGainFader;
		ModuleFader *m_lfoFilterFader;
		WaveDisplay *m_lfoWaveDisplay;

		ModuleFader *m_mixModeFader;

		ModuleFader *m_attackFader;
		ModuleFader *m_decayFader;
		ModuleFader *m_sustainFader;
		ModuleFader *m_releaseFader;


		ModuleFader *m_cutoffFader;
		ModuleFader *m_resFader;
		ModuleFader *m_filterStagesFader;

		ModuleFader *m_delayAmountFader;
		ModuleFader *m_delayTimeFader;
		ModuleFader *m_delayFeedbackFader;

		QGroupBox *lfoShapeBox;
		QGroupBox *oscBShapeBox;


		//oscillaor used to generate wave display data
		SegmentOscillator m_oscA;
		SegmentOscillator m_oscB;
		ExtendableSegementOscillator m_lfo;

		float *m_waveAData;
		int m_oscAWaveLength;
		float *m_waveBData;
		int m_oscBWaveLength;
		float *m_waveLfoData;
		int m_lfoWaveLength;
};

#endif // DEMO2MODULEVIEW_H
