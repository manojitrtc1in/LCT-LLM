












































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
[[noreturn]] constexpr void
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
id5(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
id12(Tp n) {
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
id6(Tp n) {
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
id10(Tp n) {
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
constexpr Tp
id13(Tp n) {
  if (std::is_constant_evaluated()) { return n ^ (n - 1); }
  if constexpr (dword_fittable<Tp>) {
    return static_cast<Tp>(_blsmsk_u32(n));
  } else if constexpr (qword_fittable<Tp>) {
    return static_cast<Tp>(_blsmsk_u64(n));
  } else {
    return n ^ (n - 1);
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
id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr int
id12(Tp n) {
  return detail::id12(n);
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
id6(Tp n) {
  return detail::id6(n);
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
id10(Tp n) {
  return detail::id10(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}
namespace dbg {

}
namespace algo::detail {
template <typename Edge>
class csr_base {
public:
  using edge_type = std::pair<int, Edge>;
  csr_base() = default;
  csr_base(int n, const std::vector<edge_type> &edges) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto &e : edges) { start_[e.first]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->first]] = it->second;
    }
  }
  std::span<const Edge>
  operator[](int u) const {
    assert(0 <= u && u < num_nodes());
    return {elist_.cbegin() + start_[u], elist_.cbegin() + start_[u + 1]};
  }
  std::span<Edge>
  operator[](int u) {
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
  std::vector<Edge> elist_;
};
}
namespace algo {
template <std::semiregular Edge>
class id11 : public detail::csr_base<Edge> {
  using base_type = detail::csr_base<Edge>;
  using edge_type = typename base_type::edge_type;
public:
  id11() = default;
  id11(int n, const std::vector<edge_type>& edges)
      : base_type(n, edges) {}
};
}
namespace algo {
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
class id9 {
public:
  id9() = default;
  id9(int n, BinOp binop, Id id)
      : n_(n),
        lg2_(detail::id10(n)),
        size_(1 << lg2_),
        tree_(size_ << 1, id()),
        binop_(std::move(binop)),
        id_(std::move(id)) {}
  id9(int n, const Monoid& init, BinOp binop, Id id)
      : n_(n),
        lg2_(detail::id10(n)),
        size_(1 << lg2_),
        tree_(size_ << 1, init),
        binop_(std::move(binop)),
        id_(std::move(id)) {
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> IIter>
  id9(IIter first, IIter last, BinOp binop, Id id)
      : id9(std::distance(first, last), std::move(binop), std::move(id)) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <std::input_iterator IIter,
            detail::function<Monoid(std::iter_value_t<IIter>)> Gen>
  id9(IIter first, IIter last, BinOp binop, Id id, Gen gen)
      : id9(std::distance(first, last), std::move(binop), std::move(id)) {
    std::transform(first, last, tree_.begin() + size_, std::move(gen));
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  void
  set(int pos, Monoid new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    tree_[pos] = std::move(new_val);
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  Monoid
  get(int pos) const {
    assert(0 <= pos && pos < size());
    return tree_[pos + size_];
  }
  void
  apply(int pos, Monoid z) {
    assert(0 <= pos && pos < size());
    pos += size_;
    tree_[pos] = binop_(std::move(tree_[pos]), std::move(z));
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  Monoid
  query(int l, int r) const {
    assert(0 <= l && l <= r && r <= size());
    Monoid resl = id_(), resr = id_();
    l += size_ - 1;
    r += size_ + 0;
    const int mask = detail::id6(l ^ r) - 1;
    for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
      resl = binop_(std::move(resl), tree_[(l >> detail::id12(v)) + 1]);
    }
    for (int v = mask & r; v != 0; v = detail::blsr(v)) {
      resr = binop_(tree_[(r >> detail::id12(v)) - 1], std::move(resr));
    }
    return binop_(std::move(resl), std::move(resr));
  }
  Monoid
  query() const {
    return tree_[1];
  }
  template <std::predicate<Monoid> Pred>
  int
  id7(int l, const Pred& pred) const {
    assert(0 <= l && l <= size());
    assert(pred(id_()));
    if (l < n_) [[likely]] {
      l += size_;
      Monoid cur = id_();
      do {
        l >>= detail::id12(l);
        if (!pred(binop_(cur, tree_[l]))) {
          while (l < size_) {
            l <<= 1;
            if (Monoid tmp = binop_(cur, tree_[l]); pred(tmp)) {
              cur = std::move(tmp), ++l;
            }
          }
          return l - size_;
        }
        cur = binop_(std::move(cur), tree_[l++]);
      } while (detail::popcount(l) != 1);
    }
    return n_;
  }
  template <std::predicate<Monoid> Pred>
  int
  id0(int r, const Pred& pred) const {
    assert(0 <= r && r <= size());
    if (r > 0) [[likely]] {
      r += size_ - 1;
      Monoid cur = id_();
      do {
        r >>= detail::id12(~r);
        if (!pred(binop_(tree_[r], cur))) {
          while (r < size_) {
            r <<= 1;
            r |= 1;
            if (Monoid tmp = binop_(tree_[r], cur); pred(tmp)) {
              cur = std::move(tmp), --r;
            }
          }
          return r + 1 - size_;
        }
        cur = binop_(tree_[r], std::move(cur));
      } while (detail::popcount(r--) != 1);
    }
    return 0;
  }
  int
  size() const {
    return n_;
  }
  Monoid
  id() const {
    return id_();
  }
  Monoid
  binop(Monoid x, Monoid y) const {
    return binop_(std::move(x), std::move(y));
  }
  std::vector<Monoid>
  data() const {
    return tree_;
  }
private:
  void
  update(int v) {
    tree_[v] = binop_(tree_[v << 1], tree_[v << 1 | 1]);
  }
  int n_;
  int lg2_;
  int size_;
  std::vector<Monoid> tree_;
  BinOp binop_;
  Id id_;
};
}
namespace algo::detail {
class id8 {
  struct hld_node {
    int parent;
    int depth;
    int head;
    int norm;
  };
public:
  using edge_type = std::pair<int, int>;
  using graph_type = csr_base<int>;
  static constexpr int Null = -1;
  id8() = default;
  id8(const graph_type& adj) : decomposition_(adj.num_nodes()) {
    assert(adj.num_directed_edges() == 2 * (adj.num_nodes() - 1));
    decompose(adj);
  }
  id8(int n, const std::vector<edge_type>& edges)
      : id8(graph_type(n, edges)) {}
  int
  lca(int u, int v) const {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    while (head(u) != head(v)) {
      if (depth(head(u)) < depth(head(v))) { std::swap(u, v); }
      u = parent(head(u));
    }
    return depth(u) < depth(v) ? u : v;
  }
  int
  num_nodes() const {
    return static_cast<int>(decomposition_.size());
  }
  int
  head(int u) const {
    return decomposition_[u].head;
  }
  int
  norm(int u) const {
    return decomposition_[u].norm;
  }
  int
  depth(int u) const {
    return decomposition_[u].depth;
  }
  int
  parent(int u) const {
    return decomposition_[u].parent;
  }
private:
  void
  decompose(const graph_type& adj) {
    std::vector<int> heavy(num_nodes());
    auto dfs = [&](auto dfs, int u) -> int {
      int siz = 1, id4 = 0, big_child = Null;
      for (const int v : adj[u]) {
        if (v == decomposition_[u].parent) { continue; }
        decomposition_[v].parent = u;
        decomposition_[v].depth = decomposition_[u].depth + 1;
        const int sub = dfs(dfs, v);
        if (sub > id4) {
          id4 = sub;
          big_child = v;
        }
        siz += sub;
      }
      heavy[u] = big_child;
      return siz;
    };
    decomposition_[0].parent = Null;
    decomposition_[0].depth = 0;
    dfs(dfs, 0);
    for (int u = 0, cur_pos = 0; u < num_nodes(); ++u) {
      if (decomposition_[u].parent != Null &&
          heavy[decomposition_[u].parent] == u) {
        continue;
      }
      for (int v = u; v != Null; v = heavy[v]) {
        decomposition_[v].head = u;
        decomposition_[v].norm = cur_pos++;
      }
    }
  }
  std::vector<hld_node> decomposition_;
};
}
namespace algo {
template <typename Monoid = void, typename BinOp = void, typename Id = void>
class id1;
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
class id1<Monoid, BinOp, Id> : public detail::id8 {
  using base_type = detail::id8;
  using segtree_type = id9<Monoid, BinOp, Id>;
public:
  id1() = default;
  id1(const graph_type &adj, BinOp binop, Id id)
      : base_type(adj), seg_(num_nodes(), std::move(binop), std::move(id)) {}
  id1(int n, const std::vector<edge_type> &edges, BinOp binop,
                   Id id)
      : id1(graph_type(n, edges), std::move(binop),
                         std::move(id)) {}
  id1(const graph_type &adj, const Monoid &init, BinOp binop,
                   Id id)
      : base_type(adj),
        seg_(num_nodes(), init, std::move(binop), std::move(id)) {}
  id1(int n, const std::vector<edge_type> &edges,
                   const Monoid &init, BinOp binop, Id id)
      : id1(graph_type(n, edges), init, std::move(binop),
                         std::move(id)) {}
  void
  set(int u, Monoid new_val) {
    assert(0 <= u && u < num_nodes());
    seg_.set(norm(u), std::move(new_val));
  }
  void
  apply(int u, Monoid z) {
    assert(0 <= u && u < num_nodes());
    seg_.apply(norm(u), std::move(z));
  }
  Monoid
  query(int u, int v) const {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    Monoid res = seg_.id();
    while (head(u) != head(v)) {
      if (depth(head(u)) < depth(head(v))) { std::swap(u, v); }
      res = seg_.binop(std::move(res), seg_.query(norm(head(u)), norm(u) + 1));
      u = parent(head(u));
    }
    if (depth(u) < depth(v)) { std::swap(u, v); }
    res = seg_.binop(std::move(res), seg_.query(norm(v), norm(u) + 1));
    return res;
  }
private:
  segtree_type seg_;
};
template <>
class id1<void, void, void> : public detail::id8 {
  using base_type = detail::id8;
public:
  id1() = default;
  id1(const graph_type &adj) : base_type(adj) {}
  id1(int n, const std::vector<edge_type> &edges)
      : base_type(n, edges) {}
};
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n <= 1) { return n; }
  Tp ans = 0;
  for (int i = id3(n) - 1; i >= 0; --i) {
    const Tp tmp = (n - ans * ans) >> i;
    if ((ans << 1) + (Tp(1) << i) <= tmp) { ans |= Tp(1) << i; }
  }
  return ans;
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
  vector<pair<int, int>> es;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    es.emplace_back(u, v);
    es.emplace_back(v, u);
  }
  algo::id11<int> adj(n, es);
  auto fx = [](int x, int y) { return x + y; };
  auto efx = [] { return 0; };
  algo::id1<int, decltype(fx), decltype(efx)> hld(adj, 1, fx, efx);
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
      if (int tmp = hld.depth(buf[i]); tmp > mx) {
        mx = tmp, u = buf[i];
      }
    }
    int v = u, d = 0;
    for (int i = 0; i < k; ++i) {
      if (int tmp = hld.query(buf[i], u) - 1; tmp > d) {
        d = tmp, v = buf[i];
      }
    }
    bool ok = true;
    for (int i = 0; i < k; ++i) {
      int d1 = hld.query(u, buf[i]) - 1;
      int d2 = hld.query(v, buf[i]) - 1;
      ok &= d1 + d2 == d;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  solve();
  return 0;
}