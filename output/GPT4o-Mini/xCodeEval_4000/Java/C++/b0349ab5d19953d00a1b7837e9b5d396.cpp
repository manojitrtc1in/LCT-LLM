#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
#include <numeric>
#include <bitset>
#include <tuple>
#include <functional>
#include <limits>
#include <random>
#include <iomanip>
#include <sstream>
#include <utility>
#include <complex>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class ProblemC_76 {
    
    bool ONLINE_JUDGE = (getenv("ONLINE_JUDGE") != nullptr);
    ifstream in;
    ofstream out;
    stringstream tok;

    void init() {
        if (ONLINE_JUDGE) {
            in.open("/dev/stdin");
            out.open("/dev/stdout");
        } else {
            in.open("input.txt");
            out.open("output.txt");
        }
    }

    string readString() {
        string s;
        while (!(tok >> s)) {
            getline(in, s);
            tok.clear();
            tok.str(s);
        }
        return s;
    }

    int readInt() {
        return stoi(readString());
    }

    long long readLong() {
        return stoll(readString());
    }

    double readDouble() {
        return stod(readString());
    }

public:
    static const int MAXN = 1000000;
    
    void run() {
        try {
            clock_t t1 = clock();
            init();
            solve();
            out.close();
            clock_t t2 = clock();
            cerr << "Time = " << (double)(t2 - t1) / CLOCKS_PER_SEC << endl;
        } catch (exception& e) {
            cerr << e.what() << endl;
            exit(-1);
        }
    }

    void solve() {
        int n = readInt() - 1;
        int m = readInt();
        int a = readInt() - 1;
        int b = readInt() - 1;
        int i = a / m;
        int j = b / m;
        int l = a % m;
        int r = (b == n ? m - 1 : b % m);
        
        if (l == 0 && r == m - 1) {
            out << 1;
            return;
        }
        if (j - i < 2) {
            out << j - i + 1;
            return;
        }
        if ((l != 0 && r == m - 1) || (l == 0 && r != m - 1)) {
            out << 2;
            return;
        }
        if (l - r == 1) {
            out << 2;
            return;
        }
        out << 3;
    }

    static long long gcd(long long a, long long b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    static long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    static long long binpow(long long a, int n) {
        if (n == 0) return 1;
        if ((n & 1) == 0) {
            long long b = binpow(a, n / 2);
            return b * b;
        } else return binpow(a, n - 1) * a;
    }

    static long long binpowmod(long long a, int n, long long m) {
        if (m == 1) return 0;
        if (n == 0) return 1;
        if ((n & 1) == 0) {
            long long b = binpowmod(a, n / 2, m);
            return (b * b) % m;
        } else return binpowmod(a, n - 1, m) * a % m;
    }

    static vector<int> Sieve(int n) {
        vector<bool> b(n + 1, true);
        b[0] = b[1] = false;
        long long nLong = n;
        int j = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i]) {
                j++;
                if ((long long)i * i <= nLong) {
                    for (int k = i * i; k <= n; k += i) {
                        b[k] = false;
                    }
                }
            }
        }
        vector<int> p;
        for (int i = 2; i <= n; i++) {
            if (b[i]) {
                p.push_back(i);
            }
        }
        return p;
    }
};

int main() {
    ProblemC_76().run();
    return 0;
}
