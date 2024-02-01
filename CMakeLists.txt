cmake_minimum_required(VERSION 3.23)

project(testQT VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/alexander/QT/6.6.1/macos")

find_package(Qt6 REQUIRED COMPONENTS
             Core
             Gui
             Widgets
             )
qt_standard_project_setup()

qt_add_executable(testQT
        main.cpp
        )

target_link_libraries(testQT PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt::Widgets)

