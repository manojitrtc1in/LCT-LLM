#include <stdio.h>
#include <stdbool.h>

#define MAXN 200005

typedef long long ll;

ll powMod(ll base, ll pow, ll mod) {
    ll x = 1;
    for (; pow > 0; pow >>= 1, base = (base * base) % mod) {
        if (pow & 1) {
            x = (x * base) % mod;
        }
    }
    return x;
}

ll mulMod(ll a, ll b, ll mod) {
    return (a * b) % mod;
}

ll subMod(ll a, ll b, ll mod) {
    ll ret = a - b;
    return (ret < 0) ? ret + mod : ret;
}

ll addMod(ll a, ll b, ll mod) {
    ll ret = a + b;
    return (ret < mod) ? ret : ret - mod;
}

ll mulInvPrime(ll i, ll p) {
    return powMod(i, p - 2, p);
}

ll divModPrime(ll i, ll j, ll p) {
    return mulMod(i, mulInvPrime(j, p), p);
}

typedef struct {
    ll fact[MAXN];
    ll invFact[MAXN];
} Combinatorics;

void init(Combinatorics* comb, int N, ll P) {
    comb->fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        comb->fact[i] = mulMod(comb->fact[i - 1], i, P);
    }
    comb->invFact[N] = mulInvPrime(comb->fact[N], P);
    for (int i = N - 1; i >= 0; i--) {
        comb->invFact[i] = mulMod(comb->invFact[i + 1], i + 1, P);
    }
}

ll factorial(Combinatorics* comb, int N) {
    return comb->fact[N];
}

ll invFactorial(Combinatorics* comb, int N) {
    return comb->invFact[N];
}

ll permute(Combinatorics* comb, int N, int K, ll P) {
    return mulMod(comb->fact[N], comb->invFact[N - K], P);
}

ll choose(Combinatorics* comb, int N, int K, ll P) {
    return mulMod(mulMod(comb->fact[N], comb->invFact[K], P), comb->invFact[N - K], P);
}

ll multiChoose(Combinatorics* comb, int N, int K, ll P) {
    return choose(comb, N + K - 1, K, P);
}

ll comb_choose(ll cnt, ll i, ll P) {
    ll ret = 1;
    for (ll j = 1; j <= i; j++) {
        ret = mulMod(ret, cnt - j + 1, P);
        ret = mulMod(ret, mulInvPrime(j, P), P);
    }
    return ret;
}

ll comb_multiChoose(ll cnt, ll i, ll P) {
    return comb_choose(cnt + i - 1, i, P);
}

int main() {
    int N;
    ll K, A[MAXN];
    Combinatorics comb;

    scanf("%d %lld", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }
    A[0] = A[N];
    if (K == 1) {
        printf("0\n");
        return 0;
    }
    init(&comb, N, MOD);
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += A[i] != A[i + 1];
    }
    ll ans = 0;
    for (int i = 0; i * 2 <= cnt; i++) {
        ll add = mulMod(comb_choose(cnt, i, MOD), comb_choose(cnt - i, i, MOD), MOD);
        add = mulMod(add, powMod(K, N - cnt, MOD), MOD);
        add = mulMod(add, powMod(K - 2, cnt - 2 * i, MOD), MOD);
        ans = addMod(ans, add, MOD);
    }
    ans = subMod(powMod(K, N, MOD), ans, MOD);
    ans = divModPrime(ans, 2LL, MOD);
    printf("%lld\n", ans);
    return 0;
}
