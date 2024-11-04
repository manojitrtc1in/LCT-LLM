






































































































#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> dpmex(n + 10, vector<int>(n + 10, 0));
        for (int i = 0; i < n; i++) {
            bitset<128> used = 0;
            if (a[i] < 128)
                used[a[i]] = true;
            if (used[dpmex[i][i]])
                dpmex[i][i] += 1;
            for (int j = i + 1; j < n; j++) {
                dpmex[i][j] = dpmex[i][j - 1];
                if (a[j] < 128)
                    used[a[j]] = true;
                while (used[dpmex[i][j]])
                    dpmex[i][j] += 1;
            }
        }
        vector<vector<ll>> dp(n + 10, vector<ll>(n + 10, 0));
        ll answer = 0;
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i + l <= n; i++) {
                dp[i][i + l - 1] = 1 + dpmex[i][i + l - 1];

                

                for (int k = i; k < i + l - 1; k++) {
                    ll v = dp[i][k] + dp[k + 1][i + l - 1];
                    dp[i][i + l - 1] = max(dp[i][i + l - 1], v);
                }

                answer += dp[i][i + l - 1];
            }
        }
        cout << answer << '\n';
    }
}