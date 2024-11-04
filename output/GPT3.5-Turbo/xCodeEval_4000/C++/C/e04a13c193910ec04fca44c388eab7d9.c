#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long int ll;

ll sum(const int *arr, int size) {
    ll res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i];
    }
    return res;
}

void copy_dp(ll *dp1, ll *dp2, int size) {
    memcpy(dp2, dp1, sizeof(ll) * (size + 1));
}

void add_to_knapsack(int *arr, int size, ll *dp, int k) {
    ll v = sum(arr, size);
    for (int i = k; i >= size; i--) {
        dp[i] = max(dp[i], dp[i - size] + v);
    }
}

ll recursive(int l, int r, int **arrs, ll **dps, int k) {
    ll ans = 0;
    if (l + 1 == r) {
        ans = dps[l][k];
        ll sum = 0;
        for (int i = 0; i < k && i < r; i++) {
            sum += arrs[l][i];
            ans = max(ans, dps[l][k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        copy_dp(dps[l], dps[l + 1], k);
        for (int i = l; i < m; i++) {
            add_to_knapsack(arrs[i], i - l + 1, dps[l + 1], k);
        }
        ans = recursive(m, r, arrs, dps, k);
        copy_dp(dps[m], dps[l + 1], k);
        for (int i = m; i < r; i++) {
            add_to_knapsack(arrs[i], i - m + 1, dps[l + 1], k);
        }
        ans = max(ans, recursive(l, m, arrs, dps, k));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
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
    }
    ll **dps = (ll **)malloc((n + 1) * sizeof(ll *));
    for (int i = 0; i <= n; i++) {
        dps[i] = (ll *)malloc((k + 1) * sizeof(ll));
    }
    for (int i = 0; i <= k; i++) {
        dps[0][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int size = i + 1;
        ll v = sum(arrs[i], size);
        for (int j = size; j <= k; j++) {
            dps[i + 1][j] = dps[i][j - size] + v;
        }
    }
    ll ans = recursive(0, n, arrs, dps, k);
    printf("%lld\n", ans);
    for (int i = 0; i < n; i++) {
        free(arrs[i]);
    }
    free(arrs);
    for (int i = 0; i <= n; i++) {
        free(dps[i]);
    }
    free(dps);
}

int main() {
    solve();
    return 0;
}
