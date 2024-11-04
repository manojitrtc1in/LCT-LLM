#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD 998244353
#define MAXN 400000

long fact[MAXN + 1];
long revFact[MAXN + 1];

void preFact(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    revFact[n] = pow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        revFact[i] = (revFact[i + 1] * (i + 1)) % MOD;
    }
}

long mul(long x, long y) {
    return (x * y) % MOD;
}

long div(long x, long y) {
    return (x * pow(y, MOD - 2)) % MOD;
}

long pow(long x, long y) {
    if (y < 0) return 0;
    if (y == 0) return 1;
    if (y % 2 == 1) return (x * pow(x, y - 1)) % MOD;
    long root = pow(x, y / 2);
    return (root * root) % MOD;
}

long cmb(int a, int b) {
    if (a < b) return 0;
    return mul(mul(fact[a], revFact[b]), revFact[a - b]);
}

void solve() {
    int n;
    long tmp;
    scanf("%d %ld", &n, &tmp);
    if (n <= tmp) {
        printf("0\n");
        return;
    }
    int k = (int)tmp;
    preFact(MAXN);
    long ans = 0;
    long t = cmb(n, n - k);
    int si = 1;
    for (int i = n - k; i >= 1; i--) {
        ans = (ans + si * cmb(n - k, i) * pow(i, n)) % MOD;
        if (ans < 0) ans += MOD;
        si *= -1;
    }
    ans = (ans * t) % MOD;
    if (k != 0) ans = (ans * 2) % MOD;
    if (ans < 0) ans += MOD;
    printf("%ld\n", ans);
}

int main() {
    solve();
    return 0;
}
