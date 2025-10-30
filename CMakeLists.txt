cmake_minimum_required(VERSION 3.10.0)
project(Gauss)

add_executable(Gauss main.cpp)

target_include_directories(Gauss PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(Gauss PROPERTIES LINK_SEARCH_START_STATIC ON)
set_target_properties(Gauss PROPERTIES LINK_SEARCH_END_STATIC ON)
target_link_options(Gauss PRIVATE -static)
