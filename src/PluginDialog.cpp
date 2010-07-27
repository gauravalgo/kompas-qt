/*
    Copyright © 2007, 2008, 2009, 2010 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Map2X.

    Map2X is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Map2X is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include "PluginDialog.h"

#include <QtGui/QTabWidget>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QPushButton>

#include "PluginManager/PluginManager.h"
#include "MainWindow.h"
#include "PluginModel.h"
#include "PluginDialogTab.h"

namespace Map2X { namespace QtGui {

PluginDialog::PluginDialog(MainWindow* mainWindow, QWidget* parent, Qt::WindowFlags f): QDialog(parent, f) {
    /* Buttons */
    buttons = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);
    restoreDefaultsButton = buttons->addButton(QDialogButtonBox::RestoreDefaults);
    resetButton = buttons->addButton(QDialogButtonBox::Reset);
    connect(buttons, SIGNAL(accepted()), SLOT(accept()));
    connect(buttons, SIGNAL(rejected()), SLOT(reject()));

    /* Tabs */
    tabs = new QTabWidget;
    PluginDialogTab* mapViewTab = new PluginDialogTab(
        mainWindow,
        "mapView",
        mainWindow->mapViewPluginManager(),
        tr("Plugins providing map view area."));
    tabs->addTab(mapViewTab, tr("Map viewers"));
    connect(this, SIGNAL(accepted()), mapViewTab, SLOT(save()));
    connect(restoreDefaultsButton, SIGNAL(clicked(bool)), mapViewTab, SLOT(restoreDefaults()));
    connect(resetButton, SIGNAL(clicked(bool)), mapViewTab, SLOT(reset()));

    PluginDialogTab* tileModelTab = new PluginDialogTab(
        mainWindow,
        "tileModel",
        mainWindow->tileModelPluginManager(),
        tr("Plugins for displaying different kinds of raster maps."));
    tabs->addTab(tileModelTab, tr("Raster maps"));
    connect(this, SIGNAL(accepted()), tileModelTab, SLOT(save()));
    connect(restoreDefaultsButton, SIGNAL(clicked(bool)), tileModelTab, SLOT(restoreDefaults()));
    connect(resetButton, SIGNAL(clicked(bool)), tileModelTab, SLOT(reset()));

    /* Layout */
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(tabs);
    layout->addWidget(buttons);
    setLayout(layout);

    setWindowTitle("Plugins");
    resize(640, 320);
}

}}
