#include <stdio.h>
#include <string.h>

#define MAX_SIZE 5005
#define MOD 1000000007

int dp[MAX_SIZE][MAX_SIZE];

int main() {
    char s[MAX_SIZE], t[MAX_SIZE];
    fgets(s, MAX_SIZE, stdin);
    fgets(t, MAX_SIZE, stdin);
    int sz1 = strlen(s) - 1; // subtract 1 to remove the newline character
    int sz2 = strlen(t) - 1; // subtract 1 to remove the newline character

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < sz1; i++) {
        for (int j = 0; j < sz2; j++) {
            dp[i + 1][j + 1] = (dp[i + 1][j] + (s[i] == t[j]) * (dp[i][j] + 1)) % MOD;
        }
    }

    int re = 0;
    for (int i = 0; i < sz1; i++) {
        re = (re + dp[i + 1][sz2]) % MOD;
    }

    printf("%d\n", re);

    return 0;
}
