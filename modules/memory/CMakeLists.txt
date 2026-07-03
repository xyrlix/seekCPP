file(GLOB_RECURSE MEMORY_SOURCES src/*.cpp)
file(GLOB_RECURSE MEMORY_HEADERS include/*.hpp)

add_library(memory ${MEMORY_SOURCES} ${MEMORY_HEADERS})

target_include_directories(memory
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(memory PRIVATE -Wall -Wextra -Wpedantic -g)
else()
    target_compile_options(memory PRIVATE -O2)
endif()