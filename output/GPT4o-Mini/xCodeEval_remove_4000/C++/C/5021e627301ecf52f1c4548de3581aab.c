#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

typedef long long ll;
typedef struct {
    int *data;
    size_t size;
} Vector;

void vector_init(Vector *v, size_t size) {
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
}

void vector_free(Vector *v) {
    free(v->data);
}

void vector_push_back(Vector *v, int value) {
    v->data[v->size++] = value;
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
    ll *dp = &dps[dpi * (k + 1)];
    
    if (l + 1 == r) {
        ans = dp[k];
        ll sum = 0;
        for (int i = 0; i < (carr->size < k ? carr->size : k); i++) {
            sum += carr->data[i];
            ans = ans > dp[k - i - 1] + sum ? ans : dp[k - i - 1] + sum;
        }
    } else {
        int m = (l + r) / 2;
        memcpy(&dps[(dpi + 1) * (k + 1)], dp, sizeof(ll) * (k + 1));
        
        for (int i = l; i < m; i++) {
            add_to_knap(arrs, sums, k, i, dpi + 1, dps);
        }
        ans = ans > rec(arrs, sums, m, r, dpi + 1, k, dps) ? ans : rec(arrs, sums, m, r, dpi + 1, k, dps);
        
        memcpy(&dps[(dpi + 1) * (k + 1)], dp, sizeof(ll) * (k + 1));
        
        for (int i = m; i < r; i++) {
            add_to_knap(arrs, sums, k, i, dpi + 1, dps);
        }
        ans = ans > rec(arrs, sums, l, m, dpi + 1, k, dps) ? ans : rec(arrs, sums, l, m, dpi + 1, k, dps);
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    ll *sums = (ll *)malloc(n * sizeof(ll));
    Vector *arrs = (Vector *)malloc(n * sizeof(Vector));
    ll *dps = (ll *)malloc(13 * (k + 1) * sizeof(ll));
    
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        vector_init(&arrs[i], t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i].data[j]);
        }
        if (t > k) {
            arrs[i].size = k;
        }
        sums[i] = sum(&arrs[i]);
    }
    
    memset(dps, 0, sizeof(ll) * (13 * (k + 1)));
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
