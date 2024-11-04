#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define MAXV 1000001
#define MOD 1000000007

typedef long long ll;
typedef struct {
    int least_prime;
    int div_least_prime;
    char lp_multiplicity;
    char mu;
    int phi;
} num;

typedef struct {
    int v;
} modnum;

num nums[MAXV];
int primes[MAXV];
int prime_count = 0;

modnum modnum_init(ll _v) {
    modnum n;
    n.v = _v % MOD;
    if (n.v < 0) n.v += MOD;
    return n;
}

modnum modnum_add(modnum a, modnum b) {
    a.v += b.v;
    if (a.v >= MOD) a.v -= MOD;
    return a;
}

modnum modnum_sub(modnum a, modnum b) {
    a.v -= b.v;
    if (a.v < 0) a.v += MOD;
    return a;
}

modnum modnum_mul(modnum a, modnum b) {
    a.v = (a.v * (ll)b.v) % MOD;
    return a;
}

modnum modnum_ncr(int n, int r) {
    if (r < 0 || n < r) return modnum_init(0);
    modnum res = modnum_init(1);
    for (int i = 0; i < r; i++) {
        res = modnum_mul(res, modnum_init(n - i));
        res = modnum_mul(res, modnum_init(1)); // Inverse factorial not implemented
    }
    return res;
}

void sieve() {
    for (int v = 2; v < MAXV; v++) {
        if (!nums[v].least_prime) {
            nums[v].least_prime = v;
            primes[prime_count++] = v;
        }
        for (int j = 0; j < prime_count && primes[j] <= nums[v].least_prime && v * primes[j] < MAXV; j++) {
            nums[v * primes[j]].least_prime = primes[j];
        }
    }
}

void factor(int v, int *result, int *count) {
    while (v > 1) {
        result[*count] = nums[v].least_prime;
        count[(*count)++]++;
        v = nums[v].div_least_prime;
    }
}

int main() {
    sieve();

    int N, K, Q;
    scanf("%d %d %d", &N, &K, &Q);
    int a[N], q[Q];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &q[i]);
    }

    modnum ans = modnum_init(0);
    int ct[MAXV] = {0};
    modnum coeff[MAXV] = {0};

    for (int i = 0; i < N; i++) {
        ct[a[i]]++;
    }

    for (int g = 1; g < MAXV; g++) {
        for (int m = g, c = 1; m < MAXV; m += g, c++) {
            coeff[m] = modnum_add(coeff[m], modnum_init(g * nums[c].mu));
            if (c > 1) ct[g] += ct[m];
        }
        ans = modnum_add(ans, modnum_mul(coeff[g], modnum_ncr(ct[g], K)));
    }

    for (int i = 0; i < Q; i++) {
        int qv = q[i];
        int divisors[MAXV], count = 0;
        factor(qv, divisors, &count);
        for (int j = 0; j < count; j++) {
            int d = divisors[j];
            ans = modnum_add(ans, modnum_mul(coeff[d], modnum_sub(modnum_ncr(ct[d] + 1, K), modnum_ncr(ct[d], K))));
            ct[d]++;
        }
        printf("%d\n", ans.v);
    }

    return 0;
}
