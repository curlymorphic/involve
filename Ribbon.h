#ifndef RIBBON_H
#define RIBBON_H

#include <QWidget>
#include "Model.h"

class Ribbon : public QWidget
{
	Q_OBJECT
public:
	explicit Ribbon( Model *xModel = 0, Model *yModel = 0, QWidget *parent = 0 );
	~Ribbon();
	void setMinX( float x );
	float getMinX();
	void setMaxX( float x);
	float getMaxX();

	void setMinY( float y );
	float getMinY();
	void setMaxY( float y );
	float getMaxY();

signals:

	void noteOn();
	void noteOff();

public slots:

protected:
	virtual void paintEvent( QPaintEvent *event );
	virtual void resizeEvent(QResizeEvent *event );
	virtual bool event( QEvent *event);

private:
	void recalculatePixelMultipliers();

	Model *m_xModel;
	Model *m_yModel;
	float m_minX;
	float m_maxX;
	float m_minY;
	float m_maxY;

	float m_pixelPerX;
	float m_pixelPerY;
	qint64 m_dotSize;
};

#endif // RIBBON_H
