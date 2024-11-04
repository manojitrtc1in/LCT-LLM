#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 1000
#define MAX_K 12

typedef long long ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
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
        sums[i] = 0;
        for (int j = 0; j < t; j++) {
            sums[i] += arrs[i][j];
        }
    }

    ll dps[13][MAX_K + 1];
    memset(dps, 0, sizeof(dps));

    ll ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r <= n; r++) {
            memset(dps[0], 0, sizeof(dps[0]));
            for (int i = l; i < r; i++) {
                ll v = sums[i];
                int k1 = r - i - 1;
                for (int j = k; j >= k1; j--) {
                    dps[0][j] = max(dps[0][j], dps[0][j - k1] + v);
                }
                for (int j = 1; j <= k; j++) {
                    for (int x = k; x >= k1; x--) {
                        dps[j][x] = max(dps[j][x], dps[j - 1][x - k1] + v);
                    }
                }
            }
            ans = max(ans, dps[k][k]);
        }
    }

    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}
