#ifndef RIBBON_H
#define RIBBON_H

#include <QWidget>
#include "Model.h"

class Ribbon : public QWidget
{
	Q_OBJECT
public:
	explicit Ribbon( Model *freqModel = 0, Model *velocityModel = 0, QWidget *parent = 0 );
	~Ribbon();
	void setMinFreq( float freq );
	float getMinFreq();
	void setMaxFreq( float freq);
	float getMaxFreq();

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

	Model *m_freqModel;
	Model *m_velocityModel;
	float m_minFreq;
	float m_maxFreq;

	float m_pixelPerHz;
	float m_pixelPerVel;
	qint64 m_dotSize;
};

#endif // RIBBON_H
