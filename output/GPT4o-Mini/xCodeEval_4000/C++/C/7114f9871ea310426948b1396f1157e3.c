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
    num nums[MAXV];
    int primes[MAXV];
    int prime_count;
} sieve;

sieve sv;

void sieve_init() {
    sv.prime_count = 0;
    sv.nums[1] = (num){INT_MAX, 1, 0, 1, 1};
    for (int v = 2; v < MAXV; v++) {
        num* n = &sv.nums[v];
        if (!n->least_prime) {
            *n = sv.nums[1];
            n->least_prime = v;
            sv.primes[sv.prime_count++] = v;
        }
        for (int j = 0; j < sv.prime_count; j++) {
            int p = sv.primes[j];
            if (p > n->least_prime || v * p >= MAXV) break;
            sv.nums[v * p] = (num){p, v, 1, -n->mu, n->phi * (p - 1)};
        }
    }
}

int eliminate_least_prime(int v) {
    for (int m = sv.nums[v].lp_multiplicity; m > 0; m--)
        v = sv.nums[v].div_least_prime;
    return v;
}

void for_each_divisor_unordered(int v, void (*f)(int), int c) {
    if (v == 1) { f(c); return; }
    int w = eliminate_least_prime(v);
    for (int m = 0; m <= sv.nums[v].lp_multiplicity; m++, c *= sv.nums[v].least_prime)
        for_each_divisor_unordered(w, f, c);
}

void intro(int v, ll* ans, ll* coeff, int* ct) {
    for_each_divisor_unordered(v, [&](int d) {
        *ans += coeff[d] * (ncr(ct[d] + 1, K) - ncr(ct[d], K));
        ct[d]++;
    }, 1);
}

ll ncr(int n, int r) {
    if (r < 0 || n < r) return 0;
    return factorial(n) * inverse_factorial(r) * inverse_factorial(n - r);
}

ll factorial(int n) {
    static ll fact[MAXV] = {1};
    if (fact[n] == 0) {
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
    }
    return fact[n];
}

ll inverse_factorial(int n) {
    static ll finv[MAXV] = {1};
    if (finv[n] == 0) {
        finv[n] = mod_inverse(factorial(n));
    }
    return finv[n];
}

ll mod_inverse(ll a) {
    ll m = MOD, m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

int main() {
    sieve_init();

    int N, K, Q;
    scanf("%d %d %d", &N, &K, &Q);
    int a[N], q[Q];
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    for (int i = 0; i < Q; i++) scanf("%d", &q[i]);

    ll coeff[MAXV] = {0};
    for (int g = 1; g < MAXV; g++) {
        for (int m = g, c = 1; m < MAXV; m += g, c++) {
            coeff[m] += g * sv.nums[c].mu;
        }
    }

    ll ans = 0;
    int ct[MAXV] = {0};

    for (int i = 0; i < N; i++) ct[a[i]]++;
    for (int g = 1; g < MAXV; g++) {
        for (int m = 2 * g; m < MAXV; m += g)
            ct[g] += ct[m];
        ans += coeff[g] * ncr(ct[g], K);
    }

    for (int i = 0; i < Q; i++) {
        intro(q[i], &ans, coeff, ct);
        printf("%lld\n", ans);
    }

    return 0;
}
