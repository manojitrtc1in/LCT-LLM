#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int MOD = 1000 * 1000 * 1000 + 7;

int readInt() {
    int x;
    std::cin >> x;
    return x;
}

void printInt(int value) {
    std::cout << value;
}

void solve() {
    int n = readInt();
    int a = readInt();
    int b = readInt();
    int movesNum = readInt();

    std::vector<std::vector<int>> dp(2, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1 + dp[0][i - 1];
        if (dp[0][i] >= MOD) {
            dp[0][i] -= MOD;
        }
    }

    for (int move = 0; move < movesNum; move++) {
        for (int x = 1; x <= n; x++) {
            int length = std::abs(x - b);
            dp[(move & 1) ^ 1][x] = dp[(move & 1) ^ 1][x - 1];
            if (length > 1) {
                int left = std::max(x - (length - 1), 1);
                int right = std::min(x + (length - 1), n);
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
    std::cout << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    solve();
    return 0;
}
