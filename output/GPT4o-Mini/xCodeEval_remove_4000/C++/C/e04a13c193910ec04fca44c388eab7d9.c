#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_K 1000

long long sums[MAX_N];
long long dps[13][MAX_K + 1];
int arrs[MAX_N][MAX_K];
int arr_sizes[MAX_N];

void read_int(int *f) {
    char c;
    bool neg = false;
    *f = 0;
    while ((c = getchar()) != EOF && (c < '0' || c > '9') && c != '-' && c != '+');
    if (c == '-') {
        neg = true;
        c = getchar();
    } else if (c == '+') {
        c = getchar();
    }
    do {
        *f = (*f << 3) + (*f << 1) + (c - '0');
    } while ((c = getchar()) != EOF && c >= '0' && c <= '9');
    if (neg) {
        *f = -(*f);
    }
}

void print_int(long long v) {
    if (v < 0) {
        putchar('-');
        v = -v;
    }
    if (v >= 10) {
        print_int(v / 10);
    }
    putchar('0' + (v % 10));
}

void do_copy(int dpi, int k) {
    memcpy(&dps[dpi + 1], &dps[dpi], sizeof(dps[0][0]) * (k + 1));
}

void add_to_knap(int i, int dpi, int k) {
    long long v = sums[i];
    int k1 = arr_sizes[i];
    for (int j = k; j >= k1; j--) {
        if (dps[dpi][j - k1] + v > dps[dpi][j]) {
            dps[dpi][j] = dps[dpi][j - k1] + v;
        }
    }
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
            if (dp[k - i - 1] + sum > ans) {
                ans = dp[k - i - 1] + sum;
            }
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dpi, k);
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1, k);
        }
        long long rec1 = rec(m, r, dpi + 1, k);
        if (rec1 > ans) {
            ans = rec1;
        }
        do_copy(dpi, k);
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1, k);
        }
        long long rec2 = rec(l, m, dpi + 1, k);
        if (rec2 > ans) {
            ans = rec2;
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
    
    print_int(rec(0, n, 0, k));
    putchar('\n');
}

int main() {
    solve();
    return 0;
}
