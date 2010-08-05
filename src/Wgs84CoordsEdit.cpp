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

#include "Wgs84CoordsEdit.h"
#include <QtGui/QRegExpValidator>

using namespace Map2X::Core;

namespace Map2X { namespace QtGui {

void Wgs84CoordsEdit::init() {
    /* Input mask */
    setInputMask(tr(">00°00'00.000\"A 000°00'00.000\"A"));

    /* Default text */
    setText(tr("0°0'0.0\"N 0°0'0.0\"E"));
}

}}