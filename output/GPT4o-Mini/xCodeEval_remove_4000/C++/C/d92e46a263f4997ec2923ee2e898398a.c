#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_N 500005
#define MAX_K 1000

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

void read_array(int n, long long arr[]) {
    for (int i = 0; i < n; i++) {
        read_long_long(&arr[i]);
    }
}

long long sum_array(long long arr[], int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

long long max(long long a, long long b) {
    return a > b ? a : b;
}

void do_copy(int dpi, int k) {
    memcpy(dps[dpi + 1], dps[dpi], sizeof(dps[0][0]) * (k + 1));
}

void add_to_knap(int i, int dpi, int k) {
    long long v = sums[i];
    int k1 = arr_sizes[i];
    for (int j = k; j >= k1; j--) {
        dps[dpi][j] = max(dps[dpi][j], dps[dpi][j - k1] + v);
    }
}

long long rec(int l, int r, int dpi, int k) {
    long long ans = 0;
    const long long *carr = arrs[l];
    const long long *dp = dps[dpi];

    if (l + 1 == r) {
        ans = max(ans, dp[k]);
        long long sum = 0;
        for (int i = 0; i < k && i < arr_sizes[l]; i++) {
            sum += carr[i];
            ans = max(ans, dp[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dpi, k);
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1, k);
        }
        ans = max(ans, rec(m, r, dpi + 1, k));
        do_copy(dpi, k);
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1, k);
        }
        ans = max(ans, rec(l, m, dpi + 1, k));
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
        if (t > k) {
            t = k;
        }
        read_array(t, arrs[i]);
        sums[i] = sum_array(arrs[i], arr_sizes[i]);
    }

    memset(dps, 0, sizeof(dps));
    printf("%lld\n", rec(0, n, 0, k));
}

int main() {
    solve();
    return 0;
}
