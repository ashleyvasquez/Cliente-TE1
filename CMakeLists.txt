cmake_minimum_required(VERSION 3.15)
project(T_ExtraclaseCliente)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
#Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)


find_package(Qt5Widgets REQUIRED)
find_package( Qt5Core REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package(Qt5Sql REQUIRED)

add_executable(T_ExtraclaseCliente main.cpp cliente/Cliente.cpp cliente/Cliente.h Window.cpp Window.h)

target_link_libraries(T_ExtraclaseCliente Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Sql )
qt5_use_modules( T_ExtraclaseCliente Core Widgets Gui )