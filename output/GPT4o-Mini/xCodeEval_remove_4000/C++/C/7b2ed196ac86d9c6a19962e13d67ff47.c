#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_K 100

long long sums[MAX_N];
long long dps[13][MAX_K + 1];
long long arrs[MAX_N][MAX_K];
int arr_sizes[MAX_N];

long long sum(int *arr, int size) {
    long long total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

void do_copy(int dpi, int k) {
    memcpy(dps[dpi + 1], dps[dpi], sizeof(dps[0][0]) * (k + 1));
}

void add_to_knap(int i, int dpi, int k) {
    long long v = sums[i];
    int k1 = arr_sizes[i];
    for (int j = k; j >= k1; j--) {
        if (dps[dpi][j] < dps[dpi][j - k1] + v) {
            dps[dpi][j] = dps[dpi][j - k1] + v;
        }
    }
}

long long rec(int l, int r, int dpi, int k) {
    long long ans = 0;
    int *carr = arrs[l];
    long long *dp = dps[dpi];

    if (l + 1 == r) {
        ans = dp[k];
        long long sum_val = 0;
        for (int i = 0; i < (k < arr_sizes[l] ? k : arr_sizes[l]); i++) {
            sum_val += carr[i];
            if (dp[k - i - 1] + sum_val > ans) {
                ans = dp[k - i - 1] + sum_val;
            }
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dpi, k);
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1, k);
        }
        long long temp_ans = rec(m, r, dpi + 1, k);
        if (temp_ans > ans) {
            ans = temp_ans;
        }
        do_copy(dpi, k);
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1, k);
        }
        temp_ans = rec(l, m, dpi + 1, k);
        if (temp_ans > ans) {
            ans = temp_ans;
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
            scanf("%lld", &arrs[i][j]);
        }
        if (t > k) {
            arr_sizes[i] = k;
        }
        sums[i] = sum(arrs[i], arr_sizes[i]);
    }
    memset(dps, 0, sizeof(dps));
    printf("%lld\n", rec(0, n, 0, k));
}

int main() {
    solve();
    return 0;
}
