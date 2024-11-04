#include <stdio.h>

#define mod 1000000007

typedef long long ll;

ll factorial[3123456];
ll inverse_factorial[3123456];

ll add(ll a, ll b) {
    return (a + b) % mod;
}

ll mul(ll a, ll b) {
    return (a * b) % mod;
}

ll pow(ll a, ll x) {
    ll ret = 1;
    while (x) {
        if (x & 1) {
            ret = mul(ret, a);
        }
        a = mul(a, a);
        x >>= 1;
    }
    return ret;
}

ll inv(ll x) {
    ll a = x, b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        u -= t * v;
        ll temp = a;
        a = b;
        b = temp;
        temp = u;
        u = v;
        v = temp;
    }
    return (u + mod) % mod;
}

void build_factorial() {
    factorial[0] = 1;
    for (int i = 1; i < 3123456; i++) {
        factorial[i] = mul(factorial[i - 1], i);
    }
    inverse_factorial[3123456 - 1] = inv(factorial[3123456 - 1]);
    for (int i = 3123456 - 1; i >= 1; i--) {
        inverse_factorial[i - 1] = mul(inverse_factorial[i], i);
    }
}

ll permutation(int n, int k) {
    if (k < 0 || k > n) return 0;
    return mul(factorial[n], inverse_factorial[n - k]);
}

ll combination(int n, int k) {
    if (k < 0 || k > n) return 0;
    return mul(factorial[n], mul(inverse_factorial[k], inverse_factorial[n - k]));
}

ll multiChoose(int n, int r) {
    if (n == 0) {
        return (r == 0 ? 1 : 0);
    }
    if (r == 0) {
        return 1;
    }
    return combination(n + r - 1, r);
}

ll multiChooseWithLimit(int n, int r, int lim) {
    if (n == 0) {
        return (r == 0 ? 1 : 0);
    }
    if (lim <= 0 && r > 0) {
        return 0;
    }
    if (r == 0) {
        return (lim < 0 ? 0 : 1);
    }
    ll ret = 0;
    for (int i = 0; i <= n; i++) {
        if (i * (lim + 1) > r) break;
        ret += ((i & 1) ? mod - 1 : 1) * combination(n, i) * multiChoose(n, r - i * (lim + 1));
        ret %= mod;
    }
    return ret;
}

int main() {
    build_factorial();

    int p, s, r;
    scanf("%d%d%d", &p, &s, &r);
    ll ret = 0;
    for (int top = r; top <= s; top++) {
        ll tot = 0;
        for (int q = 0; q < p; q++) {
            if (top * q > s - top) break;
            tot += combination(p - 1, q) * multiChooseWithLimit(p - q - 1, s - top - top * q, top - 1) * inv(q + 1);
            tot %= mod;
        }
        ret += tot;
        ret %= mod;
    }
    ret = mul(ret, inv(multiChoose(p, s - r)));
    printf("%lld\n", ret);
    return 0;
}
