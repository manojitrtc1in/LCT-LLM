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

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            for (int l = 0; l <= j && l <= k; l++) {
                dps[i + 1][j] = max(dps[i + 1][j], dps[i][j - l] + sums[i]);
            }
        }
    }

    printf("%lld\n", dps[n][k]);
}

int main() {
    solve();
    return 0;
}
