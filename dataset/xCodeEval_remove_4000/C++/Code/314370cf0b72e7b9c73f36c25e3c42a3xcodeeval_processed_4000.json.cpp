













































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
id3(Tp n) {
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
id7(Tp n) {
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
id7(Tp n) {
  return detail::id7(n);
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
  assert(n >= 0);
  return detail::sqrt(n);
}
template <detail::integer Tp>
constexpr Tp
id9(Tp n) {
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
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
class id6 {
public:
  id6() = default;
  id6(int n, BinOp binop, Id id)
      : n_(n),
        lg2_(detail::id7(n)),
        size_(1 << lg2_),
        tree_(size_ << 1, id()),
        binop_(std::move(binop)),
        id_(std::move(id)) {}
  id6(int n, const Monoid& init, BinOp binop, Id id)
      : n_(n),
        lg2_(detail::id7(n)),
        size_(1 << lg2_),
        tree_(size_ << 1, init),
        binop_(std::move(binop)),
        id_(std::move(id)) {
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> IIter>
  id6(IIter first, IIter last, BinOp binop, Id id)
      : id6(static_cast<int>(std::distance(first, last)), std::move(binop),
                std::move(id)) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <std::input_iterator IIter,
            detail::function<Monoid(std::iter_value_t<IIter>)> Gen>
  id6(IIter first, IIter last, BinOp binop, Id id, Gen gen)
      : id6(static_cast<int>(std::distance(first, last)), std::move(binop),
                std::move(id)) {
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
    const int mask = detail::id4(l ^ r) - 1;
    for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
      resl = binop_(std::move(resl), tree_[(l >> detail::id8(v)) + 1]);
    }
    for (int v = mask & r; v != 0; v = detail::blsr(v)) {
      resr = binop_(tree_[(r >> detail::id8(v)) - 1], std::move(resr));
    }
    return binop_(std::move(resl), std::move(resr));
  }
  Monoid
  query() const {
    return tree_[1];
  }
  template <std::predicate<Monoid> Pred>
  int
  id5(int l, const Pred& pred) const {
    assert(0 <= l && l <= size());
    assert(pred(id_()));
    if (l < n_) [[likely]] {
      l += size_;
      Monoid cur = id_();
      do {
        l >>= detail::id8(l);
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
    return size();
  }
  template <std::predicate<Monoid> Pred>
  int
  id0(int r, const Pred& pred) const {
    assert(0 <= r && r <= size());
    if (r > 0) [[likely]] {
      r += size_ - 1;
      Monoid cur = id_();
      do {
        r >>= detail::id8(~r);
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
template <typename Monoid, typename BinOp, typename Id>
id6(int, const Monoid&, BinOp, Id) -> id6<Monoid, BinOp, Id>;
template <typename IIter, typename BinOp, typename Id>
id6(IIter, IIter, BinOp, Id)
    -> id6<std::iter_value_t<IIter>, BinOp, Id>;
}
namespace algo {
class sieve {
public:
  sieve() = default;
  explicit sieve(int n) noexcept : n_(n), factors_(((n + 5) / 6) << 1) {
    const int m = (n + 5) / 6;
    const int kmax = (detail::sqrt((6 * m + 1)) - 5) / 6 + 1;
    factors_[(0 << 1) + 0] = 1;
    for (int k = 0; k <= kmax; ++k) {
      if (factors_[(k << 1) + 0] == 0) {
        const int pm = 6 * k + 1;
        const int s0 = k * (6 * k + 2 * 1) + (1 * 1) / 6;
        const int s1 = s0 + 4 * k + 0;
        for (int s = s0; s < m; s += pm) { factors_[(s << 1) + 0] = pm; }
        for (int s = s1; s < m; s += pm) { factors_[(s << 1) + 1] = pm; }
      }
      if (factors_[(k << 1) + 1] == 0) {
        const int pm = 6 * k + 5;
        const int s0 = k * (6 * k + 2 * 5) + (5 * 5) / 6;
        const int s1 = s0 + 2 * k + 1;
        for (int s = s0; s < m; s += pm) { factors_[(s << 1) + 0] = pm; }
        for (int s = s1; s < m; s += pm) { factors_[(s << 1) + 1] = pm; }
      }
    }
  }
  [[gnu::pure]] std::vector<std::pair<int, int>>
  factorize(int n) const {
    assert(1 <= n && n <= limit());
    detail::assume(1 <= n);
    std::vector<std::pair<int, int>> ans;
    ans.reserve(20);
    if (n % 2 == 0) {
      int c = 0;
      do { n /= 2, c++; } while (n % 2 == 0);
      ans.emplace_back(2, c);
    }
    if (n % 3 == 0) {
      int c = 0;
      do { n /= 3, c++; } while (n % 3 == 0);
      ans.emplace_back(3, c);
    }
    while (n > 1) {
      const int p = get_nontrivial_factor(n);
      int c = 0;
      do { n /= p, c++; } while (n % p == 0);
      ans.emplace_back(p, c);
    }
    return ans;
  }
  [[gnu::pure]] std::vector<int>
  divisors(int n) const {
    assert(1 <= n && n <= limit());
    detail::assume(0 < n);
    std::vector<int> ans{1};
    if (n % 2 == 0) {
      int c = 0;
      do { n /= 2, c++; } while (n % 2 == 0);
      const int sz = static_cast<int>(ans.size());
      for (int i = 0; i < sz; ++i) {
        for (int j = 0, d = ans[i]; j < c; ++j) { ans.emplace_back(d *= 2); }
      }
    }
    if (n % 3 == 0) {
      int c = 0;
      do { n /= 3, c++; } while (n % 3 == 0);
      const int sz = static_cast<int>(ans.size());
      for (int i = 0; i < sz; ++i) {
        for (int j = 0, d = ans[i]; j < c; ++j) { ans.emplace_back(d *= 3); }
      }
    }
    while (n > 1) {
      const int p = get_nontrivial_factor(n);
      int c = 0;
      do { n /= p, c++; } while (n % p == 0);
      const int sz = static_cast<int>(ans.size());
      for (int i = 0; i < sz; ++i) {
        for (int j = 0, d = ans[i]; j < c; ++j) { ans.emplace_back(d *= p); }
      }
    }
    return ans;
  }
  [[gnu::pure]] int
  totient(int n) const {
    assert(1 <= n && n <= limit());
    detail::assume(1 <= n);
    int ans = n;
    if (n % 2 == 0) {
      ans -= ans / 2;
      do { n /= 2; } while (n % 2 == 0);
    }
    if (n % 3 == 0) {
      ans -= ans / 3;
      do { n /= 3; } while (n % 3 == 0);
    }
    while (n > 1) {
      const int p = get_nontrivial_factor(n);
      ans -= ans / p;
      do { n /= p; } while (n % p == 0);
    }
    return ans;
  }
  [[gnu::pure]] int
  mobius(int n) const {
    assert(1 <= n && n <= limit());
    detail::assume(1 <= n);
    bool parity = false;
    if (n % 2 == 0) {
      if ((n /= 2) % 2 == 0) { return 0; }
      parity ^= 1;
    }
    if (n % 3 == 0) {
      if ((n /= 3) % 3 == 0) { return 0; }
      parity ^= 1;
    }
    while (n > 1) {
      const int p = get_nontrivial_factor(n);
      if ((n /= p) % p == 0) { return 0; }
      parity ^= 1;
    }
    return detail::alt(parity);
  }
  [[gnu::pure]] bool
  is_prime(int n) const {
    assert(1 <= n && n <= limit());
    detail::assume(1 <= n);
    return n == get_factor(n);
  }
  [[gnu::pure]] int
  get_factor(int n) const {
    assert(1 <= n && n <= limit());
    detail::assume(1 <= n);
    if (n % 2 == 0) { return 2; }
    if (n % 3 == 0) { return 3; }
    return get_nontrivial_factor(n);
  }
  int
  limit() const {
    return n_;
  }
private:
  inline int
  get_nontrivial_factor(int n) const {
    detail::assume(1 <= n);
    const int q = n / 6;
    const int r = n % 6;
    const int index = (q << 1) + (r >> 2);
    return factors_[index] ? factors_[index] : n;
  }
  int n_;
  std::vector<int> factors_;
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
  struct node {
    int l, r, w;
    bool flag;
  };
  const algo::sieve sv(MAXN - 1);
  vector<node> vs;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    vs.emplace_back(l, r, i, true);
  }
  for (int k = 3; k < MAXN / 2 + 1; ++k) {
    {
      auto d = sv.divisors(k);
      sort(d.begin(), d.end());
      const int cnt = ssize(d);
      for (int i = cnt - 2; i >= 0; --i) {
        int w = cnt - i - 2;
        w -= d.end() - upper_bound(d.begin() + i + 1, d.end(), k - d[i]) - 1;
        vs.emplace_back(d[i], k, w, false);
      }
    }
    {
      auto d = sv.divisors(2 * k);
      sort(d.begin(), d.end());
      d.pop_back();
      const int cnt = ssize(d);
      for (int i = cnt - 2; i >= 0; --i) {
        int w = d.end() - upper_bound(d.begin() + i + 1, d.end(), k - d[i]) - 1;
        vs.emplace_back(d[i], k, w, false);
      }
    }
  }
  sort(vs.begin(), vs.end(), [](node x, node y) {
    return x.l == y.l ? x.r == y.r ? !x.flag && y.flag : x.r < y.r : x.l > y.l;
  });
  auto fx = [](wint x, wint y) { return x + y; };
  auto ef = [] { return wint(0); };
  algo::id6 seg(200001, wint(0), fx, ef);
  vector<wint> ans(q);
  for (const auto [l, r, w, f] : vs) {
    if (f == 1) {
      wint x = r - l + 1;
      ans[w] += x * (x - 1) * (x - 2) / 6;
      ans[w] -= seg.query(0, r + 1);
    } else {
      seg.apply(r, w);
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}
