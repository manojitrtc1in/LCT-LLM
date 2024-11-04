#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 10007
#define N 202

typedef struct {
    int x[1];
} Field;

Field dp[N][N][10 * N];
int ok[N][N][10 * N];
char s[N];

Field go(int left, int right, int i) {
    if (i < 0) return (Field){0};
    if (i == 0 && left >= right) return (Field){1};
    Field res = dp[left][right][i];
    if (ok[left][right][i]) return res;

    res = (Field){0};

    if (left >= right) {
        Field temp = go(left, right, (i - 2 < 0) ? 0 : i - 2);
        res.x[0] = (res.x[0] + (temp.x[0] * 26) % MOD) % MOD;
    } else if (left + 1 == right) {
        if (i == 0) {
            Field temp = go(left + 1, right - 1, i);
            res.x[0] = (res.x[0] + temp.x[0]) % MOD;
        } else {
            Field temp = go(left + 1, right, i - 1);
            res.x[0] = (res.x[0] + temp.x[0]) % MOD;
        }
        Field temp = go(left, right, (i - 2 < 0) ? 0 : i - 2);
        res.x[0] = (res.x[0] + (temp.x[0] * 25) % MOD) % MOD;
    } else {
        if (s[left] == s[right - 1]) {
            Field temp = go(left + 1, right - 1, i);
            res.x[0] = (res.x[0] + temp.x[0]) % MOD;
            Field temp2 = go(left, right, (i - 2 < 0) ? 0 : i - 2);
            res.x[0] = (res.x[0] + (temp2.x[0] * 25) % MOD) % MOD;
        } else {
            Field temp = go(left + 1, right, i - 1);
            res.x[0] = (res.x[0] + temp.x[0]) % MOD;
            Field temp2 = go(left, right - 1, i - 1);
            res.x[0] = (res.x[0] + temp2.x[0]) % MOD;
            Field temp3 = go(left, right, (i - 2 < 0) ? 0 : i - 2);
            res.x[0] = (res.x[0] + (temp3.x[0] * 24) % MOD) % MOD;
        }
    }

    ok[left][right][i] = 1;
    return res;
}

int main() {
    int n;
    scanf("%s", s);
    scanf("%d", &n);

    for (int i = 0; i < 10 * strlen(s); i++) {
        dp[0][strlen(s)][i] = go(0, strlen(s), i);
    }

    // Placeholder for solver logic
    // The actual implementation of the solver is omitted for brevity.

    printf("%d\n", dp[0][strlen(s)][n].x[0]);
    return 0;
}
