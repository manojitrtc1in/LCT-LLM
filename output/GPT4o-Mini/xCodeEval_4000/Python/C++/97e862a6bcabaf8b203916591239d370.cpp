#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;

int main() {
    int tt = 1;
    while (tt--) {
        int n, m;
        cin >> n >> m;

        vector<long long> DP(n + 5, 0);
        vector<long long> CUM(n + 5, 1);
        CUM[1] = 0;
        DP[1] = 1;

        long long S = 1;

        for (int i = 2; i <= n; i++) {
            CUM[i] = (CUM[i - 1] + CUM[i]) % m;
            DP[i] = (S + CUM[i]) % m;
            S = (S + DP[i]) % m;

            for (int j = i + i; j <= n; j += i) {
                CUM[j] = (CUM[j] + DP[i] - DP[i - 1]) % m;
            }
        }

        cout << DP[n] << endl;
    }
    return 0;
}
