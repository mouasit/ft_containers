
#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template <class>
    struct is_integral{static const bool value = false;};
    template<>
    struct is_integral<int>{static const bool value = true;};
    template<>
    struct is_integral<char>{static const bool value = true;};
    template<>
    struct is_integral<bool>{static const bool value = true;};
    template<>
    struct is_integral<char16_t>{static const bool value = true;};
    template<>
    struct is_integral<char32_t>{static const bool value = true;};
    template<>
    struct is_integral<wchar_t>{static const bool value = true;};
    template<>
    struct is_integral<signed char>{static const bool value = true;};
    template<>
    struct is_integral<long long int>{static const bool value = true;};
    template<>
    struct is_integral<unsigned char>{static const bool value = true;};
    template<>
    struct is_integral<unsigned long>{static const bool value = true;};
    template<>
    struct is_integral<unsigned int>{static const bool value = true;};
    template <>
    struct is_integral<short>{ static const int value = true; };
    template <>
    struct is_integral<float>{ static const int value = true; };
    template <>
    struct is_integral<unsigned long long>{ static const int value = true; };
    template <>
    struct is_integral<long>{ static const int value = true; };
    template <>
    struct is_integral<unsigned short>{ static const int value = true; };
}

#endif
