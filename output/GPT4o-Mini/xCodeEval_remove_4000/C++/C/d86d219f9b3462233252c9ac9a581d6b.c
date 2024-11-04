#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef long long ll;
typedef unsigned int uint;

double dp[55][5010];
double dans[55][5010];
double p[55];
int f[55], s[55];

int solve() {
    int n, r;
    scanf("%d %d", &n, &r);
    double lp = 0;
    double rp = 1e8;

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %lf", &f[i], &s[i], &p[i]);
        p[i] *= 0.01;
    }

    const int K = 50 * 100 + 1;

    for (int iter = 0; iter < 100; ++iter) {
        double z = (lp + rp) * 0.5;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < K; ++j) {
                dans[i][j] = z;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < f[i]; ++j) {
                dans[i][j] = z;
            }
            int fi = f[i];
            int si = s[i];
            double pi = p[i];
            for (int j = fi; j < si; ++j) {
                dans[i][j] = fmin(z, (fi + dans[i + 1][j - fi]) * pi + (si + z) * (1 - pi));
            }
            for (int j = s[i]; j < K; ++j) {
                dans[i][j] = fmin(z, (fi + dans[i + 1][j - fi]) * pi + (si + dans[i + 1][j - si]) * (1 - pi));
            }
        }
        if (dans[0][r] < z - 1e-10) {
            rp = z;
        } else {
            lp = z;
        }
    }
    printf("%.10f\n", (lp + rp) * 0.5);
    return 0;
}

int main() {
    solve();
    return 0;
}
