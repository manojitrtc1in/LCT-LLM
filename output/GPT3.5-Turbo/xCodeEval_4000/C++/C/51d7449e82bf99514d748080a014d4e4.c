#include <stdio.h>
#include <stdlib.h>

#define MAX_N 3010

int n, k;
int m[MAX_N];
int a[MAX_N][MAX_N];
long long ans, sum[MAX_N];

void insert(long long *dp, int a, long long b) {
    for (int i = k; i >= a; i--) {
        dp[i] = dp[i] > dp[i - a] + b ? dp[i] : dp[i - a] + b;
    }
}

void DFS(int l, int r, long long *f) {
    if (l == r) {
        ans = ans > f[k] ? ans : f[k];
        long long s = 0;
        for (int i = 1; i <= m[l] && i <= k; i++) {
            s += a[l][i];
            ans = ans > s + f[k - i] ? ans : s + f[k - i];
        }
        return;
    }
    long long g[MAX_N];
    int mid = (l + r) >> 1;
    for (int i = mid + 1; i <= r; i++) {
        for (int j = k; j >= m[i]; j--) {
            g[j] = g[j] > g[j - m[i]] + sum[i] ? g[j] : g[j - m[i]] + sum[i];
        }
    }
    DFS(l, mid, g);
    for (int i = l; i <= mid; i++) {
        for (int j = k; j >= m[i]; j--) {
            g[j] = g[j] > g[j - m[i]] + sum[i] ? g[j] : g[j - m[i]] + sum[i];
        }
    }
    DFS(mid + 1, r, g);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m[i]);
        for (int j = 1; j <= m[i]; j++) {
            scanf("%d", &a[i][j]);
            sum[i] += a[i][j];
        }
    }
    DFS(1, n, (long long *)calloc(k + 1, sizeof(long long)));
    printf("%lld\n", ans);
    return 0;
}
