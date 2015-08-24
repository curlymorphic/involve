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

#include "SegmentOscillator.h"
#include "Interpolation.h"
#include "AudioMath.h"

SegmentOscillator::SegmentOscillator( int sampleRate ) :
	WTOscillator( sampleRate ),
	m_segmentShapes( 0 ),
	m_currentSegment( 0 ),
	m_segmentSampleIndex( 0 )
{
	m_segmentShapes = new WTWaveShape[ maxSegmentCount ];
	setSegmentCount( 4 );
	setAllSegments( WT_SAW );
}

SegmentOscillator::~SegmentOscillator()
{
	if( m_segmentShapes )
	{
		delete[] m_segmentShapes;
		m_segmentShapes = 0;
	}
}

int SegmentOscillator::segmentCount()
{
	return m_segmentCount;
}

void SegmentOscillator::setSegmentCount(int count)
{
	m_segmentCount = bound ( 1, count, maxSegmentCount );
	m_samplesPerSegment = TABLE_LEN / m_segmentCount;
}

void SegmentOscillator::setSegment(int index, WTWaveShape shape )
{
	index = bound( 0, index, maxSegmentCount - 1 );
	m_segmentShapes[ index ] = shape;
}

void SegmentOscillator::setAllSegments( WTWaveShape shape )
{
	for( int i = 0; i < maxSegmentCount; ++i )
	{
		setSegment( i, shape );
	}
}

sample_t SegmentOscillator::monoTick()
{
	int nextIndex;
	int index;
	float frac;
	m_segmentSampleIndex += m_increment;
	m_index += m_increment;
	if(m_index > TABLE_LEN)
	{
		m_index -= TABLE_LEN;
		m_segmentSampleIndex = m_index;
//		m_currentSegment = ( m_currentSegment + 1) % m_segmentCount;
		m_currentSegment = 0; //( m_currentSegment + 1) % m_segmentCount;
		setShape( m_segmentShapes[ 0 ] );
	}
	if(m_segmentSampleIndex >  m_samplesPerSegment  )
	{
		m_segmentSampleIndex -= m_samplesPerSegment;
		m_currentSegment = ( m_currentSegment + 1) % m_segmentCount;
		setShape( m_segmentShapes[ m_currentSegment ] );
	}
	nextIndex = m_index < TABLE_LEN - 1 ?
				m_index + 1 :
				0;
	index = m_index;
	frac = m_index - index;
	return m_currentTable ? linearInterpolate( m_currentTable[ index ] , m_currentTable[ nextIndex ], frac ) : 0;
}

