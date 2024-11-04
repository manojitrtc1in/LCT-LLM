#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_K 100

long long sum(long long *arr, int size) {
    long long total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

void smax(long long *a, long long b) {
    if (b > *a) {
        *a = b;
    }
}

void do_copy(long long dps[][MAX_K + 1], int dpi, int k) {
    memcpy(dps[dpi + 1], dps[dpi], sizeof(dps[0][0]) * (k + 1));
}

void add_to_knap(long long *dps, long long *sums, int i, int dpi, int k, int k1) {
    long long v = sums[i];
    for (int j = k; j >= k1; j--) {
        smax(&dps[j], dps[j - k1] + v);
    }
}

long long rec(long long dps[][MAX_K + 1], long long *sums, int **arrs, int l, int r, int dpi, int k) {
    long long ans = 0;
    int *carr = arrs[l];
    long long *dp = dps[dpi];

    if (l + 1 == r) {
        smax(&ans, dp[k]);
        long long sum = 0;
        for (int i = 0; i < k && i < (int)(sizeof(carr) / sizeof(carr[0])); i++) {
            sum += carr[i];
            smax(&ans, dp[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dps, dpi, k);
        for (int i = l; i < m; i++) {
            add_to_knap(dps[dpi + 1], sums, i, dpi, k, (int)(sizeof(arrs[i]) / sizeof(arrs[i][0])));
        }
        smax(&ans, rec(dps, sums, arrs, m, r, dpi + 1, k));
        do_copy(dps, dpi, k);
        for (int i = m; i < r; i++) {
            add_to_knap(dps[dpi + 1], sums, i, dpi, k, (int)(sizeof(arrs[i]) / sizeof(arrs[i][0])));
        }
        smax(&ans, rec(dps, sums, arrs, l, m, dpi + 1, k));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    long long sums[MAX_N];
    int *arrs[MAX_N];
    long long dps[13][MAX_K + 1] = {0};

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = (int *)malloc(t * sizeof(int));
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            t = k;
        }
        sums[i] = sum(arrs[i], t);
    }

    printf("%lld\n", rec(dps, sums, arrs, 0, n, 0, k));

    for (int i = 0; i < n; i++) {
        free(arrs[i]);
    }
}

int main() {
    solve();
    return 0;
}
