#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_K 1000
#define MAX_DPS 13

long long sums[MAX_N];
long long dps[MAX_DPS][MAX_K + 1];
int arrs[MAX_N][MAX_K];
int arr_sizes[MAX_N];

void add_to_knap(int i, int dpi, int k) {
    long long v = sums[i];
    int k1 = arr_sizes[i];
    for (int j = k; j >= k1; j--) {
        if (dps[dpi][j] < dps[dpi][j - k1] + v) {
            dps[dpi][j] = dps[dpi][j - k1] + v;
        }
    }
}

void do_copy(int dpi, int k) {
    memcpy(&dps[dpi + 1][0], &dps[dpi][0], sizeof(dps[0][0]) * (k + 1));
}

long long rec(int l, int r, int dpi, int k) {
    long long ans = 0;
    const int *carr = arrs[l];
    const long long *dp = dps[dpi];

    if (l + 1 == r) {
        ans = dp[k];
        long long sum = 0;
        for (int i = 0; i < k && i < arr_sizes[l]; i++) {
            sum += carr[i];
            if (ans < dp[k - i - 1] + sum) {
                ans = dp[k - i - 1] + sum;
            }
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dpi, k);
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1, k);
        }
        long long temp = rec(m, r, dpi + 1, k);
        if (ans < temp) {
            ans = temp;
        }
        do_copy(dpi, k);
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1, k);
        }
        temp = rec(l, m, dpi + 1, k);
        if (ans < temp) {
            ans = temp;
        }
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arr_sizes[i] = t;
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            arr_sizes[i] = k;
        }
        sums[i] = 0;
        for (int j = 0; j < arr_sizes[i]; j++) {
            sums[i] += arrs[i][j];
        }
    }

    memset(dps, 0, sizeof(dps));
    for (int i = 0; i < MAX_DPS; i++) {
        for (int j = 0; j <= k; j++) {
            dps[i][j] = 0;
        }
    }

    printf("%lld\n", rec(0, n, 0, k));
}

int main() {
    solve();
    return 0;
}
