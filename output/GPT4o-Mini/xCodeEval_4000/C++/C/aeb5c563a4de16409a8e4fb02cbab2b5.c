#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_N 1000
#define MAX_K 1000
#define MOD 998244353

typedef long long ll;

ll a[MAX_N][MAX_N];
ll w[MAX_N];
ll dp[MAX_K + 1];
ll ans = 0;

void chmax(ll *a, ll b) {
    if (*a < b) {
        *a = b;
    }
}

void solve(void (*solve)(void (*)(void), ll *, ll, ll), ll *dp, ll l, ll r) {
    if (r - l == 1) {
        ll sum = 0;
        for (int i = 0; i <= a[l][0]; i++) {
            chmax(&ans, dp[MAX_K - i] + sum);
            if (i != a[l][0]) sum += a[l][i + 1];
        }
        return;
    }
    ll m = (r + l) / 2;
    ll dp2[MAX_K + 1];
    memcpy(dp2, dp, sizeof(dp2));
    for (int i = m; i < r; i++) {
        for (int j = MAX_K - 1; j >= 0; j--) {
            if (a[i][0] + j <= MAX_K) {
                chmax(&dp2[j + a[i][0]], dp2[j] + w[i]);
            }
        }
    }
    solve(solve, dp2, l, m);
    for (int i = l; i < m; i++) {
        for (int j = MAX_K - 1; j >= 0; j--) {
            if (a[i][0] + j <= MAX_K) {
                chmax(&dp[j + a[i][0]], dp[j] + w[i]);
            }
        }
    }
    solve(solve, dp, m, r);
}

int main() {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    
    for (ll i = 0; i < n; i++) {
        ll t;
        scanf("%lld", &t);
        a[i][0] = t; // Store size
        for (ll j = 1; j <= t; j++) {
            scanf("%lld", &a[i][j]);
        }
        w[i] = 0;
        for (ll j = 1; j <= t; j++) {
            w[i] += a[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    solve(solve, dp, 0, n);
    printf("%lld\n", ans);

    return 0;
}
