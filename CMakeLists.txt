cmake_minimum_required(VERSION 3.20)
project(c_drills LANGUAGES C CXX)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Тип сборки" FORCE)
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)        # -std=c11, а не -std=gnu11
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)      # -std=c++20, а не -std=gnu++20
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GTest REQUIRED)
enable_testing()
include(GoogleTest)

function(add_drill name)
  cmake_parse_arguments(ARG "" "" "SOURCES;TESTS" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "add_drill(${name}): неизвестные аргументы: ${ARG_UNPARSED_ARGUMENTS}")
  endif()

  add_library(${name} ${ARG_SOURCES})
  target_include_directories(${name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

  add_executable(${name}_tests ${ARG_TESTS})
  target_link_libraries(${name}_tests PRIVATE ${name} GTest::gtest_main)

  foreach(target ${name} ${name}_tests)
    target_compile_options(${target} PRIVATE
      -Wall -Wextra -Werror -Wconversion -Wsign-conversion
      -fsanitize=address,undefined -fno-sanitize-recover=all)
    target_link_options(${target} PRIVATE
      -fsanitize=address,undefined)
  endforeach()

  gtest_discover_tests(${name}_tests)
endfunction()

add_subdirectory(w05d1_popcount)
