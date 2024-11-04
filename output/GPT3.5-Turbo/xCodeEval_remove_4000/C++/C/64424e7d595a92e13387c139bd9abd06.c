#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100
#define MAX_K 10

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

ll rec(int l, int r, int dpi, int k, ll dps[][MAX_K+1], ll sums[], int arrs[][MAX_K]) {
    ll ans = 0;
    int carr[MAX_K];
    memcpy(carr, arrs[l], sizeof(int) * MAX_K);
    ll dp[MAX_K+1];
    memcpy(dp, dps[dpi], sizeof(ll) * (MAX_K+1));

    if (l+1 == r) {
        ans = dp[k];
        ll sum = 0;
        for (int i = 0; i < k && i < MAX_K; i++) {
            sum += carr[i];
            ans = max(ans, dp[k-i-1] + sum);
        }
    } else {
        int m = (l+r)/2;

        memcpy(dps[dpi+1], dp, sizeof(ll) * (MAX_K+1));
        for (int i = l; i < m-1; i++) {
            ll v = sums[i];
            int k1 = sizeof(arrs[i]) / sizeof(int);
            for (int j = k; j >= k1; j--) {
                dp[j] = max(dp[j], dp[j-k1] + v);
            }
        }
        ans = max(ans, rec(m, r, dpi+1, k, dps, sums, arrs));

        memcpy(dps[dpi+1], dp, sizeof(ll) * (MAX_K+1));
        for (int i = m; i < r-1; i++) {
            ll v = sums[i];
            int k1 = sizeof(arrs[i]) / sizeof(int);
            for (int j = k; j >= k1; j--) {
                dp[j] = max(dp[j], dp[j-k1] + v);
            }
        }
        ans = max(ans, rec(l, m, dpi+1, k, dps, sums, arrs));
    }

    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    ll sums[MAX_N];
    int arrs[MAX_N][MAX_K];

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

    ll dps[13][MAX_K+1];
    memset(dps, 0, sizeof(ll) * 13 * (MAX_K+1));

    printf("%lld\n", rec(0, n, 0, k, dps, sums, arrs));
}

int main() {
    solve();
    return 0;
}
