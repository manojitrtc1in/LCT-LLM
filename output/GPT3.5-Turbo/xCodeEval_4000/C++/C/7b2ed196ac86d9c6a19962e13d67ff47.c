#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100
#define MAX_K 100

typedef long long ll;

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

ll rec(int l, int r, int k, int arrs[MAX_N][MAX_K], ll dps[13][MAX_K + 1], ll sums[MAX_N]) {
    ll ans = 0;
    int carr[MAX_K];
    ll dp[MAX_K + 1];
    if (l + 1 == r) {
        for (int i = 0; i < k; i++) {
            dp[i] = dps[0][i];
        }
        dp[k] = dps[0][k];
        ll sum = 0;
        for (int i = 0; i < k && i < r - l; i++) {
            sum += arrs[l][i];
            dp[k - i - 1] += sum;
            ans = max(ans, dp[k - i - 1]);
        }
    } else {
        int m = (l + r) / 2;
        memcpy(dp, dps[k], sizeof(dp));
        for (int i = l; i < m; i++) {
            int k1 = (i - l + 1);
            for (int j = k; j >= k1; j--) {
                dp[j] = max(dp[j], dp[j - k1] + sums[i]);
            }
        }
        ans = max(ans, rec(m, r, k, arrs, dp, sums));
        memcpy(dp, dps[k], sizeof(dp));
        for (int i = m; i < r; i++) {
            int k1 = (i - m + 1);
            for (int j = k; j >= k1; j--) {
                dp[j] = max(dp[j], dp[j - k1] + sums[i]);
            }
        }
        ans = max(ans, rec(l, m, k, arrs, dp, sums));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arrs[MAX_N][MAX_K];
    ll sums[MAX_N];
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
    ll dps[13][MAX_K + 1];
    memset(dps, 0, sizeof(dps));
    printf("%lld\n", rec(0, n, k, arrs, dps, sums));
}

int main() {
    solve();
    return 0;
}