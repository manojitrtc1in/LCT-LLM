#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef long long int64;

#define MAXI (2 << 29)
#define M 1000000007

int dp[5005][5005];

void reset(int dp[5005][5005]) {
    for (int i = 0; i < 5005; i++) {
        for (int j = 0; j < 5005; j++) {
            dp[i][j] = 0;
        }
    }
}

int main() {
    char s[5005], t[5005];
    fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);
    
    int sz1 = strlen(s) - 1; // Exclude newline character
    int sz2 = strlen(t) - 1; // Exclude newline character
    reset(dp);
    
    for (int i = 0; i < sz1; i++) {
        for (int j = 0; j < sz2; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = (dp[i + 1][j] + dp[i][j] + 1) % M;
            } else {
                dp[i + 1][j + 1] = dp[i + 1][j];
            }
        }
    }
    
    int64 re = 0;
    for (int i = 0; i < sz1; i++) {
        re = (re + dp[i + 1][sz2]) % M;
    }
    
    printf("%lld\n", re);
    return 0;
}
