cmake_minimum_required(VERSION 3.10)
project(Fjord)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

#--------------------------------------------------------------------------

add_library(Fjord STATIC lib/main.cpp)

include_directories(${PROJECT_SOURCE_DIR}/lib)

#--------------------------------------------------------------------------

add_executable(example example/node1.cpp)
target_link_libraries(example Fjord SDL2)