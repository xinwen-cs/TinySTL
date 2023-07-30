//
// Created by henrywen on 2023/7/30.
//

#ifndef TINYSTL_UTIL_H
#define TINYSTL_UTIL_H

#include <type_traits>

namespace tinystl {

    /*
     *
     * // move

template <class T>
typename std::remove_reference<T>::type&& move(T&& arg) noexcept
{
  return static_cast<typename std::remove_reference<T>::type&&>(arg);
}
     * */

// move
template <typename T>
std::remove_reference_t<T>&& move(T&& arg) noexcept {
    return static_cast<std::remove_reference_t<T>&&>(arg);
}

template <typename T>
void swap(T& lhs, T& rhs) {
    auto tmp(tinystl::move(lhs));
    lhs = tinystl::move(rhs);
    rhs = tinystl::move(tmp);
}
}

#endif //TINYSTL_UTIL_H
