#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <sstream>

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

    void println(const string& output) {
        cout << output << endl;
    }

    void close() {
        // No specific close operation needed for cin/cout
    }
};

class Solver {
    IO io;

public:
    Solver() {
        try {
            solve();
        } catch (runtime_error& e) {
            if (e.what() != string("Clean exit")) {
                throw;
            }
        } finally {
            io.close();
        }
    }

    void solve() {
        long long n = io.nextLong();
        long long m = io.nextLong();
        if (m < n) {
            swap(m, n);
        }

        if (n == 1) {
            io.println(id17(m));
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

    long long id17(long long m) {
        long long ans = 6 * (m / 6);
        if (m % 6 == 5) ans += 4;
        else if (m % 6 == 4) ans += 2;
        return ans;
    }

    long long MOD = 1000000007;

    bool id11(double v) {
        return abs(v) <= 1e-10;
    }

    // Other classes and methods omitted for brevity...

    void done() {
        io.close();
        throw runtime_error("Clean exit");
    }

    long long min(long long... v) {
        long long ans = v[0];
        for (int i = 1; i < sizeof(v) / sizeof(v[0]); i++) {
            ans = std::min(ans, v[i]);
        }
        return ans;
    }

    double min(double... v) {
        double ans = v[0];
        for (int i = 1; i < sizeof(v) / sizeof(v[0]); i++) {
            ans = std::min(ans, v[i]);
        }
        return ans;
    }

    int min(int... v) {
        int ans = v[0];
        for (int i = 1; i < sizeof(v) / sizeof(v[0]); i++) {
            ans = std::min(ans, v[i]);
        }
        return ans;
    }

    long long max(long long... v) {
        long long ans = v[0];
        for (int i = 1; i < sizeof(v) / sizeof(v[0]); i++) {
            ans = std::max(ans, v[i]);
        }
        return ans;
    }

    double max(double... v) {
        double ans = v[0];
        for (int i = 1; i < sizeof(v) / sizeof(v[0]); i++) {
            ans = std::max(ans, v[i]);
        }
        return ans;
    }

    int max(int... v) {
        int ans = v[0];
        for (int i = 1; i < sizeof(v) / sizeof(v[0]); i++) {
            ans = std::max(ans, v[i]);
        }
        return ans;
    }
};

int main() {
    Solver solver;
    return 0;
}
