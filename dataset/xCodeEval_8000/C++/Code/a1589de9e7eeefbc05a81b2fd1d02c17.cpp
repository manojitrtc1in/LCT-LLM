#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
char mat[45][45];
int n, m, q, s[45][45], dp[45][45][45][45];

int check(int a, int b, int c, int d) {
    return ((s[c][d] - s[a-1][d] - s[c][b-1] + s[a-1][b-1]) == 0);
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (mat[i-1][j-1] == '1');
        }
    }

    for (int di = 0; di < n; di++) {
        for (int dj = 0; dj < m; dj++) {
            for (int i = 1; i <= n - di; i++) {
                for (int j = 1; j <= m - dj; j++) {
                    dp[i][j][di + i][dj + j]
                  = dp[i][j][di+i-1][dj+j] + dp[i][j][di+i][dj+j-1] - dp[i][j][di+i-1][dj+j-1] + dp[i+1][j][di+i][dj+j] + dp[i][j+1][di+i][dj+j] - dp[i+1][j+1][di+i][dj+j] - (dp[i+1][j][di+i][dj+j-1] + dp[i+1][j][di+i-1][dj+j] - dp[i+1][j][di+i-1][dj+j-1]) - (dp[i][j+1][di+i][dj+j-1] + dp[i][j+1][di+i-1][dj+j] - dp[i][j+1][di+i-1][dj+j-1]) + dp[i+1][j+1][i+di-1][j+dj] + dp[i+1][j+1][i+di][j+dj-1] - dp[i+1][j+1][i+di-1][j+dj-1] + check(i, j, i+di, j+dj);
                }
            }
        }
    }
    int a, b, c, d;
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c >> d;
        cout << dp[a][b][c][d] << endl;
    }
    return 0;
}







































































