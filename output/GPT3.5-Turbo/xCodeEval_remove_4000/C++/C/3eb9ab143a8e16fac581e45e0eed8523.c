#include <stdio.h>

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

void barrett_init(struct barrett* b, unsigned int m) {
    b->_m = m;
    b->im = (unsigned long long)(-1) / m + 1;
}

unsigned int barrett_umod(struct barrett* b) {
    return b->_m;
}

unsigned int barrett_mul(struct barrett* b, unsigned int a, unsigned int c) {
    unsigned long long z = a;
    z *= c;

    unsigned long long x;
    x = (unsigned long long)(((unsigned __int128)(z)*b->im) >> 64);

    unsigned int v = (unsigned int)(z - x * b->_m);
    if (b->_m <= v) v += b->_m;
    return v;
}

ll id5(ll x, ll n, int m) {
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

int id2(int n) {
    if (n <= 1) return 0;
    if (n == 2 || n == 7 || n == 61) return 1;
    if (n % 2 == 0) return 0;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    const ll bases[3] = {2, 7, 61};
    for (ll i = 0; i < 3; i++) {
        ll t = d;
        ll y = id5(bases[i], t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return 0;
        }
    }
    return 1;
}

struct pair {
    ll first;
    ll second;
};

struct pair id3(ll a, ll b) {
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

int id4(int m) {
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
        int ok = 1;
        for (int i = 0; i < cnt; i++) {
            if (id5(g, (m - 1) / divs[i], m) == 1) {
                ok = 0;
                break;
            }
        }
        if (ok) return g;
    }
}

ll id1(ll n, ll m, ll a, ll b) {
    ll ans = 0;
    while (1) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        ll y_max = a * n + b;
        if (y_max < m) break;

        n = (ll)(y_max / m);
        b = (ll)(y_max % m);
        ll tmp = m;
        m = a;
        a = tmp;
    }
    return ans;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct pair p = id3(m, 998244353);
    int g = id4(m);
    int e = 998244353 / p.first;
    int e2 = m / g;
    int q = (n - 1) / e2;
    int r = (n - 1) % e2;
    ll ans = 0;
    if (p.first == 1) {
        ans = id1(q, e, 1, 0);
    } else {
        ans = id1(q, e, 1, 0) * (ll)(p.second);
        ans += id1(q, e, 1, p.second);
    }
    ans += id1(r, e, 1, 0);
    ans += id1(r, e, 1, p.second);
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}
