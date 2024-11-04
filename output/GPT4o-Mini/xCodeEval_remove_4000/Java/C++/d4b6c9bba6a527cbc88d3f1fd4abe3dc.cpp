#include <bits/stdc++.h>
using namespace std;

const long MOD = 998244353;
const string YES = "YES";
const string NO = "NO";

class MyScanner {
    ifstream br;
    stringstream st;

public:
    MyScanner(const string& filename) {
        br.open(filename);
    }

    MyScanner() {
        br.clear();
        br.str("");
    }

    void close() {
        br.close();
    }

    string next() {
        while (!st.good() || !st.good()) {
            string line;
            getline(br, line);
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

    void id6(int n, int offset, vector<vector<int>>& e) {
        for (int i = 0; i < n - 1; i++) {
            e[i][0] = nextInt() + offset;
            e[i][1] = nextInt() + offset;
        }
    }

    void nextMatrix(int n, int m, vector<vector<int>>& mat, int offset = 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = nextInt() + offset;
            }
        }
    }

    void nextPairs(int n, vector<vector<int>>& xy, int offset = 0) {
        for (int i = 0; i < n; i++) {
            xy[0][i] = nextInt() + offset;
            xy[1][i] = nextInt() + offset;
        }
    }

    void id10(vector<vector<int>>& e, int offset = 0) {
        int m = nextInt();
        e.resize(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            e[i][0] = nextInt() + offset;
            e[i][1] = nextInt() + offset;
        }
    }

    void id7(int len, vector<int>& a, int offset = 0) {
        for (int j = 0; j < len; j++)
            a[j] = nextInt() + offset;
    }

    void id16(int len, vector<long long>& a, int offset = 0) {
        for (int j = 0; j < len; j++)
            a[j] = nextLong() + offset;
    }
};

class id5 {
    ofstream out;

public:
    id5(const string& filename) {
        out.open(filename);
    }

    void printlnAns(long long ans) {
        out << ans << endl;
    }

    void printlnAns(int ans) {
        out << ans << endl;
    }

    void printlnAns(bool ans) {
        out << (ans ? YES : NO) << endl;
    }

    void printAns(const vector<long long>& arr) {
        if (!arr.empty()) {
            out << arr[0];
            for (size_t i = 1; i < arr.size(); i++) {
                out << " " << arr[i];
            }
        }
    }

    void printlnAns(const vector<long long>& arr) {
        printAns(arr);
        out << endl;
    }

    void printAns(const vector<int>& arr) {
        if (!arr.empty()) {
            out << arr[0];
            for (size_t i = 1; i < arr.size(); i++) {
                out << " " << arr[i];
            }
        }
    }

    void printlnAns(const vector<int>& arr) {
        printAns(arr);
        out << endl;
    }

    void close() {
        out.close();
    }
};

class id4 {
    id5 out;
    MyScanner in;
    int n, k, f;
    int ans;

    void initIO(bool id8) {
        if (getenv("ONLINE_JUDGE") == nullptr && id8) {
            in = MyScanner("input.txt");
            out = id5("output.txt");
        } else {
            in = MyScanner();
            out = id5(cout);
        }
    }

public:
    id4() : out("output.txt"), in("input.txt") {}

    void run() {
        bool isDebug = false;
        bool id8 = true;
        bool id2 = false;

        initIO(id8);

        int t = id2 ? in.nextInt() : 1;

        for (int i = 1; i <= t; ++i) {
            if (isDebug) {
                out.printlnAns("Test " + to_string(i));
            }

            getInput();
            ans = solve();
            printOutput();
        }

        in.close();
        out.close();
    }

    void getInput() {
        n = in.nextInt();
        k = in.nextInt();
        f = in.nextInt();
    }

    void printOutput() {
        out.printlnAns(ans);
    }

    int solve() {
        long ans = 0;
        int len = 1;
        while (len < f + 2 + f + 2)
            len <<= 1;
        vector<long> ways(len);
        vector<long> suffix(f + 2);

        for (int i = 0; i <= k && i <= f; i++)
            ways[i] = 1;
        ways[f + 1] = max(0LL, k - f);

        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                square(ways);
                long val = 0;
                for (int j = ways.size() - 1; j >= f + 1; j--)
                    val += ways[j];
                val %= MOD;
                suffix[f + 1] = val;

                for (int j = f; j >= 0; j--) {
                    long val = suffix[j + 1] + ways[j];
                    val = val >= MOD ? val - MOD : val;
                    suffix[j] = val;
                }

                for (int j = 0; j <= k && j <= f; j++) {
                    long val = suffix[j];
                    val += ways[j] * (k - j);
                    val %= MOD;
                    ways[j] = val;
                }
                long val = suffix[f + 1] * max(0LL, k - f);
                val %= MOD;
                ways[f + 1] = val;
                fill(ways.begin() + f + 2, ways.end(), 0);
            } else {
                for (int j = 0; j <= f; j++)
                    ans += ways[j] * ways[f - j] % MOD;
                ans %= MOD;
            }
        }

        return (int)ans;
    }

    static long pow(int a, int k, long p) {
        long m = k;
        long ans = 1;
        long curr = a;

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

    static long inverse(int a, long p) {
        return pow(a, (int)(p - 2), p);
    }

    static const int ROOT = (int)pow(3, 7 * 17, MOD);
    static const int ROOT_INV = (int)pow(ROOT, (int)MOD - 2, MOD);
    static const int ORDER = 1 << 23;
    static const long W4 = pow(ROOT, (int)(MOD - 1) / 4, MOD);
    static const long id15 = pow(ROOT, (int)(MOD - 1) / 4 * 3, MOD);

    static void swap(vector<long>& a, int i, int j) {
        long temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    static void fft(vector<long>& a, bool id0) {
        int n = a.size();

        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; (j & bit) > 0; bit >>= 1)
                j ^= bit;
            j ^= bit;

            if (i < j) {
                swap(a, i, j);
            }
        }

        for (int len = 2; len <= n; len <<= 1) {
            long wlen = id0 ? ROOT_INV : ROOT;
            for (int i = len; i < ORDER; i <<= 1)
                wlen = wlen * wlen % MOD;

            for (int i = 0; i < n; i += len) {
                long w = 1;
                for (int j = 0; j < len / 2; j++) {
                    long u = a[i + j];
                    long v = a[i + j + len / 2] * w % MOD;
                    a[i + j] = u + v < MOD ? u + v : u + v - MOD;
                    a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
                    w = w * wlen % MOD;
                }
            }
        }

        if (id0) {
            long inv = inverse(n, MOD);
            for (int i = 0; i < a.size(); i++)
                a[i] = a[i] * inv % MOD;
        }
    }

    static void fft4(vector<long>& a, bool id0) {
        int n = a.size();

        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; (j & bit) > 0; bit >>= 1)
                j ^= bit;
            j ^= bit;

            if (i < j) {
                swap(a, i, j);
            }
        }

        int parity = 0;
        for (int len = 2; len <= n; len <<= 1)
            parity++;

        int len;
        if (parity % 2 == 1) {
            len = 2;
            if (len <= n) {
                long wlen = id0 ? ROOT_INV : ROOT;
                for (int i = len; i < ORDER; i <<= 1)
                    wlen = wlen * wlen % MOD;

                for (int i = 0; i < n; i += len) {
                    long w = 1;
                    for (int j = 0; j < len / 2; j++) {
                        long x0 = a[i + j];
                        long x1 = a[i + j + len / 2] * w % MOD;
                        long y0 = x0 + x1;
                        a[i + j] = y0 % MOD;
                        long y1 = x0 - x1;
                        a[i + j + len / 2] = y1 < 0 ? y1 + MOD : y1;
                        w = w * wlen % MOD;
                    }
                }
                len *= 4;
            }
        } else
            len = 4;

        for (; len <= n; len <<= 2) {
            long wlen = id0 ? ROOT_INV : ROOT;
            long w4 = id0 ? id15 : W4;
            for (int i = len; i < ORDER; i <<= 1)
                wlen = wlen * wlen % MOD;

            for (int i = 0; i < n; i += len) {
                long w = 1;
                for (int j = 0; j < len / 4; j++) {
                    long x0 = a[i + j];
                    long x1 = a[i + j + len / 2] * w % MOD;
                    long x2 = a[i + j + len / 4] * w % MOD;
                    x2 = x2 * w % MOD;
                    long x3 = a[i + j + len * 3 / 4] * w % MOD;
                    x3 = x3 * w % MOD;
                    x3 = x3 * w % MOD;

                    long y0 = x0 + x1 + x2 + x3;
                    a[i + j] = y0 % MOD;
                    long y1 = x0 + x1 * w4 - x2 - x3 * w4;
                    y1 %= MOD;
                    a[i + j + len * 3 / 4] = y1 < 0 ? y1 + MOD : y1;
                    long y2 = x0 - x1 + x2 - x3;
                    y2 %= MOD;
                    a[i + j + len / 2] = y2 < 0 ? y2 + MOD : y2;
                    long y3 = x0 - x1 * w4 - x2 + x3 * w4;
                    y3 %= MOD;
                    a[i + j + len / 4] = y3 < 0 ? y3 + MOD : y3;

                    w = w * wlen % MOD;
                }
            }
        }

        if (id0) {
            long inv = inverse(n, MOD);
            for (int i = 0; i < a.size(); i++)
                a[i] = a[i] * inv % MOD;
        }
    }

    static void square(vector<long>& a) {
        fft4(a, false);
        for (int i = 0; i < a.size(); i++)
            a[i] = a[i] * a[i] % MOD;
        fft4(a, true);
    }

    static vector<long> multiplyPolynomial(const vector<long>& a, const vector<long>& b) {
        int n = 1;
        while (n < a.size() + b.size())
            n <<= 1;
        vector<long> fa = a;
        vector<long> fb = b;

        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < n; i++)
            fa[i] = fa[i] * fb[i] % MOD;
        fft(fa, true);

        return fa;
    }
};

int main() {
    id4 sol;
    sol.run();
    return 0;
}
