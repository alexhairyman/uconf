project("uconfcom")
cmake_minimum_required(VERSION 2.6)

set(CONFHEADERS "value.hh")
add_custom_target(headers SOURCES ${CONFHEADERS})

add_library(uvallib "value.cc" "valueset.cc")

add_executable(uconfcom "test.cc")
target_link_libraries(uconfcom uvallib)
