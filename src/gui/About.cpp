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


#include "About.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>

About::About( QWidget *parent ) :
	QWidget( parent )
{
	QVBoxLayout *vlayout = new QVBoxLayout;
	QLabel *title = new QLabel( tr( "Involve.\n\n Using Qt framework www.qt.io" ) );
	QLabel *content = new QLabel( tr( "Involve synth \n Copyright (C) <2015>  <Dave French> \n"
									  "This program is free software: you can redistribute it and/or modify\n"
									  "it under the terms of the GNU General Public License as published by\n"
									  "the Free Software Foundation, either version 3 of the License, or\n"
									  "(at your option) any later version.\n"

									  "This program is distributed in the hope that it will be useful,\n"
									  "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
									  "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
									  "GNU General Public License for more details.\n"

									  "You should have received a copy of the GNU General Public License\n"
									  "along with this program.  If not, see <http://www.gnu.org/licenses/>. " ) );
	vlayout->addWidget( title );
	vlayout->addWidget( content);
	setLayout( vlayout );

}

About::~About()
{

}

