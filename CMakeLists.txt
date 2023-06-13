##
# Project: Mini-is
# File: CMakeLists.txt
# Author:  Stan Rokita <stan@stansa.dev>
# Date: 2023-06-13
# Copyright: Unlicensed
##

project(MiniIS C)
cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 11)

add_executable(mini-is src/main.c)
