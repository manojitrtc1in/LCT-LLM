#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <queue>
#include <set>
#include <numeric>
#include <cstring>

using namespace std;

class Item {
public:
    long w = 0;
    long val = 0;
    int group;

    Item(long w, long val, int group) : w(w), val(val), group(group) {}

    string toString() {
        return to_string(w) + "  " + to_string(val) + "   " + to_string(group) + "  \n";
    }
};

class Suffix {
public:
    int index;
    int rank;
    int next;

    Suffix(int i, int rank, int next) : index(i), rank(rank), next(next) {}

    bool operator<(const Suffix& other) const {
        if (this->rank == other.rank) {
            return this->next < other.next;
        }
        return this->rank < other.rank;
    }

    string toString() {
        return to_string(this->index) + "   " + to_string(this->rank) + "   " + to_string(this->next) + "  ";
    }
};

class Solution {
public:
    const int MAX = numeric_limits<int>::max();
    const int MIN = numeric_limits<int>::min();

    void solution(int K, long F[], int W) {
        long res = 0;
        int ten[] = {1, 10, 100, 1000, 10000, 100000};

        vector<Item> A;

        K--;

        if (K == 0) {
            string num = to_string(W);
            reverse(num.begin(), num.end());
            long score = 0;
            for (int k = 0; k < num.length(); k++) {
                int d = num[k] - '0';
                if (d % 3 == 0) {
                    score += (F[k] * (d / 3));
                }
            }
            msg(to_string(score));
            return;
        }

        for (int i = 0; i < 6; i++) {
            long weight = ten[i] * 3;
            int cur = 0;
            for (int j = 0; j < 32; j++) {
                int go = 1 << j;
                if (cur + go >= (3 * K)) {
                    long remain = 3 * K - cur;
                    Item item(weight * remain, F[i] * remain, i);
                    A.push_back(item);
                    break;
                }
                Item item(weight * (1 << j), F[i] * (1 << j), i);
                cur += (1 << j);
                A.push_back(item);
            }
        }

        vector<long> pre(W + 1, -1);
        vector<long> dp(W + 1, -1);
        pre[0] = 0;

        for (int i = 1; i < A.size(); i++) {
            Item item = A[i - 1];
            dp.assign(W + 1, -1);
            dp[0] = 0;
            for (int j = 1; j < dp.size(); j++) {
                dp[j] = max(dp[j], pre[j]);
                long w = item.w;
                long val = item.val;
                if (j < w || pre[j - w] == -1) {
                    continue;
                }
                dp[j] = max(dp[j], pre[j - w] + val);
                string num = to_string(W - j);
                reverse(num.begin(), num.end());
                long score = 0;
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

        msg(to_string(res));
    }

    void msg(const string& s) {
        cout << s << endl;
    }

    // Other methods from the original Java code can be translated similarly...
};

int main() {
    int T = 1;
    for (int t = 0; t < T; t++) {
        int K;
        cin >> K;
        long F[6];
        for (int i = 0; i < 6; i++) {
            cin >> F[i];
        }

        int q, W;
        cin >> q >> W;

        Solution sol;
        sol.solution(K, F, W);
    }
    return 0;
}
