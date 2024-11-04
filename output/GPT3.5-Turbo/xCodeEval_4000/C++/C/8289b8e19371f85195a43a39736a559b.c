#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    int val;
} amint;

amint new_amint(int val) {
    amint a;
    a.val = val;
    return a;
}

amint amint_add(amint a, amint b) {
    amint res;
    res.val = a.val + b.val;
    return res;
}

amint amint_inverse(amint a) {
    amint res;
    res.val = -a.val;
    return res;
}

amint amint_power(amint a, ll n) {
    amint res;
    res.val = n * a.val;
    return res;
}

amint amint_unit() {
    amint res;
    res.val = 0;
    return res;
}

typedef struct {
    int n;
    int log;
    int size;
    amint *laz;
} DualSegTree;

DualSegTree new_DualSegTree(int n) {
    DualSegTree seg;
    seg.n = n;
    seg.log = 1;
    while ((1 << seg.log) < n) {
        seg.log++;
    }
    seg.size = 1 << seg.log;
    seg.laz = (amint *)malloc((seg.size << 1) * sizeof(amint));
    for (int i = 0; i < (seg.size << 1); i++) {
        seg.laz[i] = amint_unit();
    }
    return seg;
}

void DualSegTree_reset(DualSegTree *seg) {
    for (int i = 0; i < (seg->size << 1); i++) {
        seg->laz[i] = amint_unit();
    }
}

void DualSegTree_all_apply(DualSegTree *seg, int k, amint a) {
    seg->laz[k] = amint_add(seg->laz[k], a);
}

amint DualSegTree_get(DualSegTree *seg, int p) {
    p += seg->size;
    for (int i = seg->log; i >= 1; i--) {
        int k = p >> i;
        if (((k << i) != p)) {
            DualSegTree_push(seg, k);
        }
    }
    return seg->laz[p];
}

amint *DualSegTree_get_all(DualSegTree *seg) {
    for (int i = 0; i < seg->size; i++) {
        DualSegTree_push(seg, i);
    }
    amint *res = (amint *)malloc(seg->n * sizeof(amint));
    for (int i = 0; i < seg->n; i++) {
        res[i] = seg->laz[seg->size + i];
    }
    return res;
}

void DualSegTree_apply(DualSegTree *seg, int l, int r, amint a) {
    if (l == r) {
        return;
    }
    l += seg->size;
    r += seg->size;
    if (0) {
        for (int i = seg->log; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                DualSegTree_push(seg, l >> i);
            }
            if (((r >> i) << i) != r) {
                DualSegTree_push(seg, (r - 1) >> i);
            }
        }
    }
    int l2 = l, r2 = r;
    while (l < r) {
        if (l & 1) {
            DualSegTree_all_apply(seg, l++, a);
        }
        if (r & 1) {
            DualSegTree_all_apply(seg, --r, a);
        }
        l >>= 1;
        r >>= 1;
    }
    l = l2;
    r = r2;
}

void DualSegTree_push(DualSegTree *seg, int k) {
    DualSegTree_all_apply(seg, 2 * k, seg->laz[k]);
    DualSegTree_all_apply(seg, 2 * k + 1, seg->laz[k]);
    seg->laz[k] = amint_unit();
}

void solve() {
    int N, mod;
    scanf("%d%d", &N, &mod);

    DualSegTree seg = new_DualSegTree(N + 1);
    DualSegTree_apply(&seg, 1, 2, new_amint(1));

    for (int n = 1; n <= N; n++) {
        amint dp = DualSegTree_get(&seg, n);
        DualSegTree_apply(&seg, n + 1, N + 1, dp);
        ll z = 2;
        while (1) {
            ll l = n * z, r = (n + 1) * z;
            if (l > N) {
                break;
            }
            ++z;
            if (r > N + 1) {
                r = N + 1;
            }
            DualSegTree_apply(&seg, l, r, dp);
        }
    }
    amint res = DualSegTree_get(&seg, N);
    printf("%d\n", res.val);
}

int main() {
    int T = 1;

    for (int i = 0; i < T; i++) {
        solve();
    }

    return 0;
}
