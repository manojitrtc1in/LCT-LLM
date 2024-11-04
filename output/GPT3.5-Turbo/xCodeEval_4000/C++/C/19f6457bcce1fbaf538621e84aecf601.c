#include <stdio.h>
#include <stdint.h>

#define mod 1000000007

typedef uint8_t state[1 << 6];

uint64_t powe(uint64_t b, uint64_t e) {
    uint64_t r = 1;
    while (e) {
        if (e & 1) r = r * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return r;
}

void admul(uint64_t *a, uint64_t b, uint64_t c) {
    *a = (*a + b * c) % mod;
}

void go(int n) {
    uint64_t p[6][6];
    uint64_t i100 = powe(100, mod - 2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            uint64_t x;
            scanf("%llu", &x);
            p[i][j] = x * i100 % mod;
        }
    }
    state x;
    for (int i = 0; i < (1 << n); ++i) {
        x[i] = 0;
    }
    x[0] = 1;
    for (int turn = 0; turn < n; ++turn) {
        state newx;
        for (int s = 0; s < (1 << n); ++s) {
            uint64_t mul = 1;
            for (int i = 0; i < n; ++i) {
                if (s >> i & 1) {
                    mul = mul * p[i][turn] % mod;
                } else {
                    mul = mul * (1 - p[i][turn]) % mod;
                }
            }
            for (int i = 0; i < (1 << n); ++i) {
                newx[i] = x[i];
            }
            for (int i = 0; i < (1 << n); ++i) {
                if ((i & s) && newx[i] < __builtin_popcount(i)) {
                    newx[i]++;
                }
            }
            int add = 1;
            for (int i = 0; i < (1 << n); ++i) {
                if (newx[i] + (n - turn - 1) < __builtin_popcount(i)) {
                    add = 0;
                }
            }
            if (add) {
                for (int i = 0; i < (1 << n); ++i) {
                    admul(&newx[i], mul, x[i]);
                }
            }
            for (int i = 0; i < (1 << n); ++i) {
                x[i] = newx[i];
            }
        }
    }
    state fin;
    for (int i = 0; i < (1 << n); ++i) {
        fin[i] = __builtin_popcount(i);
    }
    uint64_t ans = x[fin];
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%llu\n", ans);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) go(1);
    if (n == 2) go(2);
    if (n == 3) go(3);
    if (n == 4) go(4);
    if (n == 5) go(5);
    if (n == 6) go(6);
    return 0;
}
