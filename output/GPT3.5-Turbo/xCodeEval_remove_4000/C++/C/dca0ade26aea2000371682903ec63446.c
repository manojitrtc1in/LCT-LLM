#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    ll mod;
    ll root;
    ll im;
} modinfo;

typedef struct {
    ll v;
} mint;

modinfo base0 = {1045430273, 3, 0};
modinfo base1 = {1051721729, 6, 0};
modinfo base2 = {1053818881, 7, 0};

mint modular_pow(mint x, ll n, ll mod) {
    mint res = {1};
    while (n > 0) {
        if (n & 1) {
            res.v = (res.v * x.v) % mod;
        }
        x.v = (x.v * x.v) % mod;
        n >>= 1;
    }
    return res;
}

mint modular_inverse(mint x, ll mod) {
    return modular_pow(x, mod - 2, mod);
}

mint modular_add(mint a, mint b, ll mod) {
    return (a.v + b.v) % mod;
}

mint modular_subtract(mint a, mint b, ll mod) {
    return (a.v - b.v + mod) % mod;
}

mint modular_multiply(mint a, mint b, ll mod) {
    return (a.v * b.v) % mod;
}

mint modular_divide(mint a, mint b, ll mod) {
    mint inv = modular_inverse(b, mod);
    return modular_multiply(a, inv, mod);
}

mint modular_factorial(ll n, ll mod) {
    mint res = {1};
    for (ll i = 2; i <= n; i++) {
        res.v = (res.v * i) % mod;
    }
    return res;
}

mint modular_choose(ll n, ll k, ll mod) {
    mint numerator = modular_factorial(n, mod);
    mint denominator = modular_multiply(modular_factorial(k, mod), modular_factorial(n - k, mod), mod);
    return modular_divide(numerator, denominator, mod);
}

mint modular_binomial(ll a, ll b, ll mod) {
    return modular_choose(a + b, b, mod);
}

mint modular_id7(ll n, ll mod) {
    return modular_subtract(modular_binomial(n, n, mod), (n - 1 >= 0) ? modular_binomial(n - 1, n + 1, mod) : 0, mod);
}

mint modular_id3(mint a, mint* f, int k, ll mod) {
    if (a.v == 1) {
        return f[0];
    } else {
        mint* g = (mint*)malloc((k + 1) * sizeof(mint));
        mint r = {1};
        for (int i = 0; i <= k; i++) {
            g[i].v = (f[i].v * r.v) % mod;
            r.v = (r.v * a.v) % mod;
        }
        mint c = {0};
        mint w = modular_inverse(modular_subtract(1, a, mod), mod);
        mint r = {1};
        for (int i = 0; i <= k; i++) {
            w.v = (w.v + modular_multiply(modular_choose(k + 1, i, mod), r.v)) % mod;
            r.v = (r.v * (-a.v)) % mod;
            c.v = (c.v + modular_multiply(g[k - i], w.v)) % mod;
        }
        c.v = (c.v * modular_inverse(modular_subtract(1, a, mod), mod)) % mod;
        free(g);
        return c;
    }
}

mint modular_id6(mint a, mint* f, int k, ll mod) {
    mint ans = {0};
    mint w = modular_inverse(modular_subtract(1, a, mod), mod);
    mint cur = {1};
    for (int i = 0; i < k; i++) {
        cur.v = (cur.v * w.v) % mod;
        ans.v = (ans.v + modular_multiply(modular_multiply(modular_factorial(i, mod), cur.v, mod), f[i].v, mod)) % mod;
    }
    return ans;
}

mint modular_id4(mint* a, mint* b, int n, int m, int mx, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i * m + j] = a[i * m + j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            q[i * m + j] = b[i * m + j];
        }
    }
    id1(p, s, 0);
    id1(q, s, 0);
    for (int i = 0; i < s; i++) {
        p[i].v = (p[i].v * q[i].v) % mod;
    }
    id1(p, s, 1);
    mint ans = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans.v = (ans.v + p[i * m + j].v) % mod;
        }
    }
    free(p);
    free(q);
    return ans;
}

mint modular_id0(mint** x, int n1, int m1, mint** y, int n2, int m2, ll mod) {
    int n = n1 + n2 - 1;
    int m = m1 + m2 - 1;
    mint** res = (mint**)malloc(n * sizeof(mint*));
    for (int i = 0; i < n; i++) {
        res[i] = (mint*)malloc(m * sizeof(mint));
    }
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            res[i][j] = x[i][j];
        }
    }
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            res[i][j] = y[i][j];
        }
    }
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i * m + j] = res[i][j];
        }
    }
    id1(p, s, 0);
    for (int i = 0; i < s; i++) {
        q[i] = p[i];
    }
    id1(q, s, 0);
    for (int i = 0; i < s; i++) {
        p[i].v = (p[i].v * q[i].v) % mod;
    }
    id1(p, s, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = p[i * m + j];
        }
    }
    mint ans = res[n - 1][m - 1];
    for (int i = 0; i < n; i++) {
        free(res[i]);
    }
    free(res);
    free(p);
    free(q);
    return ans;
}

mint modular_multiply(mint** x, int n1, int m1, mint** y, int n2, int m2, ll mod) {
    mint** res = (mint**)malloc(n1 * sizeof(mint*));
    for (int i = 0; i < n1; i++) {
        res[i] = (mint*)malloc(m2 * sizeof(mint));
    }
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            res[i][j] = modular_id0(x, n1, m1, y, n2, m2, mod);
        }
    }
    mint ans = res[n1 - 1][m2 - 1];
    for (int i = 0; i < n1; i++) {
        free(res[i]);
    }
    free(res);
    return ans;
}

mint modular_id1(mint* f, int n, ll mod) {
    int b = n;
    if (b >>= 1) {
        for (int i = 0; i < b; i++) {
            mint x = f[i + b];
            f[i + b].v = (f[i].v + mod - x.v) % mod;
            f[i].v = (f[i].v + x.v) % mod;
        }
    }
    if (b >>= 1) {
        mint p = {1};
        for (int i = 0, k = 0; i < n; i += b * 2) {
            for (int j = i; j < i + b; j++) {
                mint x = modular_multiply(f[j + b], p, mod);
                f[j + b].v = (f[j].v + mod - x.v) % mod;
                f[j].v = (f[j].v + x.v) % mod;
            }
            p.v = (p.v * base0.root) % mod;
        }
    }
    while (b) {
        if (b >>= 1) {
            mint p = {1};
            for (int i = 0, k = 0; i < n; i += b * 2) {
                for (int j = i; j < i + b; j++) {
                    mint x = modular_multiply(f[j + b], p, mod);
                    f[j + b].v = (f[j].v + mod - x.v) % mod;
                    f[j].v = (f[j].v + x.v) % mod;
                }
                p.v = (p.v * base1.root) % mod;
            }
        }
        if (b >>= 1) {
            mint p = {1};
            for (int i = 0, k = 0; i < n; i += b * 2) {
                for (int j = i; j < i + b; j++) {
                    mint x = modular_multiply(f[j + b], p, mod);
                    f[j].v = (f[j].v < base2.mod * 2) ? f[j].v : f[j].v - base2.mod * 2;
                    f[j + b].v = (f[j].v + mod - x.v) % mod;
                    f[j].v = (f[j].v + x.v) % mod;
                }
                p.v = (p.v * base2.root) % mod;
            }
        }
    }
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int len = 1 << (n - 1);
    for (int i = 0; i < n; i += len) {
        for (int j = 0; j < n; j += len) {
            int x_len = (len < n - i) ? len : n - i;
            int y_len = (len < n - j) ? len : n - j;
            mint* d = (mint*)malloc((x_len + y_len - 1) * sizeof(mint));
            for (int k = 0; k < x_len + y_len - 1; k++) {
                d[k].v = 0;
            }
            for (int k = 0; k < x_len; k++) {
                for (int l = 0; l < y_len; l++) {
                    d[k + l].v = (d[k + l].v + modular_multiply(x[i + k], y[j + l], mod).v) % mod;
                }
            }
            for (int k = 0; k < x_len + y_len - 1; k++) {
                x[i + j + k].v = d[k].v;
            }
            free(d);
        }
    }
    return x;
}

mint* half_fmt(mint* f, int n, ll mod) {
    int b = n;
    int lv = 0;
    if (b >>= 1) {
        mint p = {base0.root};
        for (int i = 0, k = 0; i < n; i += b * 2) {
            for (int j = i; j < i + b; j++) {
                mint x = modular_multiply(f[j + b], p, mod);
                f[j + b].v = (f[j].v + mod - x.v) % mod;
                f[j].v = (f[j].v + x.v) % mod;
            }
            p.v = (p.v * base0.root) % mod;
        }
    }
    if (b >>= 1) {
        mint p = {base1.root};
        for (int i = 0, k = 0; i < n; i += b * 2) {
            for (int j = i; j < i + b; j++) {
                mint x = modular_multiply(f[j + b], p, mod);
                f[j + b].v = (f[j].v + mod - x.v) % mod;
                f[j].v = (f[j].v + x.v) % mod;
            }
            p.v = (p.v * base1.root) % mod;
        }
    }
    while (b) {
        if (b >>= 1) {
            mint p = {base0.root};
            for (int i = 0, k = 0; i < n; i += b * 2) {
                for (int j = i; j < i + b; j++) {
                    mint x = modular_multiply(f[j + b], p, mod);
                    f[j + b].v = (f[j].v + mod - x.v) % mod;
                    f[j].v = (f[j].v + x.v) % mod;
                }
                p.v = (p.v * base0.root) % mod;
            }
        }
        if (b >>= 1) {
            mint p = {base0.root};
            for (int i = 0, k = 0; i < n; i += b * 2) {
                for (int j = i; j < i + b; j++) {
                    mint x = modular_multiply(f[j + b], p, mod);
                    f[j].v = (f[j].v < base2.mod * 2) ? f[j].v : f[j].v - base2.mod * 2;
                    f[j + b].v = (f[j].v + mod - x.v) % mod;
                    f[j].v = (f[j].v + x.v) % mod;
                }
                p.v = (p.v * base2.root) % mod;
            }
        }
    }
    return f;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

mint* multiply(mint* x, int n, mint* y, int m, ll mod) {
    int s = 1;
    while (s < n * m) {
        s *= 2;
    }
    mint* p = (mint*)malloc(s * sizeof(mint));
    mint* q = (mint*)malloc(s * sizeof(mint));
    for (int i = 0; i < n; i++) {
        p[i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        q[i] = y[i];
    }
    half_fmt(p, s, mod);
    half_fmt(q, s, mod);
    for (int i = 0; i < s; i++) {
        p[i] = modular_multiply(p[i], q[i], mod);
    }
    half_fmt(p, s, mod);
    return p;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int* ls = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ls[i]);
    }
    int tot = 0;
    for (int i = 0; i < n; i++) {
        tot += ls[i];
    }
    mint* buf = (mint*)malloc(n * sizeof(mint));
    for (int i = 0; i < n; i++) {
        int s = (ls[i] - 1) / k + 1;
        mint* f = (mint*)malloc(s * 2 * sizeof(mint));
        for (int num = 0; num < s; num++) {
            mint w = {ls[i] - k * num};
            if (num > 0) {
                f[num * 2] = modular_multiply(modular_pow(w, num - 1, tot), modular_inverse(modular_factorial(num - 1, tot), tot), tot);
            }
            f[num * 2 + 1] = modular_multiply(modular_pow(w, num, tot), modular_inverse(modular_factorial(num, tot), tot), tot);
        }
        buf[i] = modular_id3(w, f, s, tot);
        free(f);
    }
    for (int i = 0; i < n - 1; i++) {
        int j = i + 1;
        buf[i] = modular_id0(buf[i], buf[j], tot);
        free(buf[j]);
    }
    mint sum = {0};
    for (int num = 1; num < tot / k; num++) {
        mint* f = (mint*)malloc((num + 1) * sizeof(mint));
        for (int i = 0; i < num + 1; i++) {
            if (i + num - n >= 0) {
                f[i + num - n] = buf[num][i];
            } else {
                f[i + num - n] = {0};
            }
        }
        mint w = {tot - num * k};
        mint val = modular_id6(w, f, num + 1, tot);
        if (num % 2 == 0) {
            val = modular_subtract({0}, val, tot);
        }
        sum = modular_add(sum, val, tot);
        free(f);
    }
    printf("%lld\n", sum.v);
    free(ls);
    free(buf);
    return 0;
}
