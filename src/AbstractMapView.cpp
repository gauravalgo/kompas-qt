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

#include <QtCore/QMetaType>

#include "AbstractMapView.h"
#include "TileDataThread.h"

using namespace Map2X::Core;

namespace Map2X { namespace QtGui {

AbstractMapView::AbstractMapView(QWidget* parent, Qt::WindowFlags f): QWidget(parent, f), tileModel(0) {
    tileDataThread = new TileDataThread(&tileModel, &tileModelMutex, this);

    qRegisterMetaType<Core::Zoom>("Core::Zoom");
    qRegisterMetaType<Core::TileCoords>("Core::TileCoords");

    connect(this, SIGNAL(getTileData(QString,Core::Zoom,Core::TileCoords)),
            tileDataThread, SLOT(getTileData(QString,Core::Zoom,Core::TileCoords)));
    connect(tileDataThread, SIGNAL(tileData(QString,Core::Zoom,Core::TileCoords,QPixmap)),
            SLOT(tileData(QString,Core::Zoom,Core::TileCoords,QPixmap)));
    connect(tileDataThread, SIGNAL(tileLoading(QString,Core::Zoom,Core::TileCoords)),
            SLOT(tileLoading(QString,Core::Zoom,Core::TileCoords)));
    connect(tileDataThread, SIGNAL(tileNotFound(QString,Core::Zoom,Core::TileCoords)),
            SLOT(tileNotFound(QString,Core::Zoom,Core::TileCoords)));

    tileDataThread->start();
}

void AbstractMapView::setTileModel(AbstractTileModel* model) {
    tileModel = model;
    reload();
}

}}