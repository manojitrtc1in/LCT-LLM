



#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <bitset>
#include <string.h>
#include <stack>
#include <fstream>


#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define y1 gksrpkogr
#define y0 jsfibpo

using namespace std;
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
#define INF 1010101010101010101









#define int ll
struct Info {
    int x1, y1;
    int x2, y2;
    int x3, y3;
};

void R(char &c) {
    if (c == '1')c = '0';
    else c = '1';
}

char c[200][200];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    vector<Info> ans;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (c[i][j] == '1' && c[i][j + 1] == '1' && c[i][j + 2] == '1' &&
                c[i + 1][j] == '1' && c[i + 1][j + 1] == '1' && c[i + 1][j + 2] == '1') {

                ans.push_back({i, j, i, j + 1, i + 1, j});
                ans.push_back({i + 1, j + 1, i, j + 2, i + 1, j + 2});
                c[i][j] = '0';
                c[i][j + 1] = '0';
                c[i][j + 2] = '0';
                c[i + 1][j] = '0';
                c[i + 1][j + 1] = '0';
                c[i + 1][j + 2] = '0';
            }
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m; j++) {
            if (c[i][j] == '1' && c[i][j + 1] == '1' &&
                c[i + 1][j] == '1' && c[i + 1][j + 1] == '1' &&
                c[i + 2][j] == '1' && c[i + 2][j + 1] == '1') {

                ans.push_back({i, j, i, j + 1, i + 1, j});
                ans.push_back({i + 1, j + 1, i + 2, j, i + 2, j + 1});
                c[i][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j] = '0';
                c[i + 1][j + 1] = '0';
                c[i + 2][j] = '0';
                c[i + 2][j + 1] = '0';
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (c[i][j] == '1' && c[i][j + 1] == '1' && c[i + 1][j] == '1' && c[i + 1][j + 1] == '1') {
                ans.push_back({i, j, i + 1, j, i, j + 1});
                ans.push_back({i + 1, j + 1, i + 1, j, i, j + 1});
                ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                ans.push_back({i, j, i + 1, j, i + 1, j + 1});

                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            if (c[i][j] == '1' && c[i][j + 1] == '1' && c[i + 1][j] == '1' && c[i + 1][j + 1] == '0') {
                ans.push_back({i, j, i, j + 1, i + 1, j});

                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
            if (c[i][j] == '1' && c[i][j + 1] == '1' && c[i + 1][j] == '0' && c[i + 1][j + 1] == '1') {
                ans.push_back({i, j, i, j + 1, i + 1, j + 1});

                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
            if (c[i][j] == '1' && c[i][j + 1] == '0' && c[i + 1][j] == '1' && c[i + 1][j + 1] == '1') {
                ans.push_back({i, j, i + 1, j, i + 1, j + 1});

                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
            if (c[i][j] == '0' && c[i][j + 1] == '1' && c[i + 1][j] == '1' && c[i + 1][j + 1] == '1') {
                ans.push_back({i, j + 1, i + 1, j, i + 1, j + 1});

                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (c[i][j] == '1' && c[i][j + 1] == '1' && c[i + 1][j] == '0' && c[i + 1][j + 1] == '0') {
                ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});


                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
            if (c[i][j] == '1' && c[i][j + 1] == '0' && c[i + 1][j] == '1' && c[i + 1][j + 1] == '0') {
                ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});


                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
            if (c[i][j] == '1' && c[i][j + 1] == '0' && c[i + 1][j] == '0' && c[i + 1][j + 1] == '1') {
                ans.push_back({i, j, i, j + 1, i + 1, j});
                ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});


                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
            if (c[i][j] == '0' && c[i][j + 1] == '1' && c[i + 1][j] == '1' && c[i + 1][j + 1] == '0') {
                ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                ans.push_back({i, j, i + 1, j, i + 1, j + 1});


                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
            if (c[i][j] == '0' && c[i][j + 1] == '1' && c[i + 1][j] == '0' && c[i + 1][j + 1] == '1') {
                ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                ans.push_back({i, j, i + 1, j, i, j + 1});


                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
            if (c[i][j] == '0' && c[i][j + 1] == '0' && c[i + 1][j] == '1' && c[i + 1][j + 1] == '1') {
                ans.push_back({i, j, i + 1, j, i, j + 1});
                ans.push_back({i, j, i, j + 1, i + 1, j + 1});


                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            if (c[i][j] == '0' && c[i][j + 1] == '0' && c[i + 1][j] == '0' && c[i + 1][j + 1] == '0') continue;
            if (c[i][j] == '1' && c[i][j + 1] == '0' && c[i + 1][j] == '0' && c[i + 1][j + 1] == '0') {
                ans.push_back({i, j, i + 1, j, i, j + 1});
                ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                ans.push_back({i, j, i, j + 1, i + 1, j + 1});

                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
            if (c[i][j] == '0' && c[i][j + 1] == '1' && c[i + 1][j] == '0' && c[i + 1][j + 1] == '0') {
                ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});
                ans.push_back({i, j, i, j + 1, i + 1, j});

                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
            if (c[i][j] == '0' && c[i][j + 1] == '0' && c[i + 1][j] == '1' && c[i + 1][j + 1] == '0') {
                ans.push_back({i + 1, j, i, j, i, j + 1});
                ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                ans.push_back({i, j + 1, i + 1, j, i + 1, j + 1});

                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
            if (c[i][j] == '0' && c[i][j + 1] == '0' && c[i + 1][j] == '0' && c[i + 1][j + 1] == '1') {
                ans.push_back({i + 1, j + 1, i + 1, j, i, j + 1});
                ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                ans.push_back({i, j, i + 1, j, i + 1, j + 1});

                c[i][j] = '0';
                c[i + 1][j] = '0';
                c[i][j + 1] = '0';
                c[i + 1][j + 1] = '0';
                continue;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.x1 << " " << i.y1 << " " << i.x2 << " " << i.y2 << " " << i.x3 << " " << i.y3 << '\n';
    }
}

int32_t main()
{
    fast
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

