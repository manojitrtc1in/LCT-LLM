#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MOD7 1000000007
#define MOD9 1000000009
#define MODF 998244353

long long mod = MOD7;

typedef struct {
    int n;
} modint;

long long gcd(long long a, long long b, long long* x, long long* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return d;
}

modint create_modint(long long n) {
    modint result;
    if (n >= 0 && n < mod) {
        result.n = n;
    } else {
        n %= mod;
        if (n < 0) {
            n += mod;
        }
        result.n = n;
    }
    return result;
}

modint modint_add(modint a, modint b) {
    modint result = create_modint(a.n + b.n);
    return result;
}

modint modint_sub(modint a, modint b) {
    modint result = create_modint(a.n - b.n);
    return result;
}

modint modint_mul(modint a, modint b) {
    modint result = create_modint((long long)a.n * b.n % mod);
    return result;
}

modint modint_div(modint a, modint b) {
    if (b.n == 0) {
        fprintf(stderr, "Division by zero\n");
        exit(EXIT_FAILURE);
    }
    long long x, y;
    gcd(b.n, mod, &x, &y);
    return modint_mul(a, create_modint(x));
}

modint modint_inverse(modint a) {
    long long x, y;
    long long g = gcd(a.n, mod, &x, &y);
    if (g != 1) {
        fprintf(stderr, "not inversable\n");
        exit(EXIT_FAILURE);
    }
    return create_modint(x);
}

typedef struct {
    modint* data;
    int size;
} FenwickTree;

FenwickTree create_fenwick_tree(int size) {
    FenwickTree ft;
    ft.data = (modint*)calloc(size, sizeof(modint));
    ft.size = size;
    return ft;
}

void fenwick_add(FenwickTree* ft, int at, modint v) {
    while (at < ft->size) {
        ft->data[at] = modint_add(ft->data[at], v);
        at = at | (at + 1);
    }
}

modint fenwick_get(FenwickTree* ft, int to) {
    modint result = create_modint(0);
    while (to >= 0) {
        result = modint_add(result, ft->data[to]);
        to = (to & (to + 1)) - 1;
    }
    return result;
}

modint fenwick_range_get(FenwickTree* ft, int from, int to) {
    if (from >= to) {
        return create_modint(0);
    }
    return modint_sub(fenwick_get(ft, to - 1), fenwick_get(ft, from - 1));
}

void clear_fenwick_tree(FenwickTree* ft) {
    memset(ft->data, 0, ft->size * sizeof(modint));
}

void free_fenwick_tree(FenwickTree* ft) {
    free(ft->data);
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    mod = m;

    FenwickTree ft = create_fenwick_tree(n + 1);
    fenwick_add(&ft, n, create_modint(1));

    for (int i = n; i >= 1; i--) {
        modint res = fenwick_range_get(&ft, i + 1, n + 1);
        for (int z = 2; z * i <= n; z++) {
            res = modint_add(res, fenwick_range_get(&ft, z * i, z * i + z));
        }
        fenwick_add(&ft, i, res);
    }
    printf("%d\n", ft.data[1].n);
    free_fenwick_tree(&ft);
}

int main() {
    solve();
    return 0;
}
