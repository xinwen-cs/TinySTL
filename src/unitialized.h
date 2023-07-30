//
// Created by henrywen on 2023/7/25.
//

#ifndef TINYSTL_UNITIALIZED_H
#define TINYSTL_UNITIALIZED_H

#include <type_traits>
#include <cstring>

namespace tinystl {

template <typename OutputIter, typename Size, typename T>
OutputIter unchecked_fill_n(OutputIter first, Size n, const T& value) {
    for (; n > 0; --n, ++first) {
        *first = value;
    }
    return first;
}

template <typename Tp, typename Size, typename Up>
typename std::enable_if_t<
        std::is_integral_v<Tp> && sizeof(Tp) == 1 &&
        !std::is_same<Tp, bool>::value &&
        std::is_integral_v<Up> && sizeof(Up) == 1,
        Tp*>
unchecked_fill_n(Tp* first, Size n, Up value) {
    if (n > 0) {
        ::memset(first, n, value);
    }
}

template <typename OutputIter, typename Size, typename T>
OutputIter fill_n(OutputIter first, Size n, const T& value) {
    return unchecked_fill_n(first, n, value);
}

template <typename ForwardIter, typename Size, typename T>
ForwardIter unchecked_uninit_fill_n(ForwardIter first, Size n, const T& value, std::true_type) {
    return tinystl::fill_n(first, n, value);
}


//    template <class ForwardIter, class Size, class T>
//    ForwardIter
//    unchecked_uninit_fill_n(ForwardIter first, Size n, const T& value, std::false_type)
//    {
//        auto cur = first;
//        try
//        {
//            for (; n > 0; --n, ++cur)
//            {
//                tinystl::construct(&*cur, value);
//            }
//        }
//        catch (...)
//        {
//            for (; first != cur; ++first)
//                tinystl::destroy(&*first);
//        }
//        return cur;
//    }

//    template <class ForwardIter, class Size, class T>
//    ForwardIter uninitialized_fill_n(ForwardIter first, Size n, const T& value)
//    {
//        return tinystl::unchecked_uninit_fill_n(first, n, value,
//                                              std::is_trivially_copy_assignable<
//                                                      typename iterator_traits<ForwardIter>::
//                                                      value_type>{});
//    }


template <typename ForwardIterator, typename Size, typename T>
ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n, const T& value) {
    return tinystl::unchecked_uninit_fill_n(first, n, value, std::true_type{});
}

}

#endif //TINYSTL_UNITIALIZED_H
