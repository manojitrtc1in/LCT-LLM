#pragma GCC target("abm,movbe,bmi,bmi2,lzcnt,popcnt,avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("omit-frame-pointer")
#define NDEBUG 1
#include <immintrin.h>
#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <compare>
#include <complex>
#include <concepts>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <memory_resource>
#include <new>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <span>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
namespace algo::detail {
template <typename Tp>
concept integer = std::integral<Tp> && !std::same_as<Tp, bool>;
template <typename Tp>
concept signed_integer = integer<Tp> &&(Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> &&(Tp(-1) > Tp(0));
template <typename From, typename To>
concept sign_compatible_with = integer<From> &&
    ((std::is_signed_v<From> && std::is_signed_v<To>) ||
     (std::is_unsigned_v<From> && std::is_unsigned_v<To>));
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
  static inline constexpr bool same_as =
      std::is_invocable_r_v<return_type, Fn, Args...>;
};
template <typename Fn, typename Sig>
concept function = function_traits<Sig>::template same_as<Fn>;
template <typename IIter, typename Value>
concept input_iterator = std::same_as<std::iter_value_t<IIter>, Value>;
}
namespace algo::detail {
[[gnu::noreturn]] void
unreachable() {
  __builtin_unreachable();
}
[[gnu::always_inline]] constexpr void
assume(bool expr) {
  if (!expr) { unreachable(); }
}
}
namespace algo::detail {
template <typename Tp>
constexpr int
count_lz(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
count_tz(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countr_zero<Up>(n);
}
template <typename Tp>
constexpr int
bit_width(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::bit_width<Up>(n);
}
template <typename Tp>
constexpr Tp
floor_pow2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp
ceil_pow2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int
floor_log2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
ceil_log2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  if (n == 0) { return 0; }
  return Nd - std::countl_zero<Up>(n - 1);
}
template <typename Tp>
constexpr Tp
blsr(Tp n) {
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
constexpr Tp
blsi(Tp n) {
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
constexpr Tp
blsmsk(Tp n) {
  if (std::is_constant_evaluated()) { return n ^ (n - 1); }
  if constexpr (dword_fittable<Tp>) {
    return static_cast<Tp>(_blsmsk_u32(n));
  } else if constexpr (qword_fittable<Tp>) {
    return static_cast<Tp>(_blsmsk_u64(n));
  } else {
    return n ^ (n - 1);
  }
}
template <typename Tp>
constexpr int
popcount(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::popcount<Up>(n);
}
}
namespace algo {
template <detail::integer Tp>
constexpr int
count_lz(Tp n) {
  return detail::count_lz(n);
}
template <detail::integer Tp>
constexpr int
count_tz(Tp n) {
  return detail::count_tz(n);
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
floor_pow2(Tp n) {
  return detail::floor_pow2(n);
}
template <detail::integer Tp>
constexpr Tp
ceil_pow2(Tp n) {
  return detail::ceil_pow2(n);
}
template <detail::integer Tp>
constexpr int
floor_log2(Tp n) {
  return detail::floor_log2(n);
}
template <detail::integer Tp>
constexpr int
ceil_log2(Tp n) {
  return detail::ceil_log2(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n <= 1) { return n; }
  Tp ans = 0;
  for (int i = floor_log2(n) - 1; i >= 0; --i) {
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
floor_div(Tp x, Tp y) {
  if constexpr (std::is_signed_v<Tp>) {
    return x / y - ((x ^ y) < 0 && x % y != 0);
  } else {
    return x / y;
  }
}
template <typename Tp>
constexpr Tp
ceil_div(Tp x, Tp y) {
  if constexpr (std::is_signed_v<Tp>) {
    return y > 0 ? floor_div(x + y - 1, y) : -floor_div(x, -y);
  } else {
    return floor_div(x + y - 1, y);
  }
}
template <typename Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, char>>
alt(Tp n) {
  return -(n & 1) | 1;
}
}
namespace algo::detail {
template <typename Tp>
constexpr imul_result_t<Tp>
safe_mul(Tp x, Tp y) {
  using promoted_type = imul_result_t<Tp>;
  return static_cast<promoted_type>(x) * y;
}
template <typename Tp>
constexpr Tp
assumed_mulmod(Tp x, Tp y, Tp m) {
  assume(0 < m);
  assume(0 <= x && x < m);
  assume(0 <= y && y < m);
  const auto prod = safe_mul(x, y) % m;
  return static_cast<Tp>(prod);
}
template <typename Tp>
constexpr std::pair<Tp, Tp>
euclidean_extended(Tp a, Tp b) {
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
  if (a0 < 0) { x0 = -x0, a0 = -a0; }
  return std::make_pair(x0, a0);
}
template <typename Tp, typename Up>
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
namespace algo::detail {
template <typename Tp>
constexpr Tp
inv_mod(Tp a, Tp m) {
  using Sp = std::make_signed_t<Tp>;
  auto res = euclidean_extended<Sp>(a, m).first % m;
  if (res < 0) { res += m; }
  return res;
}
template <typename Tp>
std::optional<Tp>
discrete_log(Tp a, Tp b, Tp m) {
  if ((a %= m) < 0) { a += m; }
  if ((b %= m) < 0) { b += m; }
  const Tp n = sqrt(m);
  assume(a >= 0 && a < m);
  const Tp an = binpow_mod(a, n, m);
  std::map<Tp, Tp> f2;
  for (Tp q = 0, now = b; q <= n; ++q) {
    f2[now] = q;
    now = assumed_mulmod(now, a, m);
  }
  for (Tp p = 1, cur = 1; p <= n; ++p) {
    cur = assumed_mulmod(cur, an, m);
    if (f2.contains(cur)) { return std::optional(n * p - f2[cur]); }
  }
  return std::nullopt;
}
template <typename Tp>
constexpr std::optional<Tp>
primitive_root(Tp n, Tp phi) {
  assume(n >= 1);
  assume(phi >= 1);
  if (n == 1) { return 1; }
  Tp cur_phi = phi;
  std::array<Tp, 23> factors{};
  int cnt = 0;
  if (cur_phi % 2 == 0) {
    factors[cnt++] = 2;
    do { cur_phi /= 2; } while (cur_phi % 2 == 0);
  }
  if (cur_phi % 3 == 0) {
    factors[cnt++] = 3;
    do { cur_phi /= 3; } while (cur_phi % 3 == 0);
  }
  for (Tp i = 5, c = 2; safe_mul(i, i) <= cur_phi; i += c, c ^= 6) {
    if (cur_phi % i == 0) {
      factors[cnt++] = i;
      do { cur_phi /= i; } while (cur_phi % i == 0);
    }
  }
  if (cur_phi > 1) { factors[cnt++] = cur_phi; }
  const auto first = factors.begin();
  const auto last = factors.begin() + cnt;
  for (Tp g = 1; g < n; ++g) {
    if (std::gcd(n, g) != 1) { continue; }
    const auto check = std::find_if(first, last, [phi, n, g](Tp p) {
      return binpow_mod(g, phi / p, n) == 1;
    });
    if (check == last) { return std::optional(g); }
  }
  return std::nullopt;
}
template <typename Tp>
constexpr Tp
primitive_root_prime(Tp n) {
  assume(n >= 1);
  Tp cur_phi = n - 1;
  std::array<Tp, 23> factors{};
  int cnt = 0;
  if (cur_phi % 2 == 0) {
    factors[cnt++] = 2;
    do { cur_phi /= 2; } while (cur_phi % 2 == 0);
  }
  if (cur_phi % 3 == 0) {
    factors[cnt++] = 3;
    do { cur_phi /= 3; } while (cur_phi % 3 == 0);
  }
  for (Tp i = 5, c = 2; safe_mul(i, i) <= cur_phi; i += c, c ^= 6) {
    if (cur_phi % i == 0) {
      factors[cnt++] = i;
      do { cur_phi /= i; } while (cur_phi % i == 0);
    }
  }
  if (cur_phi > 1) { factors[cnt++] = cur_phi; }
  const auto first = factors.begin();
  const auto last = factors.begin() + cnt;
  for (Tp g = 1; g < n; ++g) {
    const auto check = std::find_if(first, last, [n, g](Tp p) {
      return binpow_mod(g, (n - 1) / p, n) == 1;
    });
    if (check == last) { return g; }
  }
  unreachable();
}
template <typename Tp>
std::optional<Tp>
discrete_root(Tp a, Tp b, Tp n) noexcept {
  const Tp g = primitive_root(n, n - 1);
  const Tp ga = binpow_mod(g, a, n);
  const std::optional<Tp> y = discrete_log(ga, b, n);
  return y ? std::optional(binpow_mod(g, *y, n)) : std::nullopt;
}
}
namespace algo::detail::fft {
namespace constants {
template <int MOD>
constexpr int minv_redc = std::bit_cast<int>(
    static_cast<uint32_t>(inv_mod<imul_result_t<int>>(MOD, 0x100000000)));
template <int MOD>
constexpr int rsq_redc = -static_cast<uint64_t>(MOD) % MOD;
}
template <int N>
static inline __m256i
shuffle256x32(__m256i A, __m256i B) {
  return _mm256_castps_si256(
      _mm256_shuffle_ps(_mm256_castsi256_ps(A), _mm256_castsi256_ps(B), N));
}
template <int N>
static inline __m256i
shuffle256x64(__m256i A) {
  return _mm256_castpd_si256(_mm256_permute4x64_pd(_mm256_castsi256_pd(A), N));
}
template <int N>
static inline __m256i
shuffle256x128(__m256i A, __m256i B) {
  return _mm256_castps_si256(_mm256_permute2f128_ps(_mm256_castsi256_ps(A),
                                                    _mm256_castsi256_ps(B), N));
}
static inline __m256i
mulmod256x32(__m256i A, __m256i B, __m256i M, __m256i M_Inv) {
  const __m256i prod0246 = _mm256_mul_epu32(A, B);
  const __m256i prod1357 =
      _mm256_mul_epu32(_mm256_srli_si256(A, 4), _mm256_srli_si256(B, 4));
  const __m256i qlo = _mm256_mul_epu32(prod0246, M_Inv);
  const __m256i qhi = _mm256_mul_epu32(prod1357, M_Inv);
  const __m256i tmplo = _mm256_mul_epu32(qlo, M);
  const __m256i tmphi = _mm256_mul_epu32(qhi, M);
  const __m256i alo = _mm256_sub_epi32(prod0246, tmplo);
  const __m256i ahi = _mm256_sub_epi32(prod1357, tmphi);
  const __m256i tmpd = shuffle256x32<_MM_SHUFFLE(3, 1, 3, 1)>(alo, ahi);
  const __m256i d = _mm256_shuffle_epi32(tmpd, _MM_SHUFFLE(3, 1, 2, 0));
  return _mm256_add_epi32(d, _mm256_and_si256(_mm256_srai_epi32(d, 31), M));
}
static inline __m256i
reduce256x32(__m256i A, __m256i M, __m256i M_Inv) {
  const __m256i qlo = _mm256_mul_epu32(A, M_Inv);
  const __m256i qhi = _mm256_mul_epu32(_mm256_srli_si256(A, 4), M_Inv);
  const __m256i prodlo = _mm256_mul_epu32(qlo, M);
  const __m256i prodhi = _mm256_mul_epu32(qhi, M);
  const __m256i tmplo = _mm256_sub_epi32(_mm256_setzero_si256(), prodlo);
  const __m256i tmphi = _mm256_sub_epi32(_mm256_setzero_si256(), prodhi);
  const __m256i tmpd = shuffle256x32<_MM_SHUFFLE(3, 1, 3, 1)>(tmplo, tmphi);
  const __m256i d = _mm256_shuffle_epi32(tmpd, _MM_SHUFFLE(3, 1, 2, 0));
  return _mm256_add_epi32(d, _mm256_and_si256(_mm256_srai_epi32(d, 31), M));
}
static inline __m256i
addmod256x32(__m256i A, __m256i B, __m256i M) {
  const __m256i d = _mm256_sub_epi32(_mm256_add_epi32(A, B), M);
  return _mm256_add_epi32(d, _mm256_and_si256(_mm256_srai_epi32(d, 31), M));
}
static inline __m256i
submod256x32(__m256i A, __m256i B, __m256i M) {
  const __m256i d = _mm256_sub_epi32(A, B);
  return _mm256_add_epi32(d, _mm256_and_si256(_mm256_srai_epi32(d, 31), M));
}
int*
get_storage(size_t n) noexcept {
  constexpr std::align_val_t Algn = std::align_val_t(alignof(__m256i));
  void* mem = ::operator new[](n * sizeof(int), Algn, std::nothrow);
  mem = std::assume_aligned<alignof(__m256i)>(mem);
  memset(mem, 0, n * sizeof(int));
  return static_cast<int*>(mem);
}
void
free_storage(int* ptr) noexcept {
  constexpr std::align_val_t Algn = std::align_val_t(alignof(__m256i));
  ::operator delete[](ptr, Algn);
}
void
radix_permute(int* out, int n) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (j < i) { std::swap(out[i], out[j]); }
    j ^= n - (n >> (count_tz(i + 1) + 1));
  }
}
template <int MOD, bool Inverse>
void
do_butterfly(int* out, int n) {
  constexpr int R = 0x100000000 % MOD;
  constexpr int K = count_tz(MOD - 1);
  constexpr int C = (MOD - 1) >> K;
  constexpr int G = primitive_root_prime(MOD);
  constexpr int W = binpow_mod((Inverse) ? inv_mod(G, MOD) : G, C, MOD);
  constexpr static std::array<std::array<int, 17>, K> Wn = [] {
    std::array<std::array<int, 17>, K> res{};
    res[K - 1][0] = 1;
    for (int i = 1; i < 17; ++i) {
      res[K - 1][i] = assumed_mulmod(res[K - 1][i - 1], W, MOD);
    }
    for (int i = K - 2; i >= 0; --i) {
      for (int j = 0; j < 17; ++j) {
        res[i][j] = assumed_mulmod(res[i + 1][j], res[i + 1][j], MOD);
      }
    }
    for (int i = 0; i < K; ++i) {
      for (int j = 0; j < 17; ++j) {
        res[i][j] = assumed_mulmod(res[i][j], R, MOD);
      }
    }
    return res;
  }();
  const __m256i reg_m = _mm256_set1_epi32(MOD);
  const __m256i reg_minv = _mm256_set1_epi32(constants::minv_redc<MOD>);
  const __m256i reg_w1 = _mm256_set1_epi32(Wn[0][0]);
  [[maybe_unused]] const __m256i reg_rsq =
      _mm256_set1_epi32(constants::rsq_redc<MOD>);
  const __m256i reg_w2 =
      _mm256_set_epi32(Wn[1][1], Wn[1][1], Wn[1][0], Wn[1][0], Wn[1][1],
                       Wn[1][1], Wn[1][0], Wn[1][0]);
  const __m256i reg_w3 =
      _mm256_set_epi32(Wn[2][3], Wn[2][3], Wn[2][2], Wn[2][2], Wn[2][1],
                       Wn[2][1], Wn[2][0], Wn[2][0]);
  const __m256i reg_w4 =
      _mm256_set_epi32(Wn[3][7], Wn[3][6], Wn[3][5], Wn[3][4], Wn[3][3],
                       Wn[3][2], Wn[3][1], Wn[3][0]);
  radix_permute(out, n);
  for (int i = 0; i < n; i += 16) {
    __m256i v0 = _mm256_load_si256((__m256i*)&out[i]);
    __m256i v1 = _mm256_load_si256((__m256i*)&out[i + 8]);
    if constexpr (!Inverse) {
      v0 = mulmod256x32(v0, reg_rsq, reg_m, reg_minv);
      v1 = mulmod256x32(v1, reg_rsq, reg_m, reg_minv);
    }
    __m256i u0 = shuffle256x32<_MM_SHUFFLE(2, 0, 2, 0)>(v0, v1);
    __m256i u1 = shuffle256x32<_MM_SHUFFLE(3, 1, 3, 1)>(v0, v1);
    u1 = mulmod256x32(u1, reg_w1, reg_m, reg_minv);
    v0 = addmod256x32(u0, u1, reg_m);
    v1 = submod256x32(u0, u1, reg_m);
    u0 = shuffle256x32<_MM_SHUFFLE(2, 0, 2, 0)>(v0, v1);
    u1 = shuffle256x32<_MM_SHUFFLE(3, 1, 3, 1)>(v0, v1);
    u1 = mulmod256x32(u1, reg_w2, reg_m, reg_minv);
    v0 = addmod256x32(u0, u1, reg_m);
    v1 = submod256x32(u0, u1, reg_m);
    u0 = shuffle256x128<0x20>(v0, v1);
    u1 = shuffle256x128<0x31>(v0, v1);
    u1 = mulmod256x32(u1, reg_w3, reg_m, reg_minv);
    v0 = addmod256x32(u0, u1, reg_m);
    v1 = submod256x32(u0, u1, reg_m);
    const __m256i tmp0 = shuffle256x32<_MM_SHUFFLE(2, 0, 2, 0)>(v0, v1);
    const __m256i tmp1 = shuffle256x32<_MM_SHUFFLE(3, 1, 3, 1)>(v0, v1);
    u0 = shuffle256x64<_MM_SHUFFLE(3, 1, 2, 0)>(tmp0);
    u1 = shuffle256x64<_MM_SHUFFLE(3, 1, 2, 0)>(tmp1);
    u1 = mulmod256x32(u1, reg_w4, reg_m, reg_minv);
    v0 = addmod256x32(u0, u1, reg_m);
    v1 = submod256x32(u0, u1, reg_m);
    _mm256_store_si256((__m256i*)&out[i], v0);
    _mm256_store_si256((__m256i*)&out[i + 8], v1);
  }
  for (int lg = 4, l = 32; l <= n; ++lg, l <<= 1) {
    const __m256i reg_stride = _mm256_set1_epi32(Wn[lg][16]);
    const __m256i reg_fst =
        _mm256_set_epi32(Wn[lg][7], Wn[lg][6], Wn[lg][5], Wn[lg][4], Wn[lg][3],
                         Wn[lg][2], Wn[lg][1], Wn[lg][0]);
    const __m256i reg_sec =
        _mm256_set_epi32(Wn[lg][15], Wn[lg][14], Wn[lg][13], Wn[lg][12],
                         Wn[lg][11], Wn[lg][10], Wn[lg][9], Wn[lg][8]);
    for (int i = 0; i < n; i += l) {
      __m256i reg_wf = reg_fst;
      __m256i reg_ws = reg_sec;
      for (int j = 0; j < (l >> 1); j += 16) {
        __m256i v0 = _mm256_load_si256((__m256i*)&out[i + j]);
        __m256i v1 = _mm256_load_si256((__m256i*)&out[i + j + 8]);
        __m256i v2 = _mm256_load_si256((__m256i*)&out[i + j + (l >> 1)]);
        __m256i v3 = _mm256_load_si256((__m256i*)&out[i + j + (l >> 1) + 8]);
        v2 = mulmod256x32(v2, reg_wf, reg_m, reg_minv);
        v3 = mulmod256x32(v3, reg_ws, reg_m, reg_minv);
        _mm256_store_si256((__m256i*)&out[i + j], addmod256x32(v0, v2, reg_m));
        _mm256_store_si256((__m256i*)&out[i + j + 8],
                           addmod256x32(v1, v3, reg_m));
        _mm256_store_si256((__m256i*)&out[i + j + (l >> 1)],
                           submod256x32(v0, v2, reg_m));
        _mm256_store_si256((__m256i*)&out[i + j + (l >> 1) + 8],
                           submod256x32(v1, v3, reg_m));
        reg_wf = mulmod256x32(reg_wf, reg_stride, reg_m, reg_minv);
        reg_ws = mulmod256x32(reg_ws, reg_stride, reg_m, reg_minv);
      }
    }
  }
  if constexpr (Inverse) {
    const int ninv = assumed_mulmod(inv_mod(n, MOD), R, MOD);
    const __m256i reg_ninv = _mm256_set1_epi32(ninv);
    for (int i = 0; i < n; i += 16) {
      __m256i v0 = _mm256_load_si256((__m256i*)&out[i]);
      __m256i v1 = _mm256_load_si256((__m256i*)&out[i + 8]);
      v0 = mulmod256x32(v0, reg_ninv, reg_m, reg_minv);
      v1 = mulmod256x32(v1, reg_ninv, reg_m, reg_minv);
      _mm256_store_si256((__m256i*)&out[i], reduce256x32(v0, reg_m, reg_minv));
      _mm256_store_si256((__m256i*)&out[i + 8],
                         reduce256x32(v1, reg_m, reg_minv));
    }
  }
}
template <int MOD>
void
convolution(int* __restrict__ c1, int* __restrict__ c2, int n) {
  const __m256i reg_m = _mm256_set1_epi32(MOD);
  const __m256i reg_minv = _mm256_set1_epi32(constants::minv_redc<MOD>);
  do_butterfly<MOD, false>(c1, n);
  do_butterfly<MOD, false>(c2, n);
  for (int i = 0; i < n; i += 16) {
    const __m256i v0 = _mm256_load_si256((__m256i*)&c1[i]);
    const __m256i v1 = _mm256_load_si256((__m256i*)&c1[i + 8]);
    const __m256i u0 = _mm256_load_si256((__m256i*)&c2[i]);
    const __m256i u1 = _mm256_load_si256((__m256i*)&c2[i + 8]);
    const __m256i prod0 = mulmod256x32(v0, u0, reg_m, reg_minv);
    const __m256i prod1 = mulmod256x32(v1, u1, reg_m, reg_minv);
    _mm256_store_si256((__m256i*)&c1[i], prod0);
    _mm256_store_si256((__m256i*)&c1[i + 8], prod1);
    _mm256_store_si256((__m256i*)&c2[i], _mm256_setzero_si256());
    _mm256_store_si256((__m256i*)&c2[i + 8], _mm256_setzero_si256());
  }
  do_butterfly<MOD, true>(c1, n);
}
template <int MOD>
void
consolidate(const int* c1, const int* c2, const int* c3, int* out, int n) {
  using promoted_type = imul_result_t<int>;
  constexpr int M1 = 167772161;
  constexpr int M2 = 469762049;
  constexpr int M3 = 754974721;
  constexpr int I12 = (static_cast<promoted_type>(inv_mod(M1, M2)) << 32) % M2;
  constexpr int I13 = (static_cast<promoted_type>(inv_mod(M1, M3)) << 32) % M3;
  constexpr int I23 = (static_cast<promoted_type>(inv_mod(M2, M3)) << 32) % M3;
  constexpr int C1 = (-static_cast<uint32_t>(MOD)) % MOD;
  constexpr int C2 = (static_cast<promoted_type>(C1) * M1) % MOD;
  constexpr int C3 = (static_cast<promoted_type>(C2) * M2) % MOD;
  const __m256i reg_i12 = _mm256_set1_epi32(I12);
  const __m256i reg_i13 = _mm256_set1_epi32(I13);
  const __m256i reg_i23 = _mm256_set1_epi32(I23);
  const __m256i reg_co1 = _mm256_set1_epi32(C1);
  const __m256i reg_co2 = _mm256_set1_epi32(C2);
  const __m256i reg_co3 = _mm256_set1_epi32(C3);
  const __m256i reg_m2 = _mm256_set1_epi32(M2);
  const __m256i reg_m3 = _mm256_set1_epi32(M3);
  const __m256i reg_m = _mm256_set1_epi32(MOD);
  const __m256i reg_m2inv = _mm256_set1_epi32(constants::minv_redc<M2>);
  const __m256i reg_m3inv = _mm256_set1_epi32(constants::minv_redc<M3>);
  const __m256i reg_minv = _mm256_set1_epi32(constants::minv_redc<MOD>);
  for (int i = 0; i < n; i += 16) {
    __m256i x1 = _mm256_load_si256((__m256i*)&c1[i]);
    __m256i y1 = _mm256_load_si256((__m256i*)&c1[i + 8]);
    __m256i x2 = _mm256_load_si256((__m256i*)&c2[i]);
    __m256i y2 = _mm256_load_si256((__m256i*)&c2[i + 8]);
    __m256i x3 = _mm256_load_si256((__m256i*)&c3[i]);
    __m256i y3 = _mm256_load_si256((__m256i*)&c3[i + 8]);
    x2 = mulmod256x32(submod256x32(x2, x1, reg_m2), reg_i12, reg_m2, reg_m2inv);
    y2 = mulmod256x32(submod256x32(y2, y1, reg_m2), reg_i12, reg_m2, reg_m2inv);
    const __m256i tmp1 =
        mulmod256x32(submod256x32(x3, x1, reg_m3), reg_i13, reg_m3, reg_m3inv);
    const __m256i tmp2 =
        mulmod256x32(submod256x32(y3, y1, reg_m3), reg_i13, reg_m3, reg_m3inv);
    x3 = mulmod256x32(submod256x32(tmp1, x2, reg_m3), reg_i23, reg_m3,
                      reg_m3inv);
    y3 = mulmod256x32(submod256x32(tmp2, y2, reg_m3), reg_i23, reg_m3,
                      reg_m3inv);
    x1 = mulmod256x32(x1, reg_co1, reg_m, reg_minv);
    y1 = mulmod256x32(y1, reg_co1, reg_m, reg_minv);
    x2 = mulmod256x32(x2, reg_co2, reg_m, reg_minv);
    y2 = mulmod256x32(y2, reg_co2, reg_m, reg_minv);
    x3 = mulmod256x32(x3, reg_co3, reg_m, reg_minv);
    y3 = mulmod256x32(y3, reg_co3, reg_m, reg_minv);
    x2 = addmod256x32(x1, x2, reg_m);
    y2 = addmod256x32(y1, y2, reg_m);
    x3 = addmod256x32(x2, x3, reg_m);
    y3 = addmod256x32(y2, y3, reg_m);
    _mm256_storeu_si256((__m256i*)&out[i], x3);
    _mm256_storeu_si256((__m256i*)&out[i + 8], y3);
  }
}
}
namespace algo::detail {
template <dword_fittable Tp>
constexpr bool
prime_test(Tp n) {
  if (n <= 1) { return false; }
  if (n == 2 || n == 3 || n == 5 || n == 7) { return true; }
  const int s = count_tz(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr std::array<Tp, 4> primes{2, 3, 5, 7};
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
  constexpr std::array<Tp, 12> primes{2, 3, 5, 7, 11, 13,
                                      17, 19, 23, 29, 31, 37};
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
template <typename Tp>
constexpr std::make_signed_t<Tp>
mobius(Tp n) {
  assume(n >= 1);
  Tp cur_n = n;
  bool parity = false;
  if (cur_n == 1) { return 1; }
  if (cur_n % 2 == 0) {
    if ((cur_n /= 2) % 2 == 0) { return 0; }
    parity ^= true;
  }
  if (cur_n % 3 == 0) {
    if ((cur_n /= 3) % 3 == 0) { return 0; }
    parity ^= true;
  }
  for (Tp i = 5, c = 2; safe_mul(i, i) <= cur_n; i += c, c ^= 6) {
    if (cur_n % i == 0) {
      if ((cur_n /= i) % i == 0) { return 0; }
      parity ^= true;
    }
  }
  if (cur_n > 1) { parity ^= 1; }
  return alt(parity);
}
template <typename Tp>
constexpr Tp
totient(Tp n) {
  assume(n >= 1);
  Tp cur_n = n, ans = n;
  if (cur_n % 2 == 0) {
    ans -= ans / 2;
    do { cur_n /= 2; } while (cur_n % 2 == 0);
  }
  if (cur_n % 3 == 0) {
    ans -= ans / 3;
    do { cur_n /= 3; } while (cur_n % 3 == 0);
  }
  for (Tp i = 5, c = 2; safe_mul(i, i) <= cur_n; i += c, c ^= 6) {
    if (cur_n % i == 0) {
      ans -= ans / i;
      do { cur_n /= i; } while (cur_n % i == 0);
    }
  }
  if (cur_n > 1) { ans -= ans / cur_n; }
  return ans;
}
}
namespace algo {
template <int MOD>
class modint {
  static constexpr bool IsPrime = detail::prime_test(MOD);
public:
  constexpr modint() = default;
  constexpr modint(detail::signed_integer auto x)
      : value_(static_cast<int>(x % mod())) {
    value_ += (value_ < 0) ? mod() : 0;
  }
  constexpr modint(detail::unsigned_integer auto x)
      : value_(static_cast<int>(x % mod())) {}
  constexpr modint(bool x) : value_(x) {}
  constexpr modint&
  operator+=(modint rhs) {
    value_ += rhs.value() - mod();
    value_ += (value_ < 0) ? mod() : 0;
    return *this;
  }
  constexpr modint&
  operator-=(modint rhs) {
    value_ -= rhs.value();
    value_ += (value_ < 0) ? mod() : 0;
    return *this;
  }
  constexpr modint&
  operator*=(modint rhs) {
    detail::assume(0 <= rhs.value() && rhs.value() < mod());
    detail::assume(0 <= value() && value() < mod());
    value_ = static_cast<int>(detail::safe_mul(value(), rhs.value()) % mod());
    return *this;
  }
  constexpr modint&
  operator/=(modint rhs) {
    return operator*=(rhs.inv());
  }
  constexpr modint
  operator-() const {
    const int res = value() != 0 ? mod() - value() : 0;
    return from(res);
  }
  constexpr modint&
  operator++() {
    return operator+=(1);
  }
  constexpr modint&
  operator--() {
    return operator-=(1);
  }
  constexpr modint
  operator++(int) {
    const modint res = *this;
    operator++();
    return res;
  }
  constexpr modint
  operator--(int) {
    const modint res = *this;
    operator--();
    return res;
  }
  constexpr friend bool
  operator==(modint lhs, modint rhs) {
    return lhs.value() == rhs.value();
  }
  constexpr friend bool
  operator!=(modint lhs, modint rhs) {
    return !(lhs == rhs);
  }
  constexpr friend modint
  operator+(modint lhs, modint rhs) {
    lhs += rhs;
    return lhs;
  }
  constexpr friend modint
  operator-(modint lhs, modint rhs) {
    lhs -= rhs;
    return lhs;
  }
  constexpr friend modint
  operator*(modint lhs, modint rhs) {
    lhs *= rhs;
    return lhs;
  }
  constexpr friend modint
  operator/(modint lhs, modint rhs) {
    lhs /= rhs;
    return lhs;
  }
  constexpr int
  value() const {
    return value_;
  }
  constexpr modint
  inv() const requires(IsPrime) {
    assert(value() != 0);
    return pow(mod() - 2);
  }
  constexpr modint
  inv() const requires(!IsPrime) {
    const auto [res, g] = detail::euclidean_extended(value(), mod());
    assert(g == 1);
    return modint(res);
  }
  constexpr std::optional<modint>
  sqrt() const requires(IsPrime) {
    if constexpr (mod() == 2) { return std::optional(*this); }
    if (value() == 0 || value() == 1) { return std::optional(*this); }
    if (pow((mod() - 1) / 2).value() == mod() - 1) { return std::nullopt; }
    constexpr modint Z = get_quadratic_nonresidue();
    constexpr int K = detail::count_tz(mod() - 1);
    constexpr int C = (mod() - 1) >> K;
    modint res = pow((C + 1) >> 1);
    modint cur = pow(C);
    modint fac = Z.pow(C);
    for (int i = K - 1; i > 0 && cur != 1; --i) {
      const modint nfac = fac * fac;
      if (cur.pow(1 << (i - 1)) == mod() - 1) {
        res *= fac;
        cur *= nfac;
      }
      fac = nfac;
    }
    return std::optional(res);
  }
  constexpr modint
  pow(detail::integer auto x) const {
    assert(x >= 0);
    modint res(1), mul(*this);
    while (x > 0) {
      if (x & 0x01) { res *= mul; }
      mul *= mul;
      x >>= 1;
    }
    return res;
  }
  constexpr modint
  fact() const {
    modint res(1);
    for (int i = 2; i <= value(); ++i) { res *= from(i); }
    return res;
  }
  constexpr static modint
  from(detail::integer auto x) {
    assert(0 <= x && x < mod());
    return std::bit_cast<modint>(static_cast<int>(x));
  }
  constexpr static int
  mod() {
    return MOD;
  }
  constexpr static bool
  is_prime() {
    return IsPrime;
  }
  friend std::ostream&
  operator<<(std::ostream& os, modint mt) {
    os << mt.value();
    return os;
  }
private:
  constexpr static modint
  get_quadratic_nonresidue() requires(IsPrime) {
    for (int x = 2; x < mod(); ++x) {
      if (modint::from(x).pow((mod() - 1) >> 1).value() == mod() - 1) {
        return modint(x);
      }
    }
    detail::unreachable();
  }
  int value_{0};
};
}
namespace algo {
namespace detail {
template <int MOD>
std::vector<modint<MOD>>
convolution1(const std::vector<modint<MOD>>& f1,
             const std::vector<modint<MOD>>& f2, int n) noexcept {
  const size_t n1 = f1.size();
  const size_t n2 = f2.size();
  const size_t block_sz = size_t(n) << 1;
  const int* c1 = reinterpret_cast<const int*>(f1.data());
  const int* c2 = reinterpret_cast<const int*>(f2.data());
  int* buffer = fft::get_storage(block_sz);
  int* p1 = buffer + 0 * n;
  int* p2 = buffer + 1 * n;
  std::copy(c1, c1 + n1, p1);
  std::copy(c2, c2 + n2, p2);
  fft::convolution<MOD>(p1, p2, n);
  modint<MOD>* out = reinterpret_cast<modint<MOD>*>(p1);
  std::vector<modint<MOD>> res(out, out + n);
  fft::free_storage(buffer);
  return res;
}
template <int MOD>
std::vector<modint<MOD>>
convolution3(const std::vector<modint<MOD>>& f1,
             const std::vector<modint<MOD>>& f2, int n) noexcept {
  constexpr int M1 = 167772161;
  constexpr int M2 = 469762049;
  constexpr int M3 = 754974721;
  const size_t n1 = f1.size();
  const size_t n2 = f2.size();
  const size_t block_sz = size_t(n) << 2;
  const int* c1 = reinterpret_cast<const int*>(f1.data());
  const int* c2 = reinterpret_cast<const int*>(f2.data());
  int* buffer = fft::get_storage(block_sz);
  int* p1 = buffer + 0 * n;
  int* p2 = buffer + 1 * n;
  int* p3 = buffer + 2 * n;
  int* p4 = buffer + 3 * n;
  std::copy(c1, c1 + n1, p1);
  std::copy(c2, c2 + n2, p4);
  fft::convolution<M1>(p1, p4, n);
  std::copy(c1, c1 + n1, p2);
  std::copy(c2, c2 + n2, p4);
  fft::convolution<M2>(p2, p4, n);
  std::copy(c1, c1 + n1, p3);
  std::copy(c2, c2 + n2, p4);
  fft::convolution<M3>(p3, p4, n);
  std::vector<modint<MOD>> res(n);
  int* out = reinterpret_cast<int*>(res.data());
  fft::consolidate<MOD>(p1, p2, p3, out, n);
  fft::free_storage(buffer);
  return res;
}
}
template <int MOD>
class poly {
public:
  using mint_type = modint<MOD>;
  poly() = default;
  template <detail::integer Tp>
  poly(const std::vector<Tp>& vec) : c_(vec.begin(), vec.end()) {
    drop_zeros();
  }
  poly(std::vector<mint_type> vec) : c_(std::move(vec)) { drop_zeros(); }
  template <detail::integer Tp>
  poly(std::initializer_list<Tp> lst) : c_(lst.begin(), lst.end()) {
    drop_zeros();
  }
  poly(std::initializer_list<mint_type> lst) : c_(lst) { drop_zeros(); }
  poly&
  operator+=(const poly& rhs) {
    if (size() < rhs.size()) { resize(rhs.c_.size()); }
    for (int i = 0; i < rhs.size(); ++i) { c_[i] += rhs.c_[i]; }
    drop_zeros();
    return *this;
  }
  poly&
  operator+=(mint_type x) {
    if (is_zero()) { c_.emplace_back(0); }
    c_[0] += x;
    drop_zeros();
    return *this;
  }
  poly&
  operator-=(const poly& rhs) {
    if (size() < rhs.size()) { resize(rhs.c_.size()); }
    for (int i = 0; i < rhs.size(); ++i) { c_[i] -= rhs.c_[i]; }
    drop_zeros();
    return *this;
  }
  poly&
  operator-=(mint_type x) {
    if (is_zero()) { c_.emplace_back(0); }
    c_[0] -= x;
    drop_zeros();
    return *this;
  }
  poly&
  operator*=(const poly& rhs) {
    *this = (*this) * rhs;
    return *this;
  }
  poly&
  operator*=(mint_type x) {
    for (auto& c : c_) { c *= x; }
    drop_zeros();
    return *this;
  }
  poly&
  operator/=(const poly& rhs) {
    *this = *this / rhs;
    return *this;
  }
  poly&
  operator%=(const poly& rhs) {
    *this = *this % rhs;
    return *this;
  }
  poly
  operator*(const poly& rhs) const {
    const int m = std::min(size(), rhs.size());
    return is_large(m) ? fast_mul(rhs) : slow_mul(rhs);
  }
  poly
  operator/(const poly& rhs) const {
    assert(!rhs.is_zero());
    const int m = deg() - rhs.deg() + 1;
    return is_large(m) ? fast_div(rhs) : slow_div(rhs);
  }
  poly
  operator%(const poly& rhs) const {
    assert(!rhs.is_zero());
    const poly D = *this / rhs;
    return *this - D * rhs;
  }
  friend poly
  operator-(poly p) {
    for (auto& x : p.c_) { x = -x; }
    return std::move(p);
  }
  friend poly
  operator+(poly lhs, const poly& rhs) {
    lhs += rhs;
    return std::move(lhs);
  }
  friend poly
  operator-(poly lhs, const poly& rhs) {
    lhs -= rhs;
    return std::move(lhs);
  }
  friend poly
  operator+(poly lhs, mint_type rhs) {
    lhs += rhs;
    return std::move(lhs);
  }
  friend poly
  operator+(mint_type lhs, poly rhs) {
    rhs += lhs;
    return std::move(rhs);
  }
  friend poly
  operator-(poly lhs, mint_type rhs) {
    lhs -= rhs;
    return std::move(lhs);
  }
  friend poly
  operator-(mint_type lhs, poly rhs) {
    rhs -= lhs;
    return -std::move(rhs);
  }
  friend poly
  operator*(poly lhs, mint_type rhs) {
    lhs *= rhs;
    return std::move(lhs);
  }
  friend poly
  operator*(mint_type lhs, poly rhs) {
    rhs *= lhs;
    return std::move(rhs);
  }
  mint_type
  operator[](int i) const {
    return i >= 0 && i < size() ? c_[i] : 0;
  }
  mint_type
  operator()(mint_type x) const {
    mint_type ans = 0;
    for (const auto c : c_) {
      ans *= x;
      ans += c;
    }
    return ans;
  }
  poly
  take(int n) const& {
    assert(n > 0);
    return std::vector(c_.begin(), c_.begin() + std::min(n, size()));
  }
  poly
  take(int n) && {
    assert(n > 0);
    resize(std::min(n, size()));
    return std::move(c_);
  }
  poly
  shift(int n) const {
    assert(n >= 0);
    std::vector<mint_type> out(n + size());
    std::copy_backward(c_.begin(), c_.end(), out.end());
    return out;
  }
  poly
  drop(int n) const& {
    assert(n >= 0);
    return std::vector(c_.begin() + std::min(n, size()), c_.end());
  }
  poly
  drop(int n) && {
    assert(n >= 0);
    std::shift_left(c_.begin(), c_.end(), n);
    resize(std::max(0, size() - n));
    return std::move(c_);
  }
  poly
  rev(int n) const {
    assert(n >= 0);
    std::vector<mint_type> res(std::max(size(), n + 1));
    std::copy_backward(c_.rbegin(), c_.rend(), res.end());
    return res;
  }
  poly
  diff() const& {
    std::vector<mint_type> res(std::max(0, deg()));
    for (int i = 1; i < size(); ++i) { res[i - 1] = c_[i] * i; }
    return res;
  }
  poly
  diff() && {
    const int nsz = std::max(0, size() - 1);
    for (int i = 0; i < nsz; ++i) { c_[i] = c_[i + 1] * mint_type(i + 1); }
    resize(nsz);
    return std::move(c_);
  }
  poly
  integrate() const& {
    std::vector<mint_type> res(size() + 1);
    for (int i = 0; i <= deg(); ++i) { res[i + 1] = c_[i] / mint_type(i + 1); }
    return res;
  }
  poly
  integrate() && {
    c_.emplace_back(0);
    for (int i = size() - 1; i > 0; --i) { c_[i] = c_[i - 1] / mint_type(i); }
    c_[0] = 0;
    return std::move(c_);
  }
  poly
  inv(int n) const {
    assert(size() && c_[0] != 0);
    assert(n > 0);
    int pw = 1;
    poly ans = {c_[0].inv()};
    while (pw < n) {
      poly C = ans * take(pw << 1);
      poly D = ans * std::move(C).take(pw << 1).drop(pw);
      ans -= std::move(D).take(pw).shift(pw);
      pw <<= 1;
    }
    return std::move(ans).take(n);
  }
  poly
  binpow(int k, int n) const {
    assert(k >= 0);
    assert(n > 0);
    poly res = {mint_type::from(1)};
    poly mul = take(n);
    while (k > 0) {
      if (k & 0x01) { res = (res * mul).take(n); }
      mul = (mul * mul).take(n);
      k >>= 1;
    }
    return res;
  }
  poly
  log(int n) const {
    assert(n > 0);
    assert(size() && c_[0] != 0);
    return (diff().take(n) * inv(n)).integrate().take(n);
  }
  poly
  exp(int n) const {
    assert(n > 0);
    assert(size() == 0 || c_[0] == 0);
    int pw = 1;
    poly ans = {mint_type::from(1)};
    while (pw < n) {
      const poly H = take(pw << 1).drop(pw) - ans.log(pw << 1).drop(pw);
      ans += (ans * H).take(pw).shift(pw);
      pw <<= 1;
    }
    return std::move(ans).take(n);
  }
  mint_type
  lead() const {
    return is_zero() ? 0 : c_.back();
  }
  std::vector<mint_type>
  data() const {
    return c_;
  }
  int
  deg() const {
    return size() - 1;
  }
  int
  size() const {
    return static_cast<int>(std::ssize(c_));
  }
  bool
  is_zero() const {
    return c_.empty();
  }
  friend std::ostream&
  operator<<(std::ostream& os, const poly& p) {
    for (int i = 0; i < p.size(); ++i) {
      if (i) os << ' ';
      os << p.c_[i].value();
    }
    if (p.is_zero()) { os << 0; }
    return os;
  }
private:
  static constexpr bool
  is_large(int n) {
    return n >= 128;
  }
  void
  drop_zeros() noexcept {
    while (!c_.empty() && c_.back() == 0) { c_.pop_back(); }
  }
  void
  resize(size_t n) noexcept {
    detail::assume(c_.size() < c_.max_size());
    c_.resize(n);
  }
  poly
  slow_mul(const poly& rhs) const {
    if (!is_zero() && !rhs.is_zero()) [[likely]] {
      const int n1 = size();
      const int n2 = rhs.size();
      const int n = n1 + n2 - 1;
      std::vector<mint_type> res(n);
      for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) { res[i + j] += c_[i] * rhs.c_[j]; }
      }
      return res;
    } else {
      return {};
    }
  }
  poly
  fast_mul(const poly& rhs) const {
    constexpr int Cap = 1 << detail::count_tz(mint_type::mod() - 1);
    constexpr int Lim = 1 << 23;
    const int n1 = size();
    const int n2 = rhs.size();
    const int n = detail::ceil_pow2(n1 + n2 - 1);
    if (Cap >= Lim || n <= Cap) {
      return detail::convolution1(c_, rhs.c_, n);
    } else {
      return detail::convolution3(c_, rhs.c_, n);
    }
  }
  poly
  slow_div(const poly& rhs) const {
    const int d1 = deg();
    const int d2 = rhs.deg();
    const int m = d1 - d2 + 1;
    if (d1 < d2) { return poly{}; }
    std::vector<mint_type> out(m), temp(m);
    std::copy(c_.begin() + d2, c_.end(), temp.begin());
    const mint_type x = rhs.c_.back().inv();
    for (int i = m - 1; i >= 0; --i) {
      out[i] = temp[i];
      if (temp[i] != 0) {
        out[i] *= x;
        const int q = std::max(d2 - i, 0);
        for (int j = d2; j >= q; --j) {
          temp[i + j - d2] -= out[i] * rhs.c_[j];
        }
      }
    }
    return out;
  }
  poly
  fast_div(const poly& rhs) const {
    const int d1 = deg();
    const int d2 = rhs.deg();
    const int m = d1 - d2 + 1;
    return (rev(d1).take(m) * rhs.rev(d2).inv(m)).take(m).rev(m - 1);
  }
  poly
  slow_pow(int k, int n) const {
    assert(n > 0);
    if (is_zero()) [[unlikely]] { return {}; }
    std::vector<mint_type> res(n);
    res[0] = c_[0].pow(k);
    for (int i = 1; i < n; ++i) {
      const mint_type c = k;
      for (int j = std::max(0, i - deg()); j < i; ++j) {
        res[i] += res[j] * c_[i - j] * (c * (i - j) - j);
      }
      res[i] /= mint_type(i) * c_[0];
    }
    return res;
  }
  std::vector<mint_type> c_;
};
template <int MOD>
poly(std::vector<modint<MOD>>) -> poly<MOD>;
template <int MOD>
poly(std::initializer_list<modint<MOD>>) -> poly<MOD>;
}
#define PRINT(...) (void)0
#define DEBUG(x) (void)0
namespace algo {
template <int MOD>
class factorial {
public:
  using mint_type = modint<MOD>;
  factorial() = default;
  explicit factorial(int n) noexcept : fac_(n + 1), inv_(n + 1) {
    assert(n < mint_type::mod());
    fac_[0] = 1;
    for (int i = 1; i <= n; ++i) { fac_[i] = fac_[i - 1] * mint_type::from(i); }
    inv_[n] = fac_[n].inv();
    for (int i = n; i > 0; --i) { inv_[i - 1] = inv_[i] * mint_type::from(i); }
  }
  [[gnu::pure]] mint_type
  fact(int n) const {
    assert(n <= limit());
    return n >= 0 ? fac_[n] : 0;
  }
  [[gnu::pure]] mint_type
  inv_fact(int n) const {
    assert(n <= limit());
    return n >= 0 ? inv_[n] : 0;
  }
  [[gnu::pure]] mint_type
  comb(int n, int r) const {
    assert(n <= limit());
    return n >= r && r >= 0 ? fac_[n] * inv_[r] * inv_[n - r] : 0;
  }
  [[gnu::pure]] mint_type
  perm(int n, int r) const {
    assert(n <= limit());
    return n >= r && r >= 0 ? fac_[n] * inv_[n - r] : 0;
  }
  int
  limit() const {
    return static_cast<int>(fac_.size()) - 1;
  }
private:
  std::vector<mint_type> fac_;
  std::vector<mint_type> inv_;
};
}
namespace algo {
template <int MOD>
class inv_mods {
public:
  using mint_type = modint<MOD>;
  static_assert(mint_type::is_prime());
  inv_mods() = default;
  explicit inv_mods(int n) : inv_(n + 1) {
    assert(n < mint_type::mod());
    inv_[1] = 1;
    for (int i = 2; i <= n; ++i) {
      inv_[i] = mint_type::from(mint_type::mod() - mint_type::mod() / i) *
                inv_[mint_type::mod() % i];
    }
  }
  constexpr mint_type
  inv(int n) const {
    assert(n <= limit());
    return inv_[n];
  }
  int
  limit() const {
    return static_cast<int>(inv_.size()) - 1;
  }
private:
  std::vector<mint_type> inv_;
};
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
floor_div(T1 x, T2 y) {
  assert(y != 0);
  using Tp = std::common_type_t<T1, T2>;
  return detail::floor_div<Tp>(x, y);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2>
ceil_div(T1 x, T2 y) {
  assert(y != 0);
  using Tp = std::common_type_t<T1, T2>;
  return detail::ceil_div<Tp>(x, y);
}
template <std::integral Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, char>>
alt(Tp n) {
  return detail::alt(n);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2,
          detail::sign_compatible_with<T2> T3,
          detail::sign_compatible_with<T3> T4>
constexpr std::common_type_t<T1, T2, T3, T4>
floor_sum(T1 a, T2 b, T3 c, T4 n) {
  assert(n >= 0);
  assert(c > 0);
  assert(a >= 0);
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
using bint = uint_fast8_t;
template <typename Key, typename Value, typename Hash = std::hash<Key>>
using umap = std::unordered_map<Key, Value, Hash>;
template <typename Key, typename Hash = std::hash<Key>>
using uset = std::unordered_set<Key, Hash>;
template <typename Tp, typename Comp = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;
template <typename Tp, typename Comp = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;
#define INF 0x3f3f3f3f
#define MOD 998244353
#define MAXN 200001
#define MULTI 0
namespace {
const algo::factorial<MOD> fac(MAXN - 1);
const algo::inv_mods<MOD> invs(MAXN - 1);
}
void solve() noexcept {
  using mint = algo::modint<MOD>;
  using poly = algo::poly<MOD>;
  int n;
  cin >> n;
  vector<mint> dp(n);
  vector<mint> dp2(n + 1);
  vector<mint> f(n), g(n);
  dp[0] = dp2[1] = 1;
  const int mid = (n - 1) >> 1;
  for (int i = 1; i < n; ++i) {
    mint c = invs.inv(i);
    mint d = dp2[i];
    if (i >= mid) {
      d -= dp2[i - mid];
    }
    dp[i] = c * d;
    dp2[i + 1] = dp2[i] + dp[i];
  }
  for (int i = n - mid - 1; i < n - 1; ++i) {
    auto c = dp2[i];
    if (i >= mid) {
      c -= dp2[i - mid];
    }
    f[i] = c * fac.fact(n - i - 2) * invs.inv(i);
  }
  for (int i = 0; i < n; ++i) {
    g[i] = fac.inv_fact(i);
  }
  vector<mint> coef = (poly(move(f)) * poly(move(g))).data();
  coef.resize(n);
  vector<mint> ans(n);
  for (int i = 1; i < n; ++i) {
    ans[i] = mint::from(i) * fac.fact(n - i - 1) * coef[n - i - 1];
  }
  ans[0] = ans[1];
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}
