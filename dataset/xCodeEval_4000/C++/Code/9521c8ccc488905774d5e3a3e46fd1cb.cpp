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
    assert(0 <= pos && pos < size());
    for (++pos; pos <= size_; pos += lowbit(pos)) {
      tree_[pos] = f_(tree_[pos], z);
    }
  }
  Monoid
  get(int r) const {
    assert(-1 <= r && r < size());
    Monoid res = ef_();
    for (++r; r > 0; r -= lowbit(r)) { res = f_(tree_[r], res); }
    return res;
  }
  int
  size() const {
    return size_;
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
template <integer Tp>
constexpr std::make_signed_t<Tp>
pow_m1(Tp n) {
  return -(n & 1) | 1;
}
}
}
namespace algo {
namespace detail {
template <integer Tp>
constexpr Tp
assumed_mulmod(Tp x, Tp y, Tp m) {
  assume(0 <= x && x < m);
  assume(0 <= y && y < m);
  return static_cast<safe_mul_t<std::make_unsigned_t<Tp>>>(x) * y % m;
}
template <multipliable Tp, integer Up>
constexpr Tp
binpow(const Tp &a, Up b) {
  Tp res(1), mul = a;
  std::make_unsigned_t<Up> pw = b;
  while (pw) {
    if (pw & 0x01) { res *= mul; }
    mul *= mul;
    pw >>= 1;
  }
  return res;
}
template <multipliable T1, constructible<T1> T2, integer Up>
constexpr T1
binpow(const T1 &a, Up b, const T2 &init) {
  T1 res(init), mul = a;
  std::make_unsigned_t<Up> pw = b;
  while (pw) {
    if (pw & 0x01) { res *= mul; }
    mul *= mul;
    pw >>= 1;
  }
  return res;
}
template <integer Tp>
constexpr Tp
euler_phi(Tp n) {
  typedef safe_mul_t<Tp> wide_t;
  assume(1 <= n);
  Tp cur_n = n, ans = n;
  if (cur_n % 2 == 0) {
    ans -= ans / 2;
    do { cur_n /= 2; } while (cur_n % 2 == 0);
  }
  if (cur_n % 3 == 0) {
    ans -= ans / 3;
    do { cur_n /= 3; } while (cur_n % 3 == 0);
  }
  for (Tp i = 5, c = 2; i * static_cast<wide_t>(i) <= cur_n; i += c, c ^= 6) {
    if (cur_n % i == 0) {
      ans -= ans / i;
      do { cur_n /= i; } while (cur_n % i == 0);
    }
  }
  if (cur_n > 1) { ans -= ans / cur_n; }
  return ans;
}
template <integer Tp>
constexpr std::make_signed_t<Tp>
mobius(Tp n) {
  typedef safe_mul_t<Tp> wide_t;
  assume(1 <= n);
  Tp cur_n = n;
  int cnt = 0;
  if (cur_n == 1) { return 1; }
  if (cur_n % 2 == 0) {
    if ((cur_n /= 2) % 2 == 0) { return 0; }
    cnt = cnt + 1;
  }
  if (cur_n % 3 == 0) {
    if ((cur_n /= 3) % 3 == 0) { return 0; }
    cnt = cnt + 1;
  }
  for (Tp i = 5, c = 2; i * static_cast<wide_t>(i) <= cur_n; i += c, c ^= 6) {
    if (cur_n % i == 0) {
      if ((cur_n /= i) % i == 0) { return 0; }
      cnt = cnt + 1;
    }
  }
  if (cur_n > 1) { cnt = cnt + 1; }
  return pow_m1(cnt);
}
template <signed_integer Tp>
constexpr std::pair<Tp, Tp>
euclidean_extended(Tp a, Tp b) {
  Tp x0 = 1, y0 = 0, x1 = 0, y1 = 1, a0 = a, b0 = b;
  while (b0) {
    Tp q = a0 / b0, tp = x0;
    x0 = x1, x1 = tp - q * x1, tp = y0, y0 = y1, y1 = tp - q * y1, tp = a0,
    a0 = b0, b0 = tp - q * b0;
  }
  if (a0 < 0) { x0 = -x0, a0 = -a0; }
  return std::make_pair(x0, a0);
}
template <integer Tp, integer Up>
constexpr Tp
binpow_mod(Tp a, Up b, Tp m) {
  Tp ans = 1, mul = a;
  const Tp mod = m;
  std::make_unsigned_t<Up> pw = b;
  if ((mul %= mod) < 0) mul += mod;
  while (pw) {
    if (pw & 0x01) { ans = assumed_mulmod(ans, mul, mod); }
    mul = assumed_mulmod(mul, mul, mod);
    pw >>= 1;
  }
  return ans;
}
}
}
namespace algo {
namespace detail {
template <dword_fittable Tp>
constexpr bool
prime_test(Tp n) {
  if (n <= 1) { return false; }
  if (n == 2 || n == 3 || n == 5 || n == 7) { return true; }
  const int s = count_tz(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr Tp primes[] = {2, 3, 5, 7};
  for (const Tp p : primes) {
    Tp x = binpow_mod(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = assumed_mulmod(x, x, n);
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
template <qword_fittable Tp>
constexpr bool
prime_test(Tp n) {
  if (n <= 1) { return false; }
  if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 ||
      n == 19 || n == 23 || n == 29 || n == 31 || n == 37) {
    return true;
  }
  const int s = count_tz(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr Tp primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (const Tp p : primes) {
    Tp x = binpow_mod(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = assumed_mulmod(x, x, n);
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
template <integer Tp>
std::vector<std::tuple<Tp, Tp, Tp>>
quotients(Tp n) {
  std::vector<std::tuple<Tp, Tp, Tp>> ans{};
  for (Tp i = 1, j = 1; i <= n; i = j + 1) {
    const Tp q = n / i;
    j = n / q;
    ans.emplace_back(i, j, q);
  }
  return ans;
}
template <integer Tp>
std::vector<Tp>
euler_phi_n(Tp n) noexcept {
  assume(1 <= n);
  std::vector<Tp> phi(n + 1);
  iota(phi.begin(), phi.end(), 0);
  for (Tp i = 2; i <= n; i += 2) { phi[i] -= phi[i] / 2; }
  for (Tp i = 3; i <= n; i += 3) { phi[i] -= phi[i] / 3; }
  for (Tp i = 5, c = 2; i <= n; i += c, c ^= 6) {
    if (phi[i] == i) {
      for (Tp j = i; j <= n; j += i) { phi[j] -= phi[j] / i; }
    }
  }
  return phi;
}
template <integer Tp>
std::vector<std::make_signed_t<Tp>>
mobius_n(Tp n) noexcept {
  typedef std::make_signed_t<Tp> value_t;
  typedef safe_mul_t<Tp> wide_t;
  assume(1 <= n);
  std::vector<value_t> mu(n + 1, -1);
  std::vector<Tp> lp(n + 1, 0);
  std::vector<Tp> ps;
  ps.reserve(n >> log2_floor(n));
  mu[1] = 1;
  for (Tp i = 2; i <= n; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      ps.emplace_back(i);
    }
    for (const Tp p : ps | std::views::take_while([&](Tp p) {
                        return p <= lp[i] && p * static_cast<wide_t>(i) <= n;
                      })) {
      lp[i * p] = p;
      mu[i * p] = -mu[i] * (p != lp[i]);
    }
  }
  return mu;
}
}
}
namespace algo {
template <detail::multipliable Tp, detail::integer Up>
constexpr Tp
pow(const Tp &a, Up b) {
  assert(b >= 0);
  return detail::binpow(a, b);
}
template <detail::multipliable T1, detail::constructible<T1> T2,
          detail::integer Up>
constexpr T1
pow(const T1 &a, Up b, const T2 &init) {
  assert(b >= 0);
  return detail::binpow(a, b, init);
}
template <detail::signed_integer T1, detail::signed_integer T2,
          typename Tp = std::common_type_t<T1, T2>>
constexpr std::pair<Tp, Tp>
euclidean_extended(T1 a, T2 b) {
  return detail::euclidean_extended<Tp>(a, b);
}
template <detail::integer Tp>
constexpr Tp
euler_phi(Tp n) {
  assert(n > 0);
  return detail::euler_phi(n);
}
template <detail::integer Tp>
constexpr std::make_signed_t<Tp>
mobius(Tp n) {
  assert(n > 0);
  return detail::mobius(n);
}
template <detail::integer Tp>
std::vector<std::tuple<Tp, Tp, Tp>>
quotients(Tp n) {
  assert(n > 0);
  return detail::quotients(n);
}
template <detail::integer Tp>
std::vector<Tp>
euler_phi_n(Tp n) {
  assert(n > 0);
  return detail::euler_phi_n(n);
}
template <detail::integer Tp>
std::vector<std::make_signed_t<Tp>>
mobius_n(Tp n) {
  assert(n > 0);
  return detail::mobius_n(n);
}
template <detail::integer Tp>
constexpr bool
prime_test(Tp n) {
  return detail::prime_test(n);
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
#define MAXN 300002
#define MULTI 0
namespace {
}
void solve() noexcept {
  algo::fenwick_tree cnt(MAXN,[](int x,int y){return x+y;},[]{return 0;});
  algo::fenwick_tree flt(MAXN,[](wint x,wint y){return x+y;},[]{return wint(0);});
  int n;cin>>n;
  vector<int>arr(n+1);
  for(int i=1;i<=n;++i){cin>>arr[i];}
  wint pref=0;
  wint ans=0;
  for(int i=1;i<=n;++i){
    ans+=pref;
    ans+=(i-1)*1ll*arr[i];
    ans+=flt.get(arr[i]);
    pref+=arr[i];
    for(int x=arr[i];x<MAXN;x+=arr[i]){
      flt.apply(x,-arr[i]);
      int c=cnt.get(min(MAXN-2,x+arr[i]-1))-cnt.get(x-1);
      ans-=c*1ll*x;
    }
    cout<<ans<<" \n"[i==n];
    cnt.apply(arr[i],1);
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
