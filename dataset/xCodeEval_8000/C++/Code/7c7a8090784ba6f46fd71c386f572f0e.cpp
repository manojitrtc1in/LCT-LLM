#line 1 "codeforces-workspace\\contest\\1588\\c\\c.cpp"
#if defined(ONLINE_JUDGE)  

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,avx2")
#endif



#include <bits/extc++.h>

#line 2 "Library\\lib\\alias"



#line 10 "Library\\lib\\alias"



#line 2 "Library\\lib\\limits"

#line 4 "Library\\lib\\limits"

namespace workspace {

template <class _Tp> struct numeric_limits : std::numeric_limits<_Tp> {};

#ifdef __SIZEOF_INT128__

template <> struct numeric_limits<__uint128_t> {
  constexpr static __uint128_t max() { return ~__uint128_t(0); }
  constexpr static __uint128_t min() { return 0; }
};

template <> struct numeric_limits<__int128_t> {
  constexpr static __int128_t max() {
    return numeric_limits<__uint128_t>::max() >> 1;
  }
  constexpr static __int128_t min() { return -max() - 1; }
};

#endif

}  

#line 13 "Library\\lib\\alias"

namespace workspace {

constexpr static char eol = '\n';

using namespace std;

using i32 = int_least32_t;
using u32 = uint_least32_t;
using i64 = int_least64_t;
using u64 = uint_least64_t;

#ifdef __SIZEOF_INT128__
using i128 = __int128_t;
using u128 = __uint128_t;
#else
#warning 128-bit integer is not available.
#endif

template <class _T1, class _T2,
          typename = decltype(std::declval<const _T2 &>() <
                              std::declval<const _T1 &>())>
constexpr
    typename std::conditional<std::is_same<_T1, _T2>::value, const _T1 &,
                              typename std::common_type<_T1, _T2>::type>::type
    min(const _T1 &__x, const _T2 &__y) noexcept {
  return __y < __x ? __y : __x;
}

template <class _T1, class _T2, class _Compare,
          typename = decltype(std::declval<_Compare>()(
              std::declval<const _T2 &>(), std::declval<const _T1 &>()))>
constexpr
    typename std::conditional<std::is_same<_T1, _T2>::value, const _T1 &,
                              typename std::common_type<_T1, _T2>::type>::type
    min(const _T1 &__x, const _T2 &__y, _Compare __comp) noexcept {
  return __comp(__y, __x) ? __y : __x;
}

template <class _Tp, typename = decltype(std::declval<const _Tp &>() <
                                         std::declval<const _Tp &>())>
constexpr _Tp min(std::initializer_list<_Tp> __x) noexcept {
  return *std::min_element(__x.begin(), __x.end());
}

template <class _Tp, class _Compare,
          typename = decltype(std::declval<_Compare>()(
              std::declval<const _Tp &>(), std::declval<const _Tp &>()))>
constexpr _Tp min(std::initializer_list<_Tp> __x, _Compare __comp) noexcept {
  return *std::min_element(__x.begin(), __x.end(), __comp);
}

template <class _T1, class _T2,
          typename = decltype(std::declval<const _T1 &>() <
                              std::declval<const _T2 &>())>

constexpr
    typename std::conditional<std::is_same<_T1, _T2>::value, const _T1 &,
                              typename std::common_type<_T1, _T2>::type>::type
    max(const _T1 &__x, const _T2 &__y) noexcept {
  return __x < __y ? __y : __x;
}

template <class _T1, class _T2, class _Compare,
          typename = decltype(std::declval<_Compare>()(
              std::declval<const _T1 &>(), std::declval<const _T2 &>()))>
constexpr
    typename std::conditional<std::is_same<_T1, _T2>::value, const _T1 &,
                              typename std::common_type<_T1, _T2>::type>::type
    max(const _T1 &__x, const _T2 &__y, _Compare __comp) noexcept {
  return __comp(__x, __y) ? __y : __x;
}

template <class _Tp, typename = decltype(std::declval<const _Tp &>() <
                                         std::declval<const _Tp &>())>
constexpr _Tp max(std::initializer_list<_Tp> __x) noexcept {
  return *std::max_element(__x.begin(), __x.end());
}

template <class _Tp, class _Compare,
          typename = decltype(std::declval<_Compare>()(
              std::declval<const _Tp &>(), std::declval<const _Tp &>()))>
constexpr _Tp max(std::initializer_list<_Tp> __x, _Compare __comp) noexcept {
  return *std::max_element(__x.begin(), __x.end(), __comp);
}

}  

#line 10 "codeforces-workspace\\contest\\1588\\c\\c.cpp"


#line 2 "Library\\src\\sys\\call_once.hpp"



#line 9 "Library\\src\\sys\\call_once.hpp"

namespace workspace {


template <class _F> void call_once(_F &&__f) {
  static std::unordered_set<void *> __called;
  if (__called.count(std::addressof(__f))) return;
  __called.emplace(std::addressof(__f));
  __f();
}

}  

#line 2 "Library\\src\\sys\\clock.hpp"



#line 9 "Library\\src\\sys\\clock.hpp"

namespace workspace {

using namespace std::chrono;

namespace internal {


const auto start_time{system_clock::now()};
}  



decltype(auto) elapsed() noexcept {
  const auto end_time{system_clock::now()};
  return duration_cast<milliseconds>(end_time - internal::start_time).count();
}

}  

#line 2 "Library\\src\\sys\\ejection.hpp"



#line 9 "Library\\src\\sys\\ejection.hpp"

namespace workspace {

namespace internal {

struct ejection {
  bool exit = 0;
};

}  



template <class Tp> void eject(Tp const &arg) {
  std::cout << arg << "\n";
  throw internal::ejection{};
}

void exit() { throw internal::ejection{true}; }

}  

#line 2 "Library\\src\\sys\\iteration.hpp"



#line 9 "Library\\src\\sys\\iteration.hpp"

#line 11 "Library\\src\\sys\\iteration.hpp"

namespace workspace {

void main();

struct {
  

  unsigned current{0};
  unsigned total{1};

  void read() { (std::cin >> total).ignore(); }

  int iterate() {
    static bool once = false;
    assert(!once);
    once = true;
    while (current++ < total) {
      try {
        main();
      } catch (internal::ejection const& status) {
        if (status.exit) break;
      }
    }
    return 0;
  }
} case_info;

}  

#line 1 "Library\\lib\\utils"




#line 2 "Library\\src\\utils\\chval.hpp"



#line 9 "Library\\src\\utils\\chval.hpp"

namespace workspace {


template <class _T1, class _T2,
          typename = decltype(std::declval<_T2>() < std::declval<_T1 &>())>
typename std::enable_if<std::is_assignable<_T1 &, _T2>::value, bool>::type chle(
    _T1 &__x, _T2 &&__y) noexcept {
  return __y < __x ? __x = std::forward<_T2>(__y), true : false;
}


template <class _T1, class _T2,
          typename = decltype(std::declval<_T1 &>() < std::declval<_T2>())>
typename std::enable_if<std::is_assignable<_T1 &, _T2>::value, bool>::type chgr(
    _T1 &__x, _T2 &&__y) noexcept {
  return __x < __y ? __x = std::forward<_T2>(__y), true : false;
}


template <class _T1, class _T2, class _Compare,
          typename = decltype(std::declval<_Compare>()(std::declval<_T2>(),
                                                       std::declval<_T1 &>()))>
typename std::enable_if<std::is_assignable<_T1 &, _T2>::value, bool>::type chle(
    _T1 &__x, _T2 &&__y, _Compare __comp) noexcept {
  return __comp(__y, __x) ? __x = std::forward<_T2>(__y), true : false;
}


template <class _T1, class _T2, class _Compare,
          typename = decltype(std::declval<_Compare>()(std::declval<_T1 &>(),
                                                       std::declval<_T2>()))>
typename std::enable_if<std::is_assignable<_T1 &, _T2>::value, bool>::type chgr(
    _T1 &__x, _T2 &&__y, _Compare __comp) noexcept {
  return __comp(__x, __y) ? __x = std::forward<_T2>(__y), true : false;
}

}  

#line 2 "Library\\src\\utils\\fixed_point.hpp"



#line 9 "Library\\src\\utils\\fixed_point.hpp"

namespace workspace {



template <class _F> class fixed_point {
  struct _wrapper {
    _F &__ref;

    template <class... _Args> decltype(auto) operator()(_Args &&...__args) {
      return __ref(*this, std::forward<_Args>(__args)...);
    }
  };

  _F __fn;

 public:
  

  fixed_point(_F __x) noexcept : __fn(__x) {}

  

  template <class... _Args>
  decltype(auto) operator()(_Args &&...__args) noexcept(noexcept(_wrapper{
      __fn}(std::forward<_Args>(__args)...))) {
    return _wrapper{__fn}(std::forward<_Args>(__args)...);
  }
};

}  

#line 5 "Library\\lib\\utils"


#line 2 "Library\\src\\utils\\io\\istream.hpp"



#include <cxxabi.h>

#line 13 "Library\\src\\utils\\io\\istream.hpp"

#line 2 "Library\\lib\\cxx17"

#line 2 "Library\\lib\\cxx14"

#ifndef _CXX14_CONSTEXPR
#if __cplusplus >= 201402L
#define _CXX14_CONSTEXPR constexpr
#else
#define _CXX14_CONSTEXPR
#endif
#endif
#line 4 "Library\\lib\\cxx17"

#ifndef _CXX17_CONSTEXPR
#if __cplusplus >= 201703L
#define _CXX17_CONSTEXPR constexpr
#else
#define _CXX17_CONSTEXPR
#endif
#endif

#ifndef _CXX17_STATIC_ASSERT
#if __cplusplus >= 201703L
#define _CXX17_STATIC_ASSERT static_assert
#else
#define _CXX17_STATIC_ASSERT assert
#endif
#endif

#line 22 "Library\\lib\\cxx17"

#if __cplusplus < 201703L

namespace std {


template <typename _Container>
constexpr auto size(const _Container& __cont) noexcept(noexcept(__cont.size()))
    -> decltype(__cont.size()) {
  return __cont.size();
}


template <typename _Tp, size_t _Nm>
constexpr size_t size(const _Tp (&)[_Nm]) noexcept {
  return _Nm;
}


template <typename _Container>
[[nodiscard]] constexpr auto empty(const _Container& __cont) noexcept(
    noexcept(__cont.empty())) -> decltype(__cont.empty()) {
  return __cont.empty();
}


template <typename _Tp, size_t _Nm>
[[nodiscard]] constexpr bool empty(const _Tp (&)[_Nm]) noexcept {
  return false;
}


template <typename _Tp>
[[nodiscard]] constexpr bool empty(initializer_list<_Tp> __il) noexcept {
  return __il.size() == 0;
}

struct monostate {};

}  


#else

#include <variant>

#endif
#line 2 "Library\\src\\utils\\sfinae.hpp"



#line 10 "Library\\src\\utils\\sfinae.hpp"
#include <type_traits>

#ifndef __INT128_DEFINED__

#ifdef __SIZEOF_INT128__
#define __INT128_DEFINED__ 1
#else
#define __INT128_DEFINED__ 0
#endif

#endif

namespace std {

#if __INT128_DEFINED__

template <> struct make_signed<__uint128_t> { using type = __int128_t; };
template <> struct make_signed<__int128_t> { using type = __int128_t; };

template <> struct make_unsigned<__uint128_t> { using type = __uint128_t; };
template <> struct make_unsigned<__int128_t> { using type = __uint128_t; };

template <> struct is_signed<__uint128_t> : std::false_type {};
template <> struct is_signed<__int128_t> : std::true_type {};

template <> struct is_unsigned<__uint128_t> : std::true_type {};
template <> struct is_unsigned<__int128_t> : std::false_type {};

#endif

}  


namespace workspace {

template <class Tp, class... Args> struct variadic_front { using type = Tp; };

template <class... Args> struct variadic_back;

template <class Tp> struct variadic_back<Tp> { using type = Tp; };

template <class Tp, class... Args> struct variadic_back<Tp, Args...> {
  using type = typename variadic_back<Args...>::type;
};

template <class type, template <class> class trait>
using enable_if_trait_type = typename std::enable_if<trait<type>::value>::type;


template <class _Tp>
using subscripted_type =
    typename std::decay<decltype(std::declval<_Tp&>()[0])>::type;

template <class Container>
using element_type = typename std::decay<decltype(*std::begin(
    std::declval<Container&>()))>::type;

template <class _Tp, class = void> struct has_begin : std::false_type {};

template <class _Tp>
struct has_begin<
    _Tp, std::__void_t<decltype(std::begin(std::declval<const _Tp&>()))>>
    : std::true_type {
  using type = decltype(std::begin(std::declval<const _Tp&>()));
};

template <class _Tp, class = void> struct has_size : std::false_type {};

template <class _Tp>
struct has_size<_Tp, std::__void_t<decltype(std::size(std::declval<_Tp>()))>>
    : std::true_type {};

template <class _Tp, class = void> struct has_resize : std::false_type {};

template <class _Tp>
struct has_resize<_Tp, std::__void_t<decltype(std::declval<_Tp>().resize(
                           std::declval<size_t>()))>> : std::true_type {};

template <class _Tp, class = void> struct has_mod : std::false_type {};

template <class _Tp>
struct has_mod<_Tp, std::__void_t<decltype(_Tp::mod)>> : std::true_type {};

template <class _Tp, class = void> struct is_integral_ext : std::false_type {};
template <class _Tp>
struct is_integral_ext<
    _Tp, typename std::enable_if<std::is_integral<_Tp>::value>::type>
    : std::true_type {};

#if __INT128_DEFINED__

template <> struct is_integral_ext<__int128_t> : std::true_type {};
template <> struct is_integral_ext<__uint128_t> : std::true_type {};

#endif

#if __cplusplus >= 201402

template <class _Tp>
constexpr static bool is_integral_ext_v = is_integral_ext<_Tp>::value;

#endif

template <typename _Tp, typename = void> struct multiplicable_uint {
  using type = uint_least32_t;
};
template <typename _Tp>
struct multiplicable_uint<
    _Tp,
    typename std::enable_if<(2 < sizeof(_Tp)) &&
                            (!__INT128_DEFINED__ || sizeof(_Tp) <= 4)>::type> {
  using type = uint_least64_t;
};

#if __INT128_DEFINED__

template <typename _Tp>
struct multiplicable_uint<_Tp,
                          typename std::enable_if<(4 < sizeof(_Tp))>::type> {
  using type = __uint128_t;
};

#endif

template <typename _Tp> struct multiplicable_int {
  using type =
      typename std::make_signed<typename multiplicable_uint<_Tp>::type>::type;
};

template <typename _Tp> struct multiplicable {
  using type = std::conditional_t<
      is_integral_ext<_Tp>::value,
      std::conditional_t<std::is_signed<_Tp>::value,
                         typename multiplicable_int<_Tp>::type,
                         typename multiplicable_uint<_Tp>::type>,
      _Tp>;
};

template <class> struct first_arg { using type = void; };

template <class _R, class _Tp, class... _Args>
struct first_arg<_R(_Tp, _Args...)> {
  using type = _Tp;
};

template <class _R, class _Tp, class... _Args>
struct first_arg<_R (*)(_Tp, _Args...)> {
  using type = _Tp;
};

template <class _G, class _R, class _Tp, class... _Args>
struct first_arg<_R (_G::*)(_Tp, _Args...)> {
  using type = _Tp;
};

template <class _G, class _R, class _Tp, class... _Args>
struct first_arg<_R (_G::*)(_Tp, _Args...) const> {
  using type = _Tp;
};

template <class _Tp, class = void> struct parse_compare : first_arg<_Tp> {};

template <class _Tp>
struct parse_compare<_Tp, std::__void_t<decltype(&_Tp::operator())>>
    : first_arg<decltype(&_Tp::operator())> {};

template <class _Container, class = void> struct get_dimension {
  static constexpr size_t value = 0;
};

template <class _Container>
struct get_dimension<_Container,
                     std::enable_if_t<has_begin<_Container>::value>> {
  static constexpr size_t value =
      1 + get_dimension<typename std::iterator_traits<
              typename has_begin<_Container>::type>::value_type>::value;
};

}  

#line 16 "Library\\src\\utils\\io\\istream.hpp"

namespace workspace {

namespace _istream_impl {

template <class _Tp, typename = void> struct helper {
  helper(std::istream &__is, _Tp &__x) {
    if _CXX17_CONSTEXPR (has_begin<_Tp &>::value)
      for (auto &&__e : __x) helper<std::decay_t<decltype(__e)>>(__is, __e);
    else
      static_assert(has_begin<_Tp>::value, "istream unsupported type.");
  }
};

template <class _Tp>
struct helper<_Tp, std::__void_t<decltype(std::declval<std::istream &>() >>
                                          std::declval<_Tp &>())>> {
  helper(std::istream &__is, _Tp &__x) { __is >> __x; }
};

#ifdef __SIZEOF_INT128__

template <> struct helper<__uint128_t, void> {
  helper(std::istream &__is, __uint128_t &__x) {
    std::string __s;
    __is >> __s;
    bool __neg = false;
    if (__s.front() == '-') __neg = true, __s.erase(__s.begin());
    __x = 0;
    for (char __d : __s) {
      __x *= 10;
      __d -= '0';
      if (__neg)
        __x -= __d;
      else
        __x += __d;
    }
  }
};

template <> struct helper<__int128_t, void> {
  helper(std::istream &__is, __int128_t &__x) {
    std::string __s;
    __is >> __s;
    bool __neg = false;
    if (__s.front() == '-') __neg = true, __s.erase(__s.begin());
    __x = 0;
    for (char __d : __s) {
      __x *= 10;
      __d -= '0';
      if (__neg)
        __x -= __d;
      else
        __x += __d;
    }
  }
};

#endif  


template <class _T1, class _T2> struct helper<std::pair<_T1, _T2>> {
  helper(std::istream &__is, std::pair<_T1, _T2> &__x) {
    helper<_T1>(__is, __x.first), helper<_T2>(__is, __x.second);
  }
};

template <class... _Tp> struct helper<std::tuple<_Tp...>> {
  helper(std::istream &__is, std::tuple<_Tp...> &__x) { iterate(__is, __x); }

 private:
  template <class _Tuple, size_t _Nm = 0>
  void iterate(std::istream &__is, _Tuple &__x) {
    if _CXX17_CONSTEXPR (_Nm != std::tuple_size<_Tuple>::value) {
      helper<typename std::tuple_element<_Nm, _Tuple>::type>(
          __is, std::get<_Nm>(__x)),
          iterate<_Tuple, _Nm + 1>(__is, __x);
    }
  }
};

}  



class istream : public std::istream {
 public:
  
  template <typename _Tp> istream &operator>>(_Tp &__x) {
    _istream_impl::helper<_Tp>(*this, __x);
    if (std::istream::fail()) {
      static auto once = atexit([] {
        std::cerr << "\n\033[43m\033[30mwarning: failed to read \'"
                  << abi::__cxa_demangle(typeid(_Tp).name(), 0, 0, 0)
                  << "\'.\033[0m\n\n";
      });
      assert(!once);
    }
    return *this;
  }
};

decltype(auto) cin = static_cast<istream &>(std::cin);

}  

#line 2 "Library\\src\\utils\\io\\ostream.hpp"



#line 9 "Library\\src\\utils\\io\\ostream.hpp"

#line 11 "Library\\src\\utils\\io\\ostream.hpp"

namespace workspace {

template <class _Os> struct is_ostream {
  template <typename... _Args>
  static std::true_type __test(std::basic_ostream<_Args...> *);
  static std::false_type __test(void *);
  constexpr static bool value = decltype(__test(std::declval<_Os *>()))::value;
};

template <class _Os>
using ostream_ref =
    typename std::enable_if<is_ostream<_Os>::value, _Os &>::type;


template <class _Os, class _Tp, size_t _Nm>
typename std::enable_if<bool(sizeof(_Tp) > 2), ostream_ref<_Os>>::type
operator<<(_Os &__os, const _Tp (&__a)[_Nm]) {
  if _CXX17_CONSTEXPR (_Nm) {
    __os << *__a;
    for (auto __i = __a + 1, __e = __a + _Nm; __i != __e; ++__i)
      __os << ' ' << *__i;
  }
  return __os;
}


template <class _Os, class _Tp, size_t _Nm>
ostream_ref<_Os> operator<<(_Os &__os, const std::array<_Tp, _Nm> &__a) {
  if _CXX17_CONSTEXPR (_Nm) {
    __os << __a[0];
    for (size_t __i = 1; __i != _Nm; ++__i) __os << ' ' << __a[__i];
  }
  return __os;
}


template <class _Os, class _T1, class _T2>
ostream_ref<_Os> operator<<(_Os &__os, const std::pair<_T1, _T2> &__p) {
  return __os << __p.first << ' ' << __p.second;
}


template <class _Os, class _Tp, size_t _Nm = 0>
typename std::enable_if<bool(std::tuple_size<_Tp>::value + 1),
                        ostream_ref<_Os>>::type
operator<<(_Os &__os, const _Tp &__t) {
  if _CXX17_CONSTEXPR (_Nm != std::tuple_size<_Tp>::value) {
    if _CXX17_CONSTEXPR (_Nm) __os << ' ';
    __os << std::get<_Nm>(__t);
    operator<<<_Os, _Tp, _Nm + 1>(__os, __t);
  }
  return __os;
}

template <class _Os, class _Container,
          typename = decltype(std::begin(std::declval<_Container>()))>
typename std::enable_if<
    !std::is_convertible<std::decay_t<_Container>, std::string>::value &&
        !std::is_convertible<std::decay_t<_Container>, char *>::value,
    ostream_ref<_Os>>::type
operator<<(_Os &__os, const _Container &__cont) {
  bool __h = true;
  for (auto &&__e : __cont) __h ? __h = 0 : (__os << ' ', 0), __os << __e;
  return __os;
}

#ifdef __SIZEOF_INT128__


template <class _Os> ostream_ref<_Os> operator<<(_Os &__os, __int128_t __x) {
  if (!__x) return __os << '0';
  if (__x < 0) __os << '-';
  char __s[40], *__p = __s;
  while (__x) {
    auto __d = __x % 10;
    *__p++ = '0' + (__x < 0 ? -__d : __d);
    __x /= 10;
  }
  *__p = 0;
  for (char *__t = __s; __t < --__p; ++__t) *__t ^= *__p ^= *__t ^= *__p;
  return __os << __s;
}


template <class _Os> ostream_ref<_Os> operator<<(_Os &__os, __uint128_t __x) {
  if (!__x) return __os << '0';
  char __s[40], *__p = __s;
  while (__x) *__p++ = '0' + __x % 10, __x /= 10;
  *__p = 0;
  for (char *__t = __s; __t < --__p; ++__t) *__t ^= *__p ^= *__t ^= *__p;
  return __os << __s;
}

#endif

}  

#line 8 "Library\\lib\\utils"


#line 2 "Library\\src\\utils\\grid\\motion.hpp"



#line 9 "Library\\src\\utils\\grid\\motion.hpp"

#line 11 "Library\\src\\utils\\grid\\motion.hpp"

namespace workspace {


template <class _Grid,
          typename = decltype(std::declval<std::decay_t<_Grid>>()[0].resize(0))>
constexpr decltype(auto) transpose(_Grid &&__grid) noexcept {
#if __cplusplus < 201703L
  auto __h = __grid.size(), __w = __grid[0].size();
#else
  auto __h = std::size(__grid), __w = std::size(__grid[0]);
#endif
  std::decay_t<_Grid> __t(__w);
  for (auto &&__r : __t) __r.resize(__h);
  for (size_t __i = 0; __i != __h; ++__i)
    for (size_t __j = 0; __j != __w; ++__j)
      if _CXX17_CONSTEXPR (std::is_rvalue_reference<decltype(__grid)>::value)
        __t[__j][__i] = std::move(__grid[__i][__j]);
      else
        __t[__j][__i] = __grid[__i][__j];
  return __t;
}


template <class _Tp, size_t _Rows, size_t _Cols>
constexpr decltype(auto) transpose(const _Tp (&__grid)[_Rows][_Cols]) noexcept {
  std::array<std::array<_Tp, _Rows>, _Cols> __t;
  for (size_t __i = 0; __i != _Rows; ++__i)
    for (size_t __j = 0; __j != _Cols; ++__j) __t[__j][__i] = __grid[__i][__j];
  return __t;
}


template <class _Tp, size_t _Rows, size_t _Cols>
constexpr decltype(auto) transpose(_Tp(&&__grid)[_Rows][_Cols]) noexcept {
  std::array<std::array<_Tp, _Rows>, _Cols> __t;
  for (size_t __i = 0; __i != _Rows; ++__i)
    for (size_t __j = 0; __j != _Cols; ++__j)
      __t[__j][__i] = std::move(__grid[__i][__j]);
  return __t;
}


template <class _Tp, size_t _Rows, size_t _Cols>
constexpr decltype(auto) transpose(
    const std::array<std::array<_Tp, _Cols>, _Rows> &__grid) noexcept {
  std::array<std::array<_Tp, _Rows>, _Cols> __t;
  for (size_t __i = 0; __i != _Rows; ++__i)
    for (size_t __j = 0; __j != _Cols; ++__j) __t[__j][__i] = __grid[__i][__j];
  return __t;
}


template <class _Tp, size_t _Rows, size_t _Cols>
constexpr decltype(auto) transpose(
    std::array<std::array<_Tp, _Cols>, _Rows> &&__grid) noexcept {
  std::array<std::array<_Tp, _Rows>, _Cols> __t;
  for (size_t __i = 0; __i != _Rows; ++__i)
    for (size_t __j = 0; __j != _Cols; ++__j)
      __t[__j][__i] = std::move(__grid[__i][__j]);
  return __t;
}


template <class _Grid> decltype(auto) roll_ccw(_Grid &&__grid) noexcept {
  if _CXX17_CONSTEXPR (std::is_rvalue_reference<decltype(__grid)>::value) {
    auto __t = transpose(std::move(__grid));
    std::reverse(std::begin(__t), std::end(__t));
    return __t;
  } else {
    auto __t = transpose(__grid);
    std::reverse(std::begin(__t), std::end(__t));
    return __t;
  }
}


template <class _Grid> decltype(auto) roll_cw(_Grid &&__grid) noexcept {
  if _CXX17_CONSTEXPR (std::is_rvalue_reference<decltype(__grid)>::value) {
    std::reverse(std::begin(__grid), std::end(__grid));
    return transpose(std::move(__grid));
  } else {
    auto __t = transpose(__grid);
    for (auto &&__r : __t) std::reverse(std::begin(__r), std::end(__r));
    return __t;
  }
}

}  

#line 2 "Library\\src\\utils\\io\\setup.hpp"



#line 10 "Library\\src\\utils\\io\\setup.hpp"

namespace workspace {


void io_setup(int __n) {
  std::cin.tie(0)->sync_with_stdio(0);
  std::cout << std::fixed << std::setprecision(__n);

#ifdef _buffer_check
  atexit([] {
    char bufc;
    if (std::cin >> bufc)
      std::cerr << "\n\033[43m\033[30mwarning: buffer not empty.\033[0m\n\n";
  });
#endif
}

}  

#line 11 "Library\\lib\\utils"








#line 2 "Library\\src\\utils\\py-like\\range.hpp"



#line 2 "Library\\src\\utils\\py-like\\reversed.hpp"



#line 9 "Library\\src\\utils\\py-like\\reversed.hpp"

#line 11 "Library\\src\\utils\\py-like\\reversed.hpp"

namespace workspace {



template <class _Container> class reversed {
  _Container __c;

 public:
  template <class _Tp>
  constexpr reversed(_Tp &&__x) noexcept : __c(std::forward<_Container>(__x)) {}

  template <class _Tp>
  constexpr reversed(std::initializer_list<_Tp> __x) noexcept : __c(__x) {}

  constexpr decltype(auto) begin() noexcept { return std::rbegin(__c); }
  constexpr decltype(auto) begin() const noexcept { return std::rbegin(__c); }

  constexpr decltype(auto) end() noexcept { return std::rend(__c); }
  constexpr decltype(auto) end() const noexcept { return std::rend(__c); }

  constexpr bool empty() const noexcept { return std::empty(__c); }

  constexpr decltype(auto) size() const noexcept { return std::size(__c); }

  using iterator = decltype(std::rbegin(__c));
  using const_iterator = decltype(std::crbegin(__c));

  using size_type = decltype(std::size(__c));
  using difference_type =
      typename std::iterator_traits<iterator>::difference_type;
  using value_type = typename std::iterator_traits<iterator>::value_type;

  using reference = typename std::iterator_traits<iterator>::reference;
  using const_reference =
      typename std::iterator_traits<const_iterator>::reference;
};

#if __cpp_deduction_guides >= 201606L

template <class _Tp> reversed(_Tp &&) -> reversed<_Tp>;

template <class _Tp>
reversed(std::initializer_list<_Tp>) -> reversed<std::initializer_list<_Tp>>;

#endif

}  

#line 9 "Library\\src\\utils\\py-like\\range.hpp"

namespace workspace {

template <class _Index> class range {
  _Index __first, __last;

 public:
  class iterator {
    _Index __i;

   public:
    using difference_type = std::ptrdiff_t;
    using value_type = _Index;
    using pointer = void;
    using reference = value_type;
    using iterator_category = std::random_access_iterator_tag;

    constexpr iterator() = default;
    constexpr iterator(const _Index &__x) noexcept : __i(__x) {}

    constexpr bool operator==(const iterator &__x) const noexcept {
      return __i == __x.__i;
    }
    constexpr bool operator!=(const iterator &__x) const noexcept {
      return __i != __x.__i;
    }

    constexpr bool operator<(const iterator &__x) const noexcept {
      return __i < __x.__i;
    }
    constexpr bool operator<=(const iterator &__x) const noexcept {
      return __i <= __x.__i;
    }

    constexpr bool operator>(const iterator &__x) const noexcept {
      return __i > __x.__i;
    }
    constexpr bool operator>=(const iterator &__x) const noexcept {
      return __i >= __x.__i;
    }

    constexpr iterator &operator++() noexcept {
      ++__i;
      return *this;
    }
    constexpr iterator operator++(int) noexcept {
      auto __tmp = *this;
      ++__i;
      return __tmp;
    }

    constexpr iterator &operator--() noexcept {
      --__i;
      return *this;
    }
    constexpr iterator operator--(int) noexcept {
      auto __tmp = *this;
      --__i;
      return __tmp;
    }

    constexpr difference_type operator-(const iterator &__x) const noexcept {
      return __i - __x.__i;
    }

    constexpr iterator &operator+=(difference_type __x) noexcept {
      __i += __x;
      return *this;
    }
    constexpr iterator operator+(difference_type __x) const noexcept {
      return iterator(*this) += __x;
    }

    constexpr iterator &operator-=(difference_type __x) noexcept {
      __i -= __x;
      return *this;
    }
    constexpr iterator operator-(difference_type __x) const noexcept {
      return iterator(*this) -= __x;
    }

    constexpr reference operator*() const noexcept { return __i; }
  };

  using value_type = _Index;
  using reference = value_type;

  using difference_type = std::ptrdiff_t;
  using size_type = std::size_t;

  using const_iterator = iterator;

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = reverse_iterator;

  template <class _Tp1, class _Tp2>
  constexpr range(const _Tp1 &__first, const _Tp2 &__last) noexcept
      : __first(__first), __last(__last) {}

  template <class _Tp>
  constexpr range(const _Tp &__last) noexcept : __first(), __last(__last) {}

  constexpr iterator begin() const noexcept { return {__first}; }
  constexpr const_iterator cbegin() const noexcept { return begin(); }

  constexpr iterator end() const noexcept { return {__last}; }
  constexpr const_iterator cend() const noexcept { return end(); }

  constexpr reverse_iterator rbegin() const noexcept {
    return reverse_iterator{end()};
  }
  constexpr const_reverse_iterator crbegin() const noexcept { return rbegin(); }

  constexpr reverse_iterator rend() const noexcept {
    return reverse_iterator{begin()};
  }
  constexpr const_reverse_iterator crend() const noexcept { return rend(); }

  constexpr size_type size() const noexcept { return __last - __first; }
};

#if __cpp_deduction_guides >= 201606L

template <class _Tp1, class _Tp2>
range(const _Tp1 &, const _Tp2 &)
    -> range<std::decay_t<decltype(++std::declval<_Tp1 &>())>>;

template <class _Tp>
range(const _Tp &) -> range<std::decay_t<decltype(++std::declval<_Tp &>())>>;

template <class... _Args>
constexpr decltype(auto) rrange(_Args &&...__args) noexcept {
  return reversed(range(std::forward<_Args>(__args)...));
}

#endif

}  

#line 16 "Library\\lib\\utils"




#line 2 "Library\\src\\utils\\rand\\rng.hpp"



#line 9 "Library\\src\\utils\\rand\\rng.hpp"

namespace workspace {

template <typename _Arithmetic>
using uniform_distribution = typename std::conditional<
    std::is_integral<_Arithmetic>::value,
    std::uniform_int_distribution<_Arithmetic>,
    std::uniform_real_distribution<_Arithmetic>>::type;

template <typename _Arithmetic, class _Engine = std::mt19937>
class random_number_generator : uniform_distribution<_Arithmetic> {
  using base = uniform_distribution<_Arithmetic>;

  _Engine __engine;

 public:
  random_number_generator(_Arithmetic __min, _Arithmetic __max)
      : base(__min, __max), __engine(std::random_device{}()) {}

  random_number_generator(_Arithmetic __max = 1)
      : random_number_generator(0, __max) {}

  random_number_generator(typename base::param_type const& __param)
      : base(__param), __engine(std::random_device{}()) {}

  decltype(auto) operator()() noexcept { return base::operator()(__engine); }
};

}  

#line 2 "Library\\src\\utils\\rand\\shuffle.hpp"



#line 10 "Library\\src\\utils\\rand\\shuffle.hpp"

namespace workspace {

template <class _RAIter, class _Engine = std::mt19937>
void shuffle(_RAIter __first, _RAIter __last) {
  static _Engine __engine(std::random_device{}());
  std::shuffle(__first, __last, __engine);
}

}  

#line 2 "Library\\src\\utils\\round_div.hpp"



#line 9 "Library\\src\\utils\\round_div.hpp"

#line 11 "Library\\src\\utils\\round_div.hpp"

namespace workspace {


template <typename T1, typename T2>
constexpr typename std::enable_if<(is_integral_ext<T1>::value &&
                                   is_integral_ext<T2>::value),
                                  typename std::common_type<T1, T2>::type>::type
floor_div(T1 x, T2 y) {
  assert(y != 0);
  if (y < 0) x = -x, y = -y;
  return x < 0 ? (x - y + 1) / y : x / y;
}


template <typename T1, typename T2>
constexpr typename std::enable_if<(is_integral_ext<T1>::value &&
                                   is_integral_ext<T2>::value),
                                  typename std::common_type<T1, T2>::type>::type
ceil_div(T1 x, T2 y) {
  assert(y != 0);
  if (y < 0) x = -x, y = -y;
  return x < 0 ? x / y : (x + y - 1) / y;
}

}  

#line 21 "Library\\lib\\utils"




#line 2 "Library\\src\\utils\\io\\input.hpp"



#line 10 "Library\\src\\utils\\io\\input.hpp"

namespace workspace {

namespace _input_impl {

template <class _Tp, bool _Is_class = false> class input {
  _Tp __value;

  template <class... _Args> struct is_convertible : std::false_type {};
  template <class _Arg>
  struct is_convertible<_Arg> : std::is_convertible<_Arg, _Tp> {};

 public:
  operator _Tp &() noexcept { return __value; }
  operator const _Tp &() const noexcept { return __value; }

  template <class... _Args>
  input(_Args &&...__args) noexcept : __value(std::forward<_Args>(__args)...) {
    if _CXX17_CONSTEXPR (not is_convertible<_Args...>::value) cin >> __value;
  }
};

template <class _Tp> class input<_Tp, true> : public _Tp {
  template <class... _Args> struct is_convertible : std::false_type {};
  template <class _Arg>
  struct is_convertible<_Arg> : std::is_convertible<_Arg, _Tp> {};

 public:
  operator _Tp &() noexcept { return *this; }
  operator const _Tp &() const noexcept { return *this; }

  template <class... _Args>
  input(_Args &&...__args) noexcept : _Tp(std::forward<_Args>(__args)...) {
    if _CXX17_CONSTEXPR (not is_convertible<_Args...>::value) cin >> *this;
  }

  template <class _E>
  input(std::initializer_list<_E> __l) noexcept : _Tp(__l) {}
};

}  




template <class _Tp = int_least64_t>
class input : public _input_impl::input<_Tp, std::is_class<_Tp>::value> {
 public:
  using _input_impl::input<_Tp, std::is_class<_Tp>::value>::input;
};



template <class _Tp>
struct is_integral_ext<input<_Tp>> : is_integral_ext<_Tp> {};

}  

#line 2 "Library\\src\\utils\\io\\print.hpp"



#line 9 "Library\\src\\utils\\io\\print.hpp"

namespace workspace {


template <char _Sep = ' ', char _End = '\n', class _Tp, class... _Args>
void print(_Tp &&__x, _Args &&...__args) noexcept {
  if _CXX17_CONSTEXPR (sizeof...(_Args))
    cout << __x << _Sep, print(std::forward<_Args>(__args)...);
  else
    cout << __x << _End;
}

void flush() noexcept { cout << std::flush; }

}  

#line 13 "codeforces-workspace\\contest\\1588\\c\\c.cpp"

signed main() {
  using namespace workspace;

  io_setup(15);

  

  case_info.read();  


  

  return case_info.iterate();
}

#line 2 "Library\\src\\data_structure\\segment_tree\\lazy.hpp"



#line 11 "Library\\src\\data_structure\\segment_tree\\lazy.hpp"

#line 2 "Library\\src\\algebra\\system\\monoid.hpp"



#line 9 "Library\\src\\algebra\\system\\monoid.hpp"

namespace workspace {

template <class T, class E = T> struct min_monoid {
  using value_type = T;
  static T min, max;
  T value;
  min_monoid() : value(max) {}
  min_monoid(const T &value) : value(value) {}
  operator T() const { return value; }
  min_monoid operator+(const min_monoid &rhs) const {
    return value < rhs.value ? *this : rhs;
  }
  min_monoid operator*(const E &rhs) const;
};

template <class T, class E>
T min_monoid<T, E>::min = std::numeric_limits<T>::min() / 2;
template <class T, class E>
T min_monoid<T, E>::max = std::numeric_limits<T>::max() / 2;

template <class T, class E = T> struct max_monoid : min_monoid<T, E> {
  using base = min_monoid<T, E>;
  using base::min_monoid;
  max_monoid() : base(base::min) {}
  max_monoid operator+(const max_monoid &rhs) const {
    return !(base::value < rhs.value) ? *this : rhs;
  }
  max_monoid operator*(const E &rhs) const;
};

}  

#line 2 "Library\\src\\algebra\\system\\operation.hpp"



#line 10 "Library\\src\\algebra\\system\\operation.hpp"

#line 12 "Library\\src\\algebra\\system\\operation.hpp"

namespace workspace {



template <class _Tp>
using require_unary_plus = std::enable_if_t<
    std::is_convertible<decltype(+std::declval<const _Tp &>()), _Tp>::value>;

template <class _Tp, class = void> struct has_unary_plus : std::false_type {};

template <class _Tp>
struct has_unary_plus<_Tp, require_unary_plus<_Tp>> : std::true_type {};



template <class _Tp>
using require_unary_minus = std::enable_if_t<
    std::is_convertible<decltype(-std::declval<const _Tp &>()), _Tp>::value>;

template <class _Tp, class = void> struct has_unary_minus : std::false_type {};

template <class _Tp>
struct has_unary_minus<_Tp, require_unary_minus<_Tp>> : std::true_type {};



template <class _Tp1, class _Tp2 = _Tp1>
using require_binary_plus =
    std::enable_if_t<std::is_convertible<decltype(std::declval<const _Tp1 &>() +
                                                  std::declval<const _Tp2 &>()),
                                         _Tp1>::value>;

template <class _Tp1, class _Tp2 = _Tp1, class = void>
struct has_binary_plus : std::false_type {};

template <class _Tp1, class _Tp2>
struct has_binary_plus<_Tp1, _Tp2, require_binary_plus<_Tp1, _Tp2>>
    : std::true_type {};



template <class _Tp1, class _Tp2 = _Tp1>
using require_binary_minus =
    std::__void_t<decltype(std::declval<const _Tp1 &>() -
                           std::declval<const _Tp2 &>())>;

template <class _Tp1, class _Tp2 = _Tp1, class = void>
struct has_binary_minus : std::false_type {};

template <class _Tp1, class _Tp2>
struct has_binary_minus<_Tp1, _Tp2, require_binary_minus<_Tp1, _Tp2>>
    : std::true_type {};



template <class _Tp1, class _Tp2 = _Tp1>
using require_binary_multiplies =
    std::enable_if_t<std::is_convertible<decltype(std::declval<const _Tp1 &>() *
                                                  std::declval<const _Tp2 &>()),
                                         _Tp1>::value>;

template <class _Tp1, class _Tp2 = _Tp1, class = void>
struct has_binary_multiplies : std::false_type {};

template <class _Tp1, class _Tp2>
struct has_binary_multiplies<_Tp1, _Tp2, require_binary_multiplies<_Tp1, _Tp2>>
    : std::true_type {};



template <class _Tp1, class _Tp2 = _Tp1>
using require_binary_divides =
    std::enable_if_t<std::is_convertible<decltype(std::declval<const _Tp1 &>() /
                                                  std::declval<const _Tp2 &>()),
                                         _Tp1>::value>;

template <class _Tp1, class _Tp2 = _Tp1, class = void>
struct has_binary_divides : std::false_type {};

template <class _Tp1, class _Tp2>
struct has_binary_divides<_Tp1, _Tp2, require_binary_divides<_Tp1, _Tp2>>
    : std::true_type {};



template <class _Tp1, class _Tp2 = _Tp1>
using require_binary_modulus =
    std::enable_if_t<std::is_convertible<decltype(std::declval<const _Tp1 &>() %
                                                  std::declval<const _Tp2 &>()),
                                         _Tp1>::value>;

template <class _Tp1, class _Tp2 = _Tp1, class = void>
struct has_binary_modulus : std::false_type {};

template <class _Tp1, class _Tp2>
struct has_binary_modulus<_Tp1, _Tp2, require_binary_modulus<_Tp1, _Tp2>>
    : std::true_type {};

template <class _Tp1, class _Tp2 = _Tp1, class = void, class = void,
          class = void, class = void>
struct has_arithmetic : std::false_type {};

template <class _Tp1, class _Tp2>
struct has_arithmetic<_Tp1, _Tp2, require_binary_plus<_Tp1, _Tp2>,
                      require_binary_minus<_Tp1, _Tp2>,
                      require_binary_multiplies<_Tp1, _Tp2>,
                      require_binary_divides<_Tp1, _Tp2>> : std::true_type {};

template <class _Tp1, class _Tp2 = _Tp1>
using require_arithmetic = std::enable_if_t<has_arithmetic<_Tp1, _Tp2>::value>;



template <class _Tp, class = void> struct is_comparable : std::false_type {};

template <class _Tp>
struct is_comparable<_Tp, std::__void_t<decltype(std::declval<const _Tp &>() <
                                                 std::declval<const _Tp &>())>>
    : std::true_type {};

template <class _Tp, bool _Default = false> struct try_less : std::less<_Tp> {
  constexpr bool operator()(const _Tp &__x, const _Tp &__y) noexcept {
    if _CXX17_CONSTEXPR (is_comparable<_Tp>::value)
      return std::less<_Tp>::operator()(__x, __y);
    else
      return _Default;
  }
};

}  

#line 2 "Library\\src\\data_structure\\segment_tree\\waitings.hpp"

#line 5 "Library\\src\\data_structure\\segment_tree\\waitings.hpp"

namespace workspace {

namespace internal {

struct waitings : std::queue<size_t> {
  waitings(size_t n) : in(n) {}

  bool push(size_t index) {
    

    if (in[index]) return false;
    emplace(index);
    return (in[index] = true);
  }

  size_t pop() {
    

    auto index = front();
    std::queue<size_t>::pop();
    in[index] = false;
    return index;
  }

 private:
  std::vector<int_least8_t> in;
};

}  


}  

#line 16 "Library\\src\\data_structure\\segment_tree\\lazy.hpp"

namespace workspace {

template <class _Monoid, class _End,
          class Monoid_container = std::vector<_Monoid>,
          class Endomorphism_container = std::vector<_End>>
class lazy_segment_tree {
  static_assert(
      std::is_same<_Monoid, typename Monoid_container::value_type>::value);

  static_assert(
      std::is_same<_End, typename Endomorphism_container::value_type>::value);

  static_assert(has_binary_plus<_Monoid>::value,
                "\'_Monoid\' has no proper binary \'operator+\'.");

  static_assert(has_binary_multiplies<_End>::value,
                "\'_End\' has no proper binary \'operator*\'.");

  static_assert(has_binary_multiplies<_Monoid, _End>::value,
                "\'_End\' is not applicable to \'_Monoid\'.");

  size_t size_orig, height, size_ext;
  Monoid_container data;
  Endomorphism_container lazy;
  internal::waitings wait;

  void repair() {
    while (!wait.empty()) {
      const size_t index = wait.pop() >> 1;
      if (index && wait.push(index)) pull(index);
    }
  }

  void apply(size_t node, const _End &endo) {
    data[node] = data[node] * endo;
    if (node < size_ext) lazy[node] = lazy[node] * endo;
  }

  void push(size_t node) {
    apply(node << 1, lazy[node]);
    apply(node << 1 | 1, lazy[node]);
    lazy[node] = _End{};
  }

  void pull(size_t node) { data[node] = data[node << 1] + data[node << 1 | 1]; }

  template <class Pred>
  static constexpr decltype(std::declval<Pred>()(_Monoid{})) pass_args(
      Pred pred, _Monoid const &_1, [[maybe_unused]] size_t _2) {
    return pred(_1);
  }

  template <class Pred>
  static constexpr decltype(std::declval<Pred>()(_Monoid{}, size_t{}))
  pass_args(Pred pred, _Monoid const &_1, size_t _2) {
    return pred(_1, _2);
  }

  template <class Pred>
  size_t left_partition_subtree(size_t node, _Monoid mono, size_t step,
                                Pred pred) {
    assert(node);
    while (node < size_ext) {
      push(node);
      const _Monoid tmp = data[(node <<= 1) | 1] + mono;
      if (pass_args(pred, tmp, ((node | 1) << --step) ^ size_ext))
        mono = tmp;
      else
        ++node;
    }
    return ++node -= size_ext;
  }

  template <class Pred>
  size_t right_partition_subtree(size_t node, _Monoid mono, size_t step,
                                 Pred pred) {
    assert(node);
    while (node < size_ext) {
      push(node);
      const _Monoid tmp = mono + data[node <<= 1];
      if (pass_args(pred, tmp, ((node | 1) << --step) ^ size_ext))
        ++node, mono = tmp;
    }
    return (node -= size_ext) < size_orig ? node : size_orig;
  }

 public:
  class iterator {
    lazy_segment_tree *__p;
    size_t __i;

   public:
    using difference_type = typename std::make_signed<size_t>::type;
    using value_type = _Monoid;
    using reference = _Monoid &;
    using pointer = iterator;
    using iterator_category = std::random_access_iterator_tag;

    
    iterator() = default;

    
    iterator(lazy_segment_tree *__p, size_t __i) : __p(__p), __i(__i) {}

    bool operator==(iterator const &rhs) const {
      return __p == rhs.__p && __i == rhs.__i;
    }
    bool operator!=(iterator const &rhs) const { return !operator==(rhs); }

    bool operator<(iterator const &rhs) const { return __i < rhs.__i; }
    bool operator>(iterator const &rhs) const { return __i > rhs.__i; }
    bool operator<=(iterator const &rhs) const { return __i <= rhs.__i; }
    bool operator>=(iterator const &rhs) const { return __i >= rhs.__i; }

    iterator &operator++() { return ++__i, *this; }
    iterator &operator--() { return --__i, *this; }

    difference_type operator-(iterator const &rhs) const {
      return __i - rhs.__i;
    }

    
    reference operator*() const { return __p->operator[](__i); }
  };

  using value_type = typename iterator::value_type;
  using reference = typename iterator::reference;

  iterator begin() { return {this, 0}; }
  iterator end() { return {this, size_orig}; }

  auto rbegin() { return std::make_reverse_iterator(end()); }
  auto rend() { return std::make_reverse_iterator(begin()); }

  lazy_segment_tree(size_t n = 0)
      : size_orig{n},
        height(n > 1 ? 32 - __builtin_clz(n - 1) : 0),
        size_ext{1u << height},
        data(size_ext << 1),
        lazy(size_ext),
        wait(size_ext << 1) {}

  lazy_segment_tree(size_t n, const _Monoid &init) : lazy_segment_tree(n) {
    std::fill_n(std::next(std::begin(data), size_ext), n, init);
    for (size_t i{size_ext}; --i;) pull(i);
  }

  template <class iter_type, class value_type = typename std::iterator_traits<
                                 iter_type>::value_type>
  lazy_segment_tree(iter_type first, iter_type last)
      : size_orig(std::distance(first, last)),
        height(size_orig > 1 ? 32 - __builtin_clz(size_orig - 1) : 0),
        size_ext{1u << height},
        data(size_ext << 1),
        lazy(size_ext),
        wait(size_ext << 1) {
    static_assert(std::is_constructible<_Monoid, value_type>::value,
                  "_Monoid(iter_type::value_type) is not constructible.");
    for (auto iter{std::next(std::begin(data), size_ext)};
         iter != std::end(data) && first != last; ++iter, ++first)
      *iter = _Monoid(*first);
    for (size_t i{size_ext}; --i;) pull(i);
  }

  
  size_t size() const { return size_orig; }

  
  _Monoid &operator[](size_t index) {
    assert(index < size_orig);
    index |= size_ext;
    wait.push(index);
    for (size_t i = height; i; --i) push(index >> i);
    return data[index];
  }

  void update(const _End &endo) { update(0, size_orig, endo); }

  void update(size_t index, const _End &endo) {
    update(index, index + 1, endo);
  }

  void update(size_t first, size_t last, const _End &endo) {
    assert(last <= size_orig);
    repair();
    if (first >= last) return;
    first += size_ext, last += size_ext;
    --last;
    for (size_t i = height; i; --i) push(first >> i), push(last >> i);
    ++last;
    for (size_t l = first, r = last; l != r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, endo);
      if (r & 1) apply(--r, endo);
    }
    for (first >>= __builtin_ffs(first); first; first >>= 1) pull(first);
    for (last >>= __builtin_ffs(last); last; last >>= 1) pull(last);
  }

  
  _Monoid fold(size_t first, size_t last) {
    assert(last <= size_orig);
    repair();
    if (first >= last) return _Monoid{};
    first += size_ext, last += size_ext - 1;
    _Monoid left_val{}, right_val{};
    for (size_t l = first, r = last + 1; l != r; l >>= 1, r >>= 1) {
      if (l & 1) left_val = left_val + data[l++];
      if (r & 1) right_val = data[--r] + right_val;
      left_val = left_val * lazy[first >>= 1];
      right_val = right_val * lazy[last >>= 1];
    }
    while (first >>= 1, last >>= 1) {
      left_val = left_val * lazy[first];
      right_val = right_val * lazy[last];
    }
    return left_val + right_val;
  }

  
  _Monoid fold() {
    repair();
    return data[1];
  }

  
  template <class Pred> size_t left_partition(size_t right, Pred pred) {
    assert(right <= size_orig);
    repair();
    right += size_ext - 1;
    for (size_t i{height}; i; --i) push(right >> i);
    ++right;
    _Monoid mono{};
    for (size_t left{size_ext}, step{}; left != right;
         left >>= 1, right >>= 1, ++step) {
      if ((left & 1) != (right & 1)) {
        const _Monoid tmp = data[--right] + mono;
        if (!pass_args(pred, tmp, (right << step) ^ size_ext))
          return left_partition_subtree(right, mono, step, pred);
        mono = tmp;
      }
    }
    return 0;
  }

  
  template <class Pred> size_t right_partition(size_t left, Pred pred) {
    assert(left <= size_orig);
    repair();
    left += size_ext;
    for (size_t i{height}; i; --i) push(left >> i);
    _Monoid mono{};
    for (size_t right{size_ext << 1}, step{}; left != right;
         left >>= 1, right >>= 1, ++step) {
      if ((left & 1) != (right & 1)) {
        const _Monoid tmp = mono + data[left];
        if (!pass_args(pred, tmp, ((left + 1) << step) ^ size_ext))
          return right_partition_subtree(left, mono, step, pred);
        mono = tmp;
        ++left;
      }
    }
    return size_orig;
  }
};

}  

#line 29 "codeforces-workspace\\contest\\1588\\c\\c.cpp"

namespace workspace {

void main() {
  


  input n;
  input<vector<i64>> a(n);
  

  

  

  


  

  

  

  


  struct endo {
    i64 v{};
    endo operator*(endo x) const { return {v + x.v}; }
  };

  struct mono {
    i64 v = 1ll << 60;
    mono operator+(mono x) const { return {min(v, x.v)}; }
    mono operator*(endo x) const { return {v + x.v}; }
  };

  vector sgs(2, lazy_segment_tree<mono, endo>(n, {0}));
  i64 ans = 0;
  array<map<i64, vector<int>>, 2> app;
  app[0][0].emplace_back(0);
  i64 sum = 0;

  for (auto i : range(n)) {
    sum = a[i] - sum;

    auto low = 0;
    for (auto j : range(2)) {
      auto &s = sgs[(i + j) % 2];
      auto r = i / 2 + 1;
      if (j and !(i % 2)) r--;
      s.update(0, r, {j ? -a[i] : a[i]});
      int pt = s.left_partition(r, [&](auto x) { return x.v >= 0; });
      chgr(low, pt * 2 + (i + j) % 2 - 1);
    }

    ++i;

    for (auto j : range(2)) {
      auto &ve = app[j][i % 2 != j ? -sum : sum];
      ans += ve.end() - lower_bound(ve.begin(), ve.end(), low);
    }

    app[i % 2][sum].emplace_back(i);
  }

  print(ans);
}

}  

