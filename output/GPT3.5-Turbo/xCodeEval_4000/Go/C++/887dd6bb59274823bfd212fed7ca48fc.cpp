#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <cassert>
#include <functional>
#include <random>
#include <chrono>
using namespace std;

const int MOD = 1000000007;

int readInt() {
    int x;
    cin >> x;
    return x;
}

void printInt(int x) {
    cout << x;
}

void solve() {
    int a = readInt();
    int b = readInt();
    
    long long r = 0;
    for (int i = 1; i <= b - 1; i++) {
        r += i;
        if (r >= MOD) {
            r -= MOD;
        }
    }

    long long res = (long long)a * r % MOD;

    long long k = 0;
    for (int i = 1; i <= a; i++) {
        k += (long long)i * r % MOD;
        if (k >= MOD) {
            k -= MOD;
        }
    }

    res += (long long)b * k % MOD;
    if (res >= MOD) {
        res -= MOD;
    }

    printInt(res);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
