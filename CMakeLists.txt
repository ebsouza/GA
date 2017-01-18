cmake_minimum_required(VERSION 2.8.9)
project(GA_framework)

set( CMAKE_CXX_FLAGS "-pg -g -fopenmp -std=c++11" )

file(GLOB GA "GA/*.cpp")  
file(GLOB UTIL "util/*.cpp") 
file(GLOB SOURCES "*.cpp") 

add_executable(GAlgorithm ${SOURCES} ${GA} ${UTIL})






