#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_K 100

long long sums[MAX_N];
long long dps[13][MAX_K + 1];
int arrs[MAX_N][MAX_K];
int k;

void do_copy(int dpi) {
    memcpy(dps[dpi + 1], dps[dpi], sizeof(dps[0][0]) * (k + 1));
}

void add_to_knap(int i, int dpi) {
    long long v = sums[i];
    int k1 = arrs[i][0]; // Assuming arrs[i][0] holds the size of the array
    for (int j = k; j >= k1; j--) {
        if (dps[dpi][j] < dps[dpi][j - k1] + v) {
            dps[dpi][j] = dps[dpi][j - k1] + v;
        }
    }
}

long long rec(int l, int r, int dpi) {
    long long ans = 0;
    int *carr = arrs[l];
    long long *dp = dps[dpi];

    if (l + 1 == r) {
        if (dp[k] > ans) ans = dp[k];
        long long sum = 0;
        for (int i = 0; i < k && i < carr[0]; i++) {
            sum += carr[i + 1]; // Assuming carr[0] holds the size
            if (dp[k - i - 1] + sum > ans) {
                ans = dp[k - i - 1] + sum;
            }
        }
    } else {
        int m = (l + r) / 2;
        long long do_split(int l1, int r1, int l2, int r2) {
            do_copy(dpi);
            for (int i = l1; i < r1; i++) {
                add_to_knap(i, dpi + 1);
            }
            return rec(l2, r2, dpi + 1);
        }
        long long left = do_split(l, m, m, r);
        if (left > ans) ans = left;
        long long right = do_split(m, r, l, m);
        if (right > ans) ans = right;
    }
    return ans;
}

void solve() {
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i][0] = t; // Store size in arrs[i][0]
        for (int j = 1; j <= t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            arrs[i][0] = k; // Resize to k
        }
        sums[i] = 0;
        for (int j = 1; j <= arrs[i][0]; j++) {
            sums[i] += arrs[i][j];
        }
    }
    memset(dps, 0, sizeof(dps)); // Initialize dps
    printf("%lld\n", rec(0, n, 0));
}

int main() {
    solve();
    return 0;
}
