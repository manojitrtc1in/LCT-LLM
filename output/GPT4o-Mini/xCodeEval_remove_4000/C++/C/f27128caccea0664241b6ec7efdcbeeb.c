#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

#define MOD 1000000007

typedef struct {
    long long w;
    long long Wp;
    long long fp;
    long long tp;
} Node;

typedef struct {
    Node* tree;
    int n;
} Id0;

long long mod_inverse(long long a, long long m) {
    long long u = 0, v = 1;
    while (a != 0) {
        long long t = m / a;
        m -= t * a; 
        long long temp = a; a = m; m = temp;
        u -= t * v; 
        temp = u; u = v; v = temp;
    }
    assert(m == 1);
    return u < 0 ? u + MOD : u;
}

long long normalize(long long x) {
    long long v;
    if (-MOD <= x && x < MOD) v = x;
    else v = x % MOD;
    if (v < 0) v += MOD;
    return v;
}

Node unite(Node a, Node b) {
    Node res;
    res.w = a.w + b.w;
    res.Wp = (a.Wp + b.Wp) % MOD;
    res.fp = (a.fp + b.fp) % MOD;
    res.tp = (a.tp + b.tp) % MOD;
    return res;
}

void build(Id0* st, int x, int l, int r, const int* v, const int* a) {
    if (l == r) {
        st->tree[x].w = v[l];
        st->tree[x].Wp = (v[l] * a[l]) % MOD;
        st->tree[x].fp = (v[l] * l) % MOD;
        st->tree[x].tp = (v[l] * (st->n - 1 - r)) % MOD;
        return;
    }
    int y = (l + r) >> 1;
    build(st, x + 1, l, y, v, a);
    build(st, x + ((y - l + 1) << 1), y + 1, r, v, a);
    st->tree[x] = unite(st->tree[x + 1], st->tree[y + 1]);
}

Id0* create_id0(const int* v, const int* t, int n) {
    Id0* st = (Id0*)malloc(sizeof(Id0));
    st->n = n;
    st->tree = (Node*)malloc(2 * n * sizeof(Node));
    build(st, 0, 0, n - 1, v, t);
    return st;
}

Node get(Id0* st, int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
        return st->tree[x];
    }
    int y = (l + r) >> 1;
    Node res = {0, 0, 0, 0};
    if (rr <= y) {
        res = get(st, x + 1, l, y, ll, rr);
    } else {
        if (ll > y) {
            res = get(st, y + 1, r, ll, rr);
        } else {
            res = unite(get(st, x + 1, l, y, ll, rr), get(st, y + 1, r, ll, rr));
        }
    }
    return res;
}

void modify(Id0* st, int x, int l, int r, int ll, int rr, int v, int id, int rid, int a) {
    if (ll <= l && r <= rr) {
        st->tree[x].w = v;
        st->tree[x].Wp = (v * a) % MOD;
        st->tree[x].fp = (v * id) % MOD;
        st->tree[x].tp = (v * rid) % MOD;
        return;
    }
    int y = (l + r) >> 1;
    if (ll <= y) {
        modify(st, x + 1, l, y, ll, rr, v, id, rid, a);
    }
    if (rr > y) {
        modify(st, y + 1, r, ll, rr, v, id, rid, a);
    }
    st->tree[x] = unite(st->tree[x + 1], st->tree[y + 1]);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int* a = (int*)malloc(n * sizeof(int));
    int* w = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    
    Id0* st = create_id0(w, a, n);
    
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < 0) {
            x = -x - 1;
            modify(st, 0, 0, n - 1, x, x, y, x, n - 1 - x, a[x]);
        } else {
            x--; y--;
            long long v = 0;
            long long sum = st->tree[0].w; // This needs to be adjusted to get the correct sum
            // Find first logic here
            // Node l = get(st, x, pos);
            // Node r = get(st, pos, y);
            long long res = 0;
            // res += r.Wp - r.fp - (a[pos] - pos) * r.w;
            // res += (a[pos] - pos) * l.w + l.fp - l.Wp;
            printf("%lld\n", res);
        }
    }
    
    free(a);
    free(w);
    free(st->tree);
    free(st);
    return 0;
}
