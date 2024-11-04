#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define K 18

typedef struct {
    int n;
} Mint;

Mint mint(int n) {
    Mint m;
    m.n = n;
    return m;
}

Mint mint_add(Mint a, Mint b) {
    return mint((a.n + b.n) % MOD);
}

Mint mint_sub(Mint a, Mint b) {
    return mint((a.n - b.n + MOD) % MOD);
}

Mint mint_mul(Mint a, Mint b) {
    return mint((long long)a.n * b.n % MOD);
}

Mint mint_pow(Mint a, int n) {
    Mint r = mint(1);
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

Poly poly_add(Poly a, Poly b) {
    int n = a.n > b.n ? a.n : b.n;
    Poly p = poly(n);
    for (int i = 0; i <= n; i++) {
        p.c[i] = mint_add(a.c[i], b.c[i]);
    }
    return p;
}

Poly poly_sub(Poly a, Poly b) {
    int n = a.n > b.n ? a.n : b.n;
    Poly p = poly(n);
    for (int i = 0; i <= n; i++) {
        p.c[i] = mint_sub(a.c[i], b.c[i]);
    }
    return p;
}

Poly poly_mul(Poly a, Poly b) {
    int n = a.n + b.n;
    Poly p = poly(n);
    for (int i = 0; i <= a.n; i++) {
        for (int j = 0; j <= b.n; j++) {
            p.c[i + j] = mint_add(p.c[i + j], mint_mul(a.c[i], b.c[j]));
        }
    }
    return p;
}

Poly poly_pow(Poly a, int n) {
    Poly r = poly(0);
    r.c[0] = mint(1);
    Poly x = a;
    while (n > 0) {
        if (n & 1) {
            r = poly_mul(r, x);
        }
        x = poly_mul(x, x);
        n >>= 1;
    }
    return r;
}

Poly poly_inv(Poly a) {
    int n = a.n;
    Poly r = poly(n);
    r.c[0] = mint_inv(a.c[0]);
    for (int i = 1; i <= n; i++) {
        Mint s = mint(0);
        for (int j = 1; j <= i; j++) {
            s = mint_add(s, mint_mul(a.c[j], r.c[i - j]));
        }
        r.c[i] = mint_mul(mint_sub(mint(0), s), mint_inv(a.c[0]));
    }
    return r;
}

Poly poly_log(Poly a) {
    int n = a.n;
    Poly r = poly(n);
    for (int i = 1; i <= n; i++) {
        r.c[i] = mint_mul(a.c[i], mint_inv(mint(i)));
    }
    return r;
}

Poly poly_exp(Poly a) {
    int n = a.n;
    Poly r = poly(n);
    r.c[0] = mint(1);
    for (int i = 1; i <= n; i++) {
        Mint s = mint(0);
        for (int j = 1; j <= i; j++) {
            s = mint_add(s, mint_mul(a.c[j], r.c[i - j]));
        }
        r.c[i] = mint_mul(s, mint_inv(mint(i)));
    }
    return r;
}

Mint poly_eval(Poly a, Mint x) {
    Mint r = mint(0);
    for (int i = a.n; i >= 0; i--) {
        r = mint_add(mint_mul(r, x), a.c[i]);
    }
    return r;
}

Poly poly_interpolation(int n, int* a, int* b) {
    Poly r = poly(n);
    for (int i = 0; i < n; i++) {
        r.c[i] = mint(b[i]);
    }
    return r;
}

Poly poly_quotient(Poly a, Poly b) {
    int n = a.n;
    int m = b.n;
    if (m > n) {
        return poly(0);
    }
    Poly r = poly(n);
    for (int i = n; i >= m; i--) {
        Mint x = mint_div(a.c[i], b.c[m]);
        r.c[i - m] = x;
        for (int j = 0; j < m; j++) {
            a.c[i - m + j] = mint_sub(a.c[i - m + j], mint_mul(x, b.c[j]));
        }
    }
    return r;
}

Mint poly_eval2(Poly a, Mint* p, int m) {
    Mint r = mint(0);
    for (int i = 0; i < m; i++) {
        r = mint_add(mint_mul(r, p[i]), poly_eval(a, p[i]));
    }
    return r;
}

Poly poly_sqrt(Poly a) {
    int n = a.n;
    Poly r = poly(n);
    r.c[0] = mint_sqrt(a.c[0]);
    for (int i = 1; i <= n; i++) {
        Mint s = mint(0);
        for (int j = 1; j <= i; j++) {
            s = mint_add(s, mint_mul(a.c[j], r.c[i - j]));
        }
        r.c[i] = mint_mul(mint_div(s, mint(2 * i)), mint_inv(r.c[0]));
    }
    return r;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int* hs = (int*)malloc(n * sizeof(int));
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

    Poly B = poly_log(A);
    for (int i = 0; i <= B.n; i++) {
        B.c[i] = mint_mul(B.c[i], mint(n - cnt));
    }

    Poly C = poly_exp(B);

    Mint ans = mint_pow(mint(k % MOD), n - cnt);
    for (int i = 0; i <= n - cnt; i++) {
        ans = mint_sub(ans, C.c[i]);
    }

    ans = mint_mul(ans, mint_pow(mint(k % MOD), cnt));
    printf("%d\n", ans.n);
    return 0;
}
