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

private:

	ModuleData *m_currentModule;
	QList<ModuleData*> *m_modules;

};

#endif // MODULEMANAGER_H
