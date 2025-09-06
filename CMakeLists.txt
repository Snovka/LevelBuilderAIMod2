include_directories(${GEODE_DIR}/include)

file(GLOB SOURCES src/*.cpp src/*.hpp)

add_library(LevelBuilderAI SHARED ${SOURCES})
