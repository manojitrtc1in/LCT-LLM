#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

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

void add(int* x, int y, int mod) {
    *x += y;
    if (*x >= mod) *x -= mod;
}

int id3(int v) {
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    ++v;
    return v / 2;
}

int solve2(int x, int y, int k, int bonus, int mod) {
    if (x <= 0 || y <= 0 || k <= 0) return 0;
    if (x < y) {
        int temp = x;
        x = y;
        y = temp;
    }
    if ((x & (x - 1)) == 0 && (y & (y - 1)) == 0) {
        k = (k < x) ? k : x;
        return k * (ll)y % mod * (k + 1 + bonus * 2LL) % mod;
    }
    int ty = id3(y);
    int tx = id3(x);
    int res;
    int txk = (tx < k) ? tx : k;
    if (tx == ty) {
        res = txk * (ll)ty % mod * (txk + 1 + bonus * 2LL) % mod;
        add(&res, solve2(x - tx, tx, k - tx, bonus + tx, mod), mod);
        add(&res, solve2(y - tx, tx, k - tx, bonus + tx, mod), mod);
        add(&res, solve2(x - tx, y - tx, k, bonus, mod), mod);
    } else {
        res = txk * (ll)y % mod * (txk + 1 + bonus * 2LL) % mod;
        add(&res, solve2(x - tx, y, k - tx, bonus + tx, mod), mod);
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
    int mod = 1e9 + 7;
    int q;
    scanf("%d", &q);
    while (q--) {
        int x1, y1, x2, y2, k;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &k);
        int ans = solve2(x2, y2, k, 0, mod) - solve2(x1 - 1, y2, k, 0, mod) - solve2(x2, y1 - 1, k, 0, mod) + solve2(x1 - 1, y1 - 1, k, 0, mod);
        ans %= mod;
        if (ans < 0) {
            ans += mod;
        }
        printf("%lld\n", ans * powmod(2LL, mod - 2, mod) % mod);
    }
    return 0;
}
