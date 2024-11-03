












namespace io {
template <typename _Tp>
void id11(const _Tp &val) noexcept {
  std::cout << val;
}
template <typename _Tp>
void id11(const std::vector<_Tp> &vec) noexcept {
  const int n = (int)vec.size();
  for (int i = 0; i < n; ++i) {
    if (i) std::cout << ' ';
    std::cout << vec[i];
  }
}
template <typename _First, typename _Second>
void id11(const std::pair<_First, _Second> &p) noexcept {
  std::cout << p.first << ' ' << p.second;
}
template <typename... _Args, std::size_t... Is>
void id12(const std::tuple<_Args...> &tup,
                 std::index_sequence<0, Is...>) {
  io::id11(std::get<0>(tup));
  ((std::cout << ' ', io::id11(std::get<Is>(tup))), ...);
}
template <typename... _Args>
void id11(const std::tuple<_Args...> &tup) noexcept {
  id12(tup, std::make_index_sequence<sizeof...(_Args)>{});
}
}
namespace dbg {
template <class T>
void view(const T &e) {
  std::cerr << e;
}
template <class T, class U>
void view(const std::pair<T, U> &p) {
  std::cerr << "(" << p.first << ", " << p.second << ")";
}
template <class T>
void view(const std::vector<T> &a) {
  std::cerr << "{ ";
  for (const auto &v : a) { std::cerr << v << ", "; }
  std::cerr << "\b\b }";
}
template <class T>
void view(const std::vector<std::vector<T>> &a) {
  std::cerr << "{\n";
  for (const auto &v : a) {
    std::cerr << "\t";
    view(v);
    std::cerr << "\n";
  }
  std::cerr << "}";
}
template <class T, class U>
void view(const std::vector<std::pair<T, U>> &a) {
  std::cerr << "{\n";
  for (const auto &p : a)
    std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
  std::cerr << "}";
}
template <class T, class U>
void view(const std::map<T, U> &m) {
  std::cerr << "{\n";
  for (const auto &p : m)
    std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
  std::cerr << "}";
}
template <class T>
void view(const std::set<T> &s) {
  std::cerr << "{ ";
  for (auto &v : s) {
    view(v);
    std::cerr << ", ";
  }
  std::cerr << "\b\b }";
}
}
template <typename _Head, typename... _Rest>
void print(const _Head &head, const _Rest &... rest) noexcept {
  io::id11(head);
  ((std::cout << ' ', io::id11(rest)), ...);
  std::cout << '\n';
}

  std::cerr << "Line " << __LINE__ << ":: " \
            << "\033[1;32m" << 
  dbg::view(x); \
  std::cerr << '\n';
namespace algo {
namespace base {
template <typename _Tp, typename = void>
struct is_multipliable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct is_multipliable<_Tp,
                       std::void_t<decltype(std::declval<_Tp &>() *=
                                            std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp, typename = void>
struct is_addable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct is_addable<_Tp, std::void_t<decltype(std::declval<_Tp &>() +=
                                            std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp>
constexpr bool id38 = is_multipliable<_Tp>::value;
template <typename _Tp>
constexpr bool id1 = is_addable<_Tp>::value;
template <typename _Tp>
constexpr bool id25 = std::id25<_Tp>;
template <typename _Tp>
constexpr bool id0 = std::id0<_Tp>;
template <typename _Tp, typename _U>
constexpr bool id14 = std::id14<_Tp, _U>;
template <typename _Fn>
struct function_traits : public function_traits<decltype(
                             &std::remove_reference_t<_Fn>::operator())> {};
template <typename _Fn, typename _Ret, typename... _Args>
struct function_traits<_Ret (_Fn::*)(_Args...) const> {
  static constexpr size_t arity = sizeof...(_Args);
  using result_type = _Ret;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<_Args...>>::type;
  };
};
template <typename _Ret, typename... _Args>
struct function_traits<_Ret (*)(_Args...)> {
  static constexpr size_t arity = sizeof...(_Args);
  using result_type = _Ret;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<_Args...>>::type;
  };
};
template <typename _Fn>
using invoke_result_t = typename function_traits<_Fn>::result_type;
template <typename _Tp, typename = void>
struct is_less_than_comparable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct is_less_than_comparable<
    _Tp, std::void_t<decltype(std::declval<const _Tp &>() <
                              std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp, typename = void>
struct is_greater_than_comparable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct is_greater_than_comparable<
    _Tp, std::void_t<decltype(std::declval<const _Tp &>() >
                              std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp>
constexpr bool id21 = is_less_than_comparable<_Tp>::value;
template <typename _Tp>
constexpr bool id16 =
    is_greater_than_comparable<_Tp>::value;
template <typename _Tp, typename = void>
struct is_equality_comparable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct is_equality_comparable<
    _Tp, std::void_t<decltype(std::declval<const _Tp &>() ==
                              std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp>
constexpr bool id35 = is_equality_comparable<_Tp>::value;
}
}
namespace algo {
namespace base {
template <typename _T>
constexpr _T id22(const _T &a, const _T &b) {
  return a < b ? b : a;
}
template <typename _T>
constexpr _T __mini(const _T &a, const _T &b) {
  return a < b ? a : b;
}
template <typename _T>
constexpr void __swap(_T &a, _T &b) {
  _T tp = a;
  a = b;
  b = tp;
}
template <typename _T>
constexpr void __swap(_T *a, _T *b) {
  _T tp = *a;
  *a = *b;
  *b = tp;
}
}
}
namespace algo {
namespace base {
constexpr long likely(bool x) noexcept { return __builtin_expect(x, 1); }
constexpr long unlikely(bool x) noexcept { return __builtin_expect(x, 0); }
constexpr void unreachable() noexcept { __builtin_unreachable(); }
constexpr void assume(bool x) noexcept {
  if (!x) __builtin_unreachable();
}
}
}
namespace algo {
template <typename _T,
          std::enable_if_t<base::id21<_T>, bool> = true>
constexpr _T max(const _T &a, const _T &b) {
  return base::id22(a, b);
}
template <typename _T,
          std::enable_if_t<base::id21<_T>, bool> = true>
constexpr _T min(const _T &a, const _T &b) {
  return base::__mini(a, b);
}
template <typename _T>
constexpr void swap(_T &a, _T &b) {
  base::__swap(a, b);
}
template <typename _T>
constexpr void swap(_T *a, _T *b) {
  base::__swap(a, b);
}
template <
    typename _InputIterator,
    typename _Value = typename std::iterator_traits<_InputIterator>::value_type,
    std::enable_if_t<base::id1<_Value>, bool> = true>
constexpr _Value sum(_InputIterator first, _InputIterator last,
                     const _Value &init = {}) {
  return std::accumulate(first, last, init);
};
template <typename _T,
          std::enable_if_t<base::id21<_T>, bool> = true>
std::vector<int> argsort(const std::vector<_T> &v) {
  std::vector<int> ind(v.size());
  std::iota(ind.begin(), ind.end(), 0);
  std::sort(ind.begin(), ind.end(),
            [&v](int a, int b) -> bool { return v[a] < v[b]; });
  return ind;
}
template <typename _T,
          std::enable_if_t<base::id21<_T>, bool> = true>
void id30(std::vector<_T> &vec) noexcept {
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}
template <typename _T,
          std::enable_if_t<base::id21<_T>, bool> = true>
int argmin(const std::vector<_T> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <typename _T,
          std::enable_if_t<base::id16<_T>, bool> = true>
int argmax(const std::vector<_T> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <typename _T, typename _Pred,
          std::enable_if_t<base::id25<_T>, bool> = true>
constexpr _T bisect(_T low, _T high, _Pred &&pred) {

  assert(low <= high);

  while (low < high) {
    _T mid = low + high >> 1;
    pred(mid) ? low = mid + 1 : high = mid;
  }
  return low;
}
template <typename _T,
          std::enable_if_t<base::id21<_T>, bool> = true>
int lower_bound(const std::vector<_T> &vec, const _T &x) {
  return (int)std::distance(vec.begin(),
                            std::lower_bound(vec.begin(), vec.end(), x));
}
template <typename _T,
          std::enable_if_t<base::id21<_T>, bool> = true>
int upper_bound(const std::vector<_T> &vec, const _T &x) {
  return (int)std::distance(vec.begin(),
                            std::upper_bound(vec.begin(), vec.end(), x));
}
void inverse(std::vector<int> &perm) {
  const int n = (int)perm.size();
  std::vector<int> out(n);
  for (int i = 0; i < n; ++i) { out[perm[i]] = i; }
  perm = std::move(out);
}
template <typename _T>
void permute(std::vector<_T> &vec, const std::vector<int> &perm) {
  std::vector<_T> out(vec.size());
  const int n = (int)vec.size();
  for (int i = 0; i < n; ++i) { out[perm[i]] = vec[i]; }
  vec = std::move(out);
}
template <typename _T,
          std::enable_if_t<base::id21<_T>, bool> = true>
std::vector<int> compress(const std::vector<_T> &v) {
  std::vector<int> p(v.size()), ans(v.size());
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(),
            [&v](int a, int b) -> bool { return v[a] < v[b]; });
  const int n = (int)p.size();
  for (int i = 0, k = 0; i < n; ++k) {
    int j = i;
    do {
      ans[p[j]] = k;
    } while (++j < n && !(v[p[j]] < v[p[i]]) && !(v[p[i]] < v[p[j]]));
    i = j;
  }
  return ans;
}
template <typename _T, std::enable_if_t<base::id25<_T>, bool> = true>
constexpr int id7(_T n) {
  return -(n & 1) | 1;
}
template <>
constexpr int id7<bool>(bool n) {
  return -(int)(n) | 1;
}
}
namespace algo {
namespace base {
template <typename _T>
constexpr _T id29(_T a, unsigned int b) {
  _T res(1);
  while (b) {
    if (b & 0x01) { res *= a; }
    a *= a;
    b >>= 1;
  }
  return res;
}
template <typename _T>
constexpr _T id29(_T a, unsigned int b, const _T &init) {
  _T res = init;
  while (b) {
    if (b & 0x01) { res *= a; }
    a *= a;
    b >>= 1;
  }
  return res;
}
constexpr int id28(int a, int b) {
  a = a < 0 ? -a : a;
  b = b < 0 ? -b : b;
  if (a == 0 || b == 0) { return a | b; }
  int az = __builtin_ctz(a);
  int bz = __builtin_ctz(b);
  const int shift = az < bz ? az : bz;
  b >>= bz;
  while (a != 0) {
    a >>= az;
    const int diff = b - a;
    az = __builtin_ctz(diff);
    b = a < b ? a : b;
    a = diff < 0 ? -diff : diff;
  }
  return b << shift;
}
constexpr long id28(long a, long b) {
  a = a < 0 ? -a : a;
  b = b < 0 ? -b : b;
  if (a == 0 || b == 0) { return a | b; }
  int az = __builtin_ctzl(a);
  int bz = __builtin_ctzl(b);
  const int shift = az < bz ? az : bz;
  b >>= bz;
  while (a != 0) {
    a >>= az;
    const long diff = b - a;
    az = __builtin_ctzl(diff);
    b = a < b ? a : b;
    a = diff < 0 ? -diff : diff;
  }
  return b << shift;
}
constexpr long long id28(long long a, long long b) {
  a = a < 0 ? -a : a;
  b = b < 0 ? -b : b;
  if (a == 0 || b == 0) { return a | b; }
  int az = __builtin_ctzll(a);
  int bz = __builtin_ctzll(b);
  const int shift = az < bz ? az : bz;
  b >>= bz;
  while (a != 0) {
    a >>= az;
    const long long diff = b - a;
    az = __builtin_ctzll(diff);
    b = a < b ? a : b;
    a = diff < 0 ? -diff : diff;
  }
  return b << shift;
}
constexpr int id17(int a, int b) { return a / id28(a, b) * b; }
constexpr long id17(long a, long b) { return a / id28(a, b) * b; }
constexpr long long id17(long long a, long long b) {
  return a / id28(a, b) * b;
}
template <typename _T>
constexpr _T id26(_T n) {
  _T ans = n;
  if (!(n & 0x01)) {
    ans >>= 1;
    do { n >>= 1; } while (!(n & 0x01));
  }
  for (_T i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      ans -= ans / i;
      do { n /= i; } while (n % i == 0);
    }
  }
  if (n > 1) { ans -= ans / n; }
  return ans;
}
template <typename _T>
constexpr _T id2(_T n) {
  if (n == 1) { return 1; }
  int cnt = 0;
  if (!(n & 0x01)) {
    n >>= 1;
    if (!(n & 0x01)) { return 0; }
    cnt++;
  }
  for (_T i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      n /= i;
      if (n % i == 0) { return 0; }
      cnt++;
    }
  }
  return (cnt & 0x01) ? -1 : 1;
}
template <typename _T>
constexpr std::pair<_T, _T> id15(_T a, _T b) {
  _T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    const _T q = a / b;
    _T tp = x0;
    x0 = x1, x1 = tp - q * x1, tp = y0, y0 = y1, y1 = tp - q * y1, tp = a,
    a = b, b = tp - q * b;
  }
  if (a < 0) x0 = -x0, a = -a;
  return std::make_pair(x0, a);
}
template <typename _T>
constexpr _T id32(_T a, _T b, const _T mod) {
  _T ans(1);
  a %= mod;
  if (a < 0) a += mod;
  while (b) {
    if (b & 0x01) { ans = ans * 1ll * a % mod; }
    a = a * 1ll * a % mod;
    b >>= 1;
  }
  return ans;
}
}
}
namespace algo {
namespace base {






constexpr int __sqrt(int n) {
  int p = 32 - __builtin_clz(n);
  int ans = p & 0x01;
  for (p >>= 1, p &= ~1u; p >= 0; --p) {
    ans <<= 1;
    if ((ans + 1) * 1ll * (ans + 1) <= (n >> (p << 1))) { ans |= 1; }
  }
  return ans;
}
constexpr long long __sqrt(long long n) {
  int p = 64 - __builtin_clzll(n);
  long long ans = p & 0x01;
  for (p >>= 1, p &= ~1u; p >= 0; --p) {
    ans <<= 1;
    if ((ans + 1) * (ans + 1) <= (n >> (p << 1))) { ans |= 1; }
  }
  return ans;
}
double cos(double x) noexcept {
  constexpr double tp = 1. / (2. * M_PI);
  x *= tp;
  x -= .25 + std::floor(x + .25);
  x *= 16. * (std::abs(x) - .5);
  x += .225 * x * (std::abs(x) - 1.);
  return x;
}
double sin(double x) noexcept { return cos(M_PI_2 - x); }
}
}
namespace algo {
namespace base {
constexpr int id37(int n) { return __builtin_clz(n); };
constexpr int id37(long long n) { return __builtin_clzll(n); };
constexpr int id3(int n) { return __builtin_ctz(n); };
constexpr int id3(long long n) { return __builtin_ctzll(n); }
constexpr int id19(int n) { return 32 - id37(n); };
constexpr int id19(long long n) { return 64 - id37(n); };
constexpr int id31(int n) { return 1u << (31 - id37(n)); };
constexpr long long id31(long long n) {
  return 1ull << (63 - id37(n));
}
constexpr int id34(int n) {
  if (n == 0 || n == 1) { return 1; }
  return id31(n - 1) << 1;
};
constexpr long long id34(long long n) {
  if (n == 0 || n == 1) { return 1; }
  return id31(n - 1) << 1;
}
constexpr int id18(int n) { return 31 - id37(n); };
constexpr int id18(long long n) { return 63 - id37(n); };
constexpr int id39(int n) {
  if (n == 0 || n == 1) { return 0; }
  return id18(n - 1) + 1;
}
constexpr int id39(long long n) {
  if (n == 0 || n == 1) { return 0; }
  return id18(n - 1) + 1;
}
constexpr int id4(int n) { return __builtin_popcount(n); };
constexpr int id4(long long n) { return __builtin_popcountll(n); }
constexpr int id9(int n) { return __builtin_parity(n); };
}
}
namespace algo {
namespace base {
constexpr bool id6(int n) {
  if (n <= 1) { return false; }
  if (n == 2 || n == 3 || n == 5 || n == 7) { return true; }
  const int s = id3(n - 1);
  const int d = (n - 1) >> s;
  constexpr int primes[] = {2, 3, 5, 7};
  for (int p : primes) {
    int x = id32(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = x * 1ll * x % n;
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
constexpr bool id6(long long n) {
  if (n <= 1) { return false; }
  if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 ||
      n == 19 || n == 23 || n == 29 || n == 31 || n == 37) {
    return true;
  }
  const int s = id3(n - 1);
  const int d = (n - 1) >> s;
  constexpr long long primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (long long p : primes) {
    long long x = id32(p, (long long)d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = x * 1ll * x % n;
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
std::vector<int> id5(const int n) noexcept {
  constexpr int block = 30007;
  std::vector<int> primes;
  const int rn = __sqrt(n);
  std::vector<char> is_prime(rn + 2, true);
  for (int i = 2; i <= rn; ++i) {
    if (is_prime[i]) {
      primes.emplace_back(i);
      for (int j = i * i; j <= rn; j += i) { is_prime[j] = false; }
    }
  }
  std::vector<int> ans;
  std::array<char, block> blk;
  blk.fill(true);
  blk[0] = blk[1] = false;
  for (int k = 0; k * block <= n; ++k) {
    const int start = k * block;
    for (auto &&p : primes) {
      for (int j = base::id22((start + p - 1) / p, p) * p - start; j < block;
           j += p) {
        blk[j] = false;
      }
    }
    for (int i = 0; i < block && start + i <= n; ++i) {
      if (blk[i]) { ans.emplace_back(start + i); }
      blk[i] = true;
    }
  }
  return ans;
}
std::vector<int> id13(const int n) noexcept {
  std::vector<int> phi(n + 1);
  std::iota(phi.begin(), phi.end(), 0);
  for (int i = 2; i <= n; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) { phi[j] -= phi[j] / i; }
    }
  }
  return phi;
}
std::vector<int> id33(const int n) noexcept {
  std::vector<int> ps;
  std::vector<int> lp(n + 1);
  std::vector<int> mu(n + 1, -1);
  mu[1] = 1;
  for (int i = 2, cnt = 0; i <= n; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      ps.emplace_back(i);
      cnt++;
    }
    for (int j = 0; j < cnt && ps[j] <= lp[i] && i * ps[j] <= n; ++j) {
      lp[i * ps[j]] = ps[j];
      mu[i * ps[j]] = -mu[i] * (ps[j] != lp[i]);
    }
  }
  return mu;
}
}
}
namespace algo {
namespace base {
template <typename _T>
constexpr _T id36(_T a, _T m) {
  auto r = id15(a, m);
  _T x = r.first % m;
  if (x < 0) x += m;
  return x;
}
std::optional<int> id27(int a, int b, int m) {
  a %= m;
  if (a < 0) a += m;
  b %= m;
  if (b < 0) b += m;
  const int n = __sqrt(m) + 1;
  assume(a >= 0 && a < m);
  const int an = id32(a, n, m);
  std::unordered_map<int, int> f2;
  for (int q = 0, now = b; q <= n; ++q) {
    f2[now] = q;
    now = (int)now * 1ll * a % m;
  }
  for (int p = 1, cur = 1; p <= n; ++p) {
    cur = cur * 1ll * an % m;
    if (f2.find(cur) != f2.end()) { return std::optional(n * p - f2[cur]); }
  }
  return std::nullopt;
}
constexpr std::optional<int> id8(int n) {
  int phi_n = id26(n);
  const int phi = phi_n;
  std::array<int, 21> divs = {};
  int cnt = 0;
  if (!(phi_n & 0x01)) {
    divs[cnt++] = 2;
    do { phi_n >>= 1; } while (!(phi_n & 0x01));
  }
  for (int i = 3; i * i <= phi_n; i += 2) {
    if (phi_n % i == 0) {
      divs[cnt++] = i;
      do { phi_n /= i; } while (phi_n % i == 0);
    }
  }
  if (phi_n > 1) { divs[cnt++] = phi_n; }
  for (int g = 1; g < n; ++g) {
    bool found = true;
    for (int p = 0; p < cnt; ++p) {
      if (id32(g, phi / divs[p], n) == 1) {
        found = false;
        break;
      }
    }
    if (found) { return std::optional(g); }
  }
  return n == 1 ? std::optional(1) : std::nullopt;
}
constexpr int id24(int n) {
  switch (n) {
    case 2: return 1;
    case 167772161: return 3;
    case 469762049: return 3;
    case 754974721: return 11;
    case 998244353: return 3;
    case 1000000007: return 5;
    case 1000000009: return 13;
  }
  std::array<int, 21> divs = {2};
  int cnt = 1;
  int x = (n - 1) >> 1;
  while (!(x & 0x01)) x >>= 1;
  for (int i = 3; i * i <= x; i += 2) {
    if (x % i == 0) {
      divs[cnt++] = i;
      do { x /= i; } while (x % i == 0);
    }
  }
  if (x > 1) { divs[cnt++] = x; }
  for (int g = 2; g <= n; ++g) {
    bool found = true;
    for (int i = 0; i < cnt; ++i) {
      if (id32(g, (n - 1) / divs[i], n) == 1) {
        found = false;
        break;
      }
    }
    if (found) { return g; }
  }
  unreachable();
}
std::optional<int> id10(int a, int b, int n) {
  const int g = id24(n);
  const int ga = id32(g, a, n);
  std::optional y = id27(ga, b, n);
  return y.has_value() ? std::optional(id32(g, y.value(), n))
                       : std::nullopt;
}
std::vector<int> __crt(const std::vector<int>& a, const std::vector<int>& p) {
  const int k = (int)p.size();
  std::vector<int> ans(k);
  ans[0] = a[0];
  for (int i = 1; i < k; ++i) {
    ans[i] = a[i];
    for (int j = 0; j < i; ++j) {
      ans[i] = (int)id36(p[j], p[i]) * 1ll * (ans[i] - ans[j]) % p[i];
      ans[i] += (ans[i] >> 31) & p[i];
    }
  }
  return ans;
}
}
}
namespace algo {
template <int _MOD, bool _IsPrime = base::id6(_MOD)>
struct modint {
  constexpr modint() = default;
  template <typename _U,
            std::enable_if_t<base::id14<_U, int>, bool> = true>
  constexpr modint(const _U &val) : _M_val(static_cast<int>(val % _MOD)) {
    if (_M_val < 0) _M_val += _MOD;
  }
  constexpr modint(const modint &other) : _M_val(other.val()) {}
  constexpr modint &operator=(const modint &other) {
    _M_val = other.val();
    return *this;
  }
  constexpr modint &operator+=(const modint &rhs) {
    _M_val += rhs.val() - _MOD;
    _M_val += (_M_val >> 31) & _MOD;
    return *this;
  }
  constexpr modint &operator-=(const modint &rhs) { return operator+=(-rhs); }
  constexpr modint &operator*=(const modint &rhs) {
    base::assume(val() >= 0 && val() < _MOD);
    base::assume(rhs.val() >= 0 && rhs.val() < _MOD);
    _M_val = (int)val() * 1ll * rhs.val() % _MOD;
    return *this;
  }
  constexpr modint &operator/=(const modint &rhs) {
    return operator*=(rhs.inv());
  }
  constexpr modint operator-() const {
    base::assume(0 <= val() && val() < _MOD);
    return val() ? _MOD - val() : 0;
  }
  constexpr friend bool operator<(const modint &lhs, const modint &rhs) {
    return lhs.val() < rhs.val();
  }
  constexpr friend bool operator>(const modint &lhs, const modint &rhs) {
    return rhs < lhs;
  }
  constexpr friend bool operator<=(const modint &lhs, const modint &rhs) {
    return !(lhs > rhs);
  }
  constexpr friend bool operator>=(const modint &lhs, const modint &rhs) {
    return !(lhs < rhs);
  }
  constexpr friend bool operator==(const modint &lhs, const modint &rhs) {
    return lhs.val() == rhs.val();
  }
  constexpr friend bool operator!=(const modint &lhs, const modint &rhs) {
    return !(lhs == rhs);
  }
  constexpr friend modint operator+(modint lhs, const modint &rhs) {
    lhs += rhs;
    return lhs;
  }
  constexpr friend modint operator-(modint lhs, const modint &rhs) {
    lhs -= rhs;
    return lhs;
  }
  constexpr friend modint operator*(modint lhs, const modint &rhs) {
    lhs *= rhs;
    return lhs;
  }
  constexpr friend modint operator/(modint lhs, const modint &rhs) {
    lhs /= rhs;
    return lhs;
  }
  constexpr int val() const { return _M_val; }
  constexpr int mod() const { return _MOD; }
  constexpr modint inv() const {

    assert(val() != 0);

    if constexpr (_IsPrime) {
      constexpr int ph = _MOD - 2;
      constexpr int bw = base::id19(ph);
      modint res(1), mul(*this);
      for (int i = 0; i < bw; ++i) {
        if ((ph >> i) & 0x01) { res *= mul; }
        mul *= mul;
      }
      return res;
    } else {
      int res = base::id36(val(), _MOD);
      base::assume(0 <= res && res < _MOD);
      return res;
    }
  }
  constexpr explicit operator int() const { return val(); }
  constexpr explicit operator bool() const { return val() != 0; }
  constexpr explicit operator long() const { return (long)val(); }
  constexpr explicit operator long long() const { return (long long)val(); }
  constexpr explicit operator unsigned int() const {
    return (unsigned int)val();
  }
  constexpr explicit operator unsigned long() const {
    return (unsigned long)val();
  }
  template <typename _U, std::enable_if_t<base::id25<_U>, bool> = true>
  constexpr modint pow(_U x) const {

    assert(x >= 0);

    base::assume(x >= 0);
    if constexpr (_IsPrime) { x %= _MOD - 1; }
    modint res(1), mul(*this);
    while (x > 0) {
      if (x & 0x01) { res *= mul; }
      mul *= mul, x >>= 1;
    }
    return res;
  }
  friend std::ostream &operator<<(std::ostream &os, const modint &mt) {
    os << mt.val();
    return os;
  }
private:
  int _M_val = {};
};
}
namespace algo {
template struct modint<998244353>;
template struct modint<1000000007>;
template struct modint<1000000009>;
}
namespace algo {
template <typename _Monoid, typename _F, typename _E>
class id20 {
public:
  id20() = delete;
  id20(int n, _F &&f, _E &&e) noexcept
      : _size(n), _bit(_size + 1, e()), _f(f), _ef(e) {}
  void apply(int pos, const _Monoid &z) {

    assert(0 <= pos && pos < _size);

    for (++pos; pos <= _size; pos += pos & -pos) {
      _bit[pos] = _f(_bit[pos], z);
    }
  }
  _Monoid query(int r) const {

    assert(0 <= r && r <= _size);

    _Monoid res = _ef();
    for (; r > 0; r -= r & -r) { res = _f(res, _bit[r]); }
    return res;
  }
  template <typename _Pred>
  int id23(_Pred &&pred) const {
    _Monoid cur = _ef();
    int pos = 0;
    for (int i = base::id18(_size); i >= 0; --i) {
      if (pos + (1 << i) <= _size && pred(_f(cur, _bit[pos + (1 << i)]))) {
        pos |= 1 << i;
        cur = _f(cur, _bit[pos + (1 << i)]);
      }
    }
    return pos;
  }
private:
  int _size;
  std::vector<_Monoid> _bit;
  _F _f;
  _E _ef;
};
template <typename _F, typename _E>
id20(int, _F &&, _E &&)
    -> id20<typename base::function_traits<_E>::result_type, _F, _E>;
}
namespace algo {
template <typename _Fn>
struct rec_lambda {
  constexpr rec_lambda(_Fn &&f) : _f(f) {}
  template <typename... _Args>
  decltype(auto) operator()(_Args &&... args) const {
    return _f(*this, std::forward<_Args>(args)...);
  }
private:
  _Fn _f;
};
constexpr long likely(bool x) { return base::likely(x); }
constexpr long unlikely(bool x) { return base::unlikely(x); }
constexpr void assume(bool x) { base::assume(x); }
}
using namespace std;
using namespace std::literals;
using namespace __gnu_pbds;
template <typename _Tp, typename _Fn>
using ordered_set =
    tree<_Tp, null_type, _Fn, rb_tree_tag, tree_order_statistics_node_update>;
using uint = unsigned int;
template <typename _Key, typename _Value>
using umap = unordered_map<_Key, _Value>;
template <typename _Tp, typename _Fn = less<_Tp>>
using max_heap = priority_queue<_Tp, vector<_Tp>, _Fn>;
template <typename _Tp, typename _Fn = greater<_Tp>>
using min_heap = priority_queue<_Tp, vector<_Tp>, _Fn>;
template <typename _Value> using uset = unordered_set<_Value>;
using wint = long long int;






namespace {
  array<int,MAXN>cnt;
}
inline void solve() {
  int n,m;cin>>n>>m;
  algo::assume(1<=n<MAXN&&1<=m<MAXN);
  vector<int>s(n+1),t(m+1);
  for(int i=1;i<=n;++i){cin>>s[i];}
  for(int i=1;i<=m;++i){cin>>t[i];}
  auto f=[](int x,int y){return x+y;};
  auto ef=[]{return 0;};
  algo::modint<MOD>pm=1;
  algo::id20 sgt(MAXN,f,ef);
  for(int i=1;i<=n;++i){
    int c=cnt[s[i]]++;
    sgt.apply(s[i],1);
    pm=pm*i/cnt[s[i]];
  }
  bool fl=s.size()<t.size();
  int q=algo::min(n,m);
  algo::modint<MOD>ans=0;
  for(int i=1;i<=q;++i){
    algo::modint<MOD>sm=sgt.query(t[i]);
    algo::modint<MOD>w=n-i+1;
    w=w.inv();
    ans+=sm*pm*w;
    if(cnt[t[i]]==0){fl=false;break;}
    pm*=w*cnt[t[i]]--;
    sgt.apply(t[i],-1);
  }
  ans+=fl;
  print(ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
  if constexpr (MULTI) {
    int tc = 1;
    cin >> tc;
    while (tc--) {
      solve();
    }
  } else {
    solve();
  }
  return 0;
}
