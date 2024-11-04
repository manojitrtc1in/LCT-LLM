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
template <detail::integer Integral,
          int BitSize = std::numeric_limits<Integral>::digits>
class binary_trie {
  struct trie_node {
    int size_;
    trie_node* ch_[2];
  };
  struct trie_node_allocator {
    using node_type = trie_node;
    using node_pointer = trie_node*;
    using const_node_pointer = const trie_node*;
    using pool_resource_type = std::pmr::monotonic_buffer_resource;
    node_pointer
    allocate() noexcept {
      void* mem = pool_.allocate(sizeof(node_type), alignof(node_type));
      return ::new (mem) node_type{};
    }
  private:
    pool_resource_type pool_;
  };
  using node_type = typename trie_node_allocator::node_type;
  using node_pointer = typename trie_node_allocator::node_pointer;
  using const_node_pointer = typename trie_node_allocator::const_node_pointer;
  using node_allocator_type = trie_node_allocator;
public:
  binary_trie() : pool_{}, root_(pool_.allocate()) {}
  int
  insert(Integral x, int n = 1) noexcept {
    if (n == 0) { return 0; }
    node_pointer cur = root_;
    cur->size_ += n;
    for (int i = BitSize - 1; i >= 0; --i) {
      bool b = (x >> i) & 0x01;
      if (!cur->ch_[b]) { cur->ch_[b] = pool_.allocate(); }
      cur = cur->ch_[b];
      cur->size_ += n;
    }
    return cur->size_;
  }
  constexpr int
  erase(Integral x, int n = 1) {
    std::array<node_pointer, BitSize + 1> stk{};
    stk[BitSize] = root_;
    for (int i = BitSize - 1; i >= 0; --i) {
      const bool b = (x >> i) & 0x01;
      if (!stk[i + 1]->ch_[b]) { return 0; }
      stk[i] = stk[i + 1]->ch_[b];
    }
    const int removed = std::min(stk[0]->size_, n);
    for (int i = 0; i <= BitSize; ++i) { stk[i]->size_ -= removed; }
    return removed;
  }
  constexpr int
  count(Integral x) const {
    return prefix_count(x, 0);
  }
  constexpr bool
  contains(Integral x) const {
    return count(x);
  }
  constexpr int
  prefix_count(Integral x, int l) const {
    const_node_pointer cur = root_;
    for (int i = BitSize - 1; i >= l; --i) {
      const bool b = (x >> i) & 0x01;
      if (!cur->ch_[b]) { return 0; }
      cur = cur->ch_[b];
    }
    return cur->size_;
  }
  constexpr Integral
  xor_max(Integral x) const {
    Integral res = Integral(0);
    const_node_pointer cur = root_;
    for (int i = BitSize - 1; i >= 0; --i) {
      bool b = (x >> i) & 0x01;
      if (cur->ch_[!b]) { res |= Integral(1) << i, b = !b; }
      cur = cur->ch_[b];
    }
    return res;
  }
  constexpr Integral
  xor_max(Integral x, int k) const {
    Integral res = Integral(0);
    const_node_pointer cur = root_;
    int remain = k + 1;
    for (int i = BitSize - 1; i >= 0; --i) {
      const bool b = (x >> i) & 0x01;
      const int rgt = cur->ch_[!b] ? cur->ch_[!b]->size_ : 0;
      if (rgt >= remain) {
        res |= Integral(1) << i;
        cur = cur->ch_[!b];
      } else {
        remain -= rgt;
        cur = cur->ch_[b];
      }
    }
    return res;
  }
  constexpr Integral
  xor_min(Integral x) const {
    Integral res = Integral(0);
    const_node_pointer cur = root_;
    for (int i = BitSize - 1; i >= 0; --i) {
      bool b = (x >> i) & 0x01;
      if (!cur->ch_[b]) { res |= Integral(1) << i, b = !b; }
      cur = cur->ch_[b];
    }
    return res;
  }
  constexpr Integral
  xor_min(Integral x, int k) const {
    Integral res = Integral(0);
    const_node_pointer cur = root_;
    int remain = k + 1;
    for (int i = BitSize - 1; i >= 0; --i) {
      bool b = (x >> i) & 0x01;
      const int lft = cur->ch_[b] ? cur->ch_[b]->size_ : 0;
      if (lft < remain) {
        res |= Integral(1) << i;
        remain -= lft;
        b = !b;
      }
      cur = cur->ch_[b];
    }
    return res;
  }
  constexpr int
  xor_count_lt(Integral x, Integral z) const {
    int res = 0;
    const_node_pointer cur = root_;
    for (int i = BitSize - 1; i >= 0; --i) {
      const bool b = (x >> i) & 0x01;
      const bool v = (z >> i) & 0x01;
      if (b != (v ^ b) && cur->ch_[b]) { res += cur->ch_[b]->size_; }
      if (!cur->ch_[v ^ b]) { break; }
      cur = cur->ch_[v ^ b];
    }
    return res;
  }
  constexpr int
  xor_count_leq(Integral x, Integral z) const {
    return xor_count_lt(x, z) + count(x ^ z);
  }
  constexpr int
  xor_count_gt(Integral x, Integral z) const {
    return size() - xor_count_leq(x, z);
  }
  constexpr int
  xor_count_geq(Integral x, Integral z) const {
    return size() - xor_count_lt(x, z);
  }
  constexpr Integral
  max() const {
    return xor_max(0);
  }
  constexpr Integral
  min() const {
    return xor_min(0);
  }
  constexpr int
  count_lt(Integral x) const {
    return xor_count_lt(0, x);
  }
  constexpr int
  count_leq(Integral x) const {
    return xor_count_leq(0, x);
  }
  constexpr int
  count_gt(Integral x) const {
    return xor_count_gt(0, x);
  }
  constexpr int
  count_geq(Integral x) const {
    return xor_count_geq(0, x);
  }
  constexpr int
  size() const {
    return root_->size_;
  }
  constexpr bool
  empty() const {
    return size() == 0;
  }
private:
  node_allocator_type pool_;
  node_pointer root_;
};
}
namespace algo {
template <detail::integer Tp>
constexpr int
countl_zero(Tp n) {
  return detail::count_lz(n);
}
template <detail::integer Tp>
constexpr int
countl_one(Tp n) {
  return detail::count_lz(~n);
}
template <detail::integer Tp>
constexpr int
countr_zero(Tp n) {
  return detail::count_tz(n);
}
template <detail::integer Tp>
constexpr int
countr_one(Tp n) {
  return detail::count_tz(~n & (n + 1));
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
bit_ceil(Tp n) {
  return detail::bit_ceil(n);
}
template <detail::integer Tp>
constexpr int
log2_floor(Tp n) {
  return detail::log2_floor(n);
}
template <detail::integer Tp>
constexpr int
log2_ceil(Tp n) {
  return detail::log2_ceil(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
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
  int n,k;cin>>n>>k;
  if(k==0){
    cout<<n<<'\n';
    for(int i=0;i<n;++i){int x;cin>>x;cout<<i+1<<" \n"[i+1==n];}
    return;
  }
  int msb=algo::log2_floor(k);
  vector<int>arr(n+1);
  map<int,vector<int>>pref;
  for(int i=1;i<=n;++i){
    cin>>arr[i];
    pref[arr[i]>>msb].emplace_back(i);
  }
  vector<int>ans;
  set<int>vis;
  for(const auto&[p,v1]:pref){
    if(!vis.contains(p)){
      vis.insert(p);
      if(!pref.contains(p^1)){
        ans.emplace_back(v1.front());
        continue;
      }
      vis.insert(p^1);
      vector v2=pref[p^1];
      algo::binary_trie<int,30>trie;
      for(const auto&x:v2){trie.insert(arr[x]);}
      int val=-1;
      for(const auto&x:v1){
        int q=trie.xor_max(arr[x]);
        if(q>=k){
          ans.emplace_back(x);
          val=q^arr[x];
          break;
        }
      }
      if(val!=-1){
        for(const auto&x:v2){
          if(arr[x]==val){
            ans.emplace_back(x);
            break;
          }
        }
      }else{
        ans.emplace_back(v1.front());
      }
    }
  }
  if(ans.size()<2){cout<<-1<<'\n';}
  else{cout<<ans.size()<<'\n';for(const auto&v:ans){cout<<v<<' ';}cout<<'\n';}
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  solve();
  return 0;
}
