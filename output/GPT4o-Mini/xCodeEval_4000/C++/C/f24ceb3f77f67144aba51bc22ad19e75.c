#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100000

typedef long long ll;
typedef struct {
    int n;
} modint;

int mod = 1000000007;

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

modint create_modint(ll n) {
    modint m;
    if (n >= 0 && n < mod) {
        m.n = n;
    } else {
        n %= mod;
        if (n < 0) {
            n += mod;
        }
        m.n = n;
    }
    return m;
}

modint modint_add(modint a, modint b) {
    return create_modint(a.n + b.n);
}

modint modint_sub(modint a, modint b) {
    return create_modint(a.n - b.n);
}

modint modint_mul(modint a, modint b) {
    return create_modint((ll)a.n * b.n % mod);
}

modint modint_inverse(modint a) {
    ll x, y;
    gcd(a.n, mod, &x, &y);
    return create_modint(x);
}

modint modint_div(modint a, modint b) {
    return modint_mul(a, modint_inverse(b));
}

typedef struct {
    modint* data;
    int size;
} FenwickTree;

FenwickTree create_fenwick_tree(int size) {
    FenwickTree ft;
    ft.size = size;
    ft.data = (modint*)calloc(size, sizeof(modint));
    return ft;
}

void ft_add(FenwickTree* ft, int at, modint v) {
    while (at < ft->size) {
        ft->data[at] = modint_add(ft->data[at], v);
        at |= (at + 1);
    }
}

modint ft_get(FenwickTree* ft, int to) {
    modint result = create_modint(0);
    while (to >= 0) {
        result = modint_add(result, ft->data[to]);
        to = (to & (to + 1)) - 1;
    }
    return result;
}

modint ft_range_get(FenwickTree* ft, int from, int to) {
    if (from >= to) {
        return create_modint(0);
    }
    return modint_sub(ft_get(ft, to - 1), ft_get(ft, from - 1));
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    mod = m;

    FenwickTree ft = create_fenwick_tree(n + 1);
    ft_add(&ft, n, create_modint(1));

    for (int i = n; i >= 1; i--) {
        modint res = ft_range_get(&ft, i + 1, n + 1);
        for (int z = 2; z * i <= n; z++) {
            res = modint_add(res, ft_range_get(&ft, z * i, z * i + z));
        }
        ft_add(&ft, i, res);
    }
    printf("%d\n", ft_get(&ft, 1).n);
    free(ft.data);
}

int main() {
    solve();
    return 0;
}
