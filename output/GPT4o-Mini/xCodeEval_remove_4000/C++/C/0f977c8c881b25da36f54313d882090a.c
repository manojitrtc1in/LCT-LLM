#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef long long li;
typedef long double ld;

const int INF = (int)(1e9);
const li INF64 = (li)(1e18);
const int MOD = (int)(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 4 * 1000 * 1000 + 13;

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

int mul(int a, int b) {
    return a * (li)b % mod;
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

int read() {
    return scanf("%d%d", &n, &mod) == 2;
}

int main() {
    freopen("input.txt", "r", stdin);

    clock_t tt = clock();

    int tc;
    scanf("%d", &tc);
    while (tc--) {
        if (!read()) break;
        solve();
        fprintf(stderr, "TIME = %ld\n", clock() - tt);
        tt = clock();
    }
    return 0;
}
