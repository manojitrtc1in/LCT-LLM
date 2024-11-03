#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <sstream>
#include <complex>
#include <iterator>
#include <functional>
#include <numeric>
#include <climits>
#include <cctype>
#include <array>
#include <tuple>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const long long mod = 1000000007;
const long long mod2 = 998244353;

struct FastReader {
    FastReader() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int nextInt() {
        int x;
        cin >> x;
        return x;
    }
    long long nextLong() {
        long long x;
        cin >> x;
        return x;
    }
    double nextDouble() {
        double x;
        cin >> x;
        return x;
    }
    string nextLine() {
        string str;
        getline(cin, str);
        return str;
    }
};

struct id1 {
    static const int MAXN = 100005;
    long long pref[MAXN];

    void main() {
        int n;
        cin >> n;
        vector<long long> a(n);
        input(a, n);
        if (n > 66) {
            cout << 1 << endl;
            return;
        }
        pref[1] = a[0];
        for (int i = 1; i < n; i++) {
            pref[i + 1] = pref[i] ^ a[i];
        }
        int gg = 34;
        for (int c = 0; c < n - 1; c++) {
            for (int left = c; left >= 0; left--) {
                for (int right = c + 1; right < n; right++) {
                    if (xor(left, c) > xor(c + 1, right)) {
                        gg = min(gg, right - left - 1);
                    }
                }
            }
        }
        cout << (gg == 34 ? -1 : gg) << endl;
    }

    long long xor(int i, int j) {
        return pref[j + 1] ^ pref[i];
    }

    template<typename T>
    void input(vector<T>& a, int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }
};

int main() {
    id1 g;
    g.main();
    return 0;
}
