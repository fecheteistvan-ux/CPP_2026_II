cmake_minimum_required(VERSION 3.10)
project(CegNyilvantarto CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(Main
        Szemely.h
        Szemely.cpp
        Alkalmazott.h
        Alkalmazott.cpp
        Manager.h
        Manager.cpp
        Ceg.h
        Ceg.cpp
        Main.cpp
)