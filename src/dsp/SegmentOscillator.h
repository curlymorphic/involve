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

#ifndef SEGMENTOSCILLATOR_H
#define SEGMENTOSCILLATOR_H

#include "WTOscillator.h"


class SegmentOscillator : public WTOscillator
{
public:
	SegmentOscillator( int sampleRate = 44100 );
	virtual ~SegmentOscillator();

	///
	/// \brief maxSegmentCount
	/// maximum nuber of segemts in a single cycle
	static const int maxSegmentCount = 8;

	///
	/// \brief segmentCount
	/// \return
	/// The number of segments in a cycle
	int segmentCount();

	///
	/// \brief setSegmentCount
	/// \param count
	///
	void setSegmentCount( int count );

	///
	/// \brief setSegment
	/// \param index
	/// \param shape
	///
	void setSegment( int index, WTWaveShape shape );

	///
	/// \brief setAllSegments
	/// \param shape
	///
	void setAllSegments( WTWaveShape shape );

	/// \brief monoTick Process the next cycle
	/// used as the base function of oscilator output
	/// must only be called once per sample
	/// \return
	///
	sample_t monoTick();

	virtual void restart()
	{
		WTOscillator::restart();
		m_currentSegment = 0;
		m_segmentSampleIndex = 0;
		setShape( m_segmentShapes[ 0 ] );
	}

protected:

	int m_segmentCount;
	WTWaveShape *m_segmentShapes;
	int m_currentSegment;
	float m_samplesPerSegment;
	float m_segmentSampleIndex;


};

#endif // SEGMENTOSCILLATOR_H
