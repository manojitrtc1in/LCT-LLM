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

ll rec(int l, int r, int k, int arrs[MAX_N][MAX_K], ll dps[MAX_K][MAX_K+1], ll sums[MAX_N]) {
    ll ans = 0;
    if (l + 1 == r) {
        ans = dps[k][k];
        ll sum = 0;
        for (int i = 0; i < k && i < r - l; i++) {
            sum += arrs[l][i];
            ans = max(ans, dps[k-i-1][k] + sum);
        }
    } else {
        int m = (l + r) / 2;
        ll dps_copy[MAX_K][MAX_K+1];
        memcpy(dps_copy, dps, sizeof(dps_copy));
        for (int i = l; i < m; i++) {
            for (int j = k; j >= 0; j--) {
                for (int x = 0; x <= j && x < r - l; x++) {
                    ll v = sums[i];
                    int k1 = x + 1;
                    dps_copy[j][k1] = max(dps_copy[j][k1], dps_copy[j-x-1][k] + v);
                }
            }
        }
        ans = rec(m, r, k, arrs, dps_copy, sums);
        memcpy(dps_copy, dps, sizeof(dps_copy));
        for (int i = m; i < r; i++) {
            for (int j = k; j >= 0; j--) {
                for (int x = 0; x <= j && x < r - l; x++) {
                    ll v = sums[i];
                    int k1 = x + 1;
                    dps_copy[j][k1] = max(dps_copy[j][k1], dps_copy[j-x-1][k] + v);
                }
            }
        }
        ans = max(ans, rec(l, m, k, arrs, dps_copy, sums));
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
    ll dps[MAX_K][MAX_K+1];
    memset(dps, 0, sizeof(dps));
    printf("%lld\n", rec(0, n, k, arrs, dps, sums));
}

int main() {
    solve();
    return 0;
}
