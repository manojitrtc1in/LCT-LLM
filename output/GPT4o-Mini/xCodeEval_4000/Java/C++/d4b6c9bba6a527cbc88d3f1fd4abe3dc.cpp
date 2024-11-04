#include <bits/stdc++.h>
using namespace std;

const string IMPOSSIBLE = "IMPOSSIBLE";
const string POSSIBLE = "POSSIBLE";
const string YES = "YES";
const string NO = "NO";
const long MOD = 998244353;

class MyScanner {
    ifstream br;
public:
    MyScanner(const string& filename) {
        br.open(filename);
    }

    int nextInt() {
        int x;
        br >> x;
        return x;
    }

    long long nextLong() {
        long long x;
        br >> x;
        return x;
    }

    void close() {
        br.close();
    }
};

class MyPrintWriter {
    ofstream out;
public:
    MyPrintWriter(const string& filename) {
        out.open(filename);
    }

    void println(long long ans) {
        out << ans << endl;
    }

    void println(int ans) {
        out << ans << endl;
    }

    void close() {
        out.close();
    }
};

class RoundEdu132F {
    MyPrintWriter out;
    MyScanner in;
    int n, k, f, ans;

public:
    RoundEdu132F(bool isFileIO) : out(isFileIO ? "output.txt" : ""), in(isFileIO ? "input.txt" : "") {}

    void getInput() {
        n = in.nextInt();
        k = in.nextInt();
        f = in.nextInt();
    }

    void printOutput() {
        out.println(ans);
    }

    int solve() {
        long long ans = 0;
        int len = 1;
        while (len < f + 2 + f + 2) 
            len <<= 1;
        vector<long long> ways(len), suffix(f + 2);

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
                fill(ways.begin() + f + 2, ways.end(), 0);
            } else {
                for (int j = 0; j <= f; j++)
                    ans += ways[j] * ways[f - j] % MOD;
                ans %= MOD;
            }
        }

        return (int)ans;
    }

    void square(vector<long long>& a) {
        fft4(a, false);
        for (int i = 0; i < a.size(); i++)
            a[i] = a[i] * a[i] % MOD;
        fft4(a, true);
    }

    void fft(vector<long long>& a, bool isInvertedFFT) {
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
            long long wlen = isInvertedFFT ? ROOT_INV : ROOT;
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

        if (isInvertedFFT) {
            long long inv = inverse(n, MOD);
            for (int i = 0; i < a.size(); i++)
                a[i] = a[i] * inv % MOD;
        }
    }

    long long pow(int a, int k, long p) {
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

    long long inverse(int a, long p) {
        return pow(a, (int)(p - 2), p);
    }

    void run() {
        bool isDebug = false;
        bool hasMultipleTests = false;

        int t = hasMultipleTests ? in.nextInt() : 1;

        for (int i = 1; i <= t; ++i) {
            if (isDebug) {
                out.println("Test " + to_string(i));
            }

            getInput();
            ans = solve();
            printOutput();
        }

        in.close();
        out.close();
    }

    static const int ROOT = (int)pow(3, 7 * 17, MOD);
    static const int ROOT_INV = (int)pow(ROOT, (int)MOD - 2, MOD);
    static const int ORDER = 1 << 23;

    static void fft4(vector<long long>& a, bool isInvertedFFT) {
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

        int parity = 0;
        for (int len = 2; len <= n; len <<= 1)
            parity++;

        int len;
        if (parity % 2 == 1) {
            len = 2;
            if (len <= n) {
                long wlen = isInvertedFFT ? ROOT_INV : ROOT;
                for (int i = len; i < ORDER; i <<= 1)
                    wlen = wlen * wlen % MOD;

                for (int i = 0; i < n; i += len) {
                    long w = 1;
                    for (int j = 0; j < len / 2; j++) {
                        long x0 = a[i + j];
                        long x1 = a[i + j + len / 2] * w % MOD;
                        a[i + j] = (x0 + x1) % MOD;
                        a[i + j + len / 2] = (x0 - x1 + MOD) % MOD;
                        w = w * wlen % MOD;
                    }
                }
                len *= 4;
            }
        } else {
            len = 4;
        }

        for (; len <= n; len <<= 2) {
            long wlen = isInvertedFFT ? ROOT_INV : ROOT;
            long w4 = isInvertedFFT ? W4_INV : W4;
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

                    long y0 = (x0 + x1 + x2 + x3) % MOD;
                    a[i + j] = y0;
                    long y1 = (x0 + x1 * w4 - x2 - x3 * w4) % MOD;
                    a[i + j + len * 3 / 4] = (y1 + MOD) % MOD;
                    long y2 = (x0 - x1 + x2 - x3) % MOD;
                    a[i + j + len / 2] = (y2 + MOD) % MOD;
                    long y3 = (x0 - x1 * w4 - x2 + x3 * w4) % MOD;
                    a[i + j + len / 4] = (y3 + MOD) % MOD;

                    w = w * wlen % MOD;
                }
            }
        }

        if (isInvertedFFT) {
            long inv = inverse(n, MOD);
            for (int i = 0; i < a.size(); i++)
                a[i] = a[i] * inv % MOD;
        }
    }
};

int main() {
    RoundEdu132F sol(true);
    sol.run();
    return 0;
}
