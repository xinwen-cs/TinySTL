//
// Created by henrywen on 2023/7/30.
//

#ifndef TINYSTL_FUNCTIONAL_H
#define TINYSTL_FUNCTIONAL_H

#include <cstdlib>

namespace tinystl {

template <typename Arg, typename Result>
struct unarg_function {
    typedef Arg argument_type;
    typedef Result result_type;
};

template <typename Arg1, typename Arg2, typename Result>
struct binary_function {
    typedef Arg1 first_argument;
    typedef Arg2 second_argument;
    typedef Result result;
};

template <typename T>
struct plus : public binary_function<T, T, T> {
    T operator()(const T& x, const T& y) {
        return x + y;
    }
};


template <typename T>
struct minus : public binary_function<T, T, T> {
    T operator()(const T& x, const T& y) {
        return x - y;
    }
};

template <typename T>
struct multiplies : public binary_function<T, T, T> {
    T operator()(const T& x, const T& y) {
        return x * y;
    }
};

template <typename T>
struct divides : public binary_function<T, T, T> {
    T operator()(const T& x, const T& y) {
        return x / y;
    }
};

template <typename T>
struct modulus : public binary_function<T, T, T> {
    T operator()(const T& x, const T& y) const {
        return x % y;
    }
};

template <typename T>
struct negate : public unarg_function<T, T> {
    T operator()(const T& x) const {
        return -x;
    }
};

template <typename T>
struct equal_to : public binary_function<T, T, bool> {
    bool operator()(const T& x, const T& y) const {
        return x == y;
    }
};

template <typename T>
struct not_equal_to : public binary_function<T, T, bool> {
    bool operator()(const T& x, const T& y) const {
        return x != y;
    }
};

template <typename T>
struct greater :public binary_function<T, T, bool>
{
    bool operator()(const T& x, const T& y) const { return x > y; }
};

template <typename T>
struct less :public binary_function<T, T, bool>
{
    bool operator()(const T& x, const T& y) const { return x < y; }
};

template <typename T>
struct identity : public unarg_function<T, bool> {
    const T& operator()(const T& x) const {
        return x;
    }
};


/*****************************************************************************************/
template <typename Key>
struct hash {};

template <typename T>
struct hash<T*> {
    size_t operator()(T* p) const noexcept {
        reinterpret_cast<size_t>(p);
    }
};


#define TINYSTL_TRIVIAL_HASH_FCN(Type)         \
template <> struct hash<Type>                \
{                                            \
  size_t operator()(Type val) const noexcept \
  { return static_cast<size_t>(val); }       \
};

TINYSTL_TRIVIAL_HASH_FCN(bool);
TINYSTL_TRIVIAL_HASH_FCN(char);
TINYSTL_TRIVIAL_HASH_FCN(signed char)
TINYSTL_TRIVIAL_HASH_FCN(unsigned char)
TINYSTL_TRIVIAL_HASH_FCN(wchar_t)
TINYSTL_TRIVIAL_HASH_FCN(char16_t)
TINYSTL_TRIVIAL_HASH_FCN(char32_t)
TINYSTL_TRIVIAL_HASH_FCN(short)
TINYSTL_TRIVIAL_HASH_FCN(unsigned short)
TINYSTL_TRIVIAL_HASH_FCN(int)
TINYSTL_TRIVIAL_HASH_FCN(unsigned int)
TINYSTL_TRIVIAL_HASH_FCN(long)
TINYSTL_TRIVIAL_HASH_FCN(unsigned long)
TINYSTL_TRIVIAL_HASH_FCN(long long)
TINYSTL_TRIVIAL_HASH_FCN(unsigned long long)

#undef TINYSTL_TRIVIAL_HASH_FCN



// 对于浮点数，逐位哈希
inline size_t bitwise_hash(const unsigned char* first, size_t count)
{
#if (_MSC_VER && _WIN64) || ((__GNUC__ || __clang__) &&__SIZEOF_POINTER__ == 8)
    const size_t fnv_offset = 14695981039346656037ull;
    const size_t fnv_prime = 1099511628211ull;
#else
    const size_t fnv_offset = 2166136261u;
  const size_t fnv_prime = 16777619u;
#endif
    size_t result = fnv_offset;
    for (size_t i = 0; i < count; ++i)
    {
        result ^= (size_t)first[i];
        result *= fnv_prime;
    }
    return result;
}

template <>
struct hash<float>
{
    size_t operator()(const float& val)
    {
        return val == 0.0f ? 0 : bitwise_hash((const unsigned char*)&val, sizeof(float));
    }
};

template <>
struct hash<double>
{
    size_t operator()(const double& val)
    {
        return val == 0.0f ? 0 : bitwise_hash((const unsigned char*)&val, sizeof(double));
    }
};

template <>
struct hash<long double>
{
    size_t operator()(const long double& val)
    {
        return val == 0.0f ? 0 : bitwise_hash((const unsigned char*)&val, sizeof(long double));
    }
};
}

#endif //TINYSTL_FUNCTIONAL_H
