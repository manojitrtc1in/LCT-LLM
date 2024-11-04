#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef long long ll;
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

void vector_init(Vector *v, size_t capacity) {
    v->data = (int *)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void vector_push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
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

ll rec(int l, int r, int dpi, int k, Vector *sums, Vector *arrs, Vector **dps) {
    ll ans = 0;
    Vector *carr = &arrs[l];
    Vector *dp = &dps[dpi];

    if (l + 1 == r) {
        ans = dp->data[k];
        ll sum = 0;
        for (int i = 0; i < (k < carr->size ? k : carr->size); i++) {
            sum += carr->data[i];
            if (k - i - 1 >= 0) {
                ans = (ans > dp->data[k - i - 1] + sum) ? ans : (dp->data[k - i - 1] + sum);
            }
        }
    } else {
        int m = (l + r) / 2;
        memcpy(dps[dpi + 1].data, dp->data, sizeof(int) * (k + 1));
        for (int i = l; i < m; i++) {
            ll v = sums->data[i];
            int k1 = arrs[i].size;
            for (int j = k; j >= k1; j--) {
                dp->data[j] = (dp->data[j] > dp->data[j - k1] + v) ? dp->data[j] : (dp->data[j - k1] + v);
            }
        }
        ans = rec(m, r, dpi + 1, k, sums, arrs, dps);
        memcpy(dps[dpi + 1].data, dp->data, sizeof(int) * (k + 1));
        for (int i = m; i < r; i++) {
            ll v = sums->data[i];
            int k1 = arrs[i].size;
            for (int j = k; j >= k1; j--) {
                dp->data[j] = (dp->data[j] > dp->data[j - k1] + v) ? dp->data[j] : (dp->data[j - k1] + v);
            }
        }
        ans = (ans > rec(l, m, dpi + 1, k, sums, arrs, dps)) ? ans : rec(l, m, dpi + 1, k, sums, arrs, dps);
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    Vector sums;
    Vector *arrs = (Vector *)malloc(n * sizeof(Vector));
    vector_init(&sums, n);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        vector_init(&arrs[i], t);
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
    
    Vector **dps = (Vector **)malloc(13 * sizeof(Vector *));
    for (int i = 0; i < 13; i++) {
        dps[i] = (Vector *)malloc(sizeof(Vector));
        vector_init(dps[i], k + 1);
    }

    printf("%lld\n", rec(0, n, 0, k, &sums, arrs, dps));

    for (int i = 0; i < n; i++) {
        vector_free(&arrs[i]);
    }
    free(arrs);
    vector_free(&sums);
    for (int i = 0; i < 13; i++) {
        vector_free(dps[i]);
        free(dps[i]);
    }
    free(dps);
}

int main() {
    solve();
    return 0;
}
