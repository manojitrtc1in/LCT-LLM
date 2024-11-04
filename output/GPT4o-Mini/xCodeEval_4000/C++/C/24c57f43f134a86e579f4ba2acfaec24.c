#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define MAXV 1000001
#define pb push_back
#define sz(x) ((int)(x).size())

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
        num *n = &sv.nums[v];
        if (!n->least_prime) {
            *n = sv.nums[1];
            n->least_prime = v;
            sv.primes[sv.prime_count++] = v;
        }
        for (int i = 0; i < sv.prime_count; i++) {
            int p = sv.primes[i];
            if (p > n->least_prime || v * p >= MAXV) break;
            sv.nums[v * p] = (num){p, n->div_least_prime, n->lp_multiplicity + 1, 0, n->phi * p};
        }
    }
}

int eliminate_least_prime(int v) {
    assert(1 < v && v < MAXV);
    for (int m = sv.nums[v].lp_multiplicity; m > 0; m--)
        v = sv.nums[v].div_least_prime;
    return v;
}

void for_each_divisor_unordered(int v, void (*f)(int), int c) {
    assert(0 < v && v < MAXV);
    if (v == 1) { f(c); return; }
    int w = eliminate_least_prime(v);
    for (int m = 0; m <= sv.nums[v].lp_multiplicity; m++, c *= sv.nums[v].least_prime)
        for_each_divisor_unordered(w, f, c);
}

void intro(int v, ll *ans, ll *coeff, int *ct, int K) {
    for_each_divisor_unordered(v, [&](int d) {
        *ans += coeff[d] * (ncr(ct[d] + 1, K) - ncr(ct[d], K));
        ct[d]++;
    }, 1);
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

    for (int i = 0; i < N; i++) intro(a[i], &ans, coeff, ct, K);

    for (int i = 0; i < Q; i++) {
        intro(q[i], &ans, coeff, ct, K);
        printf("%lld\n", ans);
    }

    return 0;
}
