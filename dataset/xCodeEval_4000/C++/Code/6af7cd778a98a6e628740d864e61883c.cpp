#pragma GCC target("abm,movbe,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("f16c,fma,avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("tree-vectorize")
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
template <detail::less_than_comparable Tp>
std::vector<int>
argsort(const std::vector<Tp> &vec) {
  std::vector<int> ind(vec.size());
  iota(ind.begin(), ind.end(), 0);
  sort(ind.begin(), ind.end(),
       [&](int a, int b) -> bool { return vec[a] < vec[b]; });
  return ind;
}
template <detail::less_than_comparable Tp>
std::vector<Tp>
sort_unique_erase(std::vector<Tp> out) {
  sort(out.begin(), out.end());
  out.erase(unique(out.begin(), out.end()), out.end());
  return out;
}
template <detail::less_than_comparable Tp>
int
argmin(const std::vector<Tp> &vec) {
  int j = -1;
  for (int i = 0; i < ssize(vec); ++i) {
    if (detail::unlikely(j == -1 || vec[j] < vec[i])) { j = i; }
  }
  return j;
}
template <detail::less_than_comparable Tp>
int
argmax(const std::vector<Tp> &vec) {
  int j = -1;
  for (int i = 0; i < ssize(vec); ++i) {
    if (detail::unlikely(j == -1 || vec[j] < vec[i])) { j = i; }
  }
  return j;
}
template <detail::integer Tp, std::predicate<Tp> Predicate>
constexpr Tp
bisect(Tp low, Tp high, const Predicate &pred) {
  assert(low <= high);
  while (low < high) {
    const Tp mid = low + high >> 1;
    pred(mid) ? low = mid + 1 : high = mid;
  }
  return low;
}
template <detail::less_than_comparable Tp>
int
lower_bound(const std::vector<Tp> &vec, const Tp &x) {
  return distance(vec.begin(), lower_bound(vec.begin(), vec.end(), x));
}
template <detail::less_than_comparable Tp>
int
upper_bound(const std::vector<Tp> &vec, const Tp &x) {
  return distance(vec.begin(), upper_bound(vec.begin(), vec.end(), x));
}
std::vector<int>
inverse(const std::vector<int> &perm) {
  std::vector<int> out(perm.size());
  for (int i = 0; i < ssize(perm); ++i) { out[perm[i]] = i; }
  return out;
}
template <std::semiregular Tp>
std::vector<Tp>
permute(const std::vector<Tp> &vec, const std::vector<int> &perm) {
  assert(vec.size() == perm.size());
  std::vector<Tp> out(vec.size());
  for (int i = 0; i < ssize(vec); ++i) { out[perm[i]] = vec[i]; }
  return out;
}
template <detail::less_than_comparable Tp>
std::vector<int>
compress(const std::vector<Tp> &vec) {
  std::vector<int> ind = argsort(vec);
  std::vector<int> out(vec.size());
  for (int i = 0, c = 0; i < ssize(vec); ++c) {
    int j = i;
    do {
      out[ind[j]] = c;
    } while (++j < ssize(vec) && (vec[ind[j]] == vec[ind[i]]));
    i = j;
  }
  return out;
}
}
namespace algo {
class dsu {
public:
  dsu() : n_(0), num_comp_(0), fa_{} {}
  explicit dsu(int n) : n_(n), num_comp_(n), fa_(n, -1) {}
  int
  merge(int a, int b) {
    assert(0 <= a && a < n_);
    assert(0 <= b && b < n_);
    int sa = leader(a), sb = leader(b);
    if (sa != sb) {
      num_comp_--;
      if (-fa_[sa] < -fa_[sb]) { std::swap(sa, sb); }
      fa_[sa] += fa_[sb];
      fa_[sb] = sa;
    }
    return sa;
  }
  int
  leader(int a) {
    assert(0 <= a && a < n_);
    if (fa_[a] >= 0) {
      fa_[a] = leader(fa_[a]);
      return fa_[a];
    }
    return a;
  }
  int
  size(int a) {
    assert(0 <= a && a < n_);
    return -fa_[leader(a)];
  }
  bool
  is_same(int a, int b) {
    assert(0 <= a && a < n_);
    assert(0 <= b && b < n_);
    return leader(a) == leader(b);
  }
  int
  num_components() const {
    return num_comp_;
  }
private:
  int n_, num_comp_;
  std::vector<int> fa_;
};
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
template <integer Tp>
constexpr Tp
sqrt(Tp n) {
  if (n == 0) { return 0; }
  if (n == 1) { return 1; }
  Tp ans = 0;
  for (int i = log2_floor(n) - 1; i >= 0; --i) {
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
div_ceil(Tp x, Tp y) {
  if constexpr (std::is_unsigned_v<Tp>) {
    return x / y + (x % y != 0);
  } else {
    return x / y + (x % y != 0 && (x ^ y) >= 0);
  }
}
template <std::integral Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, int>>
pow_m1(Tp n) {
  return -(n & 1) | 1;
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
div_ceil(Tp x, Tp y) {
  assert(y != 0);
  return detail::div_ceil(x, y);
}
template <detail::integer Tp>
constexpr std::make_signed_t<Tp>
pow_m1(Tp n) {
  return detail::pow_m1(n);
}
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
#define MAXN 505
#define MULTI 0
namespace {
}
void solve() noexcept {
  int n,m;cin>>n>>m;
  struct edge{
    int u,v,w;
  };
  vector<edge>es(m);
  for(int i=0;i<m;++i){
    int u,v,w;cin>>u>>v>>w;
    --u,--v,w*=2;
    es[i]={u,v,w};
  }
  vector<int>bs;
  bs.reserve(m*(m+1)>>1);
  for(int i=0;i<m;++i){
    for(int j=0;j<i;++j){
      bs.emplace_back((es[i].w+es[j].w)>>1);
    }
  }
  bs.emplace_back(0);
  bs=algo::sort_unique_erase(bs);
  auto get_set=[&](int x){
    vector tmp=es;
    sort(tmp.begin(),tmp.end(),[x](auto e1,auto e2){
      int wa=algo::abs(e1.w-x);
      int wb=algo::abs(e2.w-x);
      if(wa!=wb){return wa<wb;}
      return e1.w>e2.w;
    });
    vector<int>best(n-1);
    int c=0;
    algo::dsu uf(n);
    for(const auto&[u,v,w]:tmp){
      if(!uf.is_same(u,v)){
        best[c++]=w;
        uf.merge(u,v);
      }
    }
    sort(best.begin(),best.end());
    return best;
  };
  const int sz=ssize(bs);
  vector<vector<int>>qs(sz);
  vector<vector<wint>>pref(sz,vector<wint>(n));
  debug(bs);
  for(int i=0;i<sz;++i){
    qs[i]=get_set(bs[i]);
    for(int j=1;j<n;++j){
      pref[i][j]=pref[i][j-1]+qs[i][j-1];
    }
  }
  auto get_ans=[&](wint x){
    int p=upper_bound(bs.begin(),bs.end(),x)-bs.begin()-1;
    int c=lower_bound(qs[p].begin(),qs[p].end(),x)-qs[p].begin();
    wint l=pref[p][c];
    wint r=pref[p][n-1]-l;
    wint res=r-(n-1-c)*x+(c*x-l);
    return (r-(n-1-c)*x)+(c*x-l);
  };
  int p,k,a,b,c;cin>>p>>k>>a>>b>>c;
  wint ans=0,last=0;
  for(int i=0;i<p;++i){
    cin>>last;
    wint res=get_ans(2*last);
    res/=2;
    ans^=(res);
  }
  for(int i=p;i<k;++i){
    last=(last*a+b)%c;
    wint res=get_ans(2*last);
    res/=2;
    ans^=(res);
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
