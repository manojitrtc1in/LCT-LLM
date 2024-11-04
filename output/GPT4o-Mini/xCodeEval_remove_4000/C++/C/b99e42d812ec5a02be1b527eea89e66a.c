#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef long long int64;
const int M = 1000000007;

int dp[5005][5005];

int main() {
    char s[5005], t[5005];
    fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);
    int sz1 = strlen(s) - 1; // Remove newline character
    int sz2 = strlen(t) - 1; // Remove newline character
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < sz1; i++) {
        for (int j = 0; j < sz2; j++) {
            dp[i + 1][j + 1] = (dp[i + 1][j] + (s[i] == t[j]) * (dp[i][j] + 1)) % M;
        }
    }

    int re = 0;
    for (int i = 0; i < sz1; i++) {
        re = (re + dp[i + 1][sz2]) % M;
    }
    printf("%d\n", re);
    return 0;
}
