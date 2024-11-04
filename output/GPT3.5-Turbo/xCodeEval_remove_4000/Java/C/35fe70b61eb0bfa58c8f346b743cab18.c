#include <stdio.h>
#include <stdlib.h>

#define mod 998244353

long fact[400001];
long revFact[400001];

void preFact(int n) {
    fact[0] = 1;
    for (int i = 0; i < n; i++) {
        fact[i + 1] = (i + 1) * fact[i] % mod;
    }
    revFact[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        revFact[i] = (i + 1) * revFact[i + 1] % mod;
    }
}

long cmb(int a, int b) {
    if (a < b) return 0;
    long af = fact[a];
    long bf = revFact[b];
    long abf = revFact[a - b];
    long res = af * bf % mod * abf % mod;
    return res;
}

long pow(long x, long y) {
    if (y < 0) return 0;
    if (y == 0) return 1;
    if (y % 2 == 1) return (x * pow(x, y - 1)) % mod;
    long root = pow(x, y / 2);
    return root * root % mod;
}

void solve() {
    int n;
    scanf("%d", &n);
    long tmp;
    scanf("%ld", &tmp);
    if (n <= tmp) {
        printf("0\n");
        return;
    }
    int k = (int)tmp;
    preFact(400000);
    long ans = 0;
    int si = 1;
    long t = cmb(n, n - k);
    for (int i = n - k; i >= 1; i--) {
        ans += si * cmb(n - k, i) * pow(i, n);
        ans %= mod;
        if (ans < 0) ans += mod;
        si *= -1;
    }
    ans *= t;
    ans %= mod;
    if (k != 0) ans *= 2;
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%ld\n", ans);
}

int main() {
    solve();
    return 0;
}
