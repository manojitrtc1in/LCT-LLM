#line 1 "codeforces-workspace\\contest\\1598\\f\\f.cpp"
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

#line 2 "Library\\lib\\cxx20"



#line 2 "Library\\lib\\bit"

#if __cplusplus > 201703L

#include <bit>

#elif __cplusplus > 201402L

#ifndef _GLIBCXX_BIT
#define _GLIBCXX_BIT 1

#include <limits>
#include <type_traits>

namespace std {

template <typename _Tp> constexpr int __countl_zero(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto _Nd_ull = numeric_limits<unsigned long long>::digits;
  constexpr auto _Nd_ul = numeric_limits<unsigned long>::digits;
  constexpr auto _Nd_u = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_u) {
    constexpr int __diff = _Nd_u - _Nd;
    return __builtin_clz(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ul) {
    constexpr int __diff = _Nd_ul - _Nd;
    return __builtin_clzl(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ull) {
    constexpr int __diff = _Nd_ull - _Nd;
    return __builtin_clzll(__x) - __diff;
  } else  

  {
    static_assert(_Nd <= (2 * _Nd_ull),
                  "Maximum supported integer size is 128-bit");

    unsigned long long __high = __x >> _Nd_ull;
    if (__high != 0) {
      constexpr int __diff = (2 * _Nd_ull) - _Nd;
      return __builtin_clzll(__high) - __diff;
    }
    constexpr auto __max_ull = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & __max_ull;
    return (_Nd - _Nd_ull) + __builtin_clzll(__low);
  }
}

template <typename _Tp> constexpr int __countr_zero(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto _Nd_ull = numeric_limits<unsigned long long>::digits;
  constexpr auto _Nd_ul = numeric_limits<unsigned long>::digits;
  constexpr auto _Nd_u = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_u)
    return __builtin_ctz(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ul)
    return __builtin_ctzl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ull)
    return __builtin_ctzll(__x);
  else  

  {
    static_assert(_Nd <= (2 * _Nd_ull),
                  "Maximum supported integer size is 128-bit");

    constexpr auto __max_ull = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & __max_ull;
    if (__low != 0) return __builtin_ctzll(__low);
    unsigned long long __high = __x >> _Nd_ull;
    return __builtin_ctzll(__high) + _Nd_ull;
  }
}

template <typename _Tp> constexpr int __popcount(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return 0;

  constexpr auto _Nd_ull = numeric_limits<unsigned long long>::digits;
  constexpr auto _Nd_ul = numeric_limits<unsigned long>::digits;
  constexpr auto _Nd_u = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_u)
    return __builtin_popcount(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ul)
    return __builtin_popcountl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ull)
    return __builtin_popcountll(__x);
  else  

  {
    static_assert(_Nd <= (2 * _Nd_ull),
                  "Maximum supported integer size is 128-bit");

    constexpr auto __max_ull = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & __max_ull;
    unsigned long long __high = __x >> _Nd_ull;
    return __builtin_popcountll(__low) + __builtin_popcountll(__high);
  }
}

template <typename _Tp> constexpr _Tp __bit_ceil(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0 || __x == 1) return 1;
  auto __shift_exponent = _Nd - __countl_zero((_Tp)(__x - 1u));
#ifdef _GLIBCXX_HAVE_BUILTIN_IS_CONSTANT_EVALUATED
  if (!__builtin_is_constant_evaluated()) {
    __glibcxx_assert(__shift_exponent != numeric_limits<_Tp>::digits);
  }
#endif
  using __promoted_type = decltype(__x << 1);
  if _GLIBCXX17_CONSTEXPR (!is_same<__promoted_type, _Tp>::value) {
    const int __extra_exp = sizeof(__promoted_type) / sizeof(_Tp) / 2;
    __shift_exponent |= (__shift_exponent & _Nd) << __extra_exp;
  }
  return (_Tp)1u << __shift_exponent;
}

template <typename _Tp> constexpr _Tp __bit_floor(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0) return 0;
  return (_Tp)1u << (_Nd - __countl_zero((_Tp)(__x >> 1)));
}

template <typename _Tp> constexpr _Tp __bit_width(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  return _Nd - __countl_zero(__x);
}

}  


#endif

#endif

namespace workspace {

#ifdef _GLIBCXX_BIT

template <class _Tp> constexpr _Tp bsf(_Tp __x) noexcept {
  return std::__countr_zero(__x);
}

template <class _Tp> constexpr _Tp bsr(_Tp __x) noexcept {
  return std::__bit_width(__x) - 1;
}

#endif

template <class _Tp>
constexpr _Tp test_bit(const _Tp& __b, std::size_t __n) noexcept {
  return __b >> __n & 1;
}

}  

#line 9 "Library\\lib\\cxx20"

#if __cplusplus <= 201703L

#include <algorithm>
#include <vector>

namespace std {


template <typename _Tp, typename _Alloc, typename _Predicate>
inline typename vector<_Tp, _Alloc>::size_type erase_if(
    vector<_Tp, _Alloc>& __cont, _Predicate __pred) {
  const auto __osz = __cont.size();
  __cont.erase(remove_if(__cont.begin(), __cont.end(), __pred), __cont.end());
  return __osz - __cont.size();
}


template <typename _Tp, typename _Alloc, typename _Up>
inline typename vector<_Tp, _Alloc>::size_type erase(
    vector<_Tp, _Alloc>& __cont, const _Up& __value) {
  const auto __osz = __cont.size();
  __cont.erase(remove(__cont.begin(), __cont.end(), __value), __cont.end());
  return __osz - __cont.size();
}

}  


#endif
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

#line 4 "Library\\lib\\utils"












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






#line 2 "Library\\src\\utils\\py-like\\enumerate.hpp"



#line 2 "Library\\src\\utils\\py-like\\range.hpp"



#line 2 "Library\\src\\utils\\py-like\\reversed.hpp"



#line 9 "Library\\src\\utils\\py-like\\reversed.hpp"

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

#line 2 "Library\\src\\utils\\py-like\\zip.hpp"



#line 11 "Library\\src\\utils\\py-like\\zip.hpp"

#line 2 "Library\\src\\utils\\iterator\\category.hpp"



#line 10 "Library\\src\\utils\\iterator\\category.hpp"

namespace workspace {


template <class Tuple, size_t N = std::tuple_size<Tuple>::value - 1>
struct common_iterator_category {
  using type = typename std::common_type<
      typename common_iterator_category<Tuple, N - 1>::type,
      typename std::iterator_traits<typename std::tuple_element<
          N, Tuple>::type>::iterator_category>::type;
};

template <class Tuple> struct common_iterator_category<Tuple, 0> {
  using type = typename std::iterator_traits<
      typename std::tuple_element<0, Tuple>::type>::iterator_category;
};

}  

#line 2 "Library\\src\\utils\\iterator\\reverse.hpp"



#if __cplusplus >= 201703L

#include <iterator>
#include <optional>

namespace workspace {


template <class Iterator>
class reverse_iterator : public std::reverse_iterator<Iterator> {
  using base_std = std::reverse_iterator<Iterator>;
  std::optional<typename base_std::value_type> deref;

 public:
  using base_std::reverse_iterator;

  constexpr typename base_std::reference operator*() noexcept {
    if (!deref) {
      Iterator tmp = base_std::current;
      deref = *--tmp;
    }
    return deref.value();
  }

  constexpr reverse_iterator &operator++() noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator &operator--() noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator operator++(int) noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator operator--(int) noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
};

}  


#endif
#line 15 "Library\\src\\utils\\py-like\\zip.hpp"

namespace workspace {

template <class _Tuple> class zipped : protected _Tuple {
 public:
  zipped(const _Tuple &__x) : _Tuple(__x) {}

  template <std::size_t _Nm> constexpr decltype(auto) get() const &noexcept {
    return *std::get<_Nm>(*this);
  }

  template <std::size_t _Nm> constexpr decltype(auto) get() &&noexcept {
    auto __tmp = *std::get<_Nm>(*this);
    return __tmp;
  }
};

template <class... _Containers> class zip {
  std::tuple<_Containers...> __c;

  template <std::size_t _Nm = 0>
  constexpr decltype(auto) begin_cat() const noexcept {
    if _CXX17_CONSTEXPR (_Nm != sizeof...(_Containers)) {
      return std::tuple_cat(std::tuple(std::begin(std::get<_Nm>(__c))),
                            begin_cat<_Nm + 1>());
    } else
      return std::tuple<>();
  }

  template <std::size_t _Nm = 0>
  constexpr decltype(auto) end_cat() const noexcept {
    if _CXX17_CONSTEXPR (_Nm != sizeof...(_Containers)) {
      return std::tuple_cat(std::tuple(std::end(std::get<_Nm>(__c))),
                            end_cat<_Nm + 1>());
    } else
      return std::tuple<>();
  }

  using _Iterator_tuple =
      std::tuple<decltype(std::begin(std::declval<_Containers>()))...>;

 public:
  using size_type = std::size_t;

  class iterator : public zipped<_Iterator_tuple> {
    using _Base = zipped<_Iterator_tuple>;

   public:
    using difference_type = std::ptrdiff_t;
    using value_type = _Base;
    using pointer = void;
    using reference = value_type &;
    using iterator_category =
        typename common_iterator_category<_Iterator_tuple>::type;

   protected:
    template <std::size_t _Nm = 0>
    constexpr bool equal(const iterator &__x) const noexcept {
      if _CXX17_CONSTEXPR (_Nm != sizeof...(_Containers)) {
        return std::get<_Nm>(*this) == std::get<_Nm>(__x) ||
               equal<_Nm + 1>(__x);
      } else
        return false;
    }

    template <std::size_t _Nm = 0> constexpr void increment() noexcept {
      if _CXX17_CONSTEXPR (_Nm != sizeof...(_Containers))
        ++std::get<_Nm>(*this), increment<_Nm + 1>();
    }

    template <std::size_t _Nm = 0> constexpr void decrement() noexcept {
      if _CXX17_CONSTEXPR (_Nm != sizeof...(_Containers))
        --std::get<_Nm>(*this), decrement<_Nm + 1>();
    }

    template <std::size_t _Nm = 0>
    constexpr void advance(difference_type __d) noexcept {
      if _CXX17_CONSTEXPR (_Nm != sizeof...(_Containers))
        std::get<_Nm>(*this) += __d, advance<_Nm + 1>(__d);
    }

   public:
    iterator(const _Iterator_tuple &__x) : _Base(__x) {}

    constexpr bool operator==(const iterator &__x) const noexcept {
      return equal(__x);
    }
    constexpr bool operator!=(const iterator &__x) const noexcept {
      return !equal(__x);
    }

    constexpr iterator &operator++() noexcept {
      increment();
      return *this;
    }
    constexpr iterator operator++(int) noexcept {
      auto __tmp = *this;
      increment();
      return __tmp;
    }

    constexpr iterator &operator--() noexcept {
      decrement();
      return *this;
    }
    constexpr iterator operator--(int) noexcept {
      auto __tmp = *this;
      decrement();
      return __tmp;
    }

    constexpr bool operator<(const iterator &__x) const noexcept {
      return std::get<0>(*this) < std::get<0>(__x);
    }
    constexpr bool operator<=(const iterator &__x) const noexcept {
      return std::get<0>(*this) <= std::get<0>(__x);
    }
    constexpr bool operator>(const iterator &__x) const noexcept {
      return !operator<=(__x);
    }
    constexpr bool operator>=(const iterator &__x) const noexcept {
      return !operator>(__x);
    }

    constexpr iterator &operator+=(difference_type __d) noexcept {
      advance(__d);
      return *this;
    }
    constexpr iterator &operator-=(difference_type __d) noexcept {
      advance(-__d);
      return *this;
    }
    constexpr iterator operator+(difference_type __d) const noexcept {
      return iterator{*this} += __d;
    }
    constexpr iterator operator-(difference_type __d) const noexcept {
      return iterator{*this} -= __d;
    }

    constexpr difference_type operator-(const iterator &__x) const noexcept {
      return std::get<0>(*this) - std::get<0>(__x);
    }

    constexpr reference operator*() noexcept { return {*this}; }
  };

  using const_iterator = iterator;

  template <class... _Args>
  constexpr zip(_Args &&...__args) noexcept
      : __c(std::forward<_Args>(__args)...) {}

  template <class... _Args>
  constexpr zip(std::initializer_list<_Args>... __args) noexcept
      : __c(std::forward<_Args>(__args)...) {}

  constexpr iterator begin() const noexcept { return {begin_cat()}; }

  constexpr iterator end() const noexcept { return {end_cat()}; }

  constexpr reverse_iterator<iterator> rbegin() const noexcept {
    return reverse_iterator<iterator>{end()};
  }

  constexpr reverse_iterator<iterator> rend() const noexcept {
    return reverse_iterator<iterator>{begin()};
  }

#if __cplusplus >= 201703L
  constexpr size_type size() const noexcept {
    size_type __n = -1;
    std::apply(
        [&__n](auto &&__x) {
          if (__n < __x.size()) __n = __x.size();
        },
        __c);
    return __n;
  }
#endif
};

#if __cpp_deduction_guides >= 201606L

template <class... _Args> zip(_Args &&...) -> zip<_Args...>;





template <class _Tp, class... _Args>
zip(_Tp &&, _Args &&...) -> zip<_Tp, _Args...>;

template <class... _Args>
zip(std::initializer_list<_Args>...) -> zip<std::initializer_list<_Args>...>;

#endif

}  


namespace std {

template <size_t _Nm, class _Tuple>
struct tuple_element<_Nm, workspace::zipped<_Tuple>> {
  using type = remove_reference_t<
      typename iterator_traits<tuple_element_t<_Nm, _Tuple>>::reference>;
};

template <class _Tuple>
struct tuple_size<workspace::zipped<_Tuple>> : tuple_size<_Tuple> {};

}  

#line 10 "Library\\src\\utils\\py-like\\enumerate.hpp"

#if __cplusplus >= 201703L

namespace workspace {

namespace _enumerate_impl {

constexpr size_t min_size() noexcept { return SIZE_MAX; }

template <class _Container, class... _Args>
constexpr size_t min_size(_Container const &__cont,
                          _Args &&... __args) noexcept {
  return std::min(std::size(__cont), min_size(std::forward<_Args>(__args)...));
}

}  


template <class... _Args>
constexpr decltype(auto) enumerate(_Args &&... __args) noexcept {
  return zip(range(_enumerate_impl::min_size(__args...)),
             std::forward<_Args>(__args)...);
}

template <class... _Args>
constexpr decltype(auto) enumerate(
    std::initializer_list<_Args> const &... __args) noexcept {
  return zip(range(_enumerate_impl::min_size(__args...)),
             std::vector(__args)...);
}

}  


#endif
#line 16 "Library\\lib\\utils"








#line 2 "Library\\src\\utils\\round_div.hpp"



#line 9 "Library\\src\\utils\\round_div.hpp"

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



#line 2 "Library\\src\\utils\\io\\istream.hpp"



#include <cxxabi.h>

#line 13 "Library\\src\\utils\\io\\istream.hpp"

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

#line 13 "codeforces-workspace\\contest\\1598\\f\\f.cpp"

signed main() {
  using namespace workspace;

  io_setup(15);

  

  

  return case_info.iterate();
}

namespace workspace {

template <class _Tp> class extended {
  bool infinite{};
  int_least8_t sign{};  

  _Tp value{};          


  template <class _Os>
  friend _Os &operator<<(_Os &__os, const extended &__x) noexcept {
    return __os << __x.value;
  }

  template <class _Is>
  friend _Is &operator>>(_Is &__is, extended &__x) noexcept {
    _Tp __v;
    __is >> __v, __x = extended(__v);
    return __is;
  }

  constexpr extended(bool __x, int_least8_t __y, _Tp __z) noexcept
      : infinite(__x), sign(__y), value(__z) {}

 public:
  constexpr static extended infinity{true, +1, 0};

  constexpr extended() noexcept : infinite{false} {}

  constexpr extended(_Tp __x) noexcept
      : infinite{false},
        sign(__x != _Tp(0) ? (__x > _Tp(0) ? +1 : -1) : 0),
        value(__x) {}

  


  


  


  constexpr extended operator+() const noexcept { return *this; }

  constexpr extended operator-() const noexcept {
    return extended(infinite, -sign, -value);
  }

  constexpr extended &operator+=(const extended &__x) noexcept {
    if (!infinite) {
      if (__x.infinite) infinite = true, sign = __x.sign, value = 0;
      

      

      else
        value += __x.value;
    }
    return *this;
  }

  constexpr extended &operator-=(const extended &__x) noexcept {
    return operator+=(-__x);
  }

  constexpr extended &operator*=(const extended &__x) noexcept {
    if (sign *= __x.sign)
      infinite = infinite || __x.infinite, value *= __x.value;
    else
      infinite = false, value = 0;
    return *this;
  }

  constexpr extended &operator/=(const extended &__x) noexcept {
    if (__x.infinite)
      infinite = false, sign = 0, value = 0;
    else if (__x.sign)
      sign *= __x.sign, value /= __x.value;
    else
      infinite = true, value = 0;
    return *this;
  }

  constexpr extended operator+(const extended &__x) const noexcept {
    return extended(*this) += __x;
  }

  constexpr extended operator-(const extended &__x) const noexcept {
    return extended(*this) -= __x;
  }

  constexpr extended operator*(const extended &__x) const noexcept {
    return extended(*this) *= __x;
  }

  constexpr extended operator/(const extended &__x) const noexcept {
    return extended(*this) /= __x;
  }

  constexpr bool operator==(const extended &__x) const noexcept {
    return infinite == __x.infinite && sign == __x.sign && value == __x.value;
  }

  constexpr bool operator!=(const extended &__x) const noexcept {
    return !operator==(__x);
  }

  constexpr bool operator<(const extended &__x) const noexcept {
    auto __l = sign * infinite, __r = __x.sign * __x.infinite;
    return __l != __r ? __l < __r : value < __x.value;
  }

  constexpr bool operator<=(const extended &__x) const noexcept {
    auto __l = sign * infinite, __r = __x.sign * __x.infinite;
    return __l != __r ? __l < __r : value <= __x.value;
  }

  constexpr bool operator>(const extended &__x) const noexcept {
    return __x.operator<(*this);
  }

  constexpr bool operator>=(const extended &__x) const noexcept {
    return __x.operator<=(*this);
  }
};

using eint = extended<i32>;

void main() {
  


  input N;

  vector<tuple<i32, i32, vector<i32>>> S(N);

  for (auto &&[acc, low, dec] : S) {
    dec = {0};
    for (auto c : input<string>()) {
      if (c == '(') {
        acc++;
      } else {
        acc--;
      }
      if (chle(low, acc)) dec.emplace_back();
      if (low == acc) dec.back()++;
    }
  }

  vector dp(1 << N, pair{-eint::infinity, 0});
  auto ans = -eint::infinity;
  dp[0] = {0, 0};

  for (auto &&[s, _v] : enumerate(dp)) {
    for (auto &&[i, t] : enumerate(S)) {
      if (s >> i & 1) continue;
      auto v = _v;
      auto &&[acc, low, dec] = t;
      assert(v.second >= 0);
      if (v.second < dec.size()) v.first += dec[v.second];
      chgr(ans, v.first);
      if (v.second + low < 0) continue;
      v.second += acc;
      chgr(dp[s | 1 << i], v);
    }
  }

  print(ans);
}

}  
