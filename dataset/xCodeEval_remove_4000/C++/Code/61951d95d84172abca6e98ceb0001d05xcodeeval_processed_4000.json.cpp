













































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
concept arithmetic = integer<Tp> || (std::is_floating_point_v<Tp>);
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


    do { \
      if (!bool(Condition)) { __builtin_unreachable(); } \
    } while (0)



namespace algo::detail {
template <typename Tp>
constexpr int
id3(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
id9(Tp n) {
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
id4(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp
id1(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int
id2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
id8(Tp n) {
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
id3(Tp n) {
  return detail::id3(n);
}
template <detail::integer Tp>
constexpr int
id9(Tp n) {
  return detail::id9(n);
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
id4(Tp n) {
  return detail::id4(n);
}
template <detail::integer Tp>
constexpr Tp
id1(Tp n) {
  return detail::id1(n);
}
template <detail::integer Tp>
constexpr int
id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr int
id8(Tp n) {
  return detail::id8(n);
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
namespace pb_ds = __gnu_pbds;
template <std::semiregular Key,
          std::relation<Key, Key> Compare = std::less<Key>>
using set = pb_ds::tree<Key, pb_ds::null_type, Compare, pb_ds::rb_tree_tag,
                        pb_ds::tree_order_statistics_node_update>;
template <std::semiregular Key, std::semiregular Value,
          std::relation<Key, Key> Compare = std::less<Key>>
using map = pb_ds::tree<Key, Value, Compare, pb_ds::rb_tree_tag,
                        pb_ds::tree_order_statistics_node_update>;
template <std::semiregular Key, std::semiregular Value,
          detail::function<size_t(Key)> Hash = std::hash<Key>,
          std::equivalence_relation<Key, Key> Eq = std::equal_to<Key>>
using hash_map = pb_ds::gp_hash_table<Key, Value, Hash>;
template <std::semiregular Key,
          detail::function<size_t(Key)> Hash = std::hash<Key>,
          std::equivalence_relation<Key, Key> Eq = std::equal_to<Key>>
using hash_set = pb_ds::gp_hash_table<Key, pb_ds::null_type, Hash, Eq>;
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  for (int i = id2(n) >> 1; i >= 0; --i) {
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
  erf_assert(n >= 0);
  return detail::sqrt(n);
}
template <detail::integer Tp>
constexpr Tp
id11(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  const Tp m = detail::abs(n);
  for (int i = detail::id2(m) / 3; i >= 0; --i) {
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
  erf_assert(y != 0);
  using Tp = std::common_type_t<T1, T2>;
  return detail::floor_div<Tp>(x, y);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2>
ceil_div(T1 x, T2 y) {
  erf_assert(y != 0);
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
  erf_assert(n >= 0);
  erf_assert(c > 0);
  erf_assert(a >= 0);
  erf_assume(n >= 0);
  erf_assume(c > 0);
  erf_assume(a >= 0);
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
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
class id7 {
private:
  struct pseg_node {
    Monoid value;
    pseg_node* left = nullptr;
    pseg_node* right = nullptr;
  };
  class id6 {
  public:
    using node_type = pseg_node;
    using node_pointer = node_type*;
    using const_node_pointer = const node_type*;
    using pool_resource_type = std::pmr::monotonic_buffer_resource;
    id6() = default;
    explicit id6(size_t init_size) noexcept
        : pool_(init_size) {}
    node_pointer
    allocate(Monoid value) {
      void* mem = do_allocate();
      return ::new (mem) node_type(std::move(value));
    }
    node_pointer
    clone(const_node_pointer source) {
      void* mem = do_allocate();
      erf_assert(source != nullptr);
      return ::new (mem) node_type(*source);
    }
  private:
    void*
    do_allocate() noexcept {
      return pool_.allocate(sizeof(node_type), alignof(node_type));
    }
    pool_resource_type pool_;
  };
public:
  using node_allocator_type = id6;
  using node_type = typename node_allocator_type::node_type;
  using node_pointer = typename node_allocator_type::node_pointer;
  using const_node_pointer = typename node_allocator_type::const_node_pointer;
  id7() = default;
  id7(int n, BinOp binop, Id id)
      : pool_(n),
        size_(n),
        binop_(std::move(binop)),
        id_(std::move(id)),
        tree_{{build(size_, id_())}} {}
  id7(int n, const Monoid& init, BinOp binop, Id id)
      : pool_(n),
        size_(n),
        binop_(std::move(binop)),
        id_(std::move(id)),
        tree_{{build(size_, init)}} {}
  template <detail::input_iterator<Monoid> IIter>
  id7(IIter first, IIter last, BinOp binop, Id id)
      : pool_(std::distance(first, last)),
        size_(static_cast<int>(std::distance(first, last))),
        binop_(std::move(binop)),
        id_(std::move(id)),
        tree_{{build(first, size_)}} {}
  Monoid
  get(int pos, int version) const {
    erf_assert(0 <= version && version <= latest());
    erf_assert(0 <= pos && pos < size());
    return search(tree_[version], pos)->value;
  }
  Monoid
  get(int pos) const {
    return get(pos, latest());
  }
  void
  set(int pos, Monoid new_val, int version) {
    erf_assert(0 <= version && version <= latest());
    erf_assert(0 <= pos && pos < size());
    node_pointer new_root = search_update(
        tree_[version], pos,
        [new_val = std::move(new_val)](Monoid) { return std::move(new_val); });
    add_latest(new_root);
  }
  void
  set(int pos, Monoid new_val) {
    set(pos, std::move(new_val), latest());
  }
  void
  apply(int pos, Monoid z, int version) {
    erf_assert(0 <= version && version <= latest());
    erf_assert(0 <= pos && pos < size());
    node_pointer new_root = search_update(
        tree_[version], pos, [z = std::move(z), this](Monoid val) {
          return binop_(std::move(val), std::move(z));
        });
    add_latest(new_root);
  }
  void
  apply(int pos, Monoid z) {
    apply(pos, std::move(z), latest());
  }
  Monoid
  query(int l, int r, int version) const {
    erf_assert(0 <= version && version <= latest());
    erf_assert(0 <= l && l <= r && r <= size());
    if (erf_likely(l < r)) {
      return product(tree_[version], 0, size(), l, r);
    } else {
      return id_();
    }
  }
  Monoid
  query(int l, int r) const {
    return query(l, r, latest());
  }
  template <std::predicate<Monoid> Pred>
  int
  id5(int l, const Pred& pred, int version) const {
    erf_assert(0 <= l && l <= size());
    erf_assert(pred(id_()));
    return id10(tree_[version], l, pred);
  }
  template <std::predicate<Monoid> Pred>
  int
  id5(int l, const Pred& pred) const {
    return id5(l, pred, latest());
  }
  template <std::predicate<Monoid> Pred>
  int
  id0(int r, const Pred& pred, int version) const {
    erf_assert(0 <= r && r <= size());
    erf_assert(pred(id_()));
    return bisectl(tree_[version], r, pred);
  }
  template <std::predicate<Monoid> Pred>
  int
  id0(int r, const Pred& pred) const {
    return id0(r, pred, latest());
  }
  int
  latest() const {
    return static_cast<int>(tree_.size()) - 1;
  }
  int
  size() const {
    return size_;
  }
private:
  template <detail::input_iterator<Monoid> IIter>
  node_pointer
  build(IIter base, int n) {
    node_pointer res = pool_.allocate(*base);
    if (n > 1) {
      res->left = build(base, n >> 1);
      res->right = build(base + (n >> 1), n - (n >> 1));
      update(res);
    }
    return res;
  }
  node_pointer
  build(int n, const Monoid& value) {
    node_pointer res = pool_.allocate(value);
    if (n > 1) {
      res->left = build(n >> 1, value);
      res->right = build(n - (n >> 1), value);
      update(res);
    }
    return res;
  }
  const_node_pointer
  search(const_node_pointer root, int pos) const {
    int l = 0, r = size();
    const_node_pointer cur = root;
    while (r - l > 1) {
      const int mid = (l + r) >> 1;
      if (pos < mid) {
        cur = cur->left, r = mid;
      } else {
        cur = cur->right, l = mid;
      }
    }
    return cur;
  }
  template <typename G>
  node_pointer
  search_update(const_node_pointer root, int pos, G g) {
    int l = 0, r = size();
    std::stack<node_pointer, std::vector<node_pointer>> stk;
    node_pointer tmp = pool_.clone(root);
    node_pointer cur = tmp;
    while (r - l > 1) {
      stk.push(cur);
      const int mid = (l + r) >> 1;
      if (pos < mid) {
        cur->left = pool_.clone(cur->left);
        cur = cur->left, r = mid;
      } else {
        cur->right = pool_.clone(cur->right);
        cur = cur->right, l = mid;
      }
    }
    cur->value = g(std::move(cur->value));
    while (!stk.empty()) { update(stk.top()), stk.pop(); }
    return tmp;
  }
  Monoid
  product(const_node_pointer root, int tl, int tr, int l, int r) const {
    if (l <= tl && tr <= r) { return root->value; }
    const int mid = (tl + tr) >> 1;
    Monoid resl = l < mid ? product(root->left, tl, mid, l, r) : id_();
    Monoid resr = mid < r ? product(root->right, mid, tr, l, r) : id_();
    return binop_(std::move(resl), std::move(resr));
  }
  template <typename Pred>
  int
  bisectl(const_node_pointer root, int r, const Pred& pred) const {
    Monoid now = id_();
    auto fn = [&](auto fn, const_node_pointer cur, int tl, int tr) -> int {
      if (tr <= r) {
        if (Monoid tmp = binop_(cur->value, now); pred(tmp)) {
          now = std::move(tmp);
          return tl;
        }
        if (tr - tl == 1) { return tr; }
      }
      const int mid = (tl + tr) >> 1;
      const int resr = mid < r ? fn(fn, cur->right, mid, tr) : mid;
      return resr != mid ? resr : fn(fn, cur->left, tl, mid);
    };
    return fn(fn, root, 0, size());
  }
  template <typename Pred>
  int
  id10(const_node_pointer root, int l, const Pred& pred) const {
    Monoid now = id_();
    auto fn = [&](auto fn, const_node_pointer cur, int tl, int tr) -> int {
      if (l <= tl) {
        if (Monoid tmp = binop_(now, cur->value); pred(tmp)) {
          now = std::move(tmp);
          return tr;
        }
        if (tr - tl == 1) { return tl; }
      }
      const int mid = (tl + tr) >> 1;
      const int resl = l < mid ? fn(fn, cur->left, tl, mid) : mid;
      return resl != mid ? resl : fn(fn, cur->right, mid, tr);
    };
    return fn(fn, root, 0, size());
  }
  void
  update(node_pointer root) {
    root->value = binop_(root->left->value, root->right->value);
  }
  void
  add_latest(node_pointer new_root) noexcept {
    tree_.emplace_back(new_root);
  }
  node_allocator_type pool_;
  int size_;
  BinOp binop_;
  Id id_;
  std::vector<node_pointer> tree_;
};
template <typename Monoid, typename BinOp, typename Id>
id7(int, const Monoid&, BinOp, Id)
    -> id7<Monoid, BinOp, Id>;
template <typename IIter, typename BinOp, typename Id>
id7(IIter, IIter, BinOp, Id)
    -> id7<std::iter_value_t<IIter>, BinOp, Id>;
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
using std::shared_ptr;
using std::tie;
using std::unique_ptr;
using std::to_string;
using std::tuple;
using std::vector;
using wint = int64_t;
using uint = uint32_t;
using bint = uint8_t;
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
  const int len = 1 << n;
  array<string, 20> sn{};
  for (int i = 0; i < n; ++i) {
    cin >> sn[i];
  }
  auto fx = [](int x, int y) { return x + y; };
  auto ef = [] { return 0; };
  using pseg = algo::id7<int, decltype(fx), decltype(ef)>;
  using fmap = algo::hash_map<int, int>;
  array<unique_ptr<pseg>, 20> ps{};
  array<int, 20> ms{};
  array<fmap, 20> ffs{};
  vector<int> fsum(len);
  for (int i = 0; i < n; ++i) {
    const int m = sn[i].length();
    ps[i].reset(new pseg(m + m + 1, fx, ef));
    int s = 0;
    for (int j = 0; j < m; ++j) {
      s += algo::alt(sn[i][j] == ')');
      ps[i]->apply(s + m, 1);
      if (ffs[i].find(s) == ffs[i].end()) {
        ffs[i][s] = j;
      }
      ms[i] = min(ms[i], s);
    }
    fsum[1 << i] = s;
  }
  for (int i = 0; i < n; ++i) {
    for (int m = 0; m < len; ++m) {
      if (m >> i & 1) {
        fsum[m] += fsum[m ^ (1 << i)];
      }
    }
  }
  vector<int> dp(len, -INF);
  dp[0] = 0;
  int ans = 0;
  for (int m = 0; m < len; ++m) {
    for (int i = 0; i < n; ++i) {
      if ((m >> i & 1)) {
        const int pm = m ^ (1 << i);
        const int si = ssize(sn[i]);
        if (fsum[pm] + ms[i] >= 0) {
          if (fsum[pm] <= si && fsum[pm] >= -si) {
            dp[m] = max(dp[pm] + ps[i]->get(si - fsum[pm]), dp[m]);
          } else {
            dp[m] = max(dp[pm], dp[m]);
          }
        } else {
          if (fsum[pm] <= si && fsum[pm] >= -si) {
            ans = max(
                ans, dp[pm] + ps[i]->get(si - fsum[pm], ffs[i][-fsum[pm] - 1]));
          }
        }
      }
    }
    ans = max(ans, dp[m]);
  }
  cout << ans << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}
