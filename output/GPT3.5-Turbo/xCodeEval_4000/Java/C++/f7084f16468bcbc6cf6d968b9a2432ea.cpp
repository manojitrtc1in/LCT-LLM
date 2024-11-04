#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;

class FastReader {
public:
    FastReader() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
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

    string next() {
        string s;
        cin >> s;
        return s;
    }

    string nextLine() {
        string s;
        getline(cin, s);
        return s;
    }
};

class Main {
public:
    Main() {
        FastReader in;

        int nt = 1;
        stringstream sb;

        for (int it = 0; it < nt; it++) {
            long long n = in.nextLong();
            long long k = in.nextLong();

            if (k == 1) {
                cout << n << endl;
                return;
            }

            long long lo = 1, hi = n / 2;

            while (lo <= hi) {
                long long mid = (hi + lo) / 2;
                long long val = mid * 2 - 1;

                if (cnt(val, n) >= k) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            long long cand = hi * 2 - 1;
            if (cnt(cand, n) < k) cand = 0;

            lo = 1;
            hi = n / 2;

            while (lo <= hi) {
                long long mid = (hi + lo) / 2;
                long long val = mid * 2;
                if (cnt(val, n) >= k)
                    lo = mid + 1;
                else hi = mid - 1;
            }

            cand = max(cand, hi * 2);
            cout << cand << endl;
        }
    }

    long long cnt(long long v, long long n) {
        if (v > n) return 0;

        long long cnt = 0;
        if (v % 2 == 1) {
            long long segSize = 1;
            long long start = v;
            while (start <= n) {
                long long end = min(n, start + segSize - 1);
                cnt += end - start + 1;

                segSize *= 2;
                start *= 2;
            }

        }
        else {

            long long segSize = 2;
            long long start = v;
            while (start <= n) {
                long long end = min(n, start + segSize - 1);
                cnt += end - start + 1;

                segSize *= 2;
                start *= 2;
            }

        }

        return cnt;
    }
};

int main() {
    Main obj;
    return 0;
}
