cmake_minimum_required(VERSION 3.10)
project(Fjord)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O0")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

set(glm_DIR usr/lib/cmake/glm) # if necessary
find_package(glm REQUIRED)

#--------------------------------------------------------------------------
file(GLOB Fjord_src "lib/dat/*.cpp" "lib/*.cpp" "lib/node/*.cpp")
file(GLOB example_src "example/*.cpp")

add_library(Fjord STATIC ${Fjord_src})

include_directories(${PROJECT_SOURCE_DIR}/lib)

#--------------------------------------------------------------------------

add_executable(example ${example_src})
target_link_libraries(example Fjord SDL3 SDL3_ttf yaml-cpp box2d GL GLEW glm::glm)
find_program(LSB_RELEASE_CMD lsb_release)