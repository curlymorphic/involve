#ifndef TOUCHCONTROLLER_H
#define TOUCHCONTROLLER_H

#include <QWidget>
#include "Model.h"

class TouchController : public QWidget
{
	Q_OBJECT
public:

	TouchController(Model *xModel = 0, Model *yModel = 0, QWidget *parent = 0);
	~TouchController();
	void recalculatePixelMultipliers();

	void setMinX( float x );
	float getMinX();
	void setMaxX( float x);
	float getMaxX();

	void setMinY( float y );
	float getMinY();
	void setMaxY( float y );
	float getMaxY();

	qint64 getXPixel( float val );
	qint64 getYPixel( float val );

signals:

	void noteOn();
	void noteOff();

protected:

	virtual void resizeEvent(QResizeEvent *event );
	virtual bool event( QEvent *event);
	Model *m_xModel;
	Model *m_yModel;
	float m_minX;
	float m_maxX;
	float m_minY;
	float m_maxY;

	float m_pixelPerX;
	float m_pixelPerY;


private:



};

#endif // TOUCHCONTROLLER_H
