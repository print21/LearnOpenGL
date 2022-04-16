

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(LearnOpenGL)

find_package(Qt5 COMPONENTS Core)

# Enable automoc, autouic and auto rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

if(Qt5Core_FOUND)
  set(QT5_FOUND TRUE)
  set(QT5_BIN_DIR ${_qt5_install_prefix}/../../bin)
endif(Qt5Core_FOUND)

find_package(GLEW)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_DEBUG_POSTFIX "_d")

add_subdirectory(src)

