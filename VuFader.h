#ifndef VUFADER_H
#define VUFADER_H

#include <QWidget>
#include "Model.h"
#include "TouchController.h"

class VuFader : public TouchController
{
public:
	VuFader( Model *xModel = 0, QWidget *parent = 0 );
	~VuFader();

protected:
	virtual void paintEvent( QPaintEvent *event );
	virtual void resizeEvent( QResizeEvent *event);

private:

	qint64 m_dotSize;
};

#endif // VUFADER_H
