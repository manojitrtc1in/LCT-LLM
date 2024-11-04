#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CR 7
#define BITS 15
#define MOD (int)(1e9) + 7

typedef long long li;
typedef long double ld;

typedef struct {
    int val;
} _m_int;

_m_int new_m_int(int64_t v) {
    _m_int m;
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    m.val = (int)v;
    return m;
}

_m_int new_m_int_uint(uint64_t v) {
    _m_int m;
    if (v >= MOD) v %= MOD;
    m.val = (int)v;
    return m;
}

_m_int new_m_int_int(int v) {
    return new_m_int((int64_t)v);
}

_m_int new_m_int_uint(unsigned v) {
    return new_m_int_uint((uint64_t)v);
}

int inv_mod(int a, int m) {
    int g = m, r = a, x = 0, y = 1;

    while (r != 0) {
        int q = g / r;
        g %= r;
        int temp = x;
        x = x - q * y;
        y = temp;
    }

    return x < 0 ? x + m : x;
}

_m_int inv(const _m_int* m) {
    return new_m_int(inv_mod(m->val, MOD));
}

unsigned fast_mod(uint64_t x, unsigned m) {
    return (unsigned)(x % m);
}

_m_int mul(const _m_int* a, const _m_int* b) {
    return new_m_int(fast_mod((uint64_t)(a->val) * (uint64_t)(b->val), MOD));
}

_m_int add(const _m_int* a, const _m_int* b) {
    return new_m_int(a->val + b->val);
}

_m_int sub(const _m_int* a, const _m_int* b) {
    return new_m_int(a->val - b->val);
}

_m_int div(const _m_int* a, const _m_int* b) {
    return mul(a, &inv(b));
}

_m_int pow(const _m_int* a, int64_t p) {
    if (p < 0)
        return pow(&inv(a), -p);

    _m_int result = new_m_int_int(1);
    _m_int temp = *a;

    while (p > 0) {
        if (p & 1)
            result = mul(&result, &temp);
        temp = mul(&temp, &temp);
        p >>= 1;
    }

    return result;
}

typedef _m_int Mint;

Mint dp[CR][BITS + 1][CR][1 << BITS];
Mint cnt[CR][CR][1 << BITS];

void precalc() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < CR; i++) {
        dp[i][0][i][0] = new_m_int_int(1);
    }
    for (int cs = 0; cs < CR; cs++) {
        for (int i = 0; i < BITS; i++) {
            for (int ct = 0; ct < CR; ct++) {
                for (int x = 0; x < (1 << BITS); x++) {
                    if (dp[cs][i][ct][x].val != 0) {
                        for (int cc = 0; cc < CR + 1; cc++) {
                            dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x] = add(&dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x], &dp[cs][i][ct][x]);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < CR; i++) {
        for (int j = 0; j < CR; j++) {
            for (int x = 0; x < (1 << BITS); x++) {
                cnt[i][j][x] = dp[i][BITS][j][x];
            }
        }
    }
}

Mint dp2[5][CR];

void solve(li n) {
    memset(dp2, 0, sizeof(dp2));
    dp2[0][0] = new_m_int_int(1);
    for (int i = 0; i < 4; i++) {
        int x = (int)(n & ((1 << BITS) - 1));
        n >>= BITS;
        for (int j = 0; j < CR; j++) {
            for (int k = 0; k < CR; k++) {
                dp2[i + 1][k] = add(&dp2[i + 1][k], mul(&dp2[i][j], &cnt[j][k][x]));
            }
        }
    }
    printf("%d\n", dp2[4][0].val);
}

int main() {
    li n;
    while (scanf("%lld", &n) != EOF) {
        solve(n);
    }
    return 0;
}
