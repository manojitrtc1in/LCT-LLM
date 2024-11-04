














































namespace algo::detail {
struct modnum_base {};
struct monostate {};
template <typename Tp>
concept integer = std::integral<Tp> && !(std::same_as<Tp, bool>);
template <typename Tp>
concept signed_integer = integer<Tp> && (Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> && (Tp(-1) > Tp(0));
template <typename Tp>
concept modular_integer = std::is_base_of_v<modnum_base, Tp>;
template <typename From, typename To>
concept sign_compatible_with =
    integer<From> && ((std::is_signed_v<From> && std::is_signed_v<To>) ||
                      (std::is_unsigned_v<From> && std::is_unsigned_v<To>));
template <typename Tp>
concept arithmetic = integer<Tp> || (std::is_floating_point_v<Tp>);
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
inline void unreachable [[gnu::noreturn]] () { __builtin_unreachable(); }
constexpr void assume [[gnu::always_inline]] (bool expr) {
  if (!expr) { __builtin_unreachable(); }
}
}
namespace algo::detail {
template <typename Tp>
constexpr int id5(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id10(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countr_zero<Up>(n);
}
template <typename Tp>
constexpr int bit_width(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::bit_width<Up>(n);
}
template <typename Tp>
constexpr Tp id8(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp id1(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int id2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id9(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  if (n == 0) { return 0; }
  return Nd - std::countl_zero<Up>(n - 1);
}
template <typename Tp>
constexpr Tp blsr(Tp n) {
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
constexpr Tp blsi(Tp n) {
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
constexpr int popcount(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::popcount<Up>(n);
}
}
namespace algo {
template <detail::integer Tp>
constexpr int id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr int id10(Tp n) {
  return detail::id10(n);
}
template <detail::integer Tp>
constexpr int bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp id8(Tp n) {
  return detail::id8(n);
}
template <detail::integer Tp>
constexpr Tp id1(Tp n) {
  return detail::id1(n);
}
template <detail::integer Tp>
constexpr int id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr int id9(Tp n) {
  return detail::id9(n);
}
template <detail::integer Tp>
constexpr Tp blsr(Tp n) {
  return detail::blsr(n);
}
template <detail::integer Tp>
constexpr Tp blsi(Tp n) {
  return detail::blsi(n);
}
template <detail::integer Tp>
constexpr int popcount(Tp n) {
  return detail::popcount(n);
}
}


namespace algo {
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
class id7 {
public:
  id7() = default;
  id7(int n, BinOp binop, Id id) noexcept
      : tree_(n + 1, id()), binop_(std::move(binop)), id_(std::move(id)) {}
  id7(int n, const Monoid& def, BinOp binop, Id id)
      : tree_(n + 1, def), binop_(std::move(binop)), id_(std::move(id)) {
    tree_[0] = id_();
    for (int i = 1; i <= n; ++i) {
      const int j = i + algo::blsi(i);
      if (j <= n) { tree_[j] = binop_(tree_[i], tree_[j]); }
    }
  }
  void apply(int pos, const Monoid& z) {
    for (int i = pos + 1; i <= size(); i += detail::blsi(i)) {
      tree_[i] = binop_(tree_[i], z);
    }
  }
  Monoid query(int r) const {
    Monoid res = id_();
    for (int i = r + 1; i > 0; i = detail::blsr(i)) {
      res = binop_(tree_[i], res);
    }
    return res;
  }
  int size() const { return static_cast<int>(tree_.size()) - 1; }
private:
  std::vector<Monoid> tree_;
  [[no_unique_address]] BinOp binop_;
  [[no_unique_address]] Id id_;
};
}
namespace algo {
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
auto id12(int n, BinOp binop, Id id)
    -> id7<Monoid, BinOp, Id> {
  return {n, std::move(binop), std::move(id)};
}
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
auto id12(int n, const Monoid& def, BinOp binop, Id id)
    -> id7<Monoid, BinOp, Id> {
  return {n, def, std::move(binop), std::move(id)};
}
}
namespace algo::detail {
template <typename Tp>
constexpr Tp sqrt(Tp n) {
  if (n == 0) { return 0; }
  Tp ans = 0;
  for (int i = id2(n) >> 1; i >= 0; --i) {
    const Tp tmp = (n - ans * ans) >> i;
    if ((Tp(1) << i) + (ans << 1) <= tmp) { ans |= Tp(1) << i; }
  }
  return ans;
}
template <typename Tp>
constexpr Tp abs(Tp n) {
  return n < 0 ? -n : n;
}
template <typename Tp>
constexpr Tp floor_div(Tp x, Tp y) {
  if constexpr (std::is_signed_v<Tp>) {
    return x / y - ((x ^ y) < 0 && x % y != 0);
  } else {
    return x / y;
  }
}
template <typename Tp>
constexpr Tp ceil_div(Tp x, Tp y) {
  if constexpr (std::is_signed_v<Tp>) {
    return y > 0 ? floor_div(x + y - 1, y) : -floor_div(x, -y);
  } else {
    return floor_div(x + y - 1, y);
  }
}
template <typename Tp>
constexpr int alt(Tp n) {
  return -(n & 1) | 1;
}
}
namespace algo {
template <detail::integer Tp>
constexpr Tp sqrt(Tp n) {
  return detail::sqrt(n);
}
template <detail::integer Tp>
constexpr Tp abs(Tp n) {
  return detail::abs(n);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2> floor_div(T1 x, T2 y) {
  using Tp = std::common_type_t<T1, T2>;
  return detail::floor_div<Tp>(x, y);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2> ceil_div(T1 x, T2 y) {
  using Tp = std::common_type_t<T1, T2>;
  return detail::ceil_div<Tp>(x, y);
}
template <std::integral Tp>
constexpr int alt(Tp n) {
  return detail::alt(n);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2,
          detail::sign_compatible_with<T2> T3,
          detail::sign_compatible_with<T3> T4>
constexpr auto floor_sum(T1 a, T2 b, T3 c, T4 n)
    -> std::common_type_t<T1, T2, T3, T4> {
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
namespace algo::detail {
template <typename Tp>
constexpr imul_result_t<Tp> safe_mul(Tp x, Tp y) {
  using promoted_type = imul_result_t<Tp>;
  return static_cast<promoted_type>(x) * y;
}
template <typename Tp>
constexpr Tp mulmod(Tp x, Tp y, Tp m) {
  assume(0 < m);
  assume(0 <= x && x < m);
  assume(0 <= y && y < m);
  const auto prod = safe_mul(x, y) % m;
  return static_cast<Tp>(prod);
}
template <typename Tp>
constexpr std::array<Tp, 3> id11(Tp a, Tp b) {
  Tp x0 = 1, y0 = 0, x1 = 0, y1 = 1, a0 = a, b0 = b;
  while (b0) {
    Tp q = a0 / b0, tp = x0;
    x0 = x1;
    x1 = tp - q * x1;
    tp = y0;
    y0 = y1;
    y1 = tp - q * y1;
    tp = a0;
    a0 = b0;
    b0 = tp - q * b0;
  }
  if (a0 < 0) { x0 = -x0, y0 = -y0, a0 = -a0; }
  return {x0, y0, a0};
}
template <typename Tp, typename Up>
constexpr Tp id4(Tp a, Up b, Tp m) {
  Tp ans = 1, mul = a;
  const Tp mod = m;
  std::make_unsigned_t<Up> pw = b;
  if ((mul %= mod) < 0) mul += mod;
  while (pw) {
    if (pw & 0x01) { ans = mulmod(ans, mul, mod); }
    mul = mulmod(mul, mul, mod);
    pw >>= 1;
  }
  return ans;
}
}
namespace algo::detail {
template <dword_fittable Tp>
constexpr bool prime_test(Tp n) {
  if (n <= 1) { return false; }
  const int s = id10(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr std::array<Tp, 4> primes{2, 3, 5, 7};
  for (const Tp p : primes) {
    if (p == n) { return true; }
    Tp x = id4(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = mulmod(x, x, n);
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
template <qword_fittable Tp>
constexpr bool prime_test(Tp n) {
  if (n <= 1) { return false; }
  const int s = id10(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr std::array<Tp, 12> primes{2, 3, 5, 7, 11, 13,
                                      17, 19, 23, 29, 31, 37};
  for (const Tp p : primes) {
    if (p == n) { return true; }
    Tp x = id4(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = mulmod(x, x, n);
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
template <typename Tp>
constexpr int mobius(Tp n) {
  assume(n >= 1);
  bool parity = false;
  if (n == 1) { return 1; }
  if (n % 2 == 0) {
    if ((n /= 2) % 2 == 0) { return 0; }
    parity ^= true;
  }
  if (n % 3 == 0) {
    if ((n /= 3) % 3 == 0) { return 0; }
    parity ^= true;
  }
  const Tp sn = sqrt(n);
  for (Tp i = 5, c = 2; i <= sn; i += c, c ^= 6) {
    if (n % i == 0) {
      if ((n /= i) % i == 0) { return 0; }
      parity ^= true;
    }
  }
  if (n > 1) { parity ^= 1; }
  return alt(parity);
}
template <typename Tp>
constexpr Tp totient(Tp n) {
  assume(n >= 1);
  Tp ans = n;
  if (n % 2 == 0) {
    ans -= ans / 2;
    do { n /= 2; } while (n % 2 == 0);
  }
  if (n % 3 == 0) {
    ans -= ans / 3;
    do { n /= 3; } while (n % 3 == 0);
  }
  const Tp sn = sqrt(n);
  for (Tp i = 5, c = 2; i <= sn; i += c, c ^= 6) {
    if (n % i == 0) {
      ans -= ans / i;
      do { n /= i; } while (n % i == 0);
    }
  }
  if (n > 1) { ans -= ans / n; }
  return ans;
}
template <typename Tp>
constexpr int id6(Tp n) {
  assume(n >= 1);
  int ans = 0;
  if (n % 2 == 0) {
    ans = ans + 1;
    do { n /= 2; } while (n % 2 == 0);
  }
  if (n % 3 == 0) {
    ans = ans + 1;
    do { n /= 3; } while (n % 3 == 0);
  }
  const Tp sn = sqrt(n);
  for (Tp i = 5, c = 2; i <= sn; i += c, c ^= 6) {
    if (n % i == 0) {
      ans = ans + 1;
      do { n /= i; } while (n % i == 0);
    }
  }
  if (n > 1) { ans = ans + 1; }
  return ans;
}
template <typename Tp>
constexpr int id3(Tp n) {
  assume(n >= 1);
  int cnt = 0;
  if (n % 2 == 0) {
    do { n /= 2, cnt++; } while (n % 2 == 0);
  }
  if (n % 3 == 0) {
    do { n /= 3, cnt++; } while (n % 3 == 0);
  }
  const Tp sn = sqrt(n);
  for (Tp i = 5, c = 2; i <= sn; i += c, c ^= 6) {
    if (n % i == 0) {
      do { n /= i, cnt++; } while (n % i == 0);
    }
  }
  if (n > 1) { cnt = cnt + 1; }
  return cnt;
}
}
namespace algo {
template <uint32_t MOD = 998244353>
  requires(0 < MOD && MOD < (1u << 31))
class modint : detail::modnum_base {
public:
  static_assert(MOD > 0, "Non-positive modulus doesn't make sense");
  static constexpr bool IsPrime = detail::prime_test(MOD);
  constexpr modint() = default;
  template <detail::integer Tp>
  constexpr modint(Tp n) : value_{transform(n)} {}
  constexpr modint(bool b) : value_{b ? 0 : 1 % MOD} {}
  constexpr modint& operator+=(modint rhs) {
    value_ += rhs.value() - MOD;
    value_ += (static_cast<int32_t>(value_) >> 31) & MOD;
    return *this;
  }
  constexpr modint& operator-=(modint rhs) {
    value_ -= rhs.value();
    value_ += (static_cast<int32_t>(value_) >> 31) & MOD;
    return *this;
  }
  constexpr modint& operator*=(modint rhs) {
    detail::assume(rhs.value() < MOD);
    detail::assume(value() < MOD);
    value_ = detail::mulmod(value(), rhs.value(), MOD);
    return *this;
  }
  constexpr modint& operator/=(modint rhs) { return operator*=(rhs.inv()); }
  constexpr modint& operator++() { return operator+=(1); }
  constexpr modint& operator--() { return operator-=(1); }
  constexpr modint operator++(int) {
    const modint res{*this};
    operator++();
    return res;
  }
  constexpr modint operator--(int) {
    const modint res{*this};
    operator--();
    return res;
  }
  constexpr modint operator-() const {
    const uint32_t res = value() != 0 ? MOD - value() : 0;
    return from(res);
  }
  constexpr friend modint operator+(modint lhs, modint rhs) {
    lhs += rhs;
    return lhs;
  }
  constexpr friend modint operator-(modint lhs, modint rhs) {
    lhs -= rhs;
    return lhs;
  }
  constexpr friend modint operator*(modint lhs, modint rhs) {
    lhs *= rhs;
    return lhs;
  }
  constexpr friend modint operator/(modint lhs, modint rhs) {
    lhs /= rhs;
    return lhs;
  }
  constexpr friend bool operator==(modint lhs, modint rhs) {
    return lhs.value() == rhs.value();
  }
  constexpr friend bool operator!=(modint lhs, modint rhs) {
    return !(lhs == rhs);
  }
  constexpr uint32_t value() const { return value_; }
  constexpr uint32_t get() const { return value_; }
  static constexpr uint32_t mod() { return MOD; }
  constexpr modint inv() const {
    if constexpr (IsPrime) {
      return pow(MOD - 2);
    } else {
      const auto [res, _, g] = detail::id11<int32_t>(value(), MOD);
      return {res};
    }
  }
  constexpr std::optional<modint> sqrt() const
    requires(IsPrime)
  {
    if constexpr (MOD == 2) { return *this; }
    if (value() == 0 || value() == 1) { return *this; }
    if (pow((MOD - 1) / 2).value() == MOD - 1) { return std::nullopt; }
    constexpr modint Z = get_quadratic_nonresidue();
    constexpr uint32_t K = detail::id10(MOD - 1);
    constexpr uint32_t C = (MOD - 1) >> K;
    modint res = pow((C + 1) >> 1);
    modint cur = pow(C);
    modint fac = Z.pow(C);
    for (uint32_t i = K - 1; i > 0 && cur != 1; --i) {
      const modint nfac = fac * fac;
      if (cur.pow(1 << (i - 1)) == MOD - 1) {
        res *= fac;
        cur *= nfac;
      }
      fac = nfac;
    }
    return res;
  }
  template <detail::integer Tp>
  constexpr modint pow(Tp x) const {
    modint res{1};
    modint mul{*this};
    while (x > 0) {
      if (x & 0x01) { res *= mul; }
      mul *= mul;
      x >>= 1;
    }
    return res;
  }
  constexpr modint fact() const {
    modint res{1};
    for (uint32_t i = 2; i <= value(); ++i) { res *= from(i); }
    return res;
  }
  template <detail::integer Tp>
  constexpr static modint from(Tp x) {
    return std::bit_cast<modint>(static_cast<uint32_t>(x));
  }
  friend std::ostream& operator<<(std::ostream& os, modint m) noexcept {
    os << m.value();
    return os;
  }
  constexpr static uint32_t transform(uint32_t n) { return n % MOD; }
  constexpr static uint32_t transform(int32_t n) {
    n %= static_cast<int32_t>(MOD);
    if (n < 0) { n += static_cast<int32_t>(MOD); }
    return static_cast<uint32_t>(n);
  }
  constexpr static uint32_t transform(uint64_t n) {
    return static_cast<uint32_t>(n % MOD);
  }
  constexpr static uint32_t transform(int64_t n) {
    n %= static_cast<int64_t>(MOD);
    if (n < 0) { n += static_cast<int64_t>(MOD); }
    return static_cast<uint32_t>(n);
  }
private:
  constexpr static modint get_quadratic_nonresidue()
    requires(IsPrime)
  {
    for (uint32_t x = 2; x < MOD; ++x) {
      if (modint::from(x).pow((MOD - 1) >> 1).value() == MOD - 1) {
        return modint::from(x);
      }
    }
    detail::unreachable();
  }
  uint32_t value_{0};
};
}
namespace algo {
template <uint32_t MOD>
std::vector<modint<MOD>> id0(int n)
  requires(modint<MOD>::IsPrime)
{
  using mint_type = modint<MOD>;
  std::vector<mint_type> inv(n + 1);
  inv[1] = 1;
  for (uint32_t i = 2; i <= static_cast<uint32_t>(n); ++i) {
    inv[i] = mint_type::from(MOD - MOD / i) * inv[MOD % i];
  }
  return inv;
}
}
namespace views = std::views;
namespace chrono = std::chrono;
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
using std::nullopt;
using std::optional;
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
using bint = uint8_t;
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
  using mint = algo::modint<MOD>;
  int n;
  cin >> n;
  auto fen = algo::id12<mint>(
      n + 1, [](mint x, mint y) { return x + y; }, [] { return mint(0); });
  fen.apply(n, 1);
  vector<mint> ans(n + 1);
  for (int i = n - 1; i > 0; --i) {
    mint suf = fen.query(min(i + i - 1, n)) - fen.query(i);
    ans[i] = 2 * suf * mint(2).pow(i >> 1);
    fen.apply(i, suf);
  }
  mint nv = mint(2).pow(n).inv();
  for (int i = n - 1; i > 0; --i) { ans[i] *= nv; }
  ans[n] = 1 - accumulate(ans.begin(), ans.end(), mint(0));
  for (int i = 1; i <= n; ++i) { cout << ans[i] << '\n'; }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cout.precision(15);
  std::fixed(std::cout);
  int tc;
  std::cin >> tc;
  while (tc--) { solve(); }
  return 0;
}
