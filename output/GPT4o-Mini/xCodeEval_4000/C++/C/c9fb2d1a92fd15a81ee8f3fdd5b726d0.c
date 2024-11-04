#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 100
#define MAX_K 100

long long sums[MAX_N];
long long dps[13][MAX_K + 1];
int arrs[MAX_N][MAX_K];
int arr_sizes[MAX_N];

void do_copy(int dpi) {
    memcpy(dps[dpi + 1], dps[dpi], sizeof(dps[0][0]) * (MAX_K + 1));
}

void add_to_knap(int i, int dpi) {
    long long v = sums[i];
    int k1 = arr_sizes[i];
    for (int j = MAX_K; j >= k1; j--) {
        if (dps[dpi][j] < dps[dpi][j - k1] + v) {
            dps[dpi][j] = dps[dpi][j - k1] + v;
        }
    }
}

long long rec(int l, int r, int dpi) {
    long long ans = 0;
    const int *carr = arrs[l];
    const long long *dp = dps[dpi];
    
    if (l + 1 == r) {
        ans = dp[MAX_K];
        long long sum = 0;
        for (int i = 0; i < (k < arr_sizes[l] ? k : arr_sizes[l]); i++) {
            sum += carr[i];
            if (ans < dp[MAX_K - i - 1] + sum) {
                ans = dp[MAX_K - i - 1] + sum;
            }
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dpi);
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1);
        }
        long long temp = rec(m, r, dpi + 1);
        if (ans < temp) {
            ans = temp;
        }
        do_copy(dpi);
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1);
        }
        temp = rec(l, m, dpi + 1);
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
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j <= k; j++) {
            dps[i][j] = 0;
        }
    }
    
    printf("%lld\n", rec(0, n, 0));
}

int main() {
    solve();
    return 0;
}