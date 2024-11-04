#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3000

int n, k, m[N], a[N][N];
long long ans, sum[N];

void insert(long long *dp, int a, long long b) {
    for (int i = k; i >= a; i--) {
        if (dp[i] < dp[i - a] + b) {
            dp[i] = dp[i - a] + b;
        }
    }
}

void DFS(int l, int r, long long *f) {
    if (l == r) {
        ans = ans > f[k] ? ans : f[k];
        long long s = 0;
        for (int i = 1; i <= m[l] && i <= k; i++) {
            s += a[l][i];
            ans = ans > (s + f[k - i]) ? ans : (s + f[k - i]);
        }
        return;
    }
    long long g[N] = {0};
    int mid = (l + r) >> 1;
    memcpy(g, f, sizeof(long long) * (k + 1));
    for (int i = mid + 1; i <= r; i++) {
        insert(g, m[i], sum[i]);
    }
    DFS(l, mid, g);
    memcpy(g, f, sizeof(long long) * (k + 1));
    for (int i = l; i <= mid; i++) {
        insert(g, m[i], sum[i]);
    }
    DFS(mid + 1, r, g);
}

int main() {
    freopen("1.in", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m[i]);
        for (int j = 1; j <= m[i]; j++) {
            scanf("%d", &a[i][j]);
            sum[i] += a[i][j];
        }
    }
    long long f[N] = {0};
    DFS(1, n, f);
    printf("%lld\n", ans);
    return 0;
}
