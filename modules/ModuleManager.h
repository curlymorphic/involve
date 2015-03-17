#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H

#include <QObject>

class ModuleManager : public QObject
{
	Q_OBJECT
public:
	explicit ModuleManager(QObject *parent = 0);
	~ModuleManager();

signals:

public slots:
};

#endif // MODULEMANAGER_H
