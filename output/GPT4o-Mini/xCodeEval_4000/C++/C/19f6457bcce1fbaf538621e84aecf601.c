#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MOD 1000000007

typedef uint8_t state[64]; // Adjust size based on maximum n

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
    long long p[6][6]; // Adjust size based on maximum n
    long long i100 = powe(100, MOD - 2);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long x;
            scanf("%lld", &x);
            p[i][j] = x * i100 % MOD;
        }
    }

    long long x[1 << 6] = {0}; // Adjust size based on maximum n
    state init = {0};
    x[0] = 1;

    for (int turn = 0; turn < n; ++turn) {
        long long newx[1 << 6] = {0}; // Adjust size based on maximum n
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
                    bool add = true;
                    for (int k2 = 0; k2 < (1 << n); ++k2) {
                        if (c[k2] + (n - turn - 1) < __builtin_popcount(k2))
                            add = false;
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
    if (n == 1) go(1);
    else if (n == 2) go(2);
    else if (n == 3) go(3);
    else if (n == 4) go(4);
    else if (n == 5) go(5);
    else if (n == 6) go(6);
}
