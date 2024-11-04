#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 20

typedef uint8_t state[1 << MAX_N];

long long powe(long long b, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return r;
}

void admul(long long *a, long long b, long long c) {
    *a = (*a + b * c) % MOD;
}

void go(int n) {
    long long p[MAX_N][MAX_N];
    long long i100 = powe(100, MOD - 2);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            long long x;
            scanf("%lld", &x);
            p[i][j] = x * i100 % MOD;
        }

    long long x[1 << MAX_N] = {0};
    state init = {0};
    x[0] = 1;

    for (int turn = 0; turn < n; ++turn) {
        long long newx[1 << MAX_N] = {0};
        for (int s = 0; s < (1 << n); ++s) {
            long long mul = 1;
            for (int i = 0; i < n; ++i) {
                if (s >> i & 1)
                    mul = mul * p[i][turn] % MOD;
                else
                    mul = mul * (1 - p[i][turn]) % MOD;
            }
            for (int k = 0; k < (1 << n); ++k) {
                if (x[k] > 0) {
                    state c;
                    memcpy(c, init, sizeof(state));
                    for (int k2 = 0; k2 < (1 << n); ++k2) {
                        if ((k2 & s) && c[k2] < __builtin_popcount(k2))
                            c[k2]++;
                    }
                    int add = 1;
                    for (int k2 = 0; k2 < (1 << n); ++k2) {
                        if (c[k2] + (n - turn - 1) < __builtin_popcount(k2))
                            add = 0;
                    }
                    if (add) {
                        admul(&newx[c[0]], mul, x[k]);
                    }
                }
            }
        }
        memcpy(x, newx, sizeof(x));
    }

    state fin = {0};
    for (int i = 0; i < (1 << n); ++i)
        fin[i] = __builtin_popcount(i);
    long long ans = x[fin[0]];
    ans %= MOD;
    if (ans < 0) ans += MOD;
    printf("%lld\n", ans);
}

int main() {
    int n;
    scanf("%d", &n);
    go(n);
    return 0;
}
