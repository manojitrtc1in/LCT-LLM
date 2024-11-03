#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long int ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

ll sum(ll* arr, int size) {
    ll res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i];
    }
    return res;
}

ll rec(int l, int r, int k, ll** dps, ll* sums, int** arrs) {
    ll ans = 0;
    int dpi = 0;
    ll* dp = dps[dpi];
    if (l + 1 == r) {
        ans = dp[k];
        ll sum = 0;
        for (int i = 0; i < min(k, (int)strlen(arrs[l])); i++) {
            sum += arrs[l][i];
            ans = max(ans, dp[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        dpi++;
        memcpy(dps[dpi], dp, sizeof(ll) * (k + 1));
        for (int i = l; i < m; i++) {
            ll v = sums[i];
            int k1 = strlen(arrs[i]);
            for (int j = k; j >= k1; j--) {
                dp[j] = max(dp[j], dp[j - k1] + v);
            }
        }
        ans = max(ans, rec(m, r, k, dps, sums, arrs));
        dpi++;
        memcpy(dps[dpi], dp, sizeof(ll) * (k + 1));
        for (int i = m; i < r; i++) {
            ll v = sums[i];
            int k1 = strlen(arrs[i]);
            for (int j = k; j >= k1; j--) {
                dp[j] = max(dp[j], dp[j - k1] + v);
            }
        }
        ans = max(ans, rec(l, m, k, dps, sums, arrs));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll* sums = (ll*)malloc(n * sizeof(ll));
    int** arrs = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = (int*)malloc(t * sizeof(int));
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            arrs[i] = (int*)realloc(arrs[i], k * sizeof(int));
        }
        sums[i] = sum(arrs[i], t);
    }
    ll** dps = (ll**)malloc(13 * sizeof(ll*));
    for (int i = 0; i < 13; i++) {
        dps[i] = (ll*)malloc((k + 1) * sizeof(ll));
        memset(dps[i], 0, (k + 1) * sizeof(ll));
    }
    printf("%lld\n", rec(0, n, k, dps, sums, arrs));
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
