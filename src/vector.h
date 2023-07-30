//
// Created by henrywen on 2023/7/24.
//

#ifndef TINYSTL_VECTOR_H
#define TINYSTL_VECTOR_H

#include "algobase.h"
#include "allocator.h"
#include "unitialized.h"
#include "util.h"

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

    vector(size_type n, const value_type& value) {
        fill_init(n, value);
    }

    // TODO add iterator trait
//    template <typename Iter>
//    vector(Iter first, Iter last) {
//        range_init(first, last);
//    }
//
//    vector(std::initializer_list<value_type> init_list) {
//        range_init(init_list.begin(), init_list.end());
//    }
//
//    vector(const vector& rhs) {
//        range_init(rhs.begin_, rhs.end_);
//    }

    vector(vector&& rhs) noexcept : begin_(rhs.begin_), end_(rhs.end_), cap_(rhs.cap_){
        rhs.begin_ = nullptr;
        rhs.end_ = nullptr;
        rhs.cap_ = nullptr;
    }

//    vector& operator=(const vector& rhs);
//    vector& operator=(vector&& rhs) noexcept;
//    vector& operator=(std::initializer_list<value_type> ilist)
//    {
//        vector tmp(ilist.begin(), ilist.end());
//        swap(tmp);
//        return *this;
//    }

    ~vector() {
        destroy_and_recover(begin_, end_, cap_ - begin_);
        begin_ = end_ = cap_ = nullptr;
    }


private:
    iterator begin_;
    iterator end_;
    iterator cap_;

public:
    iterator begin() noexcept {
        return begin_;
    }

    const_iterator begin() const noexcept {
        return begin_;
    }

    iterator end() noexcept {
        return end_;
    }

    const_iterator end() const noexcept {
        return end_;
    }

    bool empty() const noexcept {
        return begin_ == end_;
    }

//    reverse_iterator       rbegin()        noexcept
//    { return reverse_iterator(end()); }
//    const_reverse_iterator rbegin()  const noexcept
//    { return const_reverse_iterator(end()); }

//    reverse_iterator       rend()          noexcept
//    { return reverse_iterator(begin()); }
//    const_reverse_iterator rend()    const noexcept
//    { return const_reverse_iterator(begin()); }
//
//    const_iterator         cbegin()  const noexcept
//    { return begin(); }
//    const_iterator         cend()    const noexcept
//    { return end(); }

    const_iterator cbegin() const noexcept {
        return begin();
    }

    const_iterator cend() const noexcept {
        return end();
    }

//    const_reverse_iterator crbegin() const noexcept
//    { return rbegin(); }
//    const_reverse_iterator crend()   const noexcept
//    { return rend(); }

    size_type size() {
        return static_cast<size_type>(end_ - begin_);
    }

    size_type max_size() {
        return static_cast<size_type>(-1) / sizeof(T);
    }

    size_type capacity() {
        return static_cast<size_type>(cap_ - begin_);
    }

    void reverse(size_type n);

    void shrink_to_fit();

    reference operator[](size_type n) {
        assert(n < size());
        return *(begin_ + n);
    }

    const_reference operator[](size_type n) const {
        return *(begin_ + n);
    }

    reference at(size_type n) {
        if (n >= size()) {
            throw std::out_of_range("vector<T>::at() subscript is out of range");
        }
        return (*this)[n];
    }

    const_reference at(size_type n) const {
        if (n >= size()) {
            throw std::out_of_range("vector<T>::at() subscript is out of range");
        }
        return (*this)[n];
    }

    reference front() {
        return *begin_;
    }

    const_reference front() const {
        return *begin_;
    }

    reference back() {
        return *(end_ - 1);
    }

    const_reference back() const {
        return *(end_ - 1);
    }

    pointer data() noexcept {
        return begin_;
    }

    const_pointer data() const noexcept {
        return begin_;
    }


//    // emplace / emplace_back
//
//    template <class... Args>
//    iterator emplace(const_iterator pos, Args&& ...args);
//
//    template <class... Args>
//    void emplace_back(Args&& ...args);
//
//    // push_back / pop_back
//
//    void push_back(const value_type& value);
//    void push_back(value_type&& value)
//    { emplace_back(mystl::move(value)); }
//
//    void pop_back();

    void swap(vector& rhs) noexcept {
        if (this != &rhs) {
            tinystl::swap(begin_, rhs.begin_);
            tinystl::swap(end_, rhs.end_);
            tinystl::swap(cap_, rhs.cap_);
        }
    }

private:
    void try_init() noexcept;
    void init_space(size_type size, size_type cap);
    void fill_init(size_type n, const_reference value);

    void destroy_and_recover(iterator first, iterator last, size_type n);
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
void vector<T>::init_space(size_type size, size_type cap) {
    try {
        begin_ = allocator_type::allocate(cap);
        end_ = begin_ + size;
        cap_ = begin_ + cap;
    } catch (...) {
        begin_ = nullptr;
        end_ = nullptr;
        cap_ = nullptr;
        throw;
    }
}

template <typename T>
void vector<T>::fill_init(size_type n, const_reference value) {
    const size_type init_size = tinystl::max(static_cast<size_type>(16), n);
    init_space(n, init_size);
    tinystl::uninitialized_fill_n(begin_, n, value);
}


template <typename T>
void vector<T>::destroy_and_recover(iterator first, iterator last, size_type n) {
    allocator_type::destroy(first, last);
    allocator_type::deallocate(first, n);
}
}



#endif //TINYSTL_VECTOR_H
