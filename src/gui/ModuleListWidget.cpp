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


#include "ModuleListWidget.h"
#include <QVBoxLayout>
#include <QLabel>



ModuleListWidget::ModuleListWidget(ModuleData *moduleData, QWidget *parent) :
	QWidget( parent ),
	m_moduleData( moduleData )
{
	QVBoxLayout *vLayout = new QVBoxLayout;
	QLabel *name = new QLabel( m_moduleData->getName() );
	QLabel *description = new QLabel( m_moduleData->getDescription() );
	vLayout->addWidget( name );
	vLayout->addWidget( description );
	setLayout( vLayout );
	setAttribute( Qt::WA_AcceptTouchEvents, true);
}

ModuleListWidget::~ModuleListWidget()
{

}

bool ModuleListWidget::event(QEvent *event)
{
	if( event->type() == QEvent::TouchBegin )
	{
		emit clicked( m_moduleData );
	}
}

