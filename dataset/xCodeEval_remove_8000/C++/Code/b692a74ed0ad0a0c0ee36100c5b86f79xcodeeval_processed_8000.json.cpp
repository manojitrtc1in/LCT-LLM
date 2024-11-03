










namespace workspace {

constexpr char eol = '\n';

using namespace std;

using i32 = int_least32_t;
using i64 = int_least64_t;
using i128 = __int128_t;
using u32 = uint_least32_t;
using u64 = uint_least64_t;
using u128 = __uint128_t;

template <class T, class Comp = less<T>>
using priority_queue = std::priority_queue<T, vector<T>, Comp>;

template <class T> using stack = std::stack<T, vector<T>>;

}  







namespace config {

const auto start_time{std::chrono::system_clock::now()};


int64_t elapsed() {
  using namespace std::chrono;
  const auto end_time{system_clock::now()};
  return duration_cast<milliseconds>(end_time - start_time).count();
}


__attribute__((constructor)) void setup() {
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);


  atexit([] {
    char bufc;
    if (cin >> bufc)
      cerr << "\n\033[43m\033[30mwarning: buffer not empty.\033[0m\n\n";
  });

}

unsigned cases(), caseid = 1;  



template <class F> void loop(F main) {
  for (const unsigned total = cases(); caseid <= total; ++caseid) {
    try {
      main();
    } catch (std::nullptr_t) {
    }
  }
}

}  




























































namespace std _GLIBCXX_VISIBILITY(default) {
  _GLIBCXX_BEGIN_NAMESPACE_VERSION

  namespace __detail {
  

  

  

  


  

  template <typename _Tp, bool = is_signed<_Tp>::value> struct __int_limits {
    static_assert(is_integral<_Tp>::value, "unsupported specialization");
    using _Up = typename make_unsigned<_Tp>::type;
    static constexpr int digits = sizeof(_Tp) * __CHAR_BIT__ - 1;
    static constexpr _Tp min() noexcept { return _Tp(_Up(1) << digits); }
    static constexpr _Tp max() noexcept { return _Tp(_Up(~_Up(0)) >> 1); }
  };

  

  template <typename _Tp> struct __int_limits<_Tp, false> {
    static_assert(is_integral<_Tp>::value, "unsupported specialization");
    static constexpr int digits = sizeof(_Tp) * __CHAR_BIT__;
    static constexpr _Tp min() noexcept { return 0; }
    static constexpr _Tp max() noexcept { return _Tp(-1); }
  };

  template <> struct __int_limits<bool>;  

  }                                       


  

  


  template <typename _Tp> constexpr _Tp id14(_Tp __x, int __s) noexcept {
    constexpr auto _Nd = __detail::__int_limits<_Tp>::digits;
    const int __r = __s % _Nd;
    if (__r == 0)
      return __x;
    else if (__r > 0)
      return (__x << __r) | (__x >> ((_Nd - __r) % _Nd));
    else
      return (__x >> -__r) | (__x << ((_Nd + __r) % _Nd));  

  }

  template <typename _Tp> constexpr _Tp id23(_Tp __x, int __s) noexcept {
    constexpr auto _Nd = __detail::__int_limits<_Tp>::digits;
    const int __r = __s % _Nd;
    if (__r == 0)
      return __x;
    else if (__r > 0)
      return (__x >> __r) | (__x << ((_Nd - __r) % _Nd));
    else
      return (__x << -__r) | (__x >> ((_Nd + __r) % _Nd));  

  }

  template <typename _Tp> constexpr int id2(_Tp __x) noexcept {
    using std::__detail::__int_limits;
    constexpr auto _Nd = __int_limits<_Tp>::digits;

    if (__x == 0) return _Nd;

    constexpr auto id17 = __int_limits<unsigned long long>::digits;
    constexpr auto id26 = __int_limits<unsigned long>::digits;
    constexpr auto id19 = __int_limits<unsigned>::digits;

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
      constexpr auto id15 = __int_limits<unsigned long long>::max();
      unsigned long long __low = __x & id15;
      return (_Nd - id17) + __builtin_clzll(__low);
    }
  }

  template <typename _Tp> constexpr int id9(_Tp __x) noexcept {
    if (__x == __detail::__int_limits<_Tp>::max())
      return __detail::__int_limits<_Tp>::digits;
    return std::id2<_Tp>((_Tp)~__x);
  }

  template <typename _Tp> constexpr int id28(_Tp __x) noexcept {
    using std::__detail::__int_limits;
    constexpr auto _Nd = __int_limits<_Tp>::digits;

    if (__x == 0) return _Nd;

    constexpr auto id17 = __int_limits<unsigned long long>::digits;
    constexpr auto id26 = __int_limits<unsigned long>::digits;
    constexpr auto id19 = __int_limits<unsigned>::digits;

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

      constexpr auto id15 = __int_limits<unsigned long long>::max();
      unsigned long long __low = __x & id15;
      if (__low != 0) return __builtin_ctzll(__low);
      unsigned long long __high = __x >> id17;
      return __builtin_ctzll(__high) + id17;
    }
  }

  template <typename _Tp> constexpr int id8(_Tp __x) noexcept {
    if (__x == __detail::__int_limits<_Tp>::max())
      return __detail::__int_limits<_Tp>::digits;
    return std::id28((_Tp)~__x);
  }

  template <typename _Tp> constexpr int id6(_Tp __x) noexcept {
    using std::__detail::__int_limits;
    constexpr auto _Nd = __int_limits<_Tp>::digits;

    if (__x == 0) return 0;

    constexpr auto id17 = __int_limits<unsigned long long>::digits;
    constexpr auto id26 = __int_limits<unsigned long>::digits;
    constexpr auto id19 = __int_limits<unsigned>::digits;

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

      constexpr auto id15 = __int_limits<unsigned long long>::max();
      unsigned long long __low = __x & id15;
      unsigned long long __high = __x >> id17;
      return __builtin_popcountll(__low) + __builtin_popcountll(__high);
    }
  }

  template <typename _Tp> constexpr bool id7(_Tp __x) noexcept {
    return std::id6(__x) == 1;
  }

  template <typename _Tp> constexpr _Tp id27(_Tp __x) noexcept {
    using std::__detail::__int_limits;
    constexpr auto _Nd = __int_limits<_Tp>::digits;
    if (__x == 0 || __x == 1) return 1;
    auto id11 = _Nd - std::id2((_Tp)(__x - 1u));
    

    

    

    


    if (!__builtin_is_constant_evaluated()) {
      __glibcxx_assert(id11 != __int_limits<_Tp>::digits);
    }

    using __promoted_type = decltype(__x << 1);
    if _GLIBCXX17_CONSTEXPR (!is_same<__promoted_type, _Tp>::value) {
      

      

      

      

      

      const int id4 = sizeof(__promoted_type) / sizeof(_Tp) / 2;
      id11 |= (id11 & _Nd) << id4;
    }
    return (_Tp)1u << id11;
  }

  template <typename _Tp> constexpr _Tp id25(_Tp __x) noexcept {
    constexpr auto _Nd = __detail::__int_limits<_Tp>::digits;
    if (__x == 0) return 0;
    return (_Tp)1u << (_Nd - std::id2((_Tp)(__x >> 1)));
  }

  template <typename _Tp> constexpr _Tp id21(_Tp __x) noexcept {
    constexpr auto _Nd = __detail::__int_limits<_Tp>::digits;
    return _Nd - std::id2(__x);
  }

  






  

  template <typename _Tp, typename _Up = _Tp>
  using _If_is_unsigned_integer =
      enable_if_t<__is_unsigned_integer<_Tp>::value, _Up>;
  


  


  

  template <typename _Tp>
  [[nodiscard]] constexpr _If_is_unsigned_integer<_Tp> rotl(_Tp __x,
                                                            int __s) noexcept {
    return std::id14(__x, __s);
  }

  

  template <typename _Tp>
  [[nodiscard]] constexpr _If_is_unsigned_integer<_Tp> rotr(_Tp __x,
                                                            int __s) noexcept {
    return std::id23(__x, __s);
  }

  


  

  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp, int> id5(_Tp __x) noexcept {
    return std::id2(__x);
  }

  

  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp, int> id18(_Tp __x) noexcept {
    return std::id9(__x);
  }

  

  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp, int> id12(_Tp __x) noexcept {
    return std::id28(__x);
  }

  

  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp, int> id3(_Tp __x) noexcept {
    return std::id8(__x);
  }

  

  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp, int> popcount(_Tp __x) noexcept {
    return std::id6(__x);
  }

  




  

  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp, bool> id24(
      _Tp __x) noexcept {
    return std::id7(__x);
  }

  

  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp> id0(_Tp __x) noexcept {
    return std::id27(__x);
  }

  

  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp> bit_floor(_Tp __x) noexcept {
    return std::id25(__x);
  }

  

  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp> bit_width(_Tp __x) noexcept {
    return std::id21(__x);
  }



  

  enum class endian {
    little = __ORDER_LITTLE_ENDIAN__,
    big = __ORDER_BIG_ENDIAN__,
    native = __BYTE_ORDER__
  };



  


  _GLIBCXX_END_NAMESPACE_VERSION
}  












namespace std {


template <typename _Tp, typename _Alloc, typename _Predicate>
inline typename vector<_Tp, _Alloc>::size_type erase_if(
    vector<_Tp, _Alloc>& __cont, _Predicate __pred) {
  const auto id13 = __cont.size();
  __cont.erase(std::remove_if(__cont.begin(), __cont.end(), __pred),
               __cont.end());
  return id13 - __cont.size();
}


template <typename _Tp, typename _Alloc, typename _Up>
inline typename vector<_Tp, _Alloc>::size_type erase(
    vector<_Tp, _Alloc>& __cont, const _Up& __value) {
  const auto id13 = __cont.size();
  __cont.erase(std::remove(__cont.begin(), __cont.end(), __value),
               __cont.end());
  return id13 - __cont.size();
}

}  




























namespace workspace {


template <class iter_type, class pred_type>
std::enable_if_t<
    std::is_convertible_v<std::invoke_result_t<pred_type, iter_type>, bool>,
    iter_type>
binary_search(iter_type ok, iter_type ng, pred_type pred) {
  assert(ok != ng);
  std::make_signed_t<decltype(ng - ok)> dist(ng - ok);
  while (1 < dist || dist < -1) {
    iter_type mid(ok + dist / 2);
    if (pred(mid))
      ok = mid, dist -= dist / 2;
    else
      ng = mid, dist /= 2;
  }
  return ok;
}


template <class iter_type, class pred_type>
std::enable_if_t<std::is_convertible_v<
                     std::invoke_result_t<pred_type, std::vector<iter_type>>,
                     std::vector<bool>>,
                 std::vector<iter_type>>
id16(std::vector<std::pair<iter_type, iter_type>> ends,
                       pred_type pred) {
  std::vector<iter_type> mids(ends.size());
  for (;;) {
    bool all_found = true;
    for (size_t i{}; i != ends.size(); ++i) {
      auto [ok, ng] = ends[i];
      iter_type mid(ok + (ng - ok) / 2);
      if (mids[i] != mid) {
        all_found = false;
        mids[i] = mid;
      }
    }
    if (all_found) break;
    auto res = pred(mids);
    for (size_t i{}; i != ends.size(); ++i) {
      (res[i] ? ends[i].first : ends[i].second) = mids[i];
    }
  }
  return mids;
}


template <class real_type, class pred_type>
std::enable_if_t<
    std::is_convertible_v<std::invoke_result_t<pred_type, real_type>, bool>,
    real_type>
binary_search(real_type ok, real_type ng, const real_type eps, pred_type pred) {
  assert(ok != ng);
  for (auto loops = 0; loops != std::numeric_limits<real_type>::digits &&
                       (ok + eps < ng || ng + eps < ok);
       ++loops) {
    real_type mid{(ok + ng) / 2};
    (pred(mid) ? ok : ng) = mid;
  }
  return ok;
}


template <class real_type, class pred_type>
std::enable_if_t<std::is_convertible_v<
                     std::invoke_result_t<pred_type, std::vector<real_type>>,
                     std::vector<bool>>,
                 std::vector<real_type>>
id16(std::vector<std::pair<real_type, real_type>> ends,
                       const real_type eps, pred_type pred) {
  std::vector<real_type> mids(ends.size());
  for (auto loops = 0; loops != std::numeric_limits<real_type>::digits;
       ++loops) {
    bool all_found = true;
    for (size_t i{}; i != ends.size(); ++i) {
      auto [ok, ng] = ends[i];
      if (ok + eps < ng || ng + eps < ok) {
        all_found = false;
        mids[i] = (ok + ng) / 2;
      }
    }
    if (all_found) break;
    auto res = pred(mids);
    for (size_t i{}; i != ends.size(); ++i) {
      (res[i] ? ends[i].first : ends[i].second) = mids[i];
    }
  }
  return mids;
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



template <class T> class id10 {
  std::vector<T> uniquely;
  std::vector<size_t> compressed;

 public:
  id10(const std::vector<T> &raw)
      : uniquely(raw), compressed(raw.size()) {
    std::sort(uniquely.begin(), uniquely.end());
    uniquely.erase(std::unique(uniquely.begin(), uniquely.end()),
                   uniquely.end());
    for (size_t i = 0; i != size(); ++i)
      compressed[i] =
          std::lower_bound(uniquely.begin(), uniquely.end(), raw[i]) -
          uniquely.begin();
  }

  size_t operator[](const size_t idx) const {
    assert(idx < size());
    return compressed[idx];
  }

  size_t size() const { return compressed.size(); }

  size_t count() const { return uniquely.size(); }

  T value(const size_t ord) const {
    assert(ord < count());
    return uniquely[ord];
  }

  size_t order(const T &value) const {
    return std::lower_bound(uniquely.begin(), uniquely.end(), value) -
           uniquely.begin();
  }

  auto begin() { return compressed.begin(); }
  auto end() { return compressed.end(); }
  auto rbegin() { return compressed.rbegin(); }
  auto rend() { return compressed.rend(); }
};






namespace workspace {


template <class Tp> void eject(Tp const &arg) {
  std::cout << arg << "\n";
  throw nullptr;
}

}  







namespace workspace {


template <class lambda_type> class fixed_point {
  lambda_type func;

 public:
  
  fixed_point(lambda_type &&func) : func(std::move(func)) {}

  
  template <class... Args> auto operator()(Args &&... args) const {
    return func(*this, std::forward<Args>(args)...);
  }
};

}  










template <class type, template <class> class trait>
using enable_if_trait_type = typename std::enable_if<trait<type>::value>::type;

template <class Container>
using element_type = typename std::decay<decltype(
    *std::begin(std::declval<Container&>()))>::type;

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
constexpr static bool id1 = is_integral_ext<T>::value;


template <typename T, typename = void> struct multiplicable_uint {
  using type = uint_least32_t;
};
template <typename T>
struct multiplicable_uint<T, typename std::enable_if<(2 < sizeof(T))>::type> {
  using type = uint_least64_t;
};
template <typename T>
struct multiplicable_uint<T, typename std::enable_if<(4 < sizeof(T))>::type> {
  using type = __uint128_t;
};

namespace workspace {
template <class T, class = void> struct hash : std::hash<T> {};

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

template <class Key> size_t id20(const size_t &seed, const Key &key) {
  return seed ^
         (hash<Key>()(key) + 0x9e3779b9 );
}
template <class T1, class T2> struct hash<std::pair<T1, T2>> {
  size_t operator()(const std::pair<T1, T2> &pair) const {
    return id20(hash<T1>()(pair.first), pair.second);
  }
};
template <class... T> class hash<std::tuple<T...>> {
  template <class Tuple, size_t index = std::tuple_size<Tuple>::value - 1>
  struct tuple_hash {
    static uint64_t apply(const Tuple &t) {
      return id20(tuple_hash<Tuple, index - 1>::apply(t),
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


std::ostream& casefmt(std::ostream& os) {
  return os << "Case 
}

}  


namespace workspace {


template <class T = void>
struct read
{
    typename std::remove_const<T>::type value;
    template <class... types>
    read(types... args) : value(args...) { std::cin >> value; }
    operator T() const { return value; }
};
template <>
struct read<void>
{
    template <class T>
    operator T() const { T value; std::cin >> value; return value; }
};
} 





namespace std {
template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.first >> p.second;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << ' ' << p.second;
}
template <class tuple_t, size_t index> struct tuple_is {
  static istream &apply(istream &is, tuple_t &t) {
    tuple_is<tuple_t, index - 1>::apply(is, t);
    return is >> get<index>(t);
  }
};
template <class tuple_t> struct tuple_is<tuple_t, SIZE_MAX> {
  static istream &apply(istream &is, tuple_t &t) { return is; }
};
template <class... T> istream &operator>>(istream &is, tuple<T...> &t) {
  return tuple_is<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is,
                                                                          t);
}
template <class tuple_t, size_t index> struct tuple_os {
  static ostream &apply(ostream &os, const tuple_t &t) {
    tuple_os<tuple_t, index - 1>::apply(os, t);
    return os << ' ' << get<index>(t);
  }
};
template <class tuple_t> struct tuple_os<tuple_t, 0> {
  static ostream &apply(ostream &os, const tuple_t &t) {
    return os << get<0>(t);
  }
};
template <class tuple_t> struct tuple_os<tuple_t, SIZE_MAX> {
  static ostream &apply(ostream &os, const tuple_t &t) { return os; }
};
template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t) {
  return tuple_os<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os,
                                                                          t);
}
template <class Container, typename Value = element_type<Container>>
typename enable_if<!is_same<typename decay<Container>::type, string>::value &&
                       !is_same<typename decay<Container>::type, char *>::value,
                   istream &>::type
operator>>(istream &is, Container &cont) {
  for (auto &&e : cont) is >> e;
  return is;
}
template <class Container, typename Value = element_type<Container>>
typename enable_if<!is_same<typename decay<Container>::type, string>::value &&
                       !is_same<typename decay<Container>::type, char *>::value,
                   ostream &>::type
operator<<(ostream &os, const Container &cont) {
  bool head = true;
  for (auto &&e : cont) head ? head = 0 : (os << ' ', 0), os << e;
  return os;
}
}  










namespace workspace {


template <typename Tp, size_t N, typename S>
constexpr auto make_vector(S* sizes, Tp const& init = Tp()) {
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
constexpr auto make_vector(std::array<S, N> const& sizes,
                           Tp const& init = Tp()) {
  static_assert(std::is_convertible_v<S, size_t>);
  if constexpr (I == N)
    return init;
  else
    return std::vector(sizes[I], make_vector<Tp, N, S, I + 1>(sizes, init));
}


template <typename Tp, size_t N = SIZE_MAX, size_t I = 0, class... Args>
constexpr auto make_vector(std::tuple<Args...> const& sizes,
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




template <typename num_type> class id22 {
  typename std::conditional<std::is_integral<num_type>::value,
                            std::uniform_int_distribution<num_type>,
                            std::uniform_real_distribution<num_type>>::type
      unif;

  std::mt19937 engine;

 public:
  id22(num_type min = std::numeric_limits<num_type>::min(),
                          num_type max = std::numeric_limits<num_type>::max())
      : unif(min, max), engine(std::random_device{}()) {}

  num_type min() const { return unif.min(); }

  num_type max() const { return unif.max(); }

  

  num_type operator()() { return unif(engine); }
};








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




template <class iter_type, class comp_type>
iter_type trinary(iter_type first, iter_type last, comp_type comp)
{
    assert(first < last);
    intmax_t dist(last - first);
    while(dist > 2)
    {
        iter_type left(first + dist / 3), right(first + dist * 2 / 3);
        if(comp(left, right)) last = right, dist = dist * 2 / 3;
        else first = left, dist -= dist / 3;
    }
    if(dist > 1 && comp(first + 1, first)) ++first;
    return first;
}


template <class comp_type>
long double trinary(long double first, long double last, const long double eps, comp_type comp)
{
    assert(first < last);
    while(last - first > eps)
    {
        long double left{(first * 2 + last) / 3}, right{(first + last * 2) / 3};
        if(comp(left, right)) last = right;
        else first = left;
    }
    return first;
}

template <class Container> class reversed {
  Container &ref, copy;

 public:
  constexpr reversed(Container &ref) : ref(ref) {}
  constexpr reversed(Container &&ref = Container()) : ref(copy), copy(ref) {}
  constexpr auto begin() const { return ref.rbegin(); }
  constexpr auto end() const { return ref.rend(); }
  constexpr operator Container() const { return ref; }
};


namespace workspace {
void main();
}
int main() { config::loop(workspace::main); }

unsigned config::cases() {
  

  

  return 1;
}

namespace workspace {
void main() {
  

  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (auto &&e : a) {
    --e;
  }

  int ans = 0;
  int fre = -1;
  

  {
    map<int, int> cnt;
    for (auto &&e : a) {
      cnt[e]++;
    }
    int ma = 0;
    for (auto &&[x, y] : cnt) {
      chge(ma, y);
    }
    int mac = 0;
    for (auto &&[x, y] : cnt) {
      if (y == ma) mac++, fre = x;
    }
    if (1 < mac) ans = n;
  }

  const int maxv = 100;
  for (auto i = 0; i < maxv; ++i) {
    if (i == fre) continue;
    vector<int> b{0};
    for (auto e : a) {
      auto pb = b.back();
      if (e == fre)
        pb--;
      else if (e == i)
        pb++;
      b.push_back(pb);
    }
    vector<int> mi(2 * n + 1, n + 1), ma(2 * n + 1, -1);
    for (auto i = 0; i <= n; ++i) {
      auto va = n + b[i];
      chle(mi[va], i);
      chge(ma[va], i);
    }
    for (auto i = 0, j = n + 1; i < size(mi); ++i) {
      chle(j, mi[i]);
      chge(ans, ma[i] - j);
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

  }

  cout << ans << eol;
}
}  

