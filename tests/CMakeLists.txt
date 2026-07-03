find_package(GTest QUIET)

if(GTest_FOUND)
    file(GLOB TEST_SOURCES *.cpp)

    add_executable(run_tests ${TEST_SOURCES})

    target_link_libraries(run_tests
        PRIVATE
            GTest::GTest
            GTest::Main
            core
            math
            io
            memory
    )

    include(GoogleTest)
    gtest_discover_tests(run_tests)
else()
    message(WARNING "GTest not found, skipping tests")
endif()