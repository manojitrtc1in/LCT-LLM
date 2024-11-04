#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_N 100
#define MAX_K 100

long long sums[MAX_N];
long long dps[13][MAX_K + 1];
int arrs[MAX_N][MAX_K];
int arr_sizes[MAX_N];

void read_int(int *f) {
    char c;
    bool positive = true;
    while ((c = getchar()) != EOF && (c < '0' || c > '9') && c != '-' && c != '+');
    if (c == '-') {
        positive = false;
        c = getchar();
    } else if (c == '+') {
        c = getchar();
    }
    *f = 0;
    do {
        *f = (*f << 3) + (*f << 1) + (c - '0');
    } while ((c = getchar()) >= '0' && c <= '9');
    if (!positive) *f = -(*f);
}

void read_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        read_int(&arr[i]);
    }
}

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
        if (dp[k] > ans) ans = dp[k];
        long long sum = 0;
        for (int i = 0; i < k && i < arr_sizes[l]; i++) {
            sum += carr[i];
            if (dp[k - i - 1] + sum > ans) ans = dp[k - i - 1] + sum;
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dpi, k);
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1, k);
        }
        long long temp = rec(m, r, dpi + 1, k);
        if (temp > ans) ans = temp;

        do_copy(dpi, k);
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1, k);
        }
        temp = rec(l, m, dpi + 1, k);
        if (temp > ans) ans = temp;
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
        read_array(arrs[i], t);
        if (t > k) arr_sizes[i] = k;
        sums[i] = sum(arrs[i], arr_sizes[i]);
    }
    memset(dps, 0, sizeof(dps));
    printf("%lld\n", rec(0, n, 0, k));
}

int main() {
    solve();
    return 0;
}
