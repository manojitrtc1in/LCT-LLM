#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long int ll;

ll sum(int *arr, int size) {
    ll s = 0;
    for (int i = 0; i < size; i++) {
        s += arr[i];
    }
    return s;
}

void copy_dp(ll **dps, int k, int dpi) {
    memcpy(dps[dpi + 1], dps[dpi], sizeof(ll) * (k + 1));
}

void add_to_knap(int *arr, int size, ll *sums, ll **dps, int k, int dpi) {
    ll v = sums[size];
    int k1 = size;
    for (int j = k; j >= k1; j--) {
        dps[dpi][j] = max(dps[dpi][j], dps[dpi][j - k1] + v);
    }
}

ll rec(int l, int r, ll **dps, ll *sums, int **arrs, int k, int dpi) {
    ll ans = 0;
    int *carr = arrs[l];
    ll *dp = dps[dpi];
    if (l + 1 == r) {
        ans = max(ans, dp[k]);
        ll sum = 0;
        for (int i = 0; i < min(k, (int)carr[0]); i++) {
            sum += carr[i];
            ans = max(ans, dp[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        copy_dp(dps, k, dpi);
        for (int i = l; i < m; i++) {
            add_to_knap(arrs[i], i, sums, dps, k, dpi + 1);
        }
        ans = max(ans, rec(m, r, dps, sums, arrs, k, dpi + 1));
        copy_dp(dps, k, dpi);
        for (int i = m; i < r; i++) {
            add_to_knap(arrs[i], i, sums, dps, k, dpi + 1);
        }
        ans = max(ans, rec(l, m, dps, sums, arrs, k, dpi + 1));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll *sums = (ll *)malloc(n * sizeof(ll));
    int **arrs = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = (int *)malloc(t * sizeof(int));
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            arrs[i] = realloc(arrs[i], k * sizeof(int));
        }
        sums[i] = sum(arrs[i], t);
    }
    ll **dps = (ll **)malloc(13 * sizeof(ll *));
    for (int i = 0; i < 13; i++) {
        dps[i] = (ll *)malloc((k + 1) * sizeof(ll));
    }
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j <= k; j++) {
            dps[i][j] = 0;
        }
    }
    printf("%lld\n", rec(0, n, dps, sums, arrs, k, 0));
    for (int i = 0; i < n; i++) {
        free(arrs[i]);
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
