#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef long long ll;
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

void vector_init(Vector *v) {
    v->size = 0;
    v->capacity = 4;
    v->data = malloc(v->capacity * sizeof(int));
}

void vector_push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void vector_free(Vector *v) {
    free(v->data);
}

ll sum(Vector *v) {
    ll total = 0;
    for (size_t i = 0; i < v->size; i++) {
        total += v->data[i];
    }
    return total;
}

void do_copy(Vector *src, Vector *dst) {
    memcpy(dst->data, src->data, sizeof(int) * (src->size));
}

void add_to_knap(Vector *arr, ll *sums, int k, int i, Vector *dp) {
    ll v = sums[i];
    int k1 = arr[i].size;
    for (int j = k; j >= k1; j--) {
        if (dp->data[j] < dp->data[j - k1] + v) {
            dp->data[j] = dp->data[j - k1] + v;
        }
    }
}

ll rec(Vector *arrs, ll *sums, int l, int r, int dpi, int k, Vector *dps) {
    ll ans = 0;
    Vector *carr = &arrs[l];
    Vector *dp = &dps[dpi];

    if (l + 1 == r) {
        ans = dp->data[k];
        ll sum = 0;
        for (int i = 0; i < k && i < carr->size; i++) {
            sum += carr->data[i];
            if (dp->data[k - i - 1] + sum > ans) {
                ans = dp->data[k - i - 1] + sum;
            }
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dp, &dps[dpi + 1]);
        for (int i = l; i < m; i++) {
            add_to_knap(arrs, sums, k, i, &dps[dpi + 1]);
        }
        ans = rec(arrs, sums, m, r, dpi + 1, k, dps);
        do_copy(dp, &dps[dpi + 1]);
        for (int i = m; i < r; i++) {
            add_to_knap(arrs, sums, k, i, &dps[dpi + 1]);
        }
        ll temp = rec(arrs, sums, l, m, dpi + 1, k, dps);
        if (temp > ans) {
            ans = temp;
        }
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll *sums = malloc(n * sizeof(ll));
    Vector *arrs = malloc(n * sizeof(Vector));
    Vector *dps = malloc(13 * sizeof(Vector));

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        vector_init(&arrs[i]);
        for (int j = 0; j < t; j++) {
            int value;
            scanf("%d", &value);
            vector_push_back(&arrs[i], value);
        }
        if (t > k) {
            arrs[i].size = k;
        }
        sums[i] = sum(&arrs[i]);
    }

    for (int i = 0; i < 13; i++) {
        vector_init(&dps[i]);
        dps[i].size = k + 1;
        dps[i].data = calloc(k + 1, sizeof(int));
    }

    printf("%lld\n", rec(arrs, sums, 0, n, 0, k, dps));

    for (int i = 0; i < n; i++) {
        vector_free(&arrs[i]);
    }
    free(arrs);
    free(sums);
    for (int i = 0; i < 13; i++) {
        free(dps[i].data);
    }
    free(dps);
}

int main() {
    solve();
    return 0;
}
