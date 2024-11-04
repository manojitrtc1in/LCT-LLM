#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

typedef long long ll;
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} vector;

void vector_init(vector *v) {
    v->size = 0;
    v->capacity = 4;
    v->data = (int *)malloc(v->capacity * sizeof(int));
}

void vector_push_back(vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void vector_free(vector *v) {
    free(v->data);
}

ll sum(const vector *v) {
    ll total = 0;
    for (size_t i = 0; i < v->size; i++) {
        total += v->data[i];
    }
    return total;
}

void add_to_knap(int i, int dpi, ll *sums, vector *arrs, ll **dps, int k) {
    ll v = sums[i];
    int k1 = arrs[i].size;
    for (int j = k; j >= k1; j--) {
        if (dps[dpi][j - k1] + v > dps[dpi][j]) {
            dps[dpi][j] = dps[dpi][j - k1] + v;
        }
    }
}

ll rec(int l, int r, int dpi, ll **dps, ll *sums, vector *arrs, int k) {
    ll ans = 0;
    const vector *carr = &arrs[l];
    const ll *dp = dps[dpi];
    if (l + 1 == r) {
        ans = dp[k];
        ll sum = 0;
        for (int i = 0; i < k && i < carr->size; i++) {
            sum += carr->data[i];
            if (dp[k - i - 1] + sum > ans) {
                ans = dp[k - i - 1] + sum;
            }
        }
    } else {
        int m = (l + r) / 2;
        memcpy(dps[dpi + 1], dps[dpi], (k + 1) * sizeof(ll));
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1, sums, arrs, dps, k);
        }
        ans = rec(m, r, dpi + 1, dps, sums, arrs, k);
        memcpy(dps[dpi + 1], dps[dpi], (k + 1) * sizeof(ll));
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1, sums, arrs, dps, k);
        }
        ll temp = rec(l, m, dpi + 1, dps, sums, arrs, k);
        if (temp > ans) {
            ans = temp;
        }
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll *sums = (ll *)malloc(n * sizeof(ll));
    vector *arrs = (vector *)malloc(n * sizeof(vector));
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

    ll **dps = (ll **)malloc(13 * sizeof(ll *));
    for (int i = 0; i < 13; i++) {
        dps[i] = (ll *)calloc(k + 1, sizeof(ll));
    }

    printf("%lld\n", rec(0, n, 0, dps, sums, arrs, k));

    for (int i = 0; i < n; i++) {
        vector_free(&arrs[i]);
    }
    free(arrs);
    free(sums);
    for (int i = 0; i < 13; i++) {
        free(dps[i]);
    }
    free(dps);
}

int main() {
    solve();
    return 0;
}
