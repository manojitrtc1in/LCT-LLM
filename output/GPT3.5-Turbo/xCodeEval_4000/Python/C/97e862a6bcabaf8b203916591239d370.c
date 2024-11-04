#include <stdio.h>

#define MAXN 1000005
#define MOD 1000000007

int DP[MAXN];
int CUM[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    DP[1] = 1;
    CUM[1] = 0;
    int S = 1;

    for (int i = 2; i <= n; i++) {
        CUM[i] = (CUM[i-1] + CUM[i]) % m;
        DP[i] = (S + CUM[i]) % m;
        S += DP[i];
        S %= m;

        for (int j = i + i; j <= n; j += i) {
            CUM[j] = (CUM[j] + DP[i] - DP[i-1]) % m;
        }
    }

    printf("%d\n", DP[n]);

    return 0;
}
