#ifndef MODULEFADER_H
#define MODULEFADER_H

#include <QWidget>
#include "Model.h"
#include "VFader.h"
#include <QLabel>

class ModuleFader : public QWidget
{
	Q_OBJECT
public:
	explicit ModuleFader(Model *model = 0, QWidget *parent = 0);
	~ModuleFader();


signals:

public slots:
	void resizeEvent( QResizeEvent *event);

private:
	Model *m_model;
	VFader *m_vFader;
	QLabel *m_label;
	QPixmap *m_backgroundImage;
	QPixmap *m_scaledBackgroundImage;
	QPixmap *m_faderImage;
	QPixmap *m_scaledFaderImage;


	float m_yScale;

};

#endif // MODULEFADER_H
