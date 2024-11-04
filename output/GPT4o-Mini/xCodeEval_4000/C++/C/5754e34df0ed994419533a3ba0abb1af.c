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
} vector_int;

typedef struct {
    ll *data;
    size_t size;
    size_t capacity;
} vector_ll;

void vector_int_init(vector_int *v) {
    v->size = 0;
    v->capacity = 1;
    v->data = malloc(v->capacity * sizeof(int));
}

void vector_int_push_back(vector_int *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void vector_ll_init(vector_ll *v) {
    v->size = 0;
    v->capacity = 1;
    v->data = malloc(v->capacity * sizeof(ll));
}

void vector_ll_push_back(vector_ll *v, ll value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(ll));
    }
    v->data[v->size++] = value;
}

ll sum(vector_ll *v) {
    ll total = 0;
    for (size_t i = 0; i < v->size; i++) {
        total += v->data[i];
    }
    return total;
}

ll max(ll a, ll b) {
    return a > b ? a : b;
}

void add_to_knapsack(vector_ll *dp, vector_ll *sums, int i, int k) {
    ll v = sums->data[i];
    int k1 = sums->size;
    for (int j = k; j >= k1; j--) {
        dp->data[j] = max(dp->data[j], dp->data[j - k1] + v);
    }
}

ll solve_recursive(vector_int *arrs, vector_ll *sums, vector_ll *dp, int l, int r, int k, int dpi) {
    ll ans = 0;
    if (l + 1 == r) {
        ans = max(ans, dp->data[k]);
        ll sum = 0;
        for (int i = 0; i < k && i < arrs->data[l]; i++) {
            sum += arrs->data[l];
            ans = max(ans, dp->data[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        ans = max(ans, solve_recursive(arrs, sums, dp, l, m, k, dpi + 1));
        ans = max(ans, solve_recursive(arrs, sums, dp, m, r, k, dpi + 1));
    }
    return ans;
}

void DSum_solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    vector_int arrs;
    vector_int_init(&arrs);
    
    vector_ll sums;
    vector_ll_init(&sums);
    
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        vector_int_push_back(&arrs, t);
        vector_ll_push_back(&sums, sum(&sums));
    }

    vector_ll dp;
    vector_ll_init(&dp);
    for (int i = 0; i <= k; i++) {
        dp.data[i] = 0;
    }

    ll result = solve_recursive(&arrs, &sums, &dp, 0, n, k, 0);
    printf("%lld\n", result);

    free(arrs.data);
    free(sums.data);
    free(dp.data);
}

int main() {
    DSum_solve();
    return 0;
}
