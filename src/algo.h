//
// Created by henrywen on 2023/7/31.
//

#ifndef TINYSTL_ALGO_H
#define TINYSTL_ALGO_H


#include <cstdlib>

namespace tinystl {

// all_of
template <typename InputIter, typename UnaryPredicate>
bool all_of(InputIter first, InputIter last, UnaryPredicate unary_pred) {
    for (; first != last; ++first) {
        if (!unary_pred(*unary_pred)) {
            return false;
        }
    }
    return true;
}

// any_of

// none_of


// count
template <typename InputIter, typename T>
size_t count(InputIter first, InputIter last, const T& value) {
    size_t n = 0;
    for (; first != last; ++first) {
        if (*first == value) {
            ++n;
        }
    }
    return n;
}

// count_if


// find


// find_if

}


#endif //TINYSTL_ALGO_H
