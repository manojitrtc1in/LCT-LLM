#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cassert>
#include <climits>
#include <functional>
#include <numeric>
#include <complex>
#include <array>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define endl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

const int id32 = 1000000007;

class FastReader {
public:
    FastReader() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int nextInt() {
        int num = 0;
        char c;
        while ((c = getchar()) < '0' || c > '9');
        while (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            c = getchar();
        }
        return num;
    }

    long long nextLong() {
        long long num = 0;
        char c;
        while ((c = getchar()) < '0' || c > '9');
        while (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            c = getchar();
        }
        return num;
    }

    double nextDouble() {
        double num = 0;
        double div = 1;
        char c;
        while ((c = getchar()) < '0' || c > '9');
        while (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            c = getchar();
        }
        if (c == '.') {
            while ((c = getchar()) >= '0' && c <= '9') {
                num += (c - '0') / (div *= 10);
            }
        }
        return num;
    }

    char nextChar() {
        char c;
        while ((c = getchar()) == ' ' || c == '\n');
        return c;
    }

    string nextString() {
        string str;
        char c;
        while ((c = getchar()) == ' ' || c == '\n');
        do {
            str += c;
        } while ((c = getchar()) != ' ' && c != '\n');
        return str;
    }

    int* nextIntArray(int n) {
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nextInt();
        }
        return arr;
    }

    long long* nextLongArray(int n) {
        long long* arr = new long long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nextLong();
        }
        return arr;
    }

    double* nextDoubleArray(int n) {
        double* arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nextDouble();
        }
        return arr;
    }
};

class CFPS {
public:
    static FastReader fr;
    static int t;
    static double epsilon;
    static bool* isPrime;
    static int* id24;

    static void main() {
        int tc;
        cin >> tc;

        for (int i = 0; i < tc; i++) {
            int n, mod;
            cin >> n >> mod;

            long long* dp = new long long[n + 1];
            dp[n] = 1;

            for (int i = n - 1; i > 0; i--) {
                dp[i] += dp[i + 1];
                dp[i] %= mod;

                for (long long div = 1; div * i <= n; div++) {
                    int lb = div * i;
                    int ub = min(div * (i + 1) - 1, (long long)n);
                    long long segSum = dp[lb];
                    if (ub + 1 <= n) {
                        segSum -= dp[ub + 1];
                    }
                    dp[i] += segSum;
                    dp[i] %= mod;
                }

                dp[i] += dp[i + 1];
                dp[i] %= mod;
            }

            cout << (dp[1] - dp[2] + mod) % mod << endl;
        }
    }
};

FastReader CFPS::fr = FastReader();
int CFPS::t = 1;
double CFPS::epsilon = 0.00000001;
bool* CFPS::isPrime;
int* CFPS::id24;

int main() {
    CFPS::main();
    return 0;
}
