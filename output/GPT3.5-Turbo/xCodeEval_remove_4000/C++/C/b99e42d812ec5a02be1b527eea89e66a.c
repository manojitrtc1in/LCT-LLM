#include <stdio.h>
#include <string.h>

#define MAXI 5005
#define M 1000000007

int dp[MAXI][MAXI];

int main() {
    char s[MAXI], t[MAXI];
    fgets(s, MAXI, stdin);
    fgets(t, MAXI, stdin);
    int sz1 = strlen(s) - 1; // subtract 1 to remove newline character
    int sz2 = strlen(t) - 1; // subtract 1 to remove newline character
    
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
