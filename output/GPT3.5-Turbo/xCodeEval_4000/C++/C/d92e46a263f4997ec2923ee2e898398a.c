#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 1005
#define MAXK 15

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

ll rec(int l, int r, int k, int arrs[][MAXN], ll dps[][MAXK], ll sums[]) {
    ll ans = 0;
    if (l + 1 == r) {
        for (int i = 0; i <= k; i++) {
            ans = max(ans, dps[l][i]);
        }
        ll sum = 0;
        for (int i = 0; i < k && i < r - l; i++) {
            sum += arrs[l][i];
            ans = max(ans, dps[l][k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        for (int i = 0; i <= k; i++) {
            dps[m][i] = dps[l][i];
        }
        for (int i = m; i < r; i++) {
            ll v = sums[i];
            int k1 = (int)strlen(arrs[i]);
            for (int j = k; j >= k1; j--) {
                dps[m][j] = max(dps[m][j], dps[m][j - k1] + v);
            }
        }
        ans = max(ans, rec(m, r, k, arrs, dps, sums));
        for (int i = 0; i <= k; i++) {
            dps[m][i] = dps[r][i];
        }
        for (int i = l; i < m; i++) {
            ll v = sums[i];
            int k1 = (int)strlen(arrs[i]);
            for (int j = k; j >= k1; j--) {
                dps[m][j] = max(dps[m][j], dps[m][j - k1] + v);
            }
        }
        ans = max(ans, rec(l, m, k, arrs, dps, sums));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    int arrs[MAXN][MAXN];
    ll sums[MAXN];
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
    ll dps[MAXK][MAXK];
    memset(dps, 0, sizeof(dps));
    printf("%lld\n", rec(0, n, k, arrs, dps, sums));
}

int main() {
    solve();
    return 0;
}