cmake_minimum_required(VERSION 3.10)
project(Fjord)
if(EXISTS "/etc/os-release")
    file(READ "/etc/os-release" os_release_content)
    if(os_release_content MATCHES "ID=ubuntu")
        add_definitions(-DLINUX_UBUNTU)
    elseif(os_release_content MATCHES "ID=arch")
        add_definitions(-DLINUX_ARCH)
    else()
        add_definitions(-DLINUX_DEFAULT)
    endif()
endif()
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

#--------------------------------------------------------------------------
file(GLOB Fjord_src "lib/dat/*.cpp" "lib/*.cpp" "lib/node/*.cpp")
file(GLOB example_src "example/*.cpp")

add_library(Fjord STATIC ${Fjord_src})

include_directories(${PROJECT_SOURCE_DIR}/lib)

#--------------------------------------------------------------------------

add_executable(example ${example_src})
target_link_libraries(example Fjord SDL2 SDL2_ttf jsoncpp yaml-cpp box2d)
find_program(LSB_RELEASE_CMD lsb_release)