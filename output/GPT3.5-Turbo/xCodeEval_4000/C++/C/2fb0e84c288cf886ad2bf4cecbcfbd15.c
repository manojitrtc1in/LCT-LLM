#include <stdio.h>

typedef long long ll;

ll safe_mod(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

ll pow_mod_constexpr(ll x, ll n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

int is_prime_constexpr(int n) {
    if (n <= 1) return 0;
    if (n == 2 || n == 7 || n == 61) return 1;
    if (n % 2 == 0) return 0;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    const ll bases[3] = {2, 7, 61};
    for (ll a : bases) {
        ll t = d;
        ll y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return 0;
        }
    }
    return 1;
}

int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (ll)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        int ok = 1;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = 0;
                break;
            }
        }
        if (ok) return g;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int mod = m;

    ll dp[n+1];
    ll p1[n+1];

    dp[n] = 1;
    p1[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        dp[i] += p1[i+1];

        for (int z = 2; z * i <= n; z++) {
            int r = 0;
            int l = z * i;
            int ans = l;

            while (l <= r) {
                int m = (l + r) / 2;
                if (m / z > i) {
                    r = m - 1;
                } else {
                    ans = m;
                    l = m + 1;
                }
            }

            dp[i] += p1[l];
            if (r <= n) dp[i] -= p1[r];
        }

        p1[i] = p1[i+1] + dp[i];
    }

    printf("%lld\n", dp[1]);

    return 0;
}
