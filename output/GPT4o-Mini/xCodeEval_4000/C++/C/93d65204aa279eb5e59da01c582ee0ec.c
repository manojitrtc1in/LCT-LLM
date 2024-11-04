#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 100
#define MAX_K 100

long long sums[MAX_N];
long long dps[13][MAX_K + 1];
int arrs[MAX_N][MAX_K];
int k;

void read_int(int *f) {
    char c;
    int positive = 1;
    while ((c = getchar()) != EOF && (c < '0' || c > '9') && c != '-' && c != '+');
    if (c == '-') {
        positive = 0;
        c = getchar();
    } else if (c == '+') {
        c = getchar();
    }
    *f = 0;
    do {
        *f = (*f << 3) + (*f << 1) + (c - '0');
    } while ((c = getchar()) != EOF && (c >= '0' && c <= '9'));
    if (!positive) *f = -(*f);
}

void do_copy(int dpi) {
    memcpy(&dps[dpi + 1][0], &dps[dpi][0], sizeof(dps[0][0]) * (k + 1));
}

void add_to_knap(int i, int dpi) {
    long long v = sums[i];
    int k1 = arrs[i][0];
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
            sum += carr[i + 1]; // +1 to skip the first element which is the size
            if (dp[k - i - 1] + sum > ans) ans = dp[k - i - 1] + sum;
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dpi);
        for (int i = l; i < m; i++) add_to_knap(i, dpi + 1);
        long long temp = rec(m, r, dpi + 1);
        if (temp > ans) ans = temp;
        do_copy(dpi);
        for (int i = m; i < r; i++) add_to_knap(i, dpi + 1);
        temp = rec(l, m, dpi + 1);
        if (temp > ans) ans = temp;
    }
    return ans;
}

void solve() {
    int n;
    read_int(&n);
    read_int(&k);
    
    for (int i = 0; i < n; i++) {
        int t;
        read_int(&t);
        arrs[i][0] = t; // Store size at the first index
        for (int j = 1; j <= t; j++) {
            read_int(&arrs[i][j]);
        }
        if (t > k) arrs[i][0] = k; // Resize if necessary
        sums[i] = 0;
        for (int j = 1; j <= arrs[i][0]; j++) {
            sums[i] += arrs[i][j];
        }
    }
    
    memset(dps, 0, sizeof(dps));
    printf("%lld\n", rec(0, n, 0));
}

int main() {
    solve();
    return 0;
}
