#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;

ll sum(const int *arr, int size) {
    ll res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i];
    }
    return res;
}

void do_copy(ll *dst, const ll *src, int size) {
    memcpy(dst, src, sizeof(ll) * size);
}

void add_to_knap(int *arrs, int arrs_size, ll *dps, int k, int i, int dpi) {
    ll v = sum(arrs, arrs_size);
    int k1 = arrs_size;
    for (int j = k; j >= k1; j--) {
        dps[dpi * (k + 1) + j] = max(dps[dpi * (k + 1) + j], dps[dpi * (k + 1) + j - k1] + v);
    }
}

ll rec(int l, int r, int dpi, int k, ll *dps, int **arrs, ll *sums) {
    ll ans = 0;
    const int *carr = arrs[l];
    const ll *dp = &dps[dpi * (k + 1)];
    if (l + 1 == r) {
        ans = dp[k];
        ll sum = 0;
        for (int i = 0; i < k && i < arrs[l][0]; i++) {
            sum += carr[i];
            ans = max(ans, dp[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        do_copy(&dps[(dpi + 1) * (k + 1)], &dps[dpi * (k + 1)], k + 1);
        for (int i = l; i < m; i++) {
            add_to_knap(arrs[i], arrs[i][0], &dps[(dpi + 1) * (k + 1)], k, i, dpi + 1);
        }
        ans = rec(m, r, dpi + 1, k, dps, arrs, sums);
        do_copy(&dps[(dpi + 1) * (k + 1)], &dps[dpi * (k + 1)], k + 1);
        for (int i = m; i < r; i++) {
            add_to_knap(arrs[i], arrs[i][0], &dps[(dpi + 1) * (k + 1)], k, i, dpi + 1);
        }
        ans = max(ans, rec(l, m, dpi + 1, k, dps, arrs, sums));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    int **arrs = (int **)malloc(n * sizeof(int *));
    ll *sums = (ll *)malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = (int *)malloc(t * sizeof(int));
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            arrs[i] = (int *)realloc(arrs[i], k * sizeof(int));
        }
        sums[i] = sum(arrs[i], t);
    }
    ll *dps = (ll *)malloc(13 * (k + 1) * sizeof(ll));
    memset(dps, 0, 13 * (k + 1) * sizeof(ll));
    printf("%lld\n", rec(0, n, 0, k, dps, arrs, sums));
    free(dps);
    for (int i = 0; i < n; i++) {
        free(arrs[i]);
    }
    free(arrs);
    free(sums);
}

int main() {
    solve();
    return 0;
}
