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

void add_to_knap(Vector *arrs, ll *sums, int k, int i, int dpi, ll *dps) {
    ll v = sums[i];
    int k1 = arrs[i].size;
    for (int j = k; j >= k1; j--) {
        dps[j] = dps[j] > dps[j - k1] + v ? dps[j] : dps[j - k1] + v;
    }
}

ll rec(Vector *arrs, ll *sums, int l, int r, int dpi, int k, ll *dps) {
    ll ans = 0;
    Vector *carr = &arrs[l];
    if (l + 1 == r) {
        ans = dps[k];
        ll sum = 0;
        for (int i = 0; i < carr->size && i < k; i++) {
            sum += carr->data[i];
            ans = ans > dps[k - i - 1] + sum ? ans : dps[k - i - 1] + sum;
        }
    } else {
        int m = (l + r) / 2;
        ll *temp_dps = malloc((k + 1) * sizeof(ll));
        memcpy(temp_dps, dps, (k + 1) * sizeof(ll));
        for (int i = l; i < m; i++) {
            add_to_knap(arrs, sums, k, i, dpi + 1, temp_dps);
        }
        ans = rec(arrs, sums, m, r, dpi + 1, k, temp_dps);
        memcpy(temp_dps, dps, (k + 1) * sizeof(ll));
        for (int i = m; i < r; i++) {
            add_to_knap(arrs, sums, k, i, dpi + 1, temp_dps);
        }
        ans = ans > rec(arrs, sums, l, m, dpi + 1, k, temp_dps) ? ans : rec(arrs, sums, l, m, dpi + 1, k, temp_dps);
        free(temp_dps);
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
    ll *dps = calloc(13 * (k + 1), sizeof(ll));
    printf("%lld\n", rec(arrs, sums, 0, n, 0, k, dps));
    for (int i = 0; i < n; i++) {
        vector_free(&arrs[i]);
    }
    free(arrs);
    free(sums);
    free(dps);
}

int main() {
    solve();
    return 0;
}
