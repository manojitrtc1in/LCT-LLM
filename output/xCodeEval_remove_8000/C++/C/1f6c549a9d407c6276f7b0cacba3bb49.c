#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define K 18

typedef struct {
    int n;
} Mint;

Mint mint_new(int n) {
    Mint m;
    m.n = n;
    return m;
}

Mint mint_add(Mint a, Mint b) {
    return mint_new((a.n + b.n) % MOD);
}

Mint mint_sub(Mint a, Mint b) {
    return mint_new((a.n - b.n + MOD) % MOD);
}

Mint mint_mul(Mint a, Mint b) {
    return mint_new((a.n * b.n) % MOD);
}

Mint mint_pow(Mint a, int n) {
    Mint r = mint_new(1);
    Mint x = a;
    while (n > 0) {
        if (n & 1) {
            r = mint_mul(r, x);
        }
        x = mint_mul(x, x);
        n >>= 1;
    }
    return r;
}

Mint mint_inv(Mint a) {
    return mint_pow(a, MOD - 2);
}

typedef struct {
    int n;
    Mint *c;
} Poly;

Poly poly_new(int n) {
    Poly p;
    p.n = n;
    p.c = (Mint *)malloc((n + 1) * sizeof(Mint));
    for (int i = 0; i <= n; i++) {
        p.c[i] = mint_new(0);
    }
    return p;
}

void poly_add(Poly *a, Poly b) {
    int n = a->n > b.n ? a->n : b.n;
    for (int i = 0; i <= n; i++) {
        a->c[i] = mint_add(a->c[i], b.c[i]);
    }
}

void poly_sub(Poly *a, Poly b) {
    int n = a->n > b.n ? a->n : b.n;
    for (int i = 0; i <= n; i++) {
        a->c[i] = mint_sub(a->c[i], b.c[i]);
    }
}

void poly_mul(Poly *a, Poly b) {
    int n = a->n + b.n;
    Poly c = poly_new(n);
    for (int i = 0; i <= a->n; i++) {
        for (int j = 0; j <= b.n; j++) {
            c.c[i + j] = mint_add(c.c[i + j], mint_mul(a->c[i], b.c[j]));
        }
    }
    free(a->c);
    a->n = n;
    a->c = c.c;
}

void poly_pow(Poly *a, int n) {
    Poly r = poly_new(a->n);
    r.c[0] = mint_new(1);
    Poly x = *a;
    while (n > 0) {
        if (n & 1) {
            poly_mul(&r, x);
        }
        poly_mul(&x, x);
        n >>= 1;
    }
    free(a->c);
    a->n = r.n;
    a->c = r.c;
}

void poly_inv(Poly *a) {
    int n = a->n;
    Poly r = poly_new(n);
    r.c[0] = mint_inv(a->c[0]);
    Mint im = mint_sub(mint_new(0), mint_new((MOD + 1) / 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            r.c[i] = mint_sub(r.c[i], mint_mul(a->c[j], r.c[i - j]));
        }
        r.c[i] = mint_mul(r.c[i], im);
    }
    free(a->c);
    a->n = r.n;
    a->c = r.c;
}

void poly_log(Poly *a) {
    int n = a->n;
    Poly r = poly_new(n);
    Mint im = mint_new((MOD + 1) / 2);
    for (int i = 1; i <= n; i++) {
        r.c[i] = mint_mul(a->c[i], mint_inv(mint_new(i)));
    }
    poly_inv(&r);
    free(a->c);
    a->n = r.n;
    a->c = r.c;
}

void poly_exp(Poly *a) {
    int n = a->n;
    Poly r = poly_new(n);
    r.c[0] = mint_new(1);
    Mint im = mint_new((MOD + 1) / 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            r.c[i] = mint_add(r.c[i], mint_mul(a->c[j], r.c[i - j]));
        }
        r.c[i] = mint_mul(r.c[i], im);
    }
    free(a->c);
    a->n = r.n;
    a->c = r.c;
}

void poly_div(Poly *a, Poly b) {
    int n = a->n;
    int m = b.n;
    if (m > n) {
        free(a->c);
        a->n = -1;
        a->c = NULL;
        return;
    }
    for (int i = n; i >= m; i--) {
        if (a->c[i].n == 0) {
            continue;
        }
        Mint x = mint_mul(a->c[i], mint_inv(b.c[m]));
        for (int j = 1; j <= m; j++) {
            a->c[i - j] = mint_sub(a->c[i - j], mint_mul(x, b.c[m - j]));
        }
        a->c[i] = mint_new(0);
    }
    while (n >= 0 && a->c[n].n == 0) {
        n--;
    }
    a->n = n;
}

Mint poly_eval(Poly a, Mint x) {
    Mint r = mint_new(0);
    for (int i = a.n; i >= 0; i--) {
        r = mint_add(mint_mul(r, x), a.c[i]);
    }
    return r;
}

typedef struct {
    int n;
    Mint *c;
} Vec;

Vec vec_new(int n) {
    Vec v;
    v.n = n;
    v.c = (Mint *)malloc(n * sizeof(Mint));
    return v;
}

void vec_free(Vec v) {
    free(v.c);
}

Vec vec_eval2(Poly a, Vec p) {
    int m = p.n;
    if (m <= (1 << K)) {
        Vec v = vec_new(m);
        for (int i = 0; i < m; i++) {
            v.c[i] = poly_eval(a, p.c[i]);
        }
        return v;
    }
    int k = 32 - __builtin_clz(m - 1);
    Poly b = poly_new((1 << k) - 1);
    for (int i = 0; i <= a.n; i++) {
        b.c[i] = a.c[i];
    }
    poly_log(&b);
    for (int i = 0; i <= b.n; i++) {
        b.c[i] = mint_mul(b.c[i], mint_new(m));
    }
    poly_exp(&b);
    Vec v = vec_new(m);
    for (int i = 0; i < m; i++) {
        v.c[i] = b.c[i];
    }
    return v;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int *hs = (int *)malloc(n * sizeof(int));
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

    Poly a = poly_new(2e5 + 1000);
    a.c[0] = mint_new(1);
    a.c[1] = mint_sub(mint_new(k), mint_new(2));
    a.c[2] = mint_new(1);

    Poly b = a;
    poly_log(&b);
    for (int i = 0; i <= b.n; i++) {
        b.c[i] = mint_mul(b.c[i], mint_new(n - cnt));
    }

    Poly c = b;
    poly_exp(&c);

    Mint ans = mint_pow(mint_new(k), n - cnt);
    for (int i = 0; i <= c.n; i++) {
        ans = mint_sub(ans, c.c[i]);
    }

    ans = mint_mul(ans, mint_pow(mint_new(k), cnt));
    printf("%d\n", ans.n);

    free(hs);
    free(a.c);
    free(b.c);
    free(c.c);

    return 0;
}
