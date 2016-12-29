cmake_minimum_required(VERSION 2.8.9)
project(GA)

set( CMAKE_CXX_FLAGS "-pg -g -fopenmp -std=c++11" )
 
file(GLOB SOURCES "*.cpp")
 
add_executable(GAlgorithm ${SOURCES})
