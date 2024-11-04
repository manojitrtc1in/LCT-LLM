#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;

#define MAX_SIZE 100000

typedef struct {
    ll val;
} modint;

modint create_modint(ll value, unsigned int mod) {
    modint m;
    m.val = (value % mod + mod) % mod;
    return m;
}

modint modint_add(modint a, modint b, unsigned int mod) {
    return create_modint(a.val + b.val, mod);
}

modint modint_sub(modint a, modint b, unsigned int mod) {
    return create_modint(a.val - b.val, mod);
}

modint modint_mul(modint a, modint b, unsigned int mod) {
    return create_modint(a.val * b.val % mod, mod);
}

modint modint_inv(modint a, unsigned int mod) {
    ll m0 = mod, t, q;
    ll x0 = 0, x1 = 1;

    if (mod == 1) return create_modint(0, mod);
    while (a.val > 1) {
        q = a.val / mod;
        t = mod;
        mod = a.val % mod, a.val = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;

    return create_modint(x1, m0);
}

modint modint_pow(modint base, ll exp, unsigned int mod) {
    modint result = create_modint(1, mod);
    while (exp > 0) {
        if (exp % 2 == 1) result = modint_mul(result, base, mod);
        base = modint_mul(base, base, mod);
        exp /= 2;
    }
    return result;
}

typedef struct {
    modint data[MAX_SIZE];
    int size;
} SegmentTree;

void segtree_init(SegmentTree* seg, int n) {
    seg->size = n;
    for (int i = 0; i < n; i++) {
        seg->data[i] = create_modint(0, 1000000007);
    }
}

void segtree_apply(SegmentTree* seg, int l, int r, modint value) {
    for (int i = l; i < r; i++) {
        seg->data[i] = modint_add(seg->data[i], value, 1000000007);
    }
}

modint segtree_get(SegmentTree* seg, int index) {
    return seg->data[index];
}

void solve() {
    ll N, mod;
    scanf("%lld %lld", &N, &mod);

    SegmentTree seg;
    segtree_init(&seg, N + 1);
    segtree_apply(&seg, 1, 2, create_modint(1, mod));

    for (ll n = 1; n <= N; n++) {
        modint dp = segtree_get(&seg, n);
        segtree_apply(&seg, n + 1, N + 1, dp);
        ll z = 2;
        while (1) {
            ll l = n * z, r = (n + 1) * z;
            if (l > N) break;
            ++z;
            if (r > N + 1) r = N + 1;
            segtree_apply(&seg, l, r, dp);
        }
    }
    printf("%lld\n", segtree_get(&seg, N).val);
}

int main() {
    int T = 1;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
