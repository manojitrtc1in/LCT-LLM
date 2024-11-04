#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long int ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    ll sums[n];
    int arrs[n][k];
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            t = k;
        }
        sums[i] = 0;
        for (int j = 0; j < t; j++) {
            sums[i] += arrs[i][j];
        }
    }

    ll dps[13][k+1];
    memset(dps, 0, sizeof(dps));

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            ll v = sums[i];
            int k1 = j;
            if (k1 >= t) {
                dps[i+1][j] = max(dps[i+1][j], dps[i][j-t] + v);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, dps[n][i]);
    }

    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}
