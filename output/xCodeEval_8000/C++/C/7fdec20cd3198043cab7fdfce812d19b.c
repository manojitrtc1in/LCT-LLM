#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long int ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

ll sum(ll arr[], int n) {
    ll s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i];
    }
    return s;
}

ll rec(int l, int r, int k, ll dps[][13], ll sums[], int arrs[][13]) {
    ll ans = 0;
    if (l + 1 == r) {
        ans = dps[k][k];
        ll sum = 0;
        for (int i = 0; i < k && i < r - l; i++) {
            sum += arrs[l][i];
            ans = max(ans, dps[k - i - 1][k] + sum);
        }
    } else {
        int m = (l + r) / 2;
        for (int i = l; i < m; i++) {
            for (int j = k; j >= 0; j--) {
                dps[i + 1][j] = dps[i][j];
                if (j >= r - i) {
                    dps[i + 1][j] = max(dps[i + 1][j], dps[i][j - (r - i)] + sums[i]);
                }
            }
        }
        ans = rec(m, r, k, dps, sums, arrs);
        for (int i = m; i < r; i++) {
            for (int j = k; j >= 0; j--) {
                dps[i + 1][j] = dps[i][j];
                if (j >= r - i) {
                    dps[i + 1][j] = max(dps[i + 1][j], dps[i][j - (r - i)] + sums[i]);
                }
            }
        }
        ans = max(ans, rec(l, m, k, dps, sums, arrs));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll sums[n];
    int arrs[n][13];
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
    ll dps[13][13] = {0};
    printf("%lld\n", rec(0, n, k, dps, sums, arrs));
}

int main() {
    solve();
    return 0;
}
