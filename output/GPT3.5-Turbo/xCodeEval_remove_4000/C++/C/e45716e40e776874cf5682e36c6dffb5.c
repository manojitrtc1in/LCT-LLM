#include <stdio.h>
#include <stdlib.h>

#define N 200001

typedef long long ll;
typedef struct {
    int from, to;
    ll cost;
    int id;
} edge;

typedef struct {
    int n, n0;
    ll max_v[4 * N], smax_v[4 * N], max_c[4 * N];
    ll min_v[4 * N], smin_v[4 * N], min_c[4 * N];
    ll sum[4 * N];
    ll len[4 * N], ladd[4 * N], lval[4 * N];
} SegmentTree;

SegmentTree* createSegmentTree(int n) {
    SegmentTree* st = (SegmentTree*) malloc(sizeof(SegmentTree));
    st->n = n;
    st->n0 = 1;
    while (st->n0 < n) {
        st->n0 <<= 1;
    }
    for (int i = 0; i < 2 * st->n0; ++i) {
        st->ladd[i] = 0;
        st->lval[i] = 1e18;
    }
    st->len[0] = st->n0;
    for (int i = 0; i < st->n0 - 1; ++i) {
        st->len[2 * i + 1] = st->len[2 * i + 2] = (st->len[i] >> 1);
    }
    for (int i = 0; i < n; ++i) {
        st->max_v[st->n0 - 1 + i] = st->min_v[st->n0 - 1 + i] = st->sum[st->n0 - 1 + i] = 0;
        st->smax_v[st->n0 - 1 + i] = -1e18;
        st->smin_v[st->n0 - 1 + i] = 1e18;
        st->max_c[st->n0 - 1 + i] = st->min_c[st->n0 - 1 + i] = 1;
    }
    for (int i = n; i < st->n0; ++i) {
        st->max_v[st->n0 - 1 + i] = st->smax_v[st->n0 - 1 + i] = -1e18;
        st->min_v[st->n0 - 1 + i] = st->smin_v[st->n0 - 1 + i] = 1e18;
        st->max_c[st->n0 - 1 + i] = st->min_c[st->n0 - 1 + i] = 0;
    }
    for (int i = st->n0 - 2; i >= 0; i--) {
        ll max_v = st->max_v[2 * i + 1];
        ll max_c = st->max_c[2 * i + 1];
        ll smax_v = st->smax_v[2 * i + 1];
        ll min_v = st->min_v[2 * i + 1];
        ll min_c = st->min_c[2 * i + 1];
        ll smin_v = st->smin_v[2 * i + 1];
        ll sum = st->sum[2 * i + 1];
        if (max_v < st->max_v[2 * i + 2]) {
            max_v = st->max_v[2 * i + 2];
            max_c = st->max_c[2 * i + 2];
            smax_v = (max_v > st->smax_v[2 * i + 2]) ? max_v : st->smax_v[2 * i + 2];
        } else if (max_v > st->max_v[2 * i + 2]) {
            smax_v = (max_v > st->smax_v[2 * i + 2]) ? max_v : st->smax_v[2 * i + 2];
        }
        if (min_v > st->min_v[2 * i + 2]) {
            min_v = st->min_v[2 * i + 2];
            min_c = st->min_c[2 * i + 2];
            smin_v = (min_v < st->smin_v[2 * i + 2]) ? min_v : st->smin_v[2 * i + 2];
        } else if (min_v < st->min_v[2 * i + 2]) {
            smin_v = (min_v < st->smin_v[2 * i + 2]) ? min_v : st->smin_v[2 * i + 2];
        }
        st->max_v[i] = max_v;
        st->max_c[i] = max_c;
        st->smax_v[i] = smax_v;
        st->min_v[i] = min_v;
        st->min_c[i] = min_c;
        st->smin_v[i] = smin_v;
        st->sum[i] = sum + st->sum[2 * i + 2];
    }
    return st;
}

void update_node_max(SegmentTree* st, int k, ll x) {
    st->sum[k] += (x - st->max_v[k]) * st->max_c[k];
    if (st->max_v[k] == st->min_v[k]) {
        st->max_v[k] = st->min_v[k] = x;
    } else if (st->max_v[k] == st->smin_v[k]) {
        st->max_v[k] = st->smin_v[k] = x;
    } else {
        st->max_v[k] = x;
    }
    if (st->lval[k] != 1e18 && x < st->lval[k]) {
        st->lval[k] = x;
    }
}

void update_node_min(SegmentTree* st, int k, ll x) {
    st->sum[k] += (x - st->min_v[k]) * st->min_c[k];
    if (st->max_v[k] == st->min_v[k]) {
        st->max_v[k] = st->min_v[k] = x;
    } else if (st->smax_v[k] == st->min_v[k]) {
        st->min_v[k] = st->smax_v[k] = x;
    } else {
        st->min_v[k] = x;
    }
    if (st->lval[k] != 1e18 && st->lval[k] < x) {
        st->lval[k] = x;
    }
}

void push(SegmentTree* st, int k) {
    if (st->n0 - 1 <= k) {
        return;
    }
    if (st->lval[k] != 1e18) {
        updateall(st, 2 * k + 1, st->lval[k]);
        updateall(st, 2 * k + 2, st->lval[k]);
        st->lval[k] = 1e18;
        return;
    }
    if (st->ladd[k] != 0) {
        addall(st, 2 * k + 1, st->ladd[k]);
        addall(st, 2 * k + 2, st->ladd[k]);
        st->ladd[k] = 0;
    }
    if (st->max_v[k] < st->max_v[2 * k + 1]) {
        update_node_max(st, 2 * k + 1, st->max_v[k]);
    }
    if (st->min_v[2 * k + 1] < st->min_v[k]) {
        update_node_min(st, 2 * k + 1, st->min_v[k]);
    }
    if (st->max_v[k] < st->max_v[2 * k + 2]) {
        update_node_max(st, 2 * k + 2, st->max_v[k]);
    }
    if (st->min_v[2 * k + 2] < st->min_v[k]) {
        update_node_min(st, 2 * k + 2, st->min_v[k]);
    }
}

void update(SegmentTree* st, int k) {
    st->sum[k] = st->sum[2 * k + 1] + st->sum[2 * k + 2];
    if (st->max_v[2 * k + 1] < st->max_v[2 * k + 2]) {
        st->max_v[k] = st->max_v[2 * k + 2];
        st->max_c[k] = st->max_c[2 * k + 2];
        st->smax_v[k] = (st->max_v[2 * k + 1] > st->smax_v[2 * k + 2]) ? st->max_v[2 * k + 1] : st->smax_v[2 * k + 2];
    } else if (st->max_v[2 * k + 1] > st->max_v[2 * k + 2]) {
        st->max_v[k] = st->max_v[2 * k + 1];
        st->max_c[k] = st->max_c[2 * k + 1];
        st->smax_v[k] = (st->smax_v[2 * k + 1] > st->max_v[2 * k + 2]) ? st->smax_v[2 * k + 1] : st->max_v[2 * k + 2];
    } else {
        st->max_v[k] = st->max_v[2 * k + 1];
        st->max_c[k] = st->max_c[2 * k + 1] + st->max_c[2 * k + 2];
        st->smax_v[k] = (st->smax_v[2 * k + 1] > st->smax_v[2 * k + 2]) ? st->smax_v[2 * k + 1] : st->smax_v[2 * k + 2];
    }
    if (st->min_v[2 * k + 1] < st->min_v[2 * k + 2]) {
        st->min_v[k] = st->min_v[2 * k + 1];
        st->min_c[k] = st->min_c[2 * k + 1];
        st->smin_v[k] = (st->smin_v[2 * k + 1] < st->min_v[2 * k + 2]) ? st->smin_v[2 * k + 1] : st->min_v[2 * k + 2];
    } else if (st->min_v[2 * k + 1] > st->min_v[2 * k + 2]) {
        st->min_v[k] = st->min_v[2 * k + 2];
        st->min_c[k] = st->min_c[2 * k + 2];
        st->smin_v[k] = (st->min_v[2 * k + 1] < st->smin_v[2 * k + 2]) ? st->min_v[2 * k + 1] : st->smin_v[2 * k + 2];
    } else {
        st->min_v[k] = st->min_v[2 * k + 1];
        st->min_c[k] = st->min_c[2 * k + 1] + st->min_c[2 * k + 2];
        st->smin_v[k] = (st->smin_v[2 * k + 1] < st->smin_v[2 * k + 2]) ? st->smin_v[2 * k + 1] : st->smin_v[2 * k + 2];
    }
}

void update_min(SegmentTree* st, int a, int b, ll x) {
    if (b <= a || st->max_v[0] <= x) {
        return;
    }
    if (a <= 0 && st->n0 <= b && st->smax_v[0] < x) {
        update_node_max(st, 0, x);
        return;
    }
    push(st, 0);
    update_min(st, a, b, 2 * 0 + 1, 0, st->n0 / 2);
    update_min(st, a, b, 2 * 0 + 2, st->n0 / 2, st->n0);
    update(st, 0);
}

void update_max(SegmentTree* st, int a, int b, ll x) {
    if (b <= a || x <= st->min_v[0]) {
        return;
    }
    if (a <= 0 && st->n0 <= b && x < st->smin_v[0]) {
        update_node_min(st, 0, x);
        return;
    }
    push(st, 0);
    update_max(st, a, b, 2 * 0 + 1, 0, st->n0 / 2);
    update_max(st, a, b, 2 * 0 + 2, st->n0 / 2, st->n0);
    update(st, 0);
}

void addall(SegmentTree* st, int k, ll x) {
    st->max_v[k] += x;
    if (st->smax_v[k] != -1e18) {
        st->smax_v[k] += x;
    }
    st->min_v[k] += x;
    if (st->smin_v[k] != 1e18) {
        st->smin_v[k] += x;
    }
    st->sum[k] += st->len[k] * x;
    if (st->lval[k] != 1e18) {
        st->lval[k] += x;
    } else {
        st->ladd[k] += x;
    }
}

void updateall(SegmentTree* st, int k, ll x) {
    st->max_v[k] = x;
    st->smax_v[k] = -1e18;
    st->min_v[k] = x;
    st->smin_v[k] = 1e18;
    st->max_c[k] = st->min_c[k] = st->len[k];
    st->sum[k] = x * st->len[k];
    st->lval[k] = x;
    st->ladd[k] = 0;
}

ll query_max(SegmentTree* st, int a, int b) {
    if (b <= a) {
        return -1e18;
    }
    if (a <= 0 && st->n0 <= b) {
        return st->max_v[0];
    }
    push(st, 0);
    ll lv = query_max(st, a, b, 2 * 0 + 1, 0, st->n0 / 2);
    ll rv = query_max(st, a, b, 2 * 0 + 2, st->n0 / 2, st->n0);
    return (lv > rv) ? lv : rv;
}

ll query_min(SegmentTree* st, int a, int b) {
    if (b <= a) {
        return 1e18;
    }
    if (a <= 0 && st->n0 <= b) {
        return st->min_v[0];
    }
    push(st, 0);
    ll lv = query_min(st, a, b, 2 * 0 + 1, 0, st->n0 / 2);
    ll rv = query_min(st, a, b, 2 * 0 + 2, st->n0 / 2, st->n0);
    return (lv < rv) ? lv : rv;
}

ll query_sum(SegmentTree* st, int a, int b) {
    if (b <= a) {
        return 0;
    }
    if (a <= 0 && st->n0 <= b) {
        return st->sum[0];
    }
    push(st, 0);
    ll lv = query_sum(st, a, b, 2 * 0 + 1, 0, st->n0 / 2);
    ll rv = query_sum(st, a, b, 2 * 0 + 2, st->n0 / 2, st->n0);
    return lv + rv;
}

void update_min_range(SegmentTree* st, int a, int b, ll x) {
    update_min(st, a, b, x);
}

void update_max_range(SegmentTree* st, int a, int b, ll x) {
    update_max(st, a, b, x);
}

void add_val_range(SegmentTree* st, int a, int b, ll x) {
    addall(st, 0, x);
}

void update_val_range(SegmentTree* st, int a, int b, ll x) {
    updateall(st, 0, x);
}

ll query_max_range(SegmentTree* st, int a, int b) {
    return query_max(st, a, b);
}

ll query_min_range(SegmentTree* st, int a, int b) {
    return query_min(st, a, b);
}

ll query_sum_range(SegmentTree* st, int a, int b) {
    return query_sum(st, a, b);
}

void destroySegmentTree(SegmentTree* st) {
    free(st);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    SegmentTree* seg = createSegmentTree(n);
    ll ans = 0;
    for (int i = 1; i <= 200000; i++) {
        int d[i];
        int size = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] % i == 0) {
                d[size++] = j;
            }
        }
        if (size <= 1) {
            continue;
        }
        int s[4];
        s[0] = d[0];
        s[1] = d[1];
        s[2] = d[size - 2];
        s[3] = d[size - 1];
        void (*F)(int, int) = NULL;
        ll pre = query_sum_range(seg, 0, n);
        F(s[0] + 1, s[3]);
        F(0, s[2]);
        F(s[1] + 1, n);
        ans += (query_sum_range(seg, 0, n) - pre) * i;
    }
    printf("%lld\n", ans);
    destroySegmentTree(seg);
    return 0;
}
