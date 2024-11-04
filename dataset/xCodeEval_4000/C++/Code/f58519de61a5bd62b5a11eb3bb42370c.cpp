#pragma GCC target("abm,movbe,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("f16c,fma,avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("stack-check=no")
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
concept signed_integer = integer<Tp> && (Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> && (Tp(-1) > Tp(0));
template <typename Tp>
concept addable = requires(std::remove_reference_t<Tp> &a,
                           const std::remove_reference_t<Tp> &b) {
  { a += b }
  ->std::same_as<std::remove_reference_t<Tp> &>;
};
template <typename Tp>
concept multipliable = requires(std::remove_reference_t<Tp> &a,
                                const std::remove_reference_t<Tp> &b) {
  { a *= b }
  ->std::same_as<std::remove_reference_t<Tp> &>;
};
template <typename Function>
struct function_traits : public function_traits<decltype(
                             &std::remove_reference_t<Function>::operator())> {
};
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
template <typename Function, typename ReturnType, typename... Args>
concept callable = std::invocable<Function, Args...>
    &&std::same_as<std::invoke_result_t<Function, Args...>, ReturnType>;
template <typename Function, typename Arg>
concept unary_op = callable<Function, Arg, Arg>;
template <typename Function, typename Arg>
concept binary_op = callable<Function, Arg, Arg, Arg>;
template <typename Tp>
concept less_than_comparable = requires(const std::remove_reference_t<Tp> &a,
                                        const std::remove_reference_t<Tp> &b) {
  { a < b }
  ->std::convertible_to<bool>;
  { !(a < b) }
  ->std::convertible_to<bool>;
};
template <typename Tp>
concept equality_comparable = std::equality_comparable<Tp>;
template <typename From, typename To>
concept constructible = std::constructible_from<To, From>;
template <typename InputIterator, typename ValueType>
concept input_iterator = std::input_iterator<InputIterator>
    &&std::same_as<std::iter_value_t<InputIterator>, ValueType>;
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
}
}
namespace algo {
namespace detail {
constexpr long
likely(bool x) noexcept {
  return __builtin_expect(x, 1);
}
constexpr long
unlikely(bool x) noexcept {
  return __builtin_expect(x, 0);
}
constexpr void
unreachable() noexcept {
  __builtin_unreachable();
}
constexpr void
assume(bool x) noexcept {
  if (!x) unreachable();
}
}
}
namespace algo {
template <typename Function>
struct rec_lambda {
  constexpr rec_lambda(const Function &f) : f_(f) {}
  template <typename... Args>
  constexpr decltype(auto)
  operator()(Args &&... args) const {
    return f_(*this, std::forward<Args>(args)...);
  }
private:
  Function f_;
};
constexpr long
likely(bool x) {
  return detail::likely(x);
}
constexpr long
unlikely(bool x) {
  return detail::unlikely(x);
}
constexpr void
assume(bool x) {
  detail::assume(x);
}
constexpr void
unreachable() {
  detail::unreachable();
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
template <std::semiregular Monoid, detail::binary_op<Monoid> Operation,
          detail::callable<Monoid> Identity>
class fenwick_tree {
public:
  fenwick_tree() = default;
  fenwick_tree(int n, const Operation &f, const Identity &e)
      : size_(n),
        lg2_(detail::log2_floor(n)),
        tree_(size_ + 1, e()),
        f_(f),
        ef_(e) {}
  void
  apply(int pos, const Monoid &z) {
    for (++pos; pos <= size_; pos += lowbit(pos)) {
      tree_[pos] = f_(tree_[pos], z);
    }
  }
  Monoid
  get(int r) const {
    Monoid res = ef_();
    for (++r; r > 0; r -= lowbit(r)) { res = f_(tree_[r], res); }
    return res;
  }
private:
  static constexpr int
  lowbit(int x) {
    return x & -x;
  }
  int size_;
  int lg2_;
  std::vector<Monoid> tree_;
  Operation f_;
  Identity ef_;
};
template <typename Operation, typename Identity>
fenwick_tree(int, const Operation &, const Identity &)
    -> fenwick_tree<std::invoke_result_t<Identity>, Operation, Identity>;
}
namespace algo {
template <std::semiregular Monoid, detail::binary_op<Monoid> Operation,
          detail::callable<Monoid> Identity>
class segtree {
public:
  segtree() = default;
  segtree(int n, const Operation &f, const Identity &e)
      : n_(n),
        lg2_(detail::log2_ceil(n)),
        size_(1 << lg2_),
        tree_(size_ << 1, e()),
        f_(f),
        ef_(e) {}
  segtree(int n, const Monoid &init, const Operation &f, const Identity &e)
      : n_(n),
        lg2_(detail::log2_ceil(n_)),
        size_(1 << lg2_),
        tree_(size_ << 1, init),
        f_(f),
        ef_(e) {
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  segtree(const std::vector<Monoid> &vec, const Operation &f, const Identity &e)
      : segtree(vec.size(), f, e) {
    std::copy(vec.begin(), vec.end(), tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> InputIterator>
  segtree(InputIterator first, InputIterator last, const Operation &f,
          const Identity &e)
      : segtree(std::distance(first, last), f, e) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <
      std::input_iterator InputIterator,
      detail::callable<Monoid, std::iter_value_t<InputIterator>> Generator>
  segtree(InputIterator first, InputIterator last, const Operation &f,
          const Identity &e, const Generator &gen)
      : segtree(std::distance(first, last), f, e) {
    std::transform(first, last, tree_.begin() + size_, gen);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  void
  set(int pos, const Monoid &new_val) {
    tree_[pos |= size_] = new_val;
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  Monoid
  get(int pos) const {
    return tree_[pos | size_];
  }
  void
  apply(int pos, const Monoid &z) {
    pos |= size_;
    tree_[pos] = f_(tree_[pos], z);
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  Monoid
  query(int l, int r) const {
    Monoid resl = ef_(), resr = ef_();
    for (l += size_, r += size_; l < r; l >>= 1, r >>= 1) {
      if (l & 0x01) { resl = f_(resl, tree_[l++]); }
      if (r & 0x01) { resr = f_(tree_[--r], resr); }
    }
    return f_(resl, resr);
  }
  Monoid
  query() const {
    return tree_[1];
  }
  template <std::predicate<Monoid> Predicate>
  int
  bisect_right(int l, const Predicate &pred) const {
    if (detail::likely(l < n_)) {
      l += size_;
      Monoid cur = ef_();
      do {
        l >>= detail::count_tz(l);
        if (!pred(f_(cur, tree_[l]))) {
          while (l < size_) {
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
  bisect_left(int r, const Predicate &pred) const {
    if (detail::likely(r > 0)) {
      r += size_;
      Monoid cur = ef_();
      do {
        r >>= detail::count_tz(r);
        r ^= (r > 1);
        if (!pred(f_(tree_[r], cur))) {
          while (r < size_) {
            r <<= 1;
            r |= 1;
            if (const Monoid tmp = f_(tree_[r], cur); pred(tmp)) {
              cur = tmp, --r;
            }
          }
          return (r + 1) - size_;
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
  int n_, lg2_, size_;
  std::vector<Monoid> tree_;
  Operation f_;
  Identity ef_;
};
template <typename Operation, typename Identity>
segtree(int, const Operation &, const Identity &)
    -> segtree<std::invoke_result_t<Identity>, Operation, Identity>;
template <typename Monoid, typename Operation, typename Identity>
segtree(int, const Monoid &, const Operation &, const Identity &)
    -> segtree<Monoid, Operation, Identity>;
template <typename Monoid, typename Operation, typename Identity>
segtree(const std::vector<Monoid> &, const Operation &, const Identity &)
    -> segtree<Monoid, Operation, Identity>;
template <typename InputIterator, typename Operation, typename Identity>
segtree(InputIterator, InputIterator, const Operation &, const Identity &)
    -> segtree<std::iter_value_t<InputIterator>, Operation, Identity>;
template <typename InputIterator, typename Operation, typename Identity,
          typename Generator>
segtree(InputIterator, InputIterator, const Operation &, const Identity &,
        const Generator &)
    -> segtree<
        std::invoke_result_t<Generator, std::iter_value_t<InputIterator>>,
        Operation, Identity>;
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
using std::to_string;
namespace ranges = std::ranges;
namespace views = std::views;
template <typename Tp, typename Fn>
using ordered_set = __gnu_pbds::tree<Tp,
__gnu_pbds::null_type, Fn, __gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>;
using uint = unsigned int;
using wint = int64_t;
template <typename KeyType, typename ValueType>
using umap = std::unordered_map<KeyType, ValueType>;
template <typename ValueType> using uset = std::unordered_set<ValueType>;
template <typename Tp, typename Fn = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Fn>;
template <typename Tp, typename Fn = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Fn>;
#pragma endregion alias
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MAXN 200001
#define MULTI 0
inline void solve() noexcept {
  int n;cin>>n;
  using node=struct{
    int a,b,c,id;
  };
  vector<node>d;
  for(int i=0,j=0;i<n;++i){
    int a;cin>>a;
    if(i+1-a>=0){d.emplace_back(i+1,a,i+1-a,j++);}
  }
  const int m=ssize(d);
  sort(d.begin(),d.end(),[](node x,node y){return x.c==y.c?x.b==y.b?x.a<y.a:x.b<y.b:x.c<y.c;});
  vector<int>dp(m,1);
  algo::segtree sg(n+1,[](int x,int y){return max(x,y);},[]{return 0;});
  algo::rec_lambda([&](auto cdq,int l,int r)->void{
    if(r-l>1){
      const int mid=l+r>>1;
      cdq(l,mid);
      vector<node>tmp(d.begin()+mid,d.begin()+r);
      sort(tmp.begin(),tmp.end(),[](node x,node y){return x.b==y.b?x.a<y.a:x.b<y.b;});
      for(int a=l,b=mid;b<r;++b){
        for(;a<mid&&d[a].b<tmp[b-mid].b;++a){
          sg.apply(d[a].a,dp[d[a].id]);
        }
        dp[tmp[b-mid].id]=max(dp[tmp[b-mid].id],sg.query(0,tmp[b-mid].a)+1);
      }
      for(int a=l;a<mid;++a){
        sg.set(d[a].a,0);
      }
      cdq(mid,r);
      inplace_merge(d.begin()+l,d.begin()+mid,d.begin()+r,[](node x,node y){return x.b==y.b?x.a<y.a:x.b<y.b;});
    }
  })(0,m);
  int ans=0;
  for(int i=0;i<m;++i){
    ans=max(ans,dp[i]);
  }
  cout<<ans<<'\n';
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  solve();
  return 0;
}
