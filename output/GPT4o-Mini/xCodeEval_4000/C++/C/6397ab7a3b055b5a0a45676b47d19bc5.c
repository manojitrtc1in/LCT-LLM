#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#define MAXN 100000
#define MOD 1000000007

typedef long long ll;
typedef struct {
    ll *data;
    int size;
} SegTree;

SegTree* create_seg_tree(int n) {
    SegTree *st = (SegTree *)malloc(sizeof(SegTree));
    st->size = 1;
    while (st->size < n) st->size *= 2;
    st->data = (ll *)calloc(2 * st->size, sizeof(ll));
    return st;
}

void update(SegTree *st, int index, ll value) {
    index += st->size;
    st->data[index] = value;
    while (index > 1) {
        index /= 2;
        st->data[index] = st->data[2 * index] + st->data[2 * index + 1];
    }
}

ll sum(SegTree *st, int left, int right) {
    left += st->size;
    right += st->size;
    ll res = 0;
    while (left < right) {
        if (left % 2 == 1) res += st->data[left++];
        if (right % 2 == 1) res += st->data[--right];
        left /= 2;
        right /= 2;
    }
    return res;
}

typedef struct {
    SegTree *st;
    int s;
    ll sum;
} bsargv_t;

bool evalfunc(int val, bsargv_t *v) {
    ll buf = sum(v->st, v->s, val + 1);
    return buf <= v->sum / 2;
}

ll lower_binary_search(ll l, ll r, bsargv_t *v) {
    if (r - l == 1) {
        return evalfunc(l, v) ? l : l - 1;
    }
    ll m = (l + r) / 2;
    if (evalfunc(m, v)) return lower_binary_search(m, r, v);
    else return lower_binary_search(l, m, v);
}

typedef struct {
    ll val;
} modll;

modll modll_init(ll init) {
    modll m;
    m.val = (init % MOD + MOD) % MOD;
    return m;
}

modll modll_add(modll a, modll b) {
    return modll_init(a.val + b.val);
}

modll modll_sub(modll a, modll b) {
    return modll_init(a.val - b.val);
}

modll modll_mul(modll a, modll b) {
    return modll_init(a.val * b.val);
}

modll modll_div(modll a, modll b) {
    return modll_mul(a, modll_init(pow(b.val, MOD - 2)));
}

modll modll_pow(modll base, ll exp) {
    modll result = modll_init(1);
    while (exp > 0) {
        if (exp % 2 == 1) result = modll_mul(result, base);
        base = modll_mul(base, base);
        exp /= 2;
    }
    return result;
}

modll facts[MAXN];
modll ifacts[MAXN];

void make_facts(int n) {
    facts[0] = modll_init(1);
    for (int i = 1; i <= n; i++) {
        facts[i] = modll_mul(facts[i - 1], modll_init(i));
    }
}

void make_ifacts(int n) {
    ifacts[n] = modll_pow(facts[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        ifacts[i] = modll_mul(ifacts[i + 1], modll_init(i + 1));
    }
}

modll combination(ll n, ll r) {
    if (n >= r && r >= 0) {
        return modll_mul(modll_mul(facts[n], ifacts[r]), ifacts[n - r]);
    }
    return modll_init(0);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    ll a[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    
    SegTree *st = create_seg_tree(n);
    SegTree *ast = create_seg_tree(n);
    SegTree *lst = create_seg_tree(n);
    SegTree *rst = create_seg_tree(n);
    
    for (int i = 0; i < n; i++) {
        ll w;
        scanf("%lld", &w);
        update(st, i, w);
        update(ast, i, modll_mul(modll_init(w), modll_init(a[i])).val);
        update(lst, i, modll_mul(modll_init(w), modll_init(n - 1 - i)).val);
        update(rst, i, modll_mul(modll_init(w), modll_init(i)).val);
    }
    
    modll ans[MAXN];
    int ans_count = 0;

    for (int unused = 0; unused < q; unused++) {
        int x;
        scanf("%d", &x);
        if (x < 0) {
            x++;
            ll y;
            scanf("%lld", &y);
            update(st, -x, y);
            update(ast, -x, modll_mul(modll_init(y), modll_init(a[-x])).val);
            update(lst, -x, modll_mul(modll_init(y), modll_init(n - 1 - (-x))).val);
            update(rst, -x, modll_mul(modll_init(y), modll_init(-x)).val);
        } else {
            int y;
            scanf("%d", &y);
            x--; y--;
            if (x == y) {
                ans[ans_count++] = modll_init(0);
            } else {
                int halfid;
                if (y - x == 1) {
                    halfid = x;
                } else {
                    bsargv_t v = {st, x, sum(st, x, y + 1)};
                    halfid = lower_binary_search(x + 1, y, &v);
                }
                ll cand0 = sum(st, x, halfid + 1);
                ll cand1 = sum(st, halfid + 1, y + 1);
                ll dst;
                int dstid;
                if (cand0 <= cand1) {
                    dst = a[halfid + 1];
                    dstid = halfid + 1;
                } else {
                    dst = a[halfid];
                    dstid = halfid;
                }
                modll buf = modll_init(0);
                buf = modll_add(buf, modll_sub(modll_mul(modll_init(dst), modll_init(sum(st, x, dstid))), ast->data[x]));
                buf = modll_add(buf, modll_sub(modll_init(ast->data[dstid]), modll_mul(modll_init(dst), modll_init(sum(st, dstid, y + 1)))));
                ans[ans_count++] = buf;
            }
        }
    }
    
    for (int i = 0; i < ans_count; i++) {
        printf("%lld\n", ans[i].val);
    }
    
    free(st->data);
    free(st);
    free(ast->data);
    free(ast);
    free(lst->data);
    free(lst);
    free(rst->data);
    free(rst);
    
    return 0;
}
