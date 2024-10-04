cmake_minimum_required(VERSION 3.18)
project(seastar-learning)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif(CCACHE_FOUND)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(Seastar_CXX_DIALECT "gnu++20" CACHE STRING "C++ dialect to use with Seastar")

add_subdirectory(seastar)

add_executable(hello-world main.cc)
target_link_libraries(hello-world Seastar::seastar)
