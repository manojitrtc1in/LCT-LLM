#include<stdio.h>

typedef long long LL;

LL mod_mul(LL x, LL y, LL n) {
    LL d = (LL)((long double)x * y / n);
    d = x * y - n * d;
    while (d < 0) {
        d += n;
    }
    while (d >= n) {
        d -= n;
    }
    return d;
}

LL powmod(LL x, LL t, LL base) {
    LL res = 1LL;
    while (t > 0) {
        if (t & 1LL) {
            res = mod_mul(res, x, base);
        }
        x = mod_mul(x, x, base);
        t >>= 1;
    }
    return res;
}

int strong_pseudo_primetest(LL n, int base) {
    LL n2 = n - 1, res;
    int s = 0;
    while (!(n2 & 1)) {
        n2 >>= 1;
        ++s;
    }
    res = powmod(base, n2, n);
    if (res == 1 || res == n - 1) {
        return 1;
    }
    --s;
    while (s >= 0) {
        res = mod_mul(res, res, n);
        if (res == n - 1) {
            return 1;
        }
        --s;
    }
    return 0;
}

int isPrime(LL n) {
    if (n < 2) {
        return 0;
    }
    if (n < 4) {
        return 1;
    }
    if (strong_pseudo_primetest(n, 2) == 0) {
        return 0;
    }
    if (strong_pseudo_primetest(n, 3) == 0) {
        return 0;
    }
    if (n < 1373653LL) {
        return 1;
    }
    if (strong_pseudo_primetest(n, 5) == 0) {
        return 0;
    }
    if (n < 25326001LL) {
        return 1;
    }
    if (strong_pseudo_primetest(n, 7) == 0) {
        return 0;
    }
    if (n == 3215031751LL) {
        return 0;
    }
    if (n < 25000000000LL) {
        return 1;
    }
    if (strong_pseudo_primetest(n, 11) == 0) {
        return 0;
    }
    if (n < 2152302898747LL) {
        return 1;
    }
    if (strong_pseudo_primetest(n, 13) == 0) {
        return 0;
    }
    if (strong_pseudo_primetest(n, 17) == 0) {
        return 0;
    }
    if (n < 341550071728321LL) {
        return 1;
    }
    if (strong_pseudo_primetest(n, 19) == 0) {
        return 0;
    }
    if (strong_pseudo_primetest(n, 23) == 0) {
        return 0;
    }
    if (strong_pseudo_primetest(n, 29) == 0) {
        return 0;
    }
    if (strong_pseudo_primetest(n, 31) == 0) {
        return 0;
    }
    if (strong_pseudo_primetest(n, 37) == 0) {
        return 0;
    }
    return 1;
}

int solve(int l, int r) {
    if (l > r) {
        return 0;
    }
    int sum = 0;
    for (int i = l; i <= r; i++) {
        if (i % 2 == 0 || i % 3 == 0 || i % 7 == 0 || !isPrime(i)) {
            continue;
        }
        if (i % 4 == 1) {
            sum++;
        }
    }
    return sum;
}

int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    int L = l / 100000;
    int R = r / 100000;
    int sum1 = 0;
    for (int i = 0; i <= L; i++) {
        sum1 += ans[i];
    }
    sum1 += solve(L * 100000 + 1, l);
    if (l >= 2 && l < 100000) {
        sum1++;
    }
    int sum2 = 0;
    for (int i = 0; i <= R; i++) {
        sum2 += ans[i];
    }
    sum2 += solve(R * 100000 + 1, r);
    if (r >= 2 && r < 100000) {
        sum2++;
    }
    printf("%d\n", sum2 - sum1);
    return 0;
}
