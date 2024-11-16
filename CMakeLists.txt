cmake_minimum_required(VERSION 3.10)
project(Fjord)
if(LSB_RELEASE_CMD)
    # Execute lsb_release -is to get the distribution ID
    execute_process(
        COMMAND ${LSB_RELEASE_CMD} -is
        OUTPUT_VARIABLE DISTRO_ID
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    set(ENV{arch} "Arch")
    set(ENV{ubuntu} "Ubuntu")
endif()
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

#--------------------------------------------------------------------------
file(GLOB Fjord_src "lib/dat/*.cpp" "lib/*.cpp" "lib/node/*.cpp")
file(GLOB example_src "example/*.cpp")

add_library(Fjord STATIC ${Fjord_src})

include_directories(${PROJECT_SOURCE_DIR}/lib)

#--------------------------------------------------------------------------

add_executable(example ${example_src})
target_link_libraries(example Fjord SDL2 jsoncpp)
find_program(LSB_RELEASE_CMD lsb_release)