#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

#define MAXN 200005
#define MOD 998244353

typedef long long ll;

ll fact[MAXN], invFact[MAXN];

void init_comb(int N) {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[N] = pow(fact[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

ll mulMod(ll a, ll b) {
    return (a * b) % MOD;
}

ll addMod(ll a, ll b) {
    return (a + b) % MOD;
}

ll subMod(ll a, ll b) {
    return (a - b + MOD) % MOD;
}

ll powMod(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = mulMod(result, base);
        }
        base = mulMod(base, base);
        exp >>= 1;
    }
    return result;
}

ll choose(int N, int K) {
    if (K > N || K < 0) return 0;
    return mulMod(mulMod(fact[N], invFact[K]), invFact[N - K]);
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

    init_comb(N);
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += A[i] != A[i + 1];
    }

    ll ans = 0;
    for (int i = 0; i * 2 <= cnt; i++) {
        ll add = mulMod(choose(cnt, i), choose(cnt - i, i));
        add = mulMod(add, powMod(K, N - cnt));
        add = mulMod(add, powMod(K - 2, cnt - 2 * i));
        ans = addMod(ans, add);
    }

    ans = subMod(powMod(K, N), ans);
    ans = mulMod(ans, powMod(2, MOD - 2));
    printf("%lld\n", ans);
    return 0;
}
