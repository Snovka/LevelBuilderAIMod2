cmake_minimum_required(VERSION 3.10)
project(LevelBuilderAI)

set(CMAKE_CXX_STANDARD 17)

# Вказуємо шлях до Geode SDK
if(NOT DEFINED GEODE_DIR)
    message(FATAL_ERROR "GEODE_DIR not defined! Use -DGEODE_DIR=/path/to/GeodeSDK")
endif()
include_directories(${GEODE_DIR}/include)

file(GLOB SOURCES src/*.cpp src/*.hpp)

add_library(LevelBuilderAI SHARED ${SOURCES})
