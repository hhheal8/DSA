cmake_minimum_required(VERSION 3.0.0)

project(algorithms VERSION 0.1.0 LANGUAGES CXX)

add_executable(
  algorithms 
  main.cpp

  # sources/algorithms.cpp
)

target_include_directories(
  algorithms PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes
  # algorithms PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/utils
)
