#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <iomanip>
#include <algorithm>

using namespace std;

class MyScanner {
    ifstream br;
    stringstream st;

public:
    MyScanner(const string &filename) {
        br.open(filename);
    }

    MyScanner() {
        br.clear();
        br.rdbuf(cin.rdbuf());
    }

    void close() {
        br.close();
    }

    string next() {
        string token;
        while (!(st >> token)) {
            string line;
            getline(br, line);
            st.clear();
            st.str(line);
        }
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

    void nextMatrix(int n, int m, vector<vector<int>> &mat, int offset = 0) {
        mat.resize(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = nextInt() + offset;
            }
        }
    }

    void nextPairs(int n, vector<pair<int, int>> &pairs, int offset = 0) {
        pairs.resize(n);
        for (int i = 0; i < n; i++) {
            pairs[i].first = nextInt() + offset;
            pairs[i].second = nextInt() + offset;
        }
    }
};

class id5 {
    ostream &os;

public:
    id5(ostream &output) : os(output) {}

    void printlnAns(long long ans) {
        os << ans << endl;
    }

    void printlnAns(int ans) {
        os << ans << endl;
    }

    void printlnAns(bool ans) {
        os << (ans ? "YES" : "NO") << endl;
    }

    void printAns(const vector<long long> &arr) {
        if (!arr.empty()) {
            os << arr[0];
            for (size_t i = 1; i < arr.size(); i++) {
                os << " " << arr[i];
            }
        }
    }

    void printlnAns(const vector<long long> &arr) {
        printAns(arr);
        os << endl;
    }

    void printAns(const vector<int> &arr) {
        if (!arr.empty()) {
            os << arr[0];
            for (size_t i = 1; i < arr.size(); i++) {
                os << " " << arr[i];
            }
        }
    }

    void printlnAns(const vector<int> &arr) {
        printAns(arr);
        os << endl;
    }
};

class id4 {
    id5 out;
    MyScanner in;
    static const long long MOD = 998244353;
    int ans;

public:
    id4(bool id8) : out(cout), in(id8 ? "input.txt" : "") {}

    void run() {
        int t = 1;

        for (int i = 1; i <= t; ++i) {
            getInput();
            ans = solve();
            printOutput();
        }
    }

private:
    int n, k, f;

    void getInput() {
        n = in.nextInt();
        k = in.nextInt();
        f = in.nextInt();
    }

    void printOutput() {
        out.printlnAns(ans);
    }

    int solve() {
        long long ans = 0;
        int len = 1;
        while (len < f + 2 + f + 2)
            len <<= 1;
        vector<long long> ways(len, 0);
        vector<long long> suffix(f + 2, 0);

        for (int i = 0; i <= k && i <= f; i++)
            ways[i] = 1;
        ways[f + 1] = max(0LL, k - f);

        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                square(ways);
                long long val = 0;
                for (int j = ways.size() - 1; j >= f + 1; j--)
                    val += ways[j];
                val %= MOD;
                suffix[f + 1] = val;

                for (int j = f; j >= 0; j--) {
                    long long val = suffix[j + 1] + ways[j];
                    val = val >= MOD ? val - MOD : val;
                    suffix[j] = val;
                }

                for (int j = 0; j <= k && j <= f; j++) {
                    long long val = suffix[j];
                    val += ways[j] * (k - j);
                    val %= MOD;
                    ways[j] = val;
                }
                long long val = suffix[f + 1] * max(0LL, k - f);
                val %= MOD;
                ways[f + 1] = val;
                fill(ways.begin() + k + 1, ways.begin() + f + 2, 0);
                fill(ways.begin() + f + 2, ways.end(), 0);
            } else {
                for (int j = 0; j <= f; j++)
                    ans += ways[j] * ways[f - j] % MOD;
                ans %= MOD;
            }
        }

        return static_cast<int>(ans);
    }

    void square(vector<long long> &a) {
        fft(a, false);
        for (size_t i = 0; i < a.size(); i++)
            a[i] = a[i] * a[i] % MOD;
        fft(a, true);
    }

    void fft(vector<long long> &a, bool id0) {
        int n = a.size();
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; (j & bit) > 0; bit >>= 1)
                j ^= bit;
            j ^= bit;

            if (i < j) {
                swap(a[i], a[j]);
            }
        }

        for (int len = 2; len <= n; len <<= 1) {
            long long wlen = id0 ? ROOT_INV : ROOT;
            for (int i = len; i < ORDER; i <<= 1)
                wlen = wlen * wlen % MOD;

            for (int i = 0; i < n; i += len) {
                long long w = 1;
                for (int j = 0; j < len / 2; j++) {
                    long long u = a[i + j];
                    long long v = a[i + j + len / 2] * w % MOD;
                    a[i + j] = (u + v < MOD) ? u + v : u + v - MOD;
                    a[i + j + len / 2] = (u - v >= 0) ? u - v : u - v + MOD;
                    w = w * wlen % MOD;
                }
            }
        }

        if (id0) {
            long long inv = inverse(n, MOD);
            for (size_t i = 0; i < a.size(); i++)
                a[i] = a[i] * inv % MOD;
        }
    }

    static long long pow(int a, int k, long long p) {
        long long m = k;
        long long ans = 1;
        long long curr = a;

        while (m > 0) {
            if ((m & 1) == 1) {
                ans *= curr;
                ans %= p;
            }
            m >>= 1;
            curr *= curr;
            curr %= p;
        }
        return ans;
    }

    static long long inverse(int a, long long p) {
        return pow(a, static_cast<int>(p - 2), p);
    }

    static const int ROOT = static_cast<int>(pow(3, 7 * 17, MOD));
    static const int ROOT_INV = static_cast<int>(pow(ROOT, static_cast<int>(MOD) - 2, MOD));
    static const int ORDER = 1 << 23;
};

int main(int argc, char *argv[]) {
    bool id8 = true;
    id4 sol(id8);
    sol.run();
    return 0;
}
