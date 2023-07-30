//
// Created by henrywen on 2023/7/25.
//

#ifndef TINYSTL_CONSTRUCT_H
#define TINYSTL_CONSTRUCT_H

namespace tinystl {

template <typename T>
void construct(T* ptr) {
    ::new ((void*)ptr) T();
}

template <typename T1, typename T2>
void construct(T1* ptr, const T2& value) {
    ::new ((void*)ptr) T2(value);
}

template <typename T>
void destroy(T* ptr) {
    destroy_one(ptr, std::is_trivially_destructible_v<T>);
}

template <typename T>
void destroy_one(T* ptr, std::true_type) {}

template <typename T>
void destroy_one(T* ptr, std::false_type) {
    if (ptr != nullptr) {
        ptr->~T();
    }
}

template <class ForwardIter>
void destroy(ForwardIter , ForwardIter , std::true_type) {}

template <class ForwardIter>
void destroy(ForwardIter first, ForwardIter last, std::false_type)
{
    for (; first != last; ++first)
        destroy(&*first);
}

template <typename ForwardIter>
void destroy(ForwardIter first, ForwardIter last) {
    destroy(first, last, std::true_type{});
}

}

#endif //TINYSTL_CONSTRUCT_H
