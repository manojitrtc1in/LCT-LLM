#include <stdio.h>
#include <string.h>

int n, m;
int a[55], b[55];
int dp[55][55][55];
const int Mod = 998244353;
int nii[5555];

int id0(int a, int b) {
    if (!b) {
        return 1;
    }
    int x = id0(a, b >> 1);
    x = 1LL * x * x % Mod;
    if (b & 1) {
        x = 1LL * x * a % Mod;
    }
    return x;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < 5555; i++) {
        nii[i] = id0(i, Mod - 2);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        memset((int*)dp, 0, sizeof(dp));
        int proba = 0, probb = 0;
        for (int j = 1; j <= n; j++) {
            if (!a[j]) {
                probb += b[j];
            } else {
                proba += b[j];
            }
        }
        dp[0][0][0]++;
        for (int j = 0; j < m; j++) {
            for (int l = 0; l <= j; l++) {
                int mm = j - l;
                for (int n = 0; n < 55; n++) {
                    if (a[i]) {
                        dp[j + 1][l + 1][n + 1] += 1LL * dp[j][l][n] * (n + b[i]) % Mod * nii[proba + probb + l - mm] % Mod;
                        if (dp[j + 1][l + 1][n + 1] >= Mod) {
                            dp[j + 1][l + 1][n + 1] -= Mod;
                        }
                    } else {
                        dp[j + 1][l][n + 1] += 1LL * dp[j][l][n] * (b[i] - n) % Mod * nii[proba + probb + l - mm] % Mod;
                        if (dp[j + 1][l][n + 1] >= Mod) {
                            dp[j + 1][l][n + 1] -= Mod;
                        }
                    }
                    if (a[i]) {
                        dp[j + 1][l + 1][n] += 1LL * dp[j][l][n] * (proba + l - n - b[i]) % Mod * nii[proba + probb + l - mm] % Mod;
                        if (dp[j + 1][l + 1][n] >= Mod) {
                            dp[j + 1][l + 1][n] -= Mod;
                        }
                        dp[j + 1][l][n] += 1LL * dp[j][l][n] * (probb - mm) % Mod * nii[proba + probb + l - mm] % Mod;
                        if (dp[j + 1][l][n] >= Mod) {
                            dp[j + 1][l][n] -= Mod;
                        }
                    } else {
                        dp[j + 1][l + 1][n] += 1LL * dp[j][l][n] * (proba + l) % Mod * nii[proba + probb + l - mm] % Mod;
                        if (dp[j + 1][l + 1][n] >= Mod) {
                            dp[j + 1][l + 1][n] -= Mod;
                        }
                        dp[j + 1][l][n] += 1LL * dp[j][l][n] * (probb - mm - b[i] + n) % Mod * nii[proba + probb + l - mm] % Mod;
                        if (dp[j + 1][l][n] >= Mod) {
                            dp[j + 1][l][n] -= Mod;
                        }
                    }
                }
            }
        }
        int all = 0;
        for (int j = 0; j < 52; j++) {
            for (int k = 0; k < 52; k++) {
                all += 1LL * dp[m][j][k] * (a[i] ? b[i] + k : b[i] - k) % Mod;
                if (all >= Mod) {
                    all -= Mod;
                }
            }
        }
        printf("%d\n", all);
    }
}