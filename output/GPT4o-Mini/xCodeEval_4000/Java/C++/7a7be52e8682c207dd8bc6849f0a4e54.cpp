#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <random>
#include <string>
#include <sstream>
#include <fstream>
#include <numeric>

using namespace std;

class F {
    int mod = 1000000007;
    int x;
    vector<int> b;

public:
    long pow(long x, long p, long mod) {
        if (p <= 0) {
            return 1;
        }
        long th = pow(x, p / 2, mod);
        th = (th * th) % mod;
        if (p % 2 == 1) {
            th = (th * x) % mod;
        }
        return th;
    }

    class Fraction {
    public:
        long x;
        long y;

        Fraction(long x, long y) : x(x), y(y) {}

        void norm() {
            long gcd = F::gcd(x, y);
            x /= gcd;
            y /= gcd;
        }

        bool operator<(const Fraction& o) const {
            if (x != o.x) return x < o.x;
            return y < o.y;
        }
    };

    static long gcd(long x, long y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }

    Fraction sum(Fraction a, Fraction b) {
        Fraction c(a.x * b.y + a.y * b.x, a.y * b.y);
        c.norm();
        return c;
    }

    long mult(long x, long y) {
        return (x * y) % mod;
    }

    long div(long x, long y) {
        return mult(x, modInv(y));
    }

    long modInv(long x) {
        return pow(x, mod - 2);
    }

    vector<int> rev(const vector<int>& a) {
        vector<int> res(a.size());
        for (int i = 0; i < a.size(); ++i) {
            res[a[i]] = i;
        }
        return res;
    }

    bool mergeSort(const string& s, vector<int>& a, int l, int r) {
        if (r - l <= 1) {
            return true;
        }
        int m = (l + r) >> 1;
        if (!mergeSort(s, a, l, m)) {
            return false;
        }
        if (!mergeSort(s, a, m, r)) {
            return false;
        }
        int i = l;
        int j = m;
        int k = l;
        while (i < m && j < r) {
            if (x == s.length()) {
                return false;
            }
            if (s[x++] == '0') {
                b[k++] = a[i++];
            } else {
                b[k++] = a[j++];
            }
        }
        while (i < m) {
            b[k++] = a[i++];
        }
        while (j < r) {
            b[k++] = a[j++];
        }
        for (int p = l; p < r; p++) {
            a[p] = b[p];
        }
        return true;
    }

    void solve() {
        string s;
        cin >> s;
        int l = 0;
        int r = 100001;
        while (true) {
            int sz = (l + r) >> 1;
            vector<int> a(sz);
            iota(a.begin(), a.end(), 0);
            x = 0;
            b.resize(sz);
            if (!mergeSort(s, a, 0, sz)) {
                r = sz;
                continue;
            }
            if (x < s.length()) {
                l = sz;
                continue;
            }
            a = rev(a);
            cout << sz << endl;
            for (int i : a) {
                cout << i + 1 << " ";
            }
            return;
        }
    }

    void run() {
        solve();
    }
};

int main() {
    F().run();
    return 0;
}
