
cmake_minimum_required(VERSION 3.5)

project(Simple)

set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -O3 ")

include_directories(/usr/include/python2.7/ ../intcrypt/src)
link_directories(../intcrypt/lib)
link_libraries(-lboost_python -lintcrypt)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB src "src/*.cpp")
#set(src xxx.cpp)

add_library(simple SHARED ${src})
set_target_properties(simple PROPERTIES PREFIX "")
