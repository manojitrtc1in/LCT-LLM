#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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

inline void normmod(ll *x, ll m) {
    *x %= m;
    if (*x < 0) *x += m;
}

inline ll id6(ll x, ll y, ll m) {
    ll res = x + y;
    if (res >= m) res -= m;
    return res;
}

inline int id6_int(int x, int y, int m) {
    int res = x + y;
    if (res >= m) res -= m;
    return res;
}

inline void id4(ll *x, ll y, ll m) {
    *x += y;
    if (*x >= m) *x -= m;
}

inline void id4_int(int *x, int y, int m) {
    *x += y;
    if (*x >= m) *x -= m;
}

inline void id2(ll *x, ll y, ll m) {
    *x -= y;
    if (*x < 0) *x += m;
}

inline void id2_int(int *x, int y, int m) {
    *x -= y;
    if (*x < 0) *x += m;
}

inline ll mulmod(ll x, ll n, ll m) {
    ll res = 0;
    normmod(&x, m);
    normmod(&n, m);
    while (n) {
        if (n & 1) res = id6(res, x, m);
        x = id6(x, x, m);
        n >>= 1;
    }
    return res;
}

inline ll powmod(ll x, ll n, ll m) {
    ll res = 1;
    while (n) {
        if (n & 1) res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}

inline ll gcd(ll a, ll b) {
    ll t;
    while (b) {
        a = a % b;
        t = a;
        a = b;
        b = t;
    }
    return a;
}

inline int gcd_int(int a, int b) {
    int t;
    while (b) {
        a = a % b;
        t = a;
        a = b;
        b = t;
    }
    return a;
}

inline ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

inline ll id1(ll a, ll b, ll *x, ll *y) {
    if (!a) {
        *x = 0;
        *y = 1;
        return b;
    }
    ll y1;
    ll d = id1(b % a, a, x, &y1);
    *x = y1 - (b / a) * (*y);
    return d;
}

inline int id3(int v) {
    return 1 << (31 - __builtin_clz(v));
}

int solve2(int x, int y, int k, int bonus, int mod) {
    if (x <= 0 || y <= 0 || k <= 0) return 0;
    if (x < y) {
        int temp = x;
        x = y;
        y = temp;
    }
    if ((x & (x - 1)) == 0) {
        k = (k < x) ? k : x;
        return k * (ll)y % mod * (k + 1 + bonus * 2LL) % mod;
    }
    int ty = id3(y);
    int tx = id3(x);
    ll res;
    int txk = (tx < k) ? tx : k;
    if (tx == ty) {
        res = txk * (ll)ty % mod * (txk + 1 + bonus * 2LL) + solve2(x - tx, tx, k - tx, bonus + tx, mod) +
              solve2(y - tx, tx, k - tx, bonus + tx, mod) + solve2(x - tx, y - tx, k, bonus, mod);
    } else {
        res = txk * (ll)y % mod * (txk + 1 + bonus * 2LL) + solve2(x - tx, y, k - tx, bonus + tx, mod);
    }
    return res % mod;
}

int main() {
    int mod = 1000000007; // Example modulus
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
        printf("%d\n", (int)(ans * powmod(2LL, mod - 2, mod) % mod));
    }
    return 0;
}
