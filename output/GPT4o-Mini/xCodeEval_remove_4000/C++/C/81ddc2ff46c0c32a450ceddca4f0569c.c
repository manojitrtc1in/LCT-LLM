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

template <int n>
bool is_prime = id1(n);

typedef struct {
    ull first;
    ull second;
} Pair;

Pair id2(ull a, ull b) {
    a = safe_mod(a, b);
    if (a == 0) return (Pair){b, 0};

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
    return (Pair){s, m0};
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

#define MOD 998244353

struct modint {
    uint _v;

    modint() : _v(0) {}
    modint(int v) {
        long long x = (long long)(v % (long long)(MOD));
        if (x < 0) x += MOD;
        _v = (uint)(x);
    }

    uint val() const { return _v; }

    modint& operator++() {
        _v++;
        if (_v == MOD) _v = 0;
        return *this;
    }
    modint& operator--() {
        if (_v == 0) _v = MOD;
        _v--;
        return *this;
    }
    modint operator+(const modint& rhs) const {
        modint result = *this;
        result._v += rhs._v;
        if (result._v >= MOD) result._v -= MOD;
        return result;
    }
    modint operator-(const modint& rhs) const {
        modint result = *this;
        result._v += MOD - rhs._v;
        if (result._v >= MOD) result._v -= MOD;
        return result;
    }
    modint operator*(const modint& rhs) const {
        ull z = _v;
        z *= rhs._v;
        return modint(z % MOD);
    }
    modint pow(long long n) const {
        modint x = *this, r = 1;
        while (n) {
            if (n & 1) r = r * x;
            x = x * x;
            n >>= 1;
        }
        return r;
    }
    modint inv() const {
        auto eg = id2(_v, MOD);
        return eg.second;
    }
};

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    modint::set_mod(m);

    modint dp[n + 1];
    modint p[n + 1];

    dp[n] = 1;
    p[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = dp[i] + p[i + 1];

        for (int z = 2; 1U * z * i <= n; z++) {
            int r = i * z + z;
            int l = 1U * z * i;
            dp[i] = dp[i] + p[l];
            if (r <= n) dp[i] = dp[i] - p[r];
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
