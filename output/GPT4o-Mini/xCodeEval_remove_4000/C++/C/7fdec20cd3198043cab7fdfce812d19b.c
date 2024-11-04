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
} Vector;

void vector_init(Vector *v) {
    v->size = 0;
    v->capacity = 1;
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

void add_to_knap(int i, int dpi, Vector *arrs, ll *sums, ll **dps, int k) {
    ll v = sums[i];
    int k1 = arrs[i].size;
    for (int j = k; j >= k1; j--) {
        dps[dpi][j] = (dps[dpi][j] > dps[dpi][j - k1] + v) ? dps[dpi][j] : (dps[dpi][j - k1] + v);
    }
}

ll rec(int l, int r, int dpi, Vector *arrs, ll *sums, ll **dps, int k) {
    ll ans = 0;
    Vector *carr = &arrs[l];
    ll *dp = dps[dpi];
    if (l + 1 == r) {
        ans = (ans > dp[k]) ? ans : dp[k];
        ll sum = 0;
        for (int i = 0; i < (k < carr->size ? k : carr->size); i++) {
            sum += carr->data[i];
            ans = (ans > dp[k - i - 1] + sum) ? ans : (dp[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        memcpy(dps[dpi + 1], dps[dpi], (k + 1) * sizeof(ll));
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1, arrs, sums, dps, k);
        }
        ans = (ans > rec(m, r, dpi + 1, arrs, sums, dps, k)) ? ans : rec(m, r, dpi + 1, arrs, sums, dps, k);
        memcpy(dps[dpi + 1], dps[dpi], (k + 1) * sizeof(ll));
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1, arrs, sums, dps, k);
        }
        ans = (ans > rec(l, m, dpi + 1, arrs, sums, dps, k)) ? ans : rec(l, m, dpi + 1, arrs, sums, dps, k);
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll *sums = malloc(n * sizeof(ll));
    Vector *arrs = malloc(n * sizeof(Vector));
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
    ll **dps = malloc(13 * sizeof(ll *));
    for (int i = 0; i < 13; i++) {
        dps[i] = malloc((k + 1) * sizeof(ll));
        memset(dps[i], 0, (k + 1) * sizeof(ll));
    }
    printf("%lld\n", rec(0, n, 0, arrs, sums, dps, k));
    
    for (int i = 0; i < 13; i++) {
        free(dps[i]);
    }
    free(dps);
    for (int i = 0; i < n; i++) {
        vector_free(&arrs[i]);
    }
    free(arrs);
    free(sums);
}

int main() {
    solve();
    return 0;
}
