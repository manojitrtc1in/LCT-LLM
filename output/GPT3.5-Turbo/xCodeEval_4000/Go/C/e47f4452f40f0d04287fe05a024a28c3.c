#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int readInt() {
    char input[100];
    scanf("%s", input);
    return atoi(input);
}

void printInt(int value) {
    printf("%d", value);
}

void printLine() {
    printf("\n");
}

int absInt(int a) {
    if (a > 0) {
        return a;
    } else {
        return -a;
    }
}

int maxInt(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int minInt(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

void solve() {
    int n = readInt();
    int a = readInt();
    int b = readInt();
    int movesNum = readInt();

    int dp[2][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1 + dp[0][i - 1];
        if (dp[0][i] >= MOD) {
            dp[0][i] -= MOD;
        }
    }

    for (int move = 0; move < movesNum; move++) {
        for (int x = 1; x <= n; x++) {
            int length = absInt(x - b);
            dp[(move & 1) ^ 1][x] = dp[(move & 1) ^ 1][x - 1];
            if (length > 1) {
                int left = maxInt(x - (length - 1), 1);
                int right = minInt(x + (length - 1), n);
                int add = dp[(move & 1)][right] - dp[(move & 1)][left - 1];
                if (add < 0) {
                    add += MOD;
                }
                int sub = dp[(move & 1)][x] - dp[(move & 1)][x - 1];
                if (sub < 0) {
                    sub += MOD;
                }
                int diff = add - sub;
                if (diff < 0) {
                    diff += MOD;
                }
                dp[(move & 1) ^ 1][x] += diff;
                if (dp[(move & 1) ^ 1][x] >= MOD) {
                    dp[(move & 1) ^ 1][x] -= MOD;
                }
            }
        }
    }

    int ans = dp[((movesNum - 1) & 1) ^ 1][a] - dp[((movesNum - 1) & 1) ^ 1][a - 1];
    if (ans < 0) {
        ans += MOD;
    }
    printInt(ans);
    printLine();
}

int main() {
    solve();
    return 0;
}
