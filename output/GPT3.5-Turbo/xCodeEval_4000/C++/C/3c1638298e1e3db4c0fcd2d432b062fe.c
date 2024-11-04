#include <stdio.h>

#define MOD 998244353
#define MAXN 2000005

typedef long long ll;

ll fac[MAXN];

void precompute_factorials() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = (fac[i-1] * i) % MOD;
    }
}

ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

ll inverse(ll x) {
    return power(x, MOD - 2);
}

ll binomial_coefficient(ll n, ll k) {
    if (k > n) {
        return 0;
    }
    ll numerator = fac[n];
    ll denominator = (fac[k] * fac[n-k]) % MOD;
    ll inv_denominator = inverse(denominator);
    return (numerator * inv_denominator) % MOD;
}

ll solve(int n, int k) {
    ll ans = 0;
    for (int i = 0; i <= n - k; i++) {
        ll sign = (n - k - i) % 2 == 0 ? 1 : -1;
        ll term = (binomial_coefficient(n - k, i) * power(i, n)) % MOD;
        ans = (ans + sign * term) % MOD;
    }
    ans = (ans * binomial_coefficient(n, n - k)) % MOD;
    return ans;
}

int main() {
    precompute_factorials();
    int n, k;
    scanf("%d %d", &n, &k);
    if (k >= n) {
        printf("0\n");
        return 0;
    }
    ll ans = (1 + (k > 0)) * solve(n, k);
    printf("%lld\n", ans);
    return 0;
}
