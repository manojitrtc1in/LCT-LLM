#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000005
#define MOD 998244353

typedef long long ll;

char A[MAX];
ll dp[MAX][25][11];

ll go(char A[], int i, int pv, int v) {
    if (i == strlen(A)) {
        if (pv == 0)
            return 1;
        return 0;
    }
    if (dp[i][pv][v] != -1)
        return dp[i][pv][v];
    ll ans = 0;
    if (A[i] == '_') {
        for (int j = 0; j < 10; j++) {
            if (i == 0 && j == 0)
                continue;
            int y = pv * 10 + j;
            y %= 25;
            ans += go(A, i + 1, y, v);
        }
    } else if (A[i] == 'X') {
        if (v != 10) {
            ans += go(A, i + 1, (pv * 10 + v) % 25, v);
        } else {
            for (int j = 0; j < 10; j++) {
                if (i == 0 && j == 0)
                    continue;
                int y = pv * 10 + j;
                y %= 25;
                ans += go(A, i + 1, y, j);
            }
        }
    } else {
        ans += go(A, i + 1, (pv * 10 + A[i] - '0') % 25, v);
    }
    return dp[i][pv][v] = ans;
}

int main() {
    scanf("%s", A);
    if (strlen(A) == 1 && A[0] == '0') {
        printf("1\n");
        return 0;
    }
    if (A[0] == '0') {
        printf("0\n");
        return 0;
    }
    if (strlen(A) == 1) {
        if (A[0] == 'X' || A[0] == '_') {
            printf("1\n");
            return 0;
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", go(A, 0, 0, 10));
    return 0;
}
