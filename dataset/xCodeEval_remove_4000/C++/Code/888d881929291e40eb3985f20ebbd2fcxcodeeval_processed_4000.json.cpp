













































namespace algo::detail {
template <typename Tp>
concept integer = std::integral<Tp> && !std::same_as<Tp, bool>;
template <typename Tp>
concept signed_integer = integer<Tp> &&(Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> &&(Tp(-1) > Tp(0));
template <typename From, typename To>
concept sign_compatible_with = integer<From> &&
    ((std::is_signed_v<From> && std::is_signed_v<To>) ||
     (std::is_unsigned_v<From> && std::is_unsigned_v<To>));
template <typename Tp>
concept qword_fittable = sizeof(Tp) <= 8UL;
template <typename Tp>
concept dword_fittable = qword_fittable<Tp> && sizeof(Tp) <= 4UL;
template <typename Tp>
concept word_fittable = dword_fittable<Tp> && sizeof(Tp) <= 2UL;
template <typename Tp>
concept byte_fittable = word_fittable<Tp> && sizeof(Tp) == 1UL;
template <typename Tp>
struct imul_result;
template <>
struct imul_result<int64_t> {
  using type = __int128_t;
};
template <>
struct imul_result<uint64_t> {
  using type = __uint128_t;
};
template <>
struct imul_result<int32_t> {
  using type = int64_t;
};
template <>
struct imul_result<uint32_t> {
  using type = uint64_t;
};
template <>
struct imul_result<int16_t> {
  using type = int32_t;
};
template <>
struct imul_result<uint16_t> {
  using type = uint32_t;
};
template <>
struct imul_result<int8_t> {
  using type = int16_t;
};
template <>
struct imul_result<uint8_t> {
  using type = uint16_t;
};
template <typename Tp>
using imul_result_t = typename imul_result<Tp>::type;
template <typename Sig>
struct function_traits;
template <typename Ret, typename... Args>
struct function_traits<Ret(Args...)> {
  using return_type = Ret;
  template <typename Fn>
  static inline constexpr bool same_as =
      std::is_invocable_r_v<return_type, Fn, Args...>;
};
template <typename Fn, typename Sig>
concept function = function_traits<Sig>::template same_as<Fn>;
template <typename IIter, typename Value>
concept input_iterator = std::same_as<std::iter_value_t<IIter>, Value>;
}
namespace algo::detail {
[[gnu::noreturn]] void
unreachable() {
  __builtin_unreachable();
}
[[gnu::always_inline]] constexpr void
assume(bool expr) {
  if (!expr) { unreachable(); }
}
}
namespace algo::detail {
template <typename Tp>
constexpr int
id4(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
id6(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countr_zero<Up>(n);
}
template <typename Tp>
constexpr int
bit_width(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::bit_width<Up>(n);
}
template <typename Tp>
constexpr Tp
id9(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp
id5(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int
id0(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
id2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  if (n == 0) { return 0; }
  return Nd - std::countl_zero<Up>(n - 1);
}
template <typename Tp>
constexpr Tp
blsr(Tp n) {
  if (std::is_constant_evaluated()) { return n & (n - 1); }
  if constexpr (dword_fittable<Tp>) {
    return static_cast<Tp>(_blsr_u32(n));
  } else if constexpr (qword_fittable<Tp>) {
    return static_cast<Tp>(_blsr_u64(n));
  } else {
    return n & (n - 1);
  }
}
template <typename Tp>
constexpr Tp
blsi(Tp n) {
  if (std::is_constant_evaluated()) { return n & -n; }
  if constexpr (dword_fittable<Tp>) {
    return static_cast<Tp>(_blsi_u32(n));
  } else if constexpr (qword_fittable<Tp>) {
    return static_cast<Tp>(_blsi_u64(n));
  } else {
    return n & -n;
  }
}
template <typename Tp>
constexpr int
popcount(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::popcount<Up>(n);
}
}
namespace algo {
template <detail::integer Tp>
constexpr int
id4(Tp n) {
  return detail::id4(n);
}
template <detail::integer Tp>
constexpr int
id6(Tp n) {
  return detail::id6(n);
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
id9(Tp n) {
  return detail::id9(n);
}
template <detail::integer Tp>
constexpr Tp
id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr int
id0(Tp n) {
  return detail::id0(n);
}
template <detail::integer Tp>
constexpr int
id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr Tp
blsr(Tp n) {
  return detail::blsr(n);
}
template <detail::integer Tp>
constexpr Tp
blsi(Tp n) {
  return detail::blsi(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}


namespace algo {
template <typename = void>
struct id1;
template <std::semiregular Weight>
struct id1<Weight> {
  int u;
  int v;
  Weight w;
};
template <>
struct id1<void> {
  int u;
  int v;
};
template <typename = void>
class id3;
template <std::semiregular Weight>
class id3<Weight> {
public:
  using edge_type = id1<Weight>;
  using arc_type = std::pair<int, Weight>;
  id3() = default;
  id3(int n, const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v, it->w};
    }
  }
  std::span<const arc_type, std::dynamic_extent>
  operator[](int u) const noexcept {
    assert(0 <= u && u < num_nodes());
    return {elist_.cbegin() + start_[u], elist_.cbegin() + start_[u + 1]};
  }
  std::span<arc_type, std::dynamic_extent>
  operator[](int u) noexcept {
    assert(0 <= u && u < num_nodes());
    return {elist_.begin() + start_[u], elist_.begin() + start_[u + 1]};
  }
  int
  num_nodes() const {
    return static_cast<int>(start_.size()) - 1;
  }
  int
  num_directed_edges() const {
    return static_cast<int>(elist_.size());
  }
private:
  std::vector<int> start_;
  std::vector<arc_type> elist_;
};
template <>
class id3<void> {
public:
  using edge_type = id1<>;
  using arc_type = int;
  id3() = default;
  id3(int n, const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = it->v;
    }
  }
  std::span<const arc_type, std::dynamic_extent>
  operator[](int u) const noexcept {
    assert(0 <= u && u < num_nodes());
    return {elist_.cbegin() + start_[u], elist_.cbegin() + start_[u + 1]};
  }
  std::span<arc_type, std::dynamic_extent>
  operator[](int u) noexcept {
    assert(0 <= u && u < num_nodes());
    return {elist_.begin() + start_[u], elist_.begin() + start_[u + 1]};
  }
  int
  num_nodes() const {
    return static_cast<int>(start_.size()) - 1;
  }
  int
  num_directed_edges() const {
    return static_cast<int>(elist_.size());
  }
private:
  std::vector<int> start_;
  std::vector<arc_type> elist_;
};
template <typename Weight>
id1(int, int, Weight) -> id1<Weight>;
id1(int, int)->id1<void>;
template <typename Weight>
id3(int, const std::vector<id1<Weight>>&)
    -> id3<Weight>;
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  for (int i = id0(n) >> 1; i >= 0; --i) {
    const Tp tmp = res | Tp(1) << i;
    if (tmp * tmp <= n) { res = tmp; }
  }
  return res;
}
template <typename Tp>
constexpr Tp
abs(Tp n) {
  return n < 0 ? -n : n;
}
template <typename Tp>
constexpr Tp
floor_div(Tp x, Tp y) {
  if constexpr (std::is_signed_v<Tp>) {
    return x / y - ((x ^ y) < 0 && x % y != 0);
  } else {
    return x / y;
  }
}
template <typename Tp>
constexpr Tp
ceil_div(Tp x, Tp y) {
  if constexpr (std::is_signed_v<Tp>) {
    return y > 0 ? floor_div(x + y - 1, y) : -floor_div(x, -y);
  } else {
    return floor_div(x + y - 1, y);
  }
}
template <typename Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, char>>
alt(Tp n) {
  return -(n & 1) | 1;
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
id8(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  const Tp m = detail::abs(n);
  for (int i = detail::id0(m) / 3; i >= 0; --i) {
    const Tp low = (m - res * res * res) >> i;
    const Tp tmp = res | Tp(1) << i;
    if (3 * res * tmp + (Tp(1) << (i + i)) <= low) { res = tmp; }
  }
  return res;
}
template <detail::integer Tp>
constexpr Tp
abs(Tp n) {
  return detail::abs(n);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2>
floor_div(T1 x, T2 y) {
  assert(y != 0);
  using Tp = std::common_type_t<T1, T2>;
  return detail::floor_div<Tp>(x, y);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2>
ceil_div(T1 x, T2 y) {
  assert(y != 0);
  using Tp = std::common_type_t<T1, T2>;
  return detail::ceil_div<Tp>(x, y);
}
template <std::integral Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, char>>
alt(Tp n) {
  return detail::alt(n);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2,
          detail::sign_compatible_with<T2> T3,
          detail::sign_compatible_with<T3> T4>
constexpr std::common_type_t<T1, T2, T3, T4>
floor_sum(T1 a, T2 b, T3 c, T4 n) {
  assert(n >= 0);
  assert(c > 0);
  assert(a >= 0);
  detail::assume(n >= 0);
  detail::assume(c > 0);
  detail::assume(a >= 0);
  using Tp = std::common_type_t<T1, T2, T3, T4>;
  Tp res = 0, a0 = a, b0 = b, c0 = c, n0 = n;
  bool neg = false;
  while (a0 != 0) {
    if (a0 < c0 && b0 < c0) {
      const Tp m = (a0 * n0 + b0) / c0;
      const Tp tmp = a0;
      res += alt(neg) * m * n0;
      b0 = c0 - b0 - 1, a0 = c0, c0 = tmp, n0 = m - 1;
      neg ^= true;
    } else {
      const Tp tmp = (n0 * (n0 + 1) >> 1) * (a0 / c0) + (n0 + 1) * (b0 / c0);
      res += alt(neg) * tmp;
      a0 %= c0, b0 %= c0;
    }
  }
  res += alt(neg) * (b0 / c0) * (n0 + 1);
  return res;
}
}
namespace algo {
class id10 {
private:
  static constexpr int Undefined = -1;
  struct scc_node {
    int time = Undefined;
    int low = Undefined;
    int comp = Undefined;
  };
public:
  using graph_type = id3<>;
  using edge_type = graph_type::edge_type;
  id10(const graph_type& adj)
      : num_nodes_{}, id7{}, nodes_(adj.num_nodes()) {
    build_scc(adj);
  }
  id10(int n, const std::vector<edge_type>& edges)
      : id10(graph_type(n, edges)) {}
  int
  id(int u) const {
    assert(0 <= u && u < num_nodes());
    return nodes_[u].comp;
  }
  int
  num_nodes() const {
    return num_nodes_;
  }
  int
  num_components() const {
    return id7;
  }
private:
  void
  build_scc(const graph_type& adj) {
    std::vector<int> rec_stack;
    rec_stack.reserve(adj.num_nodes());
    const auto dfs = [&](auto dfs, int u) -> void {
      nodes_[u].time = nodes_[u].low = num_nodes_++;
      rec_stack.emplace_back(u);
      for (const int v : adj[u]) {
        if (nodes_[v].time == Undefined) {
          dfs(dfs, v);
          nodes_[u].low = std::min(nodes_[u].low, nodes_[v].low);
        } else if (nodes_[v].comp == Undefined) {
          nodes_[u].low = std::min(nodes_[u].low, nodes_[v].time);
        }
      }
      if (nodes_[u].low == nodes_[u].time) {
        while (rec_stack.back() != u) {
          const int w = rec_stack.back();
          nodes_[w].comp = id7;
          rec_stack.pop_back();
        }
        rec_stack.pop_back();
        nodes_[u].comp = id7++;
      }
    };
    for (int u = 0; u < adj.num_nodes(); ++u) {
      if (nodes_[u].time == Undefined) { dfs(dfs, u); }
    }
  }
  int num_nodes_;
  int id7;
  std::vector<scc_node> nodes_;
};
}
namespace algo {
class two_sat {
public:
  using graph_type = id10::graph_type;
  using edge_type = id10::edge_type;
  two_sat() : two_sat(0){};
  two_sat(int n) : edges_{}, ans_(n) {}
  void
  add_disjunction(int u, int v, bool nu, bool nv) {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    u = (u << 1) ^ nu;
    v = (v << 1) ^ nv;
    edges_.emplace_back(u ^ 1, v);
    edges_.emplace_back(v ^ 1, u);
  }
  bool
  solve() {
    const int tot = num_nodes() << 1;
    const id10 scc(tot, edges_);
    for (int u = 0; u < tot; u += 2) {
      if (scc.id(u) == scc.id(u ^ 1)) { return false; }
      ans_[u >> 1] = scc.id(u) < scc.id(u ^ 1);
    }
    return true;
  }
  std::vector<uint_fast8_t>
  answer() const {
    return ans_;
  }
  int
  num_nodes() const {
    return static_cast<int>(ans_.size());
  }
private:
  std::vector<edge_type> edges_;
  std::vector<uint_fast8_t> ans_;
};
}
using std::array;
using std::bitset;
using std::cin;
using std::complex;
using std::cout;
using std::deque;
using std::endl;
using std::gcd;
using std::lcm;
using std::map;
using std::max;
using std::min;
using std::move;
using std::multimap;
using std::multiset;
using std::pair;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::string_view;
using std::swap;
using std::tie;
using std::to_string;
using std::tuple;
using std::vector;
using tint = __int128_t;
using wint = int64_t;
using uint = uint32_t;
using bint = uint_fast8_t;
template <typename Key, typename Value, typename Hash = std::hash<Key>>
using umap = std::unordered_map<Key, Value, Hash>;
template <typename Key, typename Hash = std::hash<Key>>
using uset = std::unordered_set<Key, Hash>;
template <typename Tp, typename Comp = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;
template <typename Tp, typename Comp = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;




namespace {
}
void solve() noexcept {
  int n, m;
  cin >> n >> m;
  vector<algo::id1<int>> es(n - 1);
  algo::two_sat ts(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y, v;
    cin >> x >> y >> v;
    --x, --y;
    es[i] = {x, y, v};
    if (v != -1) {
      const bool p = algo::popcount(v) & 1;
      if (p) {
        ts.add_disjunction(x, y, 0, 0);
        ts.add_disjunction(x, y, 1, 1);
      } else {
        ts.add_disjunction(x, y, 0, 1);
        ts.add_disjunction(x, y, 1, 0);
      }
    }
  }
  while (m--) {
    int a, b, p;
    cin >> a >> b >> p;
    --a, --b;
    if (p) {
      ts.add_disjunction(a, b, 0, 0);
      ts.add_disjunction(a, b, 1, 1);
    } else {
      ts.add_disjunction(a, b, 0, 1);
      ts.add_disjunction(a, b, 1, 0);
    }
  }
  if (!ts.solve()) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector f = ts.answer();
  for (int i = 0; i < n - 1; ++i) {
    auto [u, v, w] = es[i];
    if (w == -1) {
      w = f[u] ^ f[v];
    }
    cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int tc;
  std::cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
