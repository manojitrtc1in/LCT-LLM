#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef long long ll;
typedef struct {
    ll v;
} mint;

mint mod = {998244353};

mint normS(ll x) {
    return (x < mod.v) ? (mint){x} : (mint){x - mod.v};
}

mint make(ll x) {
    return normS(x);
}

mint add(mint a, mint b) {
    return make(a.v + b.v);
}

mint sub(mint a, mint b) {
    return make(a.v + mod.v - b.v);
}

mint mul(mint a, mint b) {
    return make((a.v * b.v) % mod.v);
}

mint inv(mint a) {
    ll x, y;
    ll p[] = {a.v, 1, 0}, q[] = {mod.v, 0, 1};
    while (q[0]) {
        ll t = p[0] / q[0];
        for (int i = 0; i < 3; i++) {
            ll temp = p[i] - t * q[i];
            p[i] = q[i];
            q[i] = temp;
        }
    }
    if (p[0] < 0) {
        for (int i = 0; i < 3; i++) {
            p[i] = -p[i];
        }
    }
    x = p[1];
    return make(normS(x + mod.v));
}

mint pow(mint a, ll p) {
    if (p < 0) return inv(a).pow(-p);
    mint res = {1};
    while (p) {
        if (p & 1) res = mul(res, a);
        a = mul(a, a);
        p >>= 1;
    }
    return res;
}

void InitFact(int N, mint* fact, mint* ifact) {
    fact[0] = (mint){1};
    for (int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], (mint){i});
    }
    ifact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        ifact[i] = mul(ifact[i + 1], (mint){i + 1});
    }
}

mint Choose(int a, int b, mint* fact, mint* ifact) {
    if (b < 0 || a < b) return (mint){0};
    return mul(mul(fact[a], ifact[b]), ifact[a - b]);
}

int main() {
    int N;
    scanf("%d", &N);
    
    mint fact[2000010], ifact[2000010];
    InitFact(2000010, fact, ifact);

    mint res = {0};
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            int a = i, b = j;
            if (a > b) {
                int temp = a;
                a = b;
                b = temp;
            }
            if (b == 0) continue;
            if (a == 0) {
                res = add(res, mul(mul((mint){-1}, pow((mint){-1}, i + j)), Choose(N, b, fact, ifact)));
                res = add(res, pow((mint){3}, b.v + N * (N - b)));
            } else {
                res = add(res, mul(mul(mul((mint){-1}, pow((mint){-1}, i + j)), Choose(N, a, fact, ifact)), Choose(N, b, fact, ifact)));
                res = add(res, mul((mint){3}, pow((mint){3}, (N - a) * (N - b))));
            }
        }
    }
    printf("%lld\n", res.v);
    return 0;
}
