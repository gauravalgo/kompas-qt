#ifndef Kompas_Plugins_UIComponents_MobileUIComponent_h
#define Kompas_Plugins_UIComponents_MobileUIComponent_h
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

/** @file
 * @brief Class Kompas::Plugins::UIComponents::MobileUIComponent
 */

#include "AbstractUIComponent.h"
#include "MobileCentralWidget.h"

namespace Kompas { namespace Plugins { namespace UIComponents {

/** @brief Central widget for mobile UI */
class MobileUIComponent: public QtGui::AbstractUIComponent {
    Q_OBJECT

    public:
        /** @copydoc QtGui::AbstractUIComponent::AbstractUIComponent */
        MobileUIComponent(Corrade::PluginManager::AbstractPluginManager* manager = 0, const std::string& plugin = "");

        inline QWidget* centralWidget() const { return _centralWidget; }

    private:
        MobileCentralWidget* _centralWidget;
};

}}}

#endif
