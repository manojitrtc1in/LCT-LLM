#include<stdio.h>

#define MOD 998244353
#define K 18

typedef long long ll;

ll pow_mod(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

typedef struct {
    ll n;
} Mint;

Mint mint(ll n) {
    Mint m;
    m.n = n;
    return m;
}

Mint mint_neg(Mint a) {
    return mint(a.n ? MOD - a.n : 0);
}

Mint mint_add(Mint a, Mint b) {
    a.n += b.n;
    if (a.n >= MOD) {
        a.n -= MOD;
    }
    return a;
}

Mint mint_sub(Mint a, Mint b) {
    a.n -= b.n;
    if (a.n < 0) {
        a.n += MOD;
    }
    return a;
}

Mint mint_mul(Mint a, Mint b) {
    a.n = (a.n * b.n) % MOD;
    return a;
}

Mint mint_div(Mint a, Mint b) {
    a.n = (a.n * pow_mod(b.n, MOD - 2, MOD)) % MOD;
    return a;
}

Mint mint_pow(Mint a, ll n) {
    Mint res = mint(1);
    while (n) {
        if (n & 1) {
            res = mint_mul(res, a);
        }
        a = mint_mul(a, a);
        n >>= 1;
    }
    return res;
}

typedef struct {
    int n;
    Mint inv[1 << K];
} Minv;

Minv minv() {
    Minv m;
    for (int i = 2; i < (1 << K); i++) {
        m.inv[i] = mint_sub(mint(0), mint_mul(mint(MOD / i), m.inv[MOD % i]));
    }
    return m;
}

typedef struct {
    Mint w[1 << (K - 1)];
    Mint y[1 << (K - 1)];
    Mint v[1 << (K - 1)];
} FFT;

FFT fft() {
    FFT f;
    f.w[(1 << (K - 1)) / 4] = mint_pow(mint(3), (MOD - 1) / (1 << K));
    f.y[(1 << (K - 1)) / 4] = mint_pow(f.w[(1 << (K - 1)) / 4], MOD - 2);
    for (int j = (1 << (K - 1)) / 4; j > 1; j >>= 1) {
        f.w[j / 2] = mint_mul(f.w[j], f.w[j]);
        f.y[j / 2] = mint_mul(f.y[j], f.y[j]);
    }
    f.w[0] = f.y[0] = mint(1);
    for (int j = 2; j < (1 << (K - 1)); j <<= 1) {
        for (int i = 1; i < j; i++) {
            f.w[j + i] = mint_mul(f.w[j], f.w[i]);
            f.y[j + i] = mint_mul(f.y[j], f.y[i]);
        }
    }
    f.v[0] = mint(1);
    for (int i = 1; i < (1 << K); i++) {
        f.v[i] = mint_mul(f.w[(i - 1) & -i], f.v[i - 1]);
    }
    return f;
}

typedef struct {
    int n;
    Mint c[1 << K];
} Poly;

Poly poly(int n) {
    Poly p;
    p.n = n;
    for (int i = 0; i <= n; i++) {
        p.c[i] = mint(0);
    }
    return p;
}

int poly_deg(Poly p) {
    while (p.n >= 0 && p.c[p.n].n == 0) {
        p.n--;
    }
    return p.n;
}

Mint poly_at(Poly p, int n) {
    if (n <= p.n) {
        return p.c[n];
    } else {
        return mint(0);
    }
}

Poly poly_add(Poly a, Poly b) {
    Poly res = poly(a.n > b.n ? a.n : b.n);
    for (int i = 0; i <= res.n; i++) {
        res.c[i] = mint_add(poly_at(a, i), poly_at(b, i));
    }
    return res;
}

Poly poly_sub(Poly a, Poly b) {
    Poly res = poly(a.n > b.n ? a.n : b.n);
    for (int i = 0; i <= res.n; i++) {
        res.c[i] = mint_sub(poly_at(a, i), poly_at(b, i));
    }
    return res;
}

Poly poly_mul(Poly a, Poly b) {
    Poly res = poly(a.n + b.n);
    for (int i = 0; i <= a.n; i++) {
        for (int j = 0; j <= b.n; j++) {
            res.c[i + j] = mint_add(res.c[i + j], mint_mul(poly_at(a, i), poly_at(b, j)));
        }
    }
    return res;
}

Poly poly_div(Poly a, Poly b, Minv m) {
    int da = poly_deg(a);
    int db = poly_deg(b);
    if (db > da) {
        return poly(0);
    }
    Poly res = poly(da - db);
    for (int i = da; i >= db; i--) {
        if (poly_at(a, i).n != 0) {
            Mint x = mint_div(poly_at(a, i), poly_at(b, db));
            for (int j = 1; j <= db; j++) {
                a.c[i - j] = mint_sub(poly_at(a, i - j), mint_mul(x, poly_at(b, db - j)));
            }
            res.c[i - db] = x;
        }
    }
    return res;
}

Poly poly_mod(Poly a, Poly b, Minv m) {
    int da = poly_deg(a);
    int db = poly_deg(b);
    if (db > da) {
        return a;
    }
    for (int i = da; i >= db; i--) {
        if (poly_at(a, i).n != 0) {
            Mint x = mint_div(poly_at(a, i), poly_at(b, db));
            for (int j = 1; j <= db; j++) {
                a.c[i - j] = mint_sub(poly_at(a, i - j), mint_mul(x, poly_at(b, db - j)));
            }
        }
    }
    return a;
}

Poly poly_inv(Poly a, Minv m) {
    int da = poly_deg(a);
    Poly res = poly(da);
    res.c[0] = mint_div(mint(1), poly_at(a, 0));
    Mint y = mint_div(mint((MOD + 1) / 2), mint(2));
    for (int i = 1; i <= da; i++) {
        res.c[i] = mint_mul(y, mint_sub(mint(0), poly_at(a, i)));
    }
    for (int i = 1; i <= da; i <<= 1) {
        for (int j = 0; j < i; j++) {
            Mint w = m.inv[i + j];
            for (int k = j; k <= da; k += i << 1) {
                Mint t = mint_mul(w, res.c[k + i]);
                res.c[k + i] = mint_sub(res.c[k], t);
                res.c[k] = mint_add(res.c[k], t);
            }
        }
    }
    return res;
}

Poly poly_exp(Poly a, Minv m) {
    int da = poly_deg(a);
    Poly res = poly(0);
    res.c[0] = mint(1);
    for (int i = 1; i <= da; i <<= 1) {
        Poly b = poly(i);
        for (int j = 0; j < i; j++) {
            b.c[j] = a.c[j];
        }
        Poly c = poly_mul(poly_mul(res, res), b);
        for (int j = 0; j < i; j++) {
            c.c[j] = mint_sub(b.c[j], c.c[j]);
        }
        for (int j = i; j < i << 1; j++) {
            c.c[j] = mint(0);
        }
        res = poly_mul(res, c);
    }
    return res;
}

Poly poly_log(Poly a, Minv m) {
    int da = poly_deg(a);
    Poly res = poly(da);
    for (int i = 1; i <= da; i++) {
        res.c[i] = mint_div(a.c[i], mint(i));
    }
    for (int i = 1; i <= da; i <<= 1) {
        Poly b = poly(i);
        for (int j = 0; j < i; j++) {
            b.c[j] = res.c[j];
        }
        Poly c = poly_mul(b, poly_mul(a, poly_inv(b, m)));
        for (int j = 0; j < i; j++) {
            res.c[j] = mint_sub(c.c[j + i], res.c[j]);
        }
    }
    return res;
}

Poly poly_pow(Poly a, ll n, Minv m) {
    Poly res = poly(0);
    res.c[0] = mint(1);
    while (n) {
        if (n & 1) {
            res = poly_mul(res, a);
        }
        a = poly_mul(a, a);
        n >>= 1;
    }
    return res;
}

Poly poly_sqrt(Poly a, Minv m) {
    int da = poly_deg(a);
    Poly res = poly(da);
    res.c[0] = mint(1);
    for (int i = 1; i <= da; i <<= 1) {
        Poly b = poly(i);
        for (int j = 0; j < i; j++) {
            b.c[j] = res.c[j];
        }
        Poly c = poly_mul(b, poly_inv(b, m));
        for (int j = 0; j < i; j++) {
            res.c[j] = mint_sub(a.c[j + i], c.c[j]);
        }
    }
    return res;
}

Poly poly_quotient(Poly a, Poly b, Minv m) {
    int da = poly_deg(a);
    int db = poly_deg(b);
    if (db > da) {
        return poly(0);
    }
    Poly res = poly(da - db);
    for (int i = da; i >= db; i--) {
        if (a.c[i].n != 0) {
            Mint x = mint_div(a.c[i], b.c[db]);
            for (int j = 1; j <= db; j++) {
                a.c[i - j] = mint_sub(a.c[i - j], mint_mul(x, b.c[db - j]));
            }
            res.c[i - db] = x;
        }
    }
    return res;
}

Poly poly_modulo(Poly a, Poly b, Minv m) {
    int da = poly_deg(a);
    int db = poly_deg(b);
    if (db > da) {
        return a;
    }
    for (int i = da; i >= db; i--) {
        if (a.c[i].n != 0) {
            Mint x = mint_div(a.c[i], b.c[db]);
            for (int j = 1; j <= db; j++) {
                a.c[i - j] = mint_sub(a.c[i - j], mint_mul(x, b.c[db - j]));
            }
        }
    }
    return a;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

vec poly_eval2(Poly p, vec P) {
    int m = P.n;
    if (m <= (1 << _ls)) {
        vec v = vec(m);
        for (int i = 0; i < m; i++) {
            v.a[i] = poly_eval(p, P.a[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    vec v = vec(m);
    vec w = vec(m);
    for (int i = 0; i < m; i++) {
        w.a[i] = P.a[i];
    }
    fft_fft(w.a, k);
    for (int i = 0; i < m; i++) {
        v.a[i] = w.a[i];
    }
    return v;
}

Poly poly_interpolation(vec a, vec b) {
    int m = a.n;
    assert(b.n == m);
    return poly(0);
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int hs[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &hs[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (hs[i] == hs[(i + 1) % n]) {
            cnt++;
        }
    }

    if (cnt == n) {
        printf("0\n");
        return 0;
    }

    Poly A = poly(2e5 + 1000);
    A.c[0] = mint(1);
    A.c[1] = mint((k - 2) % MOD);
    A.c[2] = mint(1);

    Poly B = poly_log(A, minv());
    for (int i = 0; i < B.n; i++) {
        B.c[i] = mint_mul(B.c[i], mint(n - cnt));
    }

    Poly C = poly_exp(B, minv());

    Mint ans = mint_pow(mint(k % MOD), n - cnt);
    for (int i = 0; i <= n - cnt; i++) {
        ans = mint_sub(ans, C.c[i]);
    }

    ans = mint_mul(ans, mint_pow(mint(k % MOD), cnt));
    printf("%lld\n", ans.n);
    return 0;
}
