#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define T9          1000000000
#define T18         1000000000000000000LL
#define INF         1011111111
#define LLINF       1000111000111000111LL
#define mod         1000000007
#define fftmod      998244353

int a[1010101];
int fact[201010];
int revFact[202020];

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
    return fact[n] * 1LL * revFact[k] % fftmod * revFact[n - k] % fftmod;
}

int main() {
    fact[0] = 1;
    const int N = 200000;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i - 1] * 1LL * i % fftmod;
    }
    revFact[N] = (int)powmod(fact[N], fftmod - 2, fftmod);
    for (int i = N - 1; i >= 0; --i) {
        revFact[i] = revFact[i + 1] * (i + 1LL) % fftmod;
    }
    
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
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
        long long cur = cnk(cnt, i) * cnk(cnt - i, i) % fftmod * powmod(freeChoices, cnt - 2 * i, fftmod) % fftmod * powmod(k, n - cnt, fftmod) % fftmod;
        ans += cur;
    }
    ans %= fftmod;
    long long tot = powmod(k, n, fftmod) - ans;
    if (tot < 0) tot += fftmod;
    printf("%lld\n", tot * powmod(2, fftmod - 2, fftmod) % fftmod);
    
    return 0;
}
