cmake_minimum_required(VERSION 3.10)

project(NN)

set(SOURCES tests/main.cpp)

include_directories(inc)

add_executable(${PROJECT_NAME} ${SOURCES})
