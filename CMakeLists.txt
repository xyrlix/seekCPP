cmake_minimum_required(VERSION 3.16)
project(seekCPP VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)

option(BUILD_TESTS "Build tests" ON)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_subdirectory(modules/core)
add_subdirectory(modules/math)
add_subdirectory(modules/io)
add_subdirectory(modules/memory)

add_executable(seekCPP src/main.cpp)

target_link_libraries(seekCPP
    PRIVATE
        core
        math
        io
        memory
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(seekCPP PRIVATE -Wall -Wextra -Wpedantic -g)
else()
    target_compile_options(seekCPP PRIVATE -O2)
endif()

install(TARGETS seekCPP
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()