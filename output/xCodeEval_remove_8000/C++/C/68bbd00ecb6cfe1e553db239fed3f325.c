#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 100005
#define MAXK 13

typedef long long ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    ll sums[MAXN];
    int arrs[MAXN][MAXK];
    int arrSize[MAXN];

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrSize[i] = t;
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            arrSize[i] = k;
        }
        sums[i] = 0;
        for (int j = 0; j < arrSize[i]; j++) {
            sums[i] += arrs[i][j];
        }
    }

    ll dps[MAXK][MAXK];
    memset(dps, 0, sizeof(dps));

    for (int i = 0; i < n; i++) {
        ll dp[MAXK];
        memcpy(dp, dps[k], sizeof(dp));
        for (int j = k; j >= arrSize[i]; j--) {
            ll sum = 0;
            for (int l = 0; l < arrSize[i]; l++) {
                sum += arrs[i][l];
                dp[j] = max(dp[j], dp[j - l - 1] + sum);
            }
        }
        memcpy(dps[k + 1], dp, sizeof(dp));
    }

    printf("%lld\n", dps[k][k]);
}

int main() {
    solve();
    return 0;
}
