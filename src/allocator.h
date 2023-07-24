//
// Created by henrywen on 2023/7/24.
//

#ifndef TINYSTL_ALLOCATOR_H
#define TINYSTL_ALLOCATOR_H

#include <cstddef>

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
    static typename allocator<T>::pointer allocate();
    static typename allocator<T>::pointer allocate(size_type n);
};

template <typename T>
typename allocator<T>::pointer allocator<T>::allocate() {
    return static_cast<pointer>(::operator new(sizeof(T)));
}

template <typename T>
typename allocator<T>::pointer allocator<T>::allocate(size_type n) {
    return static_cast<pointer>(::operator new(n * sizeof(T)));
}

}


#endif //TINYSTL_ALLOCATOR_H
