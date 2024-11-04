#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005
#define MOD 998244353

typedef long long ll;

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll inverse(ll a) {
    return power(a, MOD - 2);
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll sub(ll a, ll b) {
    return (a - b + MOD) % MOD;
}

ll f[MAXN][2];
ll h[MAXN][2];
ll inv[MAXN * 2 + 1];

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[MAXN];
    int count[2] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        count[a[i] % 2]++;
    }
    int w[MAXN];
    int fW = 0, hW = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        if (a[i] % 2 == 0) {
            hW += w[i];
        } else {
            fW += w[i];
        }
    }

    for (int i = 0; i <= m * 2; i++) {
        inv[i] = inverse(hW + fW + i - m);
    }

    for (int i = 0; i <= m; i++) {
        f[i][0] = 1;
        h[i][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            printf("%lld\n", mul(w[i], f[0][m]));
        } else {
            printf("%lld\n", mul(w[i], h[0][m]));
        }
    }
}

int main() {
    solve();
    return 0;
}
