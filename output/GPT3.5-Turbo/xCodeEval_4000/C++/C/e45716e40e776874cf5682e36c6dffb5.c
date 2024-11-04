#include <stdio.h>
#include <stdlib.h>

#define N 200001

typedef long long ll;
typedef struct {
    ll max_v[4 * N], smax_v[4 * N], max_c[4 * N];
    ll min_v[4 * N], smin_v[4 * N], min_c[4 * N];
    ll sum[4 * N];
    ll len[4 * N], ladd[4 * N], lval[4 * N];
} SegmentTree;

void update_node_max(SegmentTree *seg, int k, ll x) {
    seg->sum[k] += (x - seg->max_v[k]) * seg->max_c[k];

    if (seg->max_v[k] == seg->min_v[k]) {
        seg->max_v[k] = seg->min_v[k] = x;
    } else if (seg->max_v[k] == seg->smin_v[k]) {
        seg->max_v[k] = seg->smin_v[k] = x;
    } else {
        seg->max_v[k] = x;
    }

    if (seg->lval[k] != -1 && x < seg->lval[k]) {
        seg->lval[k] = x;
    }
}

void update_node_min(SegmentTree *seg, int k, ll x) {
    seg->sum[k] += (x - seg->min_v[k]) * seg->min_c[k];

    if (seg->max_v[k] == seg->min_v[k]) {
        seg->max_v[k] = seg->min_v[k] = x;
    } else if (seg->smax_v[k] == seg->min_v[k]) {
        seg->min_v[k] = seg->smax_v[k] = x;
    } else {
        seg->min_v[k] = x;
    }

    if (seg->lval[k] != -1 && seg->lval[k] < x) {
        seg->lval[k] = x;
    }
}

void push(SegmentTree *seg, int k, int n0) {
    if (n0 - 1 <= k) {
        return;
    }

    if (seg->lval[k] != -1) {
        updateall(seg, 2 * k + 1, seg->lval[k]);
        updateall(seg, 2 * k + 2, seg->lval[k]);
        seg->lval[k] = -1;
        return;
    }

    if (seg->ladd[k] != 0) {
        addall(seg, 2 * k + 1, seg->ladd[k]);
        addall(seg, 2 * k + 2, seg->ladd[k]);
        seg->ladd[k] = 0;
    }

    if (seg->max_v[k] < seg->max_v[2 * k + 1]) {
        update_node_max(seg, 2 * k + 1, seg->max_v[k]);
    }
    if (seg->min_v[2 * k + 1] < seg->min_v[k]) {
        update_node_min(seg, 2 * k + 1, seg->min_v[k]);
    }

    if (seg->max_v[k] < seg->max_v[2 * k + 2]) {
        update_node_max(seg, 2 * k + 2, seg->max_v[k]);
    }
    if (seg->min_v[2 * k + 2] < seg->min_v[k]) {
        update_node_min(seg, 2 * k + 2, seg->min_v[k]);
    }
}

void update(SegmentTree *seg, int k) {
    seg->sum[k] = seg->sum[2 * k + 1] + seg->sum[2 * k + 2];

    if (seg->max_v[2 * k + 1] < seg->max_v[2 * k + 2]) {
        seg->max_v[k] = seg->max_v[2 * k + 2];
        seg->max_c[k] = seg->max_c[2 * k + 2];
        seg->smax_v[k] = (seg->max_v[2 * k + 1] > seg->smax_v[2 * k + 2]) ? seg->max_v[2 * k + 1] : seg->smax_v[2 * k + 2];
    } else if (seg->max_v[2 * k + 1] > seg->max_v[2 * k + 2]) {
        seg->max_v[k] = seg->max_v[2 * k + 1];
        seg->max_c[k] = seg->max_c[2 * k + 1];
        seg->smax_v[k] = (seg->smax_v[2 * k + 1] > seg->max_v[2 * k + 2]) ? seg->smax_v[2 * k + 1] : seg->max_v[2 * k + 2];
    } else {
        seg->max_v[k] = seg->max_v[2 * k + 1];
        seg->max_c[k] = seg->max_c[2 * k + 1] + seg->max_c[2 * k + 2];
        seg->smax_v[k] = (seg->smax_v[2 * k + 1] > seg->smax_v[2 * k + 2]) ? seg->smax_v[2 * k + 1] : seg->smax_v[2 * k + 2];
    }

    if (seg->min_v[2 * k + 1] < seg->min_v[2 * k + 2]) {
        seg->min_v[k] = seg->min_v[2 * k + 1];
        seg->min_c[k] = seg->min_c[2 * k + 1];
        seg->smin_v[k] = (seg->smin_v[2 * k + 1] < seg->min_v[2 * k + 2]) ? seg->smin_v[2 * k + 1] : seg->min_v[2 * k + 2];
    } else if (seg->min_v[2 * k + 1] > seg->min_v[2 * k + 2]) {
        seg->min_v[k] = seg->min_v[2 * k + 2];
        seg->min_c[k] = seg->min_c[2 * k + 2];
        seg->smin_v[k] = (seg->min_v[2 * k + 1] < seg->smin_v[2 * k + 2]) ? seg->min_v[2 * k + 1] : seg->smin_v[2 * k + 2];
    } else {
        seg->min_v[k] = seg->min_v[2 * k + 1];
        seg->min_c[k] = seg->min_c[2 * k + 1] + seg->min_c[2 * k + 2];
        seg->smin_v[k] = (seg->smin_v[2 * k + 1] < seg->smin_v[2 * k + 2]) ? seg->smin_v[2 * k + 1] : seg->smin_v[2 * k + 2];
    }
}

void updateall(SegmentTree *seg, int k, ll x) {
    seg->max_v[k] += x;
    if (seg->smax_v[k] != -1) {
        seg->smax_v[k] += x;
    }
    seg->min_v[k] += x;
    if (seg->smin_v[k] != -1) {
        seg->smin_v[k] += x;
    }

    seg->sum[k] += seg->len[k] * x;
    if (seg->lval[k] != -1) {
        seg->lval[k] += x;
    } else {
        seg->ladd[k] += x;
    }
}

void updateall(SegmentTree *seg, int k, ll x) {
    seg->max_v[k] = x;
    seg->smax_v[k] = -1;
    seg->min_v[k] = x;
    seg->smin_v[k] = -1;
    seg->max_c[k] = seg->min_c[k] = seg->len[k];

    seg->sum[k] = x * seg->len[k];
    seg->lval[k] = x;
    seg->ladd[k] = 0;
}

void addall(SegmentTree *seg, int k, ll x) {
    seg->max_v[k] += x;
    if (seg->smax_v[k] != -1) {
        seg->smax_v[k] += x;
    }
    seg->min_v[k] += x;
    if (seg->smin_v[k] != -1) {
        seg->smin_v[k] += x;
    }

    seg->sum[k] += seg->len[k] * x;
    if (seg->lval[k] != -1) {
        seg->lval[k] += x;
    } else {
        seg->ladd[k] += x;
    }
}

void _add_val(SegmentTree *seg, ll x, int a, int b, int k, int l, int r) {
    if (b <= l || r <= a) {
        return;
    }
    if (a <= l && r <= b) {
        addall(seg, k, x);
        return;
    }

    push(seg, k, seg->len[0]);
    _add_val(seg, x, a, b, 2 * k + 1, l, (l + r) / 2);
    _add_val(seg, x, a, b, 2 * k + 2, (l + r) / 2, r);
    update(seg, k);
}

void _update_val(SegmentTree *seg, ll x, int a, int b, int k, int l, int r) {
    if (b <= l || r <= a) {
        return;
    }
    if (a <= l && r <= b) {
        updateall(seg, k, x);
        return;
    }

    push(seg, k, seg->len[0]);
    _update_val(seg, x, a, b, 2 * k + 1, l, (l + r) / 2);
    _update_val(seg, x, a, b, 2 * k + 2, (l + r) / 2, r);
    update(seg, k);
}

ll _query_max(SegmentTree *seg, int a, int b, int k, int l, int r) {
    if (b <= l || r <= a) {
        return -1;
    }
    if (a <= l && r <= b) {
        return seg->max_v[k];
    }
    push(seg, k, seg->len[0]);
    ll lv = _query_max(seg, a, b, 2 * k + 1, l, (l + r) / 2);
    ll rv = _query_max(seg, a, b, 2 * k + 2, (l + r) / 2, r);
    return (lv > rv) ? lv : rv;
}

ll _query_min(SegmentTree *seg, int a, int b, int k, int l, int r) {
    if (b <= l || r <= a) {
        return -1;
    }
    if (a <= l && r <= b) {
        return seg->min_v[k];
    }
    push(seg, k, seg->len[0]);
    ll lv = _query_min(seg, a, b, 2 * k + 1, l, (l + r) / 2);
    ll rv = _query_min(seg, a, b, 2 * k + 2, (l + r) / 2, r);
    return (lv < rv) ? lv : rv;
}

ll _query_sum(SegmentTree *seg, int a, int b, int k, int l, int r) {
    if (b <= l || r <= a) {
        return 0;
    }
    if (a <= l && r <= b) {
        return seg->sum[k];
    }
    push(seg, k, seg->len[0]);
    ll lv = _query_sum(seg, a, b, 2 * k + 1, l, (l + r) / 2);
    ll rv = _query_sum(seg, a, b, 2 * k + 2, (l + r) / 2, r);
    return lv + rv;
}

SegmentTree *create_segment_tree(int n, ll *a) {
    SegmentTree *seg = (SegmentTree *)malloc(sizeof(SegmentTree));
    int n0 = 1;
    while (n0 < n) {
        n0 <<= 1;
    }

    for (int i = 0; i < 2 * n0; ++i) {
        seg->ladd[i] = 0;
        seg->lval[i] = -1;
    }
    seg->len[0] = n0;
    for (int i = 0; i < n0 - 1; ++i) {
        seg->len[2 * i + 1] = seg->len[2 * i + 2] = (seg->len[i] >> 1);
    }

    for (int i = 0; i < n; ++i) {
        seg->max_v[n0 - 1 + i] = seg->min_v[n0 - 1 + i] = seg->sum[n0 - 1 + i] = (a != NULL) ? a[i] : 0;
        seg->smax_v[n0 - 1 + i] = -1;
        seg->smin_v[n0 - 1 + i] = -1;
        seg->max_c[n0 - 1 + i] = seg->min_c[n0 - 1 + i] = 1;
    }

    for (int i = n; i < n0; ++i) {
        seg->max_v[n0 - 1 + i] = seg->smax_v[n0 - 1 + i] = -1;
        seg->min_v[n0 - 1 + i] = seg->smin_v[n0 - 1 + i] = -1;
        seg->max_c[n0 - 1 + i] = seg->min_c[n0 - 1 + i] = 0;
    }
    for (int i = n0 - 2; i >= 0; i--) {
        update(seg, i);
    }

    return seg;
}

void update_min(SegmentTree *seg, int a, int b, ll x) {
    _update_min(seg, x, a, b, 0, 0, seg->len[0]);
}

void update_max(SegmentTree *seg, int a, int b, ll x) {
    _update_max(seg, x, a, b, 0, 0, seg->len[0]);
}

void add_val(SegmentTree *seg, int a, int b, ll x) {
    _add_val(seg, x, a, b, 0, 0, seg->len[0]);
}

void update_val(SegmentTree *seg, int a, int b, ll x) {
    _update_val(seg, x, a, b, 0, 0, seg->len[0]);
}

ll query_max(SegmentTree *seg, int a, int b) {
    return _query_max(seg, a, b, 0, 0, seg->len[0]);
}

ll query_min(SegmentTree *seg, int a, int b) {
    return _query_min(seg, a, b, 0, 0, seg->len[0]);
}

ll query_sum(SegmentTree *seg, int a, int b) {
    return _query_sum(seg, a, b, 0, 0, seg->len[0]);
}

void free_segment_tree(SegmentTree *seg) {
    free(seg);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    SegmentTree *seg = create_segment_tree(n, a);

    ll ans = 0;
    for (int i = 200000; i >= 1; i--) {
        int w[n];
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] % i == 0) {
                w[count++] = j;
            }
        }
        if (count <= 1) {
            continue;
        }

        int s[4];
        s[0] = w[0];
        s[1] = w[1];
        s[2] = w[count - 2];
        s[3] = w[count - 1];
        void (*F)(int, int) = &update_max;
        ll pre = query_sum(seg, 0, n);
        F(s[0] + 1, s[3]);
        F(0, s[2]);
        F(s[1] + 1, n);
        ans += (query_sum(seg, 0, n) - pre) * i;
    }
    printf("%lld\n", ans);

    free_segment_tree(seg);

    return 0;
}
