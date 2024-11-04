#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>

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

void add_to_knap(Vector *dp, int k, ll v, int k1) {
    for (int j = k; j >= k1; j--) {
        if (dp[j] < dp[j - k1] + v) {
            dp[j] = dp[j - k1] + v;
        }
    }
}

ll rec(Vector *arrs, Vector *sums, int l, int r, int k, Vector *dp) {
    ll ans = 0;
    if (l + 1 == r) {
        ans = dp->data[k];
        ll sum = 0;
        for (int i = 0; i < arrs[l].size && i < k; i++) {
            sum += arrs[l].data[i];
            if (k - i - 1 >= 0 && dp->data[k - i - 1] + sum > ans) {
                ans = dp->data[k - i - 1] + sum;
            }
        }
    } else {
        int m = (l + r) / 2;
        Vector dp_copy;
        vector_init(&dp_copy);
        dp_copy.data = malloc((k + 1) * sizeof(ll));
        memcpy(dp_copy.data, dp->data, (k + 1) * sizeof(ll));
        
        for (int i = l; i < m; i++) {
            add_to_knap(dp_copy.data, k, sums->data[i], arrs[i].size);
        }
        ans = rec(arrs, sums, m, r, k, &dp_copy);
        
        memcpy(dp_copy.data, dp->data, (k + 1) * sizeof(ll));
        for (int i = m; i < r; i++) {
            add_to_knap(dp_copy.data, k, sums->data[i], arrs[i].size);
        }
        ll temp = rec(arrs, sums, l, m, k, &dp_copy);
        if (temp > ans) {
            ans = temp;
        }
        free(dp_copy.data);
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    Vector sums, arrs[n];
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
        if (arrs[i].size > k) {
            arrs[i].size = k;
        }
        ll total = sum(&arrs[i]);
        vector_push_back(&sums, total);
    }
    
    Vector dp;
    vector_init(&dp);
    for (int i = 0; i <= k; i++) {
        vector_push_back(&dp, 0);
    }
    
    printf("%lld\n", rec(arrs, &sums, 0, n, k, &dp));
    
    for (int i = 0; i < n; i++) {
        vector_free(&arrs[i]);
    }
    vector_free(&sums);
    vector_free(&dp);
}

int main() {
    solve();
    return 0;
}
