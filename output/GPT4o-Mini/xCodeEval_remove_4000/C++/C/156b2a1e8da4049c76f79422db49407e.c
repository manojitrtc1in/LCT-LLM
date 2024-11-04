#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_N 22
#define MAX_MASK (1 << 20)
#define EPS 1e-9
#define MOD 1000000007

typedef double db;

int n, k;
db p[MAX_N], subret[MAX_N];
db dp[MAX_MASK];

void solve(int id) {
    if (p[id] <= EPS) {
        printf("0\n");
        return;
    }
    memset(subret, 0, sizeof(subret));
    subret[0] = dp[0] = p[id];

    for (int i = 1; i < (1 << n); i++) {
        dp[i] = 0;
        if (i & (1 << id)) continue;
        db sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += p[j];
                dp[i] += dp[i ^ (1 << j)] * p[j];
            }
        }
        dp[i] /= 1 - sum;
        subret[__builtin_popcount(i)] += dp[i];
    }
    db ret = 0;
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
    printf("\n");
}

void id3() {
    srand(time(0));
    int n = 1000;
    exit(0);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);

    _main();
    id3();

    printf("Time elapsed: %lf s.\n", (double)clock() / CLOCKS_PER_SEC);
    FILE *fp = fopen("FILE_NAME", "r+");
    fprintf(fp, "//Latest run time : %lf\n", (double)clock() / CLOCKS_PER_SEC);
    fclose(fp);

    return 0;
}
