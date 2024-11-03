#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long int ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

ll sum(int arr[], int size) {
    ll sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

ll rec(int l, int r, int dpi, int k, ll dps[][13], ll sums[], int arrs[][13]) {
    ll ans = 0;
    int carr[13];
    memcpy(carr, arrs[l], sizeof(int) * 13);
    ll dp[13];
    memcpy(dp, dps[dpi], sizeof(ll) * 13);
    if (l + 1 == r) {
        ans = max(ans, dp[k]);
        ll sum = 0;
        for (int i = 0; i < min(k, (int)sizeof(carr) / sizeof(carr[0])); i++) {
            sum += carr[i];
            ans = max(ans, dp[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        memcpy(dps[dpi + 1], dp, sizeof(ll) * 13);
        for (int i = l; i < m; i++) {
            ll v = sums[i];
            int k1 = sizeof(arrs[i]) / sizeof(arrs[i][0]);
            for (int j = k; j >= k1; j--) {
                dp[j] = max(dp[j], dp[j - k1] + v);
            }
        }
        ans = max(ans, rec(m, r, dpi + 1, k, dps, sums, arrs));
        memcpy(dps[dpi + 1], dp, sizeof(ll) * 13);
        for (int i = m; i < r; i++) {
            ll v = sums[i];
            int k1 = sizeof(arrs[i]) / sizeof(arrs[i][0]);
            for (int j = k; j >= k1; j--) {
                dp[j] = max(dp[j], dp[j - k1] + v);
            }
        }
        ans = max(ans, rec(l, m, dpi + 1, k, dps, sums, arrs));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll sums[n];
    int arrs[n][13];
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            t = k;
        }
        sums[i] = sum(arrs[i], t);
    }
    ll dps[13][13];
    memset(dps, 0, sizeof(ll) * 13 * 13);
    printf("%lld\n", rec(0, n, 0, k, dps, sums, arrs));
}

int main() {
    solve();
    return 0;
}
