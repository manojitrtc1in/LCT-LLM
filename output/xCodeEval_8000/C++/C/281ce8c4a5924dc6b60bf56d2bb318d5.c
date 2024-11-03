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
    int sizes[MAX_N];
    ll sums[MAX_N];

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        sizes[i] = t;
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            sizes[i] = k;
        }
        sums[i] = sum(arrs[i], sizes[i]);
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= sizes[i]; j--) {
            dp[j][i + 1] = max(dp[j][i + 1], dp[j - sizes[i]][i] + sums[i]);
        }
        for (int j = 0; j <= k; j++) {
            dp[j][i + 1] = max(dp[j][i + 1], dp[j][i]);
        }
    }

    printf("%lld\n", dp[k][n]);
}

int main() {
    solve();
    return 0;
}
