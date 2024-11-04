#pragma GCC target("abm,movbe,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("f16c,fma,avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("stack-check=no")
#define NDEBUG 1
#include <immintrin.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
namespace dbg {
#define debug(x) ((void)0)
}
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
template <typename Function>
using extract_return_t = typename function_traits<Function>::result_type;
}
}
namespace algo {
namespace detail {
template <dword_fittable Tp>
constexpr int
count_lz(Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable Tp>
constexpr int
count_lz(Tp n) {
  return __builtin_clzll(n);
}
template <dword_fittable Tp>
constexpr int
count_tz(Tp n) {
  return __builtin_ctz(n);
}
template <qword_fittable Tp>
constexpr int
count_tz(Tp n) {
  return __builtin_ctzll(n);
}
template <dword_fittable Tp>
constexpr int
find_ffs(Tp n) {
  return __builtin_ffs(n) - 1;
}
template <qword_fittable Tp>
constexpr int
find_ffs(Tp n) {
  return __builtin_ffsll(n) - 1;
}
template <dword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 32 - count_lz(n);
}
template <qword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 64 - count_lz(n);
}
template <dword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1u << (31 - count_lz(n));
}
template <qword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1ull << (63 - count_lz(n));
}
template <integer Tp>
constexpr Tp
bit_ceil(Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return bit_floor(n - 1) << 1;
}
template <dword_fittable Tp>
constexpr int
log2_floor(Tp n) {
  return 31 - count_lz(n);
}
template <qword_fittable Tp>
constexpr int
log2_floor(Tp n) {
  return 63 - count_lz(n);
}
template <integer Tp>
constexpr int
log2_ceil(Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return log2_floor(n - 1) + 1;
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
template <typename Monoid, typename X, typename Operation, typename Map,
          typename Composition, typename Identity, typename CompositionIdentity>
class lazy_segtree;
template <std::semiregular Monoid, std::semiregular X,
          detail::binary_op<Monoid> Operation,
          detail::callable<Monoid, Monoid, X> Map,
          detail::binary_op<X> Composition, detail::callable<Monoid> Identity,
          detail::callable<X> CompositionIdentity>
class lazy_segtree<Monoid, X, Operation, Map, Composition, Identity,
                   CompositionIdentity> {
public:
  lazy_segtree() = default;
  lazy_segtree(int n, const Operation &f, const Map &mapping,
               const Composition &g, const Identity &ef,
               const CompositionIdentity &eg)
      : n_(n),
        lg2_(detail::log2_ceil(n_)),
        size_(1 << lg2_),
        tree_(size_ << 1, ef()),
        lazy_(size_, eg()),
        f_(f),
        map_(mapping),
        g_(g),
        ef_(ef),
        eg_(eg) {}
  lazy_segtree(int n, const Monoid &init, const Operation &f,
               const Map &mapping, const Composition &g, const Identity &ef,
               const CompositionIdentity &eg)
      : n_(n),
        lg2_(detail::log2_ceil(n_)),
        size_(1 << lg2_),
        tree_(size_ << 1, init),
        lazy_(size_, eg()),
        f_(f),
        map_(mapping),
        g_(g),
        ef_(ef),
        eg_(eg) {
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> InputIterator>
  lazy_segtree(InputIterator first, InputIterator last, const Operation &f,
               const Map &mapping, const Composition &g, const Identity &ef,
               const CompositionIdentity &eg)
      : lazy_segtree(std::distance(first, last), f, mapping, g, ef, eg) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <std::input_iterator InputIterator,
            detail::callable<Monoid, std::iter_value_t<InputIterator>> Gen>
  lazy_segtree(InputIterator first, InputIterator last, const Operation &f,
               const Map &mapping, const Composition &g, const Identity &ef,
               const CompositionIdentity &eg, const Gen &gen)
      : lazy_segtree(std::distance(first, last), f, mapping, g, ef, eg) {
    std::transform(first, last, tree_.begin() + size_, gen);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  void
  set(int pos, const Monoid &value) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = lg2_; i >= 1; --i) { push(pos >> i); }
    tree_[pos] = value;
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  Monoid
  get(int pos) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = lg2_; i >= 1; --i) { push(pos >> i); }
    return tree_[pos];
  }
  void
  apply(int pos, const X &arg) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = lg2_; i >= 1; --i) { push(pos >> i); }
    tree_[pos] = map_(tree_[pos], arg);
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  void
  apply_commutative(int pos, const X &arg) {
    assert(0 <= pos && pos < size());
    pos += size_;
    tree_[pos] = map_(tree_[pos], arg);
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  void
  apply(int l, int r, const X &arg) {
    assert(0 <= l && l <= r && r <= size());
    if (l < r) {
      l += size_;
      r += size_;
      const int tz_l = detail::count_tz(l);
      const int tz_r = detail::count_tz(r);
      for (int i = lg2_; i > tz_l; --i) { push(l >> i); }
      for (int i = lg2_; i > tz_r; --i) { push((r - 1) >> i); }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { apply_subtree(_l++, arg); }
        if (_r & 0x01) { apply_subtree(--_r, arg); }
      }
      for (int i = tz_l + 1; i <= lg2_; ++i) { update(l >> i); }
      for (int i = tz_r + 1; i <= lg2_; ++i) { update((r - 1) >> i); }
    }
  }
  void
  apply_commutative(int l, int r, const X &arg) {
    assert(0 <= l && l <= r && r <= size());
    if (l < r) {
      l += size_;
      r += size_;
      const int tz_l = detail::count_tz(l);
      const int tz_r = detail::count_tz(r);
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { apply_subtree(_l++, arg); }
        if (_r & 0x01) { apply_subtree(--_r, arg); }
      }
      for (int i = tz_l + 1; i <= lg2_; ++i) { update(l >> i); }
      for (int i = tz_r + 1; i <= lg2_; ++i) { update((r - 1) >> i); }
    }
  }
  Monoid
  query(int l, int r) {
    assert(0 <= l && l <= r && r <= size());
    Monoid resl = ef_(), resr = ef_();
    if (l < r) {
      l += size_;
      r += size_;
      const int tz_l = detail::count_tz(l);
      const int tz_r = detail::count_tz(r);
      for (int i = lg2_; i > tz_l; --i) { push(l >> i); }
      for (int i = lg2_; i > tz_r; --i) { push((r - 1) >> i); }
      do {
        if (l & 0x01) { resl = f_(resl, tree_[l++]); }
        if (r & 0x01) { resr = f_(tree_[--r], resr); }
        l >>= 1;
        r >>= 1;
      } while (l < r);
    }
    return f_(resl, resr);
  }
  Monoid
  query() const {
    return tree_[1];
  }
  template <std::predicate<Monoid> Predicate>
  int
  bisect_right(int l, const Predicate &pred) {
    assert(0 <= l && l <= size());
    assert(pred(ef_()));
    if (detail::likely(l < n_)) {
      l += size_;
      for (int i = lg2_; i >= 1; --i) { push(l >> i); }
      Monoid cur = ef_();
      do {
        l >>= detail::count_tz(l);
        if (!pred(f_(cur, tree_[l]))) {
          while (l < size_) {
            push(l);
            l <<= 1;
            if (const Monoid tmp = f_(cur, tree_[l]); pred(tmp)) {
              cur = tmp, ++l;
            }
          }
          return l - size_;
        }
        cur = f_(cur, tree_[l++]);
      } while ((l & -l) - l);
    }
    return n_;
  }
  template <std::predicate<Monoid> Predicate>
  int
  bisect_left(int r, const Predicate &pred) {
    assert(0 <= r && r <= size());
    assert(pred(ef_()));
    if (detail::likely(r > 0)) {
      r += size_;
      for (int i = lg2_; i >= 1; --i) { push(r - 1 >> i); }
      Monoid cur = ef_();
      do {
        r >>= detail::count_tz(r);
        r ^= (r > 1);
        if (!pred(f_(tree_[r], cur))) {
          while (r < size_) {
            push(r);
            r <<= 1;
            r |= 1;
            if (const Monoid tmp = f_(cur, tree_[r]); pred(tmp)) {
              cur = tmp, --r;
            }
          }
          return r + 1 - size_;
        }
        cur = f_(tree_[r], cur);
      } while ((r & -r) - r);
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
    tree_[v] = f_(tree_[v << 1], tree_[v << 1 | 1]);
  }
  void
  apply_subtree(int v, const X &arg) {
    tree_[v] = map_(tree_[v], arg);
    if (v < size_) { lazy_[v] = g_(lazy_[v], arg); }
  }
  void
  push(int v) {
    apply_subtree(v << 1, lazy_[v]);
    apply_subtree(v << 1 | 1, lazy_[v]);
    lazy_[v] = eg_();
  }
  int n_, lg2_, size_;
  std::vector<Monoid> tree_;
  std::vector<X> lazy_;
  Operation f_;
  Map map_;
  Composition g_;
  Identity ef_;
  CompositionIdentity eg_;
};
template <std::semiregular Tp, std::semiregular X,
          detail::callable<Tp, Tp, X> Map, detail::binary_op<X> Composition,
          detail::callable<X> CompositionIdentity>
class lazy_segtree<Tp, X, void, Map, Composition, void, CompositionIdentity> {
public:
  lazy_segtree() = default;
  lazy_segtree(int n, const Map &mapping, const Composition &g,
               const CompositionIdentity &eg)
      : n_(n),
        lg2_(detail::log2_ceil(n_)),
        size_(1 << lg2_),
        tree_(size_),
        lazy_(size_, eg()),
        map_(mapping),
        g_(g),
        eg_(eg) {}
  lazy_segtree(int n, const Tp &init, const Map &mapping, const Composition &g,
               const CompositionIdentity &eg)
      : n_(n),
        lg2_(detail::log2_ceil(n_)),
        size_(1 << lg2_),
        tree_(size_, init),
        lazy_(size_, eg()),
        map_(mapping),
        g_(g),
        eg_(eg) {}
  template <detail::input_iterator<Tp> InputIterator>
  lazy_segtree(InputIterator first, InputIterator last, const Map &mapping,
               const Composition &g, const CompositionIdentity &eg)
      : lazy_segtree(std::distance(first, last), mapping, g, eg) {
    std::copy(first, last, tree_.begin());
  }
  template <std::input_iterator InputIterator,
            detail::callable<Tp, std::iter_value_t<InputIterator>> Gen>
  lazy_segtree(InputIterator first, InputIterator last, const Map &mapping,
               const Composition &g, const CompositionIdentity &eg,
               const Gen &gen)
      : lazy_segtree(std::distance(first, last), mapping, g, eg) {
    std::transform(first, last, tree_.begin(), gen);
  }
  void
  set(int pos, const Tp &new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = lg2_; i >= 1; --i) { push(pos >> i); }
    tree_[pos - size_] = new_val;
  }
  Tp
  get(int pos) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = lg2_; i >= 1; --i) { push(pos >> i); }
    return tree_[pos - size_];
  }
  void
  apply(int pos, const X &arg) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = lg2_; i >= 1; --i) { push(pos >> i); }
    tree_[pos - size_] = map_(tree_[pos - size_], arg);
  }
  void
  apply_commutative(int pos, const X &arg) {
    assert(0 <= pos && pos < size());
    tree_[pos] = map_(tree_[pos], arg);
  }
  void
  apply(int l, int r, const X &arg) {
    assert(0 <= l && l <= r && r <= size());
    if (l < r) {
      l += size_;
      r += size_;
      const int tz_l = detail::count_tz(l);
      const int tz_r = detail::count_tz(r);
      for (int i = lg2_; i > tz_l; --i) { push(l >> i); }
      for (int i = lg2_; i > tz_r; --i) { push((r - 1) >> i); }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { apply_subtree(_l++, arg); }
        if (_r & 0x01) { apply_subtree(--_r, arg); }
      }
    }
  }
  void
  apply_commutative(int l, int r, const X &arg) {
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
  apply_subtree(int v, const X &arg) {
    if (detail::unlikely(v >= size_)) {
      tree_[v - size_] = map_(tree_[v - size_], arg);
    } else {
      lazy_[v] = g_(lazy_[v], arg);
    }
  }
  void
  push(int v) {
    apply_subtree(v << 1, lazy_[v]);
    apply_subtree(v << 1 | 1, lazy_[v]);
    lazy_[v] = eg_();
  }
  int n_, lg2_, size_;
  std::vector<Tp> tree_;
  std::vector<X> lazy_;
  Map map_;
  Composition g_;
  CompositionIdentity eg_;
};
}
#pragma region alias
using std::array;
using std::vector;
using std::span;
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
using std::string_view;
using std::stringstream;
using std::pair;
using std::tuple;
using std::cin;
using std::cout;
using std::endl;
using std::gcd;
using std::lcm;
using std::max;
using std::min;
using std::swap;
using std::move;
using std::to_string;
namespace ranges = std::ranges;
namespace views = std::views;
template <typename Tp, typename Function>
using ordered_set = __gnu_pbds::tree<Tp,
__gnu_pbds::null_type, Function, __gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>;
using uint = unsigned int;
using wint = int64_t;
template <typename KeyType, typename ValueType>
using umap = std::unordered_map<KeyType, ValueType>;
template <typename ValueType> using uset = std::unordered_set<ValueType>;
template <typename Tp, typename Function = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Function>;
template <typename Tp, typename Function = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Function>;
#pragma endregion alias
#define INF 0x3f3f3f3f
#define MOD 998244353
#define MAXN 200001
#define MULTI 0
namespace {
}
void solve() noexcept {
  int n,q;cin>>n>>q;
  using node=struct{
    wint sum;
    int col,tl,tr;
  };
  using rec=struct{
    wint sum;
    int time;
  };
  vector<vector<rec>>record(n+1);
  auto mp1=[&](node x,node y){
    if(y.col==0){return x;}
    wint sum=x.sum+y.sum;
    int c=x.col,tl=x.tr,tr=y.tl;
    int p1=lower_bound(record[c].begin(),record[c].end(),rec{0,tl},
    [](rec w,rec v){return w.time<v.time;})-record[c].begin()-1;
    int p2=lower_bound(record[c].begin(),record[c].end(),rec{0,tr},
    [](rec w,rec v){return w.time<v.time;})-record[c].begin()-1;
    if(p2>=0){
      sum+=record[c][p2].sum;
    }
    if(p1>=0){
      sum-=record[c][p1].sum;
    }
    return node{sum,y.col,x.tl,y.tr};
  };
  auto g1=[&](node x,node y){
    if(y.col==0){return x;}
    if(x.col==0){return y;}
    wint sum=x.sum+y.sum;
    int c=x.col,tl=x.tr,tr=y.tl;
    int p1=lower_bound(record[c].begin(),record[c].end(),rec{0,tl},
    [](rec w,rec v){return w.time<v.time;})-record[c].begin()-1;
    int p2=lower_bound(record[c].begin(),record[c].end(),rec{0,tr},
    [](rec w,rec v){return w.time<v.time;})-record[c].begin()-1;
    if(p2>=0){
      sum+=record[c][p2].sum;
    }
    if(p1>=0){
      sum-=record[c][p1].sum;
    }
    return node{sum,y.col,x.tl,y.tr};
  };
  auto eg=[]{return node{0,0,0,0};};
  algo::lazy_segtree<node,node,void,decltype(mp1),decltype(g1),void,decltype(eg)>
  lsg(n+1,node{0,1,0,0},mp1,g1,eg);
  char buf[10];
  for(int time=1;time<=q;++time){
    cin>>buf;
    if(buf[0]=='C'){
      int l,r,c;cin>>l>>r>>c;
      lsg.apply(l,r+1,node{0,c,time,time});
    }else if(buf[0]=='A'){
      int c;cin>>c;
      wint x;cin>>x;
      x+=(record[c].empty())?0:record[c].back().sum;
      record[c].emplace_back(x,time);
    }else{
      int pos;cin>>pos;
      auto [sum,c,_,tr]=lsg.get(pos);
      int p1=lower_bound(record[c].begin(),record[c].end(),rec{0,tr},
      [](rec w,rec v){return w.time<v.time;})-record[c].begin()-1;
      int p2=-1+(int)record[c].size();
      if(p2>=0){
        sum+=record[c][p2].sum;
      }
      if(p1>=0){
        sum-=record[c][p1].sum;
      }
      cout<<sum<<'\n';
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
