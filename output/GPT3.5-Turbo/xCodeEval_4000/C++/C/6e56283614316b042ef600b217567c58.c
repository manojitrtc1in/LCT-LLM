#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long int ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

ll sum(ll* arr, int size) {
    ll s = 0;
    for (int i = 0; i < size; i++) {
        s += arr[i];
    }
    return s;
}

ll rec(int l, int r, int k, ll** dps, ll* sums, int** arrs) {
    ll ans = 0;
    int dpi = 0;
    ll* dp = dps[dpi];
    if (l + 1 == r) {
        ans = dp[k];
        ll sum = 0;
        for (int i = 0; i < k && i < arrs[l][0]; i++) {
            sum += arrs[l][i];
            ans = max(ans, dp[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        dpi++;
        for (int i = l; i < m; i++) {
            ll v = sums[i];
            int k1 = arrs[i][0];
            for (int j = k; j >= k1; j--) {
                dp[j] = max(dp[j], dp[j - k1] + v);
            }
        }
        ans = rec(m, r, k, dps, sums, arrs);
        dpi++;
        for (int i = m; i < r; i++) {
            ll v = sums[i];
            int k1 = arrs[i][0];
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
    ll* sums = malloc(n * sizeof(ll));
    int** arrs = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = malloc(t * sizeof(int));
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            arrs[i] = realloc(arrs[i], k * sizeof(int));
        }
        sums[i] = sum(arrs[i], t);
    }
    ll** dps = malloc(13 * sizeof(ll*));
    for (int i = 0; i < 13; i++) {
        dps[i] = malloc((k + 1) * sizeof(ll));
        memset(dps[i], 0, (k + 1) * sizeof(ll));
    }
    printf("%lld\n", rec(0, n, k, dps, sums, arrs));
    for (int i = 0; i < n; i++) {
        free(arrs[i]);
    }
    free(arrs);
    for (int i = 0; i < 13; i++) {
        free(dps[i]);
    }
    free(dps);
    free(sums);
}

int main() {
    solve();
    return 0;
}
