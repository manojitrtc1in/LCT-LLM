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

void add_to_knapsack(Vector *dp, Vector *arr, ll *sums, int k, int i) {
    ll v = sums[i];
    int k1 = arr->size;
    for (int j = k; j >= k1; j--) {
        if (dp->data[j - k1] + v > dp->data[j]) {
            dp->data[j] = dp->data[j - k1] + v;
        }
    }
}

ll solve_recursive(Vector *arrs, ll *sums, Vector *dp, int l, int r, int dpi, int k) {
    ll ans = 0;
    Vector *carr = &arrs[l];
    if (l + 1 == r) {
        ans = dp->data[k];
        ll sum = 0;
        for (int i = 0; i < (int)carr->size && i < k; i++) {
            sum += carr->data[i];
            if (dp->data[k - i - 1] + sum > ans) {
                ans = dp->data[k - i - 1] + sum;
            }
        }
    } else {
        int m = (l + r) / 2;
        Vector dp_copy;
        vector_init(&dp_copy, k + 1);
        memcpy(dp_copy.data, dp->data, (k + 1) * sizeof(int));

        for (int i = l; i < m; i++) {
            add_to_knapsack(&dp_copy, &arrs[i], sums, k, i);
        }
        ans = solve_recursive(arrs, sums, &dp_copy, m, r, dpi + 1, k);
        
        memcpy(dp_copy.data, dp->data, (k + 1) * sizeof(int));
        for (int i = m; i < r; i++) {
            add_to_knapsack(&dp_copy, &arrs[i], sums, k, i);
        }
        ll temp = solve_recursive(arrs, sums, &dp_copy, l, m, dpi + 1, k);
        if (temp > ans) {
            ans = temp;
        }
        vector_free(&dp_copy);
    }
    return ans;
}

void DSum_solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    Vector arrs[n];
    ll sums[n];
    
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        vector_init(&arrs[i], t);
        for (int j = 0; j < t; j++) {
            int value;
            scanf("%d", &value);
            vector_push_back(&arrs[i], value);
        }
        sums[i] = sum(&arrs[i]);
        if (t > k) {
            arrs[i].size = k; // Resize to k
        }
    }

    Vector dp;
    vector_init(&dp, k + 1);
    for (int i = 0; i <= k; i++) {
        dp.data[i] = 0;
    }

    ll result = solve_recursive(arrs, sums, &dp, 0, n, 0, k);
    printf("%lld\n", result);

    for (int i = 0; i < n; i++) {
        vector_free(&arrs[i]);
    }
    vector_free(&dp);
}

int main() {
    DSum_solve();
    return 0;
}
