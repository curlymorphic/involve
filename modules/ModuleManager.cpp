#include "ModuleManager.h"
#include "Demo1/Demo1AudioModule.h"
#include "Demo1/Demo1ModuleControls.h"
#include "Demo1/Demo1ModuleView.h"
#include "Demo2/Demo2AudioModule.h"
#include "Demo2/Demo2ModuleControls.h"
#include "Demo2/Demo2ModuleView.h"

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
	m_modules->count();
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

