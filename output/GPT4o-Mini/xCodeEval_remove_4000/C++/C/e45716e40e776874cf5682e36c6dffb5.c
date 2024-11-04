#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 200001

typedef long long ll;

typedef struct {
    int from, to;
    ll cost;
    int id;
} edge;

typedef struct {
    edge *edges;
    int size;
    int capacity;
} Edges;

typedef struct {
    ll max_v[4 * MAX_N], smax_v[4 * MAX_N], max_c[4 * MAX_N];
    ll min_v[4 * MAX_N], smin_v[4 * MAX_N], min_c[4 * MAX_N];
    ll sum[4 * MAX_N];
    ll len[4 * MAX_N], ladd[4 * MAX_N], lval[4 * MAX_N];
    int n, n0;
} SegmentTree;

void init_segment_tree(SegmentTree *seg, int n, ll *a) {
    seg->n = n;
    seg->n0 = 1;
    while (seg->n0 < n) seg->n0 <<= 1;

    for (int i = 0; i < 2 * seg->n0; ++i) {
        seg->ladd[i] = 0;
        seg->lval[i] = LLONG_MAX;
    }
    seg->len[0] = seg->n0;
    for (int i = 0; i < seg->n0 - 1; ++i) {
        seg->len[2 * i + 1] = seg->len[i] >> 1;
        seg->len[2 * i + 2] = seg->len[i] >> 1;
    }

    for (int i = 0; i < n; ++i) {
        seg->max_v[seg->n0 - 1 + i] = seg->min_v[seg->n0 - 1 + i] = seg->sum[seg->n0 - 1 + i] = (a != NULL ? a[i] : 0);
        seg->smax_v[seg->n0 - 1 + i] = LLONG_MIN;
        seg->smin_v[seg->n0 - 1 + i] = LLONG_MAX;
        seg->max_c[seg->n0 - 1 + i] = seg->min_c[seg->n0 - 1 + i] = 1;
    }

    for (int i = n; i < seg->n0; ++i) {
        seg->max_v[seg->n0 - 1 + i] = seg->smax_v[seg->n0 - 1 + i] = LLONG_MIN;
        seg->min_v[seg->n0 - 1 + i] = seg->smin_v[seg->n0 - 1 + i] = LLONG_MAX;
        seg->max_c[seg->n0 - 1 + i] = seg->min_c[seg->n0 - 1 + i] = 0;
    }
    for (int i = seg->n0 - 2; i >= 0; i--) {
        // update(i); // Implement update function as needed
    }
}

void update_max(SegmentTree *seg, int a, int b, ll x) {
    // Implement _update_max function as needed
}

void update_min(SegmentTree *seg, int a, int b, ll x) {
    // Implement _update_min function as needed
}

void add_val(SegmentTree *seg, int a, int b, ll x) {
    // Implement _add_val function as needed
}

ll query_sum(SegmentTree *seg, int a, int b) {
    // Implement _query_sum function as needed
    return 0; // Placeholder
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    ll v[n];
    for (int i = 0; i < n; i++) {
        v[i] = i - 1;
    }
    SegmentTree seg;
    init_segment_tree(&seg, n, v);

    ll d[200001][n]; // Assuming max n for simplicity
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                d[j][0] = i; // Store index
                if (a[i] != j * j) d[a[i] / j][0] = i; // Store index
            }
        }
    }

    ll ans = 0;
    for (int i = 200000; i >= 1; i--) {
        // Process d[i] as needed
        // Implement logic similar to the original C++ code
    }
    printf("%lld\n", ans);
    return 0;
}
