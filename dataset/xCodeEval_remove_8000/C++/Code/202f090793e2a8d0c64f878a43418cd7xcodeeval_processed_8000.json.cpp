























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



template <typename _Tp> constexpr _Tp id5(_Tp __x) noexcept {
  return std::__countr_zero(__x);
}

template <typename _Tp> constexpr _Tp id3(_Tp __x) noexcept {
  return std::__bit_width(__x) - 1;
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

struct monostate {};

template <class _Tp> class optional {
  _Tp __value;
  bool __has_value = false;

 public:
  constexpr operator bool() const noexcept { return __has_value; }
  constexpr bool has_value() const noexcept { return __has_value; }
  constexpr _Tp& value() noexcept { return __value; }
  constexpr const _Tp& value() const noexcept { return __value; }
};

}  










namespace workspace {


template <class _C1, class _C2>
constexpr decltype(auto) cat(_C1 &&id10, _C2 &&id7) noexcept {
  auto __c = std::forward<_C1>(id10);

  if _CXX17_CONSTEXPR (std::is_rvalue_reference<decltype(id7)>::value)
    __c.insert(std::end(__c), std::make_move_iterator(std::begin(id7)),
               std::make_move_iterator(std::end(id7)));
  else
    __c.insert(std::end(__c), std::cbegin(id7), std::cend(id7));

  return __c;
}


template <class _C1, class _C2, class... _Args>
constexpr decltype(auto) cat(_C1 &&id10, _C2 &&id7,
                             _Args &&...__args) noexcept {
  return cat(cat(std::forward<_C1>(id10), std::forward<_C2>(id7)),
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







namespace workspace {


template <class _F> class fixed_point {
  struct _wrapper {
    _F &__ref;

    template <class... _Args>
    decltype(auto) operator()(_Args &&...__args) noexcept(
        noexcept(__ref(*this, std::forward<_Args>(__args)...))) {
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

  constexpr decltype(auto) size() const noexcept {
    return

        __cont.size();

        std::size(__cont);

  }
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
    using iterator_category = std::random_access_iterator_tag;

    constexpr iterator(const _Index &__i = _Index()) noexcept : current(__i) {}

    constexpr bool operator==(const iterator &__x) const noexcept {
      return current == __x.current;
    }
    constexpr bool operator!=(const iterator &__x) const noexcept {
      return current != __x.current;
    }

    constexpr bool operator<(const iterator &__x) const noexcept {
      return current < __x.current;
    }
    constexpr bool operator<=(const iterator &__x) const noexcept {
      return current <= __x.current;
    }

    constexpr bool operator>(const iterator &__x) const noexcept {
      return current > __x.current;
    }
    constexpr bool operator>=(const iterator &__x) const noexcept {
      return current >= __x.current;
    }

    constexpr iterator &operator++() noexcept {
      ++current;
      return *this;
    }
    constexpr iterator &operator++(int) noexcept {
      auto __tmp = *this;
      ++current;
      return __tmp;
    }

    constexpr iterator &operator--() noexcept {
      --current;
      return *this;
    }
    constexpr iterator &operator--(int) noexcept {
      auto __tmp = *this;
      --current;
      return __tmp;
    }

    constexpr difference_type operator-(const iterator &__x) const noexcept {
      return current - __x.current;
    }

    constexpr iterator &operator+=(difference_type __x) noexcept {
      current += __x;
      return *this;
    }
    constexpr iterator operator+(difference_type __x) const noexcept {
      return iterator(*this) += __x;
    }

    constexpr iterator &operator-=(difference_type __x) noexcept {
      current -= __x;
      return *this;
    }
    constexpr iterator operator-(difference_type __x) const noexcept {
      return iterator(*this) -= __x;
    }

    constexpr reference operator*() const noexcept { return current; }
  };

  template <class _Tp1, class _Tp2>
  constexpr range(const _Tp1 &__first, const _Tp2 &__last) noexcept
      : __first(__first), __last(__last) {}

  template <class _Tp>
  constexpr range(const _Tp &__last) noexcept : __first(), __last(__last) {}

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

template <class _Tp1, class _Tp2>
range(const _Tp1 &, const _Tp2 &)
    -> range<std::decay_t<decltype(++std::declval<_Tp1 &>())>>;

template <class _Tp>
range(const _Tp &) -> range<std::decay_t<decltype(++std::declval<_Tp &>())>>;

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
class id9 : uniform_distribution<_Arithmetic> {
  using base = uniform_distribution<_Arithmetic>;

  _Engine __engine;

 public:
  id9(_Arithmetic __min, _Arithmetic __max)
      : base(__min, __max), __engine(std::random_device{}()) {}

  id9(_Arithmetic __max = 1)
      : id9(0, __max) {}

  id9(typename base::param_type const& __param)
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





signed main() {
  using namespace workspace;

  io_setup(15);

  

  case_info.read();  


  

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
    auto id5 = __z;

    for (auto __e = __r; __e != 1; --id5) (__e *= __e) %= __mod;

    while (++__shift != id5) (__b *= __b) %= __mod;

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



template <class _Tp, class _X> _Tp factorial(_X __x) noexcept {
  if (__x < 0) return 0;
  static std::vector<_Tp> __t{1};
  static size_t __i = (__t.reserve(0x1000000), 0);
  while (__i < size_t(__x)) __t.emplace_back(__t.back() * _Tp(++__i));
  return __t[__x];
}



template <class _Tp, class _X> _Tp id11(_X __x) noexcept {
  if (__x < 0) return 0;
  static std::vector<_Tp> __t{1};
  static size_t __i = (__t.reserve(0x1000000), 0);
  while (__i < size_t(__x)) __t.emplace_back(__t.back() / _Tp(++__i));
  return __t[__x];
}

}  



namespace workspace {

namespace _binom_impl {

struct id8 {
  constexpr static int size = 132;
  __uint128_t __b[size][size]{1};

  constexpr id8() noexcept {
    for (int __i = 1; __i != size; ++__i)
      for (int __j = 0; __j != __i; ++__j)
        __b[__i][__j] += __b[__i - 1][__j],
            __b[__i][__j + 1] += __b[__i - 1][__j];
  }

  constexpr auto operator()(int __x, int __y) const noexcept {
    return __x < 0 || __x < __y ? 0 : (assert(__x < size), __b[__x][__y]);
  }
};

constexpr id8 table;

}  



template <class _Tp, class _X = int_fast64_t, class _Y = int_fast64_t>
constexpr _Tp binomial(_X __x, _Y __y) {
  if constexpr (is_integral_ext<_Tp>::value)
    return _binom_impl::table(__x, __y);

  if (__y < 0 || __x < __y) return 0;

  return factorial<_Tp>(__x) * id11<_Tp>(__y) *
         id11<_Tp>(__x - __y);
}


template <class _Tp, class _X = int_fast64_t> constexpr _Tp id13(_X __x) {
  return __x < 0
             ? _Tp(0)
             : binomial<_Tp>(__x << 1, __x) - binomial<_Tp>(__x << 1, __x + 1);
}

}  

















namespace workspace {

template <class T, class E = T> struct id12 {
  using value_type = T;
  static T min, max;
  T value;
  id12() : value(max) {}
  id12(const T &value) : value(value) {}
  operator T() const { return value; }
  id12 operator+(const id12 &rhs) const {
    return value < rhs.value ? *this : rhs;
  }
  id12 operator*(const E &rhs) const;
};

template <class T, class E>
T id12<T, E>::min = std::numeric_limits<T>::min() / 2;
template <class T, class E>
T id12<T, E>::max = std::numeric_limits<T>::max() / 2;

template <class T, class E = T> struct id4 : id12<T, E> {
  using base = id12<T, E>;
  using base::id12;
  id4() : base(base::min) {}
  id4 operator+(const id4 &rhs) const {
    return !(base::value < rhs.value) ? *this : rhs;
  }
  id4 operator*(const E &rhs) const;
};

}  









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



namespace workspace {


template <class _Monoid, class _Endomorphism = void,
          template <class...> class Container_tmpl = std::vector>
class segment_tree {
  static_assert(has_binary_plus<_Monoid>::value,
                "\'_Monoid\' has no proper binary \'operator+\'.");

  constexpr static bool __support_lazy = !std::is_void<_Endomorphism>::value;


  struct node_base {
    node_base() = default;
    node_base(_Monoid const &__x) : __v(__x) {}
    operator bool() const { return __f; }
    void operator=(_Monoid const &__x) {
      __v = __x;
      __f = true;
    }
    _Monoid &operator*() { return __v; }
    _Monoid const &operator*() const { return __v; }
    void reset() { __f = false; }

   private:
    _Monoid __v{};
    bool __f{true};
  };

  struct node_base : std::optional<_Monoid> {
    using std::optional<_Monoid>::operator=;
    node_base() : std::optional<_Monoid>(_Monoid{}) {}
  };


  struct node_lazy : node_base {
    using node_base::operator=;
    

  };

  using node =
      typename std::conditional<__support_lazy, node_lazy, node_base>::type;

  using container_type = Container_tmpl<node>;

 public:
  using size_type = typename container_type::size_type;
  using difference_type = typename container_type::difference_type;

  using value_type = _Monoid;
  using reference = _Monoid &;
  using const_reference = _Monoid const &;

  class iterator {
    segment_tree *__p;
    size_type __i;

   public:
    using difference_type = segment_tree::difference_type;
    using value_type = _Monoid;
    using reference = _Monoid &;
    using pointer = iterator;
    using iterator_category = std::random_access_iterator_tag;

    
    iterator() = default;

    
    iterator(segment_tree *__p, size_type __i) : __p(__p), __i(__i) {}

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

  iterator begin() { return {this, 0}; }
  iterator end() { return {this, size_orig}; }

  auto rbegin() { return std::make_reverse_iterator(end()); }
  auto rend() { return std::make_reverse_iterator(begin()); }

 protected:
  size_type size_orig, height, size_ext;
  container_type data;

  node &pull(size_type __i) noexcept {
    if (!data[__i]) data[__i] = *pull(__i << 1) + *pull(__i << 1 | 1);
    return data[__i];
  }

  void push(size_type __i) {
    if (auto &__lz = data[__i].__z) {
      apply(data[__i << 1], *__lz);
      apply(data[__i << 1 | 1], *__lz);
      __lz.reset();
    }
  }

  void sync(size_type __i) {
    if (!data[__i])
      data[__i] = *pull(__i << 1) + *pull(__i << 1 | 1);
    else if (data[__i].__z) {
      apply(data[__i << 1], *data[__i].__z);
      apply(data[__i << 1 | 1], *data[__i].__z);
      data[__i].__z.reset();
    }
  }

  template <class _End = _Endomorphism>
  void apply(node &__nd, _End const &endo) {
    *__nd = *__nd * endo;
    __nd.__z = __nd.__z ? *__nd.__z * endo : endo;
  }

  

  

  

  

  

  


  template <class Pred>
  constexpr decltype(std::declval<Pred>()(_Monoid{})) pass_args(
      Pred &&pred, _Monoid const &_1, [[maybe_unused]] size_type _2) {
    return pred(_1);
  }

  template <class Pred>
  constexpr decltype(std::declval<Pred>()(_Monoid{}, size_type{})) pass_args(
      Pred &&pred, _Monoid const &_1, size_type _2) {
    return pred(_1, _2);
  }

  template <class Pred>
  size_type id2(size_type __i, _Monoid mono, size_type step,
                                   Pred &&pred) {
    assert(__i);
    while (__i < size_ext) {
      if constexpr (__support_lazy) push(__i);
      const _Monoid tmp = *pull((__i <<= 1) | 1) + mono;
      if (pass_args(pred, tmp, ((__i | 1) << --step) ^ size_ext))
        mono = tmp;
      else
        ++__i;
    }
    return ++__i -= size_ext;
  }

  template <class Pred>
  size_type id6(size_type __i, _Monoid mono, size_type step,
                                    Pred &&pred) {
    assert(__i);
    while (__i < size_ext) {
      if constexpr (__support_lazy) push(__i);
      const _Monoid tmp = mono + *pull(__i <<= 1);
      if (pass_args(pred, tmp, ((__i | 1) << --step) ^ size_ext))
        ++__i, mono = tmp;
    }
    return (__i -= size_ext) < size_orig ? __i : size_orig;
  }

 public:
  
  segment_tree(size_type __n = 0)
      : size_orig{__n},
        height(__n > 1 ? 64 - __builtin_clzll(__n - 1) : 0),
        size_ext{size_type{1} << height} {
    if constexpr (std::is_constructible<container_type, size_t>::value)
      data = container_type(size_ext << 1);
    data[0].reset();
  }

  
  segment_tree(size_type __n, const value_type &__x) : segment_tree(__n) {
    for (auto __i = begin(); __i != end(); ++__i) *__i = __x;
  }

  
  template <class _Iterator, typename = std::_RequireInputIter<_Iterator>>
  segment_tree(_Iterator __first, _Iterator __last)
      : segment_tree(std::distance(__first, __last)) {
    for (auto __i = begin(); __first != __last; ++__i, ++__first)
      *__i = *__first;
  }

  
  size_type size() const { return size_orig; }

  
  bool empty() const { return !size(); }

  reference front() { return operator[](0); }
  const_reference front() const { return operator[](0); }

  reference back() { return operator[](size_orig - 1); }
  const_reference back() const { return operator[](size_orig - 1); }

  
  reference operator[](size_type __i) {
    assert(__i < size_orig);
    reference __ref = *data[__i |= size_ext];
    if constexpr (__support_lazy) {
      for (size_t __h{height}; __h; --__h) {
        push(__i >> __h);
        data[__i >> __h].reset();
      }
    } else {
      while (data[__i >>= 1]) data[__i].reset();
    }
    return __ref;
  }

  
  const_reference operator[](size_type __i) const {
    assert(__i < size_orig);
    return *data[__i |= size_ext];
  }

  
  value_type fold(size_type first, size_type last) {
    assert(last <= size_orig);
    if (!(first < last)) return {};
    first += size_ext, last += size_ext;
    value_type left{}, right{};
    for (size_t l = first, r = last--; l != r; l >>= 1, r >>= 1) {
      if (l & 1) left = left + *pull(l++);
      if (r & 1) right = *pull(--r) + right;
      if constexpr (__support_lazy) {
        if (data[first >>= 1].__z) left = left * *data[first].__z;
        if (data[last >>= 1].__z) right = right * *data[last].__z;
      }
    }
    if constexpr (__support_lazy) {
      while (first >>= 1, last >>= 1) {
        if (data[first].__z) left = left * *data[first].__z;
        if (data[last].__z) right = right * *data[last].__z;
      }
    }

    

    

    

    

    

    

    

    

    

    

    

    

    


    return left + right;
  }

  
  value_type fold() { return *pull(1); }

  template <class _End = _Endomorphism>
  void update(size_type first, size_type last, _End const &endo) {
    static_assert(__support_lazy);

    assert(last <= size_orig);
    if (!(first < last)) return;
    first += size_ext, last += size_ext;

    --last;
    for (auto i = height; i; --i) push(first >> i), push(last >> i);
    ++last;

    for (auto l = first, r = last; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(pull(l++), endo);
      if (r & 1) apply(pull(--r), endo);
    }

    for (first >>= __builtin_ffs(first); data[first]; first >>= 1)
      data[first].reset();

    for (last >>= __builtin_ffs(last); data[last]; last >>= 1)
      data[last].reset();
  }

  
  template <class Pred> size_type left_partition(size_type right, Pred &&pred) {
    assert(right <= size_orig);
    right += size_ext;

    if constexpr (__support_lazy)
      for (size_t i{height}; i; --i) push(right >> i);

    _Monoid mono{};
    for (size_type left{size_ext}, step{}; left != right;
         left >>= 1, right >>= 1, ++step) {
      if ((left & 1) != (right & 1)) {
        _Monoid tmp = *pull(--right) + mono;
        if (!pass_args(pred, tmp, (right << step) ^ size_ext))
          return id2(right, mono, step, pred);
        mono = tmp;
      }
    }

    return 0;
  }

  
  template <class Pred> size_type right_partition(size_type left, Pred &&pred) {
    assert(left <= size_orig);
    left += size_ext;

    if constexpr (__support_lazy)
      for (size_t i{height}; i; --i) push(left >> i);

    _Monoid mono{};
    for (size_type right{size_ext << 1}, step{}; left != right;
         left >>= 1, right >>= 1, ++step) {
      if ((left & 1) != (right & 1)) {
        _Monoid tmp = mono + *pull(left);
        if (!pass_args(pred, tmp, ((left + 1) << step) ^ size_ext))
          return id6(left, mono, step, pred);
        mono = tmp;
        ++left;
      }
    }

    return size_orig;
  }
};

template <class _Iterator, typename = std::_RequireInputIter<_Iterator>>
segment_tree(_Iterator, _Iterator)
    -> segment_tree<typename std::iterator_traits<_Iterator>::value_type>;

template <class _Tp, typename = require_binary_plus<_Tp>>
segment_tree(typename segment_tree<_Tp>::size_type, _Tp &&)
    -> segment_tree<_Tp>;

}  



namespace workspace {

using mint = modint<998244353>;

void main() {
  


  input n;
  vector<pair<i32, i32>> ops;
  for (input m; m--;) {
    input x, y;
    --x, --y;
    ops.emplace_back(x, y);
  }

  constexpr auto max_n = 1 << 18;
  static segment_tree<int> sgt(max_n, 1);

  vector<i32> touched;
  unordered_set<i32> succ;

  for (auto &&[x, y] : reversed(ops)) {
    auto r = sgt.right_partition(0, [&](auto s) { return s <= y; });
    sgt[r] = 0;
    touched.emplace_back(r);
    r = sgt.right_partition(0, [&](auto s) { return s <= y; });
    succ.emplace(r);
  }

  for (auto &&p : touched) {
    sgt[p] = 1;
  }

  cout << binomial<mint>(n + (n - 1 - succ.size()), n) << "\n";
}

}  

