cmake_minimum_required(VERSION 3.31.3)
project(Zahleraten)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE 
    src/main.cpp)

add_executable(Zahleraten ${SOURCE})