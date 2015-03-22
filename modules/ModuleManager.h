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


#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H

#include <QObject>
#include <QList>
#include "AudioModule.h"
#include "ModuleControls.h"
#include "ModuleView.h"

class ModuleData
{
public:

	ModuleData( QString name = "", QString description = "", AudioModule *audioModule = 0, ModuleControls *moduleControls = 0, ModuleView *moduleView = 0 ) :
		m_name( name ),
		m_description( description ),
		m_audioModule( audioModule ),
		m_moduleControls( moduleControls ),
		m_moduleView( moduleView )
	{

	}

	ModuleData( ModuleData &moduleData ) :
		m_name( moduleData.m_name ),
		m_description( moduleData.m_description ),
		m_audioModule( moduleData.m_audioModule ),
		m_moduleControls( moduleData.m_moduleControls ),
		m_moduleView( moduleData.m_moduleView )
	{

	}

	const QString getName()
	{
		return m_name;
	}

	const QString getDescription()
	{
		return m_description;
	}

	AudioModule *getAudioModule()
	{
		return m_audioModule;
	}

	ModuleControls *getModuleControls()
	{
		return m_moduleControls;
	}

	ModuleView *getModuleView()
	{
		return m_moduleView;
	}

private:
	QString m_name;
	QString m_description;
	AudioModule *m_audioModule;
	ModuleControls *m_moduleControls;
	ModuleView *m_moduleView;

};

class ModuleManager : public QObject
{
	Q_OBJECT
public:
	explicit ModuleManager( int samplerate = 44100, QObject *parent = 0);
	~ModuleManager();
	void initModules( int samplerate );
	void addModule(ModuleData *moduleData );
	ModuleData *currentModule();
	ModuleData *moduleAt( int index );
	int moduleCount();
	QList<QString> moduleNames();

signals:
	void moduleChanged( ModuleData* );
public slots:
	void changeModule( int index );
	void changeModule( ModuleData* );

private:

	ModuleData *m_currentModule;
	QList<ModuleData*> *m_modules;

};

#endif // MODULEMANAGER_H
