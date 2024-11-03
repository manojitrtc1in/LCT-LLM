#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long int ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    ll sums[n];
    int arrs[n][k];
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

    ll dps[13][k+1];
    memset(dps, 0, sizeof(dps));

    for (int i = 0; i < n; i++) {
        ll ans = 0;
        int carr[k];
        memcpy(carr, arrs[i], sizeof(carr));

        if (i + 1 == n) {
            for (int j = 0; j <= k; j++) {
                ans = max(ans, dps[0][j]);
            }
            ll sum = 0;
            for (int j = 0; j < k && j < sizeof(carr) / sizeof(carr[0]); j++) {
                sum += carr[j];
                ans = max(ans, dps[0][k-j-1] + sum);
            }
        } else {
            int m = (i + n) / 2;
            memcpy(dps[1], dps[0], sizeof(dps[0]));
            for (int j = i; j < m; j++) {
                ll v = sums[j];
                int k1 = sizeof(arrs[j]) / sizeof(arrs[j][0]);
                for (int l = k; l >= k1; l--) {
                    dps[1][l] = max(dps[1][l], dps[1][l-k1] + v);
                }
            }
            ans = max(ans, rec(m, n, 1));
            memcpy(dps[1], dps[0], sizeof(dps[0]));
            for (int j = m; j < n; j++) {
                ll v = sums[j];
                int k1 = sizeof(arrs[j]) / sizeof(arrs[j][0]);
                for (int l = k; l >= k1; l--) {
                    dps[1][l] = max(dps[1][l], dps[1][l-k1] + v);
                }
            }
            ans = max(ans, rec(i, m, 1));
        }

        printf("%lld\n", ans);
    }
}

int main() {
    solve();
    return 0;
}
