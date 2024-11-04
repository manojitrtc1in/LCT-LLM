#include <stdio.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

ll dp[65][2][2][2];

void solve() {
    ll t;
    scanf("%lld", &t);

    REP(i, 61) REP(j, 2) REP(k, 2) REP(l, 2) dp[i][j][k][l] = 0;
    dp[0][0][0][0] = 1;
    REP(i, 60) {
        int f2 = (t >> i) & 1;
        if (f2) {
            dp[i + 1][0][0][0] += dp[i][0][0][0];
            dp[i + 1][1][0][0] += dp[i][0][0][0];
            dp[i + 1][0][1][0] += dp[i][0][0][0];
            dp[i + 1][1][1][0] += dp[i][0][0][0];
            dp[i + 1][0][1][0] += dp[i][0][0][1];
            dp[i + 1][1][1][0] += dp[i][0][0][1];
            dp[i + 1][0][0][1] += dp[i][0][0][1];
            dp[i + 1][1][0][1] += dp[i][0][0][1];
            dp[i + 1][1][0][0] += dp[i][0][1][0];
            dp[i + 1][0][1][0] += dp[i][0][1][0];
            dp[i + 1][1][1][0] += dp[i][0][1][0];
            dp[i + 1][0][0][1] += dp[i][0][1][0];
            dp[i + 1][1][1][0] += dp[i][0][1][1];
            dp[i + 1][0][0][1] += dp[i][0][1][1];
            dp[i + 1][1][0][1] += dp[i][0][1][1];
            dp[i + 1][0][1][1] += dp[i][0][1][1];
            dp[i + 1][0][0][0] += dp[i][1][0][0];
            dp[i + 1][1][0][0] += dp[i][1][0][0];
            dp[i + 1][0][1][0] += dp[i][1][0][0];
            dp[i + 1][1][1][0] += dp[i][1][0][0];
            dp[i + 1][0][1][0] += dp[i][1][0][1];
            dp[i + 1][1][1][0] += dp[i][1][0][1];
            dp[i + 1][0][0][1] += dp[i][1][0][1];
            dp[i + 1][1][0][1] += dp[i][1][0][1];
            dp[i + 1][1][0][0] += dp[i][1][1][0];
            dp[i + 1][0][1][0] += dp[i][1][1][0];
            dp[i + 1][1][1][0] += dp[i][1][1][0];
            dp[i + 1][0][0][1] += dp[i][1][1][0];
            dp[i + 1][1][1][0] += dp[i][1][1][1];
            dp[i + 1][0][0][1] += dp[i][1][1][1];
            dp[i + 1][1][0][1] += dp[i][1][1][1];
            dp[i + 1][0][1][1] += dp[i][1][1][1];
        } else {
            dp[i + 1][0][0][0] += dp[i][0][0][0];
            dp[i + 1][1][0][0] += dp[i][0][0][0];
            dp[i + 1][0][1][0] += dp[i][0][0][0];
            dp[i + 1][1][1][0] += dp[i][0][0][0];
            dp[i + 1][0][1][0] += dp[i][0][0][1];
            dp[i + 1][1][1][0] += dp[i][0][0][1];
            dp[i + 1][0][0][1] += dp[i][0][0][1];
            dp[i + 1][1][0][1] += dp[i][0][0][1];
            dp[i + 1][1][0][0] += dp[i][0][1][0];
            dp[i + 1][0][1][0] += dp[i][0][1][0];
            dp[i + 1][1][1][0] += dp[i][0][1][0];
            dp[i + 1][0][0][1] += dp[i][0][1][0];
            dp[i + 1][1][1][0] += dp[i][0][1][1];
            dp[i + 1][0][0][1] += dp[i][0][1][1];
            dp[i + 1][1][0][1] += dp[i][0][1][1];
            dp[i + 1][0][1][1] += dp[i][0][1][1];
            dp[i + 1][1][0][0] += dp[i][1][0][0];
            dp[i + 1][0][1][0] += dp[i][1][0][0];
            dp[i + 1][1][1][0] += dp[i][1][0][0];
            dp[i + 1][0][0][1] += dp[i][1][0][0];
            dp[i + 1][1][1][0] += dp[i][1][0][1];
            dp[i + 1][0][0][1] += dp[i][1][0][1];
            dp[i + 1][1][0][1] += dp[i][1][0][1];
            dp[i + 1][0][1][1] += dp[i][1][0][1];
            dp[i + 1][0][1][0] += dp[i][1][1][0];
            dp[i + 1][1][1][0] += dp[i][1][1][0];
            dp[i + 1][0][0][1] += dp[i][1][1][0];
            dp[i + 1][1][0][1] += dp[i][1][1][0];