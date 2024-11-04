#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <complex.h>
#include <stdbool.h>

#define MOD 1000000007

typedef long long ll;
typedef struct {
    ll *data;
    int size;
} vll;

typedef struct {
    ll *data;
    int size;
} modll;

typedef struct {
    ll *nodes;
    int n, N, base;
} SegTree;

double eps = 1e-9;

bool id6(double x, double y) { return fabs(x - y) < eps; }
bool inrange(ll x, ll t) { return x >= 0 && x < t; }
bool inrange_vll(vll xs, ll t) {
    for (int i = 0; i < xs.size; i++) {
        if (!(xs.data[i] >= 0 && xs.data[i] < t)) return false;
    }
    return true;
}
int id5(ll x) {
    int ret = 0;
    x--;
    while (x > 0) {
        ret++;
        x >>= 1;
    }
    return ret;
}
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll id2(ll x) { ll m = (ll)sqrt((double)x); return m + (m * m <= x ? 0 : -1); }
ll id8(ll x) { ll m = (ll)sqrt((double)x); return m + (x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { return n == 0 ? m : gcd(n, m % n); }
ll lcm(ll m, ll n) { return m * n / gcd(m, n); }

int left_of(int index, int base) {
    if (index >= base) return -1;
    return index * 2 + 1;
}
int right_of(int index, int base) {
    if (index >= base) return -1;
    return index * 2 + 2;
}
int parent_of(int index) {
    if (index == 0) return -1;
    return (index - 1) >> 1;
}

void update_rec(SegTree *st, int s, int t, int l, int r, int index, ll v) {
    if (s == l && t == r) {
        st->nodes[index] = v;
    } else {
        int mid = (l + r) / 2;
        int index_l = left_of(index, st->base);
        int index_r = right_of(index, st->base);
        if (s < mid && mid < t) {
            update_rec(st, s, mid, l, mid, index_l, v);
            update_rec(st, mid, t, mid, r, index_r, v);
        } else if (s < mid) {
            update_rec(st, s, t, l, mid, index_l, v);
        } else if (mid < t) {
            update_rec(st, s, t, mid, r, index_r, v);
        }
        st->nodes[index] = st->nodes[index_l] + st->nodes[index_r];
    }
}

ll add_rec(SegTree *st, int s, int t, int l, int r, int index) {
    if (s == l && t == r) {
        return st->nodes[index];
    } else {
        int mid = (l + r) / 2;
        int index_l = left_of(index, st->base);
        int index_r = right_of(index, st->base);
        ll v0 = 0, v1 = 0;
        if (s < mid && mid < t) {
            v0 = add_rec(st, s, mid, l, mid, index_l);
            v1 = add_rec(st, mid, t, mid, r, index_r);
        } else if (s < mid) {
            v0 = add_rec(st, s, t, l, mid, index_l);
        } else if (mid < t) {
            v1 = add_rec(st, s, t, mid, r, index_r);
        }
        return v0 + v1;
    }
}

SegTree* create_seg_tree(int n, ll init) {
    SegTree *st = (SegTree *)malloc(sizeof(SegTree));
    st->n = n;
    st->N = (int)pow(2, ceil(log2(n)));
    st->base = st->N - 1;
    st->nodes = (ll *)malloc((st->base + st->N) * sizeof(ll));
    for (int i = 0; i < (st->base + st->N); i++) {
        st->nodes[i] = init;
    }
    return st;
}

void update(SegTree *st, int k, ll v) {
    update_rec(st, k, k + 1, 0, st->N, 0, v);
}

ll sum(SegTree *st, int s, int t) {
    return add_rec(st, s, t, 0, st->N, 0);
}

modll create_modll(ll init) {
    modll m;
    m.data = (ll *)malloc(sizeof(ll));
    m.data[0] = init % MOD;
    if (m.data[0] < 0) m.data[0] += MOD;
    return m;
}

modll modll_add(modll x, modll y) {
    return create_modll((x.data[0] + y.data[0]) % MOD);
}

modll modll_sub(modll x, modll y) {
    return create_modll((x.data[0] - y.data[0] + MOD) % MOD);
}

modll modll_mul(modll x, modll y) {
    return create_modll((x.data[0] * y.data[0]) % MOD);
}

modll modll_div(modll x, modll y) {
    // Implement modular division using Fermat's Little Theorem
    return modll_mul(x, create_modll(pow(y.data[0], MOD - 2)));
}

modll pow_modll(modll n, ll p) {
    modll ret = create_modll(1);
    if (p == 0) return ret;
    if (p == 1) return n;
    ret = pow_modll(n, p / 2);
    ret = modll_mul(ret, ret);
    if (p % 2 == 1) ret = modll_mul(ret, n);
    return ret;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    vll a;
    a.data = (ll *)malloc(n * sizeof(ll));
    a.size = n;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a.data[i]);
    }
    
    SegTree *st = create_seg_tree(n, 0);
    SegTree *ast = create_seg_tree(n, 0);
    SegTree *lst = create_seg_tree(n, 0);
    SegTree *rst = create_seg_tree(n, 0);
    
    for (int i = 0; i < n; i++) {
        ll w;
        scanf("%lld", &w);
        update(st, i, w);
        update(ast, i, modll_mul(create_modll(w), create_modll(a.data[i])).data[0]);
        update(lst, i, modll_mul(create_modll(w), create_modll(n - 1 - i)).data[0]);
        update(rst, i, modll_mul(create_modll(w), create_modll(i)).data[0]);
    }
    
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        if (x < 0) {
            x++;
            ll y;
            scanf("%lld", &y);
            update(st, -x, y);
            update(ast, -x, modll_mul(create_modll(y), create_modll(a.data[-x])).data[0]);
            update(lst, -x, modll_mul(create_modll(y), create_modll(n - 1 - (-x))).data[0]);
            update(rst, -x, modll_mul(create_modll(y), create_modll(-x)).data[0]);
        } else {
            int y;
            scanf("%d", &y);
            x--; y--;
            if (x == y) {
                printf("0\n");
            } else {
                // Additional logic for handling queries
            }
        }
    }
    
    // Free allocated memory
    free(a.data);
    free(st->nodes);
    free(st);
    free(ast->nodes);
    free(ast);
    free(lst->nodes);
    free(lst);
    free(rst->nodes);
    free(rst);
    
    return 0;
}
