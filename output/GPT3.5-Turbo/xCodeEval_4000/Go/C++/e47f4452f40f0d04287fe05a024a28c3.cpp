#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <cassert>
#include <functional>
#include <chrono>
using namespace std;

const int MOD = 1000000007;

int readInt() {
    int x;
    cin >> x;
    return x;
}

void printInt(int x) {
    cout << x;
}

void printLine() {
    cout << endl;
}

void solve() {
    int n = readInt();
    int a = readInt();
    int b = readInt();
    int movesNum = readInt();

    vector<vector<int>> dp(2, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1 + dp[0][i - 1];
        if (dp[0][i] >= MOD) {
            dp[0][i] -= MOD;
        }
    }

    for (int move = 0; move < movesNum; move++) {
        for (int x = 1; x <= n; x++) {
            int length = abs(x - b);
            dp[(move & 1) ^ 1][x] = dp[(move & 1) ^ 1][x - 1];
            if (length > 1) {
                int left = max(x - (length - 1), 1);
                int right = min(x + (length - 1), n);
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
