#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long int ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

ll sum(const int* arr, int size) {
    ll res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i];
    }
    return res;
}

ll solve(int n, int k, int** arrs) {
    ll* sums = (ll*)malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++) {
        sums[i] = sum(arrs[i], arrs[i][0]);
    }

    ll** dps = (ll**)malloc(13 * sizeof(ll*));
    for (int i = 0; i < 13; i++) {
        dps[i] = (ll*)malloc((k + 1) * sizeof(ll));
        memset(dps[i], 0, (k + 1) * sizeof(ll));
    }

    for (int i = 0; i < n; i++) {
        int* carr = arrs[i];
        ll* dp = dps[0];
        if (i + 1 == n) {
            ll ans = dp[k];
            ll sum = 0;
            for (int j = 0; j < min(k, carr[0]); j++) {
                sum += carr[j + 1];
                ans = max(ans, dp[k - j - 1] + sum);
            }
            return ans;
        }
        else {
            for (int j = 0; j < k + 1; j++) {
                dps[1][j] = dp[j];
            }
            ll v = sums[i];
            int k1 = carr[0];
            for (int j = k; j >= k1; j--) {
                dps[1][j] = max(dps[1][j], dps[1][j - k1] + v);
            }
            for (int j = 0; j < k + 1; j++) {
                dp[j] = dps[1][j];
            }
        }
    }

    ll ans = dps[0][k];
    for (int i = 1; i < n; i++) {
        int* carr = arrs[i];
        ll* dp = dps[0];
        ll v = sums[i];
        int k1 = carr[0];
        for (int j = k; j >= k1; j--) {
            dp[j] = max(dp[j], dp[j - k1] + v);
        }
        ans = max(ans, dp[k]);
    }

    for (int i = 0; i < 13; i++) {
        free(dps[i]);
    }
    free(dps);
    free(sums);

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int** arrs = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = (int*)malloc((t + 1) * sizeof(int));
        arrs[i][0] = t;
        for (int j = 1; j <= t; j++) {
            scanf("%d", &arrs[i][j]);
        }
    }

    ll ans = solve(n, k, arrs);
    printf("%lld\n", ans);

    for (int i = 0; i < n; i++) {
        free(arrs[i]);
    }
    free(arrs);

    return 0;
}
