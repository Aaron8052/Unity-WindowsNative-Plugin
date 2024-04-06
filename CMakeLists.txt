cmake_minimum_required(VERSION 3.27)
project(Unity_WindowsNative_Plugin)

set(CMAKE_CXX_STANDARD 23)

add_library(Unity_WindowsNative_Plugin SHARED library.cpp)
