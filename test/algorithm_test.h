//
// Created by henrywen on 2023/8/1.
//

#include <iostream>

#include "../src/algorithm.h"

#ifndef TINYSTL_ALGORITHM_TEST_H
#define TINYSTL_ALGORITHM_TEST_H

namespace tinystl::test::algorithm_test {
    void algorithm_test() {
        int arr[] = {1, 2, 3, 4, 5};
        std::cout << tinystl::accumulate(arr, arr + 5, 0) << std::endl;

        int arr2[] = {2, 2, 2, 3, 3};
        std::cout << tinystl::count(arr2, arr2 + 5, 2) << std::endl;
    }
}

#endif //TINYSTL_ALGORITHM_TEST_H
