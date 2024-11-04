#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 1010101
#define MAX_FACT 201010
#define MAX_REV_FACT 202020
#define FFTMOD 1000000007

long long a[MAX_SIZE];
long long fact[MAX_FACT];
long long revFact[MAX_REV_FACT];

long long powmod(long long x, long long n, long long m) {
    long long r = 1;
    x %= m;
    while (n) {
        if (n & 1) r = (r * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return r;
}

long long cnk(int n, int k) {
    return (fact[n] * revFact[k] % FFTMOD * revFact[n - k]) % FFTMOD;
}

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= 200000; ++i) {
        fact[i] = (fact[i - 1] * i) % FFTMOD;
    }
    revFact[200000] = powmod(fact[200000], FFTMOD - 2, FFTMOD);
    for (int i = 199999; i >= 0; --i) {
        revFact[i] = (revFact[i + 1] * (i + 1)) % FFTMOD;
    }
}

int solve() {
    precompute_factorials();

    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    a[n] = a[0];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += a[i] != a[i + 1];
    }
    if (k == 1 || n == 1) {
        printf("0\n");
        return 0;
    }
    long long ans = 0;
    int freeChoices = k - 2;
    for (int i = 0; i <= cnt / 2; ++i) {
        long long cur = (cnk(cnt, i) * cnk(cnt - i, i) % FFTMOD * powmod(freeChoices, cnt - 2 * i, FFTMOD) % FFTMOD * powmod(k, n - cnt, FFTMOD)) % FFTMOD;
        ans += cur;
    }
    ans %= FFTMOD;
    long long tot = (powmod(k, n, FFTMOD) - ans + FFTMOD) % FFTMOD;
    printf("%lld\n", (tot * powmod(2, FFTMOD - 2, FFTMOD)) % FFTMOD);

    return 0;
}

int main() {
    solve();
    return 0;
}
