#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

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
            sv.nums[v * p] = (num){p, v, n->lp_multiplicity + 1, 0, n->phi * p};
        }
    }
}

bool is_prime(int v) {
    return sv.nums[v].least_prime == v;
}

int eliminate_least_prime(int v) {
    for (int m = sv.nums[v].lp_multiplicity; m > 0; m--) {
        v = sv.nums[v].div_least_prime;
    }
    return v;
}

void factor(int v, int* factors, int* multiplicities, int* count) {
    *count = 0;
    while (v > 1) {
        factors[*count] = sv.nums[v].least_prime;
        multiplicities[*count] = sv.nums[v].lp_multiplicity;
        (*count)++;
        v = eliminate_least_prime(v);
    }
}

ll modnum_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

ll ncr(int n, int r) {
    if (r < 0 || n < r) return 0;
    ll numerator = 1, denominator = 1;
    for (int i = 0; i < r; i++) {
        numerator = (numerator * (n - i)) % MOD;
        denominator = (denominator * (i + 1)) % MOD;
    }
    return (numerator * modnum_pow(denominator, MOD - 2)) % MOD;
}

int main() {
    sieve_init();

    int N, K, Q;
    scanf("%d %d %d", &N, &K, &Q);
    int a[N], q[Q];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &q[i]);
    }

    ll coeff[MAXV] = {0};
    for (int g = 1; g < MAXV; g++) {
        for (int m = g, c = 1; m < MAXV; m += g, c++) {
            coeff[m] += g * sv.nums[c].mu;
        }
    }

    ll ans = 0;
    int ct[MAXV] = {0};

    void intro(int v) {
        int factors[MAXV], multiplicities[MAXV], count;
        factor(v, factors, multiplicities, &count);
        for (int i = 0; i < count; i++) {
            ans += coeff[factors[i]] * (ncr(ct[factors[i]] + 1, K) - ncr(ct[factors[i]], K));
            ct[factors[i]]++;
        }
    }

    for (int i = 0; i < N; i++) {
        intro(a[i]);
    }

    for (int i = 0; i < Q; i++) {
        intro(q[i]);
        printf("%lld\n", ans);
    }

    return 0;
}
