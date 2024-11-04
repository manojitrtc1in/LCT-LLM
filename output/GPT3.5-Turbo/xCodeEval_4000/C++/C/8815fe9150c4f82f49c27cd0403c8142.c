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

typedef struct {
    u32 v;
} modint_base;

typedef modint_base modint;

#define mod 1000000007

u32 gcd(const u32 a, const u32 b) {
    return a < 0 ? gcd(-a, b) : b < 0 ? gcd(a, -b) : (a > b ? gcd(b, a) : a == 0 ? b : gcd(b % a, a));
}

u32 lcm(const u32 a, const u32 b) {
    return a / gcd(a, b) * b;
}

u32 inverse(const u32 a, const u32 mod) {
    u32 t, nt, r, nr, q, tmp;
    if (a < 0) {
        t = 0;
        nt = 1;
        r = mod;
        nr = a % mod;
    } else {
        t = 1;
        nt = 0;
        r = a;
        nr = mod;
    }
    while (nr != 0) {
        q = r / nr;
        tmp = nt;
        nt = t - q * nt;
        t = tmp;
        tmp = nr;
        nr = r - q * nr;
        r = tmp;
    }
    if (r > 1) {
        return 0;
    }
    if (t < 0) {
        t += mod;
    }
    return t;
}

modint_base make(const u32 x) {
    modint_base m;
    m.v = x;
    return m;
}

modint_base power(modint_base x, ull n) {
    modint_base ans = make(1);
    while (n) {
        if (n & 1) {
            ans = ans * x;
        }
        x = x * x;
        n >>= 1;
    }
    return ans;
}

modint_base inv(const ll v) {
    if (v < 1000000) {
        return small_inv((usize)v);
    } else {
        return make(inverse(v, mod));
    }
}

u32 norm(const u32 x) {
    return x < mod ? x : x - mod;
}

modint_base operator+(const modint_base m) {
    return m;
}

modint_base operator-(const modint_base m) {
    return make(norm(mod - m.v));
}

modint_base operator+(const modint_base m1, const modint_base m2) {
    return make(norm(m1.v + m2.v));
}

modint_base operator-(const modint_base m1, const modint_base m2) {
    return make(norm(m1.v + mod - m2.v));
}

modint_base operator*(const modint_base m1, const modint_base m2) {
    return make((u64)m1.v * (u64)m2.v % (u64)mod);
}

modint_base operator/(const modint_base m1, const modint_base m2) {
    return m1 * inv(m2.v);
}

modint_base operator+(const modint_base m, const ll val) {
    return make(norm(m.v + val % (ll)mod));
}

modint_base operator-(const modint_base m, const ll val) {
    return make(norm(m.v - val % (ll)mod));
}

modint_base operator*(const modint_base m, const ll val) {
    return make((u64)m.v * (u64)(val % (ll)mod) % (u64)mod);
}

modint_base operator/(const modint_base m, const ll val) {
    return make((u64)m.v * (u64)inv(val) % (u64)mod);
}

modint_base operator+(const ll val, const modint_base m) {
    return make(norm(m.v + val % (ll)mod));
}

modint_base operator-(const ll val, const modint_base m) {
    return make(norm(val - m.v % (ll)mod));
}

modint_base operator*(const ll val, const modint_base m) {
    return make((u64)m.v * (u64)(val % (ll)mod) % (u64)mod);
}

modint_base operator/(const ll val, const modint_base m) {
    return make((u64)val * (u64)inv(m.v) % (u64)mod);
}

modint_base operator^(const modint_base m, const ll n) {
    return power(m, n);
}

bool operator==(const modint_base m1, const modint_base m2) {
    return m1.v == m2.v;
}

bool operator!=(const modint_base m1, const modint_base m2) {
    return !(m1 == m2);
}

u32 mod_ref() {
    static u32 mod = 0;
    return mod;
}

void set_mod(const u32 mod) {
    mod_ref() = mod;
}

modint_base small_inv(const usize n) {
    static modint_base in[1000000];
    if (n < sizeof(in) / sizeof(in[0])) {
        return in[n];
    }
    for (usize i = sizeof(in) / sizeof(in[0]); i <= n; i++) {
        in[i] = make(-in[mod % i].v * (mod / i));
    }
    return in[n];
}

modint_base operator+=(modint_base m1, const modint_base m2) {
    return m1 = m1 + m2;
}

modint_base operator-=(modint_base m1, const modint_base m2) {
    return m1 = m1 - m2;
}

modint_base operator*=(modint_base m1, const modint_base m2) {
    return m1 = m1 * m2;
}

modint_base operator/=(modint_base m1, const modint_base m2) {
    return m1 = m1 / m2;
}

modint_base operator+=(modint_base m, const ll val) {
    return m = m + val;
}

modint_base operator-=(modint_base m, const ll val) {
    return m = m - val;
}

modint_base operator*=(modint_base m, const ll val) {
    return m = m * val;
}

modint_base operator/=(modint_base m, const ll val) {
    return m = m / val;
}

bool operator==(const modint_base m, const ll val) {
    return m.v == norm((u32)((ll)mod + val % (ll)mod));
}

bool operator!=(const modint_base m, const ll val) {
    return !(m == val);
}

bool operator==(const ll val, const modint_base m) {
    return m.v == norm((u32)((ll)mod + val % (ll)mod));
}

bool operator!=(const ll val, const modint_base m) {
    return !(val == m);
}

u32 operator()(const modint_base m) {
    return m.v;
}

typedef struct {
    bool* a;
    int* w;
} input_t;

typedef struct {
    modint_base* inv;
    modint_base** dp;
} output_t;

typedef struct {
    int n;
    int m;
    input_t input;
    output_t output;
} args_t;

args_t parse_args() {
    args_t args;
    scanf("%d %d", &args.n, &args.m);
    args.input.a = (bool*)malloc(args.n * sizeof(bool));
    args.input.w = (int*)malloc(args.n * sizeof(int));
    for (int i = 0; i < args.n; i++) {
        int a;
        scanf("%d", &a);
        args.input.a[i] = a;
    }
    for (int i = 0; i < args.n; i++) {
        int w;
        scanf("%d", &w);
        args.input.w[i] = w;
    }
    args.output.inv = (modint_base*)malloc((2 * args.m + 1) * sizeof(modint_base));
    for (int d = -args.m; d <= args.m; d++) {
        if (args.input.s + d > 0) {
            args.output.inv[d + args.m] = inv(args.input.s + d);
        }
    }
    args.output.dp = (modint_base**)malloc((args.m + 1) * sizeof(modint_base*));
    for (int i = 0; i <= args.m; i++) {
        args.output.dp[i] = (modint_base*)malloc(2 * sizeof(modint_base));
        args.output.dp[i][0] = make(0);
        args.output.dp[i][1] = make(0);
    }
    args.output.dp[0][0] = make(1);
    args.output.dp[0][1] = make(1);
    return args;
}

void free_args(args_t args) {
    free(args.input.a);
    free(args.input.w);
    free(args.output.inv);
    for (int i = 0; i <= args.m; i++) {
        free(args.output.dp[i]);
    }
    free(args.output.dp);
}

output_t solve(args_t args) {
    int zw = 0, ow = 0;
    for (int i = 0; i < args.n; i++) {
        (args.input.a[i] ? ow : zw) += args.input.w[i];
    }
    const int s = zw + ow;
    for (int i = 0; i < args.m; i++) {
        modint_base** ndp = (modint_base**)malloc((args.m + 1) * sizeof(modint_base*));
        for (int z = 0; z <= i; z++) {
            const int o = i - z;
            const int wz = zw - z;
            const int wo = ow + o;
            if (wz < 0) {
                continue;
            }
            for (int dz = -1; dz <= 0; dz++) {
                const int nwz = wz + dz;
                const int nz = z + (-dz);
                if (nwz < 0) {
                    continue;
                }
                const modint_base eps = args.output.inv[wz + wo - args.input.s + args.m];
                const modint_base p = make(dz == -1 ? wz : wo) * eps;
                args.output.dp[nz][-dz] += args.output.dp[z][-dz] * p;
                args.output.dp[nz][1 + dz] += (p + (2 * dz + 1) * eps) * args.output.dp[z][1 + dz];
            }
        }
        free(args.output.dp);
        args.output.dp = ndp;
    }
    modint_base cz = make(0), co = make(0);
    for (int i = 0; i <= args.m; i++) {
        cz += args.output.dp[i][0];
        co += args.output.dp[i][1];
    }
    for (int i = 0; i < args.n; i++) {
        printf("%d\n", args.input.w[i] * (args.input.a[i] == 0 ? cz : co));
    }
    return args.output;
}

int main() {
    args_t args = parse_args();
    solve(args);
    free_args(args);
    return 0;
}
