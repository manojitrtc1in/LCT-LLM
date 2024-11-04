#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define MAX_N 100000
#define MOD 998244353

typedef struct {
    long long m[2][2];
} Mat;

typedef struct {
    long long p, q;
} Frac;

typedef struct {
    long long value;
} Mint;

Mint mint(long long x) {
    Mint res;
    res.value = x % MOD;
    return res;
}

Mint operator_add(Mint a, Mint b) {
    return mint((a.value + b.value) % MOD);
}

Mint operator_sub(Mint a, Mint b) {
    return mint((a.value - b.value + MOD) % MOD);
}

Mint operator_mul(Mint a, Mint b) {
    return mint((a.value * b.value) % MOD);
}

Mint operator_div(Mint a, Mint b) {
    long long inv = 1; // Compute modular inverse of b.value
    for (int i = 1; i < MOD - 2; i++) {
        inv = (inv * b.value) % MOD;
    }
    return operator_mul(a, mint(inv));
}

void mat_mul(Mat *a, Mat *b, Mat *c) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c->m[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c->m[i][j] = (c->m[i][j] + a->m[i][k] * b->m[k][j]) % MOD;
            }
        }
    }
}

void build(int l, int r, Mat *a, Mat *allowed_collisions) {
    if (l == r) {
        a[2 * l] = allowed_collisions[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, a, allowed_collisions);
    build(mid + 1, r, a, allowed_collisions);
    mat_mul(&a[2 * l], &a[2 * mid + 1], &a[get_id(l, r)]);
}

void modify(int l, int r, int k, Mat *a, Mat *allowed_collisions) {
    if (l == r) {
        a[2 * l] = allowed_collisions[k];
        return;
    }
    int mid = (l + r) / 2;
    if (k <= mid) {
        modify(l, mid, k, a, allowed_collisions);
    } else {
        modify(mid + 1, r, k, a, allowed_collisions);
    }
    mat_mul(&a[2 * l], &a[2 * mid + 1], &a[get_id(l, r)]);
}

int get_id(int l, int r) {
    return l + r | (l != r);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    
    long long x[MAX_N], v[MAX_N];
    Mint p[MAX_N];
    Mint inv_100 = operator_div(mint(1), mint(100));
    
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &x[i], &v[i]);
        p[i] = operator_mul(mint(v[i]), inv_100);
    }

    Mat allowed_collisions[MAX_N];
    for (int i = 0; i < n - 1; i++) {
        allowed_collisions[i].m[0][1] = p[i + 1].value;
    }

    Mat a[2 * (n - 1) - 1];
    // Define get_prob function here
    // Define other necessary functions and logic here

    // Process events and calculate the answer
    // ...

    return 0;
}
