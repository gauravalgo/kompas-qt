qt4_wrap_cpp(OpenRasterUIComponent_MOC
    OpenRasterUIComponent.h
)
corrade_add_static_plugin(KompasQt_PluginsDesktop OpenRasterUIComponent
    OpenRasterUIComponent.conf
    OpenRasterUIComponent.cpp
    OpenRasterMenuView.cpp
    ${OpenRasterUIComponent_MOC}
)
