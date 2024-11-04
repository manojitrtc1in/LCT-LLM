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

typedef struct {
    ll first;
    ll second;
} pair;

pair id2(ll a, ll b) {
    a = safe_mod(a, b);
    if (a == 0) {
        pair p;
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
    pair p;
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
    int divs[20] = {0};
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
            if (id4(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}

typedef struct {
    int m;
} id0;

id0 create_id0(int m) {
    id0 id;
    id.m = m;
    return id;
}

int mod(id0 id) {
    return id.m;
}

ll raw(id0 id, int v) {
    return (ll)v;
}

id0 create_id0_default() {
    return create_id0(0);
}

id0 create_id0_from_bool(bool v) {
    return create_id0((int)v);
}

unsigned int val(id0 id, ll x) {
    return (unsigned int)x;
}

id0 operator_plus_plus(id0 id) {
    return id;
}

id0 operator_minus_minus(id0 id) {
    return id;
}

id0 operator_plus_plus_post(id0 id) {
    return id;
}

id0 operator_minus_minus_post(id0 id) {
    return id;
}

id0 operator_plus_equal(id0 id, id0 rhs) {
    id.m += rhs.m;
    if (id.m >= umod(id)) id.m -= umod(id);
    return id;
}

id0 operator_minus_equal(id0 id, id0 rhs) {
    id.m -= rhs.m;
    if (id.m >= umod(id)) id.m += umod(id);
    return id;
}

id0 operator_star_equal(id0 id, id0 rhs) {
    unsigned long long z = id.m;
    z *= rhs.m;
    id.m = (unsigned int)(z % umod(id));
    return id;
}

id0 operator_slash_equal(id0 id, id0 rhs) {
    return id;
}

id0 operator_plus(id0 lhs, id0 rhs) {
    return operator_plus_equal(lhs, rhs);
}

id0 operator_minus(id0 lhs, id0 rhs) {
    return operator_minus_equal(lhs, rhs);
}

id0 operator_star(id0 lhs, id0 rhs) {
    return operator_star_equal(lhs, rhs);
}

id0 operator_slash(id0 lhs, id0 rhs) {
    return operator_slash_equal(lhs, rhs);
}

bool operator_equal_equal(id0 lhs, id0 rhs) {
    return lhs.m == rhs.m;
}

bool operator_exclaim_equal(id0 lhs, id0 rhs) {
    return lhs.m != rhs.m;
}

typedef struct {
    int m;
} id5;

id5 create_id5(int m) {
    id5 id;
    id.m = m;
    return id;
}

int mod(id5 id) {
    return id.m;
}

void set_mod(id5 id, int m) {
    id.m = m;
}

ll raw(id5 id, int v) {
    return (ll)v;
}

id5 create_id5_default() {
    return create_id5(0);
}

id5 create_id5_from_bool(bool v) {
    return create_id5((int)v);
}

unsigned int val(id5 id, ll x) {
    return (unsigned int)x;
}

id5 operator_plus_plus(id5 id) {
    return id;
}

id5 operator_minus_minus(id5 id) {
    return id;
}

id5 operator_plus_plus_post(id5 id) {
    return id;
}

id5 operator_minus_minus_post(id5 id) {
    return id;
}

id5 operator_plus_equal(id5 id, id5 rhs) {
    id.m += rhs.m;
    if (id.m >= umod(id)) id.m -= umod(id);
    return id;
}

id5 operator_minus_equal(id5 id, id5 rhs) {
    id.m += mod(id) - rhs.m;
    if (id.m >= umod(id)) id.m -= umod(id);
    return id;
}

id5 operator_star_equal(id5 id, id5 rhs) {
    id.m = mul(id, id.m, rhs.m);
    return id;
}

id5 operator_slash_equal(id5 id, id5 rhs) {
    return id;
}

id5 operator_plus(id5 lhs, id5 rhs) {
    return operator_plus_equal(lhs, rhs);
}

id5 operator_minus(id5 lhs, id5 rhs) {
    return operator_minus_equal(lhs, rhs);
}

id5 operator_star(id5 lhs, id5 rhs) {
    return operator_star_equal(lhs, rhs);
}

id5 operator_slash(id5 lhs, id5 rhs) {
    return operator_slash_equal(lhs, rhs);
}

bool operator_equal_equal(id5 lhs, id5 rhs) {
    return lhs.m == rhs.m;
}

bool operator_exclaim_equal(id5 lhs, id5 rhs) {
    return lhs.m != rhs.m;
}

typedef id0 mint;

mint pow(mint x, ll n) {
    mint r = create_id0(1);
    while (n) {
        if (n & 1) r = r * x;
        x = x * x;
        n >>= 1;
    }
    return r;
}

mint inv(mint x) {
    return pow(x, mod(x) - 2);
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);

    mint::set_mod(m);

    mint dp[n + 1];
    mint p[n + 1];

    dp[n] = create_id0(1);
    p[n] = create_id0(1);
    for (int i = n - 1; i >= 1; i--) {
        dp[i] += p[i + 1];

        for (int z = 2; 1U * z * i <= n; z++) {
            int r = i * z + z;
            int l = 1U * z * i;
            dp[i] += p[l];
            if (r <= n) dp[i] -= p[r];
        }

        p[i] = p[i + 1] + dp[i];
    }

    printf("%u\n", val(dp[1]));
}

int main() {
    int _t = 1;

    while (_t--) solve();
    return 0;
}
