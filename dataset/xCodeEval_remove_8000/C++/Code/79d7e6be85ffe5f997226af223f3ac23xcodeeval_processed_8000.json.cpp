






















namespace workspace {

template <class _Tp> struct numeric_limits : std::numeric_limits<_Tp> {};



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



}  



namespace workspace {

constexpr static char eol = '\n';

using namespace std;

using i32 = int_least32_t;
using u32 = uint_least32_t;
using i64 = int_least64_t;
using u64 = uint_least64_t;


using i128 = __int128_t;
using u128 = __uint128_t;




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



















namespace std {

template <typename _Tp> constexpr int id2(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id10 = numeric_limits<unsigned long long>::digits;
  constexpr auto id17 = numeric_limits<unsigned long>::digits;
  constexpr auto id12 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id12) {
    constexpr int __diff = id12 - _Nd;
    return __builtin_clz(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= id17) {
    constexpr int __diff = id17 - _Nd;
    return __builtin_clzl(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= id10) {
    constexpr int __diff = id10 - _Nd;
    return __builtin_clzll(__x) - __diff;
  } else  

  {
    static_assert(_Nd <= (2 * id10),
                  "Maximum supported integer size is 128-bit");

    unsigned long long __high = __x >> id10;
    if (__high != 0) {
      constexpr int __diff = (2 * id10) - _Nd;
      return __builtin_clzll(__high) - __diff;
    }
    constexpr auto id9 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id9;
    return (_Nd - id10) + __builtin_clzll(__low);
  }
}

template <typename _Tp> constexpr int id7(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id10 = numeric_limits<unsigned long long>::digits;
  constexpr auto id17 = numeric_limits<unsigned long>::digits;
  constexpr auto id12 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id12)
    return __builtin_ctz(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id17)
    return __builtin_ctzl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id10)
    return __builtin_ctzll(__x);
  else  

  {
    static_assert(_Nd <= (2 * id10),
                  "Maximum supported integer size is 128-bit");

    constexpr auto id9 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id9;
    if (__low != 0) return __builtin_ctzll(__low);
    unsigned long long __high = __x >> id10;
    return __builtin_ctzll(__high) + id10;
  }
}

template <typename _Tp> constexpr int id4(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return 0;

  constexpr auto id10 = numeric_limits<unsigned long long>::digits;
  constexpr auto id17 = numeric_limits<unsigned long>::digits;
  constexpr auto id12 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id12)
    return __builtin_popcount(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id17)
    return __builtin_popcountl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id10)
    return __builtin_popcountll(__x);
  else  

  {
    static_assert(_Nd <= (2 * id10),
                  "Maximum supported integer size is 128-bit");

    constexpr auto id9 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id9;
    unsigned long long __high = __x >> id10;
    return __builtin_popcountll(__low) + __builtin_popcountll(__high);
  }
}

template <typename _Tp> constexpr _Tp id18(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0 || __x == 1) return 1;
  auto id5 = _Nd - id2((_Tp)(__x - 1u));

  if (!__builtin_is_constant_evaluated()) {
    __glibcxx_assert(id5 != numeric_limits<_Tp>::digits);
  }

  using __promoted_type = decltype(__x << 1);
  if _GLIBCXX17_CONSTEXPR (!is_same<__promoted_type, _Tp>::value) {
    const int id3 = sizeof(__promoted_type) / sizeof(_Tp) / 2;
    id5 |= (id5 & _Nd) << id3;
  }
  return (_Tp)1u << id5;
}

template <typename _Tp> constexpr _Tp id16(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0) return 0;
  return (_Tp)1u << (_Nd - id2((_Tp)(__x >> 1)));
}

template <typename _Tp> constexpr _Tp id13(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  return _Nd - id2(__x);
}

}  






namespace workspace {



template <class _Tp> constexpr _Tp bsf(_Tp __x) noexcept {
  return std::id7(__x);
}

template <class _Tp> constexpr _Tp bsr(_Tp __x) noexcept {
  return std::id13(__x) - 1;
}



template <class _Tp>
constexpr _Tp test_bit(const _Tp& __b, std::size_t __n) noexcept {
  return __b >> __n & 1;
}

}  








namespace std {


template <typename _Tp, typename _Alloc, typename _Predicate>
inline typename vector<_Tp, _Alloc>::size_type erase_if(
    vector<_Tp, _Alloc>& __cont, _Predicate __pred) {
  const auto id6 = __cont.size();
  __cont.erase(remove_if(__cont.begin(), __cont.end(), __pred), __cont.end());
  return id6 - __cont.size();
}


template <typename _Tp, typename _Alloc, typename _Up>
inline typename vector<_Tp, _Alloc>::size_type erase(
    vector<_Tp, _Alloc>& __cont, const _Up& __value) {
  const auto id6 = __cont.size();
  __cont.erase(remove(__cont.begin(), __cont.end(), __value), __cont.end());
  return id6 - __cont.size();
}

}  









namespace workspace {


template <class _F> void call_once(_F &&__f) {
  static std::unordered_set<void *> __called;
  if (__called.count(std::addressof(__f))) return;
  __called.emplace(std::addressof(__f));
  __f();
}

}  







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




















namespace workspace {


void io_setup(int __n) {
  std::cin.tie(0)->sync_with_stdio(0);
  std::cout << std::fixed << std::setprecision(__n);


  atexit([] {
    char bufc;
    if (std::cin >> bufc)
      std::cerr << "\n\033[43m\033[30mwarning: buffer not empty.\033[0m\n\n";
  });

}

}  





















































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



template <class _Tp> reversed(_Tp &&) -> reversed<_Tp>;

template <class _Tp>
reversed(std::initializer_list<_Tp>) -> reversed<std::initializer_list<_Tp>>;



}  



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

  constexpr size_type size() const noexcept {
    return std::distance(__first, __last);
  }
};



template <class _Tp1, class _Tp2>
range(const _Tp1 &, const _Tp2 &)
    -> range<std::decay_t<decltype(++std::declval<_Tp1 &>())>>;

template <class _Tp>
range(const _Tp &) -> range<std::decay_t<decltype(++std::declval<_Tp &>())>>;

template <class... _Args>
constexpr decltype(auto) rrange(_Args &&...__args) noexcept {
  return reversed(range(std::forward<_Args>(__args)...));
}



}  

































namespace std {



template <> struct make_signed<__uint128_t> { using type = __int128_t; };
template <> struct make_signed<__int128_t> { using type = __int128_t; };

template <> struct make_unsigned<__uint128_t> { using type = __uint128_t; };
template <> struct make_unsigned<__int128_t> { using type = __uint128_t; };

template <> struct is_signed<__uint128_t> : std::false_type {};
template <> struct is_signed<__int128_t> : std::true_type {};

template <> struct is_unsigned<__uint128_t> : std::true_type {};
template <> struct is_unsigned<__int128_t> : std::false_type {};



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



template <> struct is_integral_ext<__int128_t> : std::true_type {};
template <> struct is_integral_ext<__uint128_t> : std::true_type {};





template <class _Tp>
constexpr static bool id0 = is_integral_ext<_Tp>::value;



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



template <typename _Tp>
struct multiplicable_uint<_Tp,
                          typename std::enable_if<(4 < sizeof(_Tp))>::type> {
  using type = __uint128_t;
};



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




















namespace workspace {

namespace _istream_impl {

template <class _Tp, typename = void> struct helper {
  helper(std::istream &__is, _Tp &__x) {
    if id14 (has_begin<_Tp &>::value)
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
    if id14 (_Nm != std::tuple_size<_Tuple>::value) {
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
    if id14 (not is_convertible<_Args...>::value) cin >> __value;
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
    if id14 (not is_convertible<_Args...>::value) cin >> *this;
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
  if id14 (_Nm) {
    __os << *__a;
    for (auto __i = __a + 1, __e = __a + _Nm; __i != __e; ++__i)
      __os << ' ' << *__i;
  }
  return __os;
}


template <class _Os, class _Tp, size_t _Nm>
ostream_ref<_Os> operator<<(_Os &__os, const std::array<_Tp, _Nm> &__a) {
  if id14 (_Nm) {
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
  if id14 (_Nm != std::tuple_size<_Tp>::value) {
    if id14 (_Nm) __os << ' ';
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



}  



namespace workspace {


template <char _Sep = ' ', char _End = '\n', class _Tp, class... _Args>
void print(_Tp &&__x, _Args &&...__args) noexcept {
  if id14 (sizeof...(_Args))
    cout << __x << _Sep, print(std::forward<_Args>(__args)...);
  else
    cout << __x << _End;
}

void flush() noexcept { cout << std::flush; }

}  



signed main() {
  using namespace workspace;

  io_setup(15);

  

  

  return case_info.iterate();
}



















namespace workspace {


template <class _Tp>
constexpr std::enable_if_t<(is_integral_ext<_Tp>::value), _Tp> pow_mod(
    _Tp __x, _Tp __n, _Tp __mod) noexcept {
  assert(__mod > 0);

  using mul_type = typename multiplicable_uint<_Tp>::type;

  if ((__x %= __mod) < 0) __x += __mod;

  mul_type __y{1};

  while (__n) {
    if (__n & 1) (__y *= __x) %= __mod;
    __x = (mul_type)__x * __x % __mod;
    __n >>= 1;
  }

  return __y;
};

}  



namespace workspace {


template <class _Tp>
constexpr std::enable_if_t<(is_integral_ext<_Tp>::value), _Tp> sqrt_mod(
    _Tp __x, _Tp __mod) noexcept {
  assert(__mod > 0);

  using mul_type = typename multiplicable_uint<_Tp>::type;

  if ((__x %= __mod) < 0) __x += __mod;

  if (!__x) return 0;

  if (__mod == 2) return __x;

  if (pow_mod(__x, __mod >> 1, __mod) != 1) return -1;

  _Tp __z = __builtin_ctz(__mod - 1), __q = __mod >> __z;

  mul_type __a = pow_mod(__x, (__q + 1) >> 1, __mod), __b = 2;
  while (pow_mod<_Tp>(__b, __mod >> 1, __mod) == 1) ++__b;
  __b = pow_mod<_Tp>(__b, __q, __mod);

  _Tp __shift = 0;

  for (auto __r = __a * __a % __mod * pow_mod(__x, __mod - 2, __mod) % __mod;
       __r != 1; (__r *= (__b *= __b) %= __mod) %= __mod) {
    auto id8 = __z;

    for (auto __e = __r; __e != 1; --id8) (__e *= __e) %= __mod;

    while (++__shift != id8) (__b *= __b) %= __mod;

    (__a *= __b) %= __mod;
  }

  return __a;
};

}  



namespace workspace {

namespace _modint_impl {

template <auto _Mod, unsigned _Storage> struct modint {
  static_assert(is_integral_ext<decltype(_Mod)>::value,
                "_Mod must be integral type.");

  using mod_type = std::make_signed_t<typename std::conditional<
      0 < _Mod, std::add_const_t<decltype(_Mod)>, decltype(_Mod)>::type>;

  using value_type = std::decay_t<mod_type>;

  using reference = value_type &;
  using const_reference = value_type const &;

  using mul_type = typename multiplicable_uint<value_type>::type;

  static mod_type mod;  


  static unsigned storage;

 private:
  template <class _Tp>
  using modint_if = std::enable_if_t<is_integral_ext<_Tp>::value, modint>;

  value_type value = 0;  


  struct direct_ctor_t {};
  constexpr static direct_ctor_t id1{};

  

  template <class _Tp>
  constexpr modint(_Tp __n, direct_ctor_t) noexcept : value(__n) {}

 public:
  constexpr modint() noexcept = default;

  template <class _Tp, class = std::enable_if_t<
                           std::is_convertible<_Tp, value_type>::value>>
  constexpr modint(_Tp __n) noexcept
      : value((__n %= mod) < 0 ? value_type(__n + mod) : value_type(__n)) {}

  constexpr modint(bool __n) noexcept : value(__n) {}

  constexpr operator reference() noexcept { return value; }

  constexpr operator const_reference() const noexcept { return value; }

  

  constexpr modint operator++(int) noexcept {
    modint __t{*this};
    operator++();
    return __t;
  }

  constexpr modint operator--(int) noexcept {
    modint __t{*this};
    operator--();
    return __t;
  }

  constexpr modint &operator++() noexcept {
    if (++value == mod) value = 0;
    return *this;
  }

  constexpr modint &operator--() noexcept {
    if (!value)
      value = mod - 1;
    else
      --value;
    return *this;
  }

  constexpr modint operator+() const noexcept { return *this; }

  constexpr modint operator-() const noexcept {
    return {value ? mod - value : 0, id1};
  }

  


  


  constexpr modint &operator+=(const modint &__x) noexcept {
    if ((value += __x.value) >= mod) value -= mod;
    return *this;
  }

  template <class _Tp> constexpr modint_if<_Tp> &operator+=(_Tp __x) noexcept {
    __x %= mod, value += __x;
    if (value < 0)
      value += mod;
    else if (value >= mod)
      value -= mod;
    return *this;
  }

  


  


  template <class _Tp>
  constexpr modint_if<_Tp> operator+(_Tp const &__x) const noexcept {
    return modint{*this} += __x;
  }

  constexpr modint operator+(modint __x) const noexcept { return __x += *this; }

  template <class _Tp>
  constexpr friend modint_if<_Tp> operator+(_Tp const &__x,
                                            modint __y) noexcept {
    return __y += __x;
  }

  


  


  constexpr modint &operator-=(const modint &__x) noexcept {
    if ((value -= __x.value) < 0) value += mod;
    return *this;
  }

  template <class _Tp> constexpr modint_if<_Tp> &operator-=(_Tp __x) noexcept {
    __x %= mod, value -= __x;
    if (value < 0)
      value += mod;
    else if (value >= mod)
      value -= mod;
    return *this;
  }

  


  


  template <class _Tp>
  constexpr modint_if<_Tp> operator-(_Tp const &__x) const noexcept {
    return modint{*this} -= __x;
  }

  constexpr modint operator-(const modint &__x) const noexcept {
    return modint{*this} -= __x;
  }

  template <class _Tp>
  constexpr friend modint_if<_Tp> operator-(_Tp __x,
                                            const modint &__y) noexcept {
    if (((__x -= __y.value) %= mod) < 0) __x += mod;
    return {__x, id1};
  }

  


  


  constexpr modint &operator*=(const modint &__x) noexcept {
    value =
        static_cast<value_type>(value * static_cast<mul_type>(__x.value) % mod);
    return *this;
  }

  template <class _Tp> constexpr modint_if<_Tp> &operator*=(_Tp __x) noexcept {
    value = static_cast<value_type>(
        value * ((__x %= mod) < 0 ? mul_type(__x + mod) : mul_type(__x)) % mod);
    return *this;
  }

  


  


  constexpr modint operator*(const modint &__x) const noexcept {
    return {static_cast<mul_type>(value) * __x.value % mod, id1};
  }

  template <class _Tp>
  constexpr modint_if<_Tp> operator*(_Tp __x) const noexcept {
    __x %= mod;
    if (__x < 0) __x += mod;
    return {static_cast<mul_type>(value) * __x % mod, id1};
  }

  template <class _Tp>
  constexpr friend modint_if<_Tp> operator*(_Tp __x,
                                            const modint &__y) noexcept {
    __x %= mod;
    if (__x < 0) __x += mod;
    return {static_cast<mul_type>(__x) * __y.value % mod, id1};
  }

  


 protected:
  static value_type _mem(value_type __x) {
    static std::vector<value_type> __m{0, 1};
    static value_type __i = (__m.reserve(storage), 1);
    while (__i < __x) {
      ++__i;
      __m.emplace_back(mod - mul_type(mod / __i) * __m[mod % __i] % mod);
    }
    return __m[__x];
  }

  static value_type _div(mul_type __r, value_type __x) noexcept {
    assert(__x != value_type(0));
    if (!__r) return 0;

    std::make_signed_t<value_type> __v{};
    bool __neg = __x < 0 ? __x = -__x, true : false;

    if (static_cast<decltype(storage)>(__x) < storage)
      __v = _mem(__x);
    else {
      value_type __y{mod}, __u{1}, __t;

      while (__x)
        __t = __y / __x, __y ^= __x ^= (__y -= __t * __x) ^= __x,
        __v ^= __u ^= (__v -= __t * __u) ^= __u;

      if (__y < 0) __neg ^= 1;
    }

    if (__neg)
      __v = 0 < __v ? mod - __v : -__v;
    else if (__v < 0)
      __v += mod;

    return __r == mul_type(1) ? static_cast<value_type>(__v)
                              : static_cast<value_type>(__r * __v % mod);
  }

 public:
  static void reserve(unsigned __n) noexcept {
    if (storage < __n) storage = __n;
  }

  


  constexpr modint &operator/=(const modint &__x) noexcept {
    if (value) value = _div(value, __x.value);
    return *this;
  }

  template <class _Tp> constexpr modint_if<_Tp> &operator/=(_Tp __x) noexcept {
    if (value) value = _div(value, __x %= mod);
    return *this;
  }

  


  


  constexpr modint operator/(const modint &__x) const noexcept {
    if (!value) return {};
    return {_div(value, __x.value), id1};
  }

  template <class _Tp>
  constexpr modint_if<_Tp> operator/(_Tp __x) const noexcept {
    if (!value) return {};
    return {_div(value, __x %= mod), id1};
  }

  template <class _Tp>
  constexpr friend modint_if<_Tp> operator/(_Tp __x,
                                            const modint &__y) noexcept {
    if (!__x) return {};
    if ((__x %= mod) < 0) __x += mod;
    return {_div(__x, __y.value), id1};
  }

  


  constexpr modint inv() const noexcept { return _div(1, value); }

  template <class _Tp> constexpr modint_if<_Tp> pow(_Tp __e) const noexcept {
    modint __r{mod != 1, id1};

    for (modint __b{__e < 0 ? __e = -__e, _div(1, value) : value,
                              id1};
         __e; __e >>= 1, __b *= __b)
      if (__e & 1) __r *= __b;

    return __r;
  }

  template <class _Tp>
  constexpr friend modint_if<_Tp> pow(modint __b, _Tp __e) noexcept {
    if (__e < 0) {
      __e = -__e;
      __b.value = _div(1, __b.value);
    }

    modint __r{mod != 1, id1};

    for (; __e; __e >>= 1, __b *= __b)
      if (__e & 1) __r *= __b;

    return __r;
  }

  constexpr modint sqrt() const noexcept {
    return {sqrt_mod(value, mod), id1};
  }

  friend constexpr modint sqrt(const modint &__x) noexcept {
    return {sqrt_mod(__x.value, mod), id1};
  }

  friend std::istream &operator>>(std::istream &__is, modint &__x) noexcept {
    std::string __s;
    __is >> __s;
    bool __neg = false;
    if (__s.front() == '-') {
      __neg = true;
      __s.erase(__s.begin());
    }
    __x = 0;
    for (char __c : __s) __x = __x * 10 + (__c - '0');
    if (__neg) __x = -__x;
    return __is;
  }
};

template <auto _Mod, unsigned _Storage>
typename modint<_Mod, _Storage>::mod_type modint<_Mod, _Storage>::mod =
    _Mod > 0 ? _Mod : 0;

template <auto _Mod, unsigned _Storage>
unsigned modint<_Mod, _Storage>::storage = _Storage;

}  


template <auto _Mod, unsigned _Storage = 0,
          typename = std::enable_if_t<(_Mod > 0)>>
using modint = _modint_impl::modint<_Mod, _Storage>;

template <unsigned _Id = 0, unsigned _Storage = 0>
using runtime_modint = _modint_impl::modint<-(signed)_Id, 0>;

template <unsigned _Id = 0, unsigned _Storage = 0>
using runtime_modint64 = _modint_impl::modint<-(int_least64_t)_Id, 0>;

}  













namespace workspace {



template <class _Tp, class _X = int_least64_t> _Tp factorial(_X __x) noexcept {
  if (__x < 0) return 0;
  static std::vector<_Tp> __t{1};
  static size_t __i = (__t.reserve(0x1000000), 0);
  while (__i < size_t(__x)) __t.emplace_back(__t.back() * _Tp(++__i));
  return __t[__x];
}



template <class _Tp, class _X = int_least64_t>
_Tp id15(_X __x) noexcept {
  if (__x < 0) return 0;
  static std::vector<_Tp> __t{1};
  static size_t __i = (__t.reserve(0x1000000), 0);
  while (__i < size_t(__x)) __t.emplace_back(__t.back() / _Tp(++__i));
  return __t[__x];
}

}  



namespace workspace {

namespace _binom_impl {

struct id11 {
  constexpr static int size = 132;
  __uint128_t __b[size][size]{1};

  constexpr id11() noexcept {
    for (int __i = 1; __i != size; ++__i)
      for (int __j = 0; __j != __i; ++__j)
        __b[__i][__j] += __b[__i - 1][__j],
            __b[__i][__j + 1] += __b[__i - 1][__j];
  }

  constexpr auto operator()(int __x, int __y) const noexcept {
    return __x < 0 || __x < __y ? 0 : (assert(__x < size), __b[__x][__y]);
  }
};

constexpr id11 table;

}  



template <class _Tp, class _X = int_fast64_t, class _Y = int_fast64_t>
constexpr _Tp binomial(_X __x, _Y __y) {
  if constexpr (is_integral_ext<_Tp>::value)
    return _binom_impl::table(__x, __y);

  if (__y < 0 || __x < __y) return 0;

  return factorial<_Tp>(__x) * id15<_Tp>(__y) *
         id15<_Tp>(__x - __y);
}


template <class _Tp, class _X = int_fast64_t> constexpr _Tp id19(_X __x) {
  return __x < 0
             ? _Tp(0)
             : binomial<_Tp>(__x << 1, __x) - binomial<_Tp>(__x << 1, __x + 1);
}

}  



namespace workspace {

using mint = runtime_modint<>;
auto fact = factorial<mint>;



void main() {
  


  int N, M, K, mod;
  cin >> N >> M >> K >> mod;
  mint::mod = mod;

  vector binom(N + 1, vector<i64>(N + 1));
  binom[0][0] = 1;
  for (auto n : range(N)) {
    for (auto r : range(n + 1)) {
      (binom[n + 1][r] += binom[n][r]) %= mod;
      (binom[n + 1][r + 1] += binom[n][r]) %= mod;
    }
  }

  

  i64 dp[101][101][101]{};

  

  for (auto&& v : dp[0]) {
    v[0] = 1;
  }

  for (auto n : range(1, N + 1)) {  

    dp[n][1][1] = fact(n);          


    for (auto m : range(2, M + 1)) {  

      if (n < m) {
        dp[n][m][0] = fact(n);
        continue;
      }

      for (auto k : range(min(K, n) + 1)) {  

        i64& now = dp[n][m][k];
        for (auto l : range(n)) {    

          const auto r = n - 1 - l;  

          if (l > r) break;
          i64 sum{};
          for (auto x = min(k, l); ~x; --x) {
            sum += dp[l][m - 1][x] * dp[r][m - 1][k - x] * ((l != r) + 1) % mod;
          }
          sum %= mod;
          now += sum * binom[n - 1][l] % mod;
        }
        now %= mod;
      }
    }
  }

  print(dp[N][M][K]);
}

}  

