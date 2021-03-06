/*
    Copyright © 2007, 2008, 2009, 2010, 2011 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Kompas.

    Kompas is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Kompas is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include "DmsDecimalConverterDialog.h"

#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QGridLayout>
#include <QtGui/QDoubleSpinBox>

#include "LatLonCoordsEdit.h"

using namespace Kompas::Core;
using namespace Kompas::QtGui;

namespace Kompas { namespace Plugins { namespace UIComponents {

DmsDecimalConverterDialog::DmsDecimalConverterDialog(QWidget* parent, Qt::WindowFlags f): QDialog(parent, f) {
    /* Initialize labels */
    coords = new LatLonCoordsEdit;
    latitude = new QDoubleSpinBox;
    latitude->setMinimum(-90.0);
    latitude->setMaximum(90);
    latitude->setDecimals(8);
    longitude = new QDoubleSpinBox;
    longitude->setMinimum(-180.0);
    longitude->setMaximum(180.0);
    longitude->setDecimals(8);

    /* Buttons */
    QPushButton* toDecimalButton = new QPushButton(tr("DMS -> Decimal"));
    QPushButton* toDmsButton = new QPushButton(tr("Decimal -> DMS"));
    connect(toDecimalButton, SIGNAL(clicked(bool)), SLOT(toDecimal()));
    connect(toDmsButton, SIGNAL(clicked(bool)), SLOT(toDms()));

    /* Layout */
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(new QLabel(tr("Coordinates:")), 0, 0);
    layout->addWidget(coords, 0, 1);
    layout->addWidget(new QLabel(tr("Latitude:")), 1, 0);
    layout->addWidget(latitude, 1, 1);
    layout->addWidget(new QLabel(tr("Longitude:")), 2, 0);
    layout->addWidget(longitude, 2, 1);
    layout->addWidget(toDecimalButton, 3, 1);
    layout->addWidget(toDmsButton, 4, 1);
    layout->setColumnStretch(1, 1);
    setLayout(layout);

    setMinimumWidth(320);
    setAttribute(Qt::WA_DeleteOnClose);
}

void DmsDecimalConverterDialog::toDecimal() {
    LatLonCoords _coords = coords->coords();
    latitude->setValue(_coords.latitude());
    longitude->setValue(_coords.longitude());
}

void DmsDecimalConverterDialog::toDms() {
    coords->setCoords(LatLonCoords(latitude->value(), longitude->value()));
}

}}}
