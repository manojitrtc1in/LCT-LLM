#include <stdio.h>
#include <string.h>

#define MAX_SIZE 5005
#define MOD 1000000007

int dp[MAX_SIZE][MAX_SIZE];

int main() {
    char s[MAX_SIZE], t[MAX_SIZE];
    scanf("%s %s", s, t);
    memset(dp, 0, sizeof(dp));
    int s_len = strlen(s);
    int t_len = strlen(t);
    for (int i = 0; i < s_len; i++) {
        for (int j = 0; j < t_len; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = ((dp[i + 1][j] % MOD) + ((dp[i][j] + 1) % MOD)) % MOD;
            } else {
                dp[i + 1][j + 1] = dp[i + 1][j];
            }
        }
    }
    int result = 0;
    for (int i = 0; i < s_len; i++) {
        result = (result + dp[i + 1][t_len] % MOD) % MOD;
    }
    printf("%d\n", result);
    return 0;
}
