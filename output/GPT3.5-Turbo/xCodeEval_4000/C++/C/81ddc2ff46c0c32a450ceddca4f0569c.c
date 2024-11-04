#include <stdio.h>

typedef long long ll;

const int MOD = 998244353;

int add(int a, int b) {
    int res = a + b;
    if (res >= MOD) {
        res -= MOD;
    }
    return res;
}

int sub(int a, int b) {
    int res = a - b;
    if (res < 0) {
        res += MOD;
    }
    return res;
}

int mul(int a, int b) {
    return (int) (((ll) a * b) % MOD);
}

int pow_mod(int x, int n) {
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

int inv(int x) {
    return pow_mod(x, MOD - 2);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int dp[n + 1];
    int p[n + 1];

    dp[n] = 1;
    p[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = add(p[i + 1], 0);

        for (int z = 2; (ll) z * i <= n; z++) {
            int r = i * z + z;
            int l = z * i;
            dp[i] = add(dp[i], p[l]);
            if (r <= n) {
                dp[i] = sub(dp[i], p[r]);
            }
        }

        p[i] = add(p[i + 1], dp[i]);
    }

    printf("%d\n", dp[1]);

    return 0;
}
