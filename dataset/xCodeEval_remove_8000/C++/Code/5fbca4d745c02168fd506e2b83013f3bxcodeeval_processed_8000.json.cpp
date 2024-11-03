












namespace dbg {

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
constexpr Tp
sqrt(Tp n) {
  typedef safe_mul_t<Tp> wide_t;
  int p = 32 - __builtin_clz(n);
  Tp ans = p & 0x01;
  for (p >>= 1, p &= ~1u; p >= 0; --p) {
    ans <<= 1;
    if (static_cast<wide_t>(ans + 1) * (ans + 1) <= (n >> (p << 1))) {
      ans |= 1;
    }
  }
  return ans;
}
template <qword_fittable Tp>
constexpr Tp
sqrt(Tp n) {
  typedef safe_mul_t<Tp> wide_t;
  int p = 64 - __builtin_clzll(n);
  Tp ans = p & 0x01;
  for (p >>= 1, p &= ~1u; p >= 0; --p) {
    ans <<= 1;
    if (static_cast<wide_t>(ans + 1) * (ans + 1) <= (n >> (p << 1))) {
      ans |= 1;
    }
  }
  return ans;
}
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
assume(bool expr) noexcept {
  if (!expr) unreachable();
}
}
}
namespace algo {
template <int Num>
class sieve {
public:
  sieve() : lp_(((Num + 29) / 30) << 3) {
    constexpr int n = (Num + 29) / 30;
    constexpr int m = (detail::sqrt(30 * n + 1) - 29) / 30 + 1;
    lp_[(0 << 3) + 0] = 1;
    for (int k = 0; k <= m; ++k) {
      if (!lp_[(k << 3) + 0]) {
        const int pm = 30 * k + 1;
        const int s0 = k * (30 * k + 2 * 1) + (1 * 1) / 30;
        const int s1 = 6 * k + 0 + s0;
        const int s2 = 4 * k + 0 + s1;
        const int s3 = 2 * k + 0 + s2;
        const int s4 = 4 * k + 0 + s3;
        const int s5 = 2 * k + 0 + s4;
        const int s6 = 4 * k + 0 + s5;
        const int s7 = 6 * k + 0 + s6;
        for (int s = s0; s < n; s += pm) { lp_[(s << 3) + 0] = pm; }
        for (int s = s1; s < n; s += pm) { lp_[(s << 3) + 1] = pm; }
        for (int s = s2; s < n; s += pm) { lp_[(s << 3) + 2] = pm; }
        for (int s = s3; s < n; s += pm) { lp_[(s << 3) + 3] = pm; }
        for (int s = s4; s < n; s += pm) { lp_[(s << 3) + 4] = pm; }
        for (int s = s5; s < n; s += pm) { lp_[(s << 3) + 5] = pm; }
        for (int s = s6; s < n; s += pm) { lp_[(s << 3) + 6] = pm; }
        for (int s = s7; s < n; s += pm) { lp_[(s << 3) + 7] = pm; }
      }
      if (!lp_[(k << 3) + 1]) {
        const int pm = 30 * k + 7;
        const int s5 = k * (30 * k + 2 * 7) + (7 * 7) / 30;
        const int s4 = 4 * k + 1 + s5;
        const int s0 = 2 * k + 1 + s4;
        const int s7 = 4 * k + 0 + s0;
        const int s3 = 2 * k + 1 + s7;
        const int s2 = 4 * k + 1 + s3;
        const int s6 = 6 * k + 1 + s2;
        const int s1 = 2 * k + 1 + s6;
        for (int s = s0; s < n; s += pm) { lp_[(s << 3) + 0] = pm; }
        for (int s = s1; s < n; s += pm) { lp_[(s << 3) + 1] = pm; }
        for (int s = s2; s < n; s += pm) { lp_[(s << 3) + 2] = pm; }
        for (int s = s3; s < n; s += pm) { lp_[(s << 3) + 3] = pm; }
        for (int s = s4; s < n; s += pm) { lp_[(s << 3) + 4] = pm; }
        for (int s = s5; s < n; s += pm) { lp_[(s << 3) + 5] = pm; }
        for (int s = s6; s < n; s += pm) { lp_[(s << 3) + 6] = pm; }
        for (int s = s7; s < n; s += pm) { lp_[(s << 3) + 7] = pm; }
      }
      if (!lp_[(k << 3) + 2]) {
        const int pm = 30 * k + 11;
        const int s0 = k * (30 * k + 2 * 11) + (11 * 11) / 30;
        const int s6 = 2 * k + 0 + s0;
        const int s1 = 4 * k + 2 + s6;
        const int s7 = 2 * k + 0 + s1;
        const int s3 = 4 * k + 2 + s7;
        const int s5 = 6 * k + 2 + s3;
        const int s2 = 2 * k + 1 + s5;
        const int s4 = 6 * k + 2 + s2;
        for (int s = s0; s < n; s += pm) { lp_[(s << 3) + 0] = pm; }
        for (int s = s1; s < n; s += pm) { lp_[(s << 3) + 1] = pm; }
        for (int s = s2; s < n; s += pm) { lp_[(s << 3) + 2] = pm; }
        for (int s = s3; s < n; s += pm) { lp_[(s << 3) + 3] = pm; }
        for (int s = s4; s < n; s += pm) { lp_[(s << 3) + 4] = pm; }
        for (int s = s5; s < n; s += pm) { lp_[(s << 3) + 5] = pm; }
        for (int s = s6; s < n; s += pm) { lp_[(s << 3) + 6] = pm; }
        for (int s = s7; s < n; s += pm) { lp_[(s << 3) + 7] = pm; }
      }
      if (!lp_[(k << 3) + 3]) {
        const int pm = 30 * k + 13;
        const int s5 = k * (30 * k + 2 * 13) + (13 * 13) / 30;
        const int s2 = 4 * k + 2 + s5;
        const int s1 = 2 * k + 1 + s2;
        const int s7 = 4 * k + 1 + s1;
        const int s4 = 6 * k + 3 + s7;
        const int s3 = 2 * k + 1 + s4;
        const int s0 = 6 * k + 3 + s3;
        const int s6 = 4 * k + 1 + s0;
        for (int s = s0; s < n; s += pm) { lp_[(s << 3) + 0] = pm; }
        for (int s = s1; s < n; s += pm) { lp_[(s << 3) + 1] = pm; }
        for (int s = s2; s < n; s += pm) { lp_[(s << 3) + 2] = pm; }
        for (int s = s3; s < n; s += pm) { lp_[(s << 3) + 3] = pm; }
        for (int s = s4; s < n; s += pm) { lp_[(s << 3) + 4] = pm; }
        for (int s = s5; s < n; s += pm) { lp_[(s << 3) + 5] = pm; }
        for (int s = s6; s < n; s += pm) { lp_[(s << 3) + 6] = pm; }
        for (int s = s7; s < n; s += pm) { lp_[(s << 3) + 7] = pm; }
      }
      if (!lp_[(k << 3) + 4]) {
        const int pm = 30 * k + 17;
        const int s5 = k * (30 * k + 2 * 17) + (17 * 17) / 30;
        const int s6 = 2 * k + 1 + s5;
        const int s0 = 4 * k + 3 + s6;
        const int s3 = 6 * k + 3 + s0;
        const int s4 = 2 * k + 1 + s3;
        const int s7 = 6 * k + 3 + s4;
        const int s1 = 4 * k + 3 + s7;
        const int s2 = 2 * k + 1 + s1;
        for (int s = s0; s < n; s += pm) { lp_[(s << 3) + 0] = pm; }
        for (int s = s1; s < n; s += pm) { lp_[(s << 3) + 1] = pm; }
        for (int s = s2; s < n; s += pm) { lp_[(s << 3) + 2] = pm; }
        for (int s = s3; s < n; s += pm) { lp_[(s << 3) + 3] = pm; }
        for (int s = s4; s < n; s += pm) { lp_[(s << 3) + 4] = pm; }
        for (int s = s5; s < n; s += pm) { lp_[(s << 3) + 5] = pm; }
        for (int s = s6; s < n; s += pm) { lp_[(s << 3) + 6] = pm; }
        for (int s = s7; s < n; s += pm) { lp_[(s << 3) + 7] = pm; }
      }
      if (!lp_[(k << 3) + 5]) {
        const int pm = 30 * k + 19;
        const int s0 = k * (30 * k + 2 * 19) + (19 * 19) / 30;
        const int s4 = 4 * k + 2 + s0;
        const int s2 = 6 * k + 4 + s4;
        const int s5 = 2 * k + 1 + s2;
        const int s3 = 6 * k + 4 + s5;
        const int s7 = 4 * k + 2 + s3;
        const int s1 = 2 * k + 2 + s7;
        const int s6 = 4 * k + 2 + s1;
        for (int s = s0; s < n; s += pm) { lp_[(s << 3) + 0] = pm; }
        for (int s = s1; s < n; s += pm) { lp_[(s << 3) + 1] = pm; }
        for (int s = s2; s < n; s += pm) { lp_[(s << 3) + 2] = pm; }
        for (int s = s3; s < n; s += pm) { lp_[(s << 3) + 3] = pm; }
        for (int s = s4; s < n; s += pm) { lp_[(s << 3) + 4] = pm; }
        for (int s = s5; s < n; s += pm) { lp_[(s << 3) + 5] = pm; }
        for (int s = s6; s < n; s += pm) { lp_[(s << 3) + 6] = pm; }
        for (int s = s7; s < n; s += pm) { lp_[(s << 3) + 7] = pm; }
      }
      if (!lp_[(k << 3) + 6]) {
        const int pm = 30 * k + 23;
        const int s5 = k * (30 * k + 2 * 23) + (23 * 23) / 30;
        const int s1 = 6 * k + 5 + s5;
        const int s6 = 2 * k + 1 + s1;
        const int s2 = 6 * k + 5 + s6;
        const int s3 = 4 * k + 3 + s2;
        const int s7 = 2 * k + 1 + s3;
        const int s0 = 4 * k + 4 + s7;
        const int s4 = 2 * k + 1 + s0;
        for (int s = s0; s < n; s += pm) { lp_[(s << 3) + 0] = pm; }
        for (int s = s1; s < n; s += pm) { lp_[(s << 3) + 1] = pm; }
        for (int s = s2; s < n; s += pm) { lp_[(s << 3) + 2] = pm; }
        for (int s = s3; s < n; s += pm) { lp_[(s << 3) + 3] = pm; }
        for (int s = s4; s < n; s += pm) { lp_[(s << 3) + 4] = pm; }
        for (int s = s5; s < n; s += pm) { lp_[(s << 3) + 5] = pm; }
        for (int s = s6; s < n; s += pm) { lp_[(s << 3) + 6] = pm; }
        for (int s = s7; s < n; s += pm) { lp_[(s << 3) + 7] = pm; }
      }
      if (!lp_[(k << 3) + 7]) {
        const int pm = 30 * k + 29;
        const int s0 = k * (30 * k + 2 * 29) + (29 * 29) / 30;
        const int s7 = 2 * k + 1 + s0;
        const int s6 = 6 * k + 6 + s7;
        const int s5 = 4 * k + 4 + s6;
        const int s4 = 2 * k + 2 + s5;
        const int s3 = 4 * k + 4 + s4;
        const int s2 = 2 * k + 2 + s3;
        const int s1 = 4 * k + 4 + s2;
        for (int s = s0; s < n; s += pm) { lp_[(s << 3) + 0] = pm; }
        for (int s = s1; s < n; s += pm) { lp_[(s << 3) + 1] = pm; }
        for (int s = s2; s < n; s += pm) { lp_[(s << 3) + 2] = pm; }
        for (int s = s3; s < n; s += pm) { lp_[(s << 3) + 3] = pm; }
        for (int s = s4; s < n; s += pm) { lp_[(s << 3) + 4] = pm; }
        for (int s = s5; s < n; s += pm) { lp_[(s << 3) + 5] = pm; }
        for (int s = s6; s < n; s += pm) { lp_[(s << 3) + 6] = pm; }
        for (int s = s7; s < n; s += pm) { lp_[(s << 3) + 7] = pm; }
      }
    }
  }
  std::vector<std::pair<int, int>>
  factorize(int n) const {
    assert(1 <= n && n <= Num);
    detail::assume(1 <= n && n <= Num);
    std::vector<std::pair<int, int>> ans;
    if (n % 2 == 0) {
      int c = 0;
      do { n /= 2, c++; } while (n % 2 == 0);
      ans.emplace_back(2, c);
    }
    if (n % 3 == 0) {
      int c = 0;
      do { n /= 3, c++; } while (n % 3 == 0);
      ans.emplace_back(3, c);
    }
    if (n % 5 == 0) {
      int c = 0;
      do { n /= 5, c++; } while (n % 5 == 0);
      ans.emplace_back(5, c);
    }
    while (n > 1) {
      const int p = get_nontrivial_factor(n);
      int c = 0;
      do { n /= p, c++; } while (n % p == 0);
      ans.emplace_back(p, c);
    }
    return ans;
  }
  std::vector<int>
  divisors(int n) const {
    assert(1 <= n && n <= Num);
    std::vector<int> ans{1};
    for (const auto& [p, c] : factorize(n)) {
      const int cur_sz = std::ssize(ans);
      for (int i = 0; i < cur_sz; ++i) {
        for (int j = 0, d = ans[i]; j < c; ++j) { ans.emplace_back(d *= p); }
      }
    }
    return ans;
  }
private:
  int
  get_nontrivial_factor(int n) const {
    detail::assume(1 <= n && n <= Num);
    const int d = n / 30, r = n % 30;
    switch (r) {
      case 1: return lp_[(d << 3) + 0] ? lp_[(d << 3) + 0] : n;
      case 7: return lp_[(d << 3) + 1] ? lp_[(d << 3) + 1] : n;
      case 11: return lp_[(d << 3) + 2] ? lp_[(d << 3) + 2] : n;
      case 13: return lp_[(d << 3) + 3] ? lp_[(d << 3) + 3] : n;
      case 17: return lp_[(d << 3) + 4] ? lp_[(d << 3) + 4] : n;
      case 19: return lp_[(d << 3) + 5] ? lp_[(d << 3) + 5] : n;
      case 23: return lp_[(d << 3) + 6] ? lp_[(d << 3) + 6] : n;
      case 29: return lp_[(d << 3) + 7] ? lp_[(d << 3) + 7] : n;
      default: assert(false);
    }
    detail::unreachable();
  }
  std::vector<int> lp_;
};
}
namespace algo {
namespace detail {
template <integer Tp>
constexpr Tp
id2(Tp x, Tp y, Tp m) {
  assume(0 <= x && x < m);
  assume(0 <= y && y < m);
  return static_cast<safe_mul_t<std::make_unsigned_t<Tp>>>(x) * y % m;
}
template <multipliable Tp, integer Up>
constexpr Tp
binpow(Tp a, Up b) {
  Tp res(1);
  std::make_unsigned_t<Up> pw = b;
  while (pw) {
    if (pw & 0x01) { res *= a; }
    a *= a;
    pw >>= 1;
  }
  return res;
}
template <multipliable T1, constructible<T1> T2, integer Up>
constexpr T1
binpow(T1 a, Up b, const T2 &init) {
  T1 res(init);
  std::make_unsigned_t<Up> pw = b;
  while (pw) {
    if (pw & 0x01) { res *= a; }
    a *= a;
    pw >>= 1;
  }
  return res;
}
template <integer Tp>
constexpr Tp
id4(Tp n) {
  Tp ans = n;
  if (!(n & 0x01)) {
    ans >>= 1;
    do { n >>= 1; } while (!(n & 0x01));
  }
  for (Tp i = 3; i * i <= n; i += 2) {
    if (Tp x = n / i; n - x * i == 0) {
      ans -= ans / i;
      do { n = x, x /= i; } while (n - x * i == 0);
    }
  }
  if (n > 1) { ans -= ans / n; }
  return ans;
}
template <integer Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, int>>
mobius(Tp n) {
  if (n == 1) { return 1; }
  int cnt = 0;
  if (!(n & 0x01)) {
    n >>= 1;
    if (!(n & 0x01)) { return 0; }
    cnt++;
  }
  for (Tp i = 3; i * i <= n; i += 2) {
    if (Tp x = n / i; n - x * i == 0) {
      n = x;
      if (n % i == 0) { return 0; }
      cnt++;
    }
  }
  if (cnt & 0x01) { return -1; }
  return 1;
}
template <signed_integer Tp>
constexpr std::pair<Tp, Tp>
id7(Tp a, Tp b) {
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
id5(Tp a, Up b, Tp m) {
  Tp ans = 1, mul = a;
  const Tp mod = m;
  std::make_unsigned_t<Up> pw = b;
  if ((mul %= mod) < 0) mul += mod;
  while (pw) {
    if (pw & 0x01) { ans = id2(ans, mul, mod); }
    mul = id2(mul, mul, mod);
    pw >>= 1;
  }
  return ans;
}
}
}
namespace algo {
namespace detail {
template <dword_fittable Tp>
constexpr int
id6(Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable Tp>
constexpr int
id6(Tp n) {
  return __builtin_clzll(n);
}
template <dword_fittable Tp>
constexpr int
id12(Tp n) {
  return __builtin_ctz(n);
}
template <qword_fittable Tp>
constexpr int
id12(Tp n) {
  return __builtin_ctzll(n);
}
template <dword_fittable Tp>
constexpr int
id11(Tp n) {
  return __builtin_ffs(n) - 1;
}
template <qword_fittable Tp>
constexpr int
id11(Tp n) {
  return __builtin_ffsll(n) - 1;
}
template <dword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 32 - id6(n);
}
template <qword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 64 - id6(n);
}
template <dword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1u << (31 - id6(n));
}
template <qword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1ull << (63 - id6(n));
}
template <integer Tp>
constexpr Tp
id0(Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return bit_floor(n - 1) << 1;
}
template <dword_fittable Tp>
constexpr int
id9(Tp n) {
  return 31 - id6(n);
}
template <qword_fittable Tp>
constexpr int
id9(Tp n) {
  return 63 - id6(n);
}
template <integer Tp>
constexpr int
id10(Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return id9(n - 1) + 1;
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
template <dword_fittable Tp>
constexpr bool
prime_test(Tp n) {
  if (n <= 1) { return false; }
  if (n == 2 || n == 3 || n == 5 || n == 7) { return true; }
  const int s = id12(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr Tp primes[] = {2, 3, 5, 7};
  for (const auto &p : primes) {
    Tp x = id5(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = id2(x, x, n);
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
  const int s = id12(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr Tp primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (const auto &p : primes) {
    Tp x = id5(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = id2(x, x, n);
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
std::vector<int>
id8(int n) noexcept {
  constexpr int block = 30007;
  std::vector<int> primes;
  const int rn = sqrt(n);
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
      for (int j = std::max((start + p - 1) / p, p) * p - start; j < block;
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
template <integer Tp>
std::vector<Tp>
id3(Tp n) noexcept {
  std::vector<Tp> phi(n + 1);
  iota(phi.begin(), phi.end(), 0);
  for (Tp i = 2; i <= n; ++i) {
    if (phi[i] == i) {
      for (Tp j = i; j <= n; j += i) { phi[j] -= phi[j] / i; }
    }
  }
  return phi;
}
std::vector<int>
id1(int n) noexcept {
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
template <int MOD, bool IsPrime = detail::prime_test(MOD)>
class modint {
public:
  constexpr modint() = default;
  template <detail::signed_integer Tp>
  constexpr modint(Tp x) : value_(static_cast<int>(x % MOD)) {
    if (value_ < 0) { value_ += MOD; }
  }
  template <detail::unsigned_integer Tp>
  constexpr modint(Tp x) : value_(static_cast<int>(x % MOD)) {}
  constexpr modint &
  operator+=(const modint &rhs) {
    value_ += rhs.val() - MOD;
    if (value_ < 0) { value_ += MOD; }
    return *this;
  }
  constexpr modint &
  operator-=(const modint &rhs) {
    value_ -= rhs.val();
    if (value_ < 0) { value_ += MOD; }
    return *this;
  }
  constexpr modint &
  operator*=(const modint &rhs) {
    detail::assume(0 <= val() && val() < MOD);
    detail::assume(0 <= rhs.val() && rhs.val() < MOD);
    value_ = static_cast<detail::safe_mul_t<int>>(val()) * rhs.val() % MOD;
    return *this;
  }
  constexpr modint &
  operator/=(const modint &rhs) {
    return operator*=(rhs.inv());
  }
  constexpr modint
  operator-() const {
    detail::assume(0 <= val() && val() < MOD);
    return modint(MOD - val());
  }
  constexpr modint &
  operator++() {
    return operator+=(1);
  }
  constexpr modint &
  operator--() {
    return operator-=(1);
  }
  constexpr modint
  operator++(int) {
    const modint res(*this);
    operator++();
    return res;
  }
  constexpr modint
  operator--(int) {
    const modint res(*this);
    operator--();
    return res;
  }
  constexpr friend bool
  operator==(const modint &lhs, const modint &rhs) {
    return lhs.val() == rhs.val();
  }
  constexpr friend bool
  operator!=(const modint &lhs, const modint &rhs) {
    return !(lhs == rhs);
  }
  constexpr friend modint
  operator+(modint lhs, const modint &rhs) {
    lhs += rhs;
    return lhs;
  }
  constexpr friend modint
  operator-(modint lhs, const modint &rhs) {
    lhs -= rhs;
    return lhs;
  }
  constexpr friend modint
  operator*(modint lhs, const modint &rhs) {
    lhs *= rhs;
    return lhs;
  }
  constexpr friend modint
  operator/(modint lhs, const modint &rhs) {
    lhs /= rhs;
    return lhs;
  }
  constexpr int
  val() const {
    return value_;
  }
  constexpr modint
  inv() const requires(IsPrime) {
    assert(val() != 0);
    return pow(MOD - 2);
  }
  constexpr modint
  inv() const requires(!IsPrime) {
    const auto [res, g] = detail::id7(val(), MOD);
    assert(g == 1);
    return modint(res);
  }
  template <detail::integer Tp>
  constexpr modint
  pow(Tp x) const {
    assert(x >= 0);
    modint res(1), mul(*this);
    while (x > 0) {
      if (x & 0x01) { res *= mul; }
      mul *= mul, x >>= 1;
    }
    return res;
  }
  constexpr modint
  fact() const {
    modint res(1);
    for (int i = 2; i <= val(); ++i) { res *= from(i); }
    return res;
  }
  friend std::ostream &
  operator<<(std::ostream &os, const modint &mt) {
    os << mt.val();
    return os;
  }
  constexpr static int
  mod() {
    return MOD;
  }
  template <detail::integer Tp>
  constexpr static modint
  from(Tp x) {
    assert(0 <= x && x < MOD);
    detail::assume(0 <= x && x < MOD);
    return modint(x);
  }
private:
  int value_{0};
};
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





const algo::sieve<MAXN-1> s{};
vector<int>pf(MAXN),a0(MAXN);
inline void solve() noexcept {
  using mint=algo::modint<MOD>;
  int n;cin>>n;
  typedef struct{
    int a,b,to;
  }edge;
  vector<vector<edge>>adj(n);
  for(int i=0;i<n-1;++i){
    int a,b,x,y;cin>>a>>b>>x>>y;
    a--,b--;
    adj[a].emplace_back(x,y,b);
    adj[b].emplace_back(y,x,a);
  }
  vector<mint>num(n);
  set<int>primes;
  num[0]=1;
  algo::rec_lambda([&](auto dfs,int u,int p)->void{
    for(auto&&[x,y,v]:adj[u]){
      if(v!=p){
        num[v]=num[u]*y/x;
        auto fx=s.factorize(x),fy=s.factorize(y);
        for(auto&&[f,c]:fy){
          pf[f]+=c;
          primes.insert(f);
        }
        for(auto&&[f,c]:fx){
          pf[f]-=c;
          a0[f]=max(a0[f],-pf[f]);
          primes.insert(f);
        }
        dfs(v,u);
        for(auto&&[f,c]:fx){
          pf[f]+=c;
        }
        for(auto&&[f,c]:fy){
          pf[f]-=c;
        }
      }
    }
  })(0,0);
  mint base=1;
  for(auto&&p:primes){
    base*=mint::from(p).pow(a0[p]);
    pf[p]=a0[p]=0;
  }
  mint ans=0;
  for(int i=0;i<n;++i){
    ans+=base*num[i];
  }
  cout<<ans<<'\n';
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  int tc;
  std::cin >> tc;
  while (tc--) { solve(); }
  return 0;
}
