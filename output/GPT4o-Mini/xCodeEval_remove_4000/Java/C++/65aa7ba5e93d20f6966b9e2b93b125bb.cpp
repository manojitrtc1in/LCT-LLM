#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const long MOD = 1e9 + 7;
const long MOD2 = MOD * MOD;

class FastReader {
    public:
        FastReader() {}

        string next() {
            string s;
            cin >> s;
            return s;
        }

        int nextInt() {
            int x;
            cin >> x;
            return x;
        }

        double nextDouble() {
            double x;
            cin >> x;
            return x;
        }

        long long nextLong() {
            long long x;
            cin >> x;
            return x;
        }
};

void solve() {
    FastReader sc;
    string s = sc.next();
    string t = sc.next();
    int n = s.length();
    int m = t.length();
    vector<int> pre(m), suf(m);
    
    for (int i = 0, j = 0; i < m; i++) {
        while (s[j] != t[i]) j++;
        pre[i] = j++;
    }
    
    for (int i = m - 1, j = n - 1; i >= 0; i--) {
        while (s[j] != t[i]) j--;
        suf[i] = j--;
    }
    
    int ans = max(suf[0], n - 1 - pre[m - 1]);
    for (int i = 0; i < m - 1; i++) {
        ans = max(ans, suf[i + 1] - 1 - pre[i]);
    }
    
    cout << ans << endl;
}

int main() {
    int test = 1;

    while (test-- > 0) solve();
    return 0;
}
