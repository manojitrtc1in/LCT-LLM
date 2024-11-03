#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100000
#define MAX_K 12

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

ll rec(int l, int r, int k, int arrs[][MAX_K], ll dps[][MAX_K], ll sums[]) {
    ll ans = 0;
    if (l + 1 == r) {
        ans = dps[k];
        ll sum = 0;
        for (int i = 0; i < k && i < r; i++) {
            sum += arrs[l][i];
            ans = max(ans, dps[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        ll dps1[MAX_K];
        memcpy(dps1, dps, sizeof(dps1));
        for (int i = l; i < m; i++) {
            ll v = sums[i];
            int k1 = sizeof(arrs[i]) / sizeof(arrs[i][0]);
            for (int j = k; j >= k1; j--) {
                dps1[j] = max(dps1[j], dps1[j - k1] + v);
            }
        }
        ans = max(ans, rec(m, r, k, arrs, dps1, sums));
        memcpy(dps1, dps, sizeof(dps1));
        for (int i = m; i < r; i++) {
            ll v = sums[i];
            int k1 = sizeof(arrs[i]) / sizeof(arrs[i][0]);
            for (int j = k; j >= k1; j--) {
                dps1[j] = max(dps1[j], dps1[j - k1] + v);
            }
        }
        ans = max(ans, rec(l, m, k, arrs, dps1, sums));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
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
    ll dps[MAX_K];
    memset(dps, 0, sizeof(dps));
    printf("%lld\n", rec(0, n, k, arrs, dps, sums));
}

int main() {
    solve();
    return 0;
}
