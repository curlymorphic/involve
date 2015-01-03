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

signals:

public slots:

protected:
	virtual void paintEvent( QPaintEvent *event );
	virtual void resizeEvent(QResizeEvent *event );

private:
	Model *m_freqModel;
	Model *m_velocityModel;
	float m_minFreq;
	float m_maxFreq;
};

#endif // RIBBON_H
