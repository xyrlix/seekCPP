file(GLOB_RECURSE IO_SOURCES src/*.cpp)
file(GLOB_RECURSE IO_HEADERS include/*.hpp)

add_library(io ${IO_SOURCES})

target_include_directories(io
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(io PRIVATE -Wall -Wextra -Wpedantic -g)
else()
    target_compile_options(io PRIVATE -O2)
endif()