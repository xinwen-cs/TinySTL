//
// Created by henrywen on 2023/7/24.
//

#ifndef TINYSTL_VECTOR_H
#define TINYSTL_VECTOR_H

#include "allocator.h"

namespace tinystl {
template <typename T>
class vector {
public:
    typedef tinystl::allocator<T> allocator_type;

    typedef typename allocator_type::value_type value_type;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::size_type size_type;
    typedef typename allocator_type::difference_type difference_type;

    typedef value_type* iterator;
    typedef const value_type* const_iterator;


    vector() noexcept {
        try_init();
    }

    explicit vector(size_type n) {
        fill_init(n, value_type());
    }

    vector(vector&& rhs) noexcept : begin_(rhs.begin_), end_(rhs.end_), cap_(rhs.cap_){
        rhs.begin_ = nullptr;
        rhs.end_ = nullptr;
        rhs.cap_ = nullptr;
    }


private:
    iterator begin_;
    iterator end_;
    iterator cap_;

public:
    iterator begin() noexcept {
        return begin_;
    }

    iterator end() noexcept {
        return end_;
    }

    bool empty() const noexcept {
        return begin_ == end_;
    }

    size_type size() {
        return static_cast<size_type>(end_ - begin_);
    }

    reference operator[](size_type n) {
        assert(n < size());
        return *(begin_ + n);
    }

    pointer data() noexcept {
        return begin_;
    }

private:
    void try_init() noexcept;
    void fill_init(size_type n, const_reference value);
};


template <typename T>
void vector<T>::try_init() noexcept {
    try {
        begin_ = allocator_type::allocate(16);
        end_ = begin_;
        cap_ = begin_ + 16;
    } catch (...) {
        begin_ = nullptr;
        end_ = nullptr;
        cap_ = nullptr;
    }
}

template <typename T>
void vector<T>::fill_init(size_type n, const_reference value) {
//    init_space();
}
}



#endif //TINYSTL_VECTOR_H
