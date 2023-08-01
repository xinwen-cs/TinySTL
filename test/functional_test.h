//
// Created by henrywen on 2023/8/1.
//

#ifndef TINYSTL_FUNCTIONAL_TEST_H
#define TINYSTL_FUNCTIONAL_TEST_H

#include <iostream>

#include "../src/functional.h"

namespace tinystl::test::functional {
    void functional_test() {
        std::cout << tinystl::identity<int>()(5) << std::endl;
    }

}

#endif //TINYSTL_FUNCTIONAL_TEST_H
