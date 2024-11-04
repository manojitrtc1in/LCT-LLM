#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_K 100

long long sums[MAX_N];
long long dps[13][MAX_K + 1];
long long arrs[MAX_N][MAX_K];
int arrs_size[MAX_N];

void add_to_knap(int i, int dpi, int k) {
    long long v = sums[i];
    int k1 = arrs_size[i];
    for (int j = k; j >= k1; j--) {
        if (dps[dpi][j] < dps[dpi][j - k1] + v) {
            dps[dpi][j] = dps[dpi][j - k1] + v;
        }
    }
}

long long rec(int l, int r, int dpi, int k) {
    long long ans = 0;
    const long long* carr = arrs[l];
    const long long* dp = dps[dpi];

    if (l + 1 == r) {
        ans = dp[k];
        long long sum = 0;
        for (int i = 0; i < k && i < arrs_size[l]; i++) {
            sum += carr[i];
            if (ans < dp[k - i - 1] + sum) {
                ans = dp[k - i - 1] + sum;
            }
        }
    } else {
        int m = (l + r) / 2;
        memcpy(&dps[dpi + 1], &dps[dpi], sizeof(dps[0][0]) * (k + 1));
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1, k);
        }
        long long temp = rec(m, r, dpi + 1, k);
        if (ans < temp) {
            ans = temp;
        }
        memcpy(&dps[dpi + 1], &dps[dpi], sizeof(dps[0][0]) * (k + 1));
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
        arrs_size[i] = t;
        for (int j = 0; j < t; j++) {
            scanf("%lld", &arrs[i][j]);
        }
        if (t > k) {
            arrs_size[i] = k;
        }
        sums[i] = 0;
        for (int j = 0; j < arrs_size[i]; j++) {
            sums[i] += arrs[i][j];
        }
    }
    memset(dps, 0, sizeof(dps));
    printf("%lld\n", rec(0, n, 0, k));
}

int main() {
    solve();
    return 0;
}
