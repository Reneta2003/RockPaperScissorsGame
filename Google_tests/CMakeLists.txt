cmake_minimum_required(VERSION 3.29)
project(GoogleTests)

set(CMAKE_CXX_STANDARD 23)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run GameTests.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)