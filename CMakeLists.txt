cmake_minimum_required(VERSION 3.10)
project(LevelBuilderAI)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES src/*.cpp)

add_library(LevelBuilderAI SHARED ${SOURCES})
