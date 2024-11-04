#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

int a[1010101];

int solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i + 1]);
    }
    a[0] = -INF;
    a[n + 1] = INF + INF;
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        int s = a[i];
        for (int j = 2; j <= 50 && i + j - 1 <= n; ++j) {
            s ^= a[i + j - 1];
            int z = 0;
            for (int r = 0; r < 50 && i + j + r <= n + 1; ++r) {
                z ^= a[i + j + r];
                if (a[i - 1] > s || s > z) {
                    ans = (ans < j + r) ? ans : (j + r);
                    break;
                }
            }
        }
    }
    if (ans == INF) {
        ans = 0;
    }
    printf("%d\n", ans - 1);
    return 0;
}

int main() {
    return solve();
}
