#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    int res = a + b;
    if (res >= MOD) {
        res -= MOD;
    }
    return res;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int sub(int a, int b) {
    int res = a - b;
    if (res < 0) {
        res += MOD;
    }
    return res;
}

int pow(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = mul(res, x);
        }
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

int inverse(int x) {
    return pow(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> xk(k + 1);
    for (int i = 0; i <= k; i++) {
        xk[i] = pow(i, k);
    }

    int ans = 0;
    vector<int> bc(k + 1);
    bc[0] = 1;
    for (int t = 0; t <= k; t++) {
        int p1 = bc[t];
        int p2 = 0;
        for (int i = 0; i <= t; i++) {
            int contrib = pow(t, i);
            contrib = mul(contrib, xk[t - i]);
            if (i % 2 == 1) {
                contrib = sub(0, contrib);
            }
            p2 = add(p2, contrib);
        }
        int p3 = inverse(t);

        int contrib = mul(p1, p2);
        contrib = mul(contrib, p3);
        ans = add(ans, contrib);
    }

    cout << ans << '\n';

    return 0;
}
