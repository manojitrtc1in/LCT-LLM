#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005
#define MOD 998244353

typedef long long ll;

ll powMod(ll base, ll pow, ll mod) {
    ll x = 1;
    while (pow > 0) {
        if (pow & 1) {
            x = (x * base) % mod;
        }
        base = (base * base) % mod;
        pow >>= 1;
    }
    return x;
}

ll mulMod(ll a, ll b, ll mod) {
    return (a * b) % mod;
}

ll subMod(ll a, ll b, ll mod) {
    ll res = a - b;
    if (res < 0) {
        res += mod;
    }
    return res;
}

ll addMod(ll a, ll b, ll mod) {
    ll res = a + b;
    if (res >= mod) {
        res -= mod;
    }
    return res;
}

ll choose(ll N, ll K, ll mod) {
    ll res = 1;
    for (ll i = 1; i <= K; i++) {
        res = mulMod(res, N - i + 1, mod);
        res = mulMod(res, powMod(i, mod - 2, mod), mod);
    }
    return res;
}

int main() {
    int N;
    ll K, A[MAXN];
    ll cnt = 0;
    ll ans = 0;

    scanf("%d %lld", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }
    A[0] = A[N];
    if (K == 1) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < N; i++) {
        cnt += A[i] != A[i + 1];
    }
    for (int i = 0; i * 2 <= cnt; i++) {
        ll add = mulMod(choose(cnt, i, MOD), choose(cnt - i, i, MOD), MOD);
        add = mulMod(add, powMod(K, N - cnt, MOD), MOD);
        add = mulMod(add, powMod(K - 2, cnt - 2 * i, MOD), MOD);
        ans = addMod(ans, add, MOD);
    }
    ans = subMod(powMod(K, N, MOD), ans, MOD);
    ans = mulMod(ans, powMod(2, MOD - 2, MOD), MOD);
    printf("%lld\n", ans);
    return 0;
}
