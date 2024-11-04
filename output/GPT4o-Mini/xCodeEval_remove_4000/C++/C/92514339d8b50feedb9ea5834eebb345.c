#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;
typedef unsigned int uint;

#define mod 1000000007

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

inline int sign(int x) {
    return (x > 0) ? 1 : (x < 0) ? -1 : 0;
}

inline void normmod(ll *x, ll m) {
    *x %= m;
    if (*x < 0) *x += m;
}

inline ll id5(ll x, ll y, ll m) {
    ll res = x + y;
    if (res >= m) res -= m;
    return res;
}

inline void id3(ll *x, ll y, ll m) {
    *x += y;
    if (*x >= m) *x -= m;
}

inline ll mulmod(ll x, ll n, ll m) {
    ll res = 0;
    normmod(&x, m);
    normmod(&n, m);
    while (n) {
        if (n & 1) res = id5(res, x, m);
        x = id5(x, x, m);
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

ll pow2(ll v) {
    return 1LL << (63 - __builtin_clzll(v));
}

ll solve2(ll x, ll y, ll k, ll bonus) {
    if (x <= 0 || y <= 0 || k <= 0) return 0;
    if (x < y) {
        ll temp = x;
        x = y;
        y = temp;
    }
    ll ty = pow2(y);
    ll tx = pow2(x);
    ll res;
    ll txk = (tx < k) ? tx : k;
    if (tx == ty) {
        res = txk * ty % mod * (txk + 1 + bonus * 2) % mod;
        id3(&res, solve2(x - tx, tx, k - tx, bonus + tx), mod);
        id3(&res, solve2(y - tx, tx, k - tx, bonus + tx), mod);
        id3(&res, solve2(x - tx, y - tx, k, bonus), mod);
    } else {
        res = txk * y % mod * (txk + 1 + bonus * 2) % mod;
        id3(&res, solve2(x - tx, y, k - tx, bonus + tx), mod);
    }
    return res;
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int x1, y1, x2, y2, k;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &k);
        ll ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
        ans %= mod;
        if (ans < 0) {
            ans += mod;
        }
        printf("%lld\n", ans * powmod(2LL, mod - 2, mod) % mod);
    }
    return 0;
}
