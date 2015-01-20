#ifndef MODEL_H
#define MODEL_H

#include <QObject>

///
/// \brief The Model class
///This class is used to pass data about, it can be linked to many ui components
class Model : public QObject
{
	Q_OBJECT
public:
	explicit Model( float init, float min, float max, float interval, QString name, QObject *parent = 0);
	~Model();
	void setValue( float val );
	inline float value() const
	{
		return m_value;
	}

	void inc(float val);
	bool isChanged() const
	{
		return m_initValueChanged;
	}

	inline float getMax() const
	{
		return m_max;
	}

	inline float getMin() const
	{
		return m_min;
	}

	inline void setMax( float max)
	{
		m_max = max;
	}

	inline void setMin( float min )
	{
		m_min = min;
	}

signals:
	void dataChanged( float );

public slots:

private:
	float m_value;
	float m_initial;
	float m_min;
	float m_max;
	float m_interval;
	QString m_name;
	bool m_initValueChanged;

};

#endif // MODEL_H
