cmake_minimum_required(VERSION 3.2)
project(my_utils)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release)

include_directories(include)

add_executable(example_filewriter examples/example_filewriter.cpp)
target_include_directories(example_filewriter PUBLIC 3rd_party/readerwriterqueue)
target_compile_features(example_filewriter PUBLIC cxx_std_11)