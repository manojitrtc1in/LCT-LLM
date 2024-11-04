#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100005
#define MAX_K 13

typedef long long int ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

ll sum(int arr[], int size) {
    ll s = 0;
    for (int i = 0; i < size; i++) {
        s += arr[i];
    }
    return s;
}

ll dp[MAX_K][MAX_N];

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arrs[MAX_N][MAX_K];
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
    }

    ll sums[MAX_N];
    for (int i = 0; i < n; i++) {
        sums[i] = sum(arrs[i], k);
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        ll v = sums[i];
        int k1 = k;
        for (int j = k; j >= k1; j--) {
            dp[0][j] = max(dp[0][j], dp[0][j - k1] + v);
        }
    }

    for (int dpi = 0; dpi < k; dpi++) {
        memcpy(dp[dpi + 1], dp[dpi], sizeof(dp[0][0]) * (k + 1));
        for (int i = 0; i < n; i++) {
            ll v = sums[i];
            int k1 = arrs[i][0];
            for (int j = k; j >= k1; j--) {
                dp[dpi][j] = max(dp[dpi][j], dp[dpi][j - k1] + v);
            }
        }
    }

    printf("%lld\n", dp[k][k]);
}

int main() {
    solve();
    return 0;
}
