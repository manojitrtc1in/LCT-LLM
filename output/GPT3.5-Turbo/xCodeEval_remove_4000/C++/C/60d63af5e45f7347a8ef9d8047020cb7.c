#include <stdio.h>
#include <stdlib.h>

#define mod 1000000007

typedef long long ll;

ll powmod(ll x, ll n, ll m) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}

int id3(int v) {
    return 1 << (31 - __builtin_clz(v));
}

int solve2(int x, int y, int k, int bonus) {
    if (x <= 0 || y <= 0 || k <= 0)
        return 0;
    if (x < y)
        swap(x, y);
    if ((x & (x - 1)) == 0) {
        k = min(k, x);
        return k * (ll) y % mod * (k + 1 + bonus * 2LL) % mod;
    }
    int ty = id3(y);
    int tx = id3(x);
    ll res;
    int txk = min(tx, k);
    if (tx == ty) {
        res = txk * (ll) ty % mod * (txk + 1 + bonus * 2LL) + solve2(x - tx, tx, k - tx, bonus + tx) +
              solve2(y - tx, tx, k - tx, bonus + tx) + solve2(x - tx, y - tx, k, bonus);
    } else {
        res = txk * (ll) y % mod * (txk + 1 + bonus * 2LL) + solve2(x - tx, y, k - tx, bonus + tx);
    }
    return res % mod;
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int x1, y1, x2, y2, k;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &k);
        int ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
        ans %= mod;
        if (ans < 0) {
            ans += mod;
        }
        printf("%d\n", (int) (ans * powmod(2LL, mod - 2, mod) % mod));
    }
    return 0;
}