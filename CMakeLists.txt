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

# === Testing ===
include(FetchContent)
include(CTest) # Enables testing infrastructure

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)

FetchContent_MakeAvailable(Catch2)

enable_testing()

# Add test executable
add_executable(sia_tests
  tests/test_uint.cpp
  tests/test_int.cpp
  tests/test_bool.cpp
  tests/test_bigint.cpp
  tests/test_bytearray.cpp
  tests/test_string.cpp
  tests/test_array.cpp
)


target_link_libraries(sia_tests PRIVATE sia Catch2::Catch2WithMain)

target_include_directories(sia_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_test(NAME cpp_sia_tests COMMAND sia_tests)
