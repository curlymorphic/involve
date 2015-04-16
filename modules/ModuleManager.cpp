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


#include "ModuleManager.h"
#include "Demo1/Demo1AudioModule.h"
#include "Demo1/Demo1ModuleControls.h"
#include "Demo1/Demo1ModuleView.h"
#include "Demo2/Demo2AudioModule.h"
#include "Demo2/Demo2ModuleControls.h"
#include "Demo2/Demo2ModuleView.h"
#include "SuperSawer/SuperSawerModuleControls.h"
#include "SuperSawer/SuperSawAudioModule.h"
#include "SuperSawer/SuperSawModuleView.h"


ModuleManager::ModuleManager( int samplerate, QObject *parent) : QObject(parent) ,
  m_currentModule( 0 )
{

	m_modules = new QList<ModuleData*>();
	initModules( samplerate );

}

ModuleManager::~ModuleManager()
{
	for( int i = 0; i < m_modules->count(); ++i ){
		delete moduleAt( i )->getAudioModule();
		delete moduleAt( i )->getModuleView();
		delete moduleAt( i )->getModuleControls();
		delete moduleAt( i );
	}
	delete m_modules;
}

void ModuleManager::initModules( int samplerate )
{
	//TODO init modules

	Demo1ModuleControls *d1mc = new Demo1ModuleControls( );
	Demo1AudioModule *d1am = new Demo1AudioModule( samplerate, d1mc );
	Demo1ModuleView *d1mv = new Demo1ModuleView( d1mc );

	ModuleData *d1md = new ModuleData( "Demo1",
									   tr( "Single Oscillator Subtractive Synth " ),
									   d1am, d1mc, d1mv );
	addModule( d1md );

	Demo2ModuleControls *d2mc = new Demo2ModuleControls();
	Demo2AudioModule *d2am = new Demo2AudioModule( samplerate, d2mc );
	Demo2ModuleView *d2mv = new Demo2ModuleView( d2mc );

	ModuleData *d2md = new ModuleData( "Demo 2",
									   tr( "Single Constant Osc" ),
									   d2am, d2mc, d2mv );
	addModule( d2md );

	SuperSawerModuleControls *ssmc = new SuperSawerModuleControls();
	SuperSawAudioModule *ssam = new SuperSawAudioModule( samplerate, ssmc );
	SuperSawModuleView *ssmv = new SuperSawModuleView( ssmc );

	ModuleData *ssmd = new ModuleData( "Super Sawer",
									   tr( " 5 unison saw + sub" ),
									   ssam, ssmc, ssmv );
	addModule( ssmd );

	changeModule( 0 );
}

void ModuleManager::addModule(ModuleData *moduleData)
{
	m_modules->append( moduleData );
}

ModuleData *ModuleManager::currentModule()
{
	return m_currentModule;
}

ModuleData *ModuleManager::moduleAt(int index)
{
	return m_modules->at( index );
}

int ModuleManager::moduleCount()
{
	return m_modules->count();
}

QList<QString> ModuleManager::moduleNames()
{
	QList<QString> names;
	for(int i = 0; i < m_modules->count(); ++i )
	{
		names.append( m_modules->at( i )->getName() );
	}
	return names;
}

void ModuleManager::changeModule(int index)
{
	if( index >= 0 && index < m_modules->count() )
	{
		m_currentModule = m_modules->at( index );
		emit moduleChanged( m_currentModule );
	}
}

void ModuleManager::changeModule(ModuleData *moduleData)
{
	m_currentModule =moduleData;
	emit moduleChanged( m_currentModule );
}

