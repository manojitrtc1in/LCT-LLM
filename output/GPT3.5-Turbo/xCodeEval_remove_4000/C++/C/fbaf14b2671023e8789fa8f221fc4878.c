#include <stdio.h>
#include <string.h>

#define MAX_SIZE 5005
#define MOD 1000000007

int dp[MAX_SIZE][MAX_SIZE];

int main() {
    char s[MAX_SIZE], t[MAX_SIZE];
    scanf("%s %s", s, t);
    int sz1 = strlen(s), sz2 = strlen(t);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < sz1; i++) {
        for (int j = 0; j < sz2; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = ((dp[i + 1][j] % MOD) + ((dp[i][j] + 1) % MOD)) % MOD;
            } else {
                dp[i + 1][j + 1] = dp[i + 1][j];
            }
        }
    }
    int re = 0;
    for (int i = 0; i < sz1; i++) {
        re = (re + dp[i + 1][sz2] % MOD) % MOD;
    }
    printf("%d\n", re);
    return 0;
}
