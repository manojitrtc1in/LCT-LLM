#include <stdio.h>
#include <stdbool.h>

typedef unsigned long long int ull;

ull safe_mod(ull x, ull m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

struct barrett {
    unsigned int _m;
    ull im;
};

struct barrett create_barrett(unsigned int m) {
    struct barrett b;
    b._m = m;
    b.im = (ull)(-1) / m + 1;
    return b;
}

unsigned int umod(struct barrett b) {
    return b._m;
}

unsigned int mul(struct barrett b, unsigned int a, unsigned int b) {
    ull z = a;
    z *= b;
    ull x = (ull)(((ull)(z)*b.im) >> 64);
    unsigned int v = (unsigned int)(z - x * b._m);
    if (b._m <= v) v += b._m;
    return v;
}

ull id4(ull x, ull n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
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
    ull bases[3] = {2, 7, 61};
    for (int i = 0; i < 3; i++) {
        ull a = bases[i];
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

int id3(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {0};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (ull)(i)*i <= x; i += 2) {
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

typedef struct {
    ull _v;
    struct barrett bt;
} modint;

modint raw(struct barrett bt, int v) {
    modint x;
    x._v = v;
    x.bt = bt;
    return x;
}

modint create_modint(int m) {
    modint x;
    x._v = 0;
    x.bt = create_barrett(m);
    return x;
}

int mod(modint x) {
    return (int)(x.bt._m);
}

modint add(modint lhs, modint rhs) {
    lhs._v += rhs._v;
    if (lhs._v >= umod(lhs.bt)) lhs._v -= umod(lhs.bt);
    return lhs;
}

modint sub(modint lhs, modint rhs) {
    lhs._v += mod(lhs.bt) - rhs._v;
    if (lhs._v >= umod(lhs.bt)) lhs._v -= umod(lhs.bt);
    return lhs;
}

modint mul(modint lhs, modint rhs) {
    lhs._v = mul(lhs.bt, lhs._v, rhs._v);
    return lhs;
}

modint inv(modint x) {
    ull eg = id2(x._v, mod(x.bt));
    return eg.first == 1 ? eg.second : 0;
}

modint pow(modint x, ull n) {
    modint r = raw(x.bt, 1);
    while (n) {
        if (n & 1) r = mul(r, x);
        x = mul(x, x);
        n >>= 1;
    }
    return r;
}

bool equal(modint lhs, modint rhs) {
    return lhs._v == rhs._v;
}

bool not_equal(modint lhs, modint rhs) {
    return lhs._v != rhs._v;
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);

    modint::set_mod(m);

    modint dp[n + 1];
    modint p[n + 1];

    dp[n] = raw(dp[n].bt, 1);
    p[n] = raw(p[n].bt, 1);
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = add(p[i + 1], dp[i]);

        for (int z = 2; z * i <= n; z++) {
            int r = get(i, z) + 1;
            int l = z * i;
            dp[i] = add(p[l], dp[i]);
            if (r <= n) dp[i] = sub(dp[i], p[r]);
        }

        p[i] = add(p[i + 1], dp[i]);
    }

    printf("%llu", dp[1]._v);
}

int main() {
    int _t = 1;

    while (_t--) solve();
    return 0;
}
