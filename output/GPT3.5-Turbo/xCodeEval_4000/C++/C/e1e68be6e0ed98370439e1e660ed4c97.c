#include <stdio.h>

#define MOD 998244353

typedef long long LL;

LL factorial[3123456];
LL inverse_factorial[3123456];

LL add(LL a, LL b) {
    return (a + b) % MOD;
}

LL mul(LL a, LL b) {
    return (a * b) % MOD;
}

LL pow(LL a, LL x) {
    LL ret = 1;
    while (x) {
        if (x & 1) {
            ret = mul(ret, a);
        }
        a = mul(a, a);
        x >>= 1;
    }
    return ret;
}

LL inv(LL x) {
    LL a = x, b = MOD, u = 1, v = 0;
    while (b) {
        LL t = a / b;
        a -= t * b;
        u -= t * v;
        LL tmp = a;
        a = b;
        b = tmp;
        tmp = u;
        u = v;
        v = tmp;
    }
    return (u + MOD) % MOD;
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

LL combination(int n, int k) {
    if (k < 0 || k > n) return 0;
    return mul(mul(factorial[n], inverse_factorial[k]), inverse_factorial[n - k]);
}

LL multi_choose(int n, int r) {
    if (n == 0) {
        return (r == 0 ? 1 : 0);
    }
    if (r == 0) {
        return 1;
    }
    return combination(n + r - 1, r);
}

LL multi_choose_with_limit(int n, int r, int lim) {
    if (n == 0) {
        return (r == 0 ? 1 : 0);
    }
    if (lim <= 0 && r > 0) {
        return 0;
    }
    if (r == 0) {
        return (lim < 0 ? 0 : 1);
    }
    LL ret = 0;
    for (int i = 0; i <= n; i++) {
        if (i * (lim + 1) > r) break;
        ret += ((i & 1) ? MOD - 1 : 1) * combination(n, i) * multi_choose(n, r - i * (lim + 1));
        ret %= MOD;
    }
    return ret;
}

int main() {
    int p, s, r;
    scanf("%d%d%d", &p, &s, &r);
    build_factorial();
    LL ret = 0;
    for (int top = r; top <= s; top++) {
        LL tot = 0;
        for (int q = 0; q < p; q++) {
            if (top * q > s - top) break;
            tot += mul(mul(combination(p - 1, q), multi_choose_with_limit(p - q - 1, s - top - top * q, top - 1)), inv(q + 1));
            tot %= MOD;
        }
        ret += tot;
        ret %= MOD;
    }
    ret = mul(ret, inv(multi_choose(p, s - r)));
    printf("%lld\n", ret);
    return 0;
}
