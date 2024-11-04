#include <stdio.h>
#include <stdlib.h>

int f[55], s[55];
double p[55];

double dp[55][5010];
double dans[55][5010];
double pf[55];
double pp[55];

int solve() {
    int n, r;
    scanf("%d %d", &n, &r);
    int t = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %lf", &f[i], &s[i], &p[i]);
        p[i] *= 0.01;
    }

    const int K = 50 * 100 + 1;

    double lp = 0;
    double rp = 1e8;
    for (int iter = 0; iter < 100; ++iter) {
        auto z = (lp + rp) * 0.5;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < K; ++j) {
                dans[i][j] = z;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < f[i]; ++j) {
                dans[i][j] = z;
            }
            auto fi = f[i];
            auto si = s[i];
            auto pi = p[i];
            for (int j = fi; j < si; ++j) {
                dans[i][j] = min(z, (fi + dans[i + 1][j - fi]) * pi + (si + z) * (1 - pi));
            }
            for (int j = s[i]; j < K; ++j) {
                dans[i][j] = min(z, (fi + dans[i + 1][j - fi]) * pi + (si + dans[i + 1][j - si]) * (1 - pi));
            }
        }
        if (dans[0][r] < z - 1e-10) {
            rp = z;
        } else {
            lp = z;
        }
    }
    printf("%.10lf\n", (lp + rp) * 0.5);

    return 0;
}

int main() {
    return solve();
}
