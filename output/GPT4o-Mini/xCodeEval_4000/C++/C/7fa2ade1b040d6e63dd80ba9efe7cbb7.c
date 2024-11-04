#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef long long ll;
typedef struct {
    ll val;
} mint;

static unsigned int mod;

void mint_set_mod(int m) {
    mod = m;
}

mint mint_init(ll val) {
    mint m;
    m.val = (val >= 0) ? (val % mod) : (mod - (-val) % mod) % mod;
    return m;
}

mint mint_add(mint a, mint b) {
    mint res;
    res.val = (a.val + b.val) % mod;
    return res;
}

mint mint_sub(mint a, mint b) {
    mint res;
    res.val = (a.val + mod - b.val) % mod;
    return res;
}

mint mint_mul(mint a, mint b) {
    mint res;
    res.val = (a.val * b.val) % mod;
    return res;
}

mint mint_pow(mint a, ll n) {
    mint res = mint_init(1);
    while (n > 0) {
        if (n & 1) res = mint_mul(res, a);
        a = mint_mul(a, a);
        n >>= 1;
    }
    return res;
}

mint mint_inv(mint a) {
    int x = a.val, y = mod, u = 1, v = 0, t;
    while (y > 0) {
        t = x / y;
        int temp = x; x = y; y = temp - t * y;
        temp = u; u = v; v = temp - t * v;
    }
    return mint_init(u);
}

typedef struct {
    mint *laz;
    int n, log, size;
} DualSegTree;

DualSegTree* create_dual_seg_tree(int n) {
    DualSegTree *seg = (DualSegTree *)malloc(sizeof(DualSegTree));
    seg->n = n;
    seg->log = 1;
    while ((1 << seg->log) < n) ++seg->log;
    seg->size = 1 << seg->log;
    seg->laz = (mint *)malloc((seg->size << 1) * sizeof(mint));
    for (int i = 0; i < (seg->size << 1); i++) {
        seg->laz[i] = mint_init(0);
    }
    return seg;
}

void dual_seg_tree_apply(DualSegTree *seg, int l, int r, mint a) {
    l += seg->size;
    r += seg->size;
    while (l < r) {
        if (l & 1) seg->laz[l++] = mint_add(seg->laz[l], a);
        if (r & 1) seg->laz[--r] = mint_add(seg->laz[r], a);
        l >>= 1;
        r >>= 1;
    }
}

mint dual_seg_tree_get(DualSegTree *seg, int p) {
    p += seg->size;
    for (int i = seg->log; i >= 1; i--) {
        seg->laz[p >> i] = mint_add(seg->laz[p >> i], seg->laz[p]);
    }
    return seg->laz[p];
}

void solve() {
    ll N, mod;
    scanf("%lld %lld", &N, &mod);
    mint_set_mod(mod);

    DualSegTree *seg = create_dual_seg_tree(N + 1);
    mint *dp = (mint *)malloc((N + 1) * sizeof(mint));
    dp[1] = mint_init(1);

    for (ll n = 1; n <= N; n++) {
        dp[n] = mint_add(dp[n], dual_seg_tree_get(seg, n));
        dual_seg_tree_apply(seg, n + 1, N + 1, dp[n]);
        ll z = 2;
        while (1) {
            ll l = n * z, r = (n + 1) * z;
            if (l > N) break;
            ++z;
            if (r > N + 1) r = N + 1;
            dual_seg_tree_apply(seg, l, r, dp[n]);
        }
    }

    printf("%lld\n", dp[N].val);
    free(seg->laz);
    free(seg);
    free(dp);
}

int main() {
    int T = 1;
    for (int _ = 0; _ < T; _++) {
        solve();
    }
    return 0;
}
