/*
    SuperCollider Qt IDE
    Copyright (c) 2012 Jakob Leben & Tim Blechmann
    http://www.audiosynth.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*/

#ifndef SCIDE_WIDGETS_MAIN_WINDOW_HPP_INCLUDED
#define SCIDE_WIDGETS_MAIN_WINDOW_HPP_INCLUDED

#include <QMainWindow>
#include <QTabWidget>
#include <QTextDocument>
#include <QTabWidget>
#include <QVector>

#include "post_window.hpp"

namespace ScIDE
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    enum ActionRole {
        DocNew = 0,
        DocOpen,
        DocSave,
        DocSaveAs,
        DocClose,
        Quit,

        ActionCount
    };

    MainWindow();

    QAction *action( ActionRole );

public Q_SLOTS:
    void newDocument();
    void openDocument();
    void saveDocument();
    void saveDocumentAs();
    void closeDocument();

private Q_SLOTS:
    void closeTab(int index);

public:
    PostDock * postDock;

private:
    QVector<QAction*> _actions;

    QList<QTextDocument*> _docs;

    QTabWidget *_docTabs;
};

} // namespace ScIDE

#endif
