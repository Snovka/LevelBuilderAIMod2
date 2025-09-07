cmake_minimum_required(VERSION 3.10)
project(LevelBuilderAIStub)

set(CMAKE_CXX_STANDARD 17)

# Беремо всі .cpp файли у src/
file(GLOB SOURCES src/*.cpp)

# Збираємо бібліотеку .so
add_library(LevelBuilderAI SHARED ${SOURCES})