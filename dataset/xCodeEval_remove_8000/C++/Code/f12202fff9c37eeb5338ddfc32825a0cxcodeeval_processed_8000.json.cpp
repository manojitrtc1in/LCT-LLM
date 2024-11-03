



























































namespace atcoder {

namespace internal {

int id6(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int id7(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
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

    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

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

constexpr long long id22(long long x, long long n, int m) {
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

constexpr bool id21(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id22(a, t, n);
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
template <int n> constexpr bool is_prime = id21(n);

constexpr std::pair<long long, long long> id3(long long a, long long b) {
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

constexpr int id13(int m) {
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
            if (id22(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id13(m);

unsigned long long id2(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

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

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  


template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct id20 : internal::static_modint_base {
    using mint = id20;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id20() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id20(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id20(T v) {
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
            auto eg = internal::id3(_v, m);
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

template <int id> struct id18 : internal::modint_base {
    using mint = id18;

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

    id18() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id18(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id18(T v) {
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
        auto eg = internal::id3(_v, mod());
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
template <int id> internal::barrett id18<id>::bt(998244353);

using modint998244353 = id20<998244353>;
using modint1000000007 = id20<1000000007>;
using modint = id18<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id18<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  



namespace atcoder {

namespace internal {

template <class mint,
          int g = internal::primitive_root<mint::mod()>,
          internal::is_static_modint_t<mint>* = nullptr>
struct fft_info {
    static constexpr int rank2 = id7(mint::mod() - 1);
    std::array<mint, rank2 + 1> root;   

    std::array<mint, rank2 + 1> iroot;  


    std::array<mint, std::max(0, rank2 - 2 + 1)> rate2;
    std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;

    std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;
    std::array<mint, std::max(0, rank2 - 3 + 1)> irate3;

    fft_info() {
        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);
        iroot[rank2] = root[rank2].inv();
        for (int i = rank2 - 1; i >= 0; i--) {
            root[i] = root[i + 1] * root[i + 1];
            iroot[i] = iroot[i + 1] * iroot[i + 1];
        }

        {
            mint prod = 1, iprod = 1;
            for (int i = 0; i <= rank2 - 2; i++) {
                rate2[i] = root[i + 2] * prod;
                irate2[i] = iroot[i + 2] * iprod;
                prod *= iroot[i + 2];
                iprod *= root[i + 2];
            }
        }
        {
            mint prod = 1, iprod = 1;
            for (int i = 0; i <= rank2 - 3; i++) {
                rate3[i] = root[i + 3] * prod;
                irate3[i] = iroot[i + 3] * iprod;
                prod *= iroot[i + 3];
                iprod *= root[i + 3];
            }
        }
    }
};

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void id4(std::vector<mint>& a) {
    int n = int(a.size());
    int h = internal::id6(n);

    static const fft_info<mint> info;

    int len = 0;  

    while (len < h) {
        if (h - len == 1) {
            int p = 1 << (h - len - 1);
            mint rot = 1;
            for (int s = 0; s < (1 << len); s++) {
                int offset = s << (h - len);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p] * rot;
                    a[i + offset] = l + r;
                    a[i + offset + p] = l - r;
                }
                if (s + 1 != (1 << len))
                    rot *= info.rate2[bsf(~(unsigned int)(s))];
            }
            len++;
        } else {
            int p = 1 << (h - len - 2);
            mint rot = 1, imag = info.root[2];
            for (int s = 0; s < (1 << len); s++) {
                mint rot2 = rot * rot;
                mint rot3 = rot2 * rot;
                int offset = s << (h - len);
                for (int i = 0; i < p; i++) {
                    auto mod2 = 1ULL * mint::mod() * mint::mod();
                    auto a0 = 1ULL * a[i + offset].val();
                    auto a1 = 1ULL * a[i + offset + p].val() * rot.val();
                    auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();
                    auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();
                    auto id10 =
                        1ULL * mint(a1 + mod2 - a3).val() * imag.val();
                    auto na2 = mod2 - a2;
                    a[i + offset] = a0 + a2 + a1 + a3;
                    a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
                    a[i + offset + 2 * p] = a0 + na2 + id10;
                    a[i + offset + 3 * p] = a0 + na2 + (mod2 - id10);
                }
                if (s + 1 != (1 << len))
                    rot *= info.rate3[bsf(~(unsigned int)(s))];
            }
            len += 2;
        }
    }
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void id16(std::vector<mint>& a) {
    int n = int(a.size());
    int h = internal::id6(n);

    static const fft_info<mint> info;

    int len = h;  

    while (len) {
        if (len == 1) {
            int p = 1 << (h - len);
            mint irot = 1;
            for (int s = 0; s < (1 << (len - 1)); s++) {
                int offset = s << (h - len + 1);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p];
                    a[i + offset] = l + r;
                    a[i + offset + p] =
                        (unsigned long long)(mint::mod() + l.val() - r.val()) *
                        irot.val();
                    ;
                }
                if (s + 1 != (1 << (len - 1)))
                    irot *= info.irate2[bsf(~(unsigned int)(s))];
            }
            len--;
        } else {
            int p = 1 << (h - len);
            mint irot = 1, iimag = info.iroot[2];
            for (int s = 0; s < (1 << (len - 2)); s++) {
                mint id12 = irot * irot;
                mint id11 = id12 * irot;
                int offset = s << (h - len + 2);
                for (int i = 0; i < p; i++) {
                    auto a0 = 1ULL * a[i + offset + 0 * p].val();
                    auto a1 = 1ULL * a[i + offset + 1 * p].val();
                    auto a2 = 1ULL * a[i + offset + 2 * p].val();
                    auto a3 = 1ULL * a[i + offset + 3 * p].val();

                    auto id8 =
                        1ULL *
                        mint((mint::mod() + a2 - a3) * iimag.val()).val();

                    a[i + offset] = a0 + a1 + a2 + a3;
                    a[i + offset + 1 * p] =
                        (a0 + (mint::mod() - a1) + id8) * irot.val();
                    a[i + offset + 2 * p] =
                        (a0 + a1 + (mint::mod() - a2) + (mint::mod() - a3)) *
                        id12.val();
                    a[i + offset + 3 * p] =
                        (a0 + (mint::mod() - a1) + (mint::mod() - id8)) *
                        id11.val();
                }
                if (s + 1 != (1 << (len - 2)))
                    irot *= info.irate3[bsf(~(unsigned int)(s))];
            }
            len -= 2;
        }
    }
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> id17(const std::vector<mint>& a,
                                    const std::vector<mint>& b) {
    int n = int(a.size()), m = int(b.size());
    std::vector<mint> ans(n + m - 1);
    if (n < m) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                ans[i + j] += a[i] * b[j];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i + j] += a[i] * b[j];
            }
        }
    }
    return ans;
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> id5(std::vector<mint> a, std::vector<mint> b) {
    int n = int(a.size()), m = int(b.size());
    int z = 1 << internal::id6(n + m - 1);
    a.resize(z);
    internal::id4(a);
    b.resize(z);
    internal::id4(b);
    for (int i = 0; i < z; i++) {
        a[i] *= b[i];
    }
    internal::id16(a);
    a.resize(n + m - 1);
    mint iz = mint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
}

}  


template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(std::vector<mint>&& a, std::vector<mint>&& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) return id17(a, b);
    return internal::id5(a, b);
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(const std::vector<mint>& a,
                              const std::vector<mint>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) return id17(a, b);
    return internal::id5(a, b);
}

template <unsigned int mod = 998244353,
          class T,
          std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    using mint = id20<mod>;
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

std::vector<long long> id9(const std::vector<long long>& a,
                                      const std::vector<long long>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    static constexpr unsigned long long MOD1 = 754974721;  

    static constexpr unsigned long long MOD2 = 167772161;  

    static constexpr unsigned long long MOD3 = 469762049;  

    static constexpr unsigned long long id1 = MOD2 * MOD3;
    static constexpr unsigned long long id15 = MOD1 * MOD3;
    static constexpr unsigned long long id0 = MOD1 * MOD2;
    static constexpr unsigned long long id14 = MOD1 * MOD2 * MOD3;

    static constexpr unsigned long long i1 =
        internal::id3(MOD2 * MOD3, MOD1).second;
    static constexpr unsigned long long i2 =
        internal::id3(MOD1 * MOD3, MOD2).second;
    static constexpr unsigned long long i3 =
        internal::id3(MOD1 * MOD2, MOD3).second;

    auto c1 = convolution<MOD1>(a, b);
    auto c2 = convolution<MOD2>(a, b);
    auto c3 = convolution<MOD3>(a, b);

    std::vector<long long> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        unsigned long long x = 0;
        x += (c1[i] * i1) % MOD1 * id1;
        x += (c2[i] * i2) % MOD2 * id15;
        x += (c3[i] * i3) % MOD3 * id0;
        long long diff =
            c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
        if (diff < 0) diff += MOD1;
        static constexpr unsigned long long offset[5] = {
            0, 0, id14, 2 * id14, 3 * id14};
        x -= offset[diff % 5];
        c[i] = x;
    }

    return c;
}

}  
















using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
using namespace atcoder;
namespace poly{
	const int MOD=998244353;
	const int MAXN=200000;
    int fact[MAXN+1],ifact[MAXN+1];
	const int g=3;
	  int qmul(int x, int y){return 1ll*x*y%MOD;}
	  int qadd(int x, int y){return x+y>=MOD?x+y-MOD:x+y;}
	int G[19][(1<<18)+1],R[19][(1<<18)+1],inver[(1<<18)+1];
	int quick(int k1,int k2){
		int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
	}
    int inv(int A){return quick(A,MOD-2);}
    void genmath(){
        fact[0]=1;
        rb(i,1,MAXN) fact[i]=1ll*fact[i-1]*i%MOD;
        ifact[MAXN]=inv(fact[MAXN]);
        

        rl(i,MAXN-1,0) ifact[i]=1ll*ifact[i+1]*(i+1)%MOD;
    }
    int comb(int A,int B){
        if(A<0||B<0) return 0;
        if(A<B) return 0;
        return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
    }
    void add(int &A,int B){
        A+=B;
        if(A>=MOD) A-=MOD;
    }
    void sub(int &A,int B){
        A+=MOD-B;
        if(A>=MOD) A-=MOD;
    }
	struct POLY{
		int len;
		int rev[1<<18];
		POLY(){
			rb(i,1,(1<<18)) inver[i]=inv(i); 
			rb(i,1,18){
				G[i][0]=1;
				R[i][0]=1;
				int tmp2=inv(quick(g,(MOD-1)>>i)); 
				int tmp=quick(g,(MOD-1)>>i);
				rb(j,1,(1<<i)){
					G[i][j]=qmul(G[i][j-1],tmp);
					R[i][j]=qmul(R[i][j-1],tmp2);
				}
			}
		}
		void id4(vector<int> & v){
			rep(i,len){
				rev[i]=rev[i>>1]>>1;
				if(i&1) rev[i]|=len>>1; 
			}
			rep(i,len) if(rev[i]>i) swap(v[i],v[rev[i]]);
		}
		vector<int> ntt(vector<int> v){
			id4(v);
			vector<int> nex;
			  int lg=1;
			for(  int l=2;l<=len;l<<=1,++lg){
				nex.assign(len,0);
				for(  int j=0;j<len;j+=l){
					for(  int k=0;k<(l>>1);++k){
						  int A,B;
						A=v[j+k];
						B=v[j+(l>>1)+k];
						B=qmul(B,G[lg][k]);
						nex[j+k]=qadd(A,B);
						nex[j+k+(l>>1)]=qadd(A,MOD-B);
					}
				}
                v.swap(nex);
			}
			return v;
		}
		vector<int> intt(vector<int> v){
			id4(v);
			vector<int> nex;
			  int lg=1;
			for(int l=2;l<=len;l<<=1,++lg){
				nex.assign(len,0);
				for(int j=0;j<len;j+=l){
					for(int k=0;k<(l>>1);++k){
						  int A,B;
						A=v[j+k];
						B=v[j+(l>>1)+k];
						B=qmul(R[lg][k],B);
						nex[j+k]=qadd(A,B);
						nex[j+k+(l>>1)]=qadd(A,MOD-B);
					}
				}
                v.swap(nex);
			}
			return v;
		}
		void getlen(int x){
			len=1;
			while(len<x){
				len<<=1;
			}
		}
		vector<int> mul(vector<int> A,vector<int> B){
			if(A.size()+B.size()<=25){
				vector<int> ret(A.size()+B.size()-1);
				rep(i,A.size()) rep(j,B.size()) ret[i+j]=qadd(ret[i+j],qmul(A[i],B[j]));
				return ret;
			}
			getlen(A.size()+B.size());
			A.resize(len);
			B.resize(len);
			A=ntt(A);
			B=ntt(B);
			rep(i,len) A[i]=qmul(A[i],B[i]);
			A=intt(A);
			  int iv=inver[len];
			rep(i,len){
				A[i]=qmul(A[i],iv);
			}
			while(!A.empty()&&A.back()==0) A.pop_back();
			return A;
		}
		vector<int> inverse(vector<int> A,int n){
			

			vector<int> ret(n);
			if(n==1){
				ret[0]=quick(A[0],MOD-2);
			}
			else{
				vector<int> oth=inverse(A,(n+1)>>1);
				ret=oth;
				ret.resize(n);
				rep(i,n) ret[i]=(ret[i]+ret[i])%MOD;
				getlen((oth.size()<<1)+A.size());
				oth.resize(len);
				A.resize(len);
				oth=ntt(oth);
				A=ntt(A);
				rep(i,len) oth[i]=qmul(qmul(oth[i],oth[i]),A[i]);
				oth=intt(oth);
				oth.resize(n);
				  int iv=inver[len];
				rep(i,n){
					oth[i]=qmul(oth[i],iv);
				}
				rep(i,n) ret[i]=qadd(ret[i],MOD-oth[i]);
			}
			return ret;
		}
	}poly;
    vector<int> operator * (vector<int> A,vector<int> B){
		return convolution(A,B);
	}
	vector<int> operator + (vector<int> A,vector<int> B){
		int Sz=max(A.size(),B.size());
		A.resize(Sz);
		rep(i,B.size()) A[i]=qadd(A[i],B[i]);
		return A;
	}
	vector<int> operator - (vector<int> A,vector<int> B){
		int Sz=max(A.size(),B.size());
		A.resize(Sz);
		rep(i,B.size()) A[i]=qadd(A[i],MOD-B[i]);
		return A;
	}
	vector<int> operator / (vector<int> A,vector<int> B){

		return A*poly.inverse(B,A.size()-B.size()+1);
	}
	vector<int> operator % (vector<int> A,vector<int> B){
		while(A.size()!=1&&A.back()==0) A.POB();
		while(B.size()!=1&&B.back()==0) B.POB();
		if(B.size()>A.size()) return A;
		vector<int> rem,mod;
		int n,m;
		n=A.size()-1;
		m=B.size()-1;
		reverse(ALL(A));
		reverse(ALL(B));
		rem=A/B;
		reverse(ALL(A));
		reverse(ALL(B));
		rem.resize(n-m+1);
		reverse(ALL(rem));
		mod=A-rem*B;
		mod.resize(m);
        while (mod.size()&&mod.back()==0){
            mod.pop_back();
        }
		return mod;
	}
	vector<int> D(vector<int> A){

		while(A.size()!=1&&A.back()==0) A.POB();
		vector<int> ret(A.size()-1);
		rep(i,ret.size()) ret[i]=1ll*(i+1)*A[i+1]%MOD; 
		if(ret.empty()) return vector<int> (1,0);
		return ret;
	}
    vector<int> I(vector<int> A){

		while(A.size()!=1&&A.back()==0) A.POB();
		vector<int> ret(A.size()+1,0);
		rep(i,A.size()) ret[i+1]=1ll*A[i]*inver[i+1]%MOD;
        while(ret.size()!=1&&ret.back()==0) ret.POB();
		return ret;
    }
    vector<int> poly_ln(vector<int> A,int n){

        auto tmp=I(D(A)*poly.inverse(A,n));
        if(tmp.size()>n) tmp.resize(n);
        while(tmp.size()!=1&&tmp.back()==0) tmp.POB();
        return tmp;
    }
    vector<int> poly_exp(vector<int> A,int n){

        if(n==1){
            return vector<int> (1,1);
        }
        vector<int> G0=poly_exp(A,(n+1)/2);
        vector<int> G;
        G=(G0*((vector<int>{1})-poly_ln(G0,n)+A));
        if(G.size()>n) G.resize(n);
        while(G.size()!=1&&G.back()==0) G.POB();
        return G;
    }
	class MC{

		vector<vector<int> > RAM;
		vector<vector<int> > SIN;
		vector<int> Lc;
		vector<int> Rc;
		vector<int> ret;
		vector<int> x_;
		void fendge1(int l,int r,int& cnt){
			if(l==r-1){
				Lc.PB(0);
				Rc.PB(0);
				RAM.PB(SIN[l]);
				return ;
			}
			RAM.PB(vector<int> (0));
			Lc.PB(0);
			Rc.PB(0);
			int now=cnt;
			int mid=(l+r)>>1;
			int L=++cnt;
			fendge1(l,mid,cnt);
			int R=++cnt;
			fendge1(mid,r,cnt);
			Lc[now]=L;
			Rc[now]=R;
			RAM[now]=RAM[L]*RAM[R];
		}
		void fendge2(int l,int r,int cnt,vector<int> p){
			p=p%RAM[cnt];
			if(r-l<=500){
				rb(i,l,r-1){
					  int T=1;
					rep(j,p.size()){
						ret[i]=qadd(ret[i],qmul(T,p[j]));
						T=qmul(T,x_[i]);
					}
				}
				return ;
			}
			int mid=(l+r)>>1;
			fendge2(l,mid,Lc[cnt],p);
			fendge2(mid,r,Rc[cnt],p); 
		}
		public:
			vector<int> init(vector<int> p,vector<int> x){
				x_=x;
				Lc.clear();
				Rc.clear();
				RAM.clear();
				SIN.clear();
				ret.clear();
				ret=vector<int>(x.size(),0);
				rep(i,x.size()){
					SIN.PB(vector<int>{(MOD-x[i]),1});
				}
				int cnt=0;
				fendge1(0,x.size(),cnt);
				fendge2(0,x.size(),0,p);
				return ret;
			}
	}mc;
	vector<int> id19(vector<int> p,vector<int> x){
		return mc.init(p,x);	
	}
	class ITP{
		vector<int> u;
		vector<int> v;
		vector<int> fm;
		vector<int> fendge(int l,int r){
			if(l==r-1){return vector<int> {(MOD-u[l]),1};}
			int mid=(l+r)>>1;
			return fendge(l,mid)*fendge(mid,r);
		}
		pair<vector<int>,vector<int> > fendge2(int l,int r){
			if(l==r-1){
				return {vector<int> {(MOD-u[l]),1},vector<int> {fm[l]}};
			}
			int mid=(l+r)>>1;
			pair<vector<int>,vector<int> > L,R;
			L=fendge2(l,mid);
			R=fendge2(mid,r);
			return {L.FIR*R.FIR,L.FIR*R.SEC+R.FIR*L.SEC}; 
		}
		public:
			vector<int> solve(vector<mp> x){
				u.clear();
				v.clear();
				int n=x.size();
				for(auto it:x) u.PB(it.FIR),v.PB(it.SEC);
				vector<int> g=fendge(0,u.size());
				fm=id19(D(g),u);
				rep(i,n){
					fm[i]=qmul(v[i],inv(fm[i]));
				}
				return fendge2(0,n).SEC;
			}
	}itp;
	vector<int> interpolation(vector<mp> x){
		return itp.solve(x);
	}
}
using namespace poly;
int n,k,p,a[MAXN],b[MAXN];
map<int,int> gm;
mp gg[MAXN];
void precalc(){
    gg[0]=II(1,0);
    rb(i,1,k+1){
        gg[i]=gg[i-1];
        add(gg[i].second,quick(i,k));
        gg[i].first=1ll*gg[i].first*inv(p)%MOD;
        gg[i].second=1ll*gg[i].second*inv(p)%MOD;
    }
    int A=0,B=0;
    rb(i,0,k+1){
        int coef=comb(k+1,i);
        if((k+1-i)&1) coef=(MOD-coef)%MOD;
        add(A,1ll*gg[i].first*coef%MOD);
        add(B,1ll*gg[i].second*coef%MOD);
    }
    int C=1ll*(MOD-B)*inv(A)%MOD;
    vector<mp> pts;
    rb(i,0,k+1) pts.PB(II(i,(1ll*gg[i].first*C%MOD+gg[i].second)%MOD));
    vector<int> xs;
    xs.PB(0);
    rb(i,1,n) xs.PB(a[i]);
    auto ys=id19(interpolation(pts),xs);
    rep(i,xs.size()) gm[xs[i]]=ys[i];
}
struct Matrix{
	int n,m;
	LL a[4][4];
	Matrix(){
		memset(a,0,sizeof(a));
	}
	void debug(){
		cout<<n<<" "<<m<<endl;
		rep(i,n)
			rep(j,m){
				cout<<a[i][j]<<" ";
				if(j==m) cout<<endl;
			}
	}
};
Matrix multiplication(Matrix A,Matrix B){
	Matrix result;
	memset(result.a,0,sizeof(result.a));
	if(A.m!=B.n){
		cout<<"------\n";
		cout<<"|erro|\n";
		cout<<"------\n";
		cout<<"A can't multiply B \n"; 
		exit(0);
	}
	result.n=A.n;
	result.m=B.m;
	rep(i,A.n){
		rep(j,B.m){
			rep(k,A.m){
				result.a[i][j]+=A.a[i][k]*B.a[k][j]%MOD;
				result.a[i][j]%=MOD;
			}
		}
	}
	return result;
}
Matrix add(Matrix A,Matrix B){
    Matrix rest;
    rest.n=rest.m=A.n;
    rep(i,rest.n) rep(j,rest.m) rest.a[i][j]=(A.a[i][j]+B.a[i][j])%MOD;
    return rest;
}
Matrix quick_pow(Matrix A,LL times){
	if(times==0){
		Matrix res;
		res.m=res.n=A.n;
		memset(res.a,0,sizeof(res.a));	
		rb(i,1,res.m){
			res.a[i][i]=1;
		}
		return res;
	}
	Matrix res=quick_pow(A,times>>1);
	res=multiplication(res,res);
	if(times&1) res=multiplication(res,A);
	return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    genmath();
    cin>>n>>k>>p;
    rb(i,1,n) cin>>a[i];
    precalc();
    rb(i,1,n) b[i]=(1ll*quick(p,a[i]+1)*gm[a[i]]%MOD-1ll*p*gm[0]%MOD+MOD)%MOD;
    int ans=0;
    Matrix sum;
    sum.n=sum.m=4;
    rb(i,1,n){
        Matrix B;
        B.n=B.m=4;
        rep(mask,4){
            rep(mask2,4) if((mask2&mask)==mask){
                int x=mask2^mask;
                if(x==0) B.a[mask][mask2]=a[i]+1;
                if(x==1) B.a[mask][mask2]=a[i];
                if(x==2) B.a[mask][mask2]=b[i];
                if(x==3) B.a[mask][mask2]=b[i];
            }
        }
        sum=add(multiplication(sum,B),B);
        ans+=sum.a[0][3];
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}