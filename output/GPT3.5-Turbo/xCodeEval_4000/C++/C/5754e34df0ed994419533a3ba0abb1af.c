#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 100005
#define MAXK 1005

typedef long long ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

ll sum(int arr[], int size) {
    ll res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i];
    }
    return res;
}

ll dp[13][MAXK];

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arrs[MAXN][MAXK];
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
    }

    ll sums[MAXN];
    for (int i = 0; i < n; i++) {
        sums[i] = sum(arrs[i], k);
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        dp[0][k] = max(dp[0][k], dp[0][k - arrs[i][0]] + sums[i]);
    }

    for (int dpi = 0; dpi < 12; dpi++) {
        memcpy(dp[dpi + 1], dp[dpi], sizeof(dp[0]));
        for (int i = 0; i < n; i++) {
            ll v = sums[i];
            int k1 = arrs[i][0];
            for (int j = k; j >= k1; j--) {
                dp[dpi][j] = max(dp[dpi][j], dp[dpi][j - k1] + v);
            }
        }
    }

    printf("%lld\n", dp[12][k]);
}

int main() {
    solve();
    return 0;
}
