//
// Created by henrywen on 2023/7/25.
//

#ifndef TINYSTL_ALGOBASE_H
#define TINYSTL_ALGOBASE_H

namespace tinystl {
template <typename T>
const T& max(const T& lhs, const T& rhs) {
    return lhs < rhs ? rhs : lhs;
}

template <typename T, typename Compare>
const T& max(const T& lhs, const T& rhs, Compare comp) {
    return comp(lhs, rhs) ? lhs : rhs;
}


}

#endif //TINYSTL_ALGOBASE_H
