#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100
#define MAX_K 12

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

ll rec(int l, int r, int k, int dps[][MAX_K+1], ll sums[], int arrs[][MAX_N]) {
    ll ans = 0;
    int carr[MAX_N];
    memcpy(carr, arrs[l], sizeof(int) * MAX_N);
    int dp[MAX_K+1];
    memcpy(dp, dps[k], sizeof(int) * (MAX_K+1));
    if (l+1 == r) {
        ans = max(ans, dp[k]);
        ll sum = 0;
        for (int i = 0; i < k && i < MAX_N; i++) {
            sum += carr[i];
            ans = max(ans, dp[k-i-1] + sum);
        }
    } else {
        int m = (l+r)/2;
        memcpy(dps[k+1], dp, sizeof(int) * (MAX_K+1));
        for (int i = l; i < m; i++) {
            ll v = sums[i];
            int k1 = sizeof(arrs[i]) / sizeof(int);
            for (int j = k; j >= k1; j--) {
                dp[j] = max(dp[j], dp[j-k1] + v);
            }
        }
        ans = max(ans, rec(m, r, k+1, dps, sums, arrs));
        memcpy(dps[k+1], dp, sizeof(int) * (MAX_K+1));
        for (int i = m; i < r; i++) {
            ll v = sums[i];
            int k1 = sizeof(arrs[i]) / sizeof(int);
            for (int j = k; j >= k1; j--) {
                dp[j] = max(dp[j], dp[j-k1] + v);
            }
        }
        ans = max(ans, rec(l, m, k+1, dps, sums, arrs));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll sums[MAX_N];
    int arrs[MAX_N][MAX_N];
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
    int dps[MAX_K+1][MAX_K+1];
    memset(dps, 0, sizeof(int) * (MAX_K+1) * (MAX_K+1));
    printf("%lld\n", rec(0, n, 0, dps, sums, arrs));
}

int main() {
    solve();
    return 0;
}
