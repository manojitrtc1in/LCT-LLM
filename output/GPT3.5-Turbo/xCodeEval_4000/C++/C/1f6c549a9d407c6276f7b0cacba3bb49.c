#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define K 18

typedef long long ll;

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
    return mint((ll)a.n * b.n % MOD);
}

Mint mint_pow(Mint a, int n) {
    Mint res = mint(1);
    while (n > 0) {
        if (n & 1) {
            res = mint_mul(res, a);
        }
        a = mint_mul(a, a);
        n >>= 1;
    }
    return res;
}

Mint mint_inv(Mint a) {
    return mint_pow(a, MOD - 2);
}

typedef struct {
    int deg;
    Mint *c;
} Poly;

Poly poly(int deg) {
    Poly p;
    p.deg = deg;
    p.c = (Mint *)malloc((deg + 1) * sizeof(Mint));
    for (int i = 0; i <= deg; i++) {
        p.c[i] = mint(0);
    }
    return p;
}

void poly_add(Poly *a, Poly *b) {
    int deg = a->deg > b->deg ? a->deg : b->deg;
    for (int i = 0; i <= deg; i++) {
        a->c[i] = mint_add(a->c[i], b->c[i]);
    }
}

void poly_sub(Poly *a, Poly *b) {
    int deg = a->deg > b->deg ? a->deg : b->deg;
    for (int i = 0; i <= deg; i++) {
        a->c[i] = mint_sub(a->c[i], b->c[i]);
    }
}

void poly_mul(Poly *a, Poly *b) {
    int deg = a->deg + b->deg;
    Poly res = poly(deg);
    for (int i = 0; i <= a->deg; i++) {
        for (int j = 0; j <= b->deg; j++) {
            res.c[i + j] = mint_add(res.c[i + j], mint_mul(a->c[i], b->c[j]));
        }
    }
    *a = res;
}

void poly_div(Poly *a, Poly *b) {
    int deg = a->deg - b->deg;
    Poly res = poly(deg);
    while (a->deg >= b->deg) {
        int d = a->deg - b->deg;
        Mint coef = mint_mul(a->c[a->deg], mint_inv(b->c[b->deg]));
        res.c[d] = coef;
        for (int i = 0; i <= b->deg; i++) {
            a->c[d + i] = mint_sub(a->c[d + i], mint_mul(b->c[i], coef));
        }
        a->deg--;
    }
    *a = res;
}

Poly poly_log(Poly *a) {
    int deg = a->deg;
    Poly res = poly(deg);
    for (int i = 1; i <= deg; i++) {
        res.c[i - 1] = mint_mul(a->c[i], mint_inv(mint(i)));
    }
    return res;
}

Poly poly_exp(Poly *a) {
    int deg = a->deg;
    Poly res = poly(deg);
    res.c[0] = mint(1);
    for (int i = 1; i <= deg; i++) {
        res.c[i] = mint_mul(a->c[i - 1], mint(i));
    }
    return res;
}

Poly poly_pow(Poly *a, int n) {
    Poly res = poly(a->deg);
    res.c[0] = mint(1);
    while (n > 0) {
        if (n & 1) {
            poly_mul(&res, a);
        }
        poly_mul(a, a);
        n >>= 1;
    }
    return res;
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

    Poly A = poly(2e5 + 1000);
    A.c[0] = mint(1);
    A.c[1] = mint((k - 2) % MOD);
    A.c[2] = mint(1);

    Poly B = poly_log(&A);
    for (int i = 0; i <= B.deg; i++) {
        B.c[i] = mint_mul(B.c[i], mint(n - cnt));
    }

    Poly C = poly_exp(&B);

    Mint ans = mint_pow(mint(k % MOD), n - cnt);
    for (int i = 0; i <= n - cnt; i++) {
        ans = mint_sub(ans, C.c[i]);
    }

    ans = mint_mul(ans, mint_pow(mint(k % MOD), cnt));
    printf("%d\n", ans.n);

    return 0;
}
