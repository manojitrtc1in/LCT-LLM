#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <numeric>
#include <functional>
#include <fstream>
#include <sstream>
#include <complex>
#include <array>
#include <tuple>
#include <random>
#include <unordered_map>
using namespace std;

class D {
public:
    static void solve() {
        int n;
        cin >> n;

        int endOfBrute = min(n, 30);
        unordered_set<long long> prev;
        prev.insert(0LL);
        for (int i = 0; i < endOfBrute; i++) {
            unordered_set<long long> next;
            for (long long v : prev) {
                next.insert(v + 1);
                next.insert(v + 5);
                next.insert(v + 10);
                next.insert(v + 50);
            }
            prev = next;
        }

        if (n > endOfBrute) {
            int diff = n - endOfBrute;
            done(prev.size() + diff * 49LL);
        }

        cout << prev.size() << endl;
    }

    static void done() {
        throw runtime_error("Clean exit");
    }

    template<typename T>
    static void done(T output) {
        cout << output << endl;
        done();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    try {
        D::solve();
    } catch (const runtime_error& e) {
        if (string(e.what()) != "Clean exit") {
            throw e;
        }
    }

    return 0;
}
