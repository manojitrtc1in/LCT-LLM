#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <random>
#include <cassert>
#include <iomanip>
#include <limits>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

const int id32 = 1000000007;
const double epsilon = 0.00000001;
vector<bool> isPrime;
vector<int> id24;

class FastReader {
public:
    FastReader() {}

    string next() {
        string s;
        cin >> s;
        return s;
    }

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }

    long long nextLong() {
        long long x;
        cin >> x;
        return x;
    }

    double nextDouble() {
        double x;
        cin >> x;
        return x;
    }

    char nextChar() {
        char c;
        cin >> c;
        return c;
    }

    vector<int> id15(int n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = nextInt();
        return arr;
    }

    vector<long long> id42(int n) {
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = nextLong();
        return arr;
    }
};

class Edge {
public:
    int from, to;
    long long weight;
    int id;

    Edge(int fro, int t, long long weigh, int i) : from(fro), to(t), weight(weigh), id(i) {}

    bool operator<(const Edge& that) const {
        return id < that.id;
    }
};

long long dp[100005];

int main() {
    FastReader fr;
    int t = 1;

    for (int tc = 0; tc < t; tc++) {
        int n = fr.nextInt();
        long long mod = fr.nextLong();

        fill(dp, dp + n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i > 0; i--) {
            dp[i] += dp[i + 1];
            dp[i] %= mod;

            for (long long div = 1; div * i <= n; div++) {
                int lb = div * i;
                int ub = min(div * (i + 1) - 1, n);
                long long segSum = dp[lb];
                if (ub + 1 <= n)
                    segSum -= dp[ub + 1];
                dp[i] += segSum;
                dp[i] %= mod;
            }

            dp[i] += dp[i + 1];
            dp[i] %= mod;
        }

        cout << (dp[1] - dp[2] + mod) % mod << endl;
    }

    return 0;
}
