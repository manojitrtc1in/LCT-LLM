#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef long long ll;

ll sum(const ll *arr, int size) {
    ll total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

void add_to_knap(ll *dp, const ll *arr, int k, int k1) {
    ll v = sum(arr, k1);
    for (int j = k; j >= k1; j--) {
        if (dp[j] < dp[j - k1] + v) {
            dp[j] = dp[j - k1] + v;
        }
    }
}

ll rec(int l, int r, int dpi, int k, ll **dps, ll *sums, ll **arrs) {
    ll ans = 0;
    const ll *carr = arrs[l];
    ll *dp = dps[dpi];

    if (l + 1 == r) {
        if (ans < dp[k]) {
            ans = dp[k];
        }
        ll sum_val = 0;
        for (int i = 0; i < k && i < (int)(sizeof(carr) / sizeof(carr[0])); i++) {
            sum_val += carr[i];
            if (ans < dp[k - i - 1] + sum_val) {
                ans = dp[k - i - 1] + sum_val;
            }
        }
    } else {
        int m = (l + r) / 2;
        memcpy(dps[dpi + 1], dp, sizeof(ll) * (k + 1));
        for (int i = l; i < m; i++) {
            add_to_knap(dps[dpi + 1], arrs[i], k, (int)(sizeof(arrs[i]) / sizeof(arrs[i][0])));
        }
        ans = rec(m, r, dpi + 1, k, dps, sums, arrs);
        memcpy(dps[dpi + 1], dp, sizeof(ll) * (k + 1));
        for (int i = m; i < r; i++) {
            add_to_knap(dps[dpi + 1], arrs[i], k, (int)(sizeof(arrs[i]) / sizeof(arrs[i][0])));
        }
        ans = (ans > rec(l, m, dpi + 1, k, dps, sums, arrs)) ? ans : rec(l, m, dpi + 1, k, dps, sums, arrs);
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll *sums = (ll *)malloc(n * sizeof(ll));
    ll **arrs = (ll **)malloc(n * sizeof(ll *));
    ll **dps = (ll **)malloc(13 * sizeof(ll *));
    for (int i = 0; i < 13; i++) {
        dps[i] = (ll *)malloc((k + 1) * sizeof(ll));
    }

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = (ll *)malloc(t * sizeof(ll));
        for (int j = 0; j < t; j++) {
            scanf("%lld", &arrs[i][j]);
        }
        if (t > k) {
            t = k;
        }
        sums[i] = sum(arrs[i], t);
    }

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
