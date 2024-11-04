#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CR 7
#define BITS 15
#define MOD 1000000007

typedef long long li;

typedef struct {
    int val;
} _m_int;

_m_int _m_int_init(int64_t v) {
    _m_int m;
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    m.val = (int)v;
    return m;
}

_m_int _m_int_init_unsigned(uint64_t v) {
    _m_int m;
    if (v >= MOD) v %= MOD;
    m.val = (int)v;
    return m;
}

_m_int _m_int_init_int(int v) {
    return _m_int_init((int64_t)v);
}

_m_int _m_int_init_unsigned_int(unsigned v) {
    return _m_int_init_unsigned((uint64_t)v);
}

int _m_int_inv_mod(int a, int m) {
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

_m_int _m_int_inv(_m_int m) {
    return _m_int_init(_m_int_inv_mod(m.val, MOD));
}

_m_int _m_int_mul(_m_int a, _m_int b) {
    return _m_int_init((int)((int64_t)a.val * b.val % MOD));
}

_m_int _m_int_add(_m_int a, _m_int b) {
    return _m_int_init(a.val + b.val >= MOD ? a.val + b.val - MOD : a.val + b.val);
}

_m_int _m_int_sub(_m_int a, _m_int b) {
    return _m_int_init(a.val - b.val < 0 ? a.val - b.val + MOD : a.val - b.val);
}

_m_int _m_int_div(_m_int a, _m_int b) {
    return _m_int_mul(a, _m_int_inv(b));
}

_m_int _m_int_pow(_m_int a, int64_t p) {
    if (p < 0)
        return _m_int_pow(_m_int_inv(a), -p);

    _m_int result = _m_int_init_int(1);

    while (p > 0) {
        if (p & 1)
            result = _m_int_mul(result, a);
        a = _m_int_mul(a, a);
        p >>= 1;
    }

    return result;
}

typedef _m_int Mint;

Mint dp[CR][BITS + 1][CR][1 << BITS];
Mint cnt[CR][CR][1 << BITS];

void precalc() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < CR; i++) dp[i][0][i][0] = _m_int_init_int(1);
    for (int cs = 0; cs < CR; cs++) {
        for (int i = 0; i < BITS; i++) {
            for (int ct = 0; ct < CR; ct++) {
                for (int x = 0; x < (1 << BITS); x++) {
                    if (dp[cs][i][ct][x].val != 0) {
                        for (int cc = 0; cc < CR + 1; cc++) {
                            dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x] = _m_int_add(dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x], dp[cs][i][ct][x]);
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
    dp2[0][0] = _m_int_init_int(1);
    for (int i = 0; i < 4; i++) {
        int x = (n & ((1 << BITS) - 1));
        n >>= BITS;
        for (int j = 0; j < CR; j++) {
            for (int k = 0; k < CR; k++) {
                dp2[i + 1][k] = _m_int_add(dp2[i + 1][k], _m_int_mul(dp2[i][j], cnt[j][k][x]));
            }
        }
    }
    printf("%d\n", dp2[4][0].val);
}

int main() {
    li n;
    while (scanf("%lld", &n) != EOF) {
        precalc();
        solve(n);
    }
    return 0;
}
