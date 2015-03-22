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


#ifndef MENUDIALOG_H
#define MENUDIALOG_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include "ModuleManager.h"

class MenuDialog : public QDialog
{
public:
	explicit MenuDialog( ModuleManager *moduleManager = 0, QWidget *parent = 0);
	~MenuDialog();

	void loadImages();
protected:
	virtual void resizeEvent( QResizeEvent *event);

private:
	ModuleManager *m_moduleManager;
	QPixmap *m_backgroundImage;
	QPixmap *m_scaledBackgroundImage;
	QPixmap *m_logoImage;
	QPixmap *m_scaledLogoImage;


};

#endif // MENUDIALOG_H
