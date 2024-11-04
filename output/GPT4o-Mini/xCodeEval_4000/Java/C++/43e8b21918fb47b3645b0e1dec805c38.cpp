#include <bits/stdc++.h>
using namespace std;

const int gigamod = 1000000007;
int t = 1;
double epsilon = 0.00000001;
vector<bool> isPrime;
vector<int> smallestFactorOf;

class FastReader {
    ifstream bfr;
    stringstream st;
public:
    FastReader() {
        bfr.open("input.txt");
    }

    string next() {
        if (st.eof() || !st.good()) {
            string line;
            getline(bfr, line);
            st.clear();
            st.str(line);
        }
        string token;
        st >> token;
        return token;
    }

    int nextInt() {
        return stoi(next());
    }

    long long nextLong() {
        return stoll(next());
    }

    double nextDouble() {
        return stod(next());
    }

    char nextChar() {
        return next()[0];
    }

    vector<int> nextIntArray(int n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = nextInt();
        return arr;
    }

    vector<long long> nextLongArray(int n) {
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = nextLong();
        return arr;
    }
};

int main() {
    FastReader fr;

    for (int tc = 0; tc < t; tc++) {
        int n = fr.nextInt();
        long long mod = fr.nextLong();

        vector<long long> dp(n + 1);
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

vector<vector<long long>> sparseTable(const vector<long long>& a) {
    int n = a.size();
    int b = 32 - __builtin_clz(n);
    vector<vector<long long>> ret(b);
    for (int i = 0, l = 1; i < b; i++, l *= 2) {
        if (i == 0) {
            ret[i] = a;
        } else {
            ret[i].resize(n - l + 1);
            for (int j = 0; j < n - l + 1; j++) {
                ret[i][j] = min(ret[i - 1][j], ret[i - 1][j + l / 2]);
            }
        }
    }
    return ret;
}

long long sparseRMQ(const vector<vector<long long>>& table, int l, int r) {
    assert(l <= r);
    if (l >= r) return LLONG_MAX;

    int t = 31 - __builtin_clz(r - l);
    return min(table[t][l], table[t][r - (1 << t)]);
}

class Point {
public:
    long long x, y, z, id;

    Point() : x(0), y(0), z(0), id(0) {}

    Point(long long x, long long y, long long z, long long id) : x(x), y(y), z(z), id(id) {}

    bool operator<(const Point& o) const {
        if (x != o.x) return x < o.x;
        if (y != o.y) return y < o.y;
        return z < o.z;
    }

    bool operator==(const Point& that) const {
        return *this < that == false && that < *this == false;
    }
};

// Additional classes and methods would follow the same pattern as above...

