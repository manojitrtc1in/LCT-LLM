





























template <class T, int S>
struct MDVecDef {
  using Type = std::vector<typename MDVecDef<T, S - 1>::Type>;
};
template <class T>
struct MDVecDef<T, 0> {
  using Type = T;
};
template <class T, int S = 1>
using MDVec = typename MDVecDef<T, S>::Type;

















template<class T>
inline T DebugRet(T x) {
    Debug(x);
    return x;
}









  struct struct_name {                                            \
    using attr_name 
    Type attr_name;                                               \
    mut_ref(Type) get_
    const_ref(Type) get_
  };

  template <class T>                                           \
  struct struct_name {                                         \
    using attr_name
    T attr_name;                                               \
    mut_ref(T) get_
    const_ref(T) get_
  };

  bool operator==(const name &a, const name &b) {  \
    return std::memcmp(&a, &b, sizeof(name)) == 0; \
  }                                                \
  bool operator!=(const name &a, const name &b) { return !(a == b); }

  bool operator>(const name &rhs) const { return rhs < *this; }     \
  bool operator<=(const name &rhs) const { return !(*this > rhs); } \
  bool operator>=(const name &rhs) const { return !(*this < rhs); }

  name &operator+=(const name &rhs) { return *this = (*this) + rhs; } \
  name &operator-=(const name &rhs) { return *this = (*this) - rhs; } \
  name &operator*=(const name &rhs) { return *this = (*this) * rhs; } \
  name &operator/=(const name &rhs) { return *this = (*this) / rhs; }

  template <typename id3 = param>                                    \
  enable_if_t<is_same_v<id3, param> && is_same_v<id3, Type>, \
              ret_type>

  template <bool id3 = param> \
  enable_if_t<id3 == (param) && id3, ret_type>

  template <bool id3 = param> \
  static enable_if_t<id3 == (param) && id3, ret_type>

  template <class T>                 \
  struct is_
    static const bool value = false; \
  };                                 \
  template <class T>                 \
  inline constexpr bool is_

  template <>                             \
  struct is_
    static const bool value = true;       \
  };

  template <type T>                                     \
  struct is_
    static const bool value = true;                     \
  };

  template <typename... Args>                         \
  inline auto to(Args &&...args)                      \
      ->decltype(from(std::forward<Args>(args)...)) { \
    return from(std::forward<Args>(args)...);         \
  }

  operator type() const { return type(field); }

  CastToScalar(field, i8);     \
  CastToScalar(field, u8);     \
  CastToScalar(field, i16);    \
  CastToScalar(field, u16);    \
  CastToScalar(field, i32);    \
  CastToScalar(field, u32);    \
  CastToScalar(field, i64);    \
  CastToScalar(field, u64);    \
  CastToScalar(field, f32);    \
  CastToScalar(field, f64);    \
  CastToScalar(field, f80);


std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

std::mt19937 rng(0);

template <class T> T random_choice(T l, T r, std::mt19937 &gen = rng) {
  std::uniform_int_distribution<T> random(l, r);
  return random(gen);
}
namespace dalt {

struct Timer {explicit Timer(const char* m) {}void stop() const {}};


}
using i8 = char;
using i16 = short;
using i32 = int;
using i64 = long long;
using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;
using usize = size_t;
using f32 = float;
using f64 = double;


using f80 = long double;
FunctionAlias(std::lower_bound, LowerBound);
FunctionAlias(std::upper_bound, UpperBound);
FunctionAlias(std::unique, Unique);
FunctionAlias(std::swap, Swap);
FunctionAlias(std::min, Min);
FunctionAlias(std::max, Max);
FunctionAlias(std::abs, Abs);
FunctionAlias(std::sin, Sin);
FunctionAlias(std::asin, Asin);
FunctionAlias(std::cos, Cos);
FunctionAlias(std::acos, Acos);
FunctionAlias(std::tan, Tan);
FunctionAlias(std::atan, Atan);
FunctionAlias(std::sort, Sort);
FunctionAlias(std::fill, Fill);
FunctionAlias(std::move, Move);
FunctionAlias(std::reverse, Reverse);
FunctionAlias(std::max_element, MaxElement);
FunctionAlias(std::make_tuple, MakeTuple);
FunctionAlias(std::make_pair, MakePair);
FunctionAlias(std::clamp, Clamp);
FunctionAlias(std::shuffle, Shuffle);
FunctionAlias(std::to_string, ToString);
FunctionAlias(std::tie, Tie);
template <typename _Signature>
using Function = std::function<_Signature>;
using Str = std::string;
using String = Str;
using StringStream = std::stringstream;
using IStream = std::istream;
using OStream = std::ostream;
using std::enable_if;
using std::enable_if_t;
using std::is_base_of;
using std::is_base_of_v;
using std::is_floating_point;
using std::is_floating_point_v;
using std::is_integral;
using std::is_integral_v;
using std::is_arithmetic;
using std::is_arithmetic_v;
using std::is_same;
using std::is_same_v;
auto &Stderr = std::cerr;
auto &Stdin = std::cin;
auto &Stdout = std::cout;
template <class T>
using Less = std::less<T>;
template <class T>
using Greater = std::greater<T>;
template <typename _Key, typename _Tp, typename _Compare = Less<_Key>>
using TreeMap = std::map<_Key, _Tp, _Compare>;
template <typename _Key, typename _Compare = Less<_Key>>
using TreeSet = std::set<_Key, _Compare>;
template <typename _Key, typename _Compare = std::less<_Key>,
          typename _Alloc = std::allocator<_Key>>
using MultiTreeSet = std::multiset<_Key, _Compare, _Alloc>;
template <class T>
using Deque = std::deque<T>;
template <class T>
using Queue = std::queue<T>;
template <class T>
using Vec = std::vector<T>;
template <class T>
using Reducer = Function<T(const T &, const T &)>;
template <class T>
using Comparator = Function<bool(const T &, const T &)>;
template <class T>
using Indexer = Function<T(i32)>;
template <class T>
using Indexer2 = Function<T(i32, i32)>;
template <class A, class B = A, class C = A>
using Adder = Function<C(const A &, const B &)>;
template <class I>
using Checker = Function<bool(const I &)>;
template <class A, class B>
using BiChecker = Function<bool(const A &, const B &)>;
template <class T>
using Consumer = Function<void(const T &)>;
template<class T>
using Supplier = Function<T()>;
template <class FIRST, class SECOND>
using BiConsumer = Function<void(const FIRST &, const SECOND &)>;
template <class F, class T = F>
using Mapper = Function<T(const F &)>;
template <class T>
using MinHeap = std::priority_queue<T, Vec<T>, Greater<T>>;
template <class T>
using MaxHeap = std::priority_queue<T, Vec<T>, Less<T>>;
template <class T, usize S>
using Array = std::array<T, S>;
template <typename... _Elements>
using Tuple = std::tuple<_Elements...>;
template <class T, class = enable_if_t<is_floating_point_v<T>>>
using Complex = std::complex<T>;
template <class A, class B>
using Pair = std::pair<A, B>;
namespace dalt {
template <class T>
IStream& operator>>(IStream& is, Vec<T>& val) {
  for (auto& v : val) {
    is >> v;
  }
  return is;
}

  template <class T>                       \
  Vec<T>& operator op(Vec<T>& data, T x) { \
    for (auto& v : data) {                 \
      v op x;                              \
    }                                      \
    return data;                           \
  }
VEC_OP(+=)
VEC_OP(-=)
VEC_OP(*=)
VEC_OP(/=)
VEC_OP(%=)
VEC_OP(^=)
VEC_OP(&=)
VEC_OP(|=)
VEC_OP(==)
VEC_OP(!=)
template <class T>
int Compare(const Vec<T>& lhs, const Vec<T>& rhs) {
  for(int i = 0; i < Size(lhs) && i < Size(rhs); i++) {
    if(lhs[i] != rhs[i]) {
      return lhs[i] < rhs[i] ? -1 : 1;
    }
  }
  return Size(lhs) < Size(rhs) ? -1 : Size(lhs) > Size(rhs) ? 1 : 0;
}
}  



using namespace dalt;

inline i32 _builtin_clz(u32 i) {
  

  if (i <= 0) return i == 0 ? 32 : 0;
  int n = 31;
  if (i >= 1 << 16) {
    n -= 16;
    i >>= 16;
  }
  if (i >= 1 << 8) {
    n -= 8;
    i >>= 8;
  }
  if (i >= 1 << 4) {
    n -= 4;
    i >>= 4;
  }
  if (i >= 1 << 2) {
    n -= 2;
    i >>= 2;
  }
  return n - (i >> 1);
}


inline i32 _builtin_clzll(u64 i) {
  u32 x = u32(i >> 32);
  return x == 0 ? 32 + _builtin_clz((int)i) : _builtin_clz(x);
}


inline i32 _builtin_ctz(u32 i) {
  

  int y;
  if (i == 0) return 32;
  int n = 31;
  y = i << 16;
  if (y != 0) {
    n = n - 16;
    i = y;
  }
  y = i << 8;
  if (y != 0) {
    n = n - 8;
    i = y;
  }
  y = i << 4;
  if (y != 0) {
    n = n - 4;
    i = y;
  }
  y = i << 2;
  if (y != 0) {
    n = n - 2;
    i = y;
  }
  return n - ((i << 1) >> 31);
}


inline i32 _builtin_ctzll(u64 i) {
  

  int x, y;
  if (i == 0) return 64;
  int n = 63;
  y = (int)i;
  if (y != 0) {
    n = n - 32;
    x = y;
  } else
    x = (int)(i >> 32);
  y = x << 16;
  if (y != 0) {
    n = n - 16;
    x = y;
  }
  y = x << 8;
  if (y != 0) {
    n = n - 8;
    x = y;
  }
  y = x << 4;
  if (y != 0) {
    n = n - 4;
    x = y;
  }
  y = x << 2;
  if (y != 0) {
    n = n - 2;
    x = y;
  }
  return n - ((x << 1) >> 31);
}


inline i32 _builtin_popcount(u32 i) {
  

  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  i = (i + (i >> 4)) & 0x0f0f0f0f;
  i = i + (i >> 8);
  i = i + (i >> 16);
  return i & 0x3f;
}


inline i32 id2(u64 i) {
  

  i = i - ((i >> 1) & 0x5555555555555555ll);
  i = (i & 0x3333333333333333ll) + ((i >> 2) & 0x3333333333333333ll);
  i = (i + (i >> 4)) & 0x0f0f0f0f0f0f0f0fll;
  i = i + (i >> 8);
  i = i + (i >> 16);
  i = i + (i >> 32);
  return (int)i & 0x7f;
}

namespace dalt {
inline i32 id14(u32 x) {
  if (x == 0) return 32;
  return _builtin_clz(x);
}
inline i32 id14(i32 x) { return id14(u32(x)); }
inline i32 id14(u64 x) {
  if (x == 0) return 64;
  return _builtin_clzll(x);
}
inline i32 id14(i64 x) { return id14(u64(x)); }
inline i32 id8(u32 x) {
  if (x == 0) return 32;
  return _builtin_ctz(x);
}
inline i32 id8(i32 x) { return id8(u32(x)); }
inline i32 id8(u64 x) {
  if (x == 0) return 64;
  return _builtin_ctzll(x);
}
inline i32 id8(i64 x) { return id8(u64(x)); }
inline i32 id16(u32 x) {
  if (x == 0) {
    return 0;
  }
  return 32 - id14(x - 1);
}
inline i32 id16(u64 x) {
  if (x == 0) {
    return 0;
  }
  return 64 - id14(x - 1);
}
inline i32 id0(u32 x) {
  if (x == 0) {
    return -1;
  }
  return 31 - id14(x);
}
inline i32 id0(u64 x) {
  if (x == 0) {
    return -1;
  }
  return 63 - id14(x);
}
inline i32 id16(i32 x) { return id16(u32(x)); }
inline i32 id16(i64 x) { return id16(u64(x)); }
inline i32 id0(i32 x) { return id0(u32(x)); }
inline i32 id0(i64 x) { return id0(u64(x)); }
inline i32 CountBit(u32 x) { return _builtin_popcount(x); }
inline i32 CountBit(i32 x) { return CountBit(u32(x)); }
inline i32 CountBit(u64 x) { return id2(x); }
inline i32 CountBit(i64 x) { return CountBit(u64(x)); }
inline i32 id34(u32 x) { return id0(x); }
inline i32 id34(i32 x) { return id34(u32(x)); }
inline i32 id34(u64 x) { return id0(x); }
inline i32 id34(i64 x) { return id34(u64(x)); }
template <class T>
inline enable_if_t<is_integral_v<T>, T> id15(T x) {
  return x & -x;
}
template <class T>
inline enable_if_t<is_integral_v<T>, T> id11(T x) {
  if (x == 0) {
    return x;
  }
  return T(1) << id34(x);
}
template <class T>
inline enable_if_t<is_integral_v<T>, i32> id29(T x) {
  if (x == 0) {
    return -1;
  }
  return id34(id15(x));
}
inline u32 id24(i32 k) {
  if (k == 0) {
    return 0;
  }
  return (~u32()) << (32 - k);
}
inline u64 id4(i32 k) {
  if (k == 0) {
    return 0;
  }
  return (~u64()) << (64 - k);
}
inline u32 id33(i32 k) {
  if (k == 0) {
    return 0;
  }
  return (~u32()) >> (32 - k);
}
inline u64 id21(i32 k) {
  if (k == 0) {
    return 0;
  }
  return (~u64()) >> (64 - k);
}
inline u64 id5(i32 l, i32 r) {
  if (l > r) {
    return 0;
  }
  u64 high = r < 63 ? (u64(-1) << r + 1) : 0;
  u64 low = u64(-1) << l;
  return high ^ low;
}
inline u32 id13(i32 l, i32 r) {
  if (l > r) {
    return 0;
  }
  u32 high = r < 31 ? (u32(-1) << r + 1) : 0;
  u32 low = u32(-1) << l;
  return high ^ low;
}
template <class T>
inline enable_if_t<is_integral_v<T>, i32> id27(T x, i32 k) {
  return (x >> k) & 1;
}
template <class T>
inline enable_if_t<is_integral_v<T>, T> SetBit(T x, i32 k) {
  return x | (T(1) << k);
}
template <class T>
inline enable_if_t<is_integral_v<T>, T> ClearBit(T x, i32 k) {
  return x & ~(T(1) << k);
}
}  

namespace dalt {
template <class T>
struct Optional {
  using Self = Optional<T>;
 private:
  T val;
  bool show_up;
 public:
  Optional(const T &arg_val) : val(arg_val), show_up(true) {}
  Optional(const T &&arg_val) : val(arg_val), show_up(true) {}
  Optional() : show_up(false) {}
  const T &value() const {
    Assert(show_up);
    return val;
  }
  T &value() {
    Assert(show_up);
    return val;
  }
  T &operator*() { return value(); }
  const T &operator*() const { return value(); }
  bool is_some() const { return show_up; }
  bool is_none() const { return !show_up; }
  const T *operator->() const {
    return &value();
  }
  T *operator->() { return &value(); }
  inline operator T() const { return value(); }
  T or_else(T def) const {
    if (is_some()) {
      return val;
    } else {
      return def;
    }
  }
  template <class E>
  Optional<E> map(const Mapper<T, E> &mapper) const {
    if (is_some()) {
      return mapper(value());
    } else {
      return Optional<E>();
    }
  }
  bool operator==(const Self &b) const {
    return show_up == b.show_up && (!show_up || val == b.val);
  }
};
template <class E>
bool operator!=(const Optional<E> &a, const Optional<E> &b) {
  return !(a == b);
}
template <class E>
OStream &operator<<(OStream &os, const Optional<E> &v) {
  if (v.is_none()) {
    os << "{}";
  } else {
    os << '{' << v.value() << '}';
  }
  return os;
}
}  

namespace dalt {
template <class T>
inline enable_if_t<is_integral_v<T>, T> Gcd(T a, T b) {
  while (b != 0) {
    a %= b;
    Swap(a, b);
  }
  return a;
}


template <class T>
inline enable_if_t<is_integral_v<T>, Array<T, 3>> id18(T a, T b) {
  if (b == 0) {
    return Array<T, 3>{1, 0, a};
  }
  auto div = a / b;
  auto ans = id18(b, a - b * div);
  auto x = ans[0];
  auto y = ans[1];
  return Array<T, 3>{y, x - a / b * y, ans[2]};
}
template <class T>
inline enable_if_t<is_integral_v<T>, Optional<T>> id17(
    T a, T modulus) {
  auto res = id18(a, modulus);
  if (res[2] == 1) {
    auto ans = res[0] % modulus;
    if (ans < 0) {
      ans += modulus;
    }
    return ans;
  }
  return {};
}
}  

namespace dalt {
template <class T, class E>
T Modular(E val, T mod) {
  val = val % mod;
  if (val < 0) {
    val = val + mod;
  }
  return T(val);
}
template<class T>
inline T MulMod(T a, T b, T modulus) {
  i64 res = i64(a) * i64(b) % modulus;
  return T(res);
}
template<>
inline i64 MulMod<i64>(i64 a, i64 b, i64 modulus) {
  i64 k = roundl((f80)a / modulus * b);
  i64 res = (a * b - k * modulus) % modulus;
  if (res < 0) {
    res += modulus;
  }
  return res;
}
template <class T>
inline enable_if_t<is_integral_v<T>, T> AddMod(T a, T b, T modulus) {
  T res = a + b;
  if (res >= modulus) {
    res -= modulus;
  }
  return res;
}
template <class T, class E>
inline enable_if_t<is_integral_v<T> && is_integral_v<E>, T> PowMod(T x, E exp,
                                                                   T modulus) {
   Assert(exp >= E(0));                                                          
  if (exp == E(0)) {
    return modulus == T(1) ? T(0) : T(1);
  }
  T ans = PowMod(x, exp >> 1, modulus);
  ans = MulMod(ans, ans, modulus);
  if (exp & T(1)) {
    ans = MulMod(ans, x, modulus);
  }
  return ans;
}
template <class T>
inline enable_if_t<is_integral_v<T>, T> SubMod(T a, T b, T modulus) {
  T res = a - b;
  if (res < T(0)) {
    res += modulus;
  }
  return res;
}
}  

namespace dalt {
template <class T>
inline T& Chmin(T& a, const T& b) {
  if (a > b) {
    a = b;
  }
  return a;
}
template <class T>
inline T& Chmin(T& a, const T& b, const Comparator<T> &comp) {
  if (comp(b, a)) {
    a = b;
  }
  return a;
}
template <class T>
inline T& Chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
  }
  return a;
}
template <class T>
inline T& Chmax(T& a, const T& b, const Comparator<T>& comp) {
  if (comp(a, b)) {
    a = b;
  }
  return a;
}
template <class T>
inline T& AddTo(T& a, const T& b) {
  a = a + b;
  return a;
}
template <class T>
inline T& MulTo(T& a, const T& b) {
  a = a * b;
  return a;
}
template <class T>
inline T& SubFrom(T& a, const T& b) {
  a = a - b;
  return a;
}
template <class T>
inline T& DivFrom(T& a, const T& b) {
  a = a / b;
  return a;
}
template <class T, class E>
constexpr enable_if_t<is_integral_v<E>, T> id10(T x, E n) {
  if (n == E(0)) {
    return T(1);
  }
  auto ans = id10(x, n >> 1);
  ans = ans * ans;
  if (n & 1) {
    ans = ans * x;
  }
  return ans;
}
template <class T>
inline T MulLimit(T a, T b, T max, T def) {
  if (a == T(0) || b == T(0)) {
    return T(0);
  }
  

  

  

  if (a <= max / b) {
    return a * b;
  } else {
    return def;
  }
}
template <class T>
inline T MulLimit(T a, T b, T max) {
  return MulLimit(a, b, max, max);
}
template <class T>
inline T AddLimit(T a, T b, T max, T def) {
  if (a <= max - b) {
    return a + b;
  } else {
    return def;
  }
}
template <class T>
inline T AddLimit(T a, T b, T max) {
  return AddLimit(a, b, max, max);
}
i64 Round(f32 x) { return roundf(x); }
i64 Round(f64 x) { return round(x); }
i64 Round(f80 x) { return roundl(x); }


template<class T>
T id7(T l, T r) {
  if(l > r) {
    return T(0);
  }
  return (l + r) * (r - l + 1) / T(2);
}
template<class T>
T Pow2(T x) {
  return x * x;
}
}  

namespace dalt {






MakeAnnotation(modular);
template <class T, i64 M, i64 PR, i64 PHI = M - 1>
struct StaticModular {
  static_assert(is_integral_v<T>);
  const static T modulus = M;
  const static T primitive_root = PR;
  const static T phi = PHI;
  using Type = T;
};
template <class T, i64 M, i64 PR, i64 PHI>
struct is_modular<StaticModular<T, M, PR, PHI>> {
  static const bool value = true;
};
using MOD998244353 =
    StaticModular<i32, 998244353, 3>;
using MOD1000000007 = StaticModular<i32, 1000000007, 5>;
using MOD1000000009 = StaticModular<i32, 1000000009, 13>;
using MOD_BIG = StaticModular<i64, 2305843009213693951, -1>;


template <class T = i32, i64 CID = 0, i64 ID = 0>
struct DynamicModular {
  static_assert(is_integral_v<T>);
  static T modulus;
  static T primitive_root;
  static T phi;
  static void Register(T _modulus, T id25 = T(), T _phi = T()) {
    modulus = _modulus;
    primitive_root = id25;
    phi = _phi;
  }
  using Type = T;
};
template <class T, i64 CID, i64 ID>
T DynamicModular<T, CID, ID>::modulus = T();
template <class T, i64 CID, i64 ID>
T DynamicModular<T, CID, ID>::primitive_root = T();
template <class T, i64 CID, i64 ID>
T DynamicModular<T, CID, ID>::phi = T();
template <class T, i64 CID, i64 ID>
struct is_modular<DynamicModular<T, CID, ID>> {
  static const bool value = true;
};
MakeAnnotation(modint);



TEMPLATE_ARGS struct ModInt {
  using Modular = MODULAR;
  using Type = typename MODULAR::Type;
  static_assert(is_modular_v<MODULAR>);
  static_assert(is_integral_v<Type>);
  Type value;
  using Self = SELF;
  ModInt() : value(0) {}
  ModInt(const Type &v) {
    value = v;
    if (value < 0 || value >= MOD) {
      value %= MOD;
      if (value < 0) {
        value += MOD;
      }
    }
    Assert(value >= 0);
  }
  static Self nil() {
    Self res;
    res.value = -1;
    return res;
  }
  bool is_nil() {
    return value == -1;
  }
  explicit operator Type() const { return value; }
  static Type modulus() { return MOD; }
  static Type primitive_root() { return Modular::primitive_root; }
  Self operator-() const { return Self(0) - *this; }
  template <class F>
  static enable_if_t<is_integral_v<F>, Self> of(F v) {
    v %= MOD;
    if (v < 0) {
      v += MOD;
    }
    return Self(v);
  }
  Optional<Self> possible_inv() const {
    auto id35 = id17(value, MOD);
    if (id35.is_some()) {
      return Self(id35.value());
    } else {
      return {};
    }
  }
  Self operator+(const Self &rhs) const {
    auto res = value + rhs.value;
    if (res >= MOD) {
      res -= MOD;
    }
    return res;
  }
  Self operator-(const Self &rhs) const {
    auto res = value - rhs.value;
    if (res < Type(0)) {
      res += MOD;
    }
    return res;
  }
  Self operator/(const SELF &rhs) const {
    auto inv = Self(rhs.possible_inv().value());
    return (*this) * inv;
  }
  bool operator==(const Self &b) const { return value == b.value; }
  bool operator!=(const Self &b) const { return value != b.value; }
  bool operator<(const Self &b) const { return value < b.value; }
  ImplDefaultComparision(Self);
  ImplArithmeticAssignOperation(Self);
  template <class E>
  enable_if_t<is_integral_v<E>, Self> pow(E n) {
    return id10(*this, n);
  }
  friend inline IStream &operator>>(IStream &is, Self &x) {
    Type val;
    is >> val;
    x = Self(val);
    return is;
  }
  friend inline OStream &operator<<(OStream &os, const Self &x) {
    os << x.value;
    return os;
  }
};
TEMPLATE_ARGS inline enable_if_t<!is_same_v<MODULAR, MOD_BIG>, SELF> operator*(
    const SELF &a, const SELF &b) {
  return SELF(MulMod(a.value, b.value, MOD));
}
TEMPLATE_ARGS inline enable_if_t<is_same_v<MODULAR, MOD_BIG>, SELF> operator*(
    const SELF &x, const SELF &y) {
  static u64 mask = (u64(1) << 32) - 1;
  static u64 mod = MOD_BIG::modulus;
  u64 a = x.value;
  u64 b = y.value;
  u64 l1 = a & mask;
  u64 h1 = (a >> 32) & mask;
  u64 l2 = b & mask;
  u64 h2 = (b >> 32) & mask;
  u64 l = l1 * l2;
  u64 m = l1 * h2 + l2 * h1;
  u64 h = h1 * h2;
  u64 ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + ((m << 35) >> 3) + 1;
  ret = (ret & mod) + (ret >> 61);
  ret = (ret & mod) + (ret >> 61);
  return SELF(ret - 1);
}
TEMPLATE_ARGS struct is_modint<ModInt<MODULAR>> {
  static const bool value = true;
};


using ModInt998244353 = ModInt<MOD998244353>;
using ModInt1000000007 = ModInt<MOD1000000007>;
using ModInt1000000009 = ModInt<MOD1000000009>;
}  

namespace dalt {
namespace hash {


inline u64 Shuffle(u64 x) {
  static const uint64_t C = uint64_t(2e18 * M_PI) + 71;  

  static const int RANDOM = rng();
  return __builtin_bswap64((x ^ RANDOM) * C);
}
i64 SafeHash(const void *ptr, usize size) {
  using Mi1 = ModInt1000000007;
  using Mi2 = ModInt1000000009;
  static const Mi1 X1 = Mi1(random_choice<i32>(1, Mi1::modulus() - 1));
  static const Mi2 X2 = Mi2(random_choice<i32>(1, Mi2::modulus() - 1));
  Mi1 ans1 = Mi1(size);
  Mi2 ans2 = Mi2(size);
  const char *cur = (const char *)ptr;
  int offset = 0;
  while (size - offset >= 4) {
    i32 v = *(i32 *)(cur + offset);
    ans1 = ans1 * X1 + Mi1(v);
    ans2 = ans2 * X2 + Mi2(v);
    offset += 4;
  }
  if (size - offset >= 2) {
    i32 v = *(i16 *)(cur + offset);
    ans1 = ans1 * X1 + Mi1(v);
    ans2 = ans2 * X2 + Mi2(v);
    offset += 2;
  }
  if (size - offset >= 1) {
    i32 v = *(i8 *)(cur + offset);
    ans1 = ans1 * X1 + Mi1(v);
    ans2 = ans2 * X2 + Mi2(v);
    offset += 1;
  }
  return (i64(ans1.value) << 32) | ans2.value;
}
i64 FastHash(const void *ptr, usize size) {
  static const i64 X = random_choice<i64>(std::numeric_limits<i64>::min(),
                                          std::numeric_limits<i64>::max());
  const char *cur = (const char *)ptr;
  int offset = 0;
  i64 ans = size;
  while (size - offset >= 8) {
    i64 v = *((i64 *)(cur + offset));
    ans = ans * X + v;
    offset += 8;
  }
  if (size - offset >= 4) {
    i64 v = *((i32 *)(cur + offset));
    ans = ans * X + v;
    offset += 4;
  }
  if (size - offset >= 2) {
    i64 v = *((i16 *)(cur + offset));
    ans = ans * X + v;
    offset += 2;
  }
  if (size - offset >= 1) {
    i64 v = *((u8 *)(cur + offset));
    ans = ans * X + v;
    offset += 1;
  }
  return ans;
}
template <class T>
inline i64 Hash(const T &val) {
  return SafeHash(&val, sizeof(T));
}
template <>
inline i64 Hash<i64>(const i64 &val) {
  return val;
}
template <>
inline i64 Hash<i32>(const i32 &val) {
  return val;
}
}  

}  

namespace dalt {
template <class T> enable_if_t<is_integral_v<T>, T> DivFloor(T a, T b) {
  Assert(b > 0);
  auto ans = a / b;
  if (ans * b > a) {
    ans = ans - 1;
  }
  return ans;
}
template <class T> enable_if_t<is_integral_v<T>, T> id9(T a, T b) {
  Assert(b > 0);
  auto ans = a / b;
  if (ans * b < a) {
    ans = ans + 1;
  }
  return ans;
}
template <class T>
enable_if_t<is_floating_point_v<T>, T> DivFloor(T a, T b) {
  return a / b;
}
template <class T>
enable_if_t<is_floating_point_v<T>, T> id9(T a, T b) {
  return a / b;
}
template <class T>
enable_if_t<is_integral_v<T>, T> id19(T val) {
  return val - 1;
}
template <class T>
enable_if_t<is_integral_v<T>, T> id20(T val) {
  return val + 1;
}
template <class T>
enable_if_t<is_floating_point_v<T>, T> id19(T val) {
  return val;
}
template <class T>
enable_if_t<is_floating_point_v<T>, T> id20(T val) {
  return val;
}
} 

namespace dalt {
template <class T>
bool InRange(T l, T r, T x) {
  return l <= x && x <= r;
}
template <class T>
bool id22(T l, T r, T x) {
  if (l <= r) {
    return InRange(l, r, x);
  } else {
    return !InRange(id20(r), id19(l), x);
  }
}
}  

namespace dalt {
struct Nil {};
Nil operator+(const Nil &a, const Nil &b) { return Nil(); }
Nil operator-(const Nil &a, const Nil &b) { return Nil(); }
Nil operator*(const Nil &a, const Nil &b) { return Nil(); }
Nil operator/(const Nil &a, const Nil &b) { return Nil(); }
bool operator==(const Nil &a, const Nil &b) { return true; }
bool operator!=(const Nil &a, const Nil &b) { return false; }
OStream &operator<<(OStream &os, const Nil &b) {
  os << "{}";
  return os;
}
} 

namespace dalt {
namespace hash {
template <class K, class V = Nil>
struct HashMap {
  using Self = HashMap<K, V>;
 private:
  static const i32 NON_EXIST = 0;
  Vec<Pair<K, V>> entries;
  Vec<i32> hash_val;
  i32 mask;
  i32 size;
  int index_of(const K& key, i32 h) const {
    i32 index = h & mask;
    while (hash_val[index] != NON_EXIST) {
      if (hash_val[index] == h && entries[index].first == key) {
        return index;
      }
      index = (index + 1) & mask;
    }
    return index;
  }
 public:
  struct CIter
      : public std::iterator<std::bidirectional_iterator_tag, Pair<K, V>> {
    const HashMap<K, V>* hm;
    i32 index;
    const Pair<K, V>& operator*() {
      Assert(index < Size(hm->entries));
      Assert(hm->hash_val[index] != NON_EXIST);
      return hm->entries[index];
    }
    const Pair<K, V>* operator->() const {
      return &hm->entries[index];
    }
    CIter& operator++() {
      index++;
      while (index < Size(hm->entries) && hm->hash_val[index] == NON_EXIST) {
        index++;
      }
      return *this;
    }
    CIter operator++(int) {
      auto ans = *this;
      ++(*this);
      return ans;
    }
    CIter& operator--() {
      index--;
      while (index >= 0 && hm->hash_val[index] == NON_EXIST) {
        index--;
      }
      return *this;
    }
    CIter operator--(int) {
      Iter ans = *this;
      --(*this);
    }
    bool operator<(const CIter& rhs) const { return index < rhs.index; }
    bool operator>(const CIter& rhs) const { return index > rhs.index; }
    bool operator==(const CIter& rhs) const { return index == rhs.index; }
    bool operator!=(const CIter& rhs) const { return index != rhs.index; }
  };
  struct Iter
      : public std::iterator<std::bidirectional_iterator_tag, Pair<K, V>> {
    HashMap<K, V>* hm;
    i32 index;
    Pair<K, V>& operator*() {
      Assert(index < Size(hm->entries));
      Assert(hm->hash_val[index] != NON_EXIST);
      return hm->entries[index];
    }
    const Pair<K, V>& operator*() const {
      Assert(index < Size(hm->entries));
      Assert(hm->hash_val[index] != NON_EXIST);
      return hm->entries[index];
    }
    Pair<K, V>* operator->() { return &hm->entries[index]; }
    Iter& operator++() {
      index++;
      while (index < Size(hm->entries) && hm->hash_val[index] == NON_EXIST) {
        index++;
      }
      return *this;
    }
    Iter operator++(int) {
      auto ans = *this;
      ++(*this);
      return ans;
    }
    Iter& operator--() {
      index--;
      while (index >= 0 && hm->hash_val[index] == NON_EXIST) {
        index--;
      }
      return *this;
    }
    Iter operator--(int) {
      Iter ans = *this;
      --(*this);
    }
    bool operator<(const Iter& rhs) { return index < rhs.index; }
    bool operator>(const Iter& rhs) { return index > rhs.index; }
    bool operator==(const Iter& rhs) { return index == rhs.index; }
    bool operator!=(const Iter& rhs) { return index != rhs.index; }
  };
  void recap(i32 cap) {
    cap = Max(cap, 2);
    decltype(entries) old_entry(cap);
    decltype(hash_val) id28(cap);
    entries.swap(old_entry);
    hash_val.swap(id28);
    mask = cap - 1;
    size = 0;
    for (int i = 0; i < Size(old_entry); i++) {
      if (id28[i] != NON_EXIST) {
        put(Move(old_entry[i]), id28[i]);
      }
    }
  }
  bool contain(const K& key) const {
    return find(key) != end();
  }
  i32 get_hash(i64 hash) const {
    hash = Shuffle(hash);
    if (hash == NON_EXIST) {
      hash = -1;
    }
    return hash;
  }
  bool check_health() {
    if (size * 2 > Size(entries)) {
      recap(Size(entries) * 2);
      return true;
    }
    return false;
  }
  void put(Pair<K, V> kv, i32 hash) {
    auto& key = kv.first;
    i32 pos = index_of(kv.first, hash);
    if (hash_val[pos] == NON_EXIST) {
      size++;
    }
    entries[pos] = Move(kv);
    hash_val[pos] = hash;
    check_health();
  }
 public:
  HashMap(i32 cap = 1) : size(0) {
    cap = 1 << id16(cap);
    recap(cap * 2);
  }
  int get_size() const {
    return size;
  }
  void put(Pair<K, V> kv) { put(Move(kv), get_hash(Hash(kv.first))); }
  void put(K key, V value) { put(Pair<K, V>(Move(key), Move(value))); }
  Iter find(const K& key) {
    i32 hash = get_hash(Hash(key));
    i32 pos = index_of(key, hash);
    if (hash_val[pos] != NON_EXIST) {
      return Iter{
          .hm = this,
          .index = pos,
      };
    }
    return end();
  }
  CIter find(const K& key) const {
    i32 hash = get_hash(Hash(key));
    i32 pos = index_of(key, hash);
    if (hash_val[pos] != NON_EXIST) {
      return CIter{
          .hm = this,
          .index = pos,
      };
    }
    return end();
    return end();
  }
  V& operator[](const K& key) {
    i32 hash = get_hash(Hash(key));
    i32 pos = index_of(key, hash);
    if (hash_val[pos] != NON_EXIST) {
      return entries[pos].second;
    }
    entries[pos] = Pair<K, V>(key, V());
    hash_val[pos] = hash;
    size++;
    if (check_health()) {
      return (*this)[key];
    }
    return entries[pos].second;
  }
  void remove(const K& key) {
    i32 hash = get_hash(Hash(key));
    i32 h = index_of(key, hash);
    if (hash_val[h] == NON_EXIST) {
      return;
    }
    size--;
    hash_val[h] = NON_EXIST;
    int iter = (h + 1) & mask;
    while (hash_val[iter] != NON_EXIST) {
      i32 insert_pos = hash_val[iter] & mask;
      if (id22(iter + 1, h, insert_pos)) {
        Swap(entries[h], entries[iter]);
        Swap(hash_val[h], hash_val[iter]);
        h = iter;
      }
      iter = (iter + 1) & mask;
    }
  }
  CIter end() const {
    return CIter{
        .hm = this,
        .index = Size(hash_val),
    };
  }
  CIter rbegin() const {
    return --CIter{
        .hm = this,
        .index = Size(hash_val),
    };
  }
  CIter rend() const {
    return CIter{
        .hm = this,
        .index = -1,
    };
  }
  CIter begin() const {
    return ++CIter{
        .hm = this,
        .index = -1,
    };
  }
  Iter begin() {
    return ++Iter{
        .hm = this,
        .index = -1,
    };
  }
  Iter end() {
    return Iter{
        .hm = this,
        .index = Size(hash_val),
    };
  }
  Iter rbegin() {
    return --Iter{
        .hm = this,
        .index = Size(hash_val),
    };
  }
  Iter rend() {
    return Iter{
        .hm = this,
        .index = -1,
    };
  }
  Vec<Pair<K, V>> to_vec() const {
    Vec<Pair<K, V>> res;
    for (auto& kv : *this) {
      res.push_back(kv);
    }
    return res;
  }
};
}  

}  





namespace dalt {
namespace seq {




struct id30 {
  struct Node {
    int id;
    Node *fail;
    int len;
    int depth;
    Vec<Node *> children;
  };
  Node *odd;
  Node *even;
  hash::HashMap<u64, Node *> hm;
  Vec<i32> data;
  int zero;
  int front_size;
  int back_size;
  Node *id6;
  Node *id31;
  Vec<Node *> all;
  i64 id26;
  Node *newNode() {
    auto ans = new Node();
    ans->id = Size(all);
    all.push_back(ans);
    return ans;
  }
  Node *GetChild(Node *node, int index) {
    var iter = hm.find(IdOf(node, index));
    return iter == hm.end() ? NULL : iter->second;
  }
  void SetChild(Node *node, int index, Node *item) {
    hm[IdOf(node, index)] = item;
  }
  u64 IdOf(Node *node, int index) { return u64(node->id) << 32 | index; }
  id30(int id12, int id23 = 0)
      : id26(0) {
    int cap = id23 + id12;
    all.reserve(2 + cap);
    data.resize(cap);
    zero = id23;
    front_size = zero - 1;
    back_size = zero;
    odd = newNode();
    odd->len = -1;
    odd->depth = 0;
    odd->id = -1;
    even = newNode();
    even->fail = odd;
    even->len = 0;
    even->depth = 0;
    even->id = -2;
    all.clear();
    id31 = id6 = odd;
    hm = decltype(hm)(cap);
  }
  void push_front(i32 c) {
    data[front_size--] = c;
    int index = c;
    auto trace = id6;
    while (front_size + 2 + trace->len >= back_size) {
      trace = trace->fail;
    }
    while (data[front_size + trace->len + 2] != c) {
      trace = trace->fail;
    }
    var id32 = hm.find(IdOf(trace, index));
    if (id32 != hm.end()) {
      id6 = id32->second;
    } else {
      auto now = newNode();
      now->len = trace->len + 2;
      hm[IdOf(trace, index)] = now;
      if (now->len == 1) {
        now->fail = even;
      } else {
        trace = trace->fail;
        while (data[front_size + trace->len + 2] != c) {
          trace = trace->fail;
        }
        now->fail = hm[IdOf(trace, index)];
      }
      now->depth = now->fail->depth + 1;
      id6 = now;
    }
    if (id6->len == back_size - front_size - 1) {
      id31 = id6;
    }
    id26 += id6->depth;
  }
  void push_back(i32 c) {
    data[back_size++] = c;
    int index = c;
    auto trace = id31;
    while (back_size - 2 - trace->len <= front_size) {
      trace = trace->fail;
    }
    while (data[back_size - trace->len - 2] != c) {
      trace = trace->fail;
    }
    var id32 = hm.find(IdOf(trace, index));
    if (id32 != hm.end()) {
      id31 = id32->second;
    } else {
      auto now = newNode();
      now->len = trace->len + 2;
      hm[IdOf(trace, index)] = now;
      if (now->len == 1) {
        now->fail = even;
      } else {
        trace = trace->fail;
        while (data[back_size - trace->len - 2] != c) {
          trace = trace->fail;
        }
        now->fail = hm[IdOf(trace, index)];
      }
      now->depth = now->fail->depth + 1;
      id31 = now;
    }
    if (id31->len == back_size - front_size - 1) {
      id6 = id31;
    }
    id26 += id31->depth;
  }
  void visit(Consumer<Node *> consumer) {
    for (int i = Size(all) - 1; i >= 0; i--) {
      consumer(all[i]);
    }
  }
  i64 get_palindrome_substring_cnt() const { return id26; }
  int get_distinct_palindrome_substring() const { return Size(all); }

  ~id30() {
    delete odd;
    delete even;
    for (var item : all) {
      delete item;
    }
  }

};
}  

}  


template<class T> struct SegTree {  

  const T ID = -1;
  T cmb(T a, T b) { return Max(a, b); }
  int n;
  Vec<T> seg;
  void init(int _n) {  

    for (n = 1; n < _n;) n *= 2;
    seg.assign(2 * n, ID);
  }
  void pull(int p) { seg[p] = cmb(seg[2 * p], seg[2 * p + 1]); }
  void upd(int p, T val) {  

    seg[p += n] = val;
    for (p /= 2; p; p /= 2) pull(p);
  }
  T query(int l, int r) {  

    T ra = ID, rb = ID;
    for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) ra = cmb(ra, seg[l++]);
      if (r & 1) rb = cmb(seg[--r], rb);
    }
    return cmb(ra, rb);
  }
  

  

  

  

  

};
void SolveOne(int test_id, IStream &in, OStream &out) {
  

  

  int Q;
  in >> Q;
  seq::id30 tree(Q);
  using Node = seq::id30::Node;
  Vec<Node *> nodes(Q);
  nodes.clear();
  int total_size = 0;
  for(int i = 0; i < Q; i++) {
    Str op;
    in >> op;
    if(op == "push") {
      char c;
      in >> c;
      tree.push_back(c);
      nodes.push_back(tree.id31);
      total_size++;
    } else {
      if(tree.id31->len == total_size) {
        tree.id31 = tree.id31->fail; 
      }
      tree.front_size++;
      nodes.push_back(NULL);
    }
  }
  int N = Size(tree.all);
  for(var node : tree.all) {
    node->fail->children.push_back(node);
  }
  Vec<Pair<int, int>> range(N, MakePair(-1, -1));
  int id_allocator = 0;
  var dfs = [&](var &dfs, Node* root) {
    if(range[root->id].first != -1) {
      return;
    }
    range[root->id].first = id_allocator++;
    for(var node : root->children) {
      dfs(dfs, node);
    }
    range[root->id].second = id_allocator - 1;
  };
  for(var node : tree.all) {
    dfs(dfs, node);
  }
  var adder = [&](int a, int b) {
    return Max(a, b);
  };
  

  

  Vec<Vec<Node *>> events(Q);
  int front = 0;
  total_size = 0;
  SegTree<int> st;
  st.init(N);
  int cnt = 0;
  var eval = [&](Node *node) {
    return st.query(range[node->id].first, range[node->id].second);
  };
  Debug(range);
  for (int i = 0; i < Q; i++) {
    Debug(i);
    if(nodes[i] != NULL) {
      total_size++;
      

      int right = eval(nodes[i]);
      if (right - nodes[i]->len >= front) {
        cnt--;
      }
      cnt++;
      st.upd(range[nodes[i]->id].first,
                total_size);
      events[total_size - nodes[i]->len].push_back(nodes[i]);
    } else {
      

      for(var node : events[front]) {
        int right = eval(node);
        if (right - node->len <= front) {
          cnt--;
          var fail = node->fail;
          if(fail->id >= 0) {
            events[right - fail->len].push_back(fail);
          }
          break;
        }
      }
      front++;
    }
    out << cnt << '\n';
  }
}
void SolveMulti(IStream &in, OStream &out) {
  

  int id1 = 1;
  

  for (int i = 0; i < id1; i++) {
    

	SolveOne(i + 1, in, out);
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  Stdin.tie(0);
  Stdout << std::setiosflags(std::ios::fixed);
  Stdout << std::setprecision(15);

  stress::Stress();

  SolveMulti(Stdin, Stdout);

  return 0;
}