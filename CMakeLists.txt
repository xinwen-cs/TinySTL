cmake_minimum_required(VERSION 3.24)
project(TinySTL)

set(CMAKE_CXX_STANDARD 17)

add_executable(TinySTL main.cpp src/vector.h src/allocator.h test/vector_test.h src/construct.h src/algobase.h src/unitialized.h src/util.h src/numeric.h src/algorithm.h src/iterator.h src/type_traits.h src/functional.h src/algo.h test/functional_test.h test/algorithm_test.h test/test.h test/test.cpp)
