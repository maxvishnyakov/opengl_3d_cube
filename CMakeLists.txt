cmake_minimum_required(VERSION 3.5)

project(new_test_opengl VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(new_test_opengl
    main.cpp
    widget.cpp
    widget.h
    vshader.vsh
    fshader.fsh
)

find_package(OpenGL REQUIRED)
find_package(Qt5 COMPONENTS OpenGL Widgets REQUIRED)

target_link_libraries(new_test_opengl PRIVATE OpenGL::GL Qt5::Widgets)




