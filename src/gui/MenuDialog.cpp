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


#include "MenuDialog.h"
#include "About.h"
#include "SynthSelector.h"

#include <QTabWidget>
#include <QApplication>
#include <QScreen>
#include <QResizeEvent>
#include <QVBoxLayout>

MenuDialog::MenuDialog(ModuleManager *moduleManager, QWidget *parent) :
	QDialog( parent ),
	m_moduleManager( moduleManager )
{
	SynthSelector *ss = new SynthSelector( m_moduleManager );
	QTabWidget *tabWidget = new QTabWidget( );
	tabWidget->addTab( ss, tr( "Synths" )  );
	tabWidget->addTab( new About, tr( "About" ) );
	resize( QApplication::screens().at( 0 )->size() );
	connect( ss, SIGNAL(hideDialog() ) , this, SLOT( hide() ) );
	QVBoxLayout *vLayout = new QVBoxLayout;
	vLayout->addWidget( tabWidget );
	setLayout( vLayout );


	QPalette* palette = new QPalette();
	m_backgroundImage = new QPixmap (":/new/prefix1/images/Box.png");
	m_scaledBackgroundImage = new QPixmap( *m_backgroundImage );
	palette->setBrush(QPalette::Background, *( new QBrush( *m_scaledBackgroundImage )));
	palette->setBrush(QPalette::Text, *( new QBrush ( * (new QColor(200, 200, 200, 255 ) ) ) )  );
	setPalette(*palette);

}

MenuDialog::~MenuDialog()
{

}

void MenuDialog::resizeEvent(QResizeEvent *event)
{
	*m_scaledBackgroundImage = m_backgroundImage->scaled( event->size() );
	QPalette* palette = new QPalette();
	palette->setBrush(QPalette::Background, *( new QBrush( *m_scaledBackgroundImage )));
	setPalette(*palette);
	layout();
	QWidget::resizeEvent( event );
}



