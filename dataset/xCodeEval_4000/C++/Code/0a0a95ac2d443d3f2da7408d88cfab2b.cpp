#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
char s[505][505];
int n, m, mp[405][405], dp[405][405][8];
int movex[8] = {0, -1, -1, -1,  0,  1, 1, 1};
int movey[8] = {1,  1,  0, -1, -1, -1, 0, 1};

bool inGrid(int i, int j) {
    return (1 <= i && i <= n && 1 <= j && j <= m);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) {
            mp[i + 1][j + 1] = s[i][j] == '1' ? 1 : 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int d = 0; d < 8; d++) {
                int x = i;
                int y = j;
                while (inGrid(x, y) && !mp[x][y]) {
                    dp[i][j][d]++;
                    x = x + movex[d];
                    y = y + movey[d];
                }
               

            }
           

        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j]) continue;
            for (int d = 0; d < 8; d++) {
                int cnt = 1;
                if (d % 2) {
                    int x = i + movex[(d + 1)%8], y = j + movey[(d + 1)%8];
                    while (dp[i][j][(d + 1)%8] > cnt && dp[i][j][(d + 7)%8] > cnt) {
                        if (dp[x][y][((d + 1)%8 + 5) % 8] >= 1 + cnt) ans++;
                        cnt++;
                        x += movex[(d + 1) % 8];
                        y += movey[(d + 1) % 8];
                    }
                } else {
                    int x = i + movex[(d + 1)%8], y = j + movey[(d + 1)%8];
                    while (dp[i][j][(d + 1)%8] > cnt && dp[i][j][(d + 7)%8] > cnt) {
                        if (dp[x][y][((d + 1)%8 + 5) % 8] >= 1 + 2 * cnt) ans++;
                        cnt++;
                        x += movex[(d + 1) % 8];
                        y += movey[(d + 1) % 8];
                    }
                }
              

            }
           

        }
    }
    cout << ans << endl;
    return 0;
}




































