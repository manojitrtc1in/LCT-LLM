#include <stdio.h>
#include <stdlib.h>

#define mod 1000000007

typedef long long ll;

void add(ll* x, ll y) {
    *x += y;
    if (*x >= mod) *x -= mod;
}

void sub(ll* x, ll y) {
    *x -= y;
    if (*x < 0) *x += mod;
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
    ll txk = tx < k ? tx : k;
    if (tx == ty) {
        res = txk * ty % mod * (txk + 1 + bonus * 2) % mod;
        add(&res, solve2(x - tx, tx, k - tx, bonus + tx));
        add(&res, solve2(y - tx, tx, k - tx, bonus + tx));
        add(&res, solve2(x - tx, y - tx, k, bonus));
    } else {
        res = txk * y % mod * (txk + 1 + bonus * 2) % mod;
        add(&res, solve2(x - tx, y, k - tx, bonus + tx));
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
