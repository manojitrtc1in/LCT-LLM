#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXI (2 << 29)
#define M 1000000007

int dp[5005][5005];

void reset(int a[5005][5005]) {
    memset(a, 0, sizeof(int) * 5005 * 5005);
}

int main() {
    char s[5005], t[5005];
    scanf("%s %s", s, t);
    reset(dp);
    
    int s_len = strlen(s);
    int t_len = strlen(t);
    
    for (int i = 0; i < s_len; i++) {
        for (int j = 0; j < t_len; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = (dp[i + 1][j] + (dp[i][j] + 1) % M) % M;
            } else {
                dp[i + 1][j + 1] = dp[i + 1][j];
            }
        }
    }
    
    int re = 0;
    for (int i = 0; i < s_len; i++) {
        re = (re + dp[i + 1][t_len] % M) % M;
    }
    
    printf("%d\n", re);
    return 0;
}
