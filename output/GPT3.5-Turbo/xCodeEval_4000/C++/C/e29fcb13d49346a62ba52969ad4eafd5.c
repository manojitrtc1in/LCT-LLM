#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;
typedef unsigned int uint;
typedef size_t usize;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define arr(T, n) T (*const)[n]
#define c_arr(T, n) const T (*const)[n]

typedef struct {
    i32 first;
    i32 second;
} pair;

i32 gcd(const i32 a, const i32 b) {
    if (a < 0) {
        return gcd(-a, b);
    } else if (b < 0) {
        return gcd(a, -b);
    } else if (a > b) {
        return gcd(b, a);
    } else if (a == 0) {
        return b;
    } else {
        return gcd(b % a, a);
    }
}

i32 lcm(const i32 a, const i32 b) {
    return a / gcd(a, b) * b;
}

pair extgcd(const i32 a, const i32 b) {
    if (b == 0) {
        pair p = {1, 0};
        return p;
    }
    i32 g = gcd(a, b);
    i32 da = b / g;
    pair p = extgcd(b, a % b);
    i32 x = (da + p.second % da) % da;
    i32 y = (g - a * x) / b;
    pair res = {x, y};
    return res;
}

i32 inverse(const i32 a, const i32 mod) {
    return extgcd(a, mod).first;
}

#define mod_value 1000000007

typedef struct {
    i32 v;
} modint_base;

i32 mod() {
    return mod_value;
}

modint_base make(i32 x) {
    modint_base m;
    m.v = x;
    return m;
}

modint_base operator+(const modint_base m) {
    return m;
}

modint_base operator-(const modint_base m) {
    return make(mod() - m.v);
}

modint_base operator+(const modint_base m1, const modint_base m2) {
    return make((m1.v + m2.v) % mod());
}

modint_base operator-(const modint_base m1, const modint_base m2) {
    return make((m1.v + mod() - m2.v) % mod());
}

modint_base operator*(const modint_base m1, const modint_base m2) {
    return make((i64)m1.v * (i64)m2.v % (i64)mod());
}

modint_base operator/(const modint_base m1, const modint_base m2) {
    return m1 * inverse(m2.v, mod());
}

modint_base operator+(const modint_base m, const i64 val) {
    return make((m.v + val) % mod());
}

modint_base operator-(const modint_base m, const i64 val) {
    return make((m.v - val + mod()) % mod());
}

modint_base operator*(const modint_base m, const i64 val) {
    return make((m.v * (val % mod())) % mod());
}

modint_base operator/(const modint_base m, const i64 val) {
    return make((m.v * inverse(val, mod())) % mod());
}

modint_base operator+(const i64 val, const modint_base m) {
    return make((m.v + val) % mod());
}

modint_base operator-(const i64 val, const modint_base m) {
    return make((-m.v + val + mod()) % mod());
}

modint_base operator*(const i64 val, const modint_base m) {
    return make((m.v * (val % mod())) % mod());
}

modint_base operator/(const i64 val, const modint_base m) {
    return make((val * inverse(m.v, mod())) % mod());
}

modint_base operator^(const modint_base m, const i64 n) {
    modint_base ans = make(1);
    modint_base x = m;
    i64 p = n;
    while (p > 0) {
        if (p & 1) {
            ans = ans * x;
        }
        x = x * x;
        p >>= 1;
    }
    return ans;
}

bool operator==(const modint_base m1, const modint_base m2) {
    return m1.v == m2.v;
}

bool operator!=(const modint_base m1, const modint_base m2) {
    return !(m1 == m2);
}

bool operator==(const modint_base m, const i64 val) {
    return m.v == (val % mod() + mod()) % mod();
}

bool operator!=(const modint_base m, const i64 val) {
    return !(m == val);
}

bool operator==(const i64 val, const modint_base m) {
    return m.v == (val % mod() + mod()) % mod();
}

bool operator!=(const i64 val, const modint_base m) {
    return !(val == m);
}

i32 operator()(const modint_base m) {
    return m.v;
}

typedef modint_base modint;

#define popcount(u) (u ? __builtin_popcountll((u64)u) : 0)
#define log2p1(u) (u ? 64 - __builtin_clzll((u64)u) : 0)
#define msbp1(u) log2p1(u)
#define lsbp1(u) __builtin_ffsll(u)
#define clog(u) (u ? log2p1(u - 1) : u)
#define ispow2(u) (u && ((u64)u & (u64)u - 1) == 0)
#define ceil2(u) (1 << clog(u))
#define floor2(u) (u == 0 ? 0 : 1 << (log2p1(u) - 1))
#define btest(mask, ind) (((u64)mask >> ind) & 1)
#define bset(mask, ind) (mask |= (1 << ind))
#define breset(mask, ind) (mask &= ~(1 << ind))
#define bflip(mask, ind) (mask ^= (1 << ind))
#define bset(mask, ind, b) (b ? bset(mask, ind) : breset(mask, ind))
#define bcut(mask, ind) (ind == 0 ? 0 : ((u64)mask << (64 - ind)) >> (64 - ind))

#define chmin(a, b) (a > b ? a = b, true : false)
#define chmax(a, b) (a < b ? a = b, true : false)

#define inf_v(T) ((T)1 << (sizeof(T) * 8 - 2))
#define pi_v(Real) (Real)3.141592653589793238462643383279502884

#define TEN(n) (n == 0 ? 1ULL : TEN(n - 1) * 10ULL)

i32 in_i32() {
    i32 v;
    scanf("%d", &v);
    return v;
}

i64 in_i64() {
    i64 v;
    scanf("%lld", &v);
    return v;
}

bool in_bool() {
    i32 v;
    scanf("%d", &v);
    return v;
}

i32* in_i32_arr(usize n) {
    i32* arr = (i32*)malloc(n * sizeof(i32));
    for (usize i = 0; i < n; i++) {
        arr[i] = in_i32();
    }
    return arr;
}

i64* in_i64_arr(usize n) {
    i64* arr = (i64*)malloc(n * sizeof(i64));
    for (usize i = 0; i < n; i++) {
        arr[i] = in_i64();
    }
    return arr;
}

bool* in_bool_arr(usize n) {
    bool* arr = (bool*)malloc(n * sizeof(bool));
    for (usize i = 0; i < n; i++) {
        arr[i] = in_bool();
    }
    return arr;
}

void out_i32(i32 v) {
    printf("%d", v);
}

void out_i64(i64 v) {
    printf("%lld", v);
}

void out_bool(bool v) {
    printf("%d", v);
}

void out_i32_arr(i32* arr, usize n) {
    for (usize i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        out_i32(arr[i]);
    }
}

void out_i64_arr(i64* arr, usize n) {
    for (usize i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        out_i64(arr[i]);
    }
}

void out_bool_arr(bool* arr, usize n) {
    for (usize i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        out_bool(arr[i]);
    }
}

void outln_i32(i32 v) {
    printf("%d\n", v);
}

void outln_i64(i64 v) {
    printf("%lld\n", v);
}

void outln_bool(bool v) {
    printf("%d\n", v);
}

void outln_i32_arr(i32* arr, usize n) {
    out_i32_arr(arr, n);
    printf("\n");
}

void outln_i64_arr(i64* arr, usize n) {
    out_i64_arr(arr, n);
    printf("\n");
}

void outln_bool_arr(bool* arr, usize n) {
    out_bool_arr(arr, n);
    printf("\n");
}

#define SHOW(...) ((void)0)

#define mod 998244353

typedef modint_base modint;

i32 main() {
    const i32 n = in_i32();
    const i32 m = in_i32();
    bool* a = in_bool_arr(n);
    i32* w = in_i32_arr(n);
    i32 zw = 0;
    i32 ow = 0;
    for (i32 i = 0; i < n; i++) {
        if (a[i]) {
            ow += w[i];
        } else {
            zw += w[i];
        }
    }
    const i32 s = zw + ow;
    modint* inv = (modint*)malloc((2 * m + 1) * sizeof(modint));
    for (i32 d = -m; d <= m; d++) {
        if (s + d > 0) {
            inv[d + m] = make(1) / (s + d);
        }
    }
    modint** dp = (modint**)malloc((m + 1) * sizeof(modint*));
    for (i32 i = 0; i <= m; i++) {
        dp[i] = (modint*)malloc(2 * sizeof(modint));
        dp[i][0] = make(0);
        dp[i][1] = make(0);
    }
    dp[0][0] = make(1);
    dp[0][1] = make(1);
    for (i32 i = 0; i < m; i++) {
        modint** ndp = (modint**)malloc((m + 1) * sizeof(modint*));
        for (i32 j = 0; j <= m; j++) {
            ndp[j] = (modint*)malloc(2 * sizeof(modint));
            ndp[j][0] = make(0);
            ndp[j][1] = make(0);
        }
        for (i32 z = 0; z <= i; z++) {
            i32 o = i - z;
            i32 wz = zw - z;
            i32 wo = ow + o;
            if (wz < 0) {
                continue;
            }
            for (i32 dz = -1; dz <= 0; dz++) {
                i32 nwz = wz + dz;
                i32 nz = z + (-dz);
                if (nwz < 0) {
                    continue;
                }
                modint eps = inv[wz + wo - s + m];
                modint p = make(dz == -1 ? wz : wo) * eps;
                ndp[nz][-dz] += dp[z][-dz] * p;
                ndp[nz][1 + dz] += (p + (2 * dz + 1) * eps) * dp[z][1 + dz];
            }
        }
        for (i32 j = 0; j <= m; j++) {
            free(dp[j]);
        }
        free(dp);
        dp = ndp;
    }
    modint cz = make(0);
    modint co = make(0);
    for (i32 i = 0; i <= m; i++) {
        cz += dp[i][0];
        co += dp[i][1];
    }
    for (i32 i = 0; i < n; i++) {
        outln_i32(w[i] * (a[i] == 0 ? cz : co));
    }
    free(a);
    free(w);
    free(inv);
    for (i32 i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    return 0;
}
