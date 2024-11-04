





























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
constexpr enable_if_t<is_integral_v<E>, T> PowBinaryLift(T x, E n) {
  if (n == E(0)) {
    return T(1);
  }
  auto ans = PowBinaryLift(x, n >> 1);
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
T id2(T l, T r) {
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

void SolveOne(int test_id, IStream &in, OStream &out) {
  int N, K;
  in >> N >> K;
  Vec<Str> grid(N);
  in >> grid;
  using A2 = Array<int, 2>;
  var diagonal = [&](int x, int y, int k) {
    int t = Min(x, y);
    x -= t;
    y -= t;
    x += k;
    y += k;
    return A2{x, y};
  };
  var id1 = [&](int x, int y, int k) {
    var res = diagonal(x, y, k);
    return grid[res[0]][res[1]] == '1';
  };
  var rank = [&](int x, int y) {
    int t = Min(x, y);
    return t;
  };
  int round = N - K + 1;
  Vec<int> cur_rank(2 * N, -1);
  Vec<Vec<bool>> deleted(N, Vec<bool>(N));
  bool ok = true;
  var delete_item = [&](int x, int y, int k) {
    var res = diagonal(x, y, k);
    if (res[0] >= N || res[1] >= N) {
      ok = false;
      return;
    }
    deleted[res[0]][res[1]] = true;
  };
  var id4 = cur_rank.data() + N;
  for (int i = 0; i < round && ok; i++) {
    id4[0]++;
    if (i > 0) {
      Chmax(id4[0], id4[1] + 1);
      Chmax(id4[0], id4[-1] + 1);
    }
    while (id4[0] < N && !id1(0, 0, id4[0])) {
      id4[0]++;
    }
    delete_item(0, 0, id4[0]);
    for (int j = 1; j < N && ok; j++) {
      if (round - j <= i) {
        continue;
      }
      int x0 = j;
      int y0 = 0;
      int len = N - j;
      int offset = x0 - y0;
      id4[offset]++;
      Chmax(id4[offset], id4[offset - 1]);
      Chmax(id4[offset], id4[offset + 1] + 1);
      while (id4[offset] < len &&
             !id1(x0, y0, id4[offset])) {
        id4[offset]++;
      }
      delete_item(x0, y0, id4[offset]);
    }
    for (int j = 1; j < N && ok; j++) {
      if (round - j <= i) {
        continue;
      }
      int x0 = 0;
      int y0 = j;
      int len = N - j;
      int offset = x0 - y0;
      id4[offset]++;
      Chmax(id4[offset], id4[offset + 1]);
      Chmax(id4[offset], id4[offset - 1] + 1);
      while (id4[offset] < len &&
             !id1(x0, y0, id4[offset])) {
        id4[offset]++;
      }
      delete_item(x0, y0, id4[offset]);
    }
    Debug(i);
    Debug(deleted);
    Debug(cur_rank);
  }
  if (!ok) {
    out << "NO" << '\n';
    return;
  }
  out << "YES" << '\n';
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      out << 1 - int(deleted[i][j]);
    }
    out << '\n';
  }
}
void SolveMulti(IStream &in, OStream &out) {
  

  int id0 = 1;
  in >> id0;
  for (int i = 0; i < id0; i++) {
    

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