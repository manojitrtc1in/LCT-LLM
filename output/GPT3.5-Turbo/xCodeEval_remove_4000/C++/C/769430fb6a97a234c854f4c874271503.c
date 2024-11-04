#include <stdio.h>
#include <stdlib.h>

#define ll long long

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
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

typedef struct {
    ll first;
    ll second;
} pair;

typedef struct {
    ll first;
    pair second;
} ver;

ll xo(ll i) {
    if ((i & 3) == 0) return i;
    if ((i & 3) == 1) return 1;
    if ((i & 3) == 2) return i + 1;
    return 0;
}

ll dp[20][2][2][10][10];
ll memo[20][2][2][10][10];
ll n;
ll num[20];

ll solve(ll ind, ll ti, ll st, ll f, ll pd) {
    if (ind == n) {
        return ((st > 0) && (f == pd));
    }
    if (memo[ind][ti][st][f][pd]) return dp[ind][ti][st][f][pd];
    ll res = 0;
    memo[ind][ti][st][f][pd] = 1;
    if (ti) {
        for (ll i = 0; i < num[ind]; i++) {
            if (i == 0) res += solve(ind + 1, 0, st, f, i);
            if (i > 0) {
                if (st == 0) res += solve(ind + 1, 0, 1, i, i);
                else res += solve(ind + 1, 0, st, f, i);
            }
        }
        if (num[ind] == 0) res += solve(ind + 1, 1, st, f, 0);
        else {
            if (st == 0) res += solve(ind + 1, 1, 1, num[ind], num[ind]);
            else res += solve(ind + 1, 1, st, f, num[ind]);
        }
    }
    else {
        for (ll i = 0; i < 10; i++) {
            if (i == 0) res += solve(ind + 1, 0, st, f, i);
            if (i > 0) {
                if (st == 0) res += solve(ind + 1, 0, 1, i, i);
                else res += solve(ind + 1, 0, st, f, i);
            }
        }
    }
    return dp[ind][ti][st][f][pd] = res;
}

int main() {
    ll i, j, k, l, m, r;
    scanf("%lld %lld", &l, &r);

    i = 0;
    while (r) {
        num[i++] = r % 10;
        r /= 10;
    }
    n = i;
    ll ans = 0;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                for (l = 0; l < 10; l++) {
                    for (m = 0; m < 10; m++) {
                        dp[i][j][k][l][m] = 0;
                        memo[i][j][k][l][m] = 0;
                    }
                }
            }
        }
    }
    ans = solve(0, 1, 0, 0, 0);

    i = 0;
    while (l) {
        num[i++] = l % 10;
        l /= 10;
    }
    n = i;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                for (l = 0; l < 10; l++) {
                    for (m = 0; m < 10; m++) {
                        dp[i][j][k][l][m] = 0;
                        memo[i][j][k][l][m] = 0;
                    }
                }
            }
        }
    }
    ans -= solve(0, 1, 0, 0, 0);

    ans += (num[0] == num[n - 1]);
    printf("%lld", ans);

    return 0;
}
