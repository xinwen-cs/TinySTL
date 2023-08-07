//
// Created by henrywen on 2023/7/30.
//

#ifndef TINYSTL_NUMERIC_H
#define TINYSTL_NUMERIC_H

namespace tinystl {

template <typename InputIter, typename T>
T accumulate(InputIter first, InputIter last, T init) {
    for (; first != last; ++first) {
        init += *first;
    }
    return init;
}

template <typename InputIter, typename T, class BinaryOp>
T accumulate(InputIter first, InputIter last, T init, BinaryOp op) {
    for (; first != last; ++first) {
        init = op(init, *first);
    }
    return init;
}
}

// TODO adjacent_difference

template <typename InputIter1, typename InputIter2, typename T>
T inner_product(InputIter1 first1, InputIter1 last1, InputIter2 first2, InputIter2 last2, T init) {
    for (; first1 != last1; ++first1, ++first2) {
        init += (*first1 * *first2);
    }
    return init;
}

template <typename InputIter1, typename InputIter2, typename T, typename BinaryOp1, typename BinaryOp2>
T inner_product(InputIter1 first1, InputIter1 last1, InputIter2 first2, InputIter2 last2, T init, BinaryOp1 op1, BinaryOp2 op2) {
    for (; first1 != last1; ++first1, ++first2) {
        init = op1(init, op2(*first1, *first2));
    }
    return init;
}

template <typename ForwardIter, typename T>
void itoa(ForwardIter first, ForwardIter last, T value) {
    while (first != last) {
        *first++ = value++;
    }
}

// TODO partial_sum


#endif //TINYSTL_NUMERIC_H
