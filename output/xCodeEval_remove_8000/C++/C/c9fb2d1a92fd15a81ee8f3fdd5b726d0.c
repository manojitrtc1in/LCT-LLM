#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100000
#define MAX_K 12

typedef long long ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    ll sums[MAX_N];
    int arrs[MAX_N][MAX_K];
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            t = k;
        }
        sums[i] = 0;
        for (int j = 0; j < t; j++) {
            sums[i] += arrs[i][j];
        }
    }

    ll dps[13][MAX_K + 1];
    memset(dps, 0, sizeof(dps));

    for (int i = 0; i < n; i++) {
        ll ans = 0;
        const int *carr = arrs[i];
        const ll *dp = dps[i];
        if (i + 1 == n) {
            ans = dp[k];
            ll sum = 0;
            for (int j = 0; j < k && j < t; j++) {
                sum += carr[j];
                ans = max(ans, dp[k - j - 1] + sum);
            }
        } else {
            int m = (i + n) / 2;
            memcpy(dps[i + 1], dps[i], sizeof(dps[i]));
            for (int j = i; j < m; j++) {
                ll v = sums[j];
                int k1 = t;
                for (int l = k; l >= k1; l--) {
                    dps[i + 1][l] = max(dps[i + 1][l], dps[i + 1][l - k1] + v);
                }
            }
            ans = max(ans, rec(m, n, i + 1));
            memcpy(dps[i + 1], dps[i], sizeof(dps[i]));
            for (int j = m; j < n; j++) {
                ll v = sums[j];
                int k1 = t;
                for (int l = k; l >= k1; l--) {
                    dps[i + 1][l] = max(dps[i + 1][l], dps[i + 1][l - k1] + v);
                }
            }
            ans = max(ans, rec(i, m, i + 1));
        }
        printf("%lld\n", ans);
    }
}

int main() {
    solve();
    return 0;
}
