#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N (4 * 1000 * 1000 + 13)

int n, mod;
int dp[N];
int pr[N];

int add(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    if (a < 0)
        a += mod;
    return a;
}

long long mul(int a, int b) {
    return a * (long long)b % mod;
}

int read() {
    return scanf("%d%d", &n, &mod) == 2;
}

void solve() {
    memset(dp, 0, sizeof(dp));
    memset(pr, 0, sizeof(pr));
    pr[1] = 1;
    pr[2] = mod - 1;
    
    for (int i = 1; i <= n; ++i) {
        dp[i] = pr[i];
        pr[i + 1] = add(pr[i + 1], dp[i]);
        for (int j = 2; j * i <= n; ++j) {
            pr[j * i] = add(pr[j * i], dp[i]);
            if (j * (i + 1) < N)
                pr[j * (i + 1)] = add(pr[j * (i + 1)], -dp[i]);
        }
        pr[i + 1] = add(pr[i + 1], pr[i]);
    }
    printf("%d\n", dp[n]);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif

    clock_t tt = clock();

    while (read()) {
        solve();
    }

#ifdef _DEBUG
    fprintf(stderr, "TIME = %ld\n", clock() - tt);
#endif

    return 0;
}
