#ifndef AUDIODEVICEVIEW_H
#define AUDIODEVICEVIEW_H

#include <QWidget>
#include "AudioDeviceControls.h"
#include <QLabel>
#include "VuFader.h"

class AudioDeviceView : public QWidget
{
	Q_OBJECT
public:
	explicit AudioDeviceView(QWidget *parent = 0, AudioDeviceControls *controls = 0 );
	~AudioDeviceView();

signals:

public slots:
	void updateText();

private:
	AudioDeviceControls *m_audioDeviceControls;
	VuFader *m_gainFader;

};

#endif // AUDIODEVICEVIEW_H
