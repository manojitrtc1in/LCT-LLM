#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1005
#define MAX_K 1005

typedef long long ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

ll sum(int arr[], int size) {
    ll res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i];
    }
    return res;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arrs[MAX_N][MAX_K];
    int sizes[MAX_N];
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        sizes[i] = t;
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
    }

    ll sums[MAX_N];
    for (int i = 0; i < n; i++) {
        sums[i] = sum(arrs[i], sizes[i]);
    }

    ll dps[13][MAX_K];
    memset(dps, 0, sizeof(dps));

    for (int i = 0; i < n; i++) {
        int k1 = sizes[i];
        for (int j = k; j >= k1; j--) {
            dps[0][j] = max(dps[0][j], dps[0][j - k1] + sums[i]);
        }
    }

    for (int dpi = 0; dpi < 12; dpi++) {
        memcpy(dps[dpi + 1], dps[dpi], sizeof(dps[0]));
        for (int i = 0; i < n; i++) {
            int k1 = sizes[i];
            for (int j = k; j >= k1; j--) {
                dps[dpi + 1][j] = max(dps[dpi + 1][j], dps[dpi][j - k1] + sums[i]);
            }
        }
    }

    printf("%lld\n", dps[12][k]);
}

int main() {
    solve();
    return 0;
}
