#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using namespace std;

class IO {
public:
    template<typename T>
    void print(T output) {
        cout << output << endl;
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
};

class Solver {
    IO io;

public:
    Solver() {
        try {
            solve();
        } catch (runtime_error& e) {
            if (string(e.what()) != "Clean exit") {
                throw;
            }
        }
    }

    void solve() {
        int n = io.nextInt();
        int id13 = min(n, 30);
        unordered_set<long long> prev;
        prev.insert(0LL);
        for (int i = 0; i < id13; i++) {
            unordered_set<long long> next;
            for (long long v : prev) {
                next.insert(v + 1);
                next.insert(v + 5);
                next.insert(v + 10);
                next.insert(v + 50);
            }
            prev = move(next);
        }

        if (n > id13) {
            int diff = n - id13;
            done(prev.size() + diff * 49LL);
        }

        io.print(prev.size());
    }

    void done(long long output) {
        io.print(output);
        done();
    }

    void done() {
        throw runtime_error("Clean exit");
    }

    long long min(long long a, long long b) {
        return a < b ? a : b;
    }

    long long min(long long a, long long b, long long c) {
        return min(min(a, b), c);
    }

    long long max(long long a, long long b) {
        return a > b ? a : b;
    }

    long long max(long long a, long long b, long long c) {
        return max(max(a, b), c);
    }
};

int main() {
    Solver solver;
    return 0;
}
