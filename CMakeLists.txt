cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0076 NEW)
project(librobo VERSION 0.3.2)
enable_language(CXX)
add_library(robo STATIC)
target_compile_features(robo PUBLIC cxx_std_23)
target_include_directories(robo PUBLIC include)
add_subdirectory(src)
