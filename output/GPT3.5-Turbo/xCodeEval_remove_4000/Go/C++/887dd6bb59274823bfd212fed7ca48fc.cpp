#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

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

void printLine() {
    cout << endl;
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
    printLine();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
