






















namespace atcoder {

namespace internal {





int id12(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}





int bsf(unsigned int n) {

    unsigned long index;
    _BitScanForward(&index, n);
    return index;

    return __builtin_ctz(n);

}

}  


}  























namespace atcoder {

namespace internal {





constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}







struct barrett {
    unsigned int _m;
    unsigned long long im;

    

    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    

    unsigned int umod() const { return _m; }

    

    

    

    unsigned int mul(unsigned int a, unsigned int b) const {
        

        


        

        

        

        

        

        

        

        unsigned long long z = a;
        z *= b;

        unsigned long long x;
        _umul128(z, im, &x);

        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);

        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};







constexpr long long id36(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}









constexpr bool id30(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id36(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = id30(n);





constexpr std::pair<long long, long long> id6(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    

    

    

    

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  


        

        

        

        


        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    

    

    if (m0 < 0) m0 += b / s;
    return {s, m0};
}







constexpr int id22(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (id36(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id22(m);

}  


}  









namespace atcoder {

namespace internal {


template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;



template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;



template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  





namespace atcoder {

namespace internal {

struct id34 {};
struct static_modint_base : id34 {};

template <class T> using is_modint = std::is_base_of<id34, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  


template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct id29 : internal::static_modint_base {
    using mint = id29;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id29() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id29(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id29(T v) {
        _v = (unsigned int)(v % umod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::id6(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct id27 : internal::id34 {
    using mint = id27;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id27() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id27(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id27(T v) {
        _v = (unsigned int)(v % mod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::id6(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett id27<id>::bt = 998244353;

using modint998244353 = id29<998244353>;
using modint1000000007 = id29<1000000007>;
using modint = id27<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id27<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  





namespace atcoder {

namespace internal {

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void id9(std::vector<mint>& a) {
    static constexpr int g = internal::primitive_root<mint::mod()>;
    int n = int(a.size());
    int h = internal::id12(n);

    static bool first = true;
    static mint sum_e[30];  

    if (first) {
        first = false;
        mint es[30], ies[30];  

        int cnt2 = bsf(mint::mod() - 1);
        mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            

            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_e[i] = es[i] * now;
            now *= ies[i];
        }
    }
    for (int ph = 1; ph <= h; ph++) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint now = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p] * now;
                a[i + offset] = l + r;
                a[i + offset + p] = l - r;
            }
            now *= sum_e[bsf(~(unsigned int)(s))];
        }
    }
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void id26(std::vector<mint>& a) {
    static constexpr int g = internal::primitive_root<mint::mod()>;
    int n = int(a.size());
    int h = internal::id12(n);

    static bool first = true;
    static mint sum_ie[30];  

    if (first) {
        first = false;
        mint es[30], ies[30];  

        int cnt2 = bsf(mint::mod() - 1);
        mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            

            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_ie[i] = ies[i] * now;
            now *= es[i];
        }
    }

    for (int ph = h; ph >= 1; ph--) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint inow = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p];
                a[i + offset] = l + r;
                a[i + offset + p] =
                    (unsigned long long)(mint::mod() + l.val() - r.val()) *
                    inow.val();
            }
            inow *= sum_ie[bsf(~(unsigned int)(s))];
        }
    }
}

}  


template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(std::vector<mint> a, std::vector<mint> b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) {
        if (n < m) {
            std::swap(n, m);
            std::swap(a, b);
        }
        std::vector<mint> ans(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i + j] += a[i] * b[j];
            }
        }
        return ans;
    }
    int z = 1 << internal::id12(n + m - 1);
    a.resize(z);
    internal::id9(a);
    b.resize(z);
    internal::id9(b);
    for (int i = 0; i < z; i++) {
        a[i] *= b[i];
    }
    internal::id26(a);
    a.resize(n + m - 1);
    mint iz = mint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
}

template <unsigned int mod = 998244353,
          class T,
          std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    using mint = id29<mod>;
    std::vector<mint> a2(n), b2(m);
    for (int i = 0; i < n; i++) {
        a2[i] = mint(a[i]);
    }
    for (int i = 0; i < m; i++) {
        b2[i] = mint(b[i]);
    }
    auto c2 = convolution(move(a2), move(b2));
    std::vector<T> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        c[i] = c2[i].val();
    }
    return c;
}

std::vector<long long> id18(const std::vector<long long>& a,
                                      const std::vector<long long>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    static constexpr unsigned long long MOD1 = 754974721;  

    static constexpr unsigned long long MOD2 = 167772161;  

    static constexpr unsigned long long MOD3 = 469762049;  

    static constexpr unsigned long long id3 = MOD2 * MOD3;
    static constexpr unsigned long long id25 = MOD1 * MOD3;
    static constexpr unsigned long long id1 = MOD1 * MOD2;
    static constexpr unsigned long long id24 = MOD1 * MOD2 * MOD3;

    static constexpr unsigned long long i1 =
        internal::id6(MOD2 * MOD3, MOD1).second;
    static constexpr unsigned long long i2 =
        internal::id6(MOD1 * MOD3, MOD2).second;
    static constexpr unsigned long long i3 =
        internal::id6(MOD1 * MOD2, MOD3).second;

    auto c1 = convolution<MOD1>(a, b);
    auto c2 = convolution<MOD2>(a, b);
    auto c3 = convolution<MOD3>(a, b);

    std::vector<long long> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        unsigned long long x = 0;
        x += (c1[i] * i1) % MOD1 * id3;
        x += (c2[i] * i2) % MOD2 * id25;
        x += (c3[i] * i3) % MOD3 * id1;
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        long long diff =
            c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
        if (diff < 0) diff += MOD1;
        static constexpr unsigned long long offset[5] = {
            0, 0, id24, 2 * id24, 3 * id24};
        x -= offset[diff % 5];
        c[i] = x;
    }

    return c;
}

}  






















namespace std {

template <typename _Tp> constexpr _Tp id15(_Tp __x, int __s) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  const int __r = __s % _Nd;
  if (__r == 0)
    return __x;
  else if (__r > 0)
    return (__x << __r) | (__x >> ((_Nd - __r) % _Nd));
  else
    return (__x >> -__r) | (__x << ((_Nd + __r) % _Nd));  

}

template <typename _Tp> constexpr _Tp id28(_Tp __x, int __s) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  const int __r = __s % _Nd;
  if (__r == 0)
    return __x;
  else if (__r > 0)
    return (__x >> __r) | (__x << ((_Nd - __r) % _Nd));
  else
    return (__x << -__r) | (__x >> ((_Nd + __r) % _Nd));  

}

template <typename _Tp> constexpr int id2(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id20 = numeric_limits<unsigned long long>::digits;
  constexpr auto id33 = numeric_limits<unsigned long>::digits;
  constexpr auto id21 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id21) {
    constexpr int __diff = id21 - _Nd;
    return __builtin_clz(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= id33) {
    constexpr int __diff = id33 - _Nd;
    return __builtin_clzl(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= id20) {
    constexpr int __diff = id20 - _Nd;
    return __builtin_clzll(__x) - __diff;
  } else  

  {
    static_assert(_Nd <= (2 * id20),
                  "Maximum supported integer size is 128-bit");

    unsigned long long __high = __x >> id20;
    if (__high != 0) {
      constexpr int __diff = (2 * id20) - _Nd;
      return __builtin_clzll(__high) - __diff;
    }
    constexpr auto id19 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id19;
    return (_Nd - id20) + __builtin_clzll(__low);
  }
}

template <typename _Tp> constexpr int id10(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return id2<_Tp>((_Tp)~__x);
}

template <typename _Tp> constexpr int id37(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id20 = numeric_limits<unsigned long long>::digits;
  constexpr auto id33 = numeric_limits<unsigned long>::digits;
  constexpr auto id21 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id21)
    return __builtin_ctz(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id33)
    return __builtin_ctzl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id20)
    return __builtin_ctzll(__x);
  else  

  {
    static_assert(_Nd <= (2 * id20),
                  "Maximum supported integer size is 128-bit");

    constexpr auto id19 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id19;
    if (__low != 0) return __builtin_ctzll(__low);
    unsigned long long __high = __x >> id20;
    return __builtin_ctzll(__high) + id20;
  }
}

template <typename _Tp> constexpr int id8(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return id37((_Tp)~__x);
}

template <typename _Tp> constexpr int id5(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return 0;

  constexpr auto id20 = numeric_limits<unsigned long long>::digits;
  constexpr auto id33 = numeric_limits<unsigned long>::digits;
  constexpr auto id21 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id21)
    return __builtin_popcount(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id33)
    return __builtin_popcountl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id20)
    return __builtin_popcountll(__x);
  else  

  {
    static_assert(_Nd <= (2 * id20),
                  "Maximum supported integer size is 128-bit");

    constexpr auto id19 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id19;
    unsigned long long __high = __x >> id20;
    return __builtin_popcountll(__low) + __builtin_popcountll(__high);
  }
}

template <typename _Tp> constexpr bool id7(_Tp __x) noexcept {
  return id5(__x) == 1;
}

template <typename _Tp> constexpr _Tp id35(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0 || __x == 1) return 1;
  auto id11 = _Nd - id2((_Tp)(__x - 1u));

  if (!__builtin_is_constant_evaluated()) {
    __glibcxx_assert(id11 != numeric_limits<_Tp>::digits);
  }

  using __promoted_type = decltype(__x << 1);
  if _GLIBCXX17_CONSTEXPR (!is_same<__promoted_type, _Tp>::value) {
    const int id4 = sizeof(__promoted_type) / sizeof(_Tp) / 2;
    id11 |= (id11 & _Nd) << id4;
  }
  return (_Tp)1u << id11;
}

template <typename _Tp> constexpr _Tp id31(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0) return 0;
  return (_Tp)1u << (_Nd - id2((_Tp)(__x >> 1)));
}

template <typename _Tp> constexpr _Tp id23(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  return _Nd - id2(__x);
}

}  







namespace workspace {

constexpr char eol = '\n';

using namespace std;

using i32 = int_least32_t;
using u32 = uint_least32_t;
using i64 = int_least64_t;
using u64 = uint_least64_t;


using i128 = __int128_t;
using u128 = __uint128_t;




template <class T, class Comp = less<T>>
using priority_queue = std::priority_queue<T, vector<T>, Comp>;

template <class T> using stack = std::stack<T, vector<T>>;

template <typename _Tp> constexpr _Tp id17(_Tp __x) noexcept {
  return std::id37(__x);
}

template <typename _Tp> constexpr _Tp id14(_Tp __x) noexcept {
  return std::id23(__x) - 1;
}

}  























namespace std {



template <> struct make_signed<__uint128_t> { using type = __int128_t; };
template <> struct make_signed<__int128_t> { using type = __int128_t; };

template <> struct make_unsigned<__uint128_t> { using type = __uint128_t; };
template <> struct make_unsigned<__int128_t> { using type = __uint128_t; };



}  


namespace workspace {

template <class type, template <class> class trait>
using enable_if_trait_type = typename std::enable_if<trait<type>::value>::type;

template <class Container>
using element_type = typename std::decay<decltype(
    *std::begin(std::declval<Container&>()))>::type;

template <class T, class = std::nullptr_t>
struct has_begin : std::false_type {};

template <class T>
struct has_begin<T, decltype(std::begin(std::declval<T>()), nullptr)>
    : std::true_type {};

template <class T, class = int> struct mapped_of {
  using type = element_type<T>;
};
template <class T>
struct mapped_of<T,
                 typename std::pair<int, typename T::mapped_type>::first_type> {
  using type = typename T::mapped_type;
};
template <class T> using mapped_type = typename mapped_of<T>::type;

template <class T, class = void> struct is_integral_ext : std::false_type {};
template <class T>
struct is_integral_ext<
    T, typename std::enable_if<std::is_integral<T>::value>::type>
    : std::true_type {};



template <> struct is_integral_ext<__int128_t> : std::true_type {};
template <> struct is_integral_ext<__uint128_t> : std::true_type {};





template <class T>
constexpr static bool id0 = is_integral_ext<T>::value;



template <typename T, typename = void> struct multiplicable_uint {
  using type = uint_least32_t;
};
template <typename T>
struct multiplicable_uint<
    T, typename std::enable_if<(2 < sizeof(T)) &&
                               (!__INT128_DEFINED__ || sizeof(T) <= 4)>::type> {
  using type = uint_least64_t;
};



template <typename T>
struct multiplicable_uint<T, typename std::enable_if<(4 < sizeof(T))>::type> {
  using type = __uint128_t;
};



template <typename T> struct multiplicable_int {
  using type =
      typename std::make_signed<typename multiplicable_uint<T>::type>::type;
};

}  



namespace workspace {

namespace internal {


template <auto Mod, unsigned Storage> struct id34 {
  static_assert(is_integral_ext<decltype(Mod)>::value,
                "Mod must be integral type.");

  using mod_type = typename std::make_signed<typename std::conditional<
      0 < Mod, typename std::add_const<decltype(Mod)>::type,
      decltype(Mod)>::type>::type;

  using value_type = typename std::decay<mod_type>::type;

  using mul_type = typename multiplicable_uint<value_type>::type;

  static mod_type mod;

  static value_type storage;

  constexpr static void reserve(unsigned __n) noexcept { storage = __n; }

 protected:
  value_type value = 0;

 public:
  constexpr id34() noexcept = default;

  template <class int_type,
            typename std::enable_if<is_integral_ext<int_type>::value>::type * =
                nullptr>
  constexpr id34(int_type n) noexcept
      : value((n %= mod) < 0 ? n += mod : n) {}

  constexpr id34(bool n) noexcept : value(n) {}

  constexpr operator value_type() const noexcept { return value; }

  constexpr static id34 one() noexcept { return 1; }

  

  constexpr id34 operator++(int) noexcept {
    id34 __t{*this};
    operator++();
    return __t;
  }

  constexpr id34 operator--(int) noexcept {
    id34 __t{*this};
    operator--();
    return __t;
  }

  constexpr id34 &operator++() noexcept {
    if (++value == mod) value = 0;
    return *this;
  }

  constexpr id34 &operator--() noexcept {
    if (!value) value = mod;
    --value;
    return *this;
  }

  constexpr id34 operator-() const noexcept {
    id34 __t;
    __t.value = value ? mod - value : 0;
    return __t;
  }

  


  


  constexpr id34 &operator+=(id34 const &rhs) noexcept {
    if ((value += rhs.value) >= mod) value -= mod;
    return *this;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id34>::type &
  operator+=(int_type const &rhs) noexcept {
    if (((value += rhs) %= mod) < 0) value += mod;
    return *this;
  }

  


  


  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id34>::type
  operator+(int_type const &rhs) const noexcept {
    return id34{*this} += rhs;
  }

  constexpr id34 operator+(id34 rhs) const noexcept {
    return rhs += *this;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           id34>::type
  operator+(int_type const &lhs, id34 rhs) noexcept {
    return rhs += lhs;
  }

  


  


  constexpr id34 &operator-=(id34 const &rhs) noexcept {
    if ((value -= rhs.value) < 0) value += mod;
    return *this;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id34>::type &
  operator-=(int_type rhs) noexcept {
    if (((value -= rhs) %= mod) < 0) value += mod;
    return *this;
  }

  


  


  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id34>::type
  operator-(int_type const &rhs) const noexcept {
    return id34{*this} -= rhs;
  }

  constexpr id34 operator-(id34 const &rhs) const noexcept {
    id34 __t;
    if (((__t.value = value) -= rhs.value) < 0) __t.value += mod;
    return __t;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           id34>::type
  operator-(int_type lhs, id34 const &rhs) noexcept {
    if (((lhs -= rhs.value) %= mod) < 0) lhs += mod;
    id34 __t;
    __t.value = lhs;
    return __t;
  }

  


  


  constexpr id34 &operator*=(id34 const &rhs) noexcept {
    if (!rhs.value)
      value = 0;
    else if (value) {
      mul_type __r(value);
      value = static_cast<value_type>((__r *= rhs.value) %= mod);
    }
    return *this;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id34>::type &
  operator*=(int_type rhs) noexcept {
    if (!rhs)
      value = 0;
    else if (value) {
      if ((rhs %= mod) < 0) rhs += mod;
      mul_type __r(value);
      value = static_cast<value_type>((__r *= rhs) %= mod);
    }
    return *this;
  }

  


  


  constexpr id34 operator*(id34 const &rhs) const noexcept {
    if (!value or !rhs.value) return {};
    mul_type __r(value);
    id34 __t;
    __t.value = static_cast<value_type>((__r *= rhs.value) %= mod);
    return __t;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id34>::type
  operator*(int_type rhs) const noexcept {
    if (!value or !rhs) return {};
    if ((rhs %= mod) < 0) rhs += mod;
    mul_type __r(value);
    id34 __t;
    __t.value = static_cast<value_type>((__r *= rhs) %= mod);
    return __t;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           id34>::type
  operator*(int_type lhs, id34 const &rhs) noexcept {
    if (!lhs or !rhs.value) return {};
    if ((lhs %= mod) < 0) lhs += mod;
    mul_type __r(lhs);
    id34 __t;
    __t.value = (__r *= rhs.value) %= mod;
    return __t;
  }

  


 protected:
  static value_type _mem(value_type __x) {
    static std::vector<value_type> __m{0, 1};
    static value_type __i = (__m.reserve(Storage), 1);
    while (__i < __x) {
      ++__i;
      __m.emplace_back(mod - mul_type(mod / __i) * __m[mod % __i] % mod);
    }
    return __m[__x];
  }

  template <class int_type>
  constexpr static typename std::enable_if<is_integral_ext<int_type>::value,
                                           value_type>::type
  _div(mul_type __r, int_type __x) noexcept {
    assert(__x);
    if (!__r) return 0;
    int_type __v{};
    bool __neg = __x < 0 ? __x = -__x, true : false;
    if (__x < storage)
      __v = _mem(__x);
    else {
      int_type __y{mod}, __u{1}, __t;
      while (__x)
        __t = __y / __x, __y ^= __x ^= (__y -= __t * __x) ^= __x,
        __v ^= __u ^= (__v -= __t * __u) ^= __u;
      if (__y < 0) __neg ^= 1;
    }
    if (__neg)
      __v = 0 < __v ? mod - __v : -__v;
    else if (__v < 0)
      __v += mod;
    if (__r == 1) return static_cast<value_type>(__v);
    return static_cast<value_type>((__r *= __v) %= mod);
  }

 public:
  


  constexpr id34 &operator/=(id34 const &rhs) noexcept {
    if (value) value = _div(value, rhs.value);
    return *this;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id34>::type &
  operator/=(int_type rhs) noexcept {
    if (value) value = _div(value, rhs %= mod);
    return *this;
  }

  


  


  constexpr id34 operator/(id34 const &rhs) const noexcept {
    if (!value) return {};
    id34 __t;
    __t.value = _div(value, rhs.value);
    return __t;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id34>::type
  operator/(int_type rhs) const noexcept {
    if (!value) return {};
    id34 __t;
    __t.value = _div(value, rhs %= mod);
    return __t;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           id34>::type
  operator/(int_type lhs, id34 const &rhs) noexcept {
    if (!lhs) return {};
    if ((lhs %= mod) < 0) lhs += mod;
    id34 __t;
    __t.value = _div(lhs, rhs.value);
    return __t;
  }

  


  constexpr id34 inv() const noexcept { return _div(1, value); }

  template <class int_type>
  friend constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                           id34>::type
  pow(id34 b, int_type e) noexcept {
    if (e < 0) {
      e = -e;
      b.value = _div(1, b.value);
    }
    id34 __r;
    for (__r.value = 1; e; e >>= 1, b *= b)
      if (e & 1) __r *= b;
    return __r;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    id34>::type
  pow(int_type e) const noexcept {
    id34 __r, b;
    __r.value = 1;
    for (b.value = e < 0 ? e = -e, _div(1, value) : value; e; e >>= 1, b *= b)
      if (e & 1) __r *= b;
    return __r;
  }

  friend std::ostream &operator<<(std::ostream &os,
                                  const id34 &rhs) noexcept {
    return os << rhs.value;
  }

  friend std::istream &operator>>(std::istream &is, id34 &rhs) noexcept {
    intmax_t value;
    rhs = (is >> value, value);
    return is;
  }
};

template <auto Mod, unsigned Storage>
typename id34<Mod, Storage>::mod_type id34<Mod, Storage>::mod =
    Mod > 0 ? Mod : 0;

template <auto Mod, unsigned Storage>
typename id34<Mod, Storage>::value_type
    id34<Mod, Storage>::storage = Storage;

}  



template <auto Mod, unsigned Storage = 0,
          typename std::enable_if<(Mod > 0)>::type * = nullptr>
using modint = internal::id34<Mod, Storage>;


template <unsigned type_id = 0, unsigned Storage = 0>
using modint_runtime = internal::id34<-(signed)type_id, Storage>;




}  







namespace workspace {

template <class Tp> Tp factorial(int_fast32_t __x) noexcept {
  if (__x < 0) return 0;
  static std::vector<Tp> __t{1};
  static int_fast32_t __i = (__t.reserve(0x1000000), 0);
  while (__i < __x) {
    ++__i;
    __t.emplace_back(__t.back() * __i);
  }
  return __t[__x];
}

template <class Tp> Tp id16(int_fast32_t __x) noexcept {
  if (__x < 0) return 0;
  static std::vector<Tp> __t{1};
  static int_fast32_t __i = (__t.reserve(0x1000000), 0);
  while (__i < __x) {
    ++__i;
    __t.emplace_back(__t.back() / __i);
  }
  return __t[__x];
}

}  



namespace workspace {


template <class Tp> Tp binomial(int_fast32_t __x, int_fast32_t __y) {
  if (!__y) return 1;
  if (__y < 0 || __x < __y) return 0;
  return factorial<Tp>(__x) * id16<Tp>(__y) *
         id16<Tp>(__x - __y);
}

}  


















namespace std {

template <typename _Tp> constexpr _Tp id15(_Tp __x, int __s) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  const int __r = __s % _Nd;
  if (__r == 0)
    return __x;
  else if (__r > 0)
    return (__x << __r) | (__x >> ((_Nd - __r) % _Nd));
  else
    return (__x >> -__r) | (__x << ((_Nd + __r) % _Nd));  

}

template <typename _Tp> constexpr _Tp id28(_Tp __x, int __s) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  const int __r = __s % _Nd;
  if (__r == 0)
    return __x;
  else if (__r > 0)
    return (__x >> __r) | (__x << ((_Nd - __r) % _Nd));
  else
    return (__x << -__r) | (__x >> ((_Nd + __r) % _Nd));  

}

template <typename _Tp> constexpr int id2(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id20 = numeric_limits<unsigned long long>::digits;
  constexpr auto id33 = numeric_limits<unsigned long>::digits;
  constexpr auto id21 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id21) {
    constexpr int __diff = id21 - _Nd;
    return __builtin_clz(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= id33) {
    constexpr int __diff = id33 - _Nd;
    return __builtin_clzl(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= id20) {
    constexpr int __diff = id20 - _Nd;
    return __builtin_clzll(__x) - __diff;
  } else  

  {
    static_assert(_Nd <= (2 * id20),
                  "Maximum supported integer size is 128-bit");

    unsigned long long __high = __x >> id20;
    if (__high != 0) {
      constexpr int __diff = (2 * id20) - _Nd;
      return __builtin_clzll(__high) - __diff;
    }
    constexpr auto id19 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id19;
    return (_Nd - id20) + __builtin_clzll(__low);
  }
}

template <typename _Tp> constexpr int id10(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return id2<_Tp>((_Tp)~__x);
}

template <typename _Tp> constexpr int id37(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto id20 = numeric_limits<unsigned long long>::digits;
  constexpr auto id33 = numeric_limits<unsigned long>::digits;
  constexpr auto id21 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id21)
    return __builtin_ctz(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id33)
    return __builtin_ctzl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id20)
    return __builtin_ctzll(__x);
  else  

  {
    static_assert(_Nd <= (2 * id20),
                  "Maximum supported integer size is 128-bit");

    constexpr auto id19 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id19;
    if (__low != 0) return __builtin_ctzll(__low);
    unsigned long long __high = __x >> id20;
    return __builtin_ctzll(__high) + id20;
  }
}

template <typename _Tp> constexpr int id8(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return id37((_Tp)~__x);
}

template <typename _Tp> constexpr int id5(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return 0;

  constexpr auto id20 = numeric_limits<unsigned long long>::digits;
  constexpr auto id33 = numeric_limits<unsigned long>::digits;
  constexpr auto id21 = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= id21)
    return __builtin_popcount(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id33)
    return __builtin_popcountl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= id20)
    return __builtin_popcountll(__x);
  else  

  {
    static_assert(_Nd <= (2 * id20),
                  "Maximum supported integer size is 128-bit");

    constexpr auto id19 = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & id19;
    unsigned long long __high = __x >> id20;
    return __builtin_popcountll(__low) + __builtin_popcountll(__high);
  }
}

template <typename _Tp> constexpr bool id7(_Tp __x) noexcept {
  return id5(__x) == 1;
}

template <typename _Tp> constexpr _Tp id35(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0 || __x == 1) return 1;
  auto id11 = _Nd - id2((_Tp)(__x - 1u));

  if (!__builtin_is_constant_evaluated()) {
    __glibcxx_assert(id11 != numeric_limits<_Tp>::digits);
  }

  using __promoted_type = decltype(__x << 1);
  if _GLIBCXX17_CONSTEXPR (!is_same<__promoted_type, _Tp>::value) {
    const int id4 = sizeof(__promoted_type) / sizeof(_Tp) / 2;
    id11 |= (id11 & _Nd) << id4;
  }
  return (_Tp)1u << id11;
}

template <typename _Tp> constexpr _Tp id31(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0) return 0;
  return (_Tp)1u << (_Nd - id2((_Tp)(__x >> 1)));
}

template <typename _Tp> constexpr _Tp id23(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  return _Nd - id2(__x);
}

}  












namespace std {


template <typename _Tp, typename _Alloc, typename _Predicate>
inline typename vector<_Tp, _Alloc>::size_type erase_if(
    vector<_Tp, _Alloc>& __cont, _Predicate __pred) {
  const auto id13 = __cont.size();
  __cont.erase(remove_if(__cont.begin(), __cont.end(), __pred), __cont.end());
  return id13 - __cont.size();
}


template <typename _Tp, typename _Alloc, typename _Up>
inline typename vector<_Tp, _Alloc>::size_type erase(
    vector<_Tp, _Alloc>& __cont, const _Up& __value) {
  const auto id13 = __cont.size();
  __cont.erase(remove(__cont.begin(), __cont.end(), __value), __cont.end());
  return id13 - __cont.size();
}

}  

































namespace workspace {


template <class Iterator>
class reverse_iterator : public std::reverse_iterator<Iterator> {
  using base_std = std::reverse_iterator<Iterator>;
  std::optional<typename base_std::value_type> deref;

 public:
  using base_std::reverse_iterator;

  constexpr typename base_std::reference operator*() noexcept {
    if (!deref) {
      Iterator tmp = base_std::current;
      deref = *--tmp;
    }
    return deref.value();
  }

  constexpr reverse_iterator &operator++() noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator &operator--() noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator operator++(int) noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator operator--(int) noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
};

}  










namespace workspace {

namespace internal {

template <class Container> class reversed {
  Container cont;

 public:
  constexpr reversed(Container &&cont) : cont(cont) {}

  constexpr auto begin() { return std::rbegin(cont); }
  constexpr auto end() { return std::rend(cont); }
};

}  


template <class Container> constexpr auto reversed(Container &&cont) noexcept {
  return internal::reversed<Container>{std::forward<Container>(cont)};
}

template <class Tp>
constexpr auto reversed(std::initializer_list<Tp> &&cont) noexcept {
  return internal::reversed<std::initializer_list<Tp>>{
      std::forward<std::initializer_list<Tp>>(cont)};
}

}  





namespace workspace {

template <class Index> class range {
  Index first, last;

 public:
  class iterator {
    Index current;

   public:
    using difference_type = std::ptrdiff_t;
    using value_type = Index;
    using reference = typename std::add_const<Index>::type &;
    using pointer = iterator;
    using iterator_category = std::bidirectional_iterator_tag;

    constexpr iterator(Index const &__i = Index()) noexcept : current(__i) {}

    constexpr bool operator==(iterator const &rhs) const noexcept {
      return current == rhs.current;
    }
    constexpr bool operator!=(iterator const &rhs) const noexcept {
      return current != rhs.current;
    }

    constexpr iterator &operator++() noexcept {
      ++current;
      return *this;
    }
    constexpr iterator &operator--() noexcept {
      --current;
      return *this;
    }

    constexpr reference operator*() const noexcept { return current; }
  };

  constexpr range(Index first, Index last) noexcept
      : first(first), last(last) {}
  constexpr range(Index last) noexcept : first(), last(last) {}

  constexpr iterator begin() const noexcept { return iterator{first}; }
  constexpr iterator end() const noexcept { return iterator{last}; }

  constexpr reverse_iterator<iterator> rbegin() const noexcept {
    return reverse_iterator<iterator>(end());
  }
  constexpr reverse_iterator<iterator> rend() const noexcept {
    return reverse_iterator<iterator>(begin());
  }
};

template <class... Args> constexpr auto rrange(Args &&... args) noexcept {
  return internal::reversed(range(std::forward<Args>(args)...));
}

}  















namespace workspace {


template <class Tuple, size_t N = std::tuple_size<Tuple>::value - 1>
struct common_iterator_category {
  using type = typename std::common_type<
      typename common_iterator_category<Tuple, N - 1>::type,
      typename std::iterator_traits<typename std::tuple_element<
          N, Tuple>::type>::iterator_category>::type;
};

template <class Tuple> struct common_iterator_category<Tuple, 0> {
  using type = typename std::iterator_traits<
      typename std::tuple_element<0, Tuple>::type>::iterator_category;
};

}  





namespace workspace {

namespace internal {

template <class> struct id32;

template <class...> struct zipped_iterator_tuple;

template <class... Args> class zipped {
  using ref_tuple = std::tuple<Args...>;
  ref_tuple args;

  template <size_t N = 0> constexpr auto begin_cat() const noexcept {
    if constexpr (N != std::tuple_size<ref_tuple>::value) {
      return std::tuple_cat(std::tuple(std::begin(std::get<N>(args))),
                            begin_cat<N + 1>());
    } else
      return std::tuple<>();
  }

  template <size_t N = 0> constexpr auto end_cat() const noexcept {
    if constexpr (N != std::tuple_size<ref_tuple>::value) {
      return std::tuple_cat(std::tuple(std::end(std::get<N>(args))),
                            end_cat<N + 1>());
    } else
      return std::tuple<>();
  }

 public:
  constexpr zipped(Args &&... args) noexcept : args(args...) {}

  class iterator {
    using base_tuple = typename zipped_iterator_tuple<Args...>::type;

   public:
    using iterator_category =
        typename common_iterator_category<base_tuple>::type;
    using difference_type = std::ptrdiff_t;
    using value_type = id32<base_tuple>;
    using reference = id32<base_tuple> &;
    using pointer = iterator;

   protected:
    value_type current;

    template <size_t N = 0>
    constexpr bool equal(const iterator &rhs) const noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        return std::get<N>(current) == std::get<N>(rhs.current) ||
               equal<N + 1>(rhs);
      } else
        return false;
    }

    template <size_t N = 0> constexpr void increment() noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        ++std::get<N>(current);
        increment<N + 1>();
      }
    }

    template <size_t N = 0> constexpr void decrement() noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        --std::get<N>(current);
        decrement<N + 1>();
      }
    }

    template <size_t N = 0>
    constexpr void advance(difference_type __d) noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        std::get<N>(current) += __d;
        advance<N + 1>(__d);
      }
    }

   public:
    constexpr iterator() noexcept = default;
    constexpr iterator(base_tuple const &current) noexcept : current(current) {}

    constexpr bool operator==(const iterator &rhs) const noexcept {
      return equal(rhs);
    }
    constexpr bool operator!=(const iterator &rhs) const noexcept {
      return !equal(rhs);
    }

    constexpr iterator &operator++() noexcept {
      increment();
      return *this;
    }
    constexpr iterator &operator--() noexcept {
      decrement();
      return *this;
    }

    constexpr bool operator<(const iterator &rhs) const noexcept {
      return std::get<0>(current) < std::get<0>(rhs.current);
    }

    constexpr bool operator<=(const iterator &rhs) const noexcept {
      return std::get<0>(current) <= std::get<0>(rhs.current);
    }

    constexpr iterator &operator+=(difference_type __d) noexcept {
      advance(__d);
      return *this;
    }

    constexpr iterator &operator-=(difference_type __d) noexcept {
      advance(-__d);
      return *this;
    }

    constexpr iterator operator+(difference_type __d) const noexcept {
      return iterator{*this} += __d;
    }

    constexpr iterator operator-(difference_type __d) const noexcept {
      return iterator{*this} -= __d;
    }

    constexpr difference_type operator-(const iterator &rhs) const noexcept {
      return std::get<0>(current) - std::get<0>(rhs.current);
    }

    constexpr reference operator*() noexcept { return current; }
  };

  constexpr iterator begin() const noexcept { return iterator{begin_cat()}; }
  constexpr iterator end() const noexcept { return iterator{end_cat()}; }

  constexpr reverse_iterator<iterator> rbegin() const noexcept {
    return reverse_iterator<iterator>{end()};
  }
  constexpr reverse_iterator<iterator> rend() const noexcept {
    return reverse_iterator<iterator>{begin()};
  }
};

template <class Tp, class... Args> struct zipped_iterator_tuple<Tp, Args...> {
  using type = decltype(std::tuple_cat(
      std::declval<std::tuple<decltype(std::begin(std::declval<Tp>()))>>(),
      std::declval<typename zipped_iterator_tuple<Args...>::type>()));
};

template <> struct zipped_iterator_tuple<> { using type = std::tuple<>; };

template <class Iter_tuple> struct id32 : Iter_tuple {
  constexpr id32(Iter_tuple const &__t) noexcept
      : Iter_tuple::tuple(__t) {}

  constexpr id32(id32 const &__t) = default;

  constexpr id32 &operator=(id32 const &__t) = default;

  

  constexpr id32(id32 &&__t)
      : id32(static_cast<id32 const &>(__t)) {}

  

  id32 &operator=(id32 &&__t) {
    return operator=(static_cast<id32 const &>(__t));
  }

  template <size_t N>
  friend constexpr auto &get(id32<Iter_tuple> const &__z) noexcept {
    return *std::get<N>(__z);
  }

  template <size_t N>
  friend constexpr auto get(id32<Iter_tuple> &&__z) noexcept {
    return *std::get<N>(__z);
  }
};

}  


}  


namespace std {

template <size_t N, class Iter_tuple>
struct tuple_element<N, workspace::internal::id32<Iter_tuple>> {
  using type = typename remove_reference<typename iterator_traits<
      typename tuple_element<N, Iter_tuple>::type>::reference>::type;
};

template <class Iter_tuple>
struct tuple_size<workspace::internal::id32<Iter_tuple>>
    : tuple_size<Iter_tuple> {};

}  


namespace workspace {

template <class... Args> constexpr auto zip(Args &&... args) noexcept {
  return internal::zipped<Args...>(std::forward<Args>(args)...);
}

template <class... Args>
constexpr auto zip(std::initializer_list<Args> const &... args) noexcept {
  return internal::zipped<const std::initializer_list<Args>...>(args...);
}

}  







namespace workspace {

constexpr size_t min_size() noexcept { return SIZE_MAX; }

template <class Container, class... Args>
constexpr size_t min_size(Container const &cont, Args &&... args) noexcept {
  return std::min(std::size(cont), min_size(std::forward<Args>(args)...));
}

template <class... Args> constexpr auto enumerate(Args &&... args) noexcept {
  return zip(range(min_size(args...)), std::forward<Args>(args)...);
}

template <class... Args>
constexpr auto enumerate(std::initializer_list<Args> const &... args) noexcept {
  return zip(range(min_size(args...)), std::vector(args)...);
}

}  





namespace workspace {

using mint = atcoder::modint998244353;
using mint2 = modint<998244353>;
auto bi = binomial<mint2>;

void main() {
  


  int n;
  cin >> n;
  vector<mint> v{1};
  int w = 1;
  for (auto i : range(n)) {
    int a, b;
    cin >> a >> b;
    auto w2 = w + a - b;
    vector<mint> bv(w + w2);
    for (auto &&[j, e] : enumerate(bv)) {
      e = (int)bi(a + b, b + j - w);
    }
    v = atcoder::convolution(v, bv);
    rotate(begin(v), begin(v) + w, end(v));
    v.resize(w2);
    w = w2;
  }

  mint sum;
  for (auto &&x : v) {
    sum += x;
  }
  cout << sum.val() << "\n";
}

}  


int main() { workspace::main(); }
