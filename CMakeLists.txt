cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(CPlayground VERSION 0.0.1)

add_library(dynamic_array_stack dynamic_array_stack.h dynamic_array_stack.c)
add_library(evaluation evaluation.h evaluation.c)
target_link_libraries(evaluation dynamic_array_stack)

enable_testing()

set(TESTING_TARGETS dynamic_array_stack evaluation)
foreach(target ${TESTING_TARGETS})
  message("Creating test for ${target}")
  add_executable("${target}_test" "${target}_test.c")
  target_link_libraries("${target}_test" "${target}")
  add_test("${target}_test" "${target}_test")
endforeach()
