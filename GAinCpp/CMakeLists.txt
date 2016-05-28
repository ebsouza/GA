cmake_minimum_required(VERSION 2.8.9)
project(GA)
 
file(GLOB SOURCES "*.cpp")
 
add_executable(GAlgorithm ${SOURCES})
