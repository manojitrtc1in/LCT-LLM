













































namespace algo::detail {
template <typename Tp>
concept integer = std::integral<Tp> && !(std::same_as<Tp, bool>);
template <typename Tp>
concept signed_integer = integer<Tp> && (Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> && (Tp(-1) > Tp(0));
template <typename From, typename To>
concept sign_compatible_with =
    integer<From> && ((std::is_signed_v<From> && std::is_signed_v<To>) ||
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
  static constexpr bool same_as =
      std::is_invocable_r_v<return_type, Fn, Args...>;
};
template <typename Fn, typename Sig>
concept function = (function_traits<Sig>::template same_as<Fn>);
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
id8(Tp n) {
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
id5(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp
id2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int
id3(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
id6(Tp n) {
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
id8(Tp n) {
  return detail::id8(n);
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr Tp
id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr int
id3(Tp n) {
  return detail::id3(n);
}
template <detail::integer Tp>
constexpr int
id6(Tp n) {
  return detail::id6(n);
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
struct edge;
template <std::semiregular Weight>
struct edge<Weight> {
  int u;
  int v;
  Weight w;
  using arc_type = struct {
    int v;
    Weight w;
  };
};
template <>
struct edge<void> {
  int u;
  int v;
  using arc_type = int;
};
struct undirected_tag {};
struct directed_tag {};
template <typename = void>
class id7;
template <std::semiregular Weight>
class id7<Weight> {
public:
  using edge_type = edge<Weight>;
  using arc_type = typename edge_type::arc_type;
  id7() = default;
  id7(int n, const std::vector<edge_type>& edges,
                 directed_tag) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v, it->w};
    }
  }
  id7(int n, const std::vector<edge_type>& edges,
                 undirected_tag) noexcept
      : start_(n + 1), elist_(edges.size() << 1) {
    for (const auto& e : edges) {
      start_[e.u]++;
      start_[e.v]++;
    }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v, it->w};
      elist_[--start_[it->v]] = {it->u, it->w};
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
  num_arcs() const {
    return static_cast<int>(elist_.size());
  }
private:
  std::vector<int> start_;
  std::vector<arc_type> elist_;
};
template <>
class id7<void> {
public:
  using edge_type = edge<>;
  using arc_type = edge_type::arc_type;
  id7() = default;
  id7(int n, const std::vector<edge_type>& edges,
                 directed_tag) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v};
    }
  }
  id7(int n, const std::vector<edge_type>& edges,
                 undirected_tag) noexcept
      : start_(n + 1), elist_(edges.size() << 1) {
    for (const auto& e : edges) {
      start_[e.u]++;
      start_[e.v]++;
    }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v};
      elist_[--start_[it->v]] = {it->u};
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
  num_arcs() const {
    return static_cast<int>(elist_.size());
  }
private:
  std::vector<int> start_;
  std::vector<arc_type> elist_;
};
template <typename Weight>
edge(int, int, Weight) -> edge<Weight>;
edge(int, int)->edge<void>;
template <typename Weight>
id7(int, const std::vector<edge<Weight>>&, directed_tag)
    -> id7<Weight>;
template <typename Weight>
id7(int, const std::vector<edge<Weight>>&, undirected_tag)
    -> id7<Weight>;
std::vector<int>
id1(const id7<>& adj) {
  std::vector<uint_fast8_t> vis(adj.num_nodes());
  std::vector<int> order;
  order.reserve(adj.num_nodes());
  const auto dfs = [&](auto dfs, int u) -> void {
    vis[u] = true;
    for (const int v : adj[u]) {
      if (!vis[v]) { dfs(dfs, v); }
    }
    order.emplace_back(u);
  };
  for (int u = 0; u < adj.num_nodes(); ++u) {
    if (!vis[u]) { dfs(dfs, u); }
  }
  std::reverse(order.begin(), order.end());
  return order;
}
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  for (int i = id3(n) >> 1; i >= 0; --i) {
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
id10(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  const Tp m = detail::abs(n);
  for (int i = detail::id3(m) / 3; i >= 0; --i) {
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
template <std::semiregular Tp>
class id9 {
public:
  id9() = default;
  id9(int row, int col, const Tp& init = Tp()) noexcept
      : row_(row), col_(col), data_(total_size(), init) {}
  id9(std::pair<int, int> dims, const Tp& init = Tp()) noexcept
      : id9(dims.first, dims.second, init) {}
  id9(int row, const std::vector<Tp>& init_col) noexcept
      : id9(row, static_cast<int>(init_col.size())) {
    for (int i = 0; i < row_size(); ++i) {
      std::copy_n(init_col.begin(), col_size(), data_.begin() + i * col_size());
    }
  }
  std::span<const Tp, std::dynamic_extent>
  operator[](int i) const noexcept {
    assert(0 <= i && i < row_size());
    return {data_.cbegin() + i * col_size(),
            data_.cbegin() + (i + 1) * col_size()};
  }
  std::span<Tp, std::dynamic_extent>
  operator[](int i) noexcept {
    assert(0 <= i && i < row_size());
    return {data_.begin() + i * col_size(),
            data_.begin() + (i + 1) * col_size()};
  }
  const Tp&
  operator()(int i, int j) const {
    assert(0 <= i && i < row_size());
    assert(0 <= j && j < col_size());
    return data_[i * col_size() + j];
  }
  Tp&
  operator()(int i, int j) {
    assert(0 <= i && i < row_size());
    assert(0 <= j && j < col_size());
    return data_[i * col_size() + j];
  }
  void
  assign(int row, int col, const Tp& value = Tp()) noexcept {
    assert(0 <= row);
    assert(0 <= col);
    row_ = row;
    col_ = col;
    data_.assign(total_size(), value);
  }
  int
  total_size() const {
    return row_ * col_;
  }
  int
  row_size() const {
    return row_;
  }
  int
  col_size() const {
    return col_;
  }
  auto
  begin() const {
    return data_.cbegin();
  }
  auto
  begin() {
    return data_.begin();
  }
  auto
  end() const {
    return data_.cend();
  }
  auto
  end() {
    return data_.end();
  }
  auto
  rbegin() const {
    return data_.crbegin();
  }
  auto
  rbegin() {
    return data_.rbegin();
  }
  auto
  rend() const {
    return data_.crend();
  }
  auto
  rend() {
    return data_.rend();
  }
  const Tp*
  data() const {
    return data_.data();
  }
  Tp*
  data() {
    return data_.data();
  }
private:
  int row_;
  int col_;
  std::vector<Tp> data_;
};
}
namespace algo {
template <std::semiregular Semigroup,
          detail::function<Semigroup(Semigroup, Semigroup)> BinOp>
class id0 {
public:
  id0() = default;
  id0(int n, const Semigroup &init, BinOp binop)
      : table_(calc_dims(n), init), binop_(std::move(binop)) {
    std::fill(table_[0].begin(), table_[0].end(), init);
    calc_table();
  }
  template <detail::input_iterator<Semigroup> IIter>
  id0(IIter first, IIter last, BinOp binop)
      : table_(calc_dims(first, last)), binop_(std::move(binop)) {
    std::copy(first, last, table_.begin());
    calc_table();
  }
  template <std::input_iterator IIter,
            detail::function<Semigroup(std::iter_value_t<IIter>)> Gen>
  id0(IIter first, IIter last, BinOp binop, Gen gen)
      : table_(calc_dims(first, last)), binop_(std::move(binop)) {
    std::transform(first, last, table_.begin(), std::move(gen));
    calc_table();
  }
  [[gnu::pure]] Semigroup
  query_idempotent(int l, int r) const {
    assert(l < r && l >= 0 && r <= size());
    const int lg = detail::id3(r - l);
    return binop_(table_[lg][l], table_[lg][r - (1 << lg)]);
  }
  [[gnu::pure]] Semigroup
  query_incremental(int l, int r) const {
    assert(l < r && l >= 0 && r <= size());
    const int istep = detail::id3(r - l);
    Semigroup res = table_[istep][l];
    int base = l + (1 << istep), len = r - base;
    while (len > 0) {
      const int nstep = detail::id3(len);
      res = binop_(std::move(res), table_[nstep][base]);
      base += 1 << nstep;
      len -= 1 << nstep;
    }
    return res;
  }
  int
  size() const {
    return table_.col_size();
  }
private:
  inline void
  calc_table() {
    for (int j = 1; j < table_.row_size(); ++j) {
      for (int i = 0; i + (1 << j) <= table_.col_size(); ++i) {
        table_[j][i] =
            binop_(table_[j - 1][i], table_[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  static std::pair<int, int>
  calc_dims(int n) {
    return {detail::bit_width(n), n};
  }
  template <typename IIter>
  static std::pair<int, int>
  calc_dims(IIter first, IIter last) {
    const int n = static_cast<int>(std::distance(first, last));
    return calc_dims(n);
  }
  algo::id9<Semigroup> table_;
  BinOp binop_;
};
template <typename Semigroup, typename BinOp>
id0(int, const Semigroup &, BinOp) -> id0<Semigroup, BinOp>;
template <typename IIter, typename BinOp>
id0(IIter, IIter, BinOp)
    -> id0<std::iter_value_t<IIter>, BinOp>;
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
  int n;
  cin >> n;
  vector<algo::edge<>> es(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    es[i] = {u, v};
  }
  const algo::id7 adj(n, es, algo::undirected_tag{});
  vector<int> et, tin(n), dist(n);
  et.reserve(2 * n);
  auto dfs = [&](auto dfs, int u = 0, int p = 0, int h = 0) -> void {
    tin[u] = ssize(et);
    et.emplace_back(u);
    dist[u] = h;
    for (const int v : adj[u]) {
      if (v != p) {
        dfs(dfs, v, u, h + 1);
        et.emplace_back(u);
      }
    }
  };
  dfs(dfs);
  auto f = [&](int x, int y) { return dist[x] < dist[y] ? x : y; };
  algo::id0 spt(et.begin(), et.end(), f);
  auto calc = [&](int u, int v) {
    if (tin[u] > tin[v]) {
      swap(u, v);
    }
    const int lca = spt.query_idempotent(tin[u], tin[v] + 1);
    return dist[u] + dist[v] - 2 * dist[lca];
  };
  int q;
  cin >> q;
  vector<int> buf(n);
  while (q--) {
    int k;
    cin >> k;
    int u = -1, mx = -1;
    for (int i = 0; i < k; ++i) {
      cin >> buf[i];
      buf[i]--;
      if (dist[buf[i]] > mx) {
        mx = dist[buf[i]], u = buf[i];
      }
    }
    int v = u, d = 0;
    for (int i = 0; i < k; ++i) {
      if (int tmp = calc(buf[i], u); d < tmp) {
        d = tmp, v = buf[i];
      }
    }
    bool ok = true;
    for (int i = 0; i < k; ++i) {
      ok &= (calc(u, buf[i]) + calc(buf[i], v) == d);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}