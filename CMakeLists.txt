cmake_minimum_required(VERSION 3.24)
project(TinySTL)

set(CMAKE_CXX_STANDARD 17)

add_executable(TinySTL main.cpp src/vector.h src/allocator.h test/vector_test.h src/construct.h src/algobase.h src/unitialized.h src/util.h)
