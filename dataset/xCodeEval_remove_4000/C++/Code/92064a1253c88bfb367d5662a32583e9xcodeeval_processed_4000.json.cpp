


























namespace std {

template <typename _Tp> constexpr int id2(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id17 = numeric_limits<unsigned long long>::digits;
  constexpr auto id32 = numeric_limits<unsigned long>::digits;
  constexpr auto id19 = numeric_limits<unsigned>::digits;

  if
    id29(_Nd <= id19) {
      constexpr int __diff = id19 - _Nd;
      return __builtin_clz(__x) - __diff;
    }
  else if
    id29(_Nd <= id32) {
      constexpr int __diff = id32 - _Nd;
      return __builtin_clzl(__x) - __diff;
    }
  else if
    id29(_Nd <= id17) {
      constexpr int __diff = id17 - _Nd;
      return __builtin_clzll(__x) - __diff;
    }
  else  

  {
    static_assert(_Nd <= (2 * id17),
                  "Maximum supported integer size is 128-bit");

    unsigned long long __high = __x >> id17;
    if (__high != 0) {
      constexpr int __diff = (2 * id17) - _Nd;
      return __builtin_clzll(__high) - __diff;
    }
    constexpr auto id14 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id14;
    return (_Nd - id17) + __builtin_clzll(__low);
  }
}

template <typename _Tp> constexpr int id36(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id17 = numeric_limits<unsigned long long>::digits;
  constexpr auto id32 = numeric_limits<unsigned long>::digits;
  constexpr auto id19 = numeric_limits<unsigned>::digits;

  if
    id29(_Nd <= id19)
  return __builtin_ctz(__x);
  else if id29(_Nd <= id32) return id1(__x);
  else if id29(_Nd <= id17) return id23(__x);
  else  

  {
    static_assert(_Nd <= (2 * id17),
                  "Maximum supported integer size is 128-bit");

    constexpr auto id14 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id14;
    if (__low != 0) return id23(__low);
    unsigned long long __high = __x >> id17;
    return id23(__high) + id17;
  }
}

template <typename _Tp> constexpr int id4(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return 0;

  constexpr auto id17 = numeric_limits<unsigned long long>::digits;
  constexpr auto id32 = numeric_limits<unsigned long>::digits;
  constexpr auto id19 = numeric_limits<unsigned>::digits;

  if
    id29(_Nd <= id19)
  return __builtin_popcount(__x);
  else if id29(_Nd <= id32) return id6(__x);
  else if id29(_Nd <= id17) return id12(__x);
  else  

  {
    static_assert(_Nd <= (2 * id17),
                  "Maximum supported integer size is 128-bit");

    constexpr auto id14 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id14;
    unsigned long long __high = __x >> id17;
    return id12(__low) + id12(__high);
  }
}

template <typename _Tp> constexpr _Tp id34(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0 || __x == 1) return 1;
  auto id7 = _Nd - id2((_Tp)(__x - 1u));

  if (!__builtin_is_constant_evaluated()) {
    __glibcxx_assert(id7 != numeric_limits<_Tp>::digits);
  }

  using __promoted_type = decltype(__x << 1);
  if
    id29(!is_same<__promoted_type, _Tp>::value) {
      const int id3 = sizeof(__promoted_type) / sizeof(_Tp) / 2;
      id7 |= (id7 & _Nd) << id3;
    }
  return (_Tp)1u << id7;
}

template <typename _Tp> constexpr _Tp id30(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0) return 0;
  return (_Tp)1u << (_Nd - id2((_Tp)(__x >> 1)));
}

template <typename _Tp> constexpr _Tp id24(_Tp __x) noexcept {
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

constexpr static char eol = '\n';

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
decltype(auto) id15(_Compare __x = _Compare()) noexcept {
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

template <typename _Tp> constexpr _Tp id13(_Tp __x) noexcept {
  return std::id36(__x);
}

template <typename _Tp> constexpr _Tp id10(_Tp __x) noexcept {
  return std::id24(__x) - 1;
}

}  
















namespace workspace {

namespace _impl {

template <class _Iter, class _Pred>
_Iter id35(_Iter __first, _Iter __last, _Pred &&__pred,
                             bool __crit) {
  if (__first < __last)
    while (1 < __last - __first) {
      _Iter __mid = __first + ((__last - __first) >> 1);
      (__pred(__mid) == __crit ? __first : __last) = __mid;
    }

  else
    while (1 < __first - __last) {
      _Iter __mid = __last + ((__first - __last) >> 1);
      (__pred(__mid) == __crit ? __first : __last) = __mid;
    }

  return __first;
}

template <class _Real, class _Pred>
_Real id28(_Real __first, _Real __last, _Real __eps,
                               _Pred &&__pred, bool __crit) {
  if (__first < __last)
    for (auto __loop = std::numeric_limits<_Real>::digits;
         __first + __eps < __last && __loop; --__loop) {
      _Real __mid = (__first + __last) / 2;
      (__pred(__mid) == __crit ? __first : __last) = __mid;
    }

  else
    for (auto __loop = std::numeric_limits<_Real>::digits;
         __last + __eps < __first && __loop; --__loop) {
      _Real __mid = (__first + __last) / 2;
      (__pred(__mid) == __crit ? __first : __last) = __mid;
    }

  return __first;
}

}  



template <class _Iter, class _Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<_Pred>()(std::declval<_Iter>())),
                        bool>::value,
    _Iter>::type
binary_search(_Iter __first, _Iter __last, _Pred &&__pred) {
  assert(__first != __last);

  return _impl::id35(
      __first, __last, std::forward<_Pred>(__pred), __pred(__first));
}


template <class _Real, class _Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<_Pred>()(std::declval<_Real>())),
                        bool>::value,
    _Real>::type
binary_search(_Real __first, _Real __last, _Real __eps, _Pred &&__pred) {
  assert(__first != __last);

  return _impl::id28(
      __first, __last, __eps, std::forward<_Pred>(__pred), __pred(__first));
}


template <class Array,
          class _Iter = typename std::decay<
              decltype(std::get<0>(std::declval<Array>()[0]))>::type,
          class _Pred>
typename std::enable_if<
    std::is_convertible<
        decltype(std::declval<_Pred>()(std::declval<std::vector<_Iter>>())[0]),
        bool>::value,
    std::vector<_Iter>>::type
id16(Array ends, _Pred __pred) {
  std::vector<_Iter> mids(std::size(ends));
  for (;;) {
    bool all_found = true;
    for (size_t i{}; i != std::size(ends); ++i) {
      const _Iter &__first = std::get<0>(ends[i]);
      const _Iter &__last = std::get<1>(ends[i]);
      const _Iter mid(
          __first + typename std::make_signed<decltype(__last - __first)>::type(
                        __last - __first) /
                        2);
      if (mids[i] != mid) {
        all_found = false;
        mids[i] = mid;
      }
    }
    if (all_found) break;
    const auto res = __pred(mids);
    for (size_t i{}; i != std::size(ends); ++i) {
      (res[i] ? std::get<0>(ends[i]) : std::get<1>(ends[i])) = mids[i];
    }
  }
  return mids;
}


template <class Array,
          class _Real = typename std::decay<
              decltype(std::get<0>(std::declval<Array>()[0]))>::type,
          class _Pred>
typename std::enable_if<
    std::is_convertible<
        decltype(std::declval<_Pred>()(std::declval<std::vector<_Real>>())[0]),
        bool>::value,
    std::vector<_Real>>::type
id16(Array ends, const _Real eps, _Pred __pred) {
  std::vector<_Real> mids(std::size(ends));
  for (auto loops = 0; loops != std::numeric_limits<_Real>::digits; ++loops) {
    bool all_found = true;
    for (size_t i{}; i != std::size(ends); ++i) {
      const _Real __first = std::get<0>(ends[i]);
      const _Real __last = std::get<1>(ends[i]);
      if (__first + eps < __last || __last + eps < __first) {
        all_found = false;
        mids[i] = (__first + __last) / 2;
      }
    }
    if (all_found) break;
    const auto res = __pred(mids);
    for (size_t i{}; i != std::size(ends); ++i) {
      (res[i] ? std::get<0>(ends[i]) : std::get<1>(ends[i])) = mids[i];
    }
  }
  return mids;
}

}  







namespace workspace {


template <class _Iter, class _Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<_Pred>()(std::declval<_Iter>())),
                        bool>::value,
    _Iter>::type
id8(_Iter __first, _Iter __last, _Pred&& __pred) {
  assert(__first != __last);

  bool __crit = __pred(__first);

  if (__first < __last) {
    for (decltype(__last - __first) __step = 1; __step < __last - __first;
         __step <<= 1)
      if (__pred(__first += __step) != __crit)
        return _impl::id35(
            __first - __step, __first, std::forward<_Pred>(__pred), __crit);
  }

  else {
    for (decltype(__first - __last) __step = 1; __step < __first - __last;
         __step <<= 1)
      if (__pred(__first -= __step) != __crit)
        return _impl::id35(
            __first + __step, __first, std::forward<_Pred>(__pred), __crit);
  }

  return _impl::id35(__first, __last,
                                       std::forward<_Pred>(__pred), __crit);
}


template <class _Real, class _Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<_Pred>()(std::declval<_Real>())),
                        bool>::value,
    _Real>::type
id8(_Real __first, _Real __last, _Real __eps, _Pred&& __pred) {
  bool __crit = __pred(__first);

  if (__first < __last) {
    for (_Real __step = __eps; __step < __last - __first; __step += __step)
      if (__pred(__first += __step) != __crit)
        return _impl::id28(__first - __step, __first, __eps,
                                               std::forward<_Pred>(__pred),
                                               __crit);
  }

  else {
    for (_Real __step = __eps; __step < __first - __last; __step += __step)
      if (__pred(__first -= __step) != __crit)
        return _impl::id28(__first + __step, __first, __eps,
                                               std::forward<_Pred>(__pred),
                                               __crit);
  }

  return _impl::id28(__first, __last, __eps,
                                         std::forward<_Pred>(__pred), __crit);
}

}  







namespace workspace {


template <class _Iterator, class _Function>
std::enable_if_t<
    std::is_void<std::__void_t<decltype(std::declval<_Iterator>() -
                                        std::declval<_Iterator>())>>::value,
    _Iterator>
id31(_Iterator __first, _Iterator __last, _Function&& __f) {
  if (__last - __first < 2) return __first;

  decltype(__last - __first) __a{1}, __b{2};
  while (__a + __b <= __last - __first) __b ^= __a ^= __b ^= __a += __b;

  auto id21 = __f(__last - __b), id11 = __f(__last - __a);

  while (__a != 1) {
    __a ^= __b ^= __a ^= __b -= __a;

    if (id11 < id21)
      id21 = id11, id11 = __f(__last - __a);

    else if ((__last -= __b) - __first < __b)
      __a ^= __b ^= __a ^= __b -= __a, id11 = __f(__last - __a);

    else
      id11 = id21, id21 = __f(__last - __b);
  }

  return id21 < id11 ? __last - __b : __last - __a;
}

}  







namespace workspace {


template <class Iter, class Comp>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Comp>()(std::declval<Iter>(),
                                                      std::declval<Iter>())),
                        bool>::value,
    Iter>::type
id5(Iter first, Iter last, Comp comp) {
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
id5(Iter const &first, Iter const &last, Func func) {
  return id5(first, last, [&](Iter const &__i, Iter const &__j) {
    return func(__i) < func(__j);
  });
}


template <class Real, class Comp>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Comp>()(std::declval<Real>(),
                                                      std::declval<Real>())),
                        bool>::value,
    Real>::type
id5(Real first, Real last, Real const &eps, Comp comp) {
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
id5(Real const &first, Real const &last, Real const &eps,
               Func func) {
  return id5(
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


template <class _F> class fixed_point {
  _F __fn;

 public:
  
  fixed_point(_F __fn) noexcept : __fn(std::forward<_F>(__fn)) {}

  
  template <class... _Args> decltype(auto) operator()(_Args &&...__args) const {
    return __fn(*this, std::forward<_Args>(__args)...);
  }
};

}  



namespace workspace {

namespace _cached_impl {



template <class... _Args> struct get_tuple {
  using type = decltype(
      std::tuple_cat(std::declval<std::tuple<std::conditional_t<
                         std::is_convertible<std::decay_t<_Args>, _Args>::value,
                         std::decay_t<_Args>, _Args>>>()...));
};



template <class _Value, class... _Keys>
struct assoc
    : std::integral_constant<int, !std::is_void<_Value>::value>,
      std::conditional_t<std::is_void<_Value>::value,
                         std::set<typename get_tuple<_Keys...>::type>,
                         std::map<typename get_tuple<_Keys...>::type, _Value>> {
};



template <class _F, class = void> struct is_recursive : std::false_type {};



template <class _F>
struct is_recursive<
    _F, std::__void_t<decltype(&_F::template operator()<fixed_point<_F> &>)>>
    : std::true_type {};



template <class _F> class _recursive {
  template <class...> struct _cache;

  template <class _G, class _R, class _H, class... _Args>
  struct _cache<_R (_G::*)(_H, _Args...)> : assoc<_R, _Args...> {};

  template <class _G, class _R, class _H, class... _Args>
  struct _cache<_R (_G::*)(_H, _Args...) const> : assoc<_R, _Args...> {};

 public:
  using cache = _cache<decltype(&_F::template operator()<_recursive<_F> &>)>;

  _recursive(_F __x) noexcept : __fn(__x), __cptr(new cache) {}

  
  template <class... _Args> decltype(auto) operator()(_Args &&...__args) {
    typename cache::key_type __key{__args...};

    if constexpr (cache::value) {
      if (auto __i = __cptr->lower_bound(__key);
          __i != __cptr->end() && __i->first == __key)
        return __i->second;

      else
        return __cptr
            ->emplace_hint(__i, std::move(__key),
                           __fn(*this, std::forward<_Args>(__args)...))
            ->second;
    }

    else if (auto __i = __cptr->lower_bound(__key);
             __i == __cptr->end() || *__i != __key)
      __cptr->emplace_hint(__i, std::move(__key)),
          __fn(*this, std::forward<_Args>(__args)...);
  }

 private:
  _F __fn;
  std::shared_ptr<cache> __cptr;
};



template <class _F> class _non_recursive {
  template <class _T, class = void> struct _get_func { using type = _T; };

  template <class _T>
  struct _get_func<_T, std::__void_t<decltype(&_T::operator())>> {
    using type = decltype(&_T::operator());
  };

  template <class...> struct _cache;

  template <class _R, class... _Args>
  struct _cache<_R(_Args...)> : assoc<_R, _Args...> {};

  template <class _R, class... _Args>
  struct _cache<_R (*)(_Args...)> : assoc<_R, _Args...> {};

  template <class _G, class _R, class... _Args>
  struct _cache<_R (_G::*)(_Args...)> : assoc<_R, _Args...> {};

  template <class _G, class _R, class... _Args>
  struct _cache<_R (_G::*)(_Args...) const> : assoc<_R, _Args...> {};

 public:
  using cache = _cache<typename _get_func<_F>::type>;

  _non_recursive(_F __x) noexcept : __fn(__x), __cptr(new cache) {}

  
  template <class... _Args> decltype(auto) operator()(_Args &&...__args) {
    typename cache::key_type __key{__args...};

    if constexpr (cache::value) {
      if (auto __i = __cptr->lower_bound(__key);
          __i != __cptr->end() && __i->first == __key)
        return __i->second;

      else
        return __cptr
            ->emplace_hint(__i, std::move(__key),
                           __fn(std::forward<_Args>(__args)...))
            ->second;
    }

    else if (auto __i = __cptr->lower_bound(__key);
             __i == __cptr->end() || *__i != __key)
      __cptr->emplace_hint(__i, std::move(__key)),
          __fn(std::forward<_Args>(__args)...);
  }

 private:
  _F __fn;
  std::shared_ptr<cache> __cptr;
};

template <class _F>
using _cached = std::conditional_t<is_recursive<_F>::value, _recursive<_F>,
                                   _non_recursive<_F>>;

}  



template <class _F> class cached : public _cached_impl::_cached<_F> {
 public:
  
  cached() noexcept : _cached_impl::_cached<_F>(_F{}) {}

  
  cached(_F __x) noexcept : _cached_impl::_cached<_F>(__x) {}
};

}  







namespace workspace {


template <class _C1, class _C2>
constexpr decltype(auto) cat(_C1 &&id27, _C2 &&id18) noexcept {
  auto __c = std::forward<_C1>(id27);

  if constexpr (std::is_rvalue_reference<decltype(id18)>::value)
    __c.insert(std::end(__c), std::move_iterator(std::begin(id18)),
               std::move_iterator(std::end(id18)));

  else
    __c.insert(std::end(__c), std::cbegin(id18), std::cend(id18));

  return __c;
}


template <class _C1, class _C2, class... _Args>
constexpr decltype(auto) cat(_C1 &&id27, _C2 &&id18,
                             _Args &&...__args) noexcept {
  return cat(cat(std::forward<_C1>(id27), std::forward<_C2>(id18)),
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
using element_type = typename std::decay<decltype(
    *std::begin(std::declval<Container&>()))>::type;

template <class _Tp, class = std::nullptr_t>
struct has_begin : std::false_type {};

template <class _Tp>
struct has_begin<_Tp, decltype(std::begin(std::declval<_Tp>()), nullptr)>
    : std::true_type {};

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

}  



namespace workspace {


template <class _Tp>
bool compare_arg(const _Tp& id9, const _Tp& id25) noexcept {
  const auto& [__x1, __y1] = id9;
  const auto& [__x2, __y2] = id25;

  using value_type = std::decay_t<decltype(__x1)>;
  using mul_type = typename multiplicable<value_type>::type;

  if (__y1 == value_type(0))
    return value_type(0) <= __x1 &&
           (value_type(0) < __y2 ||
            (__y2 == value_type(0) && __x2 < value_type(0)));

  return value_type(0) < __y1
             ? value_type(0) <= __y2 &&
                   mul_type(__y1) * __x2 < mul_type(__x1) * __y2
             : value_type(0) <= __y2 ||
                   mul_type(__y1) * __x2 < mul_type(__x1) * __y2;
}

}  






namespace workspace {
template <class T, class = void> struct hash : std::hash<T> {};

template <class _Tp> struct hash<_Tp *> : std::hash<_Tp *> {};


template <class Unique_bits_type>
struct hash<Unique_bits_type,
            enable_if_trait_type<Unique_bits_type,
                                 std::has_unique_object_representations>> {
  size_t operator()(uint64_t x) const {
    static const uint64_t m = std::random_device{}();
    x ^= x >> 23;
    x ^= m;
    x ^= x >> 47;
    return x - (x >> 32);
  }
};


template <class Key> size_t id22(const size_t &seed, const Key &key) {
  return seed ^
         (hash<Key>()(key) + 0x9e3779b9 );
}
template <class T1, class T2> struct hash<std::pair<T1, T2>> {
  size_t operator()(const std::pair<T1, T2> &pair) const {
    return id22(hash<T1>()(pair.first), pair.second);
  }
};
template <class... T> class hash<std::tuple<T...>> {
  template <class Tuple, size_t index = std::tuple_size<Tuple>::value - 1>
  struct tuple_hash {
    static uint64_t apply(const Tuple &t) {
      return id22(tuple_hash<Tuple, index - 1>::apply(t),
                          std::get<index>(t));
    }
  };
  template <class Tuple> struct tuple_hash<Tuple, size_t(-1)> {
    static uint64_t apply(const Tuple &t) { return 0; }
  };

 public:
  uint64_t operator()(const std::tuple<T...> &t) const {
    return tuple_hash<std::tuple<T...>>::apply(t);
  }
};
template <class hash_table> struct hash_table_wrapper : hash_table {
  using key_type = typename hash_table::key_type;
  size_t count(const key_type &key) const {
    return hash_table::find(key) != hash_table::end();
  }
  template <class... Args> auto emplace(Args &&... args) {
    return hash_table::insert(typename hash_table::value_type(args...));
  }
};
template <class Key, class Mapped = __gnu_pbds::null_type>
using cc_hash_table =
    hash_table_wrapper<__gnu_pbds::cc_hash_table<Key, Mapped, hash<Key>>>;
template <class Key, class Mapped = __gnu_pbds::null_type>
using gp_hash_table =
    hash_table_wrapper<__gnu_pbds::gp_hash_table<Key, Mapped, hash<Key>>>;
template <class Key, class Mapped>
using unordered_map = std::unordered_map<Key, Mapped, hash<Key>>;
template <class Key> using unordered_set = std::unordered_set<Key, hash<Key>>;
}  











namespace workspace {

namespace _istream_impl {

template <class _Tp, typename = std::nullptr_t> struct istream_helper {
  istream_helper(std::istream &__is, _Tp &__x) {
    if constexpr (has_begin<_Tp>::value)
      for (auto &&__e : __x)
        istream_helper<std::decay_t<decltype(__e)>>(__is, __e);
    else
      static_assert(has_begin<_Tp>::value, "istream unsupported type.");
  }
};

template <class _Tp>
struct istream_helper<
    _Tp,
    decltype(std::declval<std::decay_t<decltype(
                 std::declval<std::istream &>() >> std::declval<_Tp &>())>>(),
             nullptr)> {
  istream_helper(std::istream &__is, _Tp &__x) { __is >> __x; }
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
  istream_helper(std::istream &__is, std::pair<T1, T2> &__x) {
    istream_helper<T1>(__is, __x.first), istream_helper<T2>(__is, __x.second);
  }
};

template <class... Tps> struct istream_helper<std::tuple<Tps...>> {
  istream_helper(std::istream &__is, std::tuple<Tps...> &__x) {
    iterate(__is, __x);
  }

 private:
  template <class _Tp, size_t N = 0>
  void iterate(std::istream &__is, _Tp &__x) {
    if constexpr (N == std::tuple_size<_Tp>::value)
      return;
    else
      istream_helper<typename std::tuple_element<N, _Tp>::type>(
          __is, std::get<N>(__x)),
          iterate<_Tp, N + 1>(__is, __x);
  }
};

}  



class istream : public std::istream {
 public:
  
  template <typename _Tp> istream &operator>>(_Tp &__x) {
    _istream_impl::istream_helper<_Tp>(*this, __x);
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
    !std::is_same<std::decay_t<_Container>, std::string>::value &&
        !std::is_same<std::decay_t<_Container>, char *>::value,
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


template <class _Grid,
          typename = decltype(std::declval<std::decay_t<_Grid>>()[0].resize(0))>
constexpr decltype(auto) transpose(_Grid &&__grid) noexcept {
  auto __h = std::size(__grid), __w = std::size(__grid[0]);

  std::decay_t<_Grid> __t(__w);
  for (auto &&__r : __t) __r.resize(__h);

  for (size_t __i = 0; __i != __h; ++__i)
    for (size_t __j = 0; __j != __w; ++__j)
      if constexpr (std::is_rvalue_reference<decltype(__grid)>::value)
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


template <class _Grid> decltype(auto) id33(_Grid &&__grid) noexcept {
  if constexpr (std::is_rvalue_reference<decltype(__grid)>::value) {
    auto __t = transpose(std::move(__grid));
    std::reverse(std::begin(__t), std::end(__t));
    return __t;
  }

  else {
    auto __t = transpose(__grid);
    std::reverse(std::begin(__t), std::end(__t));
    return __t;
  }
}


template <class _Grid> decltype(auto) id20(_Grid &&__grid) noexcept {
  if constexpr (std::is_rvalue_reference<decltype(__grid)>::value) {
    std::reverse(std::begin(__grid), std::end(__grid));
    return transpose(std::move(__grid));
  }

  else {
    auto __t = transpose(__grid);
    for (auto &&__r : __t) std::reverse(std::begin(__r), std::end(__r));
    return __t;
  }
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


template <typename _Tp, class _Dim, size_t _Nm>
constexpr decltype(auto) make_vector([[maybe_unused]] _Dim* __dim,
                                     const _Tp& __x = _Tp()) {
  static_assert(std::is_convertible<_Dim, size_t>::value);

  if constexpr (_Nm)
    return std::vector(*__dim,
                       make_vector<_Tp, _Dim, _Nm - 1>(std::next(__dim), __x));
  else
    return __x;
}


template <typename _Tp, class _Dim, size_t _Nm>
constexpr decltype(auto) make_vector(const _Dim (&__dim)[_Nm],
                                     const _Tp& __x = _Tp()) {
  return make_vector<_Tp, _Dim, _Nm>((_Dim*)__dim, __x);
}


template <typename _Tp, class _Dim, size_t _Nm = 0>
constexpr decltype(auto) make_vector([[maybe_unused]] const _Dim& __dim,
                                     const _Tp& __x = _Tp()) {
  if constexpr (_Nm == std::tuple_size<_Dim>::value)
    return __x;

  else {
    static_assert(
        std::is_convertible<std::tuple_element_t<_Nm, _Dim>, size_t>::value);

    return std::vector(std::get<_Nm>(__dim),
                       make_vector<_Tp, _Dim, _Nm + 1>(__dim, __x));
  }
}

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

    constexpr iterator(const _Index &__i = _Index()) noexcept : current(__i) {}

    constexpr bool operator==(const iterator &__x) const noexcept {
      return current == __x.current;
    }
    constexpr bool operator!=(const iterator &__x) const noexcept {
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

  constexpr size_t size() const noexcept {
    return std::distance(__first, __last);
  }
};

template <class... _Args>
constexpr decltype(auto) rrange(_Args &&...__args) noexcept {
  return reversed(range(std::forward<_Args>(__args)...));
}

template <class _Container>
constexpr decltype(auto) iterate(_Container &&__cont) noexcept {
  return range(std::begin(__cont), std::end(__cont));
}

template <class _Container>
constexpr decltype(auto) riterate(_Container &&__cont) noexcept {
  return range(std::rbegin(__cont), std::rend(__cont));
}

}  












namespace workspace {

template <typename _Arithmetic>
using uniform_distribution = typename std::conditional<
    std::is_integral<_Arithmetic>::value,
    std::uniform_int_distribution<_Arithmetic>,
    std::uniform_real_distribution<_Arithmetic>>::type;

template <typename _Arithmetic, class _Engine = std::mt19937>
class id26 : uniform_distribution<_Arithmetic> {
  using base = uniform_distribution<_Arithmetic>;

  _Engine __engine;

 public:
  id26(_Arithmetic __min, _Arithmetic __max)
      : base(__min, __max), __engine(std::random_device{}()) {}

  id26(_Arithmetic __max = 1)
      : id26(0, __max) {}

  id26(typename base::param_type const& __param)
      : base(__param), __engine(std::random_device{}()) {}

  decltype(auto) operator()() noexcept { return base::operator()(__engine); }
};

}  







namespace workspace {

template <class _RAIter, class _Engine = std::mt19937>
void shuffle(_RAIter __first, _RAIter __last) {
  static _Engine __engine(std::random_device{}());
  std::shuffle(__first, __last, __engine);
}

}  







namespace workspace {

auto random_tree(std::size_t __n) {
  std::vector<std::pair<std::size_t, std::size_t>> __edges;
  id26 rng(std::size_t(0), __n);
  for (std::size_t __i = 1; __i != __n; ++__i)
    __edges.emplace_back(__i + 1, rng() % __i + 1);
  return __edges;
}

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



signed main() {
  using namespace workspace;

  


  

  

  return case_info.iterate();
}

namespace workspace {

void main() {
  


  int n;
  cin >> n;
  n = id31(1, n + 1, [](int x) {
    cout << "? " << x << endl;
    cin >> x;
    return x;
  });
  cout << "! " << n << endl;
}

}  

