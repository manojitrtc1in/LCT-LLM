#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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

ll sum(const Vector *v) {
    ll total = 0;
    for (size_t i = 0; i < v->size; i++) {
        total += v->data[i];
    }
    return total;
}

void add_to_knap(Vector *dp, const Vector *arr, int k) {
    ll v = sum(arr);
    int k1 = arr->size;
    for (int j = k; j >= k1; j--) {
        if (dp[j] < dp[j - k1] + v) {
            dp[j] = dp[j - k1] + v;
        }
    }
}

ll rec(Vector *dp, Vector *arrs, int l, int r, int k, int dpi) {
    ll ans = 0;
    Vector *carr = &arrs[l];
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
        memcpy(&dp[dpi + 1], &dp[dpi], sizeof(dp[0]) * (k + 1));
        for (int i = l; i < m; i++) {
            add_to_knap(dp, &arrs[i], k);
        }
        ans = rec(dp, arrs, m, r, k, dpi + 1);
        memcpy(&dp[dpi + 1], &dp[dpi], sizeof(dp[0]) * (k + 1));
        for (int i = m; i < r; i++) {
            add_to_knap(dp, &arrs[i], k);
        }
        ll temp = rec(dp, arrs, l, m, k, dpi + 1);
        if (temp > ans) {
            ans = temp;
        }
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    Vector sums[n];
    Vector arrs[n];
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
        sums[i] = (Vector){.data = NULL, .size = 0, .capacity = 0};
        sums[i].size = sum(&arrs[i]);
    }
    Vector dp[13][k + 1];
    for (int i = 0; i < 13; i++) {
        dp[i].data = malloc((k + 1) * sizeof(ll));
        memset(dp[i].data, 0, (k + 1) * sizeof(ll));
    }
    printf("%lld\n", rec(dp[0], arrs, 0, n, k, 0));
    for (int i = 0; i < 13; i++) {
        free(dp[i].data);
    }
}

int main() {
    solve();
    return 0;
}