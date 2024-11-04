

#include <cstdint>
#include <type_traits>
#include <iostream>
#include <utility>

namespace lib::detail {

class ModIntBase {};

class StaticModIntBase : public ModIntBase {};

class RuntimeModIntBase : public ModIntBase {};

template <typename T>
using is_mod_int = std::is_base_of<ModIntBase, T>;

template <typename T>
inline constexpr bool is_mod_int_v = std::is_base_of_v<ModIntBase, T>;

template <typename T>
using is_static_mod_int = std::is_base_of<StaticModIntBase, T>;

template <typename T>
inline constexpr bool is_static_mod_int_v = std::is_base_of_v<StaticModIntBase, T>;

template <typename T>
using is_runtime_mod_int = std::is_base_of<RuntimeModIntBase, T>;

template <typename T>
inline constexpr bool is_runtime_mod_int_v = std::is_base_of_v<RuntimeModIntBase, T>;

}

namespace lib {

template <std::uint32_t MOD>
class LazyMontgomeryModInt final : public detail::StaticModIntBase {
private:
  using u32 = std::uint32_t;
  using u64 = std::uint64_t;
  using i32 = std::int32_t;

public:
  using raw_type = u32;

  static constexpr u32 getMod() { return MOD; }

  static constexpr u32 getPrimitiveRootPrime() {
    u32 tmp[32] = {}, m = getMod() - 1U;
    i32 cnt = 0;
    for (u32 i = 2U; i * i <= m; ++i)
      if (m % i == 0U) {
        tmp[cnt++] = i;
        do { m /= i; } while (m % i == 0U);
      }
    if (m != 1U) tmp[cnt++] = m;
    for (LazyMontgomeryModInt res(2U);; res += LazyMontgomeryModInt(1U)) {
      bool f = true;
      for (int i = 0; i < cnt && f; ++i) f &= res.pow((getMod() - 1U) / tmp[i]) != LazyMontgomeryModInt(1U);
      if (f) return res.get();
    }
  }

  constexpr LazyMontgomeryModInt() = default;

  ~LazyMontgomeryModInt() = default;

  template <typename T, std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>> * = nullptr>
  explicit constexpr
  LazyMontgomeryModInt(T v) : v_(reduce(static_cast<u64>(v % static_cast<i32>(MOD) + static_cast<i32>(MOD)) * r2)) {}

  template <typename T, std::enable_if_t<std::is_integral_v<T> && std::is_unsigned_v<T>> * = nullptr>
  explicit constexpr LazyMontgomeryModInt(T v) : v_(reduce(static_cast<u64>(v % MOD) * r2)) {}

  constexpr LazyMontgomeryModInt(const LazyMontgomeryModInt &) = default;

  [[nodiscard]] constexpr u32 get() const { return norm(reduce(v_)); }

  template <typename T, std::enable_if_t<std::is_integral_v<T>> * = nullptr>
  explicit constexpr operator T() const { return static_cast<T>(get()); }

  constexpr LazyMontgomeryModInt operator-() const {
    LazyMontgomeryModInt res;
    res.v_ = (MOD * 2U & -(v_ != 0U)) - v_;
    return res;
  }

  constexpr LazyMontgomeryModInt inv() const {
    i32 x1 = 1, x3 = 0, a = static_cast<i32>(get()), b = static_cast<i32>(MOD);
    while (b != 0) {
      i32 q = a / b, x1_old = x1, a_old = a;
      x1 = x3, x3 = x1_old - x3 * q, a = b, b = a_old - b * q;
    }
    return LazyMontgomeryModInt(x1);
  }

  constexpr LazyMontgomeryModInt &operator=(const LazyMontgomeryModInt &) = default;

  constexpr LazyMontgomeryModInt &operator+=(const LazyMontgomeryModInt &rhs) {
    v_ += rhs.v_ - MOD * 2U;
    v_ += MOD * 2U & -(v_ >> 31);
    return *this;
  }

  constexpr LazyMontgomeryModInt &operator-=(const LazyMontgomeryModInt &rhs) {
    v_ -= rhs.v_;
    v_ += MOD * 2U & -(v_ >> 31);
    return *this;
  }

  constexpr LazyMontgomeryModInt &operator*=(const LazyMontgomeryModInt &rhs) {
    v_ = reduce(static_cast<u64>(v_) * rhs.v_);
    return *this;
  }

  constexpr LazyMontgomeryModInt &operator/=(const LazyMontgomeryModInt &rhs) { return operator*=(rhs.inv()); }

  friend constexpr LazyMontgomeryModInt operator+(const LazyMontgomeryModInt &lhs, const LazyMontgomeryModInt &rhs) {
    return LazyMontgomeryModInt(lhs) += rhs;
  }

  friend constexpr LazyMontgomeryModInt operator-(const LazyMontgomeryModInt &lhs, const LazyMontgomeryModInt &rhs) {
    return LazyMontgomeryModInt(lhs) -= rhs;
  }

  friend constexpr LazyMontgomeryModInt operator*(const LazyMontgomeryModInt &lhs, const LazyMontgomeryModInt &rhs) {
    return LazyMontgomeryModInt(lhs) *= rhs;
  }

  friend constexpr LazyMontgomeryModInt operator/(const LazyMontgomeryModInt &lhs, const LazyMontgomeryModInt &rhs) {
    return LazyMontgomeryModInt(lhs) /= rhs;
  }

  friend constexpr bool operator==(const LazyMontgomeryModInt &lhs, const LazyMontgomeryModInt &rhs) {
    return norm(lhs.v_) == norm(rhs.v_);
  }

  friend constexpr bool operator!=(const LazyMontgomeryModInt &lhs, const LazyMontgomeryModInt &rhs) {
    return norm(lhs.v_) != norm(rhs.v_);
  }

  friend std::istream &operator>>(std::istream &is, LazyMontgomeryModInt &rhs) {
    i32 x;
    is >> x;
    rhs = LazyMontgomeryModInt(x);
    return is;
  }

  friend std::ostream &operator<<(std::ostream &os, const LazyMontgomeryModInt &rhs) { return os << rhs.get(); }

  constexpr LazyMontgomeryModInt pow(u64 y) const {
    for (LazyMontgomeryModInt res(1U), x(*this);; x *= x) {
      if ((y & 1ULL) != 0ULL) res *= x;
      if ((y >>= 1) == 0ULL) return res;
    }
  }

private:
  static constexpr u32 getR() {
    u32 two = 2U, iv = MOD * (two - MOD * MOD);
    iv *= two - MOD * iv;
    iv *= two - MOD * iv;
    return iv * (MOD * iv - two);
  }

  static constexpr u32 reduce(u64 x) { return (x + static_cast<u64>(static_cast<u32>(x) * r) * MOD) >> 32; }

  static constexpr u32 norm(u32 x) { return x - (MOD & -((MOD - 1U - x) >> 31)); }

  raw_type v_;
  static constexpr u32 r = getR();
  static constexpr u32 r2 = -static_cast<u64>(MOD) % MOD;

  static_assert((MOD & 1U) == 1U, "MOD should be odd");
  static_assert(-r * MOD == 1U, "unknown error");
  static_assert(((MOD >> 30) & 3U) == 0U, "MOD should be less than (1U << 30)");
  static_assert(MOD != 1U, "MOD should not be 1");
};

}

namespace lib {

template <std::uint64_t MOD>
class LongMontgomeryModInt final : public detail::StaticModIntBase {
private:
  using u32 = std::uint32_t;
  using u64 = std::uint64_t;
  using i32 = std::int32_t;
  using i64 = std::int64_t;

#ifdef __GNUC__
  using u128 = unsigned __int128;
#endif

public:
  using raw_type = u64;

  static constexpr u64 getMod() { return MOD; }

  static constexpr u64 getPrimitiveRootPrime() {
    u64 tmp[64] = {}, m = getMod() - 1ULL;
    i32 cnt = 0;
    for (u64 i = 2ULL; i * i <= m; ++i)
      if (m % i == 0ULL) {
        tmp[cnt++] = i;
        do { m /= i; } while (m % i == 0ULL);
      }
    if (m != 1ULL) tmp[cnt++] = m;
    for (LongMontgomeryModInt res(2U);; res += LongMontgomeryModInt(1U)) {
      bool f = true;
      for (int i = 0; i < cnt && f; ++i) f &= res.pow((getMod() - 1ULL) / tmp[i]) != LongMontgomeryModInt(1U);
      if (f) return res.get();
    }
  }

  constexpr LongMontgomeryModInt() = default;

  ~LongMontgomeryModInt() = default;

  template <typename T, std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>> * = nullptr>
  explicit constexpr LongMontgomeryModInt(T v) : v_(reduce(
#ifdef __GNUC__
      static_cast<u128>(norm(v % static_cast<i64>(MOD))) * r2
#else
      ::lib::LongMontgomeryModInt<MOD>::umul(norm(v % static_cast<i64>(MOD)), r2)
#endif
  )) {}

  template <typename T, std::enable_if_t<std::is_integral_v<T> && std::is_unsigned_v<T>> * = nullptr>
  explicit constexpr LongMontgomeryModInt(T v) : v_(reduce(
#ifdef __GNUC__
      static_cast<u128>(v % MOD) * r2
#else
      ::lib::LongMontgomeryModInt<MOD>::umul(norm(v % MOD), r2)
#endif
  )) {}

  constexpr LongMontgomeryModInt(const LongMontgomeryModInt &) = default;

  [[nodiscard]] constexpr u64 get() const { return reduce(v_); }

  template <typename T, std::enable_if_t<std::is_integral_v<T>> * = nullptr>
  explicit constexpr operator T() const { return static_cast<T>(get()); }

  constexpr LongMontgomeryModInt operator-() const {
    LongMontgomeryModInt res;
    res.v_ = (MOD & -(v_ != 0ULL)) - v_;
    return res;
  }

  constexpr LongMontgomeryModInt inv() const {
    i64 x1 = 1LL, x3 = 0LL, a = static_cast<i64>(get()), b = static_cast<i64>(MOD);
    while (b != 0LL) {
      i64 q = a / b, x1_old = x1, a_old = a;
      x1 = x3, x3 = x1_old - x3 * q, a = b, b = a_old - b * q;
    }
    return LongMontgomeryModInt(x1);
  }

  constexpr LongMontgomeryModInt &operator=(const LongMontgomeryModInt &) = default;

  constexpr LongMontgomeryModInt &operator+=(const LongMontgomeryModInt &rhs) {
    v_ += rhs.v_ - MOD;
    v_ += MOD & -(v_ >> 63);
    return *this;
  }

  constexpr LongMontgomeryModInt &operator-=(const LongMontgomeryModInt &rhs) {
    v_ -= rhs.v_;
    v_ += MOD & -(v_ >> 63);
    return *this;
  }

  constexpr LongMontgomeryModInt &operator*=(const LongMontgomeryModInt &rhs) {
    v_ = reduce(
#ifdef __GNUC__
        static_cast<u128>(v_) * rhs.v_
#else
        ::lib::LongMontgomeryModInt<MOD>::umul(v_, rhs.v_)
#endif
    );
    return *this;
  }

  constexpr LongMontgomeryModInt &operator/=(const LongMontgomeryModInt &rhs) { return operator*=(rhs.inv()); }

  friend constexpr LongMontgomeryModInt operator+(const LongMontgomeryModInt &lhs, const LongMontgomeryModInt &rhs) {
    return LongMontgomeryModInt(lhs) += rhs;
  }

  friend constexpr LongMontgomeryModInt operator-(const LongMontgomeryModInt &lhs, const LongMontgomeryModInt &rhs) {
    return LongMontgomeryModInt(lhs) -= rhs;
  }

  friend constexpr LongMontgomeryModInt operator*(const LongMontgomeryModInt &lhs, const LongMontgomeryModInt &rhs) {
    return LongMontgomeryModInt(lhs) *= rhs;
  }

  friend constexpr LongMontgomeryModInt operator/(const LongMontgomeryModInt &lhs, const LongMontgomeryModInt &rhs) {
    return LongMontgomeryModInt(lhs) /= rhs;
  }

  friend constexpr bool operator==(const LongMontgomeryModInt &lhs, const LongMontgomeryModInt &rhs) {
    return lhs.v_ == rhs.v_;
  }

  friend constexpr bool operator!=(const LongMontgomeryModInt &lhs, const LongMontgomeryModInt &rhs) {
    return lhs.v_ != rhs.v_;
  }

  friend std::istream &operator>>(std::istream &is, LongMontgomeryModInt &rhs) {
    i64 x;
    is >> x;
    rhs = LongMontgomeryModInt(x);
    return is;
  }

  friend std::ostream &operator<<(std::ostream &os, const LongMontgomeryModInt &rhs) { return os << rhs.get(); }

  constexpr LongMontgomeryModInt pow(u64 y) const {
    for (LongMontgomeryModInt res(1U), x(*this);; x *= x) {
      if (y & 1) res *= x;
      if ((y >>= 1) == 0U) return res;
    }
  }

private:
  static constexpr u64 getR() {
    u64 two = 2ULL, iv = MOD * (two - MOD * MOD);
    iv *= two - MOD * iv;
    iv *= two - MOD * iv;
    iv *= two - MOD * iv;
    return iv * (two - MOD * iv);
  }

  static constexpr u64 getR2() {
    u64 iv = -MOD % MOD;
    for (int i = 0; i != 64; ++i) {
      if ((iv <<= 1) >= MOD) iv -= MOD;
    }
    return iv;
  }

#ifdef __GNUC__

  static constexpr u64 reduce(u128 x) {
    u64 res = static_cast<u64>(x >> 64) - static_cast<u64>(static_cast<u128>(static_cast<u64>(x) * r) * MOD >> 64);
    return res + (MOD & -(res >> 63));
  }

  static constexpr u64 reduce(u64 x) {
    u64 res = -static_cast<u64>(static_cast<u128>(x * r) * MOD >> 64);
    return res + (MOD & -(res >> 63));
  }

#else

  static constexpr std::pair<u64, u64> umul(u64 x, u64 y) {
    u64 a = x >> 32, b = static_cast<u32>(x), c = y >> 32, d = static_cast<u32>(y), ad = a * d, bc = b * c;
    return std::make_pair(
        a * c + (ad >> 32) + (bc >> 32) + (((ad & 0xFFFFFFFFU) + (bc & 0xFFFFFFFFU) + (b * d >> 32)) >> 32), x * y);
  }

  static constexpr u64 umulh(u64 x, u64 y) {
    u64 a = x >> 32, b = static_cast<u32>(x), c = y >> 32, d = static_cast<u32>(y), ad = a * d, bc = b * c;
    return a * c + (ad >> 32) + (bc >> 32) + (((ad & 0xFFFFFFFFU) + (bc & 0xFFFFFFFFU) + (b * d >> 32)) >> 32);
  }

  static constexpr u64 reduce(const std::pair<u64, u64> &x) {
    u64 res = x.first - ::lib::LongMontgomeryModInt<MOD>::umulh(x.second * r, MOD);
    return res + (MOD & -(res >> 63));
  }

  static constexpr u64 reduce(u64 x) {
    u64 res = -::lib::LongMontgomeryModInt<MOD>::umulh(x * r, MOD);
    return res + (MOD & -(res >> 63));
  }

#endif

  static constexpr u64 norm(i64 x) { return x + (MOD & -(x < 0)); }

  raw_type v_;

  static constexpr u64 r = getR();
  static constexpr u64 r2 = getR2();

  static_assert((MOD & 1ULL) == 1ULL, "MOD should be odd");
  static_assert(r * MOD == 1ULL, "unknown error");
  static_assert((MOD & (1ULL << 63)) == 0ULL, "MOD should be less than (1ULL << 63)");
  static_assert(MOD != 1ULL, "MOD should not be 1");
};
}

#ifndef fast_io
#define fast_io
#endif
#include "cstdio"
#include "string"
#include "cstring"
namespace fast_io {

constexpr int WTZ = 1 << 21;

char buf[WTZ], buff[WTZ], *t1 = buf, *t2 = buf, *HL = buff;

#define getc() (t1 == t2 && (t2 = (t1 = buf) + fread(buf, 1, WTZ, stdin), t1 == t2) ? EOF : *t1++)

inline void flush() noexcept {
	fwrite(buff, 1, HL - buff, stdout);
}

inline void putc(const char& ch) noexcept {
	if (HL == buff + WTZ) {
		flush();
		HL = buff;
	}
	*HL++ = ch;
}

class Istream {
public:
	template<typename _Tp> Istream& operator>> (_Tp &value) {
		char ch = getc();
		int flag = 0;
		value = 0;
		while (ch > '9' || ch < '0') {
			if (ch == '-') {
				flag = 1;
			}
			ch = getc();
		}
		while (ch <= '9' && ch >= '0') {
			value = value * 10 + (ch - '0');
			ch = getc();
		}
		value = flag ? -value : value;
		return *this;
	}	
	Istream& operator>> (char &ch) {
		ch = getc();
		while (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF) {
			ch = getc();
		}
		return *this;
	}
	Istream& operator>> (char str[]) {
		char ch = getc();
		int len = 0;
		while (ch == ' ' || ch == '\r' || ch == '\n' || ch == EOF) {
			ch = getc();
		}
		while (ch != ' ' && ch != '\r' && ch != '\n' && ch != EOF) {
			str[len++] = ch;
			ch = getc();
		} 
		str[len] = '\0';
		return *this;
	}
  Istream& operator>> (std::string& str) {
    char ch = getc();
    str.clear();
    while (ch == ' ' || ch == '\r' || ch == '\n' || ch == EOF) {
      ch = getc();
    }
    while ((ch != ' ' && ch != '\r' && ch != '\n' && ch != EOF) && str.size() <= str.max_size()) {
      str.append(1, ch);
      ch = getc();
    }
    return *this;
  }
};

class Ostream {
public:
  ~Ostream() noexcept {
    flush();
  }
	template<typename _Tp> Ostream& operator<< (_Tp value) {
		static char stk[20];
		unsigned int tp = 0;
		if (!value) {
			putc('0');
			return *this;
		}
		if (value < 0) {
			putc('-');
			value = -value;
		}
		while (value) {
			stk[++tp] = value % 10 + 48;
			value /= 10; 
		}
		while (tp) {
			putc(stk[tp--]);
		}
		return *this;
	}
	Ostream& operator<< (const char& ch) {
		putc(ch);
		return *this;
	}
	Ostream& operator<< (char str[]) {
		char *ch = str;
		while (*ch != '\0') {
			putc(*ch++);
		}
		return *this;
	}
	Ostream& operator<< (const char str[]) {
		const char *ch = str;
		while (*ch != '\0') {
			putc(*ch++);
		}
		return *this;
	}
	Ostream& operator<< (const std::string& str) {
		for (auto& it: str) {
      putc(it);
    }
    return *this;
	}
};

#undef getc
}


#ifdef Feicheng
#include "/home/feicheng/Program/Template/Other_Template/feicheng.hpp"
#endif
#include "bits/stdc++.h"

#define MT

constexpr int mod = 1'000'000'007;
constexpr int N = 1'000'005;
constexpr int I = (mod + 1) / 2;

using mint = lib::LazyMontgomeryModInt<mod>;

int n, m, k;

class Factorial {
  mint fac[N], ifac[N], pow2[N];
  int n;
public:
  Factorial() : n(1) {}
  void init(const int& _n) {
    if (_n < n) {
      return;
    }
    // debug(_n);
    // debug(n);
    fac[0] = mint(1);
    for (int i = n; i <= _n; ++i) {
      fac[i] = fac[i - 1] * static_cast<mint>(i);
    }
    ifac[_n] = fac[_n].inv();
    for (int i = _n; i >= n; --i) {
      ifac[i - 1] = ifac[i] * static_cast<mint>(i);
    }
    pow2[0] = mint(1);
    for (int i = n; i <= _n; ++i) {
      pow2[i] = pow2[i - 1] * static_cast<mint>(I);
    }
    n = _n;
  }
  mint Binom(const int& n, const int& m) {
    return n < m ? mint(0) : fac[n] * ifac[n - m] * ifac[m];
  }
  mint Pow(const int& n) {
    return pow2[n];
  } 
} Fac;

template<typename Read, typename Print> void solve(Read& in, Print& out) {
  in >> n >> m >> k;
  mint answer(0);
  if (n == m) {
    out << 1ll * m * k % mod << '\n';
    return;
  }
  Fac.init(n);
  for (int i = 1; i <= m; ++i) {
    answer += static_cast<mint>(i) * Fac.Binom(n - i - 1, m - i) * Fac.Pow(n - i);
  }
  answer *= mint(k);
  out << static_cast<int>(answer) << '\n';
}

int main(int argc, const char** argv) {
#ifndef fast_io  
  std::basic_ios<char>::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::istream& reader = std::cin;
  std::ostream& printer = std::cout;
#else 
  fast_io::Istream&& reader = fast_io::Istream();
  fast_io::Ostream&& printer = fast_io::Ostream();
#endif
#ifdef MT
  int t;
  for (reader >> t; t; --t) {
    solve(reader, printer);
  }
#else
  solve(reader, printer);
#endif
  return 0;
} 