cmake_minimum_required(VERSION 3.10.0)
project(Gauss VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Gauss main.cpp)

target_include_directories(Gauss PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

