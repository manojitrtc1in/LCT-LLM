#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

typedef struct {
    long long w;
    long long Wp;
    long long fp;
    long long tp;
} Node;

typedef struct {
    int n;
    Node *tree;
} SegTree;

long long inverse(long long a, long long m) {
    long long u = 0, v = 1;
    while (a != 0) {
        long long t = m / a;
        m -= t * a; 
        long long temp = a; a = m; m = temp;
        u -= t * v; 
        temp = u; u = v; v = temp;
    }
    assert(m == 1);
    return u;
}

long long normalize(long long x, long long mod) {
    long long v;
    if (-mod <= x && x < mod) v = x;
    else v = x % mod;
    if (v < 0) v += mod;
    return v;
}

void apply(Node *node, int l, int r, int v, int id, int rid, int a) {
    node->w = v;
    node->Wp = normalize(v * a, 1000000007);
    node->fp = normalize(v * id, 1000000007);
    node->tp = normalize(v * rid, 1000000007);
}

Node unite(Node a, Node b) {
    Node res;
    res.w = a.w + b.w;
    res.Wp = normalize(a.Wp + b.Wp, 1000000007);
    res.fp = normalize(a.fp + b.fp, 1000000007);
    res.tp = normalize(a.tp + b.tp, 1000000007);
    return res;
}

void push(SegTree *st, int x, int l, int r) {
    // No operation for push in this context
}

void pull(SegTree *st, int x, int z) {
    st->tree[x] = unite(st->tree[x + 1], st->tree[z]);
}

void build(SegTree *st, int x, int l, int r, int *v, int *a) {
    if (l == r) {
        apply(&st->tree[x], l, r, v[l], l, st->n - 1 - r, a[l]);
        return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(st, x + 1, l, y, v, a);
    build(st, z, y + 1, r, v, a);
    pull(st, x, z);
}

Node get(SegTree *st, int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
        return st->tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(st, x, l, r);
    Node res = {0, 0, 0, 0};
    if (rr <= y) {
        res = get(st, x + 1, l, y, ll, rr);
    } else {
        if (ll > y) {
            res = get(st, z, y + 1, r, ll, rr);
        } else {
            res = unite(get(st, x + 1, l, y, ll, rr), get(st, z, y + 1, r, ll, rr));
        }
    }
    pull(st, x, z);
    return res;
}

void modify(SegTree *st, int x, int l, int r, int ll, int rr, int v, int id, int rid, int a) {
    if (ll <= l && r <= rr) {
        apply(&st->tree[x], l, r, v, id, rid, a);
        return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(st, x, l, r);
    if (ll <= y) {
        modify(st, x + 1, l, y, ll, rr, v, id, rid, a);
    }
    if (rr > y) {
        modify(st, z, y + 1, r, ll, rr, v, id, rid, a);
    }
    pull(st, x, z);
}

int find_first(SegTree *st, int x, int l, int r, int ll, int rr, int (*f)(Node)) {
    if (ll <= l && r <= rr) {
        if (!f(st->tree[x])) {
            return -1;
        }
        return find_first_knowingly(st, x, l, r, f);
    }
    push(st, x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
        res = find_first(st, x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
        res = find_first(st, z, y + 1, r, ll, rr, f);
    }
    pull(st, x, z);
    return res;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int *a = (int *)malloc(n * sizeof(int));
    int *w = (int *)malloc(n * sizeof(int));
    range(i, 0, n) scanf("%d", &a[i]);
    range(i, 0, n) scanf("%d", &w[i]);
    
    SegTree st;
    st.n = n;
    st.tree = (Node *)malloc((2 * n - 1) * sizeof(Node));
    build(&st, 0, 0, n - 1, a, w);
    
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < 0) {
            x = -x;
            x--;
            modify(&st, 0, 0, n - 1, x, x, y, x, n - 1 - x, a[x]);
        } else {
            x--; y--;
            long long v = 0;
            long long sum = st.get(&st, x, y).w;
            int pos = find_first(&st, 0, 0, n - 1, x, y, [&](Node a) {
                if ((v + a.w) * 2 >= sum) return 1;
                v += a.w;
                return 0;
            });
            assert(pos != -1);
            Node l = get(&st, x, pos);
            Node r = get(&st, pos, y);
            long long res = 0;

            res += r.Wp - r.fp - normalize((a[pos] - pos) * r.w, 1000000007);
            res += normalize((a[pos] - pos) * l.w + l.fp - l.Wp, 1000000007);
            printf("%lld\n", res);
        }
    }
    
    free(a);
    free(w);
    free(st.tree);
    return 0;
}
