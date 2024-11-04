#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const long long mod = 998244353;

long long fact[400001], revFact[400001];

void preFact(int n) {
    fact[0] = 1;
    for (int i = 0; i < n; i++) {
        fact[i + 1] = (i + 1) * fact[i] % mod;
    }
    revFact[n] = pow(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        revFact[i] = revFact[i + 1] * (i + 1) % mod;
    }
}

long long cmb(int a, int b) {
    if (a < b) return 0;
    return fact[a] * revFact[b] % mod * revFact[a - b] % mod;
}

long long pow(long long x, long long y) {
    if (y < 0) return 0;
    if (y == 0) return 1;
    if (y % 2 == 1) return x * pow(x, y - 1) % mod;
    long long root = pow(x, y / 2);
    return root * root % mod;
}

void solve() {
    int n;
    long long tmp;
    cin >> n >> tmp;
    if (n <= tmp) {
        cout << 0 << endl;
        return;
    }
    int k = (int)tmp;
    preFact(400000);
    long long ans = 0;
    long long t = cmb(n, n - k);
    int si = 1;
    for (int i = n - k; i >= 1; i--) {
        ans = (ans + si * cmb(n - k, i) * pow(i, n)) % mod;
        if (ans < 0) ans += mod;
        si *= -1;
    }
    ans = (ans * t) % mod;
    if (k != 0) ans = (ans * 2) % mod;
    if (ans < 0) ans += mod;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
