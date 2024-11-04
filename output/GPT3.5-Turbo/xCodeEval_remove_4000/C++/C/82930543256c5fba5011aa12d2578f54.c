#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100
#define MAX_K 10

typedef long long int ll;

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

ll rec(int l, int r, int k, int arrs[][MAX_K], ll sums[], ll dps[][MAX_K+1]) {
    ll ans = 0;
    int carr[MAX_K];
    ll dp[MAX_K+1];
    if (l+1 == r) {
        for (int i = 0; i <= k; i++) {
            dp[i] = dps[l][i];
        }
        smax(ans, dp[k]);
        ll sum = 0;
        for (int i = 0; i < min(k, (int)strlen(arrs[l])); i++) {
            carr[i] = arrs[l][i];
            sum += carr[i];
            smax(ans, dp[k-i-1] + sum);
        }
    } else {
        int m = (l+r)/2;
        for (int i = 0; i <= k; i++) {
            dp[i] = dps[l][i];
        }
        for (int i = l; i < m; i++) {
            ll v = sums[i];
            int k1 = strlen(arrs[i]);
            for (int j = k; j >= k1; j--) {
                smax(dp[j], dp[j-k1] + v);
            }
        }
        smax(ans, rec(m, r, k, arrs, sums, dp));
        for (int i = 0; i <= k; i++) {
            dp[i] = dps[l][i];
        }
        for (int i = m; i < r; i++) {
            ll v = sums[i];
            int k1 = strlen(arrs[i]);
            for (int j = k; j >= k1; j--) {
                smax(dp[j], dp[j-k1] + v);
            }
        }
        smax(ans, rec(l, m, k, arrs, sums, dp));
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
    ll dps[MAX_N][MAX_K+1];
    memset(dps, 0, sizeof(dps));
    printf("%lld\n", rec(0, n, k, arrs, sums, dps));
}

int main() {
    solve();
    return 0;
}
