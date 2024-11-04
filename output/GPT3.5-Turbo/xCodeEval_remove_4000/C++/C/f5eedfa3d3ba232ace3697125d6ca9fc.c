#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 1010101
#define MAX_K 202020
#define MOD 1000000007

int a[MAX_N];
int fact[MAX_K];
int revFact[MAX_K];

long long cnk(int n, int k) {
    return (fact[n] * 1LL * revFact[k] % MOD * revFact[n - k] % MOD);
}

int solve() {
    fact[0] = 1;
    const int N = 200000;
    for (int i = 1; i <= N; ++i) {
        fact[i] = (fact[i - 1] * 1LL * i) % MOD;
    }
    revFact[N] = powmod(fact[N], MOD - 2, MOD);
    for (int i = N - 1; i >= 0; --i) {
        revFact[i] = (revFact[i + 1] * (i + 1LL)) % MOD;
    }
    
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    a[n] = a[0];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += (a[i] != a[i + 1]);
    }
    if (k == 1 || n == 1) {
        printf("0\n");
        return 0;
    }
    long long ans = 0;
    int freeChoices = k - 2;
    for (int i = 0; i <= cnt / 2; ++i) {
        long long cur = (cnk(cnt, i) * cnk(cnt - i, i) % MOD * powmod(freeChoices, cnt - 2 * i, MOD) % MOD * powmod(k, n - cnt, MOD) % MOD);
        ans += cur;
    }
    ans %= MOD;
    long long tot = (powmod(k, n, MOD) - ans);
    if (tot < 0) tot += MOD;
    printf("%lld\n", tot * powmod(2, MOD - 2, MOD) % MOD);
    
    return 0;
}

int main() {
    solve();
    return 0;
}
