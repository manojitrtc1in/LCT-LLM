#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define _  (int)(2e5 + 10)
#define __ (int)(1e6 + 10)
#define LOG 18

int n, k;
double p[22], subret[22];
double dp[1 << 20];

void solve(int id) {
    if (p[id] <= 1e-9) {
        printf("0\n");
        return;
    }
    memset(subret, 0, sizeof(subret));
    subret[0] = dp[0] = p[id];
    for (int i = 1; i < (1 << n); i++) {
        dp[i] = 0;
        if (i & (1 << id)) continue;
        double sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += p[j];
                dp[i] += dp[i ^ (1 << j)] * p[j];
            }
        }
        dp[i] /= 1 - sum;
        subret[__builtin_popcount(i)] += dp[i];
    }
    double ret = 0;
    for (int i = 0; i < k; i++) ret += subret[i];

    printf("%.10f\n", ret);
}

void _main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &p[i]);
    }
    for (int i = 0; i < n; i++) {
        solve(i);
    }
}

void generate_test_case() {
#ifdef _LOCAL_JUDGE
    srand(time(0));
    int n = 1000;
#endif
    exit(0);
}

int main() {
#ifdef _LOCAL_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
#if 1
    _main();
#else
    generate_test_case();
#endif
#ifdef _LOCAL_JUDGE
    printf("Time elapsed: %f s.\n", run_time());
    printf("%s\n", my_time());
#endif
    return 0;
}
