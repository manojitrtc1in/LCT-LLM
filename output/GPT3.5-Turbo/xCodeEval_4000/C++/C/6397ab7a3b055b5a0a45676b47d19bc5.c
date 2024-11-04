#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

typedef struct {
    int n;
    int N;
    int base;
    ll* nodes;
} SegTree;

SegTree* createSegTree(int n, ll init) {
    SegTree* st = (SegTree*)malloc(sizeof(SegTree));
    st->n = n;
    st->N = 1 << (int)(ceil(log2(n)));
    st->base = st->N - 1;
    st->nodes = (ll*)malloc((st->base + st->N) * sizeof(ll));
    for (int i = 0; i < st->base + st->N; i++) {
        st->nodes[i] = init;
    }
    return st;
}

int left_of(int index, int base) {
    if (index >= base) return -1;
    else return index * 2 + 1;
}

int right_of(int index, int base) {
    if (index >= base) return -1;
    else return index * 2 + 2;
}

int parent_of(int index) {
    if (index == 0) return -1;
    else return (index - 1) >> 1;
}

void update_rec(int s, int t, int l, int r, int index, ll v, ll* nodes) {
    if (s == l && t == r) {
        nodes[index] = v;
    }
    else {
        int mid = (l + r) / 2;
        int index_l = left_of(index, base);
        int index_r = right_of(index, base);
        if (s < mid && mid < t) {
            update_rec(s, mid, l, mid, index_l, v, nodes);
            update_rec(mid, t, mid, r, index_r, v, nodes);
        }
        else if (s < mid) {
            update_rec(s, t, l, mid, index_l, v, nodes);
        }
        else if (mid < t) {
            update_rec(s, t, mid, r, index_r, v, nodes);
        }
        nodes[index] = nodes[index_l] + nodes[index_r];
    }
}

void update(SegTree* st, int k, ll v) {
    update_rec(k, k + 1, 0, st->N, 0, v, st->nodes);
}

ll add_rec(int s, int t, int l, int r, int index, ll* nodes) {
    if (s == l && t == r) {
        return nodes[index];
    }
    else {
        int mid = (l + r) / 2;
        int index_l = left_of(index, base);
        int index_r = right_of(index, base);
        ll v0 = 0, v1 = 0;
        if (s < mid && mid < t) {
            v0 = add_rec(s, mid, l, mid, index_l, nodes);
            v1 = add_rec(mid, t, mid, r, index_r, nodes);
        }
        else if (s < mid) {
            v0 = add_rec(s, t, l, mid, index_l, nodes);
        }
        else if (mid < t) {
            v1 = add_rec(s, t, mid, r, index_r, nodes);
        }
        return v0 + v1;
    }
}

ll sum(SegTree* st, int s, int t) {
    return add_rec(s, t, 0, st->N, 0, st->nodes);
}

void freeSegTree(SegTree* st) {
    free(st->nodes);
    free(st);
}

ll lower_binary_search(ll l, ll r, ll* v, int n, ll(*evalfunc)(ll, ll*, int)) {
    if (r - l == 1) {
        if (evalfunc(l, v, n)) return l;
        else return l - 1;
    }
    ll m = (l + r) / 2;
    if (evalfunc(m, v, n)) return lower_binary_search(m, r, v, n, evalfunc);
    else return lower_binary_search(l, m, v, n, evalfunc);
}

typedef struct {
    SegTree* st;
    int s;
    ll sum;
} bsargv_t;

int evalfunc(ll val, bsargv_t* v) {
    ll buf = sum(v->st, v->s, val + 1);
    if (buf <= v->sum / 2) return 1;
    else return 0;
}

const ll MOD = 1000000007;

typedef struct {
    ll val;
} modll;

modll createModll(ll init) {
    modll x;
    x.val = init % MOD;
    if (x.val < 0) x.val += MOD;
    return x;
}

modll modll_add(modll x, modll y) {
    return createModll(x.val + y.val);
}

modll modll_sub(modll x, modll y) {
    return createModll(x.val - y.val);
}

modll modll_mul(modll x, modll y) {
    return createModll(x.val * y.val);
}

modll modll_div(modll x, modll y) {
    ll inv = 1;
    if (y.val != 0) {
        inv = y.val;
        if (inv < 0) inv += MOD;
        while (inv % MOD != 1) inv += MOD;
        inv /= MOD;
    }
    return createModll(x.val * inv);
}

modll modll_pow(modll n, ll p) {
    modll ret;
    if (p == 0) ret = createModll(1);
    else if (p == 1) ret = n;
    else {
        ret = modll_pow(n, p / 2);
        ret = modll_mul(ret, ret);
        if (p % 2 == 1) ret = modll_mul(ret, n);
    }
    return ret;
}

ll* facts = NULL;
int facts_size = 0;

void make_facts(int n) {
    if (facts == NULL) {
        facts = (ll*)malloc((n + 1) * sizeof(ll));
        facts[0] = 1;
        facts_size = n + 1;
    }
    else if (n >= facts_size) {
        facts = (ll*)realloc(facts, (n + 1) * sizeof(ll));
        for (int i = facts_size; i <= n; i++) {
            facts[i] = facts[i - 1] * i % MOD;
        }
        facts_size = n + 1;
    }
}

ll* ifacts = NULL;
int ifacts_size = 0;

void make_ifacts(int n) {
    if (ifacts == NULL) {
        ifacts = (ll*)malloc((n + 1) * sizeof(ll));
        ifacts[0] = 1;
        ifacts[1] = 1;
        ifacts_size = n + 1;
    }
    else if (n >= ifacts_size) {
        ifacts = (ll*)realloc(ifacts, (n + 1) * sizeof(ll));
        for (int i = ifacts_size; i <= n; i++) {
            ifacts[i] = ifacts[MOD % i] * (MOD - MOD / i) % MOD;
        }
        ifacts_size = n + 1;
    }
}

ll combination(ll n, ll r) {
    if (n >= r && r >= 0) {
        make_facts(n);
        make_ifacts(n);
        return facts[n] * ifacts[r] % MOD * ifacts[n - r] % MOD;
    }
    else return 0;
}

ll disc_log(modll a, modll b) {
    ll ret = -1;
    ll m = (ll)ceil(sqrt(MOD));
    ll* mp = (ll*)malloc(m * sizeof(ll));
    for (int i = 0; i < m; i++) {
        mp[i] = -1;
    }
    modll x = createModll(1);
    for (int i = 0; i < m; i++) {
        mp[x.val] = i;
        x = modll_mul(x, a);
    }
    x = modll_div(createModll(1), modll_pow(a, m));
    modll k = b;
    for (int i = 0; i < m; i++) {
        if (mp[k.val] == -1) k = modll_mul(k, x);
        else {
            ret = i * m + mp[k.val];
            break;
        }
    }
    free(mp);
    return ret;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    ll* a = (ll*)malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    SegTree* st = createSegTree(n, 0);
    SegTree* ast = createSegTree(n, 0);
    SegTree* lst = createSegTree(n, 0);
    SegTree* rst = createSegTree(n, 0);
    for (int i = 0; i < n; i++) {
        ll w;
        scanf("%lld", &w);
        update(st, i, w);
        update(ast, i, modll_mul(createModll(w), createModll(a[i])).val);
        update(lst, i, modll_mul(createModll(w), createModll(n - 1 - i)).val);
        update(rst, i, modll_mul(createModll(w), createModll(i)).val);
    }
    for (int unused = 0; unused < q; unused++) {
        int x;
        scanf("%d", &x);
        if (x < 0) {
            x++;
            ll y;
            scanf("%lld", &y);
            update(st, -x, y);
            update(ast, -x, modll_mul(createModll(y), createModll(a[-x])).val);
            update(lst, -x, modll_mul(createModll(y), createModll(n - 1 - (-x))).val);
            update(rst, -x, modll_mul(createModll(y), createModll(-x)).val);
        }
        else {
            int y;
            scanf("%d", &y);
            x--; y--;
            if (x == y) {
                printf("0\n");
            }
            else {
                int halfid;
                if (y - x == 1) {
                    halfid = x;
                }
                else {
                    bsargv_t v;
                    v.st = st;
                    v.s = x;
                    v.sum = sum(st, x, y + 1);
                    halfid = lower_binary_search(x + 1, y, (ll*)&v, sizeof(bsargv_t) / sizeof(ll), (ll(*)(ll, ll*, int))evalfunc);
                }
                ll cand0 = sum(st, x, halfid + 1);
                ll cand1 = sum(st, halfid + 1, y + 1);
                ll dst;
                int dstid;
                if (cand0 <= cand1) {
                    dst = a[halfid + 1];
                    dstid = halfid + 1;
                }
                else {
                    dst = a[halfid];
                    dstid = halfid;
                }
                modll buf = createModll(0);
                buf = modll_sub(buf, modll_mul(createModll(dst), createModll(sum(st, x, dstid)).val));
                buf = modll_sub(buf, modll_sub(sum(ast, x, dstid), modll_mul(createModll(sum(st, x, dstid)).val, createModll(n - 1 - dstid)).val));
                buf = modll_add(buf, modll_sub(sum(ast, dstid, y + 1), modll_mul(createModll(dst), createModll(sum(st, dstid, y + 1)).val)));
                buf = modll_sub(buf, modll_sub(sum(rst, dstid, y + 1), modll_mul(createModll(sum(st, dstid, y + 1)).val, createModll(dstid)).val));
                printf("%lld\n", buf.val);
            }
        }
    }
    free(a);
    freeSegTree(st);
    freeSegTree(ast);
    freeSegTree(lst);
    freeSegTree(rst);
    return 0;
}
