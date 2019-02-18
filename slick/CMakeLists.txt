cmake_minimum_required(VERSION 3.13)
project(slick)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)

link_libraries(-lGL)

link_libraries(-lGLU)

link_libraries(-lglut)

add_executable(slick
        include/button.cpp
        include/button.h
        include/camera.cpp
        include/camera.h
        include/structs.cpp
        include/structs.h
        include/text.cpp
        include/text.h
        include/texture.cpp
        include/texture.h
        main.cpp
        main.h)
