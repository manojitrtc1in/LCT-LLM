#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <random>

using namespace std;

class D {
public:
    static void main() {
        Solver solver;
    }

    class Solver {
        public:
        Solver() {
            try {
                solve();
            } catch (const runtime_error& e) {
                if (e.what() != string("Clean exit")) {
                    throw;
                }
            }
        }

        void solve() {
            int n;
            cin >> n;

            int endOfBrute = min(n, 30);
            set<long> prev;
            prev.insert(0L);
            for (int i = 0; i < endOfBrute; i++) {
                set<long> next;
                for (long v : prev) {
                    next.insert(v + 1);
                    next.insert(v + 5);
                    next.insert(v + 10);
                    next.insert(v + 50);
                }
                prev = next;
            }

            if (n > endOfBrute) {
                int diff = n - endOfBrute;
                done(prev.size() + diff * 49L);
            }

            cout << prev.size() << endl;
        }

        long MOD = (long)1e9 + 7;

        bool closeToZero(double v) {
            return abs(v) <= 0.0000000000001;
        }

        void done(long output) {
            cout << output << endl;
            throw runtime_error("Clean exit");
        }

        long min(long... v) {
            long ans = v[0];
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

        long max(long... v) {
            long ans = v[0];
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
};

int main() {
    D::main();
    return 0;
}
