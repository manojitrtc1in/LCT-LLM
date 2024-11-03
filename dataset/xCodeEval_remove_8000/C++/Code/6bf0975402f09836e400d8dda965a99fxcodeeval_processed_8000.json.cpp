








namespace io {
template <typename _Tp>
void id8(const _Tp &val) noexcept {
  std::cout << val;
}
template <typename _Tp>
void id8(const std::vector<_Tp> &vec) noexcept {
  const int n = (int)vec.size();
  for (int i = 0; i < n; ++i) {
    if (i) std::cout << ' ';
    std::cout << vec[i];
  }
}
template <typename _First, typename _Second>
void id8(const std::pair<_First, _Second> &p) noexcept {
  std::cout << p.first << ' ' << p.second;
}
template <typename... _Args, std::size_t... Is>
void id9(const std::tuple<_Args...> &tup,
                 std::index_sequence<0, Is...>) {
  io::id8(std::get<0>(tup));
  ((std::cout << ' ', io::id8(std::get<Is>(tup))), ...);
}
template <typename... _Args>
void id8(const std::tuple<_Args...> &tup) noexcept {
  id9(tup, std::make_index_sequence<sizeof...(_Args)>{});
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
  io::id8(head);
  ((std::cout << ' ', io::id8(rest)), ...);
  std::cout<<'\n';
}
void flush() noexcept { std::cout.flush(); }

  std::cerr << "Line " << __LINE__ << ":: " \
            << "\033[1;32m" << 
  dbg::view(x); \
  std::cerr << '\n';
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
template <int _N>
struct sieve {
  constexpr sieve() : _lp{}, _cnt{} {
    constexpr int sqn = base::__sqrt(_N);
    for (int i = 2; i <= sqn; ++i) {
      if (!_lp[i]) {
        _lp[i] = i, _cnt++;
        for (int j = i * i; j <= _N; j += i) { _lp[j] = i; }
      }
    }
    for (int i = sqn + 1; i <= _N; ++i) {
      if (!_lp[i]) { _lp[i] = i, _cnt++; }
    }
  }
  constexpr int num_primes() const { return _cnt; }
  constexpr bool is_prime(int n) const { return _lp[n] == n; }
  std::vector<int> prime_list() const noexcept {
    std::vector<int> ans(_cnt);
    if constexpr (_N >= 2) { ans[0] = 2; }
    for (int i = 3, c = 1; i <= _N; i += 2) {
      if (_lp[i] == i) { ans[c] = i; }
    }
    return ans;
  }
  std::vector<int> prime_list(int n) const noexcept {
    std::vector<int> ans;
    for (int i = 2; i <= n; ++i) {
      if (_lp[i] == i) { ans.emplace_back(i); }
    }
    return ans;
  }
  std::vector<std::pair<int, int>> factorize(int n) const noexcept {
    std::vector<std::pair<int, int>> ans{};
    while (n > 1) {
      int p = _lp[n];
      int cnt = 0;
      do { n /= p, cnt++; } while (n % p == 0);
      ans.emplace_back(p, cnt);
    }
    return ans;
  }
  std::vector<int> divisors(int n) const noexcept {
    std::vector<int> ans{1};
    for (auto [p, c] : factorize(n)) {
      const int sz = (int)ans.size();
      for (int i = 0; i < sz; ++i) {
        for (int j = 0, d = ans[i]; j < c; ++j) { ans.emplace_back(d *= p); }
      }
    }
    return ans;
  }
private:
  std::array<int, _N + 1> _lp;
  int _cnt;
};
}
namespace algo {
namespace base {
template <typename _Tp>
constexpr _Tp id23(_Tp a, unsigned int b) {
  _Tp res(1);
  while (b) {
    if (b & 0x01) { res *= a; }
    a *= a;
    b >>= 1;
  }
  return res;
}
template <typename _Tp, typename _Up>
constexpr _Tp id23(_Tp a, unsigned int b, const _Up &init) {
  _Tp res = init;
  while (b) {
    if (b & 0x01) { res *= a; }
    a *= a;
    b >>= 1;
  }
  return res;
}
template <typename _Tp>
constexpr _Tp id20(_Tp n) {
  _Tp ans = n;
  if (!(n & 0x01)) {
    ans >>= 1;
    do { n >>= 1; } while (!(n & 0x01));
  }
  for (_Tp i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      ans -= ans / i;
      do { n /= i; } while (n % i == 0);
    }
  }
  if (n > 1) { ans -= ans / n; }
  return ans;
}
template <typename _Tp>
constexpr _Tp id0(_Tp n) {
  if (n == 1) { return 1; }
  int cnt = 0;
  if (!(n & 0x01)) {
    n >>= 1;
    if (!(n & 0x01)) { return 0; }
    cnt++;
  }
  for (_Tp i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      n /= i;
      if (n % i == 0) { return 0; }
      cnt++;
    }
  }
  return (cnt & 0x01) ? -1 : 1;
}
template <typename _Tp>
constexpr std::pair<_Tp, _Tp> id11(_Tp a, _Tp b) {
  _Tp x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    const _Tp q = a / b;
    _Tp tp = x0;
    x0 = x1, x1 = tp - q * x1, tp = y0, y0 = y1, y1 = tp - q * y1, tp = a,
    a = b, b = tp - q * b;
  }
  if (a < 0) x0 = -x0, a = -a;
  return std::make_pair(x0, a);
}
template <typename _Tp>
constexpr _Tp id25(_Tp a, _Tp b, const _Tp mod) {
  _Tp ans(1);
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
constexpr int id29(int n) { return __builtin_clz(n); };
constexpr int id29(long long n) { return __builtin_clzll(n); };
constexpr int id1(int n) { return __builtin_ctz(n); };
constexpr int id1(long long n) { return __builtin_ctzll(n); }
constexpr int id15(int n) { return 32 - id29(n); };
constexpr int id15(long long n) { return 64 - id29(n); };
constexpr int id24(int n) { return 1u << (31 - id29(n)); };
constexpr long long id24(long long n) {
  return 1ull << (63 - id29(n));
}
constexpr int id27(int n) {
  if (n == 0 || n == 1) { return 1; }
  return id24(n - 1) << 1;
};
constexpr long long id27(long long n) {
  if (n == 0 || n == 1) { return 1; }
  return id24(n - 1) << 1;
}
constexpr int id14(int n) { return 31 - id29(n); };
constexpr int id14(long long n) { return 63 - id29(n); };
constexpr int id30(int n) {
  if (n == 0 || n == 1) { return 0; }
  return id14(n - 1) + 1;
}
constexpr int id30(long long n) {
  if (n == 0 || n == 1) { return 0; }
  return id14(n - 1) + 1;
}
constexpr int id3(int n) { return __builtin_popcount(n); };
constexpr int id3(long long n) { return __builtin_popcountll(n); }
constexpr int id6(int n) { return __builtin_parity(n); };
}
}
namespace algo {
namespace base {
template <typename _Tp>
constexpr _Tp id18(const _Tp &a, const _Tp &b) {
  return a < b ? b : a;
}
template <typename _Tp>
constexpr _Tp __mini(const _Tp &a, const _Tp &b) {
  return a < b ? a : b;
}
template <typename _Tp>
constexpr void __swap(_Tp &a, _Tp &b) {
  _Tp tp = a;
  a = b;
  b = tp;
}
template <typename _Tp>
constexpr void __swap(_Tp *a, _Tp *b) {
  _Tp tp = *a;
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
namespace base {
constexpr bool id4(int n) {
  if (n <= 1) { return false; }
  if (n == 2 || n == 3 || n == 5 || n == 7) { return true; }
  const int s = id1(n - 1);
  const int d = (n - 1) >> s;
  constexpr int primes[] = {2, 3, 5, 7};
  for (int p : primes) {
    int x = id25(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = x * 1ll * x % n;
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
constexpr bool id4(long long n) {
  if (n <= 1) { return false; }
  if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 ||
      n == 19 || n == 23 || n == 29 || n == 31 || n == 37) {
    return true;
  }
  const int s = id1(n - 1);
  const int d = (n - 1) >> s;
  constexpr long long primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (long long p : primes) {
    long long x = id25(p, (long long)d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = x * 1ll * x % n;
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
std::vector<int> id22(const int n) noexcept {
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
      for (int j = base::id18((start + p - 1) / p, p) * p - start; j < block;
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
std::vector<int> id10(const int n) noexcept {
  std::vector<int> phi(n + 1);
  std::iota(phi.begin(), phi.end(), 0);
  for (int i = 2; i <= n; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) { phi[j] -= phi[j] / i; }
    }
  }
  return phi;
}
std::vector<int> id26(const int n) noexcept {
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
template <typename _Tp>
concept integer = std::integral<_Tp> && !std::same_as<_Tp, bool>;
template <typename _Tp>
concept addable = requires(std::remove_reference_t<_Tp> &a,
                           const std::remove_reference_t<_Tp> &b) {
  { a += b }
  ->std::same_as<std::remove_reference_t<_Tp> &>;
};
template <typename _Tp>
concept multipliable = requires(std::remove_reference_t<_Tp> &a,
                                const std::remove_reference_t<_Tp> &b) {
  { a *= b }
  ->std::same_as<std::remove_reference_t<_Tp> &>;
};
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
template <typename _Ret, typename... _Args>
struct function_traits<_Ret(_Args...)> {
  static constexpr size_t arity = sizeof...(_Args);
  using result_type = _Ret;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<_Args...>>::type;
  };
};
template <typename _Fn>
using extract_return_t = typename function_traits<_Fn>::result_type;
template <typename _Fn, typename _Ret, typename... _Args>
concept callable = std::invocable<_Fn, _Args...>
    &&std::same_as<std::invoke_result_t<_Fn, _Args...>, _Ret>;
template <typename _Fn, typename _Arg>
concept unary_op = callable<_Fn, _Arg, _Arg>;
template <typename _Fn, typename _Arg>
concept binary_op = callable<_Fn, _Arg, _Arg, _Arg>;
template <typename _Fn, typename _Arg>
concept unary_predicate = callable<_Fn, bool, _Arg>;
template <typename _Tp>
concept less_than_comparable = requires(const std::remove_reference_t<_Tp> &a,
                                        const std::remove_reference_t<_Tp> &b) {
  { a < b }
  ->std::convertible_to<bool>;
  { !(a < b) }
  ->std::convertible_to<bool>;
};
template <typename _Tp>
concept equality_comparable = std::equality_comparable<_Tp>;
template <typename _From, typename _To>
concept constructible = std::constructible_from<_To, _From>;
template <typename _Iter, typename _Value>
concept input_iterator =
    std::input_iterator<_Iter> &&std::same_as<std::iter_value_t<_Iter>, _Value>;
}
}
namespace algo {
template <base::multipliable _Tp>
constexpr _Tp binpow(_Tp a, unsigned b) {
  return base::id23(a, b);
}
template <base::multipliable _Tp, base::constructible<_Tp> _Up>
constexpr _Tp binpow(_Tp a, unsigned int b, _Up ini) {
  return base::id23(a, b, ini);
}
template <base::integer _Tp>
constexpr std::pair<_Tp, _Tp> id16(_Tp a, _Tp b) {
  return base::id11(a, b);
}
template <base::integer _Tp>
constexpr _Tp id13(_Tp n) {
  base::assume(n >= 0);
  return base::id20(n);
}
template <base::integer _Tp>
constexpr _Tp mobius(_Tp n) {
  base::assume(n >= 0);
  return base::id0(n);
}
std::vector<int> id12(int n) {
  base::assume(n >= 0);
  return base::id10(n);
}
std::vector<int> id2(int n) {
  base::assume(n >= 0);
  return base::id26(n);
}
std::vector<int> id17(int n) {
  base::assume(n >= 0);
  return base::id22(n);
}
constexpr bool prime_test(int n) { return base::id4(n); }
constexpr bool prime_test(long long n) { return base::id4(n); }
}
namespace algo {
namespace base {
template <base::integer _Tp>
constexpr _Tp id28(_Tp a, _Tp m) {
  auto r = id11(a, m);
  _Tp x = r.first % m;
  if (x < 0) x += m;
  return x;
}
std::optional<int> id21(int a, int b, int m) {
  a %= m;
  if (a < 0) a += m;
  b %= m;
  if (b < 0) b += m;
  const int n = __sqrt(m) + 1;
  assume(a >= 0 && a < m);
  const int an = id25(a, n, m);
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
constexpr std::optional<int> id5(int n) {
  int phi_n = id20(n);
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
      if (id25(g, phi / divs[p], n) == 1) {
        found = false;
        break;
      }
    }
    if (found) { return std::optional(g); }
  }
  return n == 1 ? std::optional(1) : std::nullopt;
}
constexpr int id19(int n) {
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
      if (id25(g, (n - 1) / divs[i], n) == 1) {
        found = false;
        break;
      }
    }
    if (found) { return g; }
  }
  unreachable();
}
std::optional<int> id7(int a, int b, int n) {
  const int g = id19(n);
  const int ga = id25(g, a, n);
  std::optional y = id21(ga, b, n);
  return y.has_value() ? std::optional(id25(g, y.value(), n))
                       : std::nullopt;
}
std::vector<int> __crt(const std::vector<int>& a, const std::vector<int>& p) {
  const int k = (int)p.size();
  std::vector<int> ans(k);
  ans[0] = a[0];
  for (int i = 1; i < k; ++i) {
    ans[i] = a[i];
    for (int j = 0; j < i; ++j) {
      ans[i] = (int)id28(p[j], p[i]) * 1ll * (ans[i] - ans[j]) % p[i];
      ans[i] += (ans[i] >> 31) & p[i];
    }
  }
  return ans;
}
}
}
namespace algo {
template <int _MOD, bool _IsPrime = base::id4(_MOD)>
struct modint {
  constexpr modint() = default;
  template <base::integer _Up>
  constexpr modint(const _Up &val) : _M_val(static_cast<int>(val % _MOD)) {
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
    if constexpr (_IsPrime) {
      constexpr int ph = _MOD - 2;
      constexpr int bw = base::id15(ph);
      modint res(1), mul(*this);
      for (int i = 0; i < bw; ++i) {
        if ((ph >> i) & 0x01) { res *= mul; }
        mul *= mul;
      }
      return res;
    } else {
      int res = base::id28(val(), _MOD);
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
  template <base::integer _Up>
  constexpr modint pow(_Up x) const {
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
  array<int,MAXN>tmp;
  auto phi=algo::id12(MAXN);
  array<vector<int>,MAXN>divs;
  constexpr algo::sieve<MAXN>s;
}
inline void solve() noexcept {
  for(int i=1;i<MAXN;++i){
    divs[i]=s.divisors(i);
  }
  int n;cin>>n;
  vector arr(n+1,0);
  for(int i=1;i<=n;++i){cin>>arr[i];}
  algo::modint<MOD>ans=0;
  array<int,MAXN>tmp{};
  for(int d=1;d<=n;++d){
    for(int x=d;x<=n;x+=d){
      for(int p:divs[arr[x]]){
        tmp[p]++;
      }
    }
    algo::modint<MOD>p1=phi[d];
    for(int x=d;x<=n;x+=d){
      for(int p:divs[arr[x]]){
        if(tmp[p]){
          ans+=p1*phi[p]*tmp[p]*tmp[p];
          tmp[p]=0;
        }
      }
    }
  }
  print(ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
  solve();
  return 0;
}
