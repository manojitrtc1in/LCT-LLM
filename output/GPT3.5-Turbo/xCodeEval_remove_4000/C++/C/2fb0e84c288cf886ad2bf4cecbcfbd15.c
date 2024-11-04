#include <stdio.h>
#include <stdbool.h>

typedef long long ll;

ll safe_mod(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

struct barrett {
    unsigned int _m;
    unsigned long long im;
};

struct barrett create_barrett(unsigned int m) {
    struct barrett b;
    b._m = m;
    b.im = (unsigned long long)(-1) / m + 1;
    return b;
}

unsigned int umod(struct barrett b) {
    return b._m;
}

unsigned int mul(struct barrett b, unsigned int a, unsigned int b) {
    unsigned long long z = a;
    z *= b;

    unsigned long long x = (unsigned long long)(((unsigned __int128)(z)*b.im) >> 64);

    unsigned int v = (unsigned int)(z - x * b._m);
    if (b._m <= v) v += b._m;
    return v;
}

ll id4(ll x, ll n, int m) {
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

bool id1(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    ll bases[3] = {2, 7, 61};
    for (int i = 0; i < 3; i++) {
        ll a = bases[i];
        ll t = d;
        ll y = id4(a, t, n);
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

struct pair {
    ll first;
    ll second;
};

struct pair id2(ll a, ll b) {
    a = safe_mod(a, b);
    if (a == 0) {
        struct pair p;
        p.first = b;
        p.second = 0;
        return p;
    }

    ll s = b, t = a;
    ll m0 = 0, m1 = 1;

    while (t) {
        ll u = s / t;
        s -= t * u;
        m0 -= m1 * u;

        ll tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }

    if (m0 < 0) m0 += b / s;

    struct pair p;
    p.first = s;
    p.second = m0;
    return p;
}

int id3(int m) {
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
    for (int i = 3; (ll)(i)*i <= x; i += 2) {
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
            if (id4(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T>
bool is_modint() {
    return std::is_base_of<modint_base, T>::value;
}

template <class T>
bool is_modint_t() {
    return std::enable_if_t<is_modint<T>::value>;
}

template <class T>
bool is_integral() {
    return std::is_integral<T>::value;
}

template <class T>
bool is_signed_int() {
    return (is_integral<T>::value && std::is_signed<T>::value);
}

template <class T>
bool is_unsigned_int() {
    return (is_integral<T>::value && std::is_unsigned<T>::value);
}

template <class T>
bool to_unsigned() {
    if (is_signed_int128<T>::value) {
        return make_unsigned_int128<T>;
    } else {
        if (is_signed<T>::value) {
            return std::make_unsigned<T>;
        } else {
            return std::common_type<T>;
        }
    }
}

template <class T>
bool is_signed_int_t() {
    return std::enable_if_t<is_signed_int<T>::value>;
}

template <class T>
bool is_unsigned_int_t() {
    return std::enable_if_t<is_unsigned_int<T>::value>;
}

template <class T>
bool to_unsigned_t() {
    return to_unsigned<T>::type;
}

template <int m>
struct id0 : internal::static_modint_base {
    using mint = id0;

    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id0() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id0(T v) {
        ll x = (ll)(v % (ll)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id0(T v) {
        _v = (unsigned int)(v % umod());
    }
    id0(bool v) { _v = ((unsigned int)(v) % umod()); }

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

    mint pow(ll n) const {
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
            struct pair eg = id2(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = id1(m);
};

template <int id>
struct id5 : internal::modint_base {
    using mint = id5;

    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = create_barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id5() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id5(T v) {
        ll x = (ll)(v % (ll)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id5(T v) {
        _v = (unsigned int)(v % mod());
    }
    id5(bool v) { _v = ((unsigned int)(v) % mod()); }

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
        _v = mul(bt, _v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(ll n) const {
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
        struct pair eg = id2(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static struct barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> struct barrett id5<id>::bt = create_barrett(998244353);

typedef id0<998244353> modint998244353;
typedef id0<1000000007> modint1000000007;
typedef id5<-1> modint;

int get(int i, int z) {
    int l = i * z;
    int r = (i + i) * z;

    int ans = l;

    while (l <= r) {
        int m = (l + r) / 2;
        if (m / z > i) {
            r = m - 1;
        } else {
            ans = max(ans, m);
            l = m + 1;
        }
    }

    return ans;
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);

    modint::set_mod(m);

    modint dp[n + 1];
    modint p1[n + 1];

    dp[n] = 1;
    p1[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        dp[i] += p1[i + 1];

        for (int z = 2; z * i <= n; z++) {
            int r = get(i, z) + 1;
            int l = z * i;
            dp[i] += p1[l];
            if (r <= n) dp[i] -= p1[r];
        }

        p1[i] = p1[i + 1] + dp[i];
    }

    printf("%d", dp[1].val());
}

int main() {
    int _t = 1;

    while (_t--) solve();
    return 0;
}
