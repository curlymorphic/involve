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


#include "SynthSelector.h"
#include <QVBoxLayout>
#include <QLabel>
#include "ModuleListWidget.h"

SynthSelector::SynthSelector(ModuleManager *moduleManager, QWidget *parent) :
	QWidget(parent),
	m_moduleManager( moduleManager )
{
	QVBoxLayout *vLayout = new QVBoxLayout;
	QLabel *label = new QLabel( tr( "Select a Synth" ) );
	vLayout->addWidget( label );
	for( int i = 0 ; i < m_moduleManager->moduleCount(); ++i )
	{
		ModuleListWidget *mlw = new ModuleListWidget( m_moduleManager->moduleAt( i ) );
		vLayout->addWidget( mlw );
		connect( mlw, SIGNAL( clicked( ModuleData* ) ),
				 this, SLOT( moduleSelected( ModuleData* ) ) );
	}
	setLayout( vLayout );
	setAutoFillBackground( true );

}

SynthSelector::~SynthSelector()
{

}

void SynthSelector::moduleSelected(ModuleData *moduleData)
{
	m_moduleManager->changeModule( moduleData );
	emit hideDialog();
}

