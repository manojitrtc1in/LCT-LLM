#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000007

typedef long long ll;

typedef struct {
    int a;
    int b;
    int c;
} triple;

inline int bits_count(int v) {
    v = v - ((v >> 1) & 0x55555555);
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
    return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}

inline int bits_count_ll(ll v) {
    int t = v >> 32;
    int p = (v & ((1LL << 32) - 1));
    return bits_count(t) + bits_count(p);
}

unsigned int reverse_bits(unsigned int x) {
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return ((x >> 16) | (x << 16));
}

inline int sign(int x) {
    return (x > 0) ? 1 : (x < 0) ? -1 : 0;
}

inline bool id0(int x) {
    return (x != 0 && (x & (x - 1)) == 0);
}

void add(int* x, int y) {
    *x += y;
    if (*x >= MOD) *x -= MOD;
}

void sub(int* x, int y) {
    *x -= y;
    if (*x < 0) *x += MOD;
}

int id3(int v) {
    return 1 << (31 - __builtin_clz(v));
}

int solve2(int x, int y, int k, int bonus) {
    if (x <= 0 || y <= 0 || k <= 0) return 0;
    if (x < y) {
        int temp = x;
        x = y;
        y = temp;
    }
    int ty = id3(y);
    int tx = id3(x);
    int res;
    int txk = (tx < k) ? tx : k;

    if (tx == ty) {
        res = txk * (ll)ty % MOD * (txk + 1 + bonus * 2LL) % MOD;
        add(&res, solve2(x - tx, tx, k - tx, bonus + tx));
        add(&res, solve2(y - tx, tx, k - tx, bonus + tx));
        add(&res, solve2(x - tx, y - tx, k, bonus));
    } else {
        res = txk * (ll)y % MOD * (txk + 1 + bonus * 2LL) % MOD;
        add(&res, solve2(x - tx, y, k - tx, bonus + tx));
    }
    return res;
}

ll powmod(ll x, ll n, ll m) {
    ll res = 1;
    while (n) {
        if (n & 1) res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int x1, y1, x2, y2, k;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &k);
        int ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
        ans %= MOD;
        if (ans < 0) {
            ans += MOD;
        }
        printf("%d\n", ans * powmod(2LL, MOD - 2, MOD) % MOD);
    }
    return 0;
}
