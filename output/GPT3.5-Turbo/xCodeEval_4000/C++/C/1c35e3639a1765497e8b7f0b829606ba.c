#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define MOD 998244353

typedef struct {
    ll v;
} mint;

mint make(ll x) {
    mint m;
    m.v = x;
    return m;
}

mint add(mint a, mint b) {
    return make((a.v + b.v) % MOD);
}

mint sub(mint a, mint b) {
    return make((a.v - b.v + MOD) % MOD);
}

mint mul(mint a, mint b) {
    return make((a.v * b.v) % MOD);
}

mint pow(mint a, ll p) {
    mint res = make(1);
    while (p > 0) {
        if (p & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        p >>= 1;
    }
    return res;
}

mint inv(mint a) {
    return pow(a, MOD - 2);
}

mint div(mint a, mint b) {
    return mul(a, inv(b));
}

mint fact[2000010];
mint ifact[2000010];

void initFact(int N) {
    fact[0] = make(1);
    for (int i = 1; i <= N; i++) {
        fact[i] = mul(fact[i - 1], make(i));
    }
    ifact[N] = inv(fact[N]);
    for (int i = N - 1; i >= 0; i--) {
        ifact[i] = mul(ifact[i + 1], make(i + 1));
    }
}

mint choose(int a, int b) {
    if (b < 0 || a < b) {
        return make(0);
    }
    return mul(mul(fact[a], ifact[b]), ifact[a - b]);
}

mint solve(ll N) {
    mint res = make(0);
    for (int i = 0; i <= N; i++) {
        if (i == 0) {
            for (int j = 1; j <= N; j++) {
                res = add(res, mul(pow(make(-1), i + j), mul(choose(N, j), pow(make(3), j + N * (N - j)))));
            }
        } else {
            res = add(res, mul(mul(pow(make(-1), i), choose(N, i)), sub(pow(sub(pow(make(3), N - i), make(1)), N), pow(make(3), (N - i) * N)))));
            res = add(res, mul(mul(pow(make(-1), i), choose(N, i)), mul(pow(make(3), i + N * (N - i)), make(3))));
        }
    }
    return sub(make(0), res);
}

int main() {
    ll N;
    scanf("%lld", &N);
    initFact(2000010);
    mint ans = solve(N);
    printf("%lld\n", ans.v);
    return 0;
}
