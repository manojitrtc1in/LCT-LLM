#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int uint;

typedef struct {
    uint _v;
} mint;

typedef struct {
    uint _m;
    unsigned long long im;
} barrett;

barrett bt;

void set_mod(int m) {
    bt._m = m;
    bt.im = (unsigned long long)(-1) / m + 1;
}

uint safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return (uint)x;
}

uint mul(uint a, uint b) {
    unsigned long long z = a;
    z *= b;
    unsigned long long x = (unsigned long long)(((unsigned __int128)(z) * bt.im) >> 64);
    uint v = (uint)(z - x * bt._m);
    if (bt._m <= v) v += bt._m;
    return v;
}

uint mod() {
    return bt._m;
}

mint raw(int v) {
    mint x;
    x._v = v;
    return x;
}

mint mint_init(int v) {
    long long x = (long long)(v % (long long)(mod()));
    if (x < 0) x += mod();
    mint m;
    m._v = (uint)x;
    return m;
}

mint mint_add(mint lhs, mint rhs) {
    lhs._v += rhs._v;
    if (lhs._v >= mod()) lhs._v -= mod();
    return lhs;
}

mint mint_sub(mint lhs, mint rhs) {
    lhs._v += mod() - rhs._v;
    if (lhs._v >= mod()) lhs._v -= mod();
    return lhs;
}

mint mint_mul(mint lhs, mint rhs) {
    lhs._v = mul(lhs._v, rhs._v);
    return lhs;
}

mint mint_pow(mint x, long long n) {
    mint r = {1};
    while (n) {
        if (n & 1) r = mint_mul(r, x);
        x = mint_mul(x, x);
        n >>= 1;
    }
    return r;
}

void solve(int n, int m) {
    set_mod(m);
    mint ways[n + 1];
    mint extras[n + 1];
    ways[1] = raw(1);
    mint sum = raw(0);
    mint extra = raw(0);
    
    for (int i = 1; i <= n; ++i) {
        ways[i] = mint_add(ways[i], sum);
        extra = mint_add(extra, extras[i]);
        ways[i] = mint_add(ways[i], extra);
        
        for (int j = 2; i * j <= n; ++j) {
            extras[i * j] = mint_add(extras[i * j], ways[i]);
            if ((i + 1) * j <= n)
                extras[(i + 1) * j] = mint_sub(extras[(i + 1) * j], ways[i]);
        }
        sum = mint_add(sum, ways[i]);
    }
    printf("%u\n", ways[n]._v);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    solve(n, m);
    return 0;
}
