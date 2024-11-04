#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long int ll;

typedef struct {
    ll* nodes;
    int n;
    int N;
    int base;
} SegTree;

SegTree* createSegTree(int n, ll init) {
    SegTree* st = (SegTree*)malloc(sizeof(SegTree));
    st->n = n;
    st->N = pow(2, ceil(log2(n)));
    st->base = st->N - 1;
    st->nodes = (ll*)malloc((st->base + st->N) * sizeof(ll));
    for (int i = 0; i < st->base + st->N; i++) {
        st->nodes[i] = init;
    }
    return st;
}

int left_of(int index, int base) {
    if (index >= base) {
        return -1;
    }
    else {
        return index * 2 + 1;
    }
}

int right_of(int index, int base) {
    if (index >= base) {
        return -1;
    }
    else {
        return index * 2 + 2;
    }
}

int parent_of(int index) {
    if (index == 0) {
        return -1;
    }
    else {
        return (index - 1) >> 1;
    }
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

void destroySegTree(SegTree* st) {
    free(st->nodes);
    free(st);
}

ll id4(ll l, ll r, SegTree* st, int s, ll sum);
typedef struct {
    SegTree* st;
    int s;
    ll sum;
} bsargv_t;

int evalfunc(ll val, bsargv_t* v) {
    ll buf = sum(v->st, v->s, val + 1);
    if (buf <= v->sum / 2) {
        return 1;
    }
    else {
        return 0;
    }
}

ll id4(ll l, ll r, SegTree* st, int s, ll sum) {
    if (r - l == 1) {
        if (evalfunc(l, &(bsargv_t){st, s, sum})) {
            return l;
        }
        else {
            return l - 1;
        }
    }
    ll m = (l + r) / 2;
    if (evalfunc(m, &(bsargv_t){st, s, sum})) {
        return id4(m, r, st, s, sum);
    }
    else {
        return id4(l, m, st, s, sum);
    }
}

typedef struct {
    ll val;
} modll;

modll createModll(ll init) {
    modll x;
    x.val = init;
    return x;
}

modll modify(modll x) {
    ll ret = x.val % 1000000007;
    if (ret < 0) {
        ret += 1000000007;
    }
    x.val = ret;
    return x;
}

modll inv(modll x) {
    if (x.val == 0) {
        return createModll(1 / x.val);
    }
    else if (x.val == 1) {
        return createModll(1);
    }
    else {
        return modify(inv(createModll(1000000007 % x.val)) * modify(createModll(1000000007 / x.val)));
    }
}

modll add(modll x, modll y) {
    return modify(createModll(x.val + y.val));
}

modll subtract(modll x, modll y) {
    return modify(createModll(x.val - y.val));
}

modll multiply(modll x, modll y) {
    return modify(createModll(x.val * y.val));
}

modll divide(modll x, modll y) {
    return modify(multiply(x, inv(y)));
}

modll pow(modll n, ll p) {
    modll ret;
    if (p == 0) {
        ret = createModll(1);
    }
    else if (p == 1) {
        ret = n;
    }
    else {
        ret = pow(n, p / 2);
        ret = multiply(ret, ret);
        if (p % 2 == 1) {
            ret = multiply(ret, n);
        }
    }
    return ret;
}

typedef struct {
    modll* facts;
    int size;
} facts_t;

facts_t createFacts(int n) {
    facts_t facts;
    facts.size = n;
    facts.facts = (modll*)malloc(n * sizeof(modll));
    facts.facts[0] = createModll(1);
    for (int i = 1; i < n; i++) {
        facts.facts[i] = multiply(facts.facts[i - 1], createModll(i));
    }
    return facts;
}

modll combination(facts_t* facts, ll n, ll r) {
    if (n >= r && r >= 0) {
        modll ret;
        ret = divide(facts->facts[n], multiply(facts->facts[r], facts->facts[n - r]));
        return ret;
    }
    else {
        return createModll(0);
    }
}

modll get_fact(facts_t* facts, ll n) {
    return facts->facts[n];
}

modll id3(facts_t* facts, ll n) {
    return divide(get_fact(facts, n), get_fact(facts, n));
}

ll disc_log(modll a, modll b) {
    ll ret = -1;
    ll m = id8(1000000007);
    modll* mp = (modll*)malloc(m * sizeof(modll));
    for (int i = 0; i < m; i++) {
        mp[i] = createModll(0);
    }
    modll x = createModll(1);
    for (int i = 0; i < m; i++) {
        mp[x.val] = createModll(i);
        x = multiply(x, a);
    }
    x = divide(createModll(1), pow(a, m));
    modll k = b;
    for (int i = 0; i < m; i++) {
        if (mp[k.val].val == 0) {
            k = multiply(k, x);
        }
        else {
            ret = i * m + mp[k.val].val;
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
        update(ast, i, multiply(createModll(w), createModll(a[i])));
        update(lst, i, multiply(createModll(w), subtract(createModll(n - 1), createModll(i))));
        update(rst, i, multiply(createModll(w), createModll(i)));
    }
    modll* ans = (modll*)malloc(q * sizeof(modll));
    for (int unused = 0; unused < q; unused++) {
        int x;
        scanf("%d", &x);
        if (x < 0) {
            x++;
            ll y;
            scanf("%lld", &y);
            update(st, -x, y);
            update(ast, -x, multiply(createModll(y), createModll(a[-x])));
            update(lst, -x, multiply(createModll(y), subtract(createModll(n - 1), createModll(-x))));
            update(rst, -x, multiply(createModll(y), createModll(-x)));
        }
        else {
            int y;
            scanf("%d", &y);
            x--; y--;
            if (x == y) {
                ans[unused] = createModll(0);
            }
            else {
                int halfid;
                if (y - x == 1) {
                    halfid = x;
                }
                else {
                    bsargv_t v = { st, x, sum(st, x, y + 1) };
                    halfid = id4(x + 1, y, st, x, sum(st, x, y + 1));
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
                buf = add(buf, multiply(createModll(dst), subtract(sum(st, x, dstid), sum(ast, x, dstid))));
                buf = subtract(buf, subtract(sum(lst, x, dstid), multiply(sum(st, x, dstid), subtract(createModll(n - 1), createModll(dstid))))));
                buf = add(buf, subtract(sum(ast, dstid, y + 1), multiply(createModll(dst), subtract(sum(st, dstid, y + 1), sum(rst, dstid, y + 1))))));
                buf = subtract(buf, subtract(sum(rst, dstid, y + 1), multiply(sum(st, dstid, y + 1), createModll(dstid)))));
                ans[unused] = buf;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        printf("%lld\n", ans[i].val);
    }
    free(a);
    destroySegTree(st);
    destroySegTree(ast);
    destroySegTree(lst);
    destroySegTree(rst);
    free(ans);
    return 0;
}
