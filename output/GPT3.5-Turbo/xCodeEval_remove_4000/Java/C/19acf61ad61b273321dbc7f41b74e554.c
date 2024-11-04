#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000001

int dp[MAXN];

int max(int a, int b) {
    return (a > b) ? a : b;
}

void solve() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n, k, d;
        scanf("%d %d %d", &n, &k, &d);
        int a[n];
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[j]);
        }

        int g = 0;
        for (int j = 0; j < d; ++j) {
            if (dp[a[j]]++ == 0) {
                g++;
            }
        }
        int all = g;
        for (int j = d; j < n; ++j) {
            if (--dp[a[j - d]] == 0) {
                g--;
            }
            if (dp[a[j]]++ == 0) {
                g++;
            }
            all = max(all, g);
        }
        printf("%d\n", all);
        for (int j = 0; j < d; ++j) {
            dp[a[n - j - 1]]--;
        }
    }
}

int main() {
    solve();
    return 0;
}
