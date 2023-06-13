##
# Project: Mini-is
# File: CMakeLists.txt
# Author:  Stan Rokita <stan@stansa.dev>
# Date: 2023-06-13
# Copyright: Unlicensed
##

cmake_minimum_required(VERSION 3.15)
project(MiniIS C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES "src/*.c")
add_library(mini-is ${SOURCES})
target_include_directories(mini-is PRIVATE inc)
target_include_directories(mini-is PUBLIC pub_inc)

file(GLOB TEST_SOURCES "test/src/*.cc")
add_executable(mini-is-test ${TEST_SOURCES})
target_link_libraries(mini-is-test PRIVATE mini-is)
# Test unit tests need to access internal headers
target_include_directories(mini-is-test PRIVATE inc)

file(GLOB INT_TEST_SOURCES "integration_test/src/*.cc")
add_executable(mini-is-int-test ${INT_TEST_SOURCES})
target_link_libraries(mini-is-int-test PRIVATE mini-is)
target_link_libraries(mini-is-int-test PRIVATE GTest::gtest)

find_package(GTest REQUIRED)

target_link_libraries(mini-is-test PRIVATE GTest::gtest)

add_custom_target(run-test
        COMMAND mini-is-test
        DEPENDS mini-is-test
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

add_custom_target(run-int-test
        COMMAND mini-is-int-test
        DEPENDS mini-is-int-test
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
