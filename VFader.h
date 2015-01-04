#ifndef VFADER_H
#define VFADER_H

#include <QWidget>
#include "Model.h"
#include "TouchController.h"

class VFader : public TouchController
{
public:
	VFader( Model *xModel = 0, Model *yModel = 0, QWidget *parent = 0 );
	~VFader();

protected:
	virtual void paintEvent( QPaintEvent *event );
	virtual void resizeEvent( QResizeEvent *event);

private:

	qint64 m_dotSize;
};

#endif // VFADER_H
