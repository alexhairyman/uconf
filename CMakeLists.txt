project("uconfcom")
cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_COMPILER "clang")
set(CONFHEADERS "value.hh" "storage.template.hh")
add_custom_target(headers SOURCES ${CONFHEADERS})

add_library(uvallib "value.cc" "valtree.cc" "valerr.cc")

add_executable(uconfcom "test.cc")
target_link_libraries(uconfcom stdc++ uvallib)
