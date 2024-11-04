#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <math.h>

#define MAXN 200005
#define MOD 998244353

typedef long long ll;

ll fact[MAXN], invFact[MAXN];

void init(int N) {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

ll mulMod(ll a, ll b, ll mod) {
    return (a * b) % mod;
}

ll powMod(ll base, ll pow, ll mod) {
    ll x = 1;
    while (pow > 0) {
        if (pow & 1) x = mulMod(x, base, mod);
        base = mulMod(base, base, mod);
        pow >>= 1;
    }
    return x;
}

ll mulInvPrime(ll i, ll p) {
    return powMod(i, p - 2, p);
}

ll divModPrime(ll i, ll j, ll p) {
    return mulMod(i, mulInvPrime(j, p), p);
}

void initWithMod(int N, ll P) {
    assert(N < P);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = mulMod(fact[i - 1], i, P);
    }
    invFact[N] = mulInvPrime(fact[N], P);
    for (int i = N - 1; i >= 0; i--) {
        invFact[i] = mulMod(invFact[i + 1], i + 1, P);
    }
}

ll choose(int N, int K, ll P) {
    return mulMod(mulMod(fact[N], invFact[K], P), invFact[N - K], P);
}

int main() {
    int N;
    ll K, A[MAXN];

    scanf("%d %lld", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }
    A[0] = A[N];

    if (K == 1) {
        printf("0\n");
        return 0;
    }

    initWithMod(N, MOD);
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += A[i] != A[i + 1];
    }

    ll ans = 0;
    for (int i = 0; i * 2 <= cnt; i++) {
        ll add = mulMod(choose(cnt, i, MOD), choose(cnt - i, i, MOD), MOD);
        add = mulMod(add, powMod(K, N - cnt, MOD), MOD);
        add = mulMod(add, powMod(K - 2, cnt - 2 * i, MOD), MOD);
        ans = (ans + add) % MOD;
    }

    ans = (powMod(K, N, MOD) - ans + MOD) % MOD;
    ans = divModPrime(ans, 2LL, MOD);
    printf("%lld\n", ans);
    return 0;
}
