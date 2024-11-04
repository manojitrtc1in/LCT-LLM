#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} pii;

ll dp[20][2][2][10][10];
ll memo[20][2][2][10][10];
ll n;
ll num[20];

void umax(ll *a, ll b) {
    if (*a < b) *a = b;
}

void umin(ll *a, ll b) {
    if (*a > b) *a = b;
}

ll abs_val(ll a) {
    return a > 0 ? a : -a;
}

ll gcd(ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll modpow(ll a, ll n, ll temp) {
    ll res = 1, y = a;
    while (n > 0) {
        if (n & 1) res = (res * y) % temp;
        y = (y * y) % temp;
        n /= 2;
    }
    return res % temp;
}

ll ison(ll mask, ll pos) {
    return (mask & (1 << pos));
}

ll cbit(ll n) {
    ll k = 0;
    while (n) n &= (n - 1), k++;
    return k;
}

ll nbit(ll n) {
    ll k = 0;
    while (n) n /= 2, k++;
    return k;
}

int sgn(ll x) {
    return x < 0 ? -1 : !!x;
}

void inc(ll *x, ll y) {
    *x += y;
    if (*x >= MOD) *x -= MOD;
}

void dec(ll *x, ll y) {
    *x -= y;
    if (*x < 0) *x += MOD;
}

void chmax(ll *x, ll y) {
    if (y > *x) *x = y;
}

void mulm(ll *x, ll y) {
    *x *= y;
    if (*x >= MOD) *x -= MOD;
}

ll xo(ll i) {
    if ((i & 3) == 0) return i;
    if ((i & 3) == 1) return 1;
    if ((i & 3) == 2) return i + 1;
    return 0;
}

ll solve(ll ind, ll ti, ll st, ll f, ll pd) {
    if (ind == n) {
        return ((st > 0ll) && (f == pd));
    }
    if (memo[ind][ti][st][f][pd]) return dp[ind][ti][st][f][pd];
    ll res = 0;
    memo[ind][ti][st][f][pd] = 1ll;
    if (ti) {
        for (ll i = 0; i < num[ind]; i++) {
            if (i == 0) res += solve(ind + 1, 0ll, st, f, i);
            if (i > 0) {
                if (st == 0) res += solve(ind + 1ll, 0ll, 1ll, i, i);
                else res += solve(ind + 1ll, 0ll, st, f, i);
            }
        }
        if (num[ind] == 0) res += solve(ind + 1ll, 1ll, st, f, 0ll);
        else {
            if (st == 0) res += solve(ind + 1ll, 1ll, 1ll, num[ind], num[ind]);
            else res += solve(ind + 1ll, 1ll, st, f, num[ind]);
        }
    } else {
        for (ll i = 0; i < 10; i++) {
            if (i == 0) res += solve(ind + 1, 0ll, st, f, i);
            if (i > 0) {
                if (st == 0) res += solve(ind + 1ll, 0ll, 1ll, i, i);
                else res += solve(ind + 1ll, 0ll, st, f, i);
            }
        }
    }
    return dp[ind][ti][st][f][pd] = res;
}

int main() {
    ll l, r;
    scanf("%lld %lld", &l, &r);
    
    ll k = r;
    n = 0;
    while (r) {
        num[n++] = r % 10;
        r /= 10;
    }
    ll ans = 0;
    memset(dp, 0, sizeof(dp));
    memset(memo, 0, sizeof(memo));
    ans = solve(0, 1, 0, 0, 0);
    
    memset(dp, 0, sizeof(dp));
    memset(memo, 0, sizeof(memo));
    while (l) {
        num[n++] = l % 10;
        l /= 10;
    }
    ans -= solve(0, 1, 0, 0, 0);
    
    n = 0;
    while (k) {
        num[n++] = k % 10;
        k /= 10;
    }
    ans += (num[0] == num[n - 1]);
    printf("%lld\n", ans);
    return 0;
}
