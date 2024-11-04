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

void add_to_knap(Vector *arr, ll *dp, int k, ll v) {
    int k1 = arr->size;
    for (int j = k; j >= k1; j--) {
        dp[j] = dp[j] > dp[j - k1] + v ? dp[j] : dp[j - k1] + v;
    }
}

ll rec(Vector *arrs, ll *sums, int l, int r, int dpi, int k, ll **dps) {
    ll ans = 0;
    Vector *carr = &arrs[l];
    ll *dp = dps[dpi];

    if (l + 1 == r) {
        ans = dp[k];
        ll sum = 0;
        for (int i = 0; i < carr->size && i < k; i++) {
            sum += carr->data[i];
            ans = ans > dp[k - i - 1] + sum ? ans : dp[k - i - 1] + sum;
        }
    } else {
        int m = (l + r) / 2;
        memcpy(dps[dpi + 1], dp, (k + 1) * sizeof(ll));
        for (int i = l; i < m; i++) {
            add_to_knap(&arrs[i], dp, k, sums[i]);
        }
        ans = rec(arrs, sums, m, r, dpi + 1, k, dps);
        memcpy(dps[dpi + 1], dp, (k + 1) * sizeof(ll));
        for (int i = m; i < r; i++) {
            add_to_knap(&arrs[i], dp, k, sums[i]);
        }
        ans = ans > rec(arrs, sums, l, m, dpi + 1, k, dps) ? ans : rec(arrs, sums, l, m, dpi + 1, k, dps);
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    Vector *arrs = (Vector *)malloc(n * sizeof(Vector));
    ll *sums = (ll *)malloc(n * sizeof(ll));
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
        sums[i] = sum(&arrs[i]);
    }

    ll **dps = (ll **)malloc(13 * sizeof(ll *));
    for (int i = 0; i < 13; i++) {
        dps[i] = (ll *)calloc(k + 1, sizeof(ll));
    }

    printf("%lld\n", rec(arrs, sums, 0, n, 0, k, dps));

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
