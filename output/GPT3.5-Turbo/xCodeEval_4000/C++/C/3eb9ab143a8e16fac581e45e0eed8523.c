#include <stdio.h>
#include <stdbool.h>

typedef long long ll;

ll safe_mod(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

ll pow_mod_constexpr(ll x, ll n, int m) {
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

bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    const ll bases[3] = {2, 7, 61};
    for (ll a : bases) {
        ll t = d;
        ll y = pow_mod_constexpr(a, t, n);
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

typedef struct {
    unsigned int _m;
    unsigned long long im;
} barrett;

barrett create_barrett(unsigned int m) {
    barrett b;
    b._m = m;
    b.im = (unsigned long long)(-1) / m + 1;
    return b;
}

unsigned int umod(barrett b) {
    return b._m;
}

unsigned int mul(barrett b, unsigned int a, unsigned int b) {
    unsigned long long z = a;
    z *= b;
    unsigned long long x = (unsigned long long)(((unsigned __int128)(z)*b.im) >> 64);
    unsigned int v = (unsigned int)(z - x * b._m);
    if (b._m <= v) v += b._m;
    return v;
}

typedef struct {
    ll _v;
    barrett bt;
} dynamic_modint;

dynamic_modint create_dynamic_modint(int id) {
    dynamic_modint dm;
    dm._v = 0;
    dm.bt = create_barrett(998244353);
    return dm;
}

unsigned int mod(dynamic_modint dm) {
    return (unsigned int)(dm.bt.umod());
}

dynamic_modint raw(dynamic_modint dm, int v) {
    dynamic_modint x = dm;
    x._v = v;
    return x;
}

dynamic_modint dynamic_modint_add(dynamic_modint lhs, dynamic_modint rhs) {
    dynamic_modint x = lhs;
    x._v += rhs._v;
    if (x._v >= umod(x.bt)) x._v -= umod(x.bt);
    return x;
}

dynamic_modint dynamic_modint_sub(dynamic_modint lhs, dynamic_modint rhs) {
    dynamic_modint x = lhs;
    x._v += mod(x.bt) - rhs._v;
    if (x._v >= umod(x.bt)) x._v -= umod(x.bt);
    return x;
}

dynamic_modint dynamic_modint_mul(dynamic_modint lhs, dynamic_modint rhs) {
    dynamic_modint x = lhs;
    x._v = mul(x.bt, x._v, rhs._v);
    return x;
}

dynamic_modint dynamic_modint_div(dynamic_modint lhs, dynamic_modint rhs) {
    dynamic_modint x = lhs;
    x._v = dynamic_modint_mul(x, dynamic_modint_inv(rhs))._v;
    return x;
}

dynamic_modint dynamic_modint_pow(dynamic_modint dm, ll n) {
    dynamic_modint x = dm;
    dynamic_modint r = raw(x, 1);
    while (n) {
        if (n & 1) r = dynamic_modint_mul(r, x);
        x = dynamic_modint_mul(x, x);
        n >>= 1;
    }
    return r;
}

dynamic_modint dynamic_modint_inv(dynamic_modint dm) {
    dynamic_modint x = dm;
    ll eg = inv_gcd(x._v, mod(x.bt));
    return raw(x, eg.second);
}

ll inv_gcd(ll a, ll b) {
    a = safe_mod(a, b);
    if (a == 0) return b;

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
    return m0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    dynamic_modint::set_mod(m);
    dynamic_modint ways[n + 1];
    dynamic_modint extras[n + 1];
    ways[1] = raw(ways[1], 1);
    dynamic_modint sum = raw(sum, 0);
    dynamic_modint extra = raw(extra, 0);
    for (int i = 1; i <= n; ++i) {
        ways[i] = dynamic_modint_add(ways[i], sum);
        extra = dynamic_modint_add(extra, extras[i]);
        ways[i] = dynamic_modint_add(ways[i], extra);
        for (int j = 2; i * j <= n; ++j) {
            extras[i * j] = dynamic_modint_add(extras[i * j], ways[i]);
            if ((i + 1) * j <= n)
                extras[(i + 1) * j] = dynamic_modint_sub(extras[(i + 1) * j], ways[i]);
        }
        sum = dynamic_modint_add(sum, ways[i]);
    }
    printf("%d\n", ways[n]._v);
    return 0;
}
