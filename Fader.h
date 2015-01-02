#ifndef FADER_H
#define FADER_H

#include <QWidget>
#include <QSlider>
#include "Model.h"


///
/// \brief The Fader class
/// Model compatable ui component
///
class Fader : public QSlider
{
	Q_OBJECT
public:
	explicit Fader( Model *model = 0, QWidget *parent = 0 );
	~Fader();
	void setModel(Model *model);
	inline int multipler()
	{
		return 10;
	}

signals:

public slots:
	void modelValueChanged( int val);
	void UiComponentValueChanged( int );

private:
	Model *m_model;
};


#endif // FADER_H
