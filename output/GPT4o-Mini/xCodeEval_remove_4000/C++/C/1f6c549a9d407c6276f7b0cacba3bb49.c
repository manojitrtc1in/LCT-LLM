#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MOD 998244353
#define K 18
#define MAX_SIZE 200000

typedef long long Int;

typedef struct {
    int n;
} Mint;

Mint mint(int n) {
    Mint m;
    m.n = n % MOD;
    if (m.n < 0) m.n += MOD;
    return m;
}

Mint mint_neg(Mint m) {
    return m.n ? mint(MOD - m.n) : mint(0);
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

Mint mint_inv(Mint a) {
    // Fermat's little theorem for modular inverse
    return mint_pow(a, MOD - 2);
}

Mint mint_pow(Mint base, int exp) {
    Mint result = mint(1);
    while (exp) {
        if (exp & 1) result = mint_mul(result, base);
        base = mint_mul(base, base);
        exp >>= 1;
    }
    return result;
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

void poly_add(Poly *a, Poly b) {
    if (b.size > a->size) {
        a->c = (Mint *)realloc(a->c, b.size * sizeof(Mint));
        a->size = b.size;
    }
    for (int i = 0; i < b.size; i++) {
        a->c[i] = mint_add(a->c[i], b.c[i]);
    }
}

void poly_sub(Poly *a, Poly b) {
    if (b.size > a->size) {
        a->c = (Mint *)realloc(a->c, b.size * sizeof(Mint));
        a->size = b.size;
    }
    for (int i = 0; i < b.size; i++) {
        a->c[i] = mint_sub(a->c[i], b.c[i]);
    }
}

void poly_mul(Poly *a, Poly b) {
    if (a->size == 0 || b.size == 0) {
        a->size = 0;
        return;
    }
    int rdeg = a->size + b.size - 2;
    Poly result = poly_init(rdeg);
    for (int i = 0; i < a->size; i++) {
        for (int j = 0; j < b.size; j++) {
            result.c[i + j] = mint_add(result.c[i + j], mint_mul(a->c[i], b.c[j]));
        }
    }
    poly_free(a);
    *a = result;
}

Mint poly_eval(Poly p, Mint x) {
    Mint result = mint(0);
    for (int i = p.size - 1; i >= 0; i--) {
        result = mint_add(mint_mul(result, x), p.c[i]);
    }
    return result;
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

    Poly A = poly_init(2e5 + 1000);
    A.c[0] = mint(1);
    A.c[1] = mint((k - 2) % MOD);
    A.c[2] = mint(1);

    // Logarithm and Exponential operations would need to be implemented here

    Mint ans = mint_pow(mint(k), n - cnt);
    for (int i = 0; i <= n - cnt; i++) {
        ans = mint_sub(ans, C.c[i]); // C needs to be defined
    }

    ans = mint_mul(ans, mint_pow(mint(k), cnt));
    printf("%d\n", ans.n);
    
    free(hs);
    poly_free(&A);
    return 0;
}
