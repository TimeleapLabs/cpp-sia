
cmake_minimum_required(VERSION 3.14)
project(sia LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(sia STATIC
  src/sia.cpp
  src/uint.cpp
  src/int.cpp
  src/bool.cpp
  src/bigint.cpp
  src/bytearray.cpp
  src/string.cpp
  src/array.cpp
)

target_include_directories(sia PUBLIC include)
