#include <iostream>

#include "test/vector_test.h"
#include "test/functional_test.h"

using namespace tinystl::test;

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector::vector_test();

    functional::functional_test();
    return 0;
}
