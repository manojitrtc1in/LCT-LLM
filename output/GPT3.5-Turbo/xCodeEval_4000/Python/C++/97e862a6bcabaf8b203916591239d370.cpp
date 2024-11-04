#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> DP(n + 5, 0);
    vector<int> CUM(n + 5, 1);
    CUM[1] = 0;
    DP[1] = 1;

    int S = 1;

    for (int i = 2; i <= n; i++) {
        CUM[i] = (CUM[i - 1] + CUM[i]) % m;
        DP[i] = (S + CUM[i]) % m;
        S += DP[i];
        S %= m;

        for (int j = i + i; j <= n; j += i) {
            CUM[j] = (CUM[j] + DP[i] - DP[i - 1]) % m;
        }
    }

    cout << DP[n] << endl;

    return 0;
}
