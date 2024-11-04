#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>
#include <list>

using namespace std;

class IO {
public:
    IO() {}

    string next() {
        string input;
        cin >> input;
        return input;
    }

    int nextInt() {
        int ret;
        cin >> ret;
        return ret;
    }

    long long nextLong() {
        long long ret;
        cin >> ret;
        return ret;
    }

    double nextDouble() {
        double ret;
        cin >> ret;
        return ret;
    }

    void println(const string &output) {
        cout << output << endl;
    }

    void close() {
        // No explicit close needed in C++
    }
};

class Solver {
    IO io;

public:
    Solver() {
        try {
            solve();
        } catch (const runtime_error &e) {
            if (e.what() != string("Clean exit")) {
                throw;
            }
        }
    }

    void solve() {
        long long n = io.nextLong();
        long long m = io.nextLong();
        if (m < n) {
            swap(m, n);
        }

        if (n == 1) {
            io.println(brute1(m));
            return;
        }
        if (n == 2) {
            if (m < 3) io.println(0);
            else if (m == 3) io.println(4);
            else if (m == 7) io.println(12);
            else io.println(2 * m);
            return;
        }

        io.println(2 * (n * m / 2));
    }

    long long brute1(long long m) {
        long long ans = 6 * (m / 6);
        if (m % 6 == 5) ans += 4;
        else if (m % 6 == 4) ans += 2;
        return ans;
    }

    long long MOD = 1e9 + 7;

    bool closeToZero(double v) {
        return abs(v) <= 1e-10;
    }

    // Other classes and methods can be translated similarly...
};

int main() {
    Solver solver;
    return 0;
}
