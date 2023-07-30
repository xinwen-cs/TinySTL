//
// Created by henrywen on 2023/7/24.
//

#ifndef TINYSTL_ALLOCATOR_H
#define TINYSTL_ALLOCATOR_H

#include <cstddef>

#include "construct.h"

namespace tinystl {

template <typename T>
class allocator {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

public:
    static pointer allocate();
    static pointer allocate(size_type n);

    static void deallocate(pointer ptr);
    static void deallocate(pointer ptr, size_type n);

    static void construct(pointer ptr);
    static void construct(pointer ptr, const_reference value);
    static void construct(pointer ptr, T&& value);

    template <typename... Args>
    static void construct(pointer ptr, Args&& ...args);

    static void destroy(pointer ptr);
    static void destroy(pointer first, pointer last);
};

template <typename T>
typename allocator<T>::pointer allocator<T>::allocate() {
    return static_cast<pointer>(::operator new(sizeof(T)));
}

template <typename T>
typename allocator<T>::pointer allocator<T>::allocate(size_type n) {
    return static_cast<pointer>(::operator new(n * sizeof(T)));
}

template <typename T>
void allocator<T>::deallocate(pointer ptr) {
    if (ptr == nullptr) {
        return;
    }
    ::operator delete(ptr);
}

template <typename T>
void allocator<T>::deallocate(pointer ptr, size_type) {
    if (ptr == nullptr) {
        return;
    }
    ::operator delete(ptr);
}

template <typename T>
void allocator<T>::construct(pointer ptr) {
    tinystl::construct(ptr);
}

template <typename T>
void allocator<T>::destroy(pointer ptr) {
    tinystl::destroy(ptr);
}

template <typename T>
void allocator<T>::destroy(pointer first, pointer last) {
    tinystl::destroy(first, last);
}

}


#endif //TINYSTL_ALLOCATOR_H
