#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DECIMAL_DIGITS 10
#define STATIC_MOD 998244353

typedef long long LL;

#ifdef STATIC_MOD
const int mod = STATIC_MOD;
#else
int mod;
#endif

typedef struct {
    int x;
} ModInt;

ModInt ModInt_raw(long long x) {
    return (ModInt){(int)x};
}

ModInt ModInt_get(long long x) {
    return ModInt_raw((mod + x % mod) % mod);
}

ModInt ModInt_init(int y) {
    return (ModInt){y >= mod ? y - mod : y};
}

ModInt ModInt_add(ModInt l, ModInt r) {
    long long x = l.x + r.x;
    return ModInt_raw(x >= mod ? x - mod : x);
}

ModInt ModInt_mul(ModInt l, ModInt r) {
    return ModInt_raw((long long)l.x * r.x % mod);
}

ModInt ModInt_inv(ModInt x) {
    long long a = x.x, b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; 
        long long temp = b; b = a; a = temp;
        u -= t * v; 
        temp = v; v = u; u = temp;
    }
    return ModInt_get(u);
}

ModInt ModInt_div(ModInt l, int r) {
    return ModInt_mul(l, ModInt_inv(ModInt_raw(r)));
}

ModInt ModInt_pow(ModInt a, long long x) {
    ModInt ret = ModInt_raw(1);
    while (x) {
        if (x & 1) {
            ret = ModInt_mul(ret, a);
        }
        a = ModInt_mul(a, a);
        x >>= 1;
    }
    return ret;
}

ModInt factorial[3123456];
ModInt inverse_factorial[3123456];
bool is_build = false;

void factorial_build() {
    is_build = true;
    factorial[0] = ModInt_raw(1);
    for (int i = 1; i < 3123456; i++) {
        factorial[i] = ModInt_mul(factorial[i - 1], ModInt_raw(i));
    }
    inverse_factorial[3123455] = ModInt_inv(factorial[3123455]);
    for (int i = 3123455; i >= 1; i--) {
        inverse_factorial[i - 1] = ModInt_mul(inverse_factorial[i], ModInt_raw(i));
    }
}

ModInt combination(int n, int k) {
    if (k < 0 || k > n) return ModInt_raw(0);
    if (!is_build) factorial_build();
    return ModInt_mul(factorial[n], ModInt_mul(inverse_factorial[k], inverse_factorial[n - k]));
}

ModInt multiChoose(int n, int r) {
    if (n == 0) {
        return ModInt_raw(r == 0 ? 1 : 0);
    }
    if (r == 0) {
        return ModInt_raw(1);
    }
    return combination(n + r - 1, r);
}

ModInt multiChoose_limited(int n, int r, int lim) {
    if (n == 0) {
        return ModInt_raw(r == 0 ? 1 : 0);
    }
    if (lim <= 0 && r > 0) {
        return ModInt_raw(0);
    }
    if (r == 0) {
        return ModInt_raw(lim < 0 ? 0 : 1);
    }
    ModInt ret = ModInt_raw(0);
    for (int i = 0; i <= n; i++) {
        if (i * (lim + 1) > r) break;
        ret = ModInt_add(ret, ModInt_mul(ModInt_init(i & 1 ? mod - 1 : 1), 
            ModInt_mul(combination(n, i), multiChoose(n, r - i * (lim + 1)))));
    }
    return ret;
}

int main() {
    int p, s, r;
    scanf("%d%d%d", &p, &s, &r);
    ModInt ret = ModInt_raw(0);
    for (int top = r; top <= s; top++) {
        ModInt tot = ModInt_raw(0);
        for (int q = 0; q < p; q++) {
            if (top * q > s - top) break;
            tot = ModInt_add(tot, ModInt_mul(ModInt_mul(combination(p - 1, q), 
                multiChoose_limited(p - q - 1, s - top - top * q, top - 1)), 
                ModInt_inv(q + 1)));
        }
        ret = ModInt_add(ret, tot);
    }
    ret = ModInt_mul(ret, ModInt_inv(multiChoose(p, s - r)));
    printf("%lld\n", ret.x);
    return 0;
}
