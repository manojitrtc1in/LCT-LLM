#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, mod;
    cin >> n >> mod;

    int M = sqrt(n) + 10;

    vector<int> dp(n+1, 0);
    vector<int> imos(n+1, 0);
    dp[1] = 1;
    for (int i = 1; i < n; i++) {
        imos[i] = (imos[i] + imos[i-1]) % mod;
        dp[i] += imos[i];
        dp[i] %= mod;

        imos[i+1] += dp[i];
        imos[i+1] %= mod;

        for (int j = 2; j <= n; j++) {
            if (i*j > n) {
                break;
            }

            imos[i*j] += dp[i];
            imos[i*j] %= mod;
            if ((i+1)*j <= n) {
                imos[(i+1)*j] -= dp[i];
                imos[(i+1)*j] %= mod;
            }
        }
    }

    int res = dp[n] + imos[n] + imos[n-1];
    res %= mod;
    cout << res << endl;

    return 0;
}
