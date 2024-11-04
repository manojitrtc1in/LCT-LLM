#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll gcd(ll a, ll b, ll* x, ll* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return d;
}

typedef struct {
    int n;
} modint;

modint modint_create(ll n) {
    modint m;
    m.n = n;
    return m;
}

modint modint_add(modint a, modint b, int mod) {
    return modint_create((a.n + b.n) % mod);
}

modint modint_sub(modint a, modint b, int mod) {
    return modint_create((a.n - b.n + mod) % mod);
}

modint modint_mul(modint a, modint b, int mod) {
    return modint_create((a.n * b.n) % mod);
}

modint modint_inverse(modint a, int mod) {
    ll x, y;
    ll g = gcd(a.n, mod, &x, &y);
    return modint_create(x);
}

typedef struct {
    int first;
    int second;
} pii;

pii pii_create(int first, int second) {
    pii p;
    p.first = first;
    p.second = second;
    return p;
}

typedef struct {
    int begin;
    int end;
} RevRange;

RevRange RevRange_create(int begin, int end) {
    RevRange r;
    r.begin = begin - 1;
    r.end = (begin < end) ? begin - 1 : end - 1;
    return r;
}

typedef struct {
    int* value;
    int size;
} FenwickTree;

FenwickTree FenwickTree_create(int size) {
    FenwickTree ft;
    ft.value = (int*)malloc(sizeof(int) * size);
    ft.size = size;
    for (int i = 0; i < size; i++) {
        ft.value[i] = 0;
    }
    return ft;
}

void FenwickTree_add(FenwickTree* ft, int at, int v) {
    while (at < ft->size) {
        ft->value[at] += v;
        at = at | (at + 1);
    }
}

int FenwickTree_get(FenwickTree* ft, int from, int to) {
    if (from >= to) {
        return 0;
    }
    int result = 0;
    while (to > 0) {
        result += ft->value[to - 1];
        to = (to & (to - 1));
    }
    while (from > 0) {
        result -= ft->value[from - 1];
        from = (from & (from - 1));
    }
    return result;
}

void FenwickTree_clear(FenwickTree* ft) {
    for (int i = 0; i < ft->size; i++) {
        ft->value[i] = 0;
    }
}

void BVerkhnyayaYacheika_solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    int mod = m;
    FenwickTree ft = FenwickTree_create(n + 1);
    FenwickTree_add(&ft, n, 1);
    for (int i = n - 1; i >= 1; i--) {
        modint res = modint_create(FenwickTree_get(&ft, i + 1, n + 1));
        for (int z = 2; z * i <= n; z++) {
            res = modint_add(res, modint_create(FenwickTree_get(&ft, z * i, z * i + z)), mod);
        }
        FenwickTree_add(&ft, i, res.n);
    }
    printf("%d\n", FenwickTree_get(&ft, 1, 2));
}

int main() {
    BVerkhnyayaYacheika_solve();
    return 0;
}
