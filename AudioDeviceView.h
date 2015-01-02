#ifndef AUDIODEVICEVIEW_H
#define AUDIODEVICEVIEW_H

#include <QWidget>
#include "AudioDeviceControls.h"
#include <QLabel>

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
	QLabel *m_sampleRateLabel;
	QLabel *m_bufferSizeLabel;

};

#endif // AUDIODEVICEVIEW_H
