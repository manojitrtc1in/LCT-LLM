#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define N 200001
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
typedef struct {
    int from, to;
    ll cost;
    int id;
} edge;

typedef struct {
    ll max_v[4 * N], smax_v[4 * N], max_c[4 * N];
    ll min_v[4 * N], smin_v[4 * N], min_c[4 * N];
    ll sum[4 * N];
    ll len[4 * N], ladd[4 * N], lval[4 * N];
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
        // Update function not implemented here, should be added
    }
}

void update_min(SegmentTree *seg, int a, int b, ll x) {
    // Implementation of update_min not shown
}

void update_max(SegmentTree *seg, int a, int b, ll x) {
    // Implementation of update_max not shown
}

void add_val(SegmentTree *seg, int a, int b, ll x) {
    // Implementation of add_val not shown
}

void update_val(SegmentTree *seg, int a, int b, ll x) {
    // Implementation of update_val not shown
}

ll query_max(SegmentTree *seg, int a, int b) {
    // Implementation of query_max not shown
    return 0; // Placeholder
}

ll query_min(SegmentTree *seg, int a, int b) {
    // Implementation of query_min not shown
    return 0; // Placeholder
}

ll query_sum(SegmentTree *seg, int a, int b) {
    // Implementation of query_sum not shown
    return 0; // Placeholder
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    ll v[n];
    for (int i = 0; i < n; i++) {
        v[i] = i - 1;
    }
    SegmentTree seg;
    init_segment_tree(&seg, n, v);

    ll **d = (ll **)malloc(200001 * sizeof(ll *));
    for (int i = 0; i < 200001; i++) {
        d[i] = (ll *)malloc(n * sizeof(ll));
        memset(d[i], 0, n * sizeof(ll)); // Initialize
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                // Add index i to d[j]
                // Implementation of adding index not shown
                if (a[i] != j * j) {
                    // Add index i to d[a[i] / j]
                    // Implementation of adding index not shown
                }
            }
        }
    }

    for (int i = 200000; i >= 1; i--) {
        ll *w = d[i];
        // Check size of w and continue if necessary
        // Implementation not shown

        // Update segment tree and calculate answer
        // Implementation not shown
    }

    printf("%lld\n", ans);
    free(a);
    for (int i = 0; i < 200001; i++) {
        free(d[i]);
    }
    free(d);
    return 0;
}
