#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll safe_mod(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
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

unsigned int mul(barrett b, unsigned int a, unsigned int c) {
    unsigned long long z = a;
    z *= c;
    unsigned long long x;
    __uint128_t y = (__uint128_t)z * b.im;
    x = y >> 64;
    unsigned int v = (unsigned int)(z - x * b._m);
    if (b._m <= v) v += b._m;
    return v;
}

ll id7(ll x, ll n, int m) {
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

int id6(int n) {
    if (n <= 1) return 0;
    if (n == 2 || n == 7 || n == 61) return 1;
    if (n % 2 == 0) return 0;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    ll bases[3] = {2, 7, 61};
    for (int i = 0; i < 3; i++) {
        ll a = bases[i];
        ll t = d;
        ll y = id7(a, t, n);
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

typedef struct {
    ll first;
    ll second;
} pair;

pair create_pair(ll first, ll second) {
    pair p;
    p.first = first;
    p.second = second;
    return p;
}

pair add(pair a, pair b) {
    pair p;
    p.first = a.first + b.first;
    p.second = a.second + b.second;
    return p;
}

pair mul_pair(pair a, pair b, int m) {
    pair p;
    p.first = a.first * b.first % m;
    p.second = a.second * b.first % m + b.second;
    return p;
}

pair pow_pair(pair a, ll n, int m) {
    pair p = create_pair(1, 0);
    while (n) {
        if (n & 1) p = mul_pair(p, a, m);
        a = mul_pair(a, a, m);
        n >>= 1;
    }
    return p;
}

pair inv_pair(pair a, int m) {
    pair p = create_pair(1, 0);
    ll b = a.first;
    while (b) {
        ll t = a.first / b;
        a = create_pair(a.second, a.first - t * b);
        p = create_pair(p.second, p.first - t * p.second);
        ll tmp = a.first;
        a.first = b;
        b = tmp;
        tmp = p.first;
        p.first = p.second;
        p.second = tmp;
    }
    if (p.first < 0) p.first += m;
    return p;
}

typedef struct {
    unsigned int _v;
    unsigned int _m;
    unsigned long long im;
} modint;

modint create_modint(unsigned int v, unsigned int m) {
    modint x;
    x._v = v;
    x._m = m;
    x.im = (unsigned long long)(-1) / m + 1;
    return x;
}

unsigned int val(modint x) {
    return x._v;
}

modint add_modint(modint a, modint b) {
    unsigned int v = a._v + b._v;
    if (v >= a._m) v -= a._m;
    return create_modint(v, a._m);
}

modint sub_modint(modint a, modint b) {
    unsigned int v = a._v + a._m - b._v;
    if (v >= a._m) v -= a._m;
    return create_modint(v, a._m);
}

modint mul_modint(modint a, modint b) {
    unsigned long long z = a._v;
    z *= b._v;
    unsigned long long x;
    __uint128_t y = (__uint128_t)z * a.im;
    x = y >> 64;
    unsigned int v = (unsigned int)(z - x * a._m);
    if (a._m <= v) v += a._m;
    return create_modint(v, a._m);
}

modint div_modint(modint a, modint b) {
    return mul_modint(a, inv_pair(create_pair(b._v, 0), b._m));
}

modint pow_modint(modint a, ll n) {
    modint x = create_modint(1, a._m);
    while (n) {
        if (n & 1) x = mul_modint(x, a);
        a = mul_modint(a, a);
        n >>= 1;
    }
    return x;
}

modint inv_modint(modint a) {
    return inv_pair(create_pair(a._v, 0), a._m);
}

typedef struct {
    int n;
    modint* data;
} vector;

vector create_vector(int n, modint* data) {
    vector v;
    v.n = n;
    v.data = data;
    return v;
}

vector add_vector(vector a, vector b) {
    vector v = create_vector(a.n, a.data);
    for (int i = 0; i < v.n; i++) {
        v.data[i] = add_modint(v.data[i], b.data[i]);
    }
    return v;
}

vector sub_vector(vector a, vector b) {
    vector v = create_vector(a.n, a.data);
    for (int i = 0; i < v.n; i++) {
        v.data[i] = sub_modint(v.data[i], b.data[i]);
    }
    return v;
}

vector mul_vector(vector a, vector b) {
    vector v = create_vector(a.n, a.data);
    for (int i = 0; i < v.n; i++) {
        v.data[i] = mul_modint(v.data[i], b.data[i]);
    }
    return v;
}

vector div_vector(vector a, vector b) {
    vector v = create_vector(a.n, a.data);
    for (int i = 0; i < v.n; i++) {
        v.data[i] = div_modint(v.data[i], b.data[i]);
    }
    return v;
}

vector pow_vector(vector a, ll n) {
    vector v = create_vector(a.n, a.data);
    for (int i = 0; i < v.n; i++) {
        v.data[i] = pow_modint(v.data[i], n);
    }
    return v;
}

vector inv_vector(vector a) {
    vector v = create_vector(a.n, a.data);
    for (int i = 0; i < v.n; i++) {
        v.data[i] = inv_modint(v.data[i]);
    }
    return v;
}

typedef struct {
    int n;
    vector* data;
} matrix;

matrix create_matrix(int n, vector* data) {
    matrix m;
    m.n = n;
    m.data = data;
    return m;
}

matrix add_matrix(matrix a, matrix b) {
    matrix m = create_matrix(a.n, a.data);
    for (int i = 0; i < m.n; i++) {
        m.data[i] = add_vector(m.data[i], b.data[i]);
    }
    return m;
}

matrix sub_matrix(matrix a, matrix b) {
    matrix m = create_matrix(a.n, a.data);
    for (int i = 0; i < m.n; i++) {
        m.data[i] = sub_vector(m.data[i], b.data[i]);
    }
    return m;
}

matrix mul_matrix(matrix a, matrix b) {
    matrix m = create_matrix(a.n, a.data);
    for (int i = 0; i < m.n; i++) {
        m.data[i] = mul_vector(m.data[i], b.data[i]);
    }
    return m;
}

matrix div_matrix(matrix a, matrix b) {
    matrix m = create_matrix(a.n, a.data);
    for (int i = 0; i < m.n; i++) {
        m.data[i] = div_vector(m.data[i], b.data[i]);
    }
    return m;
}

matrix pow_matrix(matrix a, ll n) {
    matrix m = create_matrix(a.n, a.data);
    for (int i = 0; i < m.n; i++) {
        m.data[i] = pow_vector(m.data[i], n);
    }
    return m;
}

matrix inv_matrix(matrix a) {
    matrix m = create_matrix(a.n, a.data);
    for (int i = 0; i < m.n; i++) {
        m.data[i] = inv_vector(m.data[i]);
    }
    return m;
}

int main() {
    int n, m, mod;
    scanf("%d%d%d", &n, &m, &mod);

    vector C = create_vector(n + 1, (modint*)malloc((n + 1) * sizeof(modint)));
    for (int i = 0; i <= n; i++) {
        C.data[i] = create_modint(0, mod);
    }
    C.data[0] = create_modint(1, mod);
    for (int i = 1; i <= n; i++) {
        C.data[i] = create_modint(1, mod);
        for (int j = i - 1; j >= 1; j--) {
            C.data[j] = add_modint(C.data[j], C.data[j - 1]);
        }
    }

    vector g = create_vector(n + 1, (modint*)malloc((n + 1) * sizeof(modint)));
    for (int i = 0; i <= n; i++) {
        g.data[i] = create_modint(0, mod);
    }
    for (int i = 0; i <= n; i++) {
        g.data[i] = create_modint((ll)i * (i + 1) / 2, mod);
    }

    vector* f = (vector*)malloc((n + 1) * sizeof(vector));
    for (int i = 0; i <= n; i++) {
        f[i] = create_vector(2, (modint*)malloc(2 * sizeof(modint)));
        f[i].data[0] = create_modint(0, mod);
        f[i].data[1] = create_modint(0, mod);
    }

    f[0].data[0] = create_modint(1, mod);
    f[0].data[1] = create_modint(0, mod);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            modint z = mul_modint(f[j].data[0], f[i - 1 - j].data[0], mod);
            f[i].data[0] = add_modint(f[i].data[0], mul_modint(z, C.data[i - 1][j], mod));
            f[i].data[1] = add_modint(f[i].data[1], mul_modint(z, add_modint(g.data[j], g.data[i - 1 - j]), mod));
            f[i].data[1] = add_modint(f[i].data[1], mul_modint(add_modint(mul_modint(f[i - 1 - j].data[0], f[j].data[1], mod), mul_modint(f[j].data[0], f[i - 1 - j].data[1], mod), mod), C.data[i - 1][j], mod));
        }
    }

    vector* dp = (vector*)malloc((n + 2) * sizeof(vector));
    for (int i = 0; i <= n + 1; i++) {
        dp[i] = create_vector(m + 1, (modint*)malloc((m + 1) * sizeof(modint)));
        for (int j = 0; j <= m; j++) {
            dp[i].data[j] = create_modint(0, mod);
        }
    }

    dp[0].data[0] = create_modint(1, mod);
    for (int l = 0; l <= n; l++) {
        for (int r = l + 1; r <= n + 1; r++) {
            int di = r - l - 1;
            for (int i = 0; i + di <= m; i++) {
                modint z = mul_modint(dp[l].data[i], f[di].data[0], mod);
                dp[r].data[i + di] = add_modint(dp[r].data[i + di], mul_modint(z, C.data[i + di][di], mod));
                dp[r].data[i + di] = add_modint(dp[r].data[i + di], mul_modint(add_modint(mul_modint(dp[l].data[i].data[1], f[di].data[0], mod), mul_modint(dp[l].data[i].data[0], f[di].data[1], mod), mod), C.data[i + di][di], mod));
            }
        }
    }

    printf("%lld\n", dp[n + 1].data[m].data[1]);
    return 0;
}
