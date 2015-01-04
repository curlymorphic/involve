#ifndef RIBBON_H
#define RIBBON_H

#include <QWidget>
#include "Model.h"
#include "TouchController.h"

class Ribbon : public TouchController
{
	Q_OBJECT
public:
	explicit Ribbon( Model *xModel = 0, Model *yModel = 0, QWidget *parent = 0 );
	~Ribbon();


protected:
	virtual void paintEvent( QPaintEvent *event );
	virtual void resizeEvent( QResizeEvent *event);

private:

	qint64 m_dotSize;
};

#endif // RIBBON_H
