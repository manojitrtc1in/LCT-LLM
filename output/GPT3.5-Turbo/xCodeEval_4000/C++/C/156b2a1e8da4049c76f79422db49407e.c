#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FILE_NAME "model.c"

#define MAX_N 22
#define MAX_MASK (1 << MAX_N)
#define EPS 1e-9

int n, k;
double p[MAX_N], subret[MAX_N];
double dp[MAX_MASK];

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
