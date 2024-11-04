#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int main() {
    int tt = 1;

    for (int _ = 0; _ < tt; _++) {
        int n, m;
        scanf("%d %d", &n, &m);

        long long DP[MAXN] = {0};
        long long CUM[MAXN] = {0};
        CUM[1] = 0;
        DP[1] = 1;

        long long S = 1;

        for (int i = 2; i <= n; i++) {
            CUM[i] = (CUM[i - 1] + CUM[i]) % m;
            DP[i] = (S + CUM[i]) % m;
            S = (S + DP[i]) % m;

            for (int j = i + i; j <= n; j += i) {
                CUM[j] = (CUM[j] + DP[i] - DP[i - 1]) % m;
            }
        }

        printf("%lld\n", DP[n]);
    }

    return 0;
}
