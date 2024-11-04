#define ONLINE_JUDGE 1

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    char s[n + 1], t[m + 1];
    scanf("%s %s", s, t);
    int dp[n][m][k + 1][2];
    int ans = -1;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            dp[i][j][1][0] = dp[i][j][1][1] = -1;
            if(i > 0)
                dp[i][j][1][0] = max(dp[i][j][1][0], max(dp[i - 1][j][1][0], dp[i - 1][j][1][1]));
            if(j > 0)
                dp[i][j][1][0] = max(dp[i][j][1][0], max(dp[i][j - 1][1][0], dp[i][j - 1][1][1]));
            if(s[i] == t[j])
                if(i > 0 && j > 0 && dp[i - 1][j - 1][1][1] != -1)
                    dp[i][j][1][1] = dp[i - 1][j - 1][1][1] + 1;
                else
                    dp[i][j][1][1] = 1;
            if(1 == k)
                ans = max(ans, dp[i][j][1][1]);
        }
    }
    for(int ki = 2;ki <= k;ki++) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                dp[i][j][ki][0] = dp[i][j][ki][1] = -1;
                if(s[i] == t[j] && i > 0 && j > 0) {
                    if(dp[i - 1][j - 1][ki][1] != -1)
                        dp[i][j][ki][1] = max(dp[i][j][ki][1], dp[i - 1][j - 1][ki][1] + 1);
                    if(max(dp[i - 1][j - 1][ki - 1][0], dp[i - 1][j - 1][ki - 1][1]) != -1)
                        dp[i][j][ki][1] = max(dp[i][j][ki][1], max(dp[i - 1][j - 1][ki - 1][0], dp[i - 1][j - 1][ki - 1][1]) + 1);
                }
                if(i > 0)
                    dp[i][j][ki][0] = max(dp[i][j][ki][0], max(dp[i - 1][j][ki][0], dp[i - 1][j][ki][1]));
                if(j > 0)
                    dp[i][j][ki][0] = max(dp[i][j][ki][0], max(dp[i][j - 1][ki][0], dp[i][j - 1][ki][1]));
                if(ki == k)
                    ans = max(ans, dp[i][j][ki][1]);
            }
        }
    }
    printf("%d", ans);
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
