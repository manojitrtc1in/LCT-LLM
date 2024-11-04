#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

void add_to_knap(Vector *dp, Vector *arr, int k) {
    ll v = sum(arr);
    int k1 = arr->size;
    for (int j = k; j >= k1; j--) {
        if (dp->data[j] < dp->data[j - k1] + v) {
            dp->data[j] = dp->data[j - k1] + v;
        }
    }
}

ll rec(Vector *arrs, Vector *sums, int l, int r, int dpi, Vector *dps, int k) {
    ll ans = 0;
    Vector *carr = &arrs[l];
    Vector *dp = &dps[dpi];

    if (l + 1 == r) {
        ans = dp->data[k];
        ll sum = 0;
        for (int i = 0; i < (k < carr->size ? k : carr->size); i++) {
            sum += carr->data[i];
            if (ans < dp->data[k - i - 1] + sum) {
                ans = dp->data[k - i - 1] + sum;
            }
        }
    } else {
        int m = (l + r) / 2;
        memcpy(&dps[dpi + 1], &dps[dpi], sizeof(Vector) * (dpi + 1));
        for (int i = l; i < m; i++) {
            add_to_knap(&dps[dpi + 1], &arrs[i], k);
        }
        ans = rec(arrs, sums, m, r, dpi + 1, dps, k);
        memcpy(&dps[dpi + 1], &dps[dpi], sizeof(Vector) * (dpi + 1));
        for (int i = m; i < r; i++) {
            add_to_knap(&dps[dpi + 1], &arrs[i], k);
        }
        if (ans < rec(arrs, sums, l, m, dpi + 1, dps, k)) {
            ans = rec(arrs, sums, l, m, dpi + 1, dps, k);
        }
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    Vector sums;
    Vector *arrs = malloc(n * sizeof(Vector));
    vector_init(&sums);
    
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
        sums.data[i] = sum(&arrs[i]);
    }

    Vector *dps = malloc(13 * sizeof(Vector));
    for (int i = 0; i < 13; i++) {
        vector_init(&dps[i]);
        for (int j = 0; j <= k; j++) {
            dps[i].data[j] = 0;
        }
    }

    printf("%lld\n", rec(arrs, &sums, 0, n, 0, dps, k));

    for (int i = 0; i < n; i++) {
        vector_free(&arrs[i]);
    }
    free(arrs);
    vector_free(&sums);
    for (int i = 0; i < 13; i++) {
        vector_free(&dps[i]);
    }
    free(dps);
}

int main() {
    solve();
    return 0;
}
