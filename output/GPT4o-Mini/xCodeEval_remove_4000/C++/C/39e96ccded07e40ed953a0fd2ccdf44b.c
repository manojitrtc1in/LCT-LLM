#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_N 500005
#define MAX_K 100

long long sums[MAX_N];
long long dps[13][MAX_K + 1];
long long arrs[MAX_N][MAX_K];
int arr_sizes[MAX_N];

void read_int(int *x) {
    scanf("%d", x);
}

void read_long_long(long long *x) {
    scanf("%lld", x);
}

void read_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

long long sum(int arr[], int size) {
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
        long long sum = 0;
        for (int i = 0; i < arr_sizes[l] && i < k; i++) {
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
    read_int(&n);
    read_int(&k);

    for (int i = 0; i < n; i++) {
        int t;
        read_int(&t);
        arr_sizes[i] = t;
        for (int j = 0; j < t; j++) {
            read_int(&arrs[i][j]);
        }
        if (t > k) {
            arr_sizes[i] = k;
        }
        sums[i] = sum(arrs[i], arr_sizes[i]);
    }

    memset(dps, 0, sizeof(dps));
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j <= k; j++) {
            dps[i][j] = 0;
        }
    }

    long long result = rec(0, n, 0, k);
    printf("%lld\n", result);
}

int main() {
    solve();
    return 0;
}