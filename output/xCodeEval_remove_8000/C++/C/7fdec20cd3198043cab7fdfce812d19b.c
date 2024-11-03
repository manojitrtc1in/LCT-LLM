#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100
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

    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r <= n; r++) {
            memset(dps[r], 0, sizeof(dps[r]));
            if (l + 1 == r) {
                for (int i = 0; i <= k; i++) {
                    dps[r][i] = dps[l][i];
                }
                ll sum = 0;
                for (int i = 0; i < k && i < r - l; i++) {
                    sum += arrs[l][i];
                    dps[r][k - i - 1] = max(dps[r][k - i - 1], dps[l][k - i - 1] + sum);
                }
            } else {
                int m = (l + r) / 2;
                for (int i = l; i < m; i++) {
                    for (int j = k; j >= 0; j--) {
                        ll v = sums[i];
                        int k1 = r - l;
                        if (j >= k1) {
                            dps[r][j] = max(dps[r][j], dps[l][j - k1] + v);
                        }
                    }
                }
                for (int i = m; i < r; i++) {
                    for (int j = k; j >= 0; j--) {
                        ll v = sums[i];
                        int k1 = r - l;
                        if (j >= k1) {
                            dps[r][j] = max(dps[r][j], dps[l][j - k1] + v);
                        }
                    }
                }
            }
        }
    }

    printf("%lld\n", dps[n][k]);
}

int main() {
    solve();
    return 0;
}
