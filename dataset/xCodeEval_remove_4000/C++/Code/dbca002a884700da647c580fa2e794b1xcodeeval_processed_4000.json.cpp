









namespace dbg {

}
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
id8(Tp n) {
  return std::countr_zero<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr int
bit_width(Tp n) {
  return std::bit_width<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr Tp
bit_floor(Tp n) {
  return static_cast<Tp>(std::bit_floor<std::make_unsigned_t<Tp>>(n));
}
template <typename Tp>
constexpr Tp
id0(Tp n) {
  return static_cast<Tp>(std::id0<std::make_unsigned_t<Tp>>(n));
}
template <typename Tp>
constexpr int
id5(Tp n) {
  return bit_width(n) - 1;
}
template <typename Tp>
constexpr int
id6(Tp n) {
  return bit_width(n - (n != 0));
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
id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr int
id6(Tp n) {
  return detail::id6(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}
namespace algo::detail {
constexpr void
assume(bool expr) {
  if (!expr) { __builtin_unreachable(); }
}
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n <= 1) { return n; }
  Tp ans = 0;
  for (int i = id5(n) - 1; i >= 0; --i) {
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
cdiv(Tp x, Tp y) {
  return y >= 0 ? (x + y - 1) / y : -(x / -y);
}
template <typename Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, char>>
sgn(Tp n) {
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
cdiv(T1 x, T2 y) {
  assert(y != 0);
  return detail::cdiv<std::common_type_t<T1, T2>>(x, y);
}
template <std::integral Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, char>>
sgn(Tp n) {
  return detail::sgn(n);
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
      res += sgn(neg) * m * n0;
      b0 = c0 - b0 - 1, a0 = c0, c0 = tmp, n0 = m - 1;
      neg ^= true;
    } else {
      const Tp tmp = (n0 * (n0 + 1) >> 1) * (a0 / c0) + (n0 + 1) * (b0 / c0);
      res += sgn(neg) * tmp;
      a0 %= c0, b0 %= c0;
    }
  }
  res += sgn(neg) * (b0 / c0) * (n0 + 1);
  return res;
}
}
namespace algo {
template <typename...>
class id9;
template <std::semiregular Monoid, std::semiregular id2,
          detail::binary_op<Monoid> Operation,
          detail::callable<Monoid, Monoid, id2> Map,
          detail::binary_op<id2> Composition,
          detail::callable<Monoid> Identity,
          detail::callable<id2> CompositionIdentity>
class id9<Monoid, id2, Operation, Map, Composition, Identity,
                   CompositionIdentity> {
public:
  id9() = default;
  id9(int n, const Operation& f, const Map& mapping,
               const Composition& g, const Identity& ef,
               const CompositionIdentity& eg)
      : n_(n),
        id7(detail::id6(n)),
        size_(1 << id7),
        tree_(size_ << 1, ef()),
        lazy_(size_, eg()),
        binop_(f),
        map_(mapping),
        comp_(g),
        id_(ef),
        id_comp_(eg) {}
  id9(int n, const Monoid& init, const Operation& f,
               const Map& mapping, const Composition& g, const Identity& ef,
               const CompositionIdentity& eg)
      : n_(n),
        id7(detail::id6(n)),
        size_(1 << id7),
        tree_(size_ << 1, init),
        lazy_(size_, eg()),
        binop_(f),
        map_(mapping),
        comp_(g),
        id_(ef),
        id_comp_(eg) {
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> InputIterator>
  id9(InputIterator first, InputIterator last, const Operation& f,
               const Map& mapping, const Composition& g, const Identity& ef,
               const CompositionIdentity& eg)
      : id9(std::distance(first, last), f, mapping, g, ef, eg) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <
      std::input_iterator InputIterator,
      detail::callable<Monoid, std::iter_value_t<InputIterator> > Generator>
  id9(InputIterator first, InputIterator last, const Operation& f,
               const Map& mapping, const Composition& g, const Identity& ef,
               const CompositionIdentity& eg, const Generator& gen)
      : id9(std::distance(first, last), f, mapping, g, ef, eg) {
    std::transform(first, last, tree_.begin() + size_, gen);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  void
  set(int pos, const Monoid& new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos] = new_val;
    for (int i = 1; i <= id7; ++i) { update(pos >> i); }
  }
  void
  set(int pos, Monoid&& new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos] = std::move(new_val);
    for (int i = 1; i <= id7; ++i) { update(pos >> i); }
  }
  Monoid
  get(int pos) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    return tree_[pos];
  }
  void
  apply(int pos, const id2& arg) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos] = map_(std::move(tree_[pos]), arg);
    for (int i = 1; i <= id7; ++i) { update(pos >> i); }
  }
  void
  apply(int pos, id2&& arg) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos] = map_(std::move(tree_[pos]), std::move(arg));
    for (int i = 1; i <= id7; ++i) { update(pos >> i); }
  }
  void
  apply(int l, int r, const id2& arg) {
    assert(0 <= l && l <= r && r <= size());
    if (l < r) {
      l += size_;
      r += size_;
      const int tz_l = detail::id8(l);
      const int tz_r = detail::id8(r);
      for (int i = id7; i > tz_l; --i) { push(l >> i); }
      for (int i = id7; i > tz_r; --i) { push((r - 1) >> i); }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { apply_subtree(_l++, arg); }
        if (_r & 0x01) { apply_subtree(--_r, arg); }
      }
      for (int i = tz_l + 1; i <= id7; ++i) { update(l >> i); }
      for (int i = tz_r + 1; i <= id7; ++i) { update((r - 1) >> i); }
    }
  }
  Monoid
  query(int l, int r) {
    assert(0 <= l && l <= r && r <= size());
    Monoid resl = id_(), resr = id_();
    if (l < r) {
      l += size_;
      r += size_;
      const int tz_l = detail::id8(l);
      const int tz_r = detail::id8(r);
      for (int i = id7; i > tz_l; --i) { push(l >> i); }
      for (int i = id7; i > tz_r; --i) { push((r - 1) >> i); }
      do {
        if (l & 0x01) { resl = binop_(std::move(resl), tree_[l++]); }
        if (r & 0x01) { resr = binop_(tree_[--r], std::move(resr)); }
        l >>= 1;
        r >>= 1;
      } while (l < r);
    }
    return binop_(std::move(resl), std::move(resr));
  }
  Monoid
  query() const {
    return tree_[1];
  }
  template <std::predicate<Monoid> Predicate>
  int
  id4(int l, const Predicate& pred) {
    assert(0 <= l && l <= size());
    assert(pred(id_()));
    if (l < n_) [[likely]] {
      l += size_;
      for (int i = id7; i > 0; --i) { push(l >> i); }
      Monoid cur = id_();
      do {
        l >>= detail::id8(l);
        if (!pred(binop_(cur, tree_[l]))) {
          while (l < size_) {
            push(l);
            l <<= 1;
            if (Monoid tmp = binop_(cur, tree_[l]); pred(tmp)) {
              cur = std::move(tmp), ++l;
            }
          }
          return l - size_;
        }
        cur = binop_(std::move(cur), tree_[l++]);
      } while (_blsr_u32(l) != 0);
    }
    return n_;
  }
  template <std::predicate<Monoid> Predicate>
  int
  id1(int r, const Predicate& pred) {
    assert(0 <= r && r <= size());
    assert(pred(id_()));
    if (r > 0) [[likely]] {
      r += size_;
      for (int i = id7; i >= 1; --i) { push((r - 1) >> i); }
      Monoid cur = id_();
      do {
        r >>= detail::id8(r);
        if (r > 1) { r -= 1; }
        if (!pred(binop_(tree_[r], cur))) {
          while (r < size_) {
            push(r);
            r <<= 1;
            r |= 1;
            if (Monoid tmp = binop_(cur, tree_[r]); pred(tmp)) {
              cur = std::move(tmp), --r;
            }
          }
          return r + 1 - size_;
        }
        cur = binop_(tree_[r], std::move(cur));
      } while (_blsr_u32(r) != 0);
    }
    return 0;
  }
  int
  size() const {
    return n_;
  }
private:
  void
  update(int v) {
    tree_[v] = binop_(tree_[v << 1], tree_[v << 1 | 1]);
  }
  void
  apply_subtree(int v, const id2& arg) {
    tree_[v] = map_(std::move(tree_[v]), arg);
    if (v < size_) { lazy_[v] = comp_(std::move(lazy_[v]), arg); }
  }
  void
  push(int v) {
    apply_subtree(v << 1, lazy_[v]);
    apply_subtree(v << 1 | 1, lazy_[v]);
    lazy_[v] = id_comp_();
  }
  int n_, id7, size_;
  std::vector<Monoid> tree_;
  std::vector<id2> lazy_;
  Operation binop_;
  Map map_;
  Composition comp_;
  Identity id_;
  CompositionIdentity id_comp_;
};
template <std::semiregular Tp, std::semiregular id2,
          detail::callable<Tp, Tp, id2> Map,
          detail::binary_op<id2> Composition,
          detail::callable<id2> CompositionIdentity>
class id9<Tp, id2, Map, Composition, CompositionIdentity> {
public:
  id9() = default;
  id9(int n, const Map& mapping, const Composition& g,
               const CompositionIdentity& eg)
      : n_(n),
        id7(detail::id6(n)),
        size_(1 << id7),
        tree_(size_),
        lazy_(size_, eg()),
        map_(mapping),
        comp_(g),
        id_comp_(eg) {}
  id9(int n, const Tp& init, const Map& mapping, const Composition& g,
               const CompositionIdentity& eg)
      : n_(n),
        id7(detail::id6(n)),
        size_(1 << id7),
        tree_(size_, init),
        lazy_(size_, eg()),
        map_(mapping),
        comp_(g),
        id_comp_(eg) {}
  template <detail::input_iterator<Tp> InputIterator>
  id9(InputIterator first, InputIterator last, const Map& mapping,
               const Composition& g, const CompositionIdentity& eg)
      : id9(std::distance(first, last), mapping, g, eg) {
    std::copy(first, last, tree_.begin());
  }
  template <std::input_iterator InputIterator,
            detail::callable<Tp, std::iter_value_t<InputIterator> > Generator>
  id9(InputIterator first, InputIterator last, const Map& mapping,
               const Composition& g, const CompositionIdentity& eg,
               const Generator& gen)
      : id9(std::distance(first, last), mapping, g, eg) {
    std::transform(first, last, tree_.begin(), gen);
  }
  void
  set(int pos, const Tp& new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos - size_] = new_val;
  }
  void
  set(int pos, Tp&& new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos - size_] = std::move(new_val);
  }
  Tp
  get(int pos) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    return tree_[pos - size_];
  }
  void
  apply(int pos, const id2& arg) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos - size_] = map_(std::move(tree_[pos - size_]), arg);
  }
  void
  apply(int pos, id2&& arg) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos - size_] = map_(std::move(tree_[pos - size_]), std::move(arg));
  }
  void
  apply_commutative(int pos, const id2& arg) {
    assert(0 <= pos && pos < size());
    tree_[pos] = map_(std::move(tree_[pos]), arg);
  }
  void
  apply_commutative(int pos, id2&& arg) {
    assert(0 <= pos && pos < size());
    tree_[pos] = map_(std::move(tree_[pos]), std::move(arg));
  }
  void
  apply(int l, int r, const id2& arg) {
    assert(0 <= l && l <= r && r <= size());
    if (l < r) {
      l += size_;
      r += size_;
      const int tz_l = detail::id8(l);
      const int tz_r = detail::id8(r);
      for (int i = id7; i > tz_l; --i) { push(l >> i); }
      for (int i = id7; i > tz_r; --i) { push((r - 1) >> i); }
      do {
        if (l & 0x01) { apply_subtree(l++, arg); }
        if (r & 0x01) { apply_subtree(--r, arg); }
        l >>= 1;
        r >>= 1;
      } while (l < r);
    }
  }
  void
  apply_commutative(int l, int r, const id2& arg) {
    assert(0 <= l && l <= r && r <= size());
    for (l += size_, r += size_; l < r; l >>= 1, r >>= 1) {
      if (l & 0x01) { apply_subtree(l++, arg); }
      if (r & 0x01) { apply_subtree(--r, arg); }
    }
  }
  int
  size() const {
    return n_;
  }
private:
  void
  apply_subtree(int v, const id2& arg) {
    if (v < size_) [[likely]] {
      lazy_[v] = comp_(std::move(lazy_[v]), arg);
    } else {
      tree_[v - size_] = map_(std::move(tree_[v - size_]), arg);
    }
  }
  void
  push(int v) {
    apply_subtree(v << 1, lazy_[v]);
    apply_subtree(v << 1 | 1, lazy_[v]);
    lazy_[v] = id_comp_();
  }
  int n_, id7, size_;
  std::vector<Tp> tree_;
  std::vector<id2> lazy_;
  Map map_;
  Composition comp_;
  CompositionIdentity id_comp_;
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
using std::lcm;
using std::tie;
using std::max;
using std::min;
using std::move;
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
constexpr int64_t operator""_w(unsigned long long x) { return static_cast<int64_t>(x); }
namespace {
}
void solve() noexcept {
  struct node{
    wint sum;
    int tl,tr,col;
  };
  struct data{
    wint sum;
    int time;
  };
  int n,q;cin>>n>>q;
  vector<vector<data>>pref(n+1,vector<data>{{0,0}});
  auto comp=[&](node x,node y){
    if(x.col==0){return y;}
    if(y.col==0){return x;}
    node res{x.sum+y.sum,x.tl,y.tr,y.col};
    int col=x.col;
    auto pos=lower_bound(pref[col].begin(),pref[col].end(),y.tl,[](data d,int t){return d.time<t;});
    if(pos!=pref[col].begin()){
      res.sum+=prev(pos)->sum;
    }
    return res;
  };
  auto eg=[]{return node{0,0,0,0};};
  algo::id9<node,node,decltype(comp),decltype(comp),decltype(eg)>
  lsg(n,node{0,0,0,1},comp,comp,eg);
  char buf[10];
  for(int t=1;t<=q;++t){
    cin>>buf;
    if(buf[0]=='C'){
      int l,r,c;cin>>l>>r>>c;
      const wint s=pref[c].back().sum;
      lsg.apply(--l,r,node{.sum=-s,.tl=t,.tr=t,.col=c});
    }else if(buf[0]=='A'){
      int c,x;cin>>c>>x;
      const wint s=pref[c].back().sum;
      pref[c].emplace_back(s+x,t);
    }else{
      int i;cin>>i;
      auto[s,_,__,c]=lsg.get(--i);
      cout<<s+pref[c].back().sum<<'\n';
    }
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
