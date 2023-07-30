//
// Created by henrywen on 2023/7/24.
//

#ifndef TINYSTL_VECTOR_TEST_H
#define TINYSTL_VECTOR_TEST_H

#include <iostream>

#include "../src/vector.h"

namespace tinystl::test::vector {
    class A {
        int i;
        double d;

    public:
        A() {
            i = 1;
            d = 1.0;
        }
    };
    void vector_test() {
        std::cout << "[===============================================================]\n";
        std::cout << "[----------------- Run container test : vector -----------------]\n";
        std::cout << "[-------------------------- API test ---------------------------]\n";

        tinystl::vector<int> v1;

        std::cout << std::boolalpha << v1.empty() << std::endl;

        std::cout << v1.data() << std::endl;

        tinystl::vector<int> v2(10);

        for (auto it : v2) {
            std::cout << it << std::endl;
        }

        std::cout << v2.size() << std::endl;
        std::cout << std::boolalpha << v2.empty() << std::endl;

        tinystl::vector<int> v3(5, 17);
        for (auto i = 0; i < v3.size(); ++i) {
            std::cout << v3[i] << std::endl;
        }
        for (auto it : v3) {
            std::cout << it << std::endl;
        }

        std::cout << v3.front() << std::endl;
        std::cout << v3.cbegin() << std::endl;
        std::cout << v3.data() << std::endl;
        std::cout << v3.max_size() << std::endl;
        std::cout << v3.capacity() << std::endl;
    }
}

#endif //TINYSTL_VECTOR_TEST_H
