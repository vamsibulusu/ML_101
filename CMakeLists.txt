cmake_minimum_required(VERSION 3.11.2)
project(gradient_descent)
set(CMAKE_BUILD_TYPE Release)
 
include_directories(include)
file(GLOB SOURCES "/*.cpp")
add_library(testStudent SHARED ${SOURCES})
#use sudo make install to install gradient descent
