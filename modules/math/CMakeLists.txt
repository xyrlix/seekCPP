file(GLOB_RECURSE MATH_SOURCES src/*.cpp)
file(GLOB_RECURSE MATH_HEADERS include/*.hpp)

add_library(math ${MATH_SOURCES})

target_include_directories(math
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(math PRIVATE -Wall -Wextra -Wpedantic -g)
else()
    target_compile_options(math PRIVATE -O2)
endif()