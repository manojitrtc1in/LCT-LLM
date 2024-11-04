

























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

template <typename _Tp> constexpr _Tp id22(_Tp __x, int __s) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  const int __r = __s % _Nd;
  if (__r == 0)
    return __x;
  else if (__r > 0)
    return (__x >> __r) | (__x << ((_Nd - __r) % _Nd));
  else
    return (__x << -__r) | (__x >> ((_Nd + __r) % _Nd));  

}

template <typename _Tp> constexpr int id1(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id17 = numeric_limits<unsigned long long>::digits;
  constexpr auto id26 = numeric_limits<unsigned long>::digits;
  constexpr auto id19 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id19) {
    constexpr int __diff = id19 - _Nd;
    return __builtin_clz(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= id26) {
    constexpr int __diff = id26 - _Nd;
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

template <typename _Tp> constexpr int id7(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return id1<_Tp>((_Tp)~__x);
}

template <typename _Tp> constexpr int id28(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id17 = numeric_limits<unsigned long long>::digits;
  constexpr auto id26 = numeric_limits<unsigned long>::digits;
  constexpr auto id19 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id19)
    return __builtin_ctz(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id26)
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

template <typename _Tp> constexpr int id5(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return id28((_Tp)~__x);
}

template <typename _Tp> constexpr int id3(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return 0;

  constexpr auto id17 = numeric_limits<unsigned long long>::digits;
  constexpr auto id26 = numeric_limits<unsigned long>::digits;
  constexpr auto id19 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id19)
    return __builtin_popcount(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id26)
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

template <typename _Tp> constexpr bool id4(_Tp __x) noexcept {
  return id3(__x) == 1;
}

template <typename _Tp> constexpr _Tp id27(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0 || __x == 1) return 1;
  auto id8 = _Nd - id1((_Tp)(__x - 1u));

  if (!__builtin_is_constant_evaluated()) {
    __glibcxx_assert(id8 != numeric_limits<_Tp>::digits);
  }

  using __promoted_type = decltype(__x << 1);
  if _GLIBCXX17_CONSTEXPR (!is_same<__promoted_type, _Tp>::value) {
    const int id2 = sizeof(__promoted_type) / sizeof(_Tp) / 2;
    id8 |= (id8 & _Nd) << id2;
  }
  return (_Tp)1u << id8;
}

template <typename _Tp> constexpr _Tp id24(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0) return 0;
  return (_Tp)1u << (_Nd - id1((_Tp)(__x >> 1)));
}

template <typename _Tp> constexpr _Tp id20(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  return _Nd - id1(__x);
}

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




template <class T, class Comp = less<T>>
using priority_queue = std::priority_queue<T, vector<T>, Comp>;

template <class T> using stack = std::stack<T, vector<T>>;

template <typename _Tp> constexpr _Tp id14(_Tp __x) noexcept {
  return std::id28(__x);
}

template <typename _Tp> constexpr _Tp id12(_Tp __x) noexcept {
  return std::id20(__x) - 1;
}

}  


















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

template <typename _Tp> constexpr _Tp id22(_Tp __x, int __s) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  const int __r = __s % _Nd;
  if (__r == 0)
    return __x;
  else if (__r > 0)
    return (__x >> __r) | (__x << ((_Nd - __r) % _Nd));
  else
    return (__x << -__r) | (__x >> ((_Nd + __r) % _Nd));  

}

template <typename _Tp> constexpr int id1(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id17 = numeric_limits<unsigned long long>::digits;
  constexpr auto id26 = numeric_limits<unsigned long>::digits;
  constexpr auto id19 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id19) {
    constexpr int __diff = id19 - _Nd;
    return __builtin_clz(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= id26) {
    constexpr int __diff = id26 - _Nd;
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

template <typename _Tp> constexpr int id7(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return id1<_Tp>((_Tp)~__x);
}

template <typename _Tp> constexpr int id28(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id17 = numeric_limits<unsigned long long>::digits;
  constexpr auto id26 = numeric_limits<unsigned long>::digits;
  constexpr auto id19 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id19)
    return __builtin_ctz(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id26)
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

template <typename _Tp> constexpr int id5(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return id28((_Tp)~__x);
}

template <typename _Tp> constexpr int id3(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return 0;

  constexpr auto id17 = numeric_limits<unsigned long long>::digits;
  constexpr auto id26 = numeric_limits<unsigned long>::digits;
  constexpr auto id19 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id19)
    return __builtin_popcount(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id26)
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

template <typename _Tp> constexpr bool id4(_Tp __x) noexcept {
  return id3(__x) == 1;
}

template <typename _Tp> constexpr _Tp id27(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0 || __x == 1) return 1;
  auto id8 = _Nd - id1((_Tp)(__x - 1u));

  if (!__builtin_is_constant_evaluated()) {
    __glibcxx_assert(id8 != numeric_limits<_Tp>::digits);
  }

  using __promoted_type = decltype(__x << 1);
  if _GLIBCXX17_CONSTEXPR (!is_same<__promoted_type, _Tp>::value) {
    const int id2 = sizeof(__promoted_type) / sizeof(_Tp) / 2;
    id8 |= (id8 & _Nd) << id2;
  }
  return (_Tp)1u << id8;
}

template <typename _Tp> constexpr _Tp id24(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0) return 0;
  return (_Tp)1u << (_Nd - id1((_Tp)(__x >> 1)));
}

template <typename _Tp> constexpr _Tp id20(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  return _Nd - id1(__x);
}

}  












namespace std {


template <typename _Tp, typename _Alloc, typename _Predicate>
inline typename vector<_Tp, _Alloc>::size_type erase_if(
    vector<_Tp, _Alloc>& __cont, _Predicate __pred) {
  const auto id11 = __cont.size();
  __cont.erase(remove_if(__cont.begin(), __cont.end(), __pred), __cont.end());
  return id11 - __cont.size();
}


template <typename _Tp, typename _Alloc, typename _Up>
inline typename vector<_Tp, _Alloc>::size_type erase(
    vector<_Tp, _Alloc>& __cont, const _Up& __value) {
  const auto id11 = __cont.size();
  __cont.erase(remove(__cont.begin(), __cont.end(), __value), __cont.end());
  return id11 - __cont.size();
}

}  


















namespace std {



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


template <class Iter, class Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Pred>()(std::declval<Iter>())),
                        bool>::value,
    Iter>::type
binary_search(Iter ok, Iter ng, Pred pred) {
  assert(ok != ng);
  typename std::make_signed<decltype(ng - ok)>::type dist(ng - ok);
  while (1 < dist || dist < -1) {
    const Iter mid(ok + dist / 2);
    if (pred(mid))
      ok = mid, dist -= dist / 2;
    else
      ng = mid, dist /= 2;
  }
  return ok;
}


template <class Real, class Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Pred>()(std::declval<Real>())),
                        bool>::value,
    Real>::type
binary_search(Real ok, Real ng, const Real eps, Pred pred) {
  assert(ok != ng);
  for (auto loops = 0; loops != std::numeric_limits<Real>::digits &&
                       (ok + eps < ng || ng + eps < ok);
       ++loops) {
    const Real mid{(ok + ng) / 2};
    (pred(mid) ? ok : ng) = mid;
  }
  return ok;
}


template <class Array,
          class Iter = typename std::decay<
              decltype(std::get<0>(std::declval<Array>()[0]))>::type,
          class Pred>
typename std::enable_if<
    std::is_convertible<
        decltype(std::declval<Pred>()(std::declval<std::vector<Iter>>())[0]),
        bool>::value,
    std::vector<Iter>>::type
id16(Array ends, Pred pred) {
  std::vector<Iter> mids(std::size(ends));
  for (;;) {
    bool all_found = true;
    for (size_t i{}; i != std::size(ends); ++i) {
      const Iter &ok = std::get<0>(ends[i]);
      const Iter &ng = std::get<1>(ends[i]);
      const Iter mid(
          ok + typename std::make_signed<decltype(ng - ok)>::type(ng - ok) / 2);
      if (mids[i] != mid) {
        all_found = false;
        mids[i] = mid;
      }
    }
    if (all_found) break;
    const auto res = pred(mids);
    for (size_t i{}; i != std::size(ends); ++i) {
      (res[i] ? std::get<0>(ends[i]) : std::get<1>(ends[i])) = mids[i];
    }
  }
  return mids;
}


template <class Array,
          class Real = typename std::decay<
              decltype(std::get<0>(std::declval<Array>()[0]))>::type,
          class Pred>
typename std::enable_if<
    std::is_convertible<
        decltype(std::declval<Pred>()(std::declval<std::vector<Real>>())[0]),
        bool>::value,
    std::vector<Real>>::type
id16(Array ends, const Real eps, Pred pred) {
  std::vector<Real> mids(std::size(ends));
  for (auto loops = 0; loops != std::numeric_limits<Real>::digits; ++loops) {
    bool all_found = true;
    for (size_t i{}; i != std::size(ends); ++i) {
      const Real ok = std::get<0>(ends[i]);
      const Real ng = std::get<1>(ends[i]);
      if (ok + eps < ng || ng + eps < ok) {
        all_found = false;
        mids[i] = (ok + ng) / 2;
      }
    }
    if (all_found) break;
    const auto res = pred(mids);
    for (size_t i{}; i != std::size(ends); ++i) {
      (res[i] ? std::get<0>(ends[i]) : std::get<1>(ends[i])) = mids[i];
    }
  }
  return mids;
}

}  







namespace workspace {


template <class Index, class Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Pred>()(std::declval<Index>())),
                        bool>::value,
    Index>::type
id9(Index range, Pred pred) {
  Index step(1);
  while (step < range && pred(step)) step <<= 1;
  if (range < step) step = range;
  return binary_search(Index(0), step, pred);
}


template <class Real, class Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Pred>()(std::declval<Real>())),
                        bool>::value,
    Real>::type
id9(Real range, Real const &eps, Pred pred) {
  Real step(1);
  while (step < range && pred(step)) step += step;
  if (range < step) step = range;
  return binary_search(Real(0), step, eps, pred);
}

}  








namespace workspace {


template <class Iter, class Comp>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Comp>()(std::declval<Iter>(),
                                                      std::declval<Iter>())),
                        bool>::value,
    Iter>::type
id6(Iter first, Iter last, Comp comp) {
  assert(first < last);
  typename std::make_signed<decltype(last - first)>::type dist(last - first);
  while (2 < dist) {
    Iter left(first + dist / 3), right(first + dist * 2 / 3);
    if (comp(left, right))
      last = right, dist = (dist + dist) / 3;
    else
      first = left, dist -= dist / 3;
  }
  if (1 < dist && comp(first + 1, first)) ++first;
  return first;
}


template <class Iter, class Func>
typename std::enable_if<
    std::is_same<decltype(std::declval<Func>()(std::declval<Iter>()), nullptr),
                 std::nullptr_t>::value,
    Iter>::type
id6(Iter const &first, Iter const &last, Func func) {
  return id6(first, last, [&](Iter const &__i, Iter const &__j) {
    return func(__i) < func(__j);
  });
}


template <class Real, class Comp>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Comp>()(std::declval<Real>(),
                                                      std::declval<Real>())),
                        bool>::value,
    Real>::type
id6(Real first, Real last, Real const &eps, Comp comp) {
  assert(first < last);
  while (eps < last - first) {
    Real left{(first * 2 + last) / 3}, right{(first + last * 2) / 3};
    if (comp(left, right))
      last = right;
    else
      first = left;
  }
  return first;
}


template <class Real, class Func>
typename std::enable_if<
    std::is_same<decltype(std::declval<Func>()(std::declval<Real>()), nullptr),
                 std::nullptr_t>::value,
    Real>::type
id6(Real const &first, Real const &last, Real const &eps,
               Func func) {
  return id6(
      first, last, eps,
      [&](Real const &__i, Real const &__j) { return func(__i) < func(__j); });
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

template <class C1, class C2>
constexpr C1 &&cat(C1 &&id23, C2 const &id18) noexcept {
  id23.insert(id23.end(), std::begin(id18), std::end(id18));
  return id23;
}

}  







namespace workspace {


template <class Tp, class Comp = std::less<Tp>>
bool chle(Tp &x, const Tp &y, Comp comp = Comp()) {
  return comp(y, x) ? x = y, true : false;
}


template <class Tp, class Comp = std::less<Tp>>
bool chge(Tp &x, const Tp &y, Comp comp = Comp()) {
  return comp(x, y) ? x = y, true : false;
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

template <class Container>
using element_type = typename std::decay<decltype(
    *std::begin(std::declval<Container&>()))>::type;

template <class T, class = std::nullptr_t>
struct has_begin : std::false_type {};

template <class T>
struct has_begin<T, decltype(std::begin(std::declval<T>()), nullptr)>
    : std::true_type {};

template <class T, class = int> struct mapped_of {
  using type = element_type<T>;
};
template <class T>
struct mapped_of<T,
                 typename std::pair<int, typename T::mapped_type>::first_type> {
  using type = typename T::mapped_type;
};
template <class T> using mapped_type = typename mapped_of<T>::type;

template <class T, class = void> struct is_integral_ext : std::false_type {};
template <class T>
struct is_integral_ext<
    T, typename std::enable_if<std::is_integral<T>::value>::type>
    : std::true_type {};



template <> struct is_integral_ext<__int128_t> : std::true_type {};
template <> struct is_integral_ext<__uint128_t> : std::true_type {};





template <class T>
constexpr static bool id0 = is_integral_ext<T>::value;



template <typename T, typename = void> struct multiplicable_uint {
  using type = uint_least32_t;
};
template <typename T>
struct multiplicable_uint<
    T, typename std::enable_if<(2 < sizeof(T)) &&
                               (!__INT128_DEFINED__ || sizeof(T) <= 4)>::type> {
  using type = uint_least64_t;
};



template <typename T>
struct multiplicable_uint<T, typename std::enable_if<(4 < sizeof(T))>::type> {
  using type = __uint128_t;
};



template <typename T> struct multiplicable_int {
  using type =
      typename std::make_signed<typename multiplicable_uint<T>::type>::type;
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

namespace internal {
auto *const cin_ptr = (istream *)&std::cin;
}
auto &cin = *internal::cin_ptr;

}  







namespace workspace {


template <class Os, class T1, class T2>
Os &operator<<(Os &__os, const std::pair<T1, T2> &__p) {
  return __os << __p.first << ' ' << __p.second;
}


template <class Os, class Tp, size_t N = 0>
typename std::enable_if<bool(std::tuple_size<Tp>::value + 1), Os &>::type
operator<<(Os &__os, const Tp &__t) {
  if constexpr (N != std::tuple_size<Tp>::value) {
    if constexpr (N) __os << ' ';
    __os << std::get<N>(__t);
    operator<<<Os, Tp, N + 1>(__os, __t);
  }
  return __os;
}

template <class Os, class Container,
          typename = decltype(std::begin(std::declval<Container>()))>
typename std::enable_if<
    !std::is_same<typename std::decay<Container>::type, std::string>::value &&
        !std::is_same<typename std::decay<Container>::type, char *>::value,
    Os &>::type
operator<<(Os &__os, const Container &__cont) {
  bool __h = true;
  for (auto &&__e : __cont) __h ? __h = 0 : (__os << ' ', 0), __os << __e;
  return __os;
}




template <class Os> Os &operator<<(Os &__os, __int128_t __x) {
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


template <class Os> Os &operator<<(Os &__os, __uint128_t __x) {
  if (!__x) return __os << '0';
  char __s[40], *__p = __s;
  while (__x) *__p++ = '0' + __x % 10, __x /= 10;
  *__p = 0;
  for (char *__t = __s; __t < --__p; ++__t) *__t ^= *__p ^= *__t ^= *__p;
  return __os << __s;
}



}  










namespace workspace {


void io_setup(int precision) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout << std::fixed << std::setprecision(precision);


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


template <typename Tp, size_t N, typename S>
constexpr auto make_vector([[maybe_unused]] S* sizes, Tp const& init = Tp()) {
  static_assert(std::is_convertible_v<S, size_t>);
  if constexpr (N)
    return std::vector(*sizes,
                       make_vector<Tp, N - 1, S>(std::next(sizes), init));
  else
    return init;
}


template <typename Tp, size_t N, typename S>
constexpr auto make_vector(const S (&sizes)[N], Tp const& init = Tp()) {
  return make_vector<Tp, N, S>((S*)sizes, init);
}


template <typename Tp, size_t N, typename S, size_t I = 0>
constexpr auto make_vector([[maybe_unused]] std::array<S, N> const& sizes,
                           Tp const& init = Tp()) {
  static_assert(std::is_convertible_v<S, size_t>);
  if constexpr (I == N)
    return init;
  else
    return std::vector(sizes[I], make_vector<Tp, N, S, I + 1>(sizes, init));
}


template <typename Tp, size_t N = SIZE_MAX, size_t I = 0, class... Args>
constexpr auto make_vector([[maybe_unused]] std::tuple<Args...> const& sizes,
                           Tp const& init = Tp()) {
  using tuple_type = std::tuple<Args...>;
  if constexpr (I == std::tuple_size_v<tuple_type> || I == N)
    return init;
  else {
    static_assert(
        std::is_convertible_v<std::tuple_element_t<I, tuple_type>, size_t>);
    return std::vector(std::get<I>(sizes),
                       make_vector<Tp, N, I + 1>(sizes, init));
  }
}


template <typename Tp, class Fst, class Snd>
constexpr auto make_vector(std::pair<Fst, Snd> const& sizes,
                           Tp const& init = Tp()) {
  static_assert(std::is_convertible_v<Fst, size_t>);
  static_assert(std::is_convertible_v<Snd, size_t>);
  return make_vector({(size_t)sizes.first, (size_t)sizes.second}, init);
}

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

namespace internal {

template <class Container> class reversed {
  Container cont;

 public:
  constexpr reversed(Container &&cont) : cont(cont) {}

  constexpr auto begin() { return std::rbegin(cont); }
  constexpr auto end() { return std::rend(cont); }
};

}  


template <class Container> constexpr auto reversed(Container &&cont) noexcept {
  return internal::reversed<Container>{std::forward<Container>(cont)};
}

template <class Tp>
constexpr auto reversed(std::initializer_list<Tp> &&cont) noexcept {
  return internal::reversed<std::initializer_list<Tp>>{
      std::forward<std::initializer_list<Tp>>(cont)};
}

}  





namespace workspace {

template <class Index> class range {
  Index first, last;

 public:
  class iterator {
    Index current;

   public:
    using difference_type = std::ptrdiff_t;
    using value_type = Index;
    using reference = typename std::add_const<Index>::type &;
    using pointer = iterator;
    using iterator_category = std::bidirectional_iterator_tag;

    constexpr iterator(Index const &__i = Index()) noexcept : current(__i) {}

    constexpr bool operator==(iterator const &rhs) const noexcept {
      return current == rhs.current;
    }
    constexpr bool operator!=(iterator const &rhs) const noexcept {
      return current != rhs.current;
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

  constexpr range(Index first, Index last) noexcept
      : first(first), last(last) {}
  constexpr range(Index last) noexcept : first(), last(last) {}

  constexpr iterator begin() const noexcept { return iterator{first}; }
  constexpr iterator end() const noexcept { return iterator{last}; }

  constexpr reverse_iterator<iterator> rbegin() const noexcept {
    return reverse_iterator<iterator>(end());
  }
  constexpr reverse_iterator<iterator> rend() const noexcept {
    return reverse_iterator<iterator>(begin());
  }
};

template <class... Args> constexpr auto rrange(Args &&... args) noexcept {
  return internal::reversed(range(std::forward<Args>(args)...));
}

}  













namespace workspace {

namespace internal {

template <class> struct id25;

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
    using value_type = id25<base_tuple>;
    using reference = id25<base_tuple> &;
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

template <class Iter_tuple> struct id25 : Iter_tuple {
  constexpr id25(Iter_tuple const &__t) noexcept
      : Iter_tuple::tuple(__t) {}

  constexpr id25(id25 const &__t) = default;

  constexpr id25 &operator=(id25 const &__t) = default;

  

  constexpr id25(id25 &&__t)
      : id25(static_cast<id25 const &>(__t)) {}

  

  id25 &operator=(id25 &&__t) {
    return operator=(static_cast<id25 const &>(__t));
  }

  template <size_t N>
  friend constexpr auto &get(id25<Iter_tuple> const &__z) noexcept {
    return *std::get<N>(__z);
  }

  template <size_t N>
  friend constexpr auto get(id25<Iter_tuple> &&__z) noexcept {
    return *std::get<N>(__z);
  }
};

}  


}  


namespace std {

template <size_t N, class Iter_tuple>
struct tuple_element<N, workspace::internal::id25<Iter_tuple>> {
  using type = typename remove_reference<typename iterator_traits<
      typename tuple_element<N, Iter_tuple>::type>::reference>::type;
};

template <class Iter_tuple>
struct tuple_size<workspace::internal::id25<Iter_tuple>>
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

constexpr size_t min_size() noexcept { return SIZE_MAX; }

template <class Container, class... Args>
constexpr size_t min_size(Container const &cont, Args &&... args) noexcept {
  return std::min(std::size(cont), min_size(std::forward<Args>(args)...));
}

template <class... Args> constexpr auto enumerate(Args &&... args) noexcept {
  return zip(range(min_size(args...)), std::forward<Args>(args)...);
}

template <class... Args>
constexpr auto enumerate(std::initializer_list<Args> const &... args) noexcept {
  return zip(range(min_size(args...)), std::vector(args)...);
}

}  

















signed main() {
  using namespace workspace;

  io_setup(15);

  

  

  return case_info.iterate();
}

namespace workspace {

template <class Pair> Pair operator-(const Pair &id10, const Pair &id21) {
  return {id10.first - id21.first, id10.second - id21.second};
}

void main() {
  

  vector<tuple<i64, int, int>> pd;
  int n;
  cin >> n;
  vector<pair<int, int>> pts(n);
  cin >> pts;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      const auto v = pts[i] - pts[j];
      pd.emplace_back((i64)v.first * v.first + (i64)v.second * v.second, i, j);
    }
  }
  sort(rbegin(pd), rend(pd));

  vector<int> ans;
  vector<bool> usd(n);
  for (auto [s, i, j] : pd) {
    if (usd[i] || usd[j]) {
      continue;
    }
    usd[i] = usd[j] = 1;
    if (!ans.empty()) {
      

      auto k = ans.back();
      auto v1 = pts[i] - pts[k];
      auto v2 = pts[j] - pts[i];
      auto ip = (i64)v1.first * v2.first + (i64)v1.second * v2.second;
      if (ip >= 0) {
        swap(i, j);
      }
    }
    ans.emplace_back(i);
    if (i == j) {
      break;
    }
    ans.emplace_back(j);
  }

  assert(ans.size() == n);
  for (auto &&x : ans) {
    ++x;
  }
  cout << ans << "\n";
}

}  

