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

typedef modint (*op_func)(modint, modint);

typedef struct {
    int n;
    int log;
    int size;
    modint *laz;
    op_func op;
} id2;

id2 id2_create(int n, op_func op) {
    id2 seg;
    seg.n = n;
    seg.op = op;
    seg.log = 1;
    while ((1 << seg.log) < n) {
        seg.log++;
    }
    seg.size = 1 << seg.log;
    seg.laz = (modint *)malloc((seg.size << 1) * sizeof(modint));
    for (int i = 0; i < (seg.size << 1); i++) {
        seg.laz[i] = modint_create(0);
    }
    return seg;
}

void id2_reset(id2 *seg) {
    for (int i = 0; i < (seg->size << 1); i++) {
        seg->laz[i] = modint_create(0);
    }
}

void id2_all_apply(id2 *seg, int k, modint a) {
    seg->laz[k] = seg->op(seg->laz[k], a);
}

modint id2_get(id2 *seg, int p) {
    p += seg->size;
    for (int i = seg->log; i >= 1; i--) {
        int k = p >> i;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    return seg->laz[p];
}

modint *id2_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

void id2_apply(id2 *seg, int l, int r, modint a) {
    if (l == r) {
        return;
    }
    l += seg->size;
    r += seg->size;
    if (!seg->op) {
        for (int i = seg->log; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                int k = l >> i;
                seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
                seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
                seg->laz[k] = modint_create(0);
            }
            if (((r >> i) << i) != r) {
                int k = (r - 1) >> i;
                seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
                seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
                seg->laz[k] = modint_create(0);
            }
        }
    }
    int l2 = l;
    int r2 = r;
    while (l < r) {
        if (l & 1) {
            seg->laz[l] = seg->op(seg->laz[l], a);
            l++;
        }
        if (r & 1) {
            r--;
            seg->laz[r] = seg->op(seg->laz[r], a);
        }
        l >>= 1;
        r >>= 1;
    }
    l = l2;
    r = r2;
}

typedef modint (*op_func)(modint, modint);

modint op_add(modint m1, modint m2) {
    return modint_add(m1, m2);
}

typedef struct {
    op_func op;
    bool commute;
} Group_Add;

Group_Add group_add_create() {
    Group_Add group;
    group.op = op_add;
    group.commute = true;
    return group;
}

modint group_add_op(op_func op, modint m1, modint m2) {
    return op(m1, m2);
}

modint group_add_inverse(op_func op, modint m) {
    return modint_neg(m);
}

modint group_add_power(op_func op, modint m, ll n) {
    return modint_mul(modint_create(n), m);
}

modint group_add_unit(op_func op) {
    return modint_create(0);
}

typedef modint (*op_func)(modint, modint);

typedef struct {
    int n;
    int log;
    int size;
    modint *laz;
    op_func op;
} id2;

id2 id2_create(int n, op_func op) {
    id2 seg;
    seg.n = n;
    seg.op = op;
    seg.log = 1;
    while ((1 << seg.log) < n) {
        seg.log++;
    }
    seg.size = 1 << seg.log;
    seg.laz = (modint *)malloc((seg.size << 1) * sizeof(modint));
    for (int i = 0; i < (seg.size << 1); i++) {
        seg.laz[i] = modint_create(0);
    }
    return seg;
}

void id2_reset(id2 *seg) {
    for (int i = 0; i < (seg->size << 1); i++) {
        seg->laz[i] = modint_create(0);
    }
}

void id2_all_apply(id2 *seg, int k, modint a) {
    seg->laz[k] = seg->op(seg->laz[k], a);
}

modint id2_get(id2 *seg, int p) {
    p += seg->size;
    for (int i = seg->log; i >= 1; i--) {
        int k = p >> i;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    return seg->laz[p];
}

modint *id2_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

void id2_apply(id2 *seg, int l, int r, modint a) {
    if (l == r) {
        return;
    }
    l += seg->size;
    r += seg->size;
    if (!seg->op) {
        for (int i = seg->log; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                int k = l >> i;
                seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
                seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
                seg->laz[k] = modint_create(0);
            }
            if (((r >> i) << i) != r) {
                int k = (r - 1) >> i;
                seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
                seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
                seg->laz[k] = modint_create(0);
            }
        }
    }
    int l2 = l;
    int r2 = r;
    while (l < r) {
        if (l & 1) {
            seg->laz[l] = seg->op(seg->laz[l], a);
            l++;
        }
        if (r & 1) {
            r--;
            seg->laz[r] = seg->op(seg->laz[r], a);
        }
        l >>= 1;
        r >>= 1;
    }
    l = l2;
    r = r2;
}

typedef modint (*op_func)(modint, modint);

modint op_add(modint m1, modint m2) {
    return modint_add(m1, m2);
}

typedef struct {
    op_func op;
    bool commute;
} Group_Add;

Group_Add group_add_create() {
    Group_Add group;
    group.op = op_add;
    group.commute = true;
    return group;
}

modint group_add_op(op_func op, modint m1, modint m2) {
    return op(m1, m2);
}

modint group_add_inverse(op_func op, modint m) {
    return modint_neg(m);
}

modint group_add_power(op_func op, modint m, ll n) {
    return modint_mul(modint_create(n), m);
}

modint group_add_unit(op_func op) {
    return modint_create(0);
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

typedef modint (*op_func)(modint, modint);

modint op_add(modint m1, modint m2) {
    return modint_add(m1, m2);
}

typedef struct {
    int n;
    int log;
    int size;
    modint *laz;
    op_func op;
} id2;

id2 id2_create(int n, op_func op) {
    id2 seg;
    seg.n = n;
    seg.op = op;
    seg.log = 1;
    while ((1 << seg.log) < n) {
        seg.log++;
    }
    seg.size = 1 << seg.log;
    seg.laz = (modint *)malloc((seg.size << 1) * sizeof(modint));
    for (int i = 0; i < (seg.size << 1); i++) {
        seg.laz[i] = modint_create(0);
    }
    return seg;
}

void id2_reset(id2 *seg) {
    for (int i = 0; i < (seg->size << 1); i++) {
        seg->laz[i] = modint_create(0);
    }
}

void id2_all_apply(id2 *seg, int k, modint a) {
    seg->laz[k] = seg->op(seg->laz[k], a);
}

modint id2_get(id2 *seg, int p) {
    p += seg->size;
    for (int i = seg->log; i >= 1; i--) {
        int k = p >> i;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    return seg->laz[p];
}

modint *id2_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

void id2_apply(id2 *seg, int l, int r, modint a) {
    if (l == r) {
        return;
    }
    l += seg->size;
    r += seg->size;
    if (!seg->op) {
        for (int i = seg->log; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                int k = l >> i;
                seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
                seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
                seg->laz[k] = modint_create(0);
            }
            if (((r >> i) << i) != r) {
                int k = (r - 1) >> i;
                seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
                seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
                seg->laz[k] = modint_create(0);
            }
        }
    }
    int l2 = l;
    int r2 = r;
    while (l < r) {
        if (l & 1) {
            seg->laz[l] = seg->op(seg->laz[l], a);
            l++;
        }
        if (r & 1) {
            r--;
            seg->laz[r] = seg->op(seg->laz[r], a);
        }
        l >>= 1;
        r >>= 1;
    }
    l = l2;
    r = r2;
}

typedef modint (*op_func)(modint, modint);

modint op_add(modint m1, modint m2) {
    return modint_add(m1, m2);
}

typedef struct {
    int n;
    int log;
    int size;
    modint *laz;
    op_func op;
} id2;

id2 id2_create(int n, op_func op) {
    id2 seg;
    seg.n = n;
    seg.op = op;
    seg.log = 1;
    while ((1 << seg.log) < n) {
        seg.log++;
    }
    seg.size = 1 << seg.log;
    seg.laz = (modint *)malloc((seg.size << 1) * sizeof(modint));
    for (int i = 0; i < (seg.size << 1); i++) {
        seg.laz[i] = modint_create(0);
    }
    return seg;
}

void id2_reset(id2 *seg) {
    for (int i = 0; i < (seg->size << 1); i++) {
        seg->laz[i] = modint_create(0);
    }
}

void id2_all_apply(id2 *seg, int k, modint a) {
    seg->laz[k] = seg->op(seg->laz[k], a);
}

modint id2_get(id2 *seg, int p) {
    p += seg->size;
    for (int i = seg->log; i >= 1; i--) {
        int k = p >> i;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    return seg->laz[p];
}

modint *id2_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

void id2_apply(id2 *seg, int l, int r, modint a) {
    if (l == r) {
        return;
    }
    l += seg->size;
    r += seg->size;
    if (!seg->op) {
        for (int i = seg->log; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                int k = l >> i;
                seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
                seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
                seg->laz[k] = modint_create(0);
            }
            if (((r >> i) << i) != r) {
                int k = (r - 1) >> i;
                seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
                seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
                seg->laz[k] = modint_create(0);
            }
        }
    }
    int l2 = l;
    int r2 = r;
    while (l < r) {
        if (l & 1) {
            seg->laz[l] = seg->op(seg->laz[l], a);
            l++;
        }
        if (r & 1) {
            r--;
            seg->laz[r] = seg->op(seg->laz[r], a);
        }
        l >>= 1;
        r >>= 1;
    }
    l = l2;
    r = r2;
}

typedef modint (*op_func)(modint, modint);

modint op_add(modint m1, modint m2) {
    return modint_add(m1, m2);
}

typedef struct {
    int n;
    int log;
    int size;
    modint *laz;
    op_func op;
} id2;

id2 id2_create(int n, op_func op) {
    id2 seg;
    seg.n = n;
    seg.op = op;
    seg.log = 1;
    while ((1 << seg.log) < n) {
        seg.log++;
    }
    seg.size = 1 << seg.log;
    seg.laz = (modint *)malloc((seg.size << 1) * sizeof(modint));
    for (int i = 0; i < (seg.size << 1); i++) {
        seg.laz[i] = modint_create(0);
    }
    return seg;
}

void id2_reset(id2 *seg) {
    for (int i = 0; i < (seg->size << 1); i++) {
        seg->laz[i] = modint_create(0);
    }
}

void id2_all_apply(id2 *seg, int k, modint a) {
    seg->laz[k] = seg->op(seg->laz[k], a);
}

modint id2_get(id2 *seg, int p) {
    p += seg->size;
    for (int i = seg->log; i >= 1; i--) {
        int k = p >> i;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    return seg->laz[p];
}

modint *id2_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

void id2_apply(id2 *seg, int l, int r, modint a) {
    if (l == r) {
        return;
    }
    l += seg->size;
    r += seg->size;
    if (!seg->op) {
        for (int i = seg->log; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                int k = l >> i;
                seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
                seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
                seg->laz[k] = modint_create(0);
            }
            if (((r >> i) << i) != r) {
                int k = (r - 1) >> i;
                seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
                seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
                seg->laz[k] = modint_create(0);
            }
        }
    }
    int l2 = l;
    int r2 = r;
    while (l < r) {
        if (l & 1) {
            seg->laz[l] = seg->op(seg->laz[l], a);
            l++;
        }
        if (r & 1) {
            r--;
            seg->laz[r] = seg->op(seg->laz[r], a);
        }
        l >>= 1;
        r >>= 1;
    }
    l = l2;
    r = r2;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
    return result;
}

modint *group_add_get_all(id2 *seg) {
    for (int i = 0; i < seg->size; i++) {
        int k = i + seg->size;
        seg->laz[k << 1] = seg->op(seg->laz[k << 1], seg->laz[k]);
        seg->laz[(k << 1) + 1] = seg->op(seg->laz[(k << 1) + 1], seg->laz[k]);
        seg->laz[k] = modint_create(0);
    }
    modint *result = (modint *)malloc(seg->n * sizeof(modint));
    memcpy(result, seg->laz + seg->size, seg->n * sizeof(modint));
