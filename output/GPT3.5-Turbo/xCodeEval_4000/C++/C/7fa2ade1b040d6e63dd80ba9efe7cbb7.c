#include <stdio.h>
#include <stdbool.h>

typedef long long ll;

typedef struct {
    unsigned int val;
} modint;

modint modint_create(ll val) {
    modint m;
    m.val = (val >= 0 ? val % 1000000007 : (1000000007 - (-val) % 1000000007) % 1000000007);
    return m;
}

bool modint_less(modint m1, modint m2) {
    return m1.val < m2.val;
}

modint modint_add(modint m1, modint m2) {
    modint m;
    m.val = (m1.val + m2.val) % 1000000007;
    return m;
}

modint modint_sub(modint m1, modint m2) {
    modint m;
    m.val = (m1.val + 1000000007 - m2.val) % 1000000007;
    return m;
}

modint modint_mul(modint m1, modint m2) {
    modint m;
    m.val = (unsigned int)((1LL * m1.val * m2.val) % 1000000007);
    return m;
}

modint modint_div(modint m1, modint m2) {
    modint m;
    m.val = (unsigned int)((1LL * m1.val * m2.val) % 1000000007);
    return m;
}

modint modint_neg(modint m) {
    modint n;
    n.val = 1000000007 - m.val;
    return n;
}

modint modint_pow(modint m, ll n) {
    modint result;
    result.val = 1;
    modint mul = m;
    while (n > 0) {
        if (n & 1) {
            result = modint_mul(result, mul);
        }
        mul = modint_mul(mul, mul);
        n >>= 1;
    }
    return result;
}

typedef modint (*modint_op)(modint, modint);

typedef struct {
    modint value_type;
    modint_op op;
    modint_op inverse;
    modint_op power;
    modint unit;
    bool commute;
} Group_Add;

modint Group_Add_op(modint x, modint y) {
    return modint_add(x, y);
}

modint Group_Add_inverse(modint x) {
    return modint_neg(x);
}

modint Group_Add_power(modint x, ll n) {
    return modint_mul(modint_create(n), x);
}

modint Group_Add_unit() {
    return modint_create(0);
}

bool Group_Add_commute = true;

Group_Add Group_Add_create() {
    Group_Add g;
    g.op = Group_Add_op;
    g.inverse = Group_Add_inverse;
    g.power = Group_Add_power;
    g.unit = Group_Add_unit();
    g.commute = Group_Add_commute;
    return g;
}

typedef struct {
    int n;
    int log;
    int size;
    modint *laz;
} DualSegTree;

DualSegTree DualSegTree_create(int n) {
    DualSegTree seg;
    seg.n = n;
    seg.log = 1;
    while ((1 << seg.log) < n) {
        seg.log++;
    }
    seg.size = 1 << seg.log;
    seg.laz = (modint *)malloc((seg.size << 1) * sizeof(modint));
    for (int i = 0; i < (seg.size << 1); i++) {
        seg.laz[i] = Group_Add_unit();
    }
    return seg;
}

void DualSegTree_reset(DualSegTree *seg) {
    for (int i = 0; i < (seg->size << 1); i++) {
        seg->laz[i] = Group_Add_unit();
    }
}

void DualSegTree_all_apply(DualSegTree *seg, int k, modint a) {
    seg->laz[k] = Group_Add_op(seg->laz[k], a);
}

modint DualSegTree_get(DualSegTree *seg, int p) {
    p += seg->size;
    for (int i = seg->log; i >= 1; i--) {
        int k = p >> i;
        seg->laz[k << 1] = Group_Add_op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = Group_Add_op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = Group_Add_unit();
    }
    return seg->laz[p];
}

modint *DualSegTree_get_all(DualSegTree *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = Group_Add_op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = Group_Add_op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = Group_Add_unit();
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    for (int i = 0; i < seg->n; i++) {
        result[i] = seg->laz[seg->size + i];
    }
    return result;
}

void DualSegTree_apply(DualSegTree *seg, int l, int r, modint a) {
    if (l == r) {
        return;
    }

    l += seg->size;
    r += seg->size;

    if (!Group_Add_commute) {
        for (int i = seg->log; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                int k = l >> i;
                seg->laz[k << 1] = Group_Add_op(seg->laz[k << 1], seg->laz[k]);
                seg->laz[(k << 1) + 1] = Group_Add_op(seg->laz[(k << 1) + 1], seg->laz[k]);
                seg->laz[k] = Group_Add_unit();
            }
            if (((r >> i) << i) != r) {
                int k = (r - 1) >> i;
                seg->laz[k << 1] = Group_Add_op(seg->laz[k << 1], seg->laz[k]);
                seg->laz[(k << 1) + 1] = Group_Add_op(seg->laz[(k << 1) + 1], seg->laz[k]);
                seg->laz[k] = Group_Add_unit();
            }
        }
    }

    {
        int l2 = l, r2 = r;
        while (l < r) {
            if (l & 1) {
                seg->laz[l] = Group_Add_op(seg->laz[l], a);
                l++;
            }
            if (r & 1) {
                r--;
                seg->laz[r] = Group_Add_op(seg->laz[r], a);
            }
            l >>= 1;
            r >>= 1;
        }
        l = l2;
        r = r2;
    }
}

void DualSegTree_debug(DualSegTree *seg) {
    modint *all = DualSegTree_get_all(seg);
    printf("dualsegtree getall: ");
    for (int i = 0; i < seg->n; i++) {
        printf("%u ", all[i].val);
    }
    printf("\n");
    free(all);
}

void solve() {
    int N, mod;
    scanf("%d %d", &N, &mod);
    modint::set_mod(mod);

    DualSegTree seg = DualSegTree_create(N + 1);

    modint *dp = (modint *)malloc((N + 1) * sizeof(modint));
    dp[1] = modint_create(1);
    for (int n = 1; n <= N; n++) {
        dp[n] = modint_add(dp[n], DualSegTree_get(&seg, n));
        DualSegTree_apply(&seg, n + 1, N + 1, dp[n]);
        ll z = 2;
        while (1) {
            ll l = n * z, r = (n + 1) * z;
            if (l > N) {
                break;
            }
            z++;
            if (r > N + 1) {
                r = N + 1;
            }
            DualSegTree_apply(&seg, l, r, dp[n]);
        }
    }

    printf("%u\n", dp[N].val);

    free(dp);
}

int main() {
    int T = 1;

    for (int i = 0; i < T; i++) {
        solve();
    }

    return 0;
}
