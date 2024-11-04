#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ll long long
#define MOD 1000000007

ll dp[20][2][2][10][10];
ll memo[20][2][2][10][10];
ll n;
ll num[20];

ll solve(ll ind, ll ti, ll st, ll f, ll pd) {
    if (ind == n) {
        return (st > 0 && f == pd);
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
    } else {
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
    ll l, r, k;
    scanf("%lld %lld", &l, &r);
    
    ll idx = 0;
    while (r) {
        num[idx++] = r % 10;
        r /= 10;
    }
    n = idx;
    ll ans = 0;
    memset(dp, 0, sizeof(dp));
    memset(memo, 0, sizeof(memo));
    ans = solve(0, 1, 0, 0, 0);
    
    idx = 0;
    memset(dp, 0, sizeof(dp));
    memset(memo, 0, sizeof(memo));
    k = l;
    while (l) {
        num[idx++] = l % 10;
        l /= 10;
    }
    n = idx;
    ans -= solve(0, 1, 0, 0, 0);
    
    idx = 0;
    while (k) {
        num[idx++] = k % 10;
        k /= 10;
    }
    ans += (num[0] == num[idx - 1]);
    printf("%lld\n", ans);
    
    return 0;
}
