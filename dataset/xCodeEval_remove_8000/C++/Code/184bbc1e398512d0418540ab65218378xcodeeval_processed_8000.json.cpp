


























namespace std {

template <typename _Tp> constexpr _Tp id13(_Tp __x, int __s) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  const int __r = __s % _Nd;
  if (__r == 0)
    return __x;
  else if (__r > 0)
    return (__x << __r) | (__x >> ((_Nd - __r) % _Nd));
  else
    return (__x >> -__r) | (__x << ((_Nd + __r) % _Nd));  

}

template <typename _Tp> constexpr _Tp id21(_Tp __x, int __s) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  const int __r = __s % _Nd;
  if (__r == 0)
    return __x;
  else if (__r > 0)
    return (__x >> __r) | (__x << ((_Nd - __r) % _Nd));
  else
    return (__x << -__r) | (__x >> ((_Nd + __r) % _Nd));  

}

template <typename _Tp> constexpr int id2(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id17 = numeric_limits<unsigned long long>::digits;
  constexpr auto id25 = numeric_limits<unsigned long>::digits;
  constexpr auto id19 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id19) {
    constexpr int __diff = id19 - _Nd;
    return __builtin_clz(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= id25) {
    constexpr int __diff = id25 - _Nd;
    return __builtin_clzl(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= id17) {
    constexpr int __diff = id17 - _Nd;
    return __builtin_clzll(__x) - __diff;
  } else  

  {
    static_assert(_Nd <= (2 * id17),
                  "Maximum supported integer size is 128-bit");

    unsigned long long __high = __x >> id17;
    if (__high != 0) {
      constexpr int __diff = (2 * id17) - _Nd;
      return __builtin_clzll(__high) - __diff;
    }
    constexpr auto id15 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id15;
    return (_Nd - id17) + __builtin_clzll(__low);
  }
}

template <typename _Tp> constexpr int id9(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return id2<_Tp>((_Tp)~__x);
}

template <typename _Tp> constexpr int id28(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id17 = numeric_limits<unsigned long long>::digits;
  constexpr auto id25 = numeric_limits<unsigned long>::digits;
  constexpr auto id19 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id19)
    return __builtin_ctz(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id25)
    return __builtin_ctzl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id17)
    return __builtin_ctzll(__x);
  else  

  {
    static_assert(_Nd <= (2 * id17),
                  "Maximum supported integer size is 128-bit");

    constexpr auto id15 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id15;
    if (__low != 0) return __builtin_ctzll(__low);
    unsigned long long __high = __x >> id17;
    return __builtin_ctzll(__high) + id17;
  }
}

template <typename _Tp> constexpr int id8(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return id28((_Tp)~__x);
}

template <typename _Tp> constexpr int id5(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return 0;

  constexpr auto id17 = numeric_limits<unsigned long long>::digits;
  constexpr auto id25 = numeric_limits<unsigned long>::digits;
  constexpr auto id19 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id19)
    return __builtin_popcount(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id25)
    return __builtin_popcountl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id17)
    return __builtin_popcountll(__x);
  else  

  {
    static_assert(_Nd <= (2 * id17),
                  "Maximum supported integer size is 128-bit");

    constexpr auto id15 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id15;
    unsigned long long __high = __x >> id17;
    return __builtin_popcountll(__low) + __builtin_popcountll(__high);
  }
}

template <typename _Tp> constexpr bool id7(_Tp __x) noexcept {
  return id5(__x) == 1;
}

template <typename _Tp> constexpr _Tp id26(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0 || __x == 1) return 1;
  auto id11 = _Nd - id2((_Tp)(__x - 1u));

  if (!__builtin_is_constant_evaluated()) {
    __glibcxx_assert(id11 != numeric_limits<_Tp>::digits);
  }

  using __promoted_type = decltype(__x << 1);
  if _GLIBCXX17_CONSTEXPR (!is_same<__promoted_type, _Tp>::value) {
    const int id3 = sizeof(__promoted_type) / sizeof(_Tp) / 2;
    id11 |= (id11 & _Nd) << id3;
  }
  return (_Tp)1u << id11;
}

template <typename _Tp> constexpr _Tp id23(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0) return 0;
  return (_Tp)1u << (_Nd - id2((_Tp)(__x >> 1)));
}

template <typename _Tp> constexpr _Tp id20(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  return _Nd - id2(__x);
}

}  









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

constexpr char eol = '\n';

using namespace std;

using i32 = int_least32_t;
using u32 = uint_least32_t;
using i64 = int_least64_t;
using u64 = uint_least64_t;


using i128 = __int128_t;
using u128 = __uint128_t;




namespace _alias_impl {

template <class> struct first_arg { using type = void; };

template <class _Tp, class = void> struct parse_comp : first_arg<_Tp> {};

template <class _Tp>
struct parse_comp<_Tp, std::__void_t<decltype(&_Tp::operator())>>
    : first_arg<decltype(&_Tp::operator())> {};

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

}  


template <class _Tp = void, class _Compare = std::less<_Tp>>
decltype(auto) id16(_Compare __x = _Compare()) noexcept {
  using type = std::conditional_t<
      std::is_void<_Tp>::value,
      std::decay_t<typename _alias_impl::parse_comp<_Compare>::type>, _Tp>;

  return std::priority_queue<type, std::vector<type>, _Compare>(__x);
}

template <class _Tp = void, class _Compare = std::less<_Tp>>
decltype(auto) make_set(_Compare __x = _Compare()) noexcept {
  using type = std::conditional_t<
      std::is_void<_Tp>::value,
      std::decay_t<typename _alias_impl::parse_comp<_Compare>::type>, _Tp>;

  return std::set<type, _Compare>(__x);
}

template <class _Key, class _Mapped, class _Compare = std::less<_Key>>
decltype(auto) make_map(_Compare __x = _Compare()) noexcept {
  return std::map<_Key, _Mapped, _Compare>(__x);
}

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

template <typename _Tp> constexpr _Tp id14(_Tp __x) noexcept {
  return std::id28(__x);
}

template <typename _Tp> constexpr _Tp id12(_Tp __x) noexcept {
  return std::id20(__x) - 1;
}

}  
























namespace workspace {

using namespace std::chrono;

namespace internal {


const auto start_time{system_clock::now()};
}  



int64_t elapsed() {
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


template <class _C1, class _C2>
constexpr decltype(auto) cat(_C1 &&id22, _C2 &&id18) noexcept {
  auto __c = std::forward<_C1>(id22);

  if constexpr (std::is_rvalue_reference<decltype(id18)>::value)
    __c.insert(std::end(__c), std::move_iterator(std::begin(id18)),
               std::move_iterator(std::end(id18)));

  else
    __c.insert(std::end(__c), std::cbegin(id18), std::cend(id18));

  return __c;
}


template <class _C1, class _C2, class... _Args>
constexpr decltype(auto) cat(_C1 &&id22, _C2 &&id18,
                             _Args &&...__args) noexcept {
  return cat(cat(std::forward<_C1>(id22), std::forward<_C2>(id18)),
             std::forward<_Args>(__args)...);
}

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

































namespace std {



template <> struct make_signed<__uint128_t> { using type = __int128_t; };
template <> struct make_signed<__int128_t> { using type = __int128_t; };

template <> struct make_unsigned<__uint128_t> { using type = __uint128_t; };
template <> struct make_unsigned<__int128_t> { using type = __uint128_t; };



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
using element_type = typename std::decay<decltype(
    *std::begin(std::declval<Container&>()))>::type;

template <class _Tp, class = std::nullptr_t>
struct has_begin : std::false_type {};

template <class _Tp>
struct has_begin<_Tp, decltype(std::begin(std::declval<_Tp>()), nullptr)>
    : std::true_type {};

template <class _Tp, class = std::nullptr_t>
struct has_mod : std::false_type {};

template <class _Tp>
struct has_mod<_Tp, decltype(_Tp::mod, nullptr)> : std::true_type {};

template <class _Tp, class = void> struct is_integral_ext : std::false_type {};
template <class _Tp>
struct is_integral_ext<
    _Tp, typename std::enable_if<std::is_integral<_Tp>::value>::type>
    : std::true_type {};



template <> struct is_integral_ext<__int128_t> : std::true_type {};
template <> struct is_integral_ext<__uint128_t> : std::true_type {};





template <class _Tp>
constexpr static bool id1 = is_integral_ext<_Tp>::value;



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

}  



namespace workspace {

namespace internal {

template <class Tp, typename = std::nullptr_t> struct istream_helper {
  istream_helper(std::istream &is, Tp &x) {
    if constexpr (has_begin<Tp>::value)
      for (auto &&e : x)
        istream_helper<typename std::decay<decltype(e)>::type>(is, e);
    else
      static_assert(has_begin<Tp>::value, "istream unsupported type.");
  }
};

template <class Tp>
struct istream_helper<
    Tp,
    decltype(std::declval<std::decay<decltype(std::declval<std::istream &>() >>
                                              std::declval<Tp &>())>>(),
             nullptr)> {
  istream_helper(std::istream &is, Tp &x) { is >> x; }
};



template <> struct istream_helper<__uint128_t, std::nullptr_t> {
  istream_helper(std::istream &__is, __uint128_t &__x) {
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

template <> struct istream_helper<__int128_t, std::nullptr_t> {
  istream_helper(std::istream &__is, __int128_t &__x) {
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




template <class T1, class T2> struct istream_helper<std::pair<T1, T2>> {
  istream_helper(std::istream &is, std::pair<T1, T2> &x) {
    istream_helper<T1>(is, x.first), istream_helper<T2>(is, x.second);
  }
};

template <class... Tps> struct istream_helper<std::tuple<Tps...>> {
  istream_helper(std::istream &is, std::tuple<Tps...> &x) { iterate(is, x); }

 private:
  template <class Tp, size_t N = 0> void iterate(std::istream &is, Tp &x) {
    if constexpr (N == std::tuple_size<Tp>::value)
      return;
    else
      istream_helper<typename std::tuple_element<N, Tp>::type>(is,
                                                               std::get<N>(x)),
          iterate<Tp, N + 1>(is, x);
  }
};

}  



class istream : public std::istream {
 public:
  
  template <typename Tp> istream &operator>>(Tp &x) {
    internal::istream_helper<Tp>(*this, x);
    if (std::istream::fail()) {
      static auto once = atexit([] {
        std::cerr << "\n\033[43m\033[30mwarning: failed to read \'"
                  << abi::__cxa_demangle(typeid(Tp).name(), 0, 0, 0)
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
  if constexpr (_Nm) {
    __os << *__a;
    for (auto __i = __a + 1, __e = __a + _Nm; __i != __e; ++__i)
      __os << ' ' << *__i;
  }
  return __os;
}


template <class _Os, class _Tp, size_t _Nm>
ostream_ref<_Os> operator<<(_Os &__os, const std::array<_Tp, _Nm> &__a) {
  if constexpr (_Nm) {
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
  if constexpr (_Nm != std::tuple_size<_Tp>::value) {
    if constexpr (_Nm) __os << ' ';
    __os << std::get<_Nm>(__t);
    operator<<<_Os, _Tp, _Nm + 1>(__os, __t);
  }
  return __os;
}

template <class _Os, class _Container,
          typename = decltype(std::begin(std::declval<_Container>()))>
typename std::enable_if<
    !std::is_same<typename std::decay<_Container>::type, std::string>::value &&
        !std::is_same<typename std::decay<_Container>::type, char *>::value,
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























namespace workspace {

namespace _reversed_impl {

template <class _Container> class reversed {
  _Container __cont;

 public:
  constexpr reversed(_Container &&__cont) noexcept : __cont(__cont) {}

  constexpr decltype(auto) begin() noexcept { return std::rbegin(__cont); }
  constexpr decltype(auto) begin() const noexcept {
    return std::rbegin(__cont);
  }

  constexpr decltype(auto) end() noexcept { return std::rend(__cont); }
  constexpr decltype(auto) end() const noexcept { return std::rend(__cont); }

  constexpr decltype(auto) size() const noexcept { return std::size(__cont); }
};

}  


template <class _Container>
constexpr decltype(auto) reversed(_Container &&__cont) noexcept {
  return _reversed_impl::reversed<_Container>{std::forward<_Container>(__cont)};
}

template <class _Tp>
constexpr decltype(auto) reversed(
    std::initializer_list<_Tp> &&__cont) noexcept {
  return _reversed_impl::reversed<std::initializer_list<_Tp>>{
      std::forward<std::initializer_list<_Tp>>(__cont)};
}

}  





namespace workspace {

template <class _Index> class range {
  _Index __first, __last;

 public:
  class iterator {
    _Index current;

   public:
    using difference_type = std::ptrdiff_t;
    using value_type = _Index;
    using reference = typename std::add_const<_Index>::type &;
    using pointer = iterator;
    using iterator_category = std::bidirectional_iterator_tag;

    constexpr iterator(_Index const &__i = _Index()) noexcept : current(__i) {}

    constexpr bool operator==(iterator const &__x) const noexcept {
      return current == __x.current;
    }
    constexpr bool operator!=(iterator const &__x) const noexcept {
      return current != __x.current;
    }

    constexpr iterator &operator++() noexcept {
      ++current;
      return *this;
    }
    constexpr iterator &operator--() noexcept {
      --current;
      return *this;
    }

    constexpr reference operator*() const noexcept { return current; }
  };

  constexpr range(_Index __first, _Index __last) noexcept
      : __first(__first), __last(__last) {}
  constexpr range(_Index __last) noexcept : __first(), __last(__last) {}

  constexpr iterator begin() const noexcept { return iterator{__first}; }
  constexpr iterator end() const noexcept { return iterator{__last}; }

  constexpr reverse_iterator<iterator> rbegin() const noexcept {
    return reverse_iterator<iterator>(end());
  }
  constexpr reverse_iterator<iterator> rend() const noexcept {
    return reverse_iterator<iterator>(begin());
  }
};

template <class... _Args>
constexpr decltype(auto) rrange(_Args &&...__args) noexcept {
  return reversed(range(std::forward<_Args>(__args)...));
}

}  













namespace workspace {

namespace internal {

template <class> struct id24;

template <class...> struct zipped_iterator_tuple;

template <class... Args> class zipped {
  using ref_tuple = std::tuple<Args...>;
  ref_tuple args;

  template <size_t N = 0> constexpr auto begin_cat() const noexcept {
    if constexpr (N != std::tuple_size<ref_tuple>::value) {
      return std::tuple_cat(std::tuple(std::begin(std::get<N>(args))),
                            begin_cat<N + 1>());
    } else
      return std::tuple<>();
  }

  template <size_t N = 0> constexpr auto end_cat() const noexcept {
    if constexpr (N != std::tuple_size<ref_tuple>::value) {
      return std::tuple_cat(std::tuple(std::end(std::get<N>(args))),
                            end_cat<N + 1>());
    } else
      return std::tuple<>();
  }

 public:
  constexpr zipped(Args &&... args) noexcept : args(args...) {}

  class iterator {
    using base_tuple = typename zipped_iterator_tuple<Args...>::type;

   public:
    using iterator_category =
        typename common_iterator_category<base_tuple>::type;
    using difference_type = std::ptrdiff_t;
    using value_type = id24<base_tuple>;
    using reference = id24<base_tuple> &;
    using pointer = iterator;

   protected:
    value_type current;

    template <size_t N = 0>
    constexpr bool equal(const iterator &rhs) const noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        return std::get<N>(current) == std::get<N>(rhs.current) ||
               equal<N + 1>(rhs);
      } else
        return false;
    }

    template <size_t N = 0> constexpr void increment() noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        ++std::get<N>(current);
        increment<N + 1>();
      }
    }

    template <size_t N = 0> constexpr void decrement() noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        --std::get<N>(current);
        decrement<N + 1>();
      }
    }

    template <size_t N = 0>
    constexpr void advance(difference_type __d) noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        std::get<N>(current) += __d;
        advance<N + 1>(__d);
      }
    }

   public:
    constexpr iterator() noexcept = default;
    constexpr iterator(base_tuple const &current) noexcept : current(current) {}

    constexpr bool operator==(const iterator &rhs) const noexcept {
      return equal(rhs);
    }
    constexpr bool operator!=(const iterator &rhs) const noexcept {
      return !equal(rhs);
    }

    constexpr iterator &operator++() noexcept {
      increment();
      return *this;
    }
    constexpr iterator &operator--() noexcept {
      decrement();
      return *this;
    }

    constexpr bool operator<(const iterator &rhs) const noexcept {
      return std::get<0>(current) < std::get<0>(rhs.current);
    }

    constexpr bool operator<=(const iterator &rhs) const noexcept {
      return std::get<0>(current) <= std::get<0>(rhs.current);
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

    constexpr difference_type operator-(const iterator &rhs) const noexcept {
      return std::get<0>(current) - std::get<0>(rhs.current);
    }

    constexpr reference operator*() noexcept { return current; }
  };

  constexpr iterator begin() const noexcept { return iterator{begin_cat()}; }
  constexpr iterator end() const noexcept { return iterator{end_cat()}; }

  constexpr reverse_iterator<iterator> rbegin() const noexcept {
    return reverse_iterator<iterator>{end()};
  }
  constexpr reverse_iterator<iterator> rend() const noexcept {
    return reverse_iterator<iterator>{begin()};
  }
};

template <class Tp, class... Args> struct zipped_iterator_tuple<Tp, Args...> {
  using type = decltype(std::tuple_cat(
      std::declval<std::tuple<decltype(std::begin(std::declval<Tp>()))>>(),
      std::declval<typename zipped_iterator_tuple<Args...>::type>()));
};

template <> struct zipped_iterator_tuple<> { using type = std::tuple<>; };

template <class Iter_tuple> struct id24 : Iter_tuple {
  constexpr id24(Iter_tuple const &__t) noexcept
      : Iter_tuple::tuple(__t) {}

  constexpr id24(id24 const &__t) = default;

  constexpr id24 &operator=(id24 const &__t) = default;

  

  constexpr id24(id24 &&__t)
      : id24(static_cast<id24 const &>(__t)) {}

  

  id24 &operator=(id24 &&__t) {
    return operator=(static_cast<id24 const &>(__t));
  }

  template <size_t N>
  friend constexpr auto &get(id24<Iter_tuple> const &__z) noexcept {
    return *std::get<N>(__z);
  }

  template <size_t N>
  friend constexpr auto get(id24<Iter_tuple> &&__z) noexcept {
    return *std::get<N>(__z);
  }
};

}  


}  


namespace std {

template <size_t N, class Iter_tuple>
struct tuple_element<N, workspace::internal::id24<Iter_tuple>> {
  using type = typename remove_reference<typename iterator_traits<
      typename tuple_element<N, Iter_tuple>::type>::reference>::type;
};

template <class Iter_tuple>
struct tuple_size<workspace::internal::id24<Iter_tuple>>
    : tuple_size<Iter_tuple> {};

}  


namespace workspace {

template <class... Args> constexpr auto zip(Args &&... args) noexcept {
  return internal::zipped<Args...>(std::forward<Args>(args)...);
}

template <class... Args>
constexpr auto zip(std::initializer_list<Args> const &... args) noexcept {
  return internal::zipped<const std::initializer_list<Args>...>(args...);
}

}  







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












signed main() {
  using namespace workspace;

  io_setup(15);

  

  

  return case_info.iterate();
}













namespace workspace {

template <class Cap, class Cost = void> class flow_graph {
 protected:
  class adjacency_impl;

 public:
  using container_type = std::vector<adjacency_impl>;
  using size_type = typename container_type::size_type;

  class id4 {
   public:
    size_type src;  

    size_type dst;  

    Cap cap;        

    Cap flow = 0;   


    id4(size_type __s, size_type __d, const Cap &__u = 1)
        : src(__s), dst(__d), cap(__u) {
      assert(!(cap < static_cast<Cap>(0)));
    }

    
    template <class Os>
    friend Os &operator<<(Os &__os, id4 const &__e) {
      return __os << __e.src << ' ' << __e.dst << ' ' << __e.cap << ' '
                  << __e.flow;
    }

   protected:
    id4() = default;

    id4(size_type __s, size_type __d, const Cap &__u,
                    const Cap &__f)
        : src(__s), dst(__d), cap(__u), flow(__f) {}

    id4 make_rev() const { return {dst, src, flow, cap}; }
  };

  class weighted_edge : public id4 {
   public:
    Cost cost;  


    weighted_edge(const id4 &__e, const Cost &__c = 0)
        : id4(__e), cost(__c) {}

    weighted_edge(size_type __s, size_type __d, const Cap &__u = 1,
                  const Cost &__c = 0)
        : id4(__s, __d, __u), cost(__c) {}

    
    template <class Os>
    friend Os &operator<<(Os &__os, weighted_edge const &__e) {
      return __os << static_cast<id4>(__e) << ' ' << __e.cost;
    }

   protected:
    weighted_edge() = default;

    weighted_edge make_rev() const {
      return {id4::make_rev(), -cost};
    }
  };

  using edge = typename std::conditional<std::is_void<Cost>::value,
                                         id4, weighted_edge>::type;

 protected:
  struct edge_impl : edge {
    bool aux = false;
    edge_impl *rev = nullptr;

    edge_impl() = default;

    edge_impl(const edge_impl &__e) = default;
    edge_impl &operator=(const edge_impl &__e) = default;

    edge_impl(edge_impl &&__e) = default;
    edge_impl &operator=(edge_impl &&__e) = default;

    edge_impl(const edge &__e) : edge(__e) {}
    edge_impl(edge &&__e) : edge(__e) {}

    void push(Cap __f) {
      edge::cap -= __f;
      edge::flow += __f;
      if (rev) {
        rev->cap += __f;
        rev->flow -= __f;
      }
    }

    edge_impl make_rev() {
      edge_impl __e = edge::make_rev();
      __e.aux = true;
      __e.rev = this;
      return __e;
    }
  };

 public:
  class adjacency {
   public:
    using value_type = edge;
    using reference = edge &;
    using const_reference = edge const &;
    using pointer = edge *;
    using const_pointer = const edge *;

    class iterator {
      edge_impl *__p;

     public:
      iterator(edge_impl *__p = nullptr) : __p(__p) {}

      bool operator!=(iterator const &__x) const { return __p != __x.__p; }

      iterator &operator++() {
        do ++__p;
        while (__p->rev && __p->aux);
        return *this;
      }

      pointer operator->() const { return __p; }

      reference operator*() const { return *__p; }

      bool operator==(const iterator &__x) const { return __p == __x.__p; }
    };

    class const_iterator {
      const edge_impl *__p;

     public:
      const_iterator(const edge_impl *__p = nullptr) : __p(__p) {}

      bool operator!=(const_iterator const &__x) const {
        return __p != __x.__p;
      }

      const_iterator &operator++() {
        do ++__p;
        while (__p->rev && __p->aux);
        return *this;
      }

      const_pointer operator->() const { return __p; }

      const_reference operator*() const { return *__p; }
    };

    adjacency()
        : first(new edge_impl[2]), last(first + 1), __s(first), __t(first) {}

    ~adjacency() { delete[] first; }

    const_reference operator[](size_type i) const {
      assert(i < size());
      return *(first + i);
    }

    size_type size() const { return __t - first; }

    auto begin() { return iterator{__s}; }
    auto begin() const { return const_iterator{__s}; }

    auto end() { return iterator{__t}; }
    auto end() const { return const_iterator{__t}; }

    
    adjacency(adjacency &&__x) : first(nullptr) { operator=(std::move(__x)); }

    
    adjacency &operator=(adjacency &&__x) {
      std::swap(first, __x.first);
      last = __x.last;
      __s = __x.__s;
      __t = __x.__t;
      return *this;
    }

   protected:
    edge_impl *first, *last, *__s, *__t;
  };

  using value_type = adjacency;
  using reference = adjacency &;
  using const_reference = adjacency const &;

 protected:
  class adjacency_impl : public adjacency {
   public:
    using base = adjacency;
    using base::__s;
    using base::__t;
    using base::first;
    using base::last;

    using iterator = edge_impl *;

    iterator _push(edge_impl &&__e) {
      if (__t == last) {
        size_type __n(last - first);
        iterator loc = new edge_impl[__n << 1 | 1];
        __s += loc - first;
        __t = loc;
        for (iterator __p{first}; __p != last; ++__p, ++__t) {
          *__t = *__p;
          if (__p->rev) __p->rev->rev = __t;
        }
        delete[] first;
        first = loc;
        last = __t + __n;
      }
      *__t = std::move(__e);
      if (__s->aux) ++__s;
      return __t++;
    }

    iterator begin() const { return first; }

    iterator end() const { return __t; }
  };

  
  container_type graph;

 public:
  
  flow_graph(size_type __n = 0) : graph(__n) {}

  
  flow_graph(const flow_graph &__x) : graph(__x.size()) {
    for (auto &&__adj : __x)
      for (auto &&__e : __adj) add_edge(__e);
  }

  
  flow_graph(flow_graph &&__x) : graph(std::move(__x.graph)) {}

  
  flow_graph &operator=(const flow_graph &__x) {
    return operator=(std::move(flow_graph{__x}));
  }

  
  flow_graph &operator=(flow_graph &&__x) {
    graph = std::move(__x.graph);
    return *this;
  }

  
  bool empty() const { return graph.empty(); }

  
  size_type size() const { return graph.size(); }

  
  reference operator[](size_type node) {
    assert(node < size());
    return graph[node];
  }

  
  const_reference operator[](size_type node) const {
    assert(node < size());
    return graph[node];
  }

  class iterator : public container_type::iterator {
    using base = typename container_type::iterator;

   public:
    using reference = adjacency &;
    using pointer = adjacency *;

    iterator(base const &__i) : base(__i) {}

    pointer operator->() const { return base::operator->(); }

    reference operator*() const { return base::operator*(); }
  };

  class const_iterator : public container_type::const_iterator {
    using base = typename container_type::const_iterator;

   public:
    using const_reference = const adjacency &;
    using const_pointer = const adjacency *;

    const_iterator(base const &__i) : base(__i) {}

    const_pointer operator->() const { return base::operator->(); }

    const_reference operator*() const { return base::operator*(); }
  };

  auto begin() { return iterator{graph.begin()}; }
  auto begin() const { return const_iterator{graph.begin()}; }

  auto end() { return iterator{graph.end()}; }
  auto end() const { return const_iterator{graph.end()}; }

  
  size_type add_node() { return add_nodes(1).front(); }

  
  virtual std::vector<size_type> add_nodes(size_type __n) {
    std::vector<size_type> __nds(__n);
    std::iota(__nds.begin(), __nds.end(), graph.size());
    __n += graph.size();
    if (__n > graph.capacity()) {
      flow_graph __x(__n);
      for (auto &&adj : graph)
        for (auto &&__e : adj)
          if (!__e.aux) __x.add_edge(__e);
      graph = std::move(__x.graph);
    } else
      graph.resize(__n);
    return __nds;
  }

  
  template <class... Args>
  typename std::enable_if<std::is_constructible<edge, Args...>::value,
                          edge &>::type
  add_edge(Args &&...__args) {
    edge_impl __e = edge(std::forward<Args>(__args)...);
    assert(__e.src < size());
    assert(__e.dst < size());
    edge_impl *__p = graph[__e.src]._push(std::move(__e));
    

    if (__e.src != __e.dst) __p->rev = graph[__e.dst]._push(__p->make_rev());
    return *__p;
  }

  
  template <class Tp>
  typename std::enable_if<
      (std::tuple_size<typename std::decay<Tp>::type>::value >= 0),
      edge &>::type
  add_edge(Tp &&__t) {
    return id6(std::forward<Tp>(__t));
  }

  
  template <class... Args> edge &id0(Args &&...__args) {
    edge_impl __e = edge(std::forward<Args>(__args)...);
    assert(__e.src < size());
    assert(__e.dst < size());
    (__e.flow += __e.flow) += __e.cap;
    edge_impl *__p = graph[__e.src]._push(std::move(__e));
    

    if (__e.src != __e.dst) {
      edge_impl __r = __p->make_rev();
      __r.aux = false;
      __p->rev = graph[__e.dst]._push(std::move(__r));
    }
    return *__p;
  }

  
  template <class Tp>
  typename std::enable_if<
      (std::tuple_size<typename std::decay<Tp>::type>::value >= 0),
      edge &>::type
  id0(Tp &&__t) {
    return id10(std::forward<Tp>(__t));
  }

 protected:
  

  template <class Tp, size_t N = 0, class... Args>
  decltype(auto) id6(Tp &&__t, Args &&...__args) {
    if constexpr (N == std::tuple_size<typename std::decay<Tp>::type>::value)
      return add_edge(std::forward<Args>(__args)...);
    else
      return id6<Tp, N + 1>(std::forward<Tp>(__t),
                                         std::forward<Args>(__args)...,
                                         std::get<N>(__t));
  }

  

  template <class Tp, size_t N = 0, class... Args>
  decltype(auto) id10(Tp &&__t, Args &&...__args) {
    if constexpr (N == std::tuple_size<typename std::decay<Tp>::type>::value)
      return id0(std::forward<Args>(__args)...);
    else
      return id10<Tp, N + 1>(std::forward<Tp>(__t),
                                           std::forward<Args>(__args)...,
                                           std::get<N>(__t));
  }

  template <class Os> friend Os &operator<<(Os &__os, flow_graph const &__g) {
    for (const auto &adj : __g)
      for (const auto &e : adj) __os << e << "\n";
    return __os;
  }
};

}  



namespace workspace {


template <class Cap, class Cost = Cap>
class id27 : public flow_graph<Cap, Cost> {
  using base = flow_graph<Cap, Cost>;
  using edge_impl = typename base::edge_impl;

 public:
  using edge = typename base::edge;
  using size_type = typename base::size_type;

  
  id27(size_type __n = 0) : base::flow_graph(__n), b(__n) {}

  std::vector<size_type> add_nodes(size_type __n) override {
    b.resize(b.size() + __n);
    return base::add_nodes(__n);
  }

  using base::add_edge;

  
  edge &add_edge(size_type __s, size_type __d, Cap __l, Cap __u, Cost __c) {
    assert(!(__u < __l));
    b[__s] -= __l;
    b[__d] += __l;
    auto &__e = base::add_edge(__s, __d, __u - __l, __c);
    __e.flow = __l;
    return __e;
  }

  
  template <class... Args> edge &id0(Args &&... __args) {
    auto &__e = static_cast<edge_impl &>(
        base::id0(std::forward<Args>(__args)...));
    assert(!(__e.cost < 0));
    __e.rev->cost = __e.cost;
    return __e;
  }

  
  void supply(size_type node, Cap __f = 1) {
    assert(node < b.size());
    b[node] += __f;
  }

  
  void demand(size_type node, Cap __f = 1) {
    assert(node < b.size());
    b[node] -= __f;
  }

  
  const auto &balance() const { return b; }

  
  Cap balance(size_type node) const { return b[node]; }

  
  const auto &potential() const { return p; }

  
  Cost potential(size_type node) const { return p[node]; }

  
  Cost cost() const { return current; }

  
  bool run() {
    p.resize(b.size());

    Cap delta = 0;
    for (auto &&__adj : base::graph)
      for (auto &&__e : __adj) delta = std::max(delta, __e.cap);
    if (delta == static_cast<Cap>(0))
      return std::all_of(b.begin(), b.end(),
                         [](Cap __x) { return __x == static_cast<Cap>(0); });

    parent.resize(b.size());

    while (static_cast<Cap>(0) < delta) {
      delta /= 2;

      for (auto &&__adj : base::graph)
        for (auto &&__e : __adj)
          if (delta < __e.cap && __e.cost < p[__e.dst] - p[__e.src]) {
            b[__e.src] -= __e.cap;
            b[__e.dst] += __e.cap;
            __e.push(__e.cap);
          }

      sources.clear();
      sinks.clear();
      for (size_type __v = 0; __v != b.size(); ++__v)
        if (delta < b[__v])
          sources.emplace_back(__v);
        else if (b[__v] < -delta)
          sinks.emplace_back(__v);

      while (dual(delta)) {
        primal(delta);
        sources.erase(
            std::remove_if(sources.begin(), sources.end(),
                           [&](auto __v) { return !(delta < b[__v]); }),
            sources.end());
        sinks.erase(
            std::remove_if(sinks.begin(), sinks.end(),
                           [&](auto __v) { return !(b[__v] < -delta); }),
            sinks.end());
      }
    }

    current = 0;
    for (auto &&__adj : base::graph)
      for (auto &&__e : __adj)
        if (!__e.aux) current += __e.cost * __e.flow;

    return sources.empty() && sinks.empty();
  }

 protected:
  

  Cost current{};

  

  std::vector<Cap> b;

  

  std::vector<Cost> p;

  std::vector<edge_impl *> parent;
  std::vector<size_type> sources, sinks;

  

  void primal(Cap delta) {
    for (auto __t : sinks)
      if (parent[__t]) {
        auto __f = -b[__t];
        auto __s = __t;
        while (parent[__s])
          __f = std::min(__f, parent[__s]->cap), __s = parent[__s]->src;
        if (delta < b[__s]) {
          __f = std::min(__f, b[__s]);
          b[__s] -= __f;
          b[__t] += __f;
          for (auto *__p = parent[__t]; __p; __p = parent[__p->src]) {
            __p->push(__f);
            parent[__p->dst] = nullptr;
          }
        }
      }
  }

  

  bool dual(Cap delta) {
    std::fill(parent.begin(), parent.end(), nullptr);
    size_type reachable = 0;

    struct state {
      size_type __v;
      Cost __d;
      state(size_type __v, Cost __d) : __v(__v), __d(__d) {}
      bool operator<(const state &__x) const { return __x.__d < __d; }
    };

    std::priority_queue<state> __q;
    decltype(p) __nx(p.size(), numeric_limits<Cost>::max());
    Cost __ld = 0;

    for (auto __v : sources) {
      __nx[__v] = p[__v];
      __q.emplace(__v, 0);
    }

    while (!__q.empty()) {
      auto [__v, __d] = __q.top();
      __q.pop();
      if (__d + p[__v] != __nx[__v]) continue;
      __ld = __d;
      if (b[__v] < -delta && ++reachable == sinks.size()) break;
      for (auto &__e : base::graph[__v])
        if (delta < __e.cap && (__d = __nx[__v] + __e.cost) < __nx[__e.dst]) {
          __q.emplace(__e.dst, (__nx[__e.dst] = __d) - p[__e.dst]);
          parent[__e.dst] = &__e;
        }
    }

    for (size_type __v = 0; __v != p.size(); ++__v)
      p[__v] = std::min(__nx[__v], p[__v] += __ld);

    return reachable;
  }

};  



template <class Cap, class Gain = Cap>
class max_gain_flow : public id27<Cap, Gain> {
  using base = id27<Cap, Gain>;
  using base::cost;

 public:
  using base::id27;
  using edge = typename base::edge;

  
  template <class... Args> decltype(auto) add_edge(Args &&... __args) {
    return add_edge(std::tuple<Args...>{std::forward<Args>(__args)...});
  }

  
  template <class Tp>
  typename std::enable_if<
      (std::tuple_size<typename std::decay<Tp>::type>::value >= 0),
      const edge &>::type
  add_edge(Tp __t) {
    std::get<std::tuple_size<decltype(__t)>::value - 1>(__t) *=
        -1;  

    return base::add_edge(std::move(__t));
  }

  
  Gain gain() const { return -cost(); }
};

}  



namespace workspace {

void main() {
  


  int d, n;
  cin >> d >> n;

  using mcf_type = id27<int, int>;
  id27<int, int> mcf;
  auto in = mcf.add_nodes(1 << d);
  auto out = mcf.add_nodes(1 << d);
  auto ext = mcf.add_node();

  vector<int> pwds(n);
  vector<int> need(1 << d);

  for (auto &&a : pwds) {
    string s;
    cin >> s;
    reverse(begin(s), end(s));

    for (auto &&c : s) {
      a <<= 1;
      a += c - '0';
    }

    need[a] = 1;
  }

  mcf.supply(in[0], n);
  mcf.demand(ext, n);
  mcf.add_edge(in[0], ext, n, 0);

  for (auto i : range(1 << d)) {
    mcf.add_edge(out[i], ext, n, 1);

    mcf.add_edge(in[i], out[i], need[i], n, 0);

    for (auto j : range(d)) {
      if (i >> j & 1) {
        mcf.add_edge(out[i ^ 1 << j], in[i], n, 1);
      }
    }
  }

  assert(mcf.run());

  vector<char> ans;

  vector<mcf_type::adjacency::iterator> iter(mcf.size());
  for (auto i : range(iter.size())) {
    iter[i] = mcf[i].begin();
  }

  while (1) {
    int now = 0;
    while (iter[out[now]] != mcf[out[now]].end() && !iter[out[now]]->flow)
      ++iter[out[now]];

    if (iter[out[now]] == mcf[out[now]].end()) break;

    while (now != ext) {
      auto &e = iter[out[now]];

      if (e->flow) {
        e->flow--;
        if (e->dst == ext)
          ans.emplace_back('R');
        else
          ans.push_back('0' + id14(now ^ e->dst));
        now = e->dst;
      }

      else {
        ++iter[out[now]];
      }
    }
  }

  assert(ans.size() == mcf.cost());
  ans.pop_back();

  cout << ans.size() << "\n";
  cout << ans << "\n";
}

}  

