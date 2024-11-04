#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef long long ll;

typedef struct {
    unsigned int val;
} modint;

modint modint_create(ll val) {
    modint m;
    m.val = val >= 0 ? val % 1000000007 : (1000000007 - (-val) % 1000000007) % 1000000007;
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
    m.val = (unsigned int)((1LL * m1.val * (m2.val + 1000000007 - 1)) % 1000000007);
    return m;
}

modint modint_neg(modint m) {
    modint neg;
    neg.val = 1000000007 - m.val;
    return neg;
}

modint modint_pow(modint m, ll n) {
    modint ret;
    ret.val = 1;
    modint mul = m;
    while (n > 0) {
        if (n & 1) {
            ret = modint_mul(ret, mul);
        }
        mul = modint_mul(mul, mul);
        n >>= 1;
    }
    return ret;
}

typedef struct {
    int n;
    int log;
    int size;
    modint *laz;
} id2;

id2 id2_create(int n) {
    id2 seg;
    seg.n = n;
    seg.log = 1;
    while ((1 << seg.log) < n) {
        seg.log++;
    }
    seg.size = 1 << seg.log;
    seg.laz = (modint *)malloc((seg.size << 1) * sizeof(modint));
    for (int i = 0; i < (seg.size << 1); i++) {
        seg.laz[i].val = 0;
    }
    return seg;
}

void id2_reset(id2 *seg) {
    for (int i = 0; i < (seg->size << 1); i++) {
        seg->laz[i].val = 0;
    }
}

void id2_all_apply(id2 *seg, int k, modint a) {
    seg->laz[k] = modint_add(seg->laz[k], a);
}

modint id2_get(id2 *seg, int p) {
    p += seg->size;
    for (int i = seg->log; i >= 1; i--) {
        int k = p >> i;
        seg->laz[2 * k] = modint_add(seg->laz[2 * k], seg->laz[k]);
        seg->laz[2 * k + 1] = modint_add(seg->laz[2 * k + 1], seg->laz[k]);
        seg->laz[k].val = 0;
    }
    return seg->laz[p];
}

modint *id2_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[2 * k] = modint_add(seg->laz[2 * k], seg->laz[k]);
        seg->laz[2 * k + 1] = modint_add(seg->laz[2 * k + 1], seg->laz[k]);
        seg->laz[k].val = 0;
    }
    return seg->laz + seg->size;
}

void id2_apply(id2 *seg, int l, int r, modint a) {
    if (l == r) {
        return;
    }
    l += seg->size;
    r += seg->size;
    for (int i = seg->log; i >= 1; i--) {
        if (((l >> i) << i) != l) {
            int k = l >> i;
            seg->laz[2 * k] = modint_add(seg->laz[2 * k], seg->laz[k]);
            seg->laz[2 * k + 1] = modint_add(seg->laz[2 * k + 1], seg->laz[k]);
            seg->laz[k].val = 0;
        }
        if (((r >> i) << i) != r) {
            int k = (r - 1) >> i;
            seg->laz[2 * k] = modint_add(seg->laz[2 * k], seg->laz[k]);
            seg->laz[2 * k + 1] = modint_add(seg->laz[2 * k + 1], seg->laz[k]);
            seg->laz[k].val = 0;
        }
    }
    int l2 = l, r2 = r;
    while (l < r) {
        if (l & 1) {
            seg->laz[l] = modint_add(seg->laz[l], a);
            l++;
        }
        if (r & 1) {
            r--;
            seg->laz[r] = modint_add(seg->laz[r], a);
        }
        l >>= 1;
        r >>= 1;
    }
    l = l2;
    r = r2;
}

void id2_debug(id2 *seg) {
    modint *all = id2_get_all(seg);
    printf("dualsegtree getall:");
    for (int i = 0; i < seg->n; i++) {
        printf(" %u", all[i].val);
    }
    printf("\n");
}

typedef struct {
    modint val;
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

void solve() {
    ll N, mod;
    scanf("%lld %lld", &N, &mod);
    modint::set_mod(mod);

    id2 seg = id2_create(N + 1);
    id2_apply(&seg, 1, 2, modint_create(1));

    for (int n = 1; n <= N; n++) {
        modint dp = id2_get(&seg, n);
        id2_apply(&seg, n + 1, N + 1, dp);
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
            id2_apply(&seg, l, r, dp);
        }
    }
    modint ans = id2_get(&seg, N);
    printf("%u\n", ans.val);
}

int main() {
    int T = 1;

    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}
