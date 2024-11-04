#include <stdio.h>
#include <string.h>

#define ll long long

ll dp[20][2][2][10][10];
ll memo[20][2][2][10][10];
ll n;
ll num[20];

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
    }
    else {
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
    ll i, j, k, l, m, r;
    scanf("%lld %lld", &l, &r);

    memset(dp, 0, sizeof(dp));
    memset(memo, 0, sizeof(memo));

    k = r;
    n = 0;
    while (r) {
        num[n++] = r % 10;
        r /= 10;
    }
    ll ans = 0;
    ans = solve(0, 1, 0, 0, 0);

    memset(dp, 0, sizeof(dp));
    memset(memo, 0, sizeof(memo));

    n = 0;
    while (l) {
        num[n++] = l % 10;
        l /= 10;
    }
    ans -= solve(0, 1, 0, 0, 0);

    ans += (num[0] == num[n - 1ll]);
    printf("%lld\n", ans);

    return 0;
}
