//
// Created by henrywen on 2023/7/25.
//

#ifndef TINYSTL_ALGOBASE_H
#define TINYSTL_ALGOBASE_H

#include "util.h"

namespace tinystl {
template <typename T>
const T& max(const T& lhs, const T& rhs) {
    return lhs < rhs ? rhs : lhs;
}

template <typename T, typename Compare>
const T& max(const T& lhs, const T& rhs, Compare comp) {
    return comp(lhs, rhs) ? lhs : rhs;
}


template <class T>
const T& min(const T& lhs, const T& rhs)
{
    return rhs < lhs ? rhs : lhs;
}

template <class T, class Compare>
const T& min(const T& lhs, const T& rhs, Compare comp)
{
    return comp(rhs, lhs) ? rhs : lhs;
}

// iter_swap
template <typename Iter1, typename Iter2>
void iter_swap(Iter1 lhs, Iter2 rhs) {
    tinystl::swap(*lhs, *rhs);
}

}

#endif //TINYSTL_ALGOBASE_H
