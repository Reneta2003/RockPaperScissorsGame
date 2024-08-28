cmake_minimum_required(VERSION 3.29)
project(RockPaperScissors)

set(CMAKE_CXX_STANDARD 23)

add_executable(RockPaperScissors main.cpp)

enable_testing()

add_subdirectory(Google_tests/lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run Google_tests/GameTests.cpp
        Google_tests/GameTests.cpp
        Google_tests/main.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)