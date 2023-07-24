//
// Created by henrywen on 2023/7/24.
//

#ifndef TINYSTL_VECTOR_TEST_H
#define TINYSTL_VECTOR_TEST_H

#include <iostream>

#include "../src/vector.h"

namespace tinystl::test::vector {
    void vector_test() {
        std::cout << "[===============================================================]\n";
        std::cout << "[----------------- Run container test : vector -----------------]\n";
        std::cout << "[-------------------------- API test ---------------------------]\n";

        tinystl::vector<int> v1;

        std::cout << v1.data() << std::endl;
    }
}

#endif //TINYSTL_VECTOR_TEST_H
