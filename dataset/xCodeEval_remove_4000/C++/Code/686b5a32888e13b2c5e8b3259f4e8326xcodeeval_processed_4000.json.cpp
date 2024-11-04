












































namespace algo::detail {
template <typename Tp>
concept integer = std::integral<Tp> && !std::same_as<Tp, bool>;
template <typename Tp>
concept signed_integer = integer<Tp> &&(Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> &&(Tp(-1) > Tp(0));
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
template <typename InputIterator, typename ValueType>
concept input_iterator = std::input_iterator<InputIterator> &&
    std::same_as<std::iter_value_t<InputIterator>, ValueType>;
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
struct imul_result {
  static_assert(integer<Tp>);
};
template <qword_fittable Tp>
struct imul_result<Tp> {
  using type =
      std::conditional_t<std::is_signed_v<Tp>, __int128_t, __uint128_t>;
};
template <dword_fittable Tp>
struct imul_result<Tp> {
  using type = std::conditional_t<std::is_signed_v<Tp>, int64_t, uint64_t>;
};
template <word_fittable Tp>
struct imul_result<Tp> {
  using type = std::conditional_t<std::is_signed_v<Tp>, int32_t, uint32_t>;
};
template <byte_fittable Tp>
struct imul_result<Tp> {
  using type = std::conditional_t<std::is_signed_v<Tp>, int16_t, uint16_t>;
};
template <typename Tp>
using imul_result_t = typename imul_result<Tp>::type;
}
namespace algo::detail {
template <typename Tp>
constexpr int
id3(Tp n) {
  return std::countl_zero<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr int
id5(Tp n) {
  return std::countr_zero<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr int
bit_width(Tp n) {
  return std::bit_width<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr Tp
id7(Tp n) {
  return static_cast<Tp>(std::bit_floor<std::make_unsigned_t<Tp>>(n));
}
template <typename Tp>
constexpr Tp
id4(Tp n) {
  return static_cast<Tp>(std::bit_ceil<std::make_unsigned_t<Tp>>(n));
}
template <typename Tp>
constexpr int
id0(Tp n) {
  return bit_width(n) - 1;
}
template <typename Tp>
constexpr int
id1(Tp n) {
  return bit_width(n - (n != 0));
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
id6(Tp n) {
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
  return std::popcount<std::make_unsigned_t<Tp>>(n);
}
}
namespace algo {
template <detail::integer Tp>
constexpr int
id3(Tp n) {
  return detail::id3(n);
}
template <detail::integer Tp>
constexpr int
id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
id7(Tp n) {
  return detail::id7(n);
}
template <detail::integer Tp>
constexpr Tp
id4(Tp n) {
  return detail::id4(n);
}
template <detail::integer Tp>
constexpr int
id0(Tp n) {
  return detail::id0(n);
}
template <detail::integer Tp>
constexpr int
id1(Tp n) {
  return detail::id1(n);
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
constexpr void
assume(bool expr) {
  if (!expr) { __builtin_unreachable(); }
}
}
namespace algo {
template <std::semiregular Abelian, detail::binary_op<Abelian> Operation,
          detail::callable<Abelian> Identity,
          detail::callable<Abelian, Abelian> Inverse>
class id2 {
  struct splay_node {
    int children_[2], parent_;
    bool flip_;
    Abelian self_, sub_, vsub_, path_;
  };
public:
  static constexpr int Null = 0;
  id2(int n, const Operation &f, const Identity &e, const Inverse &iv)
      : n_(n),
        tree_(n + 1, splay_node{{Null, Null}, Null, false, e(), e(), e(), e()}),
        binop_(f),
        id_(e),
        invop_(iv) {}
  id2(int n, const Abelian &init, const Operation &f,
                const Identity &e, const Inverse &iv)
      : n_(n),
        tree_(n + 1,
              splay_node{{Null, Null}, Null, false, init, init, e(), init}),
        binop_(f),
        id_(e),
        invop_(iv) {
    tree_[Null].self_ = tree_[Null].sub_ = tree_[Null].path_ = id_();
  }
  void
  reroot(int u) {
    assert(0 < u && u <= size());
    make_root(u);
  }
  void
  link(int v, int u) {
    assert(0 < u && u <= size());
    assert(0 < v && v <= size());
    make_root(u);
    access(v);
    toggle(v, u);
  }
  void
  cut(int v, int u) {
    assert(0 < u && u <= size());
    assert(0 < v && v <= size());
    make_root(v);
    access(u);
    if (tree_[u].children_[0] == v) {
      tree_[u].children_[0] = Null;
      tree_[v].parent_ = Null;
      update(u);
    }
  }
  int
  find_parent(int u) {
    assert(0 < u && u <= size());
    access(u);
    return tree_[u].children_[0];
  }
  int
  find_root(int u) {
    assert(0 < u && u <= size());
    access(u);
    while (tree_[u].children_[0] != Null) {
      u = tree_[u].children_[0];
      push(u);
    }
    splay(u);
    return u;
  }
  bool
  connected(int v, int u) {
    assert(0 < u && u <= size());
    assert(0 < v && v <= size());
    return lca(u, v);
  }
  int
  lca(int v, int u) {
    assert(0 < u && u <= size());
    assert(0 < v && v <= size());
    if (u == v) { return u; }
    access(v);
    int w = Null, z = u;
    do {
      splay(z);
      toggle(z, w);
      w = z, z = tree_[z].parent_;
    } while (z != Null);
    splay(u);
    return tree_[v].parent_ != Null ? w : Null;
  }
  Abelian
  query_subtree(int u) {
    assert(0 < u && u <= size());
    access(u);
    return binop_(tree_[u].self_, tree_[u].vsub_);
  }
  Abelian
  query_path(int v, int u) {
    assert(0 < u && u <= size());
    assert(0 < v && v <= size());
    make_root(u);
    access(v);
    return tree_[v].path_;
  }
  void
  set(int u, const Abelian &new_val) {
    assert(0 < u && u <= size());
    access(u);
    tree_[u].self_ = new_val;
    update(u);
  }
  void
  set(int u, Abelian &&new_val) {
    assert(0 < u && u <= size());
    access(u);
    tree_[u].self_ = std::move(new_val);
    update(u);
  }
  Abelian
  get(int u) const {
    assert(0 < u && u <= size());
    return tree_[u].self_;
  }
  int
  size() const {
    return n_;
  }
private:
  void
  make_root(int u) {
    access(u);
    tree_[u].flip_ ^= true;
    push(u);
  }
  int
  side(int u) const {
    const int p = tree_[u].parent_;
    if (tree_[p].children_[0] == u) { return 0; }
    if (tree_[p].children_[1] == u) { return 1; }
    return -1;
  }
  void
  access(int u) {
    splay(u);
    toggle(u, 0);
    while (tree_[u].parent_ != Null) {
      const int w = tree_[u].parent_;
      splay(w);
      toggle(w, u);
      rotate(u);
    }
  }
  bool
  is_root(int u) const {
    return side(u) < 0;
  }
  void
  update(int u) {
    const int l = tree_[u].children_[0];
    const int r = tree_[u].children_[1];
    tree_[u].sub_ = binop_(binop_(tree_[u].self_, tree_[u].vsub_),
                           binop_(tree_[l].sub_, tree_[r].sub_));
    tree_[u].path_ =
        binop_(tree_[u].self_, binop_(tree_[l].path_, tree_[r].path_));
  }
  void
  toggle(int v, int u) {
    const int c = tree_[v].children_[1];
    tree_[v].vsub_ = binop_(std::move(tree_[v].vsub_), tree_[c].sub_);
    if (tree_[u].parent_ == v) {
      tree_[v].vsub_ = binop_(std::move(tree_[v].vsub_), invop_(tree_[u].sub_));
    }
    tree_[v].children_[1] = u;
    tree_[u].parent_ = v;
    update(v);
  }
  void
  rotate(int u) {
    const int v = tree_[u].parent_;
    const int w = tree_[v].parent_;
    const int du = side(u);
    const int dv = side(v);
    attach(v, tree_[u].children_[!du], du);
    attach(u, v, !du);
    if (dv != -1) { attach(w, u, dv); }
    tree_[u].parent_ = w;
  }
  void
  attach(int v, int u, bool d) {
    tree_[v].children_[d] = u;
    tree_[u].parent_ = v;
    update(v);
  }
  void
  push(int u) {
    if (u != Null && tree_[u].flip_) {
      const int l = tree_[u].children_[0];
      const int r = tree_[u].children_[1];
      tree_[l].flip_ ^= true;
      tree_[r].flip_ ^= true;
      std::swap(tree_[u].children_[0], tree_[u].children_[1]);
      tree_[u].flip_ = false;
    }
  }
  void
  splay(int u) {
    push(u);
    while (!is_root(u) && !is_root(tree_[u].parent_)) {
      const int v = tree_[u].parent_;
      const int w = tree_[v].parent_;
      push(w);
      push(v);
      push(u);
      rotate(side(v) == side(u) ? v : u);
      rotate(u);
    }
    if (!is_root(u)) {
      push(tree_[u].parent_);
      push(u);
      rotate(u);
    }
  }
  int n_;
  std::vector<splay_node> tree_;
  Operation binop_;
  Identity id_;
  Inverse invop_;
};
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n <= 1) { return n; }
  Tp ans = 0;
  for (int i = id0(n) - 1; i >= 0; --i) {
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
  return (n & 1) ? -1 : 1;
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
  return detail::floor_div<std::common_type_t<T1, T2>>(x, y);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2>
ceil_div(T1 x, T2 y) {
  assert(y != 0);
  return detail::ceil_div<std::common_type_t<T1, T2>>(x, y);
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
  typedef std::common_type_t<T1, T2, T3, T4> Tp;
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

namespace ranges = std::ranges;
namespace views = std::views;
namespace chrono = std::chrono;
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
using std::swap;
using std::tie;
using std::to_string;
using std::tuple;
using std::vector;
using wint = int64_t;
using uint = uint32_t;
template <typename Key, typename Value, typename Hash = std::hash<Key>>
using umap = std::unordered_map<Key, Value, Hash>;
template <typename Value, typename Hash = std::hash<Value>>
using uset = std::unordered_set<Value, Hash>;
template <typename Tp, typename Comp = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;
template <typename Tp, typename Comp = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;





namespace {
}
void solve() noexcept {
  int n;
  cin >> n;
  auto f = [](int x, int y) { return x + y; };
  auto ef = [] { return 0; };
  auto iv = [](int x) { return -x; };
  algo::id2<int, decltype(f), decltype(ef), decltype(iv)> lct(n, 1, f,
                                                                        ef, iv);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    lct.link(u, v);
  }
  vector<int> dist(n + 1);
  for (int i = 1; i <= n; ++i) {
    dist[i] = lct.query_path(1, i) - 1;
    lct.reroot(1);
  }
  debug("dist = {}\n", dist);
  auto calc = [&](int u, int v) {
    const int lca = lct.lca(u, v);
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
      if (dist[buf[i]] > mx) { mx = dist[buf[i]], u = buf[i]; }
    }
    int v = u, d = 0;
    for (int i = 0; i < k; ++i) {
      if (int tmp = calc(buf[i], u); d < tmp) { d = tmp, v = buf[i]; }
    }
    bool ok = true;
    for (int i = 0; i < k; ++i) {
      ok &= (calc(u, buf[i]) + calc(buf[i], v) == d);
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
