#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MOD 998244353
#define K 18
typedef long long Int;

typedef struct {
    int n;
} Mint;

Mint mint(int n) {
    Mint m;
    m.n = (n % MOD + MOD) % MOD;
    return m;
}

Mint mint_add(Mint a, Mint b) {
    return mint(a.n + b.n);
}

Mint mint_sub(Mint a, Mint b) {
    return mint(a.n - b.n);
}

Mint mint_mul(Mint a, Mint b) {
    return mint((long long)a.n * b.n % MOD);
}

Mint mint_pow(Mint a, int exp) {
    Mint res = mint(1);
    while (exp) {
        if (exp & 1) res = mint_mul(res, a);
        a = mint_mul(a, a);
        exp >>= 1;
    }
    return res;
}

Mint mint_inv(Mint a) {
    return mint_pow(a, MOD - 2);
}

typedef struct {
    Mint *c;
    int size;
} Poly;

Poly poly_init(int n) {
    Poly p;
    p.size = n + 1;
    p.c = (Mint *)calloc(p.size, sizeof(Mint));
    return p;
}

void poly_free(Poly *p) {
    free(p->c);
}

void poly_add(Poly *a, Poly *b) {
    int max_size = a->size > b->size ? a->size : b->size;
    a->c = (Mint *)realloc(a->c, max_size * sizeof(Mint));
    for (int i = 0; i < b->size; i++) {
        a->c[i] = mint_add(a->c[i], b->c[i]);
    }
}

void poly_sub(Poly *a, Poly *b) {
    int max_size = a->size > b->size ? a->size : b->size;
    a->c = (Mint *)realloc(a->c, max_size * sizeof(Mint));
    for (int i = 0; i < b->size; i++) {
        a->c[i] = mint_sub(a->c[i], b->c[i]);
    }
}

void poly_mul(Poly *a, Poly *b) {
    int rdeg = a->size + b->size - 2;
    Poly res = poly_init(rdeg);
    for (int i = 0; i < a->size; i++) {
        for (int j = 0; j < b->size; j++) {
            res.c[i + j] = mint_add(res.c[i + j], mint_mul(a->c[i], b->c[j]));
        }
    }
    poly_free(a);
    *a = res;
}

Poly poly_log(Poly *p) {
    assert(p->c[0].n == 1);
    Poly res = poly_init(p->size - 1);
    for (int i = 1; i < p->size; i++) {
        res.c[i - 1] = mint_mul(mint(i), p->c[i]);
    }
    return res;
}

Poly poly_exp(Poly *p) {
    assert(p->c[0].n == 0);
    Poly res = poly_init(p->size);
    res.c[0] = mint(1);
    for (int i = 1; i < p->size; i++) {
        for (int j = 0; j < i; j++) {
            res.c[i] = mint_add(res.c[i], mint_mul(res.c[j], p->c[i - j]));
        }
    }
    return res;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *hs = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &hs[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (hs[i] == hs[(i + 1) % n]) cnt++;
    }

    if (cnt == n) {
        printf("0\n");
        free(hs);
        return 0;
    }

    Poly A = poly_init(200000 + 1000);
    A.c[0] = mint(1);
    A.c[1] = mint((k - 2) % MOD);
    A.c[2] = mint(1);

    Poly B = poly_log(&A);
    for (int i = 0; i < B.size; i++) {
        B.c[i] = mint_mul(B.c[i], mint(n - cnt));
    }

    Poly C = poly_exp(&B);

    Mint ans = mint_pow(mint(k % MOD), n - cnt);
    for (int i = 0; i <= n - cnt; i++) {
        ans = mint_sub(ans, C.c[i]);
    }

    ans = mint_mul(ans, mint_pow(mint(k % MOD), cnt));
    printf("%d\n", ans.n);

    free(hs);
    poly_free(&A);
    poly_free(&B);
    poly_free(&C);
    return 0;
}
