#ifndef VUFADER_H
#define VUFADER_H

#include <QWidget>
#include "Model.h"
#include "TouchController.h"
#include "AudioMath.h"

class VuFader : public TouchController
{
public:
	VuFader( Model *xModel = 0, QWidget *parent = 0, sampleFrame *peaks = 0 );
	~VuFader();

protected:
	virtual void paintEvent( QPaintEvent *event );
	virtual void resizeEvent( QResizeEvent *event);

private:

	qint64 m_dotSize;
	sampleFrame *m_peaks;
};

#endif // VUFADER_H
