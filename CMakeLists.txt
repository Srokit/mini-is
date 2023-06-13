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

file(GLOB SOURCES "src/*.c")
add_library(mini-is SHARED ${SOURCES})
target_include_directories(mini-is PUBLIC inc)

file(GLOB TEST_SOURCES "test/src/*.cc")
add_executable(mini-is-test ${TEST_SOURCES})
target_link_libraries(mini-is-test PRIVATE mini-is)

find_package(GTest REQUIRED)

target_link_libraries(mini-is-test PRIVATE GTest::gtest)

add_custom_target(run-test
        COMMAND mini-is-test
        DEPENDS mini-is-test
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
