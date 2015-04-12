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

#include "AudioDevice.h"
#include <qendian.h>
#include <qmath.h>
#include <QIODevice>


AudioDevice::AudioDevice(const QAudioFormat &format, ModuleManager *mm, AudioDeviceControls * adc,  QObject *parent) :
	QIODevice(parent),
	m_pos(0),
	m_module( mm->currentModule()->getAudioModule() ),
	m_moduleControls( mm->currentModule()->getModuleControls() ),
	m_device(QAudioDeviceInfo::defaultOutputDevice()),
	m_audioDevice(0),
	m_audioOutput(0),
	m_output(0),
	m_audioDeviceControls( adc ),
	m_limiter( adc->m_sampleRate )
{
	m_format = format;

	m_frameBuffer = new sampleFrame[100000]; //to big !!!!
	for (int i = 0; i < 100000 ; ++i)
	{
		m_frameBuffer[i][0] = 0;
		m_frameBuffer[i][1] = 0;
	}

	connect( mm, SIGNAL(moduleChanged(ModuleData*)),
			 this, SLOT(moduleChanged(ModuleData*)) , Qt::QueuedConnection );
}



AudioDevice::~AudioDevice()
{

}



void AudioDevice::start()
{
	open(QIODevice::ReadOnly);
}



void AudioDevice::stop()
{
	m_pos=0;
	close();
}




void AudioDevice::sampleFrameToBuffer(sampleFrame *buf, int frames, QAudioFormat &format)
{
	const int channelBytes = format.sampleSize() / 8;
	const int sampleBytes = format.channelCount() * channelBytes;

	qint64 length = (frames * format.channelCount() * (format.sampleSize() / 8));


	Q_ASSERT(length % sampleBytes == 0);
	Q_UNUSED(sampleBytes); // suppress warning in release builds

	m_buffer.resize(length);
	unsigned char *ptr = reinterpret_cast<unsigned char *>(m_buffer.data());
	int sampleIndex = 0;

	const sampleFrame *x = buf;
	while (length) {
		for (int i=0; i<format.channelCount(); ++i) {
			if (format.sampleSize() == 8 && format.sampleType() == QAudioFormat::UnSignedInt) {
				const quint8 value = static_cast<quint8>((1.0 + x[0][i]) / 2 * 255);
				*reinterpret_cast<quint8*>(ptr) = value;
			} else if (format.sampleSize() == 8 && format.sampleType() == QAudioFormat::SignedInt) {
				const qint8 value = static_cast<qint8>(x[0][i] * 127);
				*reinterpret_cast<quint8*>(ptr) = value;
			} else if (format.sampleSize() == 16 && format.sampleType() == QAudioFormat::UnSignedInt) {
				quint16 value = static_cast<quint16>((1.0 + x[0][i]) / 2 * 65535);
				if (format.byteOrder() == QAudioFormat::LittleEndian)
					qToLittleEndian<quint16>(value, ptr);
				else
					qToBigEndian<quint16>(value, ptr);
			} else if (format.sampleSize() == 16 && format.sampleType() == QAudioFormat::SignedInt) {
				qint16 value = static_cast<qint16>(x[0][i] * 32767);
				if (format.byteOrder() == QAudioFormat::LittleEndian)
					qToLittleEndian<qint16>(value, ptr);
				else
					qToBigEndian<qint16>(value, ptr);
			}

			ptr += channelBytes;
			length -= channelBytes;
		}
		++sampleIndex;
		++x;
	}
}

void AudioDevice::createAudioOutput()
{
	if( m_audioOutput) { delete m_audioOutput; }
	m_audioOutput = 0;
	m_audioOutput = new QAudioOutput(m_device, m_format, this);

	start();
	m_audioOutput->setBufferSize( 512 );
	m_audioOutput->start(this);
	qDebug(" buffer size : %d", m_audioOutput->bufferSize() );
}



qint64 AudioDevice::readData(char *data, qint64 len)
{
	if( len )
	{
		len = len > bytesAvailable() ? bytesAvailable() : len;
		m_module->processAudio( m_frameBuffer, len / 4 );
		for(int i = 0; i < len / 4; i++)
		{
			m_frameBuffer[i][0] *= m_audioDeviceControls->m_gainModel.value();
			m_audioDeviceControls->peaks[0] = qMax( m_audioDeviceControls->peaks[0],
					m_frameBuffer[i][0] );
			m_frameBuffer[i][1] *= m_audioDeviceControls->m_gainModel.value();
			m_audioDeviceControls->peaks[1] = qMax( m_audioDeviceControls->peaks[1],
					m_frameBuffer[i][1] );
		}
		m_limiter.processAudio( m_frameBuffer, len / 4 );
		sampleFrameToBuffer( m_frameBuffer, len, m_format );
		memcpy(data,m_buffer,len);
		m_audioDeviceControls->m_bufferSize = len;
	}
	return len;
}

qint64 AudioDevice::writeData(const char *data, qint64 len)
{
	Q_UNUSED(data);
	Q_UNUSED(len);

	return 0;
}

qint64 AudioDevice::bytesAvailable() const
{
	return bufferSize * 4;
}

void AudioDevice::moduleChanged(ModuleData *md)
{
	m_module = md->getAudioModule();
	m_moduleControls = md->getModuleControls();
}



