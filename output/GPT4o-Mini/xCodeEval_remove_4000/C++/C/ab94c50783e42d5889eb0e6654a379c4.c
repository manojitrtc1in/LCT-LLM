#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef long long ll;

ll sum(ll *arr, int size) {
    ll total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

void add_to_knap(ll *dp, ll *sums, int *arr, int k, int i) {
    ll v = sums[i];
    int k1 = arr[i];
    for (int j = k; j >= k1; j--) {
        if (dp[j] < dp[j - k1] + v) {
            dp[j] = dp[j - k1] + v;
        }
    }
}

ll rec(int l, int r, int dpi, ll **dps, ll *sums, int **arrs, int k) {
    ll ans = 0;
    int *carr = arrs[l];
    ll *dp = dps[dpi];

    if (l + 1 == r) {
        ans = dp[k];
        ll sum_val = 0;
        for (int i = 0; i < k && i < arrs[l][0]; i++) {
            sum_val += carr[i];
            if (ans < dp[k - i - 1] + sum_val) {
                ans = dp[k - i - 1] + sum_val;
            }
        }
    } else {
        int m = (l + r) / 2;
        ll do_split(int l1, int r1, int l2, int r2) {
            memcpy(dps[dpi + 1], dps[dpi], sizeof(ll) * (k + 1));
            for (int i = l1; i < r1; i++) {
                add_to_knap(dps[dpi + 1], sums, arrs[i], k, i);
            }
            return rec(l2, r2, dpi + 1, dps, sums, arrs, k);
        }
        ll left_split = do_split(l, m, m, r);
        if (ans < left_split) {
            ans = left_split;
        }
        ll right_split = do_split(m, r, l, m);
        if (ans < right_split) {
            ans = right_split;
        }
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll *sums = malloc(n * sizeof(ll));
    int **arrs = malloc(n * sizeof(int *));
    ll **dps = malloc(13 * sizeof(ll *));
    for (int i = 0; i < 13; i++) {
        dps[i] = malloc((k + 1) * sizeof(ll));
    }

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = malloc((t + 1) * sizeof(int));
        arrs[i][0] = t; // Store the size
        for (int j = 1; j <= t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            arrs[i][0] = k; // Resize to k
        }
        sums[i] = sum(arrs[i] + 1, arrs[i][0]); // Calculate sum
    }

    memset(dps, 0, sizeof(ll) * 13 * (k + 1)); // Initialize dp array
    printf("%lld\n", rec(0, n, 0, dps, sums, arrs, k));

    // Free allocated memory
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
