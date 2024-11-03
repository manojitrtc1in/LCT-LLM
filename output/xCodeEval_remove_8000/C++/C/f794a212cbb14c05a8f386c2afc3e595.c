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

ll sum(int arr[], int size) {
    ll s = 0;
    for (int i = 0; i < size; i++) {
        s += arr[i];
    }
    return s;
}

ll rec(int l, int r, int k, int arrs[MAX_N][MAX_K], ll dps[MAX_K][MAX_K]) {
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
        ll dps_copy[MAX_K][MAX_K];
        memcpy(dps_copy, dps, sizeof(dps_copy));
        for (int i = l; i < m; i++) {
            ll v = sum(arrs[i], k);
            for (int j = k; j >= 0; j--) {
                for (int x = 0; x <= j; x++) {
                    dps[j][x] = max(dps[j][x], dps_copy[j - x][x] + v);
                }
            }
        }
        ans = rec(m, r, k, arrs, dps);
        memcpy(dps, dps_copy, sizeof(dps_copy));
        for (int i = m; i < r; i++) {
            ll v = sum(arrs[i], k);
            for (int j = k; j >= 0; j--) {
                for (int x = 0; x <= j; x++) {
                    dps[j][x] = max(dps[j][x], dps_copy[j - x][x] + v);
                }
            }
        }
        ans = max(ans, rec(l, m, k, arrs, dps));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arrs[MAX_N][MAX_K];
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
    }
    ll dps[MAX_K][MAX_K] = {0};
    printf("%lld\n", rec(0, n, k, arrs, dps));
}

int main() {
    solve();
    return 0;
}
