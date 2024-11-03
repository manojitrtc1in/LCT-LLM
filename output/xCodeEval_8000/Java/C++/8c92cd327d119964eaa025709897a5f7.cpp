#include <iostream>
#include <vector>

using namespace std;

long long invl(long long a, long long mod) {
    long long b = mod;
    long long p = 1, q = 0;
    while (b > 0) {
        long long c = a / b;
        long long d;
        d = a;
        a = b;
        b = d % b;
        d = p;
        p = q;
        q = d - c * q;
    }
    return p < 0 ? p + mod : p;
}

void solve() {
    int mod = 1000000007;
    int n, m;
    cin >> n >> m;

    if (m > n + 1) {
        cout << 0 << endl;
        return;
    }

    vector<vector<long long>> dp = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
