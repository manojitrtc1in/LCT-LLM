










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
concept qword_fittable = sizeof(Tp) <= 8UL;
template <typename Tp>
concept dword_fittable = qword_fittable<Tp> && sizeof(Tp) <= 4UL;
template <typename Tp>
concept word_fittable = dword_fittable<Tp> && sizeof(Tp) <= 2UL;
template <typename Tp>
concept byte_fittable = word_fittable<Tp> && sizeof(Tp) == 1UL;
template <typename From, typename To>
concept sign_compatible_with = integer<From> &&
    ((std::is_signed_v<From> && std::is_signed_v<To>) ||
     (std::is_unsigned_v<From> && std::is_unsigned_v<To>));
template <typename Tp>
struct imul_result;
template <>
struct imul_result<char> {
  using type = int16_t;
};
template <>
struct imul_result<unsigned char> {
  using type = uint16_t;
};
template <>
struct imul_result<short> {
  using type = int32_t;
};
template <>
struct imul_result<int> {
  using type = int64_t;
};
template <>
struct imul_result<unsigned int> {
  using type = uint64_t;
};
template <>
struct imul_result<long> {
  using type = __int128_t;
};
template <>
struct imul_result<unsigned long> {
  using type = __uint128_t;
};
template <>
struct imul_result<long long> {
  using type = __int128_t;
};
template <>
struct imul_result<unsigned long long> {
  using type = __uint128_t;
};
template <typename Tp>
using imul_result_t = typename imul_result<Tp>::type;
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
}
namespace algo::detail {
template <dword_fittable Tp>
constexpr int
id5(Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable Tp>
constexpr int
id5(Tp n) {
  return __builtin_clzll(n);
}
template <dword_fittable Tp>
constexpr int
id6(Tp n) {
  return __builtin_ctz(n);
}
template <qword_fittable Tp>
constexpr int
id6(Tp n) {
  return __builtin_ctzll(n);
}
template <dword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 32 - id5(n);
}
template <qword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 64 - id5(n);
}
template <dword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return std::make_unsigned_t<Tp>(1) << (31 - id5(n));
}
template <qword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return std::make_unsigned_t<Tp>(1) << (63 - id5(n));
}
template <typename Tp>
constexpr Tp
id0(Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return bit_floor(n - 1) << 1;
}
template <dword_fittable Tp>
constexpr int
id1(Tp n) {
  return 31 - id5(n);
}
template <qword_fittable Tp>
constexpr int
id1(Tp n) {
  return 63 - id5(n);
}
template <typename Tp>
constexpr int
id2(Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return id1(n - 1) + 1;
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
namespace algo {
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
id1(Tp n) {
  return detail::id1(n);
}
template <detail::integer Tp>
constexpr int
id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}
namespace dbg {

}
namespace algo {

  do { \
    if (!(expr)) __builtin_unreachable(); \
  } while (false)


}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (unlikely(n <= 1)) { return n; }
  Tp ans = 0;
  for (int i = id1(n) - 1; i >= 0; --i) {
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
  return y >= 0 ? (x + y - 1) / y : -(-x / y);
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
  assume(n >= 0);
  assume(c > 0);
  assume(a >= 0);
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
template <typename Tp, std::predicate<Tp, Tp> Compare = std::less<Tp>>
std::vector<int>
argsort(const std::vector<Tp> &vec, const Compare &comp = {}) {
  std::vector<int> ind(vec.size());
  iota(ind.begin(), ind.end(), 0);
  sort(ind.begin(), ind.end(),
       [&](int a, int b) -> bool { return comp(vec[a], vec[b]); });
  return ind;
}
template <typename Tp, std::predicate<Tp, Tp> Compare = std::less<Tp>>
std::vector<Tp>
id4(std::vector<Tp> out, const Compare &comp = {}) {
  sort(out.begin(), out.end(), comp);
  out.erase(unique(out.begin(), out.end()), out.end());
  return std::move(out);
}
std::vector<int>
inverse(const std::vector<int> &perm) {
  std::vector<int> out(perm.size());
  for (int i = 0; i < ssize(perm); ++i) { out[perm[i]] = i; }
  return out;
}
template <std::semiregular Tp>
std::vector<Tp>
id7(const std::vector<Tp> &vec, const std::vector<int> &perm) {
  assert(vec.size() == perm.size());
  std::vector<Tp> out(vec.size());
  for (int i = 0; i < ssize(vec); ++i) { out[perm[i]] = vec[i]; }
  return out;
}
template <std::semiregular Tp>
std::vector<Tp>
id3(const std::vector<Tp> &vec, const std::vector<int> &perm) {
  assert(vec.size() == perm.size());
  std::vector<Tp> out(vec.size());
  for (int i = 0; i < ssize(vec); ++i) { out[i] = vec[perm[i]]; }
  return out;
}
template <std::semiregular Tp, std::predicate<Tp, Tp> Compare = std::less<Tp>>
std::vector<int>
compress(const std::vector<Tp> &vec, const Compare &comp = {}) {
  std::vector<int> ind = argsort(vec, comp);
  std::vector<int> out(vec.size());
  for (int i = 0, c = 0; i < ssize(vec); ++c) {
    int j = i;
    do {
      out[ind[j]] = c;
    } while (++j < ssize(vec) && !comp(vec[ind[j]], vec[ind[i]]) &&
             !comp(vec[ind[i]], vec[ind[j]]));
    i = j;
  }
  return out;
}
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
using std::tie;
using std::lcm;
using std::max;
using std::min;
using std::move;
using std::swap;
using std::to_string;
namespace ranges = std::ranges;
namespace views = std::views;
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
  int n;cin>>n;
  vector<int>psi(n),an(n);
  set<int>st;
  for(int i=0;i<n;++i){
    cin>>psi[i];
    psi[i]--;
    st.insert(psi[i]);
  }
  vector<int>sv;
  int mx=0;
  for(int i=0;i<n;++i){
    cin>>an[i];
    mx=max(mx,an[i]);
    --an[i];
    if(an[i]<n){sv.emplace_back(an[i]);}
  }
  const int k=ssize(st);
  int t=(mx-n)/(n-k);
  for(int i=0;i<n;++i){
    st.insert(i);
  }
  for(auto v:sv){
    st.erase(v);
  }
  debug(t);
  vector<int>f(n);
  iota(f.begin(),f.end(),0);
  for(int i=t!=0?algo::id1(t):-1;i>=0;--i){
    debug(f);
    f=algo::id3(f,f);
    if((t>>i)&1){f=algo::id3(psi,f);}
  }
  debug(f);
  vector<char>vis(n);
  vector<int>ans(n);
  for(int i=0;i<n;++i){
    if(!vis[f[i]]){
      ans[i]=an[f[i]];
      vis[f[i]]=true;
    }else{
      auto lb=st.lower_bound(an[f[i]]);
      assert(lb!=st.end());
      ans[i]=*lb;
      st.erase(lb);
    }
  }
  for(int i=0;i<n;++i){
    cout<<ans[i]+1<<" \n"[i+1==n];
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
