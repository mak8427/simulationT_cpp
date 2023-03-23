cmake_minimum_required(VERSION 3.24)
project(simulationT)

set(CMAKE_CXX_STANDARD 17)

add_executable(simulationT main.cpp Product.h Product.cpp Consumer.cpp Consumer.h)
