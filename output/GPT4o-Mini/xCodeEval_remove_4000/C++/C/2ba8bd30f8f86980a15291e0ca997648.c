#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef long long ll;

ll sum(ll *arr, int size) {
    ll total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

void add_to_knap(ll *dp, ll v, int k, int k1) {
    for (int j = k; j >= k1; j--) {
        dp[j] = dp[j] > dp[j - k1] + v ? dp[j] : dp[j - k1] + v;
    }
}

ll rec(int l, int r, int dpi, int k, ll **dps, ll *sums, ll **arrs) {
    ll ans = 0;
    ll *carr = arrs[l];
    ll *dp = dps[dpi];

    if (l + 1 == r) {
        ans = dp[k];
        ll sum_val = 0;
        for (int i = 0; i < (k < (int)arrs[l][0] ? k : (int)arrs[l][0]); i++) {
            sum_val += carr[i];
            ans = ans > dp[k - i - 1] + sum_val ? ans : dp[k - i - 1] + sum_val;
        }
    } else {
        int m = (l + r) / 2;
        memcpy(dps[dpi + 1], dps[dpi], sizeof(ll) * (k + 1));
        for (int i = l; i < m; i++) {
            add_to_knap(dps[dpi + 1], sums[i], k, (int)arrs[i][0]);
        }
        ans = ans > rec(m, r, dpi + 1, k, dps, sums, arrs) ? ans : rec(m, r, dpi + 1, k, dps, sums, arrs);
        memcpy(dps[dpi + 1], dps[dpi], sizeof(ll) * (k + 1));
        for (int i = m; i < r; i++) {
            add_to_knap(dps[dpi + 1], sums[i], k, (int)arrs[i][0]);
        }
        ans = ans > rec(l, m, dpi + 1, k, dps, sums, arrs) ? ans : rec(l, m, dpi + 1, k, dps, sums, arrs);
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll *sums = malloc(n * sizeof(ll));
    ll **arrs = malloc(n * sizeof(ll *));
    ll **dps = malloc(13 * sizeof(ll *));
    for (int i = 0; i < 13; i++) {
        dps[i] = malloc((k + 1) * sizeof(ll));
    }

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = malloc((t + 1) * sizeof(ll));
        arrs[i][0] = t; // Store size at index 0
        for (int j = 1; j <= t; j++) {
            scanf("%lld", &arrs[i][j]);
        }
        if (t > k) {
            arrs[i][0] = k; // Resize if necessary
        }
        sums[i] = sum(arrs[i] + 1, (int)arrs[i][0]);
    }

    memset(dps, 0, sizeof(ll) * (k + 1)); // Initialize dp array
    printf("%lld\n", rec(0, n, 0, k, dps, sums, arrs));

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
