#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100005
#define MAX_K 13

typedef long long ll;

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
    int arr_sizes[MAX_N];
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arr_sizes[i] = t;
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            arr_sizes[i] = k;
        }
    }

    ll sums[MAX_N];
    for (int i = 0; i < n; i++) {
        sums[i] = sum(arrs[i], arr_sizes[i]);
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        dp[0][k] = max(dp[0][k], dp[0][k - arr_sizes[i]] + sums[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[j][k] = max(dp[j][k], dp[j][k - arr_sizes[i]] + sums[i]);
        }
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            int size = arr_sizes[j];
            ll sum = sums[j];
            for (int l = k; l >= size; l--) {
                dp[i][l] = max(dp[i][l], dp[i - 1][l - size] + sum);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, dp[i][k]);
    }

    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}
