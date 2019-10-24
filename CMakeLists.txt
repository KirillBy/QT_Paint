cmake_minimum_required(VERSION 3.5)

project(QT_PAINT LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(QT_PAINT
  main.cpp
  paint.cpp
  paint.h
  paint.ui
  paintscene.cpp
  paintscene.h
  resources.qrc
)

target_link_libraries(QT_PAINT PRIVATE Qt5::Widgets)
