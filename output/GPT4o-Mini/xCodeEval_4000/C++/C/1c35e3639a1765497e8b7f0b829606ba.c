#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 2000010
#define MOD 998244353

typedef long long ll;
typedef struct {
    unsigned int v;
} ModInt;

ModInt fact[MAX_N], ifact[MAX_N];

ModInt normS(unsigned int x) {
    return (x < MOD) ? x : x - MOD;
}

ModInt make(unsigned int x) {
    ModInt m;
    m.v = x;
    return m;
}

ModInt add(ModInt a, ModInt b) {
    return make(normS(a.v + b.v));
}

ModInt sub(ModInt a, ModInt b) {
    return make(normS(a.v + MOD - b.v));
}

ModInt mul(ModInt a, ModInt b) {
    return make((unsigned long long)a.v * b.v % MOD);
}

ModInt inv(ModInt a) {
    ll x, y;
    ll p[] = {a.v, 1, 0}, q[] = {MOD, 0, 1};
    while (q[0]) {
        ll t = p[0] / q[0];
        for (int i = 0; i < 3; i++) {
            ll temp = p[i] - t * q[i];
            p[i] = q[i];
            q[i] = temp;
        }
    }
    if (p[0] < 0) {
        for (int i = 0; i < 3; i++) p[i] = -p[i];
    }
    x = p[1];
    return make(normS(x + MOD));
}

ModInt powMod(ModInt a, ll p) {
    if (p < 0) return inv(a).pow(-p);
    ModInt res = {1}, x = a;
    while (p) {
        if (p & 1) res = mul(res, x);
        x = mul(x, x);
        p >>= 1;
    }
    return res;
}

void InitFact(int N) {
    fact[0] = make(1).v;
    for (int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], make(i).v);
    }
    ifact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        ifact[i] = mul(ifact[i + 1], make(i + 1).v);
    }
}

ModInt Choose(int a, int b) {
    if (b < 0 || a < b) return make(0);
    return mul(mul(fact[a], ifact[b]), ifact[a - b]);
}

ModInt solve(ll N) {
    ModInt res = {0};
    for (int i = 0; i <= N; i++) {
        if (i == 0) {
            for (int j = 1; j <= N; j++) {
                res = add(res, mul(mul(make(-1).v, Choose(N, j)), powMod(make(3).v, j + N * (N - j))));
            }
        } else {
            res = add(res, mul(mul(make(-1).v, Choose(N, i)), 
                sub(powMod(make(3).v, N - i), make(1).v).pow(N) - powMod(make(3).v, (N - i) * N)));
            res = add(res, mul(mul(make(-1).v, Choose(N, i)), powMod(make(3).v, i + N * (N - i))));
        }
    }
    return make(-res.v);
}

int main() {
    int N;
    scanf("%d", &N);
    InitFact(MAX_N);
    ModInt result = solve(N);
    printf("%u\n", result.v);
    return 0;
}
