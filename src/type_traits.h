//
// Created by henrywen on 2023/7/30.
//

#ifndef TINYSTL_TYPE_TRAITS_H
#define TINYSTL_TYPE_TRAITS_H

namespace tinystl {
template <typename T, T v>
struct integral_constant {
    static constexpr T value = v;
};

template <bool b>
using bool_constant = integral_constant<bool, b>;

typedef bool_constant<true> true_type;
typedef bool_constant<false> false_type;

}

#endif //TINYSTL_TYPE_TRAITS_H
