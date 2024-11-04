#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <cassert>
#include <climits>
#include <complex>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iterator>
#include <list>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <ctime>
#include <array>
#include <tuple>
#include <regex>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class D {
public:
    static void solve() {
        long long n, m;
        cin >> n >> m;
        if (m < n) {
            long long helper = m;
            m = n;
            n = helper;
        }

        if (n == 1) {
            cout << brute1(m) << endl;
            return;
        }
        if (n == 2) {
            if (m < 3) cout << 0 << endl;
            else if (m == 3) cout << 4 << endl;
            else if (m == 7) cout << 12 << endl;
            else cout << 2 * m << endl;
            return;
        }

        cout << 2 * (n * m / 2) << endl;
    }

    static long long brute1(long long m) {
        long long ans = 6 * (m / 6);
        if (m % 6 == 5) ans += 4;
        else if (m % 6 == 4) ans += 2;
        return ans;
    }
};

int main() {
    D::solve();
    return 0;
}
