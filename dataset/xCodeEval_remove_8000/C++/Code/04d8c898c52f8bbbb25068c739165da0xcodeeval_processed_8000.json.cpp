










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













namespace std {


template <typename _Tp, typename _Alloc, typename _Predicate>
inline typename vector<_Tp, _Alloc>::size_type erase_if(
    vector<_Tp, _Alloc>& __cont, _Predicate __pred) {
  const auto id3 = __cont.size();
  __cont.erase(std::remove_if(__cont.begin(), __cont.end(), __pred),
               __cont.end());
  return id3 - __cont.size();
}


template <typename _Tp, typename _Alloc, typename _Up>
inline typename vector<_Tp, _Alloc>::size_type erase(
    vector<_Tp, _Alloc>& __cont, const _Up& __value) {
  const auto id3 = __cont.size();
  __cont.erase(std::remove(__cont.begin(), __cont.end(), __value),
               __cont.end());
  return id3 - __cont.size();
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
id4(std::vector<std::pair<iter_type, iter_type>> ends,
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
id4(std::vector<std::pair<real_type, real_type>> ends,
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


std::ostream& casefmt(std::ostream& os) {
  return os << "Case 
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



template <class T> class id1 {
  std::vector<T> uniquely;
  std::vector<size_t> compressed;

 public:
  id1(const std::vector<T> &raw)
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
constexpr static bool id0 = is_integral_ext<T>::value;


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

template <class Key> size_t id5(const size_t &seed, const Key &key) {
  return seed ^
         (hash<Key>()(key) + 0x9e3779b9 );
}
template <class T1, class T2> struct hash<std::pair<T1, T2>> {
  size_t operator()(const std::pair<T1, T2> &pair) const {
    return id5(hash<T1>()(pair.first), pair.second);
  }
};
template <class... T> class hash<std::tuple<T...>> {
  template <class Tuple, size_t index = std::tuple_size<Tuple>::value - 1>
  struct tuple_hash {
    static uint64_t apply(const Tuple &t) {
      return id5(tuple_hash<Tuple, index - 1>::apply(t),
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


template <typename Tp, typename S, size_t N>
constexpr auto make_vector(S* sizes, Tp const& init = Tp()) {
  static_assert(std::is_convertible_v<S, size_t>);
  if constexpr (N)
    return std::vector(*sizes,
                       make_vector<Tp, S, N - 1>(std::next(sizes), init));
  else
    return init;
}


template <typename Tp, typename S, size_t N>
constexpr auto make_vector(const S (&sizes)[N], Tp const& init = Tp()) {
  return make_vector<Tp, S, N>((S*)sizes, init);
}


template <typename Tp, typename S, size_t N, size_t I = 0>
constexpr auto make_vector(std::array<S, N> const& sizes,
                           Tp const& init = Tp()) {
  static_assert(std::is_convertible_v<S, size_t>);
  if constexpr (I == N)
    return init;
  else
    return std::vector(sizes[I], make_vector<Tp, S, N, I + 1>(sizes, init));
}


template <typename Tp, size_t I = 0, class... Args>
constexpr auto make_vector(std::tuple<Args...> const& sizes,
                           Tp const& init = Tp()) {
  using tuple_type = std::tuple<Args...>;
  if constexpr (I == tuple_size_v<tuple_type>)
    return init;
  else {
    static_assert(
        std::is_convertible_v<tuple_element_t<I, tuple_type>, size_t>);
    return std::vector(get<I>(sizes), make_vector<Tp, I + 1>(sizes, init));
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




template <typename num_type> class id7 {
  typename std::conditional<std::is_integral<num_type>::value,
                            std::uniform_int_distribution<num_type>,
                            std::uniform_real_distribution<num_type>>::type
      unif;

  std::mt19937 engine;

 public:
  id7(num_type min = std::numeric_limits<num_type>::min(),
                          num_type max = std::numeric_limits<num_type>::max())
      : unif(min, max), engine(std::random_device{}()) {}

  num_type min() const { return unif.min(); }

  num_type max() const { return unif.max(); }

  

  num_type operator()() { return unif(engine); }
};

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

namespace internal {


template <auto Mod> struct id8 {
  static_assert(is_integral_ext<decltype(Mod)>::value,
                "Mod must be integral type.");

  using mod_type =
      typename std::conditional<0 < Mod,
                                typename std::add_const<decltype(Mod)>::type,
                                decltype(Mod)>::type;
  static mod_type mod;

  using value_type = typename std::decay<mod_type>::type;

  constexpr operator value_type() const noexcept { return value; }

  constexpr static id8 one() noexcept { return 1; }

  constexpr id8() noexcept = default;

  template <class int_type,
            typename std::enable_if<is_integral_ext<int_type>::value>::type * =
                nullptr>
  constexpr id8(int_type n) noexcept
      : value((n %= mod) < 0 ? mod + n : n) {}

  constexpr id8(bool n) noexcept : id8(int(n)) {}

  constexpr id8 operator++(int) noexcept {
    id8 t{*this};
    return operator+=(1), t;
  }

  constexpr id8 operator--(int) noexcept {
    id8 t{*this};
    return operator-=(1), t;
  }

  constexpr id8 &operator++() noexcept { return operator+=(1); }

  constexpr id8 &operator--() noexcept { return operator-=(1); }

  constexpr id8 operator-() const noexcept {
    return value ? mod - value : 0;
  }

  constexpr id8 &operator+=(const id8 &rhs) noexcept {
    return (value += rhs.value) < mod ? 0 : value -= mod, *this;
  }

  constexpr id8 &operator-=(const id8 &rhs) noexcept {
    return (value += mod - rhs.value) < mod ? 0 : value -= mod, *this;
  }

  constexpr id8 &operator*=(const id8 &rhs) noexcept {
    return value = (typename multiplicable_uint<value_type>::type)value *
                   rhs.value % mod,
           *this;
  }

  constexpr id8 &operator/=(const id8 &rhs) noexcept {
    return operator*=(rhs.inverse());
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id8>::type
  operator+(const int_type &rhs) const noexcept {
    return id8{*this} += rhs;
  }

  constexpr id8 operator+(const id8 &rhs) const noexcept {
    return id8{*this} += rhs;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id8>::type
  operator-(const int_type &rhs) const noexcept {
    return id8{*this} -= rhs;
  }

  constexpr id8 operator-(const id8 &rhs) const noexcept {
    return id8{*this} -= rhs;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id8>::type
  operator*(const int_type &rhs) const noexcept {
    return id8{*this} *= rhs;
  }

  constexpr id8 operator*(const id8 &rhs) const noexcept {
    return id8{*this} *= rhs;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id8>::type
  operator/(const int_type &rhs) const noexcept {
    return id8{*this} /= rhs;
  }

  constexpr id8 operator/(const id8 &rhs) const noexcept {
    return id8{*this} /= rhs;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           id8>::type
  operator+(const int_type &lhs, const id8 &rhs) noexcept {
    return id8(lhs) + rhs;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           id8>::type
  operator-(const int_type &lhs, const id8 &rhs) noexcept {
    return id8(lhs) - rhs;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           id8>::type
  operator*(const int_type &lhs, const id8 &rhs) noexcept {
    return id8(lhs) * rhs;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           id8>::type
  operator/(const int_type &lhs, const id8 &rhs) noexcept {
    return id8(lhs) / rhs;
  }

  constexpr id8 inverse() const noexcept {
    assert(value);
    value_type a{mod}, b{value}, u{}, v{1}, t{};
    while (b)
      t = a / b, a ^= b ^= (a -= t * b) ^= b, u ^= v ^= (u -= t * v) ^= v;
    return {u};
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id8>::type
  power(int_type e) noexcept {
    return pow(*this, e);
  }

  template <class int_type>
  friend constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                           id8>::type
  pow(id8 b, int_type e) noexcept {
    id8 res{1};
    for (e < 0 ? b = b.inverse(), e = -e : 0; e; e >>= 1, b *= b)
      if (e & 1) res *= b;
    return res;
  }

  friend std::ostream &operator<<(std::ostream &os,
                                  const id8 &rhs) noexcept {
    return os << rhs.value;
  }

  friend std::istream &operator>>(std::istream &is, id8 &rhs) noexcept {
    intmax_t value;
    rhs = (is >> value, value);
    return is;
  }

 protected:
  value_type value = 0;
};

template <auto Mod>
typename id8<Mod>::mod_type id8<Mod>::mod = Mod;

}  



template <auto Mod, typename std::enable_if<(Mod > 0)>::type * = nullptr>
using modint = internal::id8<Mod>;


template <unsigned type_id = 0>
using modint_runtime = internal::id8<-(signed)type_id>;




}  









namespace workspace {


struct id2 {
  using u64 = uint_least64_t;
  using u128 = __uint128_t;

  
  constexpr static u64 mod = (1ull << 61) - 1;

  const static u64 base;

  
  u64 value = 0;

  
  size_t length = 0;

  id2() = default;

  
  template <class char_type, typename std::enable_if<std::is_convertible<
                                 char_type, u64>::value>::type * = nullptr>
  id2(char_type c) : value(u64(c) + 1), length(1) {}

  id2(u64 value, size_t length) : value(value), length(length) {}

  operator std::pair<u64, size_t>() const { return {value, length}; }

  
  bool operator==(const id2 &rhs) const {
    return value == rhs.value && length == rhs.length;
  }

  
  bool operator!=(const id2 &rhs) const { return !operator==(rhs); }

  
  id2 operator+(const id2 &rhs) const {
    return {plus(value, mult(rhs.value, base_pow(length))),
            length + rhs.length};
  }

  
  id2 operator+=(const id2 &rhs) {
    return *this = operator+(rhs);
  }

  
  id2 operator-(const id2 &rhs) const {
    assert(!(length < rhs.length));
    return {minus(value, mult(rhs.value, base_pow(length - rhs.length))),
            length - rhs.length};
  }

  
  id2 operator-=(const id2 &rhs) {
    return *this = operator-(rhs);
  }

  
  static u64 base_pow(size_t exp) {
    static std::vector<u64> pow{1};
    while (pow.size() <= exp) {
      pow.emplace_back(mult(pow.back(), base));
    }
    return pow[exp];
  }

 private:
  static u64 plus(u64 lhs, u64 rhs) {
    return (lhs += rhs) < mod ? lhs : lhs - mod;
  }

  static u64 minus(u64 lhs, u64 rhs) {
    return (lhs -= rhs) < mod ? lhs : lhs + mod;
  }

  static u64 mult(u128 lhs, u64 rhs) {
    lhs *= rhs;
    lhs = (lhs >> 61) + (lhs & mod);
    return lhs < mod ? lhs : lhs - mod;
  }
};


const id2::u64 id2::base =
    id7<u64>(1 << 30, mod - 1)();


template <class str_type> struct id6 {
  constexpr static size_t npos = -1;

  id6() = default;

  id6(str_type str) {
    std::reverse(std::begin(str), std::end(str));
    for (auto &&c : str) suffix.emplace_back(id2{c} + suffix.back());
    std::reverse(suffix.begin(), suffix.end());
  }

  
  size_t size() const { return suffix.size() - 1; }

  
  id2 substr(size_t pos = 0, size_t n = npos) const {
    assert(!(size() < pos));
    return suffix[pos] - suffix[pos + std::min(n, size() - pos)];
  }

  
  size_t lcp(id6 const &rhs) const {
    auto n = std::min(size(), rhs.size());
    return binary_search<size_t>(
        0, n + 1, [&](size_t l) { return substr(0, l) == rhs.substr(0, l); });
  }

 private:
  std::vector<id2> suffix{{}};
};

}  



namespace workspace {
using mint = modint<1000000007>;

void main() {
  

  string s, t;
  cin >> s >> t;
  id6 srh(s), trh(t);
  auto n = size(s), m = size(t);
  vector<mint> dp(n + 1), acc(n + 1);
  dp[0] = acc[0] = 1;
  for (auto i = 1, j = -1; i <= n; ++i) {
    dp[i] += dp[i - 1];
    if (i >= m && srh.substr(i - m, m) == trh.substr()) j = i - m;
    if (j != -1) dp[i] += acc[j];
    acc[i] = acc[i - 1] + dp[i];
  }
  cout << dp[n] - 1 << eol;
}
}
