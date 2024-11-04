#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i < b; i++)
#define sz(x) ((int)(x).size())

typedef long long li;
typedef long double ld;

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    int first;
    int second;
} pair;

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
    fore(i, 1, n + 1) {
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
    int n, mod;
    if (scanf("%d%d", &n, &mod) != 2)
        return 0;

    solve();

    return 0;
}
