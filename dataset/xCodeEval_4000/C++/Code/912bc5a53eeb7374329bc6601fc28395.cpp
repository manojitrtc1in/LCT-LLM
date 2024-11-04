#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int n, m, step[2005][2005], vis[2005][2005];
char chess[2005][2005];
pair<int, int> end[2005][2005], best;


int movex(int x, int y) {
    if (chess[x][y] == '^') {
        return (x - 1);
    } else if (chess[x][y] == 'v') {
        return (x + 1);
    } else {
        return x;
    }
}
int movey(int x, int y) {
    if (chess[x][y] == '>') {
        return (y + 1);
    } else if (chess[x][y] == '<') {
        return (y - 1);
    } else {
        return y;
    }
}

int dfs(int x, int y) {
    if (vis[x][y]) {
        cout << "-1";
        exit(0);
    }
    vis[x][y] = 1;
    int nxtx = movex(x, y);
    int nxty = movey(x, y);

    if (chess[nxtx][nxty] == '#') {
        end[x][y] = make_pair(x, y);
        step[x][y] = 1;
        return 1;
    } else if (step[nxtx][nxty]) {
        end[x][y] = end[nxtx][nxty];
        step[x][y] = step[nxtx][nxty] + 1;
        return step[x][y];
    } else {
        int res = dfs(nxtx, nxty);
        end[x][y] = end[nxtx][nxty];
        step[x][y] = res + 1;
        return step[x][y];
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> chess[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (!step[i][j] && chess[i][j] != '#') {
                

                int res = dfs(i, j);
                if (ans < res) {
                    ans = res;
                    best = end[i][j];
                }
            }
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (step[i][j] == ans) {
                if (end[i][j].first != best.first || end[i][j].second != best.second) {
                    cout << 2 * ans << endl;
                    exit(0);
                }
            }
        }
    }
    cout << max(0, 2 * ans - 1) << endl;
    return 0;
}
































































