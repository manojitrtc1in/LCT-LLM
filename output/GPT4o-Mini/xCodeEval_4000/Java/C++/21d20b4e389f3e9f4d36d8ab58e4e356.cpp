#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>

using namespace std;

const string IMPOSSIBLE = "IMPOSSIBLE";
const string POSSIBLE = "POSSIBLE";
const string YES = "YES";
const string NO = "NO";
const long MOD = 998244353;

class MyScanner {
    ifstream br;
public:
    MyScanner(const string& filename) : br(filename) {}
    
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
    
    string nextLine() {
        string str;
        getline(br, str);
        return str;
    }
    
    void close() {
        br.close();
    }
};

class MyPrintWriter {
    ofstream out;
public:
    MyPrintWriter(const string& filename) : out(filename) {}
    
    void println(long long ans) {
        out << ans << endl;
    }
    
    void println(int ans) {
        out << ans << endl;
    }
    
    void println(bool ans) {
        out << (ans ? YES : NO) << endl;
    }
    
    void close() {
        out.close();
    }
};

class RoundEdu132F {
    MyPrintWriter out;
    MyScanner in;
    int n, k, f;
    int ans;

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
        fft(a, false);
        for (size_t i = 0; i < a.size(); i++)
            a[i] = a[i] * a[i] % MOD;
        fft(a, true);
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
            for (size_t i = 0; i < a.size(); i++)
                a[i] = a[i] * inv % MOD;
        }
    }

    long long inverse(int a, long long p) {
        return pow(a, (int)(p - 2), p);
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

public:
    RoundEdu132F(const string& inputFile, const string& outputFile) 
        : in(inputFile), out(outputFile) {}

    void run() {
        bool hasMultipleTests = false;
        int t = hasMultipleTests ? in.nextInt() : 1;

        for (int i = 1; i <= t; ++i) {
            getInput();
            ans = solve();
            printOutput();
        }
        in.close();
        out.close();
    }
};

int main() {
    RoundEdu132F sol("input.txt", "output.txt");
    sol.run();
    return 0;
}
