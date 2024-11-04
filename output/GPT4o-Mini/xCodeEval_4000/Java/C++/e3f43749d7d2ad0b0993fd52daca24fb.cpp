#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <random>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const string IMPOSSIBLE = "IMPOSSIBLE";
const string POSSIBLE = "POSSIBLE";
const string YES = "YES";
const string NO = "NO";
const long MOD = 998244353;
const int RADIX = 10;

class MyScanner {
    ifstream fin;
    stringstream ss;

public:
    MyScanner(istream &is) {
        ss.clear();
        ss.str("");
        fin.rdbuf(is.rdbuf());
    }

    void close() {
        fin.close();
    }

    string next() {
        string s;
        fin >> s;
        return s;
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

    vector<int> nextIntArray(int len) {
        vector<int> a(len);
        for (int j = 0; j < len; j++)
            a[j] = nextInt();
        return a;
    }

    vector<vector<int>> nextPairs(int n) {
        vector<vector<int>> xy(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
            xy[0][i] = nextInt();
            xy[1][i] = nextInt();
        }
        return xy;
    }
};

class MyPrintWriter {
    ostream &out;

public:
    MyPrintWriter(ostream &os) : out(os) {}

    void println(const string &s) {
        out << s << endl;
    }

    void printAns(const vector<long> &arr) {
        if (!arr.empty()) {
            out << arr[0];
            for (size_t i = 1; i < arr.size(); i++) {
                out << " " << arr[i];
            }
        }
    }

    void printlnAns(const vector<long> &arr) {
        printAns(arr);
        out << endl;
    }
};

class Round791F {
    MyPrintWriter out;
    MyScanner in;

public:
    Round791F(istream &is, ostream &os) : in(is), out(os) {}

    void run() {
        bool isDebug = false;
        bool isFileIO = false;
        bool hasMultipleTests = false;

        int t = hasMultipleTests ? in.nextInt() : 1;

        for (int i = 1; i <= t; ++i) {
            int n = in.nextInt();
            int m = in.nextInt();
            auto uv = in.nextPairs(m);
            vector<int> u = uv[0];
            vector<int> v = uv[1];

            if (isDebug) {
                out.println("Test " + to_string(i));
            }

            long ans = solve2(u, v, n);
            out.println(to_string(ans));

            if (isDebug)
                out.flush();
        }
    }

private:
    void validate(const vector<int> &u, const vector<int> &v, int n) {
        set<string> set;
        vector<vector<int>> cmp(RADIX, vector<int>(RADIX, 0));

        for (size_t i = 0; i < u.size(); i++) {
            int small = min(u[i], v[i]);
            int large = max(u[i], v[i]);
            cmp[small][large] = -1;
            cmp[large][small] = 1;
        }

        auto comp = [&cmp](char o1, char o2) {
            return cmp[o1 - '0'][o2 - '0'];
        };

        long long curr = 0;
        long long limit = pow(RADIX, n);
        string s;

        while (curr < limit) {
            s = to_string(curr);
            int padding = n - s.length();
            s.insert(s.begin(), padding, '0');
            vector<char> arr(s.begin(), s.end());
            sort(arr.begin(), arr.end(), comp);
            set.insert(string(arr.begin(), arr.end()));
            curr++;
        }

        out.println(to_string(set.size()));
        for (const auto &str : set) {
            out.println(str);
        }
    }

    long solve2(const vector<int> &u, const vector<int> &v, int n) {
        vector<long> dp(1 << RADIX, 0);
        for (int j = 0; j < RADIX; j++) {
            dp[1 << j] = 1;
        }

        vector<vector<int>> cmp(RADIX, vector<int>(RADIX, 0));
        int m = u.size();
        for (int i = 0; i < m; i++) {
            int small = min(u[i], v[i]);
            int larger = max(u[i], v[i]);
            cmp[small][larger] = -1;
            cmp[larger][small] = 1;
        }

        vector<vector<bool>> isValid(1 << RADIX, vector<bool>(RADIX, false));
        vector<vector<int>> map(1 << RADIX, vector<int>(RADIX, 0));

        for (int mask = 0; mask < (1 << RADIX); mask++) {
            for (int j = 0; j < RADIX; j++) {
                bool ok = true;
                int next = 1 << j;
                for (int k = 0; k < RADIX; k++) {
                    if ((1 << k & mask) == 0)
                        continue;

                    if (cmp[j][k] == 0) {
                    } else if (cmp[j][k] == -1) {
                        next |= 1 << k;
                    } else {
                        ok = false;
                    }
                }
                isValid[mask][j] = ok;
                map[mask][j] = next;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            vector<long> next(1 << RADIX, 0);
            for (int mask = 0; mask < (1 << RADIX); mask++) {
                for (int j = 0; j < RADIX; j++) {
                    if (!isValid[mask][j])
                        continue;
                    int mask2 = map[mask][j];
                    long val = next[mask2] + dp[mask];
                    next[mask2] = val < MOD ? val : val - MOD;
                }
            }
            dp = next;
        }

        long sum = 0;
        for (int mask = 0; mask < (1 << RADIX); mask++)
            sum += dp[mask];

        return sum % MOD;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Round791F sol(cin, cout);
    sol.run();
    return 0;
}
