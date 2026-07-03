file(GLOB_RECURSE CORE_SOURCES src/*.cpp)
file(GLOB_RECURSE CORE_HEADERS include/*.hpp)

add_library(core ${CORE_SOURCES})

target_include_directories(core
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(core PRIVATE -Wall -Wextra -Wpedantic -g)
else()
    target_compile_options(core PRIVATE -O2)
endif()