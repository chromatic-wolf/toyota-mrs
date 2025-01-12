cmake_minimum_required(VERSION 3.16)

project(simpleqml3d VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.7.2 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.7.2)

qt_add_executable(appsimpleqml3d
    main.cpp
)

qt_add_qml_module(appsimpleqml3d
    URI simpleqml3d
    VERSION 1.0
    QML_FILES
    Main.qml
        QML_FILES ThreeDimensionalScene.qml
        QML_FILES RenderableEntity.qml
        QML_FILES IronMan.qml
        RESOURCES qml.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appsimpleqml3d PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appsimpleqml3d
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appsimpleqml3d
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appsimpleqml3d
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
