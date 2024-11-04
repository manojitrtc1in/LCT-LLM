













namespace algo {
namespace detail {
template <typename Tp>
concept integer = std::integral<Tp> && !std::same_as<Tp, bool>;
template <typename Tp>
concept signed_integer = integer<Tp> &&(Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> &&(Tp(-1) > Tp(0));
template <typename Tp>
concept addable = requires(std::remove_reference_t<Tp> &a,
                           const std::remove_reference_t<Tp> &b) {
  { a += b } -> std::same_as<std::remove_reference_t<Tp> &>;
};
template <typename Tp>
concept multipliable = requires(std::remove_reference_t<Tp> &a,
                                const std::remove_reference_t<Tp> &b) {
  { a *= b } -> std::same_as<std::remove_reference_t<Tp> &>;
};
template <typename Function, typename ReturnType, typename... Args>
concept callable = std::invocable<Function, Args...> &&
    std::same_as<std::invoke_result_t<Function, Args...>, ReturnType>;
template <typename Function, typename Arg>
concept unary_op = callable<Function, Arg, Arg>;
template <typename Function, typename Arg>
concept binary_op = callable<Function, Arg, Arg, Arg>;
template <typename Tp>
concept less_than_comparable = requires(const std::remove_reference_t<Tp> &a,
                                        const std::remove_reference_t<Tp> &b) {
  { a < b } -> std::convertible_to<bool>;
  { !(a < b) } -> std::convertible_to<bool>;
};
template <typename Tp>
concept equality_comparable = std::equality_comparable<Tp>;
template <typename From, typename To>
concept constructible = std::constructible_from<To, From>;
template <typename InputIterator, typename ValueType>
concept input_iterator = std::input_iterator<InputIterator> &&
    std::same_as<std::iter_value_t<InputIterator>, ValueType>;
template <typename Tp>
concept qword_fittable = integer<Tp> && sizeof(Tp) <= 8UL;
template <typename Tp>
concept dword_fittable = qword_fittable<Tp> && sizeof(Tp) <= 4UL;
template <typename Tp>
concept word_fittable = dword_fittable<Tp> && sizeof(Tp) <= 2UL;
template <typename Tp>
concept byte_fittable = word_fittable<Tp> && sizeof(Tp) == 1UL;
template <integer Tp>
struct safely_multipliable;
template <>
struct safely_multipliable<char> {
  using type = int16_t;
};
template <>
struct safely_multipliable<unsigned char> {
  using type = uint16_t;
};
template <>
struct safely_multipliable<short> {
  using type = int32_t;
};
template <>
struct safely_multipliable<int> {
  using type = int64_t;
};
template <>
struct safely_multipliable<unsigned int> {
  using type = uint64_t;
};
template <>
struct safely_multipliable<long> {
  using type = __int128_t;
};
template <>
struct safely_multipliable<unsigned long> {
  using type = __uint128_t;
};
template <>
struct safely_multipliable<long long> {
  using type = __int128_t;
};
template <>
struct safely_multipliable<unsigned long long> {
  using type = __uint128_t;
};
template <typename Tp>
using safe_mul_t = typename safely_multipliable<Tp>::type;
template <typename Function>
struct function_traits
    : public function_traits<
          decltype(&std::remove_reference_t<Function>::operator())> {};
template <typename Function, typename ReturnType, typename... Args>
struct function_traits<ReturnType (Function::*)(Args...) const> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = std::tuple_element_t<I, std::tuple<Args...>>;
  };
};
template <typename ReturnType, typename... Args>
struct function_traits<ReturnType (*)(Args...)> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = std::tuple_element_t<I, std::tuple<Args...>>;
  };
};
template <typename ReturnType, typename... Args>
struct function_traits<ReturnType(Args...)> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = std::tuple_element_t<I, std::tuple<Args...>>;
  };
};
}
}
namespace algo {
namespace detail {
template <dword_fittable Tp>
constexpr int
id8(Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable Tp>
constexpr int
id8(Tp n) {
  return __builtin_clzll(n);
}
template <dword_fittable Tp>
constexpr int
id9(Tp n) {
  return __builtin_ctz(n);
}
template <qword_fittable Tp>
constexpr int
id9(Tp n) {
  return __builtin_ctzll(n);
}
template <dword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 32 - id8(n);
}
template <qword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 64 - id8(n);
}
template <dword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1u << (31 - id8(n));
}
template <qword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1ull << (63 - id8(n));
}
template <integer Tp>
constexpr Tp
id0(Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return bit_floor(n - 1) << 1;
}
template <dword_fittable Tp>
constexpr int
id1(Tp n) {
  return 31 - id8(n);
}
template <qword_fittable Tp>
constexpr int
id1(Tp n) {
  return 63 - id8(n);
}
template <integer Tp>
constexpr int
id2(Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return id1(n - 1) + 1;
}
template <dword_fittable Tp>
constexpr int
popcount(Tp n) {
  return __builtin_popcount(n);
}
template <qword_fittable Tp>
constexpr int
popcount(Tp n) {
  return __builtin_popcountll(n);
}
}
}
namespace algo {
template <detail::integer Tp>
constexpr int
id7(Tp n) {
  return detail::id8(n);
}
template <detail::integer Tp>
constexpr int
id4(Tp n) {
  return detail::id8(~n);
}
template <detail::integer Tp>
constexpr int
id3(Tp n) {
  return detail::id9(n);
}
template <detail::integer Tp>
constexpr int
id5(Tp n) {
  return detail::id9(~n & (n + 1));
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
bit_floor(Tp n) {
  return detail::bit_floor(n);
}
template <detail::integer Tp>
constexpr Tp
id0(Tp n) {
  return detail::id0(n);
}
template <detail::integer Tp>
constexpr int
id1(Tp n) {
  return detail::id1(n);
}
template <detail::integer Tp>
constexpr int
id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}
namespace dbg {

}
namespace algo {
namespace detail {
constexpr bool
likely(bool x) noexcept {
  return __builtin_expect(x, 1);
}
constexpr bool
unlikely(bool x) noexcept {
  return __builtin_expect(x, 0);
}
constexpr void
unreachable() noexcept {
  __builtin_unreachable();
}
constexpr void
assume(bool expr) noexcept {
  if (!expr) unreachable();
}
}
}
namespace algo {
namespace detail {
template <integer Tp>
constexpr Tp
sqrt(Tp n) {
  if (n == 0) { return 0; }
  if (n == 1) { return 1; }
  Tp ans = 0;
  for (int i = id1(n) - 1; i >= 0; --i) {
    const Tp tmp = (n - ans * ans) >> i;
    if ((ans << 1) + (Tp(1) << i) <= tmp) { ans |= Tp(1) << i; }
  }
  return ans;
}
template <integer Tp>
constexpr Tp
abs(Tp n) {
  if constexpr (std::is_signed_v<Tp>) {
    return n < 0 ? -n : n;
  } else {
    return n;
  }
}
template <integer Tp>
constexpr Tp
id6(Tp x, Tp y) {
  if constexpr (std::is_unsigned_v<Tp>) {
    return x / y + (x % y != 0);
  } else {
    return x / y + (x % y != 0 && (x ^ y) >= 0);
  }
}
template <std::integral Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, int>>
id10(Tp n) {
  return -(n & 1) | 1;
}
template <integer Tp>
constexpr Tp
floor_sum(Tp a, Tp b, Tp c, Tp n) {
  Tp res = 0;
  bool neg = false;
  while (a != 0) {
    if (a < c && b < c) {
      const Tp m = (a * n + b) / c;
      const Tp tmp = a;
      res += id10(neg) * m * n;
      b = c - b - 1, a = c, c = tmp, n = m - 1;
      neg ^= true;
    } else {
      const Tp tmp = (n * (n + 1) >> 1) * (a / c) + (n + 1) * (b / c);
      res += id10(neg) * tmp;
      a %= c, b %= c;
    }
  }
  res += id10(neg) * (b / c) * (n + 1);
  return res;
}
}
}
namespace algo {
template <detail::integer Tp>
constexpr Tp
sqrt(Tp n) {
  assert(n >= 0);
  return detail::sqrt(n);
}
template <detail::integer Tp>
constexpr Tp
abs(Tp n) {
  return detail::abs(n);
}
template <detail::integer Tp>
constexpr Tp
id6(Tp x, Tp y) {
  assert(y != 0);
  return detail::id6(x, y);
}
template <detail::integer Tp>
constexpr std::make_signed_t<Tp>
id10(Tp n) {
  return detail::id10(n);
}
template <detail::integer Tp>
constexpr Tp
floor_sum(Tp a, Tp b, Tp c, Tp n) {
  assert(n >= 0);
  assert(c > 0);
  return detail::floor_sum(a, b, c, n);
}
}
namespace algo {
class two_sat {
  struct scc_node {
    int time_ = -1;
    int low_ = -1;
    int comp_ = -1;
    std::vector<int> adj_;
  };
public:
  two_sat() : two_sat(0){};
  two_sat(int n) : n_(n), valid_(-1), nodes_(n_ << 1), scc_{}, ans_(n_) {}
  void
  add_disjunction(int u, int v, bool nu, bool nv) {
    assert(0 <= u && u < n_);
    assert(0 <= v && v < n_);
    u = (u << 1) ^ nu;
    v = (v << 1) ^ nv;
    nodes_[u ^ 1].adj_.emplace_back(v);
    nodes_[v ^ 1].adj_.emplace_back(u);
  }
  bool
  solve() {
    if (detail::likely(valid_ == -1)) {
      scc_.reserve(n_);
      int time = 0, cc = 0;
      const int tot = n_ << 1;
      for (int u = 0; u < tot; ++u) {
        if (nodes_[u].time_ == -1) {
          std::tie(time, cc) = traverse(u, time, cc);
        }
      }
      for (int u = 0; u < tot; u += 2) {
        if (nodes_[u].comp_ == nodes_[u ^ 1].comp_) {
          valid_ = false;
          return false;
        }
        ans_[u >> 1] = nodes_[u].comp_ < nodes_[u ^ 1].comp_;
      }
      valid_ = true;
    }
    return valid_;
  }
  std::vector<int8_t>
  answer() const {
    assert(valid_ == 1);
    return ans_;
  }
private:
  std::pair<int, int>
  traverse(int u, int time, int cc) {
    nodes_[u].time_ = time;
    nodes_[u].low_ = time;
    scc_.emplace_back(u);
    time++;
    for (const int v : nodes_[u].adj_) {
      if (nodes_[v].time_ == -1) {
        std::tie(time, cc) = traverse(v, time, cc);
        nodes_[u].low_ = std::min(nodes_[u].low_, nodes_[v].low_);
      } else if (nodes_[v].low_ != -1) {
        nodes_[u].low_ = std::min(nodes_[u].low_, nodes_[v].time_);
      }
    }
    if (nodes_[u].low_ == nodes_[u].time_) {
      while (scc_.back() != u) {
        const int w = scc_.back();
        scc_.pop_back();
        nodes_[w].comp_ = cc;
      }
      scc_.pop_back();
      nodes_[u].comp_ = cc;
      cc++;
    }
    return std::pair(time, cc);
  }
  int n_, valid_;
  std::vector<scc_node> nodes_;
  std::vector<int> scc_;
  std::vector<int8_t> ans_;
};
}

using std::array;
using std::vector;
using std::bitset;
using std::stack;
using std::queue;
using std::deque;
using std::set;
using std::map;
using std::multimap;
using std::multiset;
using std::complex;
using std::string;
using std::pair;
using std::tuple;
using std::cin;
using std::cout;
using std::endl;
using std::gcd;
using std::tie;
using std::lcm;
using std::max;
using std::min;
using std::swap;
using std::to_string;
template <typename Tp, typename Function>
using ordered_set = __gnu_pbds::tree<Tp,
__gnu_pbds::null_type, Function, __gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>;
using wint = int64_t;
template <typename KeyType, typename ValueType>
using umap = std::unordered_map<KeyType, ValueType>;
template <typename ValueType> using uset = std::unordered_set<ValueType>;
template <typename Tp, typename Function = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Function>;
template <typename Tp, typename Function = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Function>;





template <typename Tp>
constexpr void chmax(Tp &x, const Tp &y) { x = max(x, y); }
template <typename Tp>
constexpr void chmin(Tp &x, const Tp &y) { x = min(x, y); }
namespace {
}
void solve() noexcept {
  struct edge{
    int u,v,w;
  };
  int n,m;cin>>n>>m;
  vector<edge>es(n-1);
  algo::two_sat ts(n);
  for(int i=0;i<n-1;++i){
    int x,y,v;cin>>x>>y>>v;
    --x,--y;
    es[i]={x,y,v};
    if(v!=-1){
      const bool p=algo::popcount(v)&1;
      if(p){
        ts.add_disjunction(x,y,0,0);
        ts.add_disjunction(x,y,1,1);
      }else{
        ts.add_disjunction(x,y,0,1);
        ts.add_disjunction(x,y,1,0);
      }
    }
  }
  while(m--){
    int a,b,p;cin>>a>>b>>p;
    --a,--b;
    if(p){
      ts.add_disjunction(a,b,0,0);
      ts.add_disjunction(a,b,1,1);
    }else{
      ts.add_disjunction(a,b,0,1);
      ts.add_disjunction(a,b,1,0);
    }
  }
  if(!ts.solve()){cout<<"NO\n";return;}
  cout<<"YES\n";
  vector f=ts.answer();
  for(int i=0;i<n-1;++i){
    auto[u,v,w]=es[i];
    if(w==-1){
      w=f[u]^f[v];
    }
    cout<<u+1<<' '<<v+1<<' '<<w<<'\n';
  }
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  int tc;
  std::cin >> tc;
  while (tc--) { solve(); }
  return 0;
}
