/*
 * Copyright (c) 2014-2015 Dave French <contact/dot/dave/dot/french3/at/googlemail/dot/com>
 *
 * This file is part of Involve - http://github.com/curlymorphic/involve
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */

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

	inline float logValue() const
	{
		float x = value();
		float totalLength = log10(getMax() - getMin());
		float m_pixelsPerUnitWidth = 20000 / totalLength;

		return   pow( 10, ( x + ( (getMax() - getMin()) ) ) / ( m_pixelsPerUnitWidth  ) );
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

	inline const QString getName() const
	{
		return m_name;
	}

signals:
	void dataChanged( Model *model );

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
