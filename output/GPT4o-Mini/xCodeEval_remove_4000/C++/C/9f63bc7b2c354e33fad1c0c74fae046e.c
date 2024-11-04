#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int uint;
typedef unsigned long long ull;

ull safe_mod(ull x, ull m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

struct barrett {
    uint _m;
    ull im;

    barrett(uint m) : _m(m), im((ull)(-1) / m + 1) {}

    uint umod() const { return _m; }

    uint mul(uint a, uint b) const {
        ull z = a;
        z *= b;

        ull x = (ull)(((ull)(z) * im) >> 64);
        uint v = (uint)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

ull id4(ull x, ull n, int m) {
    if (m == 1) return 0;
    uint _m = (uint)(m);
    ull r = 1;
    ull y = safe_mod(x, m);
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
    ull d = n - 1;
    while (d % 2 == 0) d /= 2;
    const ull bases[3] = {2, 7, 61};
    for (ull a : bases) {
        ull t = d;
        ull y = id4(a, t, n);
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

#define is_prime(n) id1(n)

ull id2(ull a, ull b) {
    a = safe_mod(a, b);
    if (a == 0) return (ull)b;

    ull s = b, t = a;
    ull m0 = 0, m1 = 1;

    while (t) {
        ull u = s / t;
        s -= t * u;
        m0 -= m1 * u;

        ull tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }

    if (m0 < 0) m0 += b / s;
    return (s << 32) | m0; // Return as a combined value
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
    for (int i = 3; (ull)(i) * i <= x; i += 2) {
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

struct modint {
    uint _v;
    static uint umod() { return 998244353; }

    modint() : _v(0) {}
    modint(int v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (uint)(x);
    }

    uint val() const { return _v; }

    modint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    modint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    modint operator+(const modint& rhs) const {
        modint result = *this;
        result += rhs;
        return result;
    }
    modint operator-(const modint& rhs) const {
        modint result = *this;
        result -= rhs;
        return result;
    }
    modint operator*(const modint& rhs) const {
        modint result = *this;
        result *= rhs;
        return result;
    }
    modint operator/(const modint& rhs) const {
        return *this * rhs.inv();
    }

    modint& operator+=(const modint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    modint& operator-=(const modint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    modint& operator*=(const modint& rhs) {
        _v = (_v * rhs._v) % umod();
        return *this;
    }

    modint pow(long long n) const {
        modint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    modint inv() const {
        auto eg = id2(_v, umod());
        return (modint)(eg >> 32); // Extract the second part as the inverse
    }
};

uint l1;
uint r1;

int get(int i, int z) {
    l1 = (uint)1U * i * z;
    r1 = (uint)1U * (i + i) * z;

    uint ans = l1;

    while (l1 <= r1) {
        uint m = (l1 + r1) / 2;
        if (m / z > i) {
            r1 = m - 1;
        } else {
            ans = (ans > m) ? ans : m;
            l1 = m + 1;
        }
    }

    return ans;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    modint::set_mod(m);

    modint dp[n + 1];
    modint p[n + 1];

    dp[n] = 1;
    p[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        dp[i] += p[i + 1];

        for (int z = 2; z * i <= n; z++) {
            int r = get(i, z) + 1;
            int l = z * i;
            dp[i] += p[l];
            if (r <= n) dp[i] -= p[r];
        }

        p[i] = p[i + 1] + dp[i];
    }

    printf("%u\n", dp[1].val());
}

int main() {
    int _t = 1;
    while (_t--) solve();
    return 0;
}
