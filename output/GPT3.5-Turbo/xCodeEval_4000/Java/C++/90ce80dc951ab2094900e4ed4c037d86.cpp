#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

class Solution {
    const int MAX = INT_MAX;
    const int MIN = INT_MIN;

    struct Item {
        long long w = 0;
        long long val = 0;
        int group;
        Item(long long w, long long val, int group) : w(w), val(val), group(group) {}
    };

public:
    void solution(int K, long long F[], int W) {
        long long res = 0;
        int ten[] = {1, 10, 100, 1000, 10000, 100000};

        vector<Item> A;

        K--;

        if (K == 0) {
            string num = to_string(W);
            reverse(num.begin(), num.end());
            long long score = 0;
            for (int k = 0; k < num.length(); k++) {
                int d = num[k] - '0';
                if (d % 3 == 0) {
                    score += (F[k] * (d / 3));
                }
            }
            cout << score << endl;
            return;
        }

        for (int i = 0; i < 6; i++) {
            long long weight = ten[i] * 3;

            int cur = 0;
            for (int j = 0; j < 32; j++) {
                int go = 1 << j;
                if (cur + go >= (3 * K)) {
                    long long remain = 3 * K - cur;
                    Item item(weight * remain, F[i] * remain, i);
                    A.push_back(item);
                    break;
                }
                Item item(weight * (1 << j), F[i] * (1 << j), i);
                cur += (1 << j);
                A.push_back(item);
            }
        }

        vector<long long> pre(W + 1, -1);
        vector<long long> dp(W + 1, -1);
        pre[0] = 0;

        for (int i = 1; i < A.size(); i++) {
            Item item = A[i - 1];
            dp = vector<long long>(W + 1, -1);
            dp[0] = 0;
            for (int j = 1; j < dp.size(); j++) {
                dp[j] = max(dp[j], pre[j]);
                long long w = (item.w);
                long long val = item.val;
                if (j < w || pre[j - w] == -1) {
                    continue;
                }
                dp[j] = max(dp[j], pre[j - w] + val);
                string num = to_string(W - j);
                reverse(num.begin(), num.end());
                long long score = 0;
                for (int k = 0; k < num.length(); k++) {
                    int d = num[k] - '0';
                    if (d % 3 == 0) {
                        score += (F[k] * (d / 3));
                    }
                }
                res = max(res, dp[j] + score);
            }
            pre = dp;
        }

        cout << res << endl;
    }
};

int main() {
    int T = 1;

    for (int t = 0; t < T; t++) {
        int K = Int();
        long long F[6];
        for (int i = 0; i < 6; i++) {
            F[i] = Int();
        }

        int q = Int();
        int W = Int();

        Solution sol;
        sol.solution(K, F, W);
    }

    return 0;
}

int Int() {
    int n;
    cin >> n;
    return n;
}
