#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef long long ll;

typedef struct {
    unsigned int val;
} mint;

void mint_set_mod(unsigned int mod) {
    static unsigned int _mod = 0;
    _mod = mod;
}

mint mint_init(ll val) {
    mint m;
    unsigned int mod = 1000000007; // Default mod
    m.val = (val >= 0) ? (val % mod) : (mod - (-val) % mod) % mod;
    return m;
}

mint mint_add(mint a, mint b) {
    unsigned int mod = 1000000007; // Default mod
    mint result;
    result.val = (a.val + b.val) % mod;
    return result;
}

mint mint_sub(mint a, mint b) {
    unsigned int mod = 1000000007; // Default mod
    mint result;
    result.val = (a.val + mod - b.val) % mod;
    return result;
}

mint mint_mul(mint a, mint b) {
    unsigned int mod = 1000000007; // Default mod
    mint result;
    result.val = (unsigned long long)a.val * b.val % mod;
    return result;
}

mint mint_inv(mint a) {
    unsigned int mod = 1000000007; // Default mod
    int x = a.val, y = mod, u = 1, v = 0, t;
    while (y > 0) {
        t = x / y;
        int temp = x; x = y; y = temp - t * y;
        temp = u; u = v; v = temp - t * v;
    }
    mint result;
    result.val = u;
    return result;
}

typedef struct {
    mint *laz;
    int n, log, size;
} DualSegTree;

void DualSegTree_init(DualSegTree *seg, int n) {
    seg->n = n;
    seg->log = 1;
    while ((1 << seg->log) < n) ++seg->log;
    seg->size = 1 << seg->log;
    seg->laz = (mint *)malloc((seg->size << 1) * sizeof(mint));
    for (int i = 0; i < (seg->size << 1); ++i) {
        seg->laz[i] = mint_init(0);
    }
}

void DualSegTree_apply(DualSegTree *seg, int l, int r, mint a) {
    assert(0 <= l && l <= r && r <= seg->n);
    if (l == r) return;

    l += seg->size;
    r += seg->size;

    while (l < r) {
        if (l & 1) seg->laz[l++] = mint_add(seg->laz[l], a);
        if (r & 1) seg->laz[--r] = mint_add(seg->laz[r], a);
        l >>= 1;
        r >>= 1;
    }
}

mint DualSegTree_get(DualSegTree *seg, int p) {
    assert(0 <= p && p < seg->n);
    p += seg->size;
    return seg->laz[p];
}

void solve() {
    ll N, mod;
    scanf("%lld %lld", &N, &mod);
    mint_set_mod(mod);

    DualSegTree seg;
    DualSegTree_init(&seg, N + 1);
    DualSegTree_apply(&seg, 1, 2, mint_init(1));

    for (ll n = 1; n <= N; ++n) {
        mint dp = DualSegTree_get(&seg, n);
        DualSegTree_apply(&seg, n + 1, N + 1, dp);
        ll z = 2;
        while (1) {
            ll l = n * z, r = (n + 1) * z;
            if (l > N) break;
            ++z;
            if (r > N + 1) r = N + 1;
            DualSegTree_apply(&seg, l, r, dp);
        }
    }
    printf("%u\n", seg.laz[N].val);
}

int main() {
    ll T = 1;
    for (ll _ = 0; _ < T; ++_) {
        solve();
    }
    return 0;
}
