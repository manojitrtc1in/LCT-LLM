#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAXN 22
#define MAXK 22
#define MAXMASK (1 << 20)
#define EPS 1e-9

typedef double db;

int n, k;
db p[MAXN], subret[MAXN];
db dp[MAXMASK];

void solve(int id) {
    if (p[id] <= EPS) {
        printf("0 ");
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
    for (int i = 0; i < k; i++) {
        ret += subret[i];
    }
    printf("%.10lf ", ret);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &p[i]);
    }
    for (int i = 0; i < n; i++) {
        solve(i);
    }
    printf("\n");
    return 0;
}
