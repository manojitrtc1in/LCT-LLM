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

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
        }
    }

    cout << dp[n][m] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
