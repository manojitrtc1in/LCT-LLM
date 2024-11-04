#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAXV 1000001

typedef long long ll;

typedef struct {
    int least_prime;
    int div_least_prime;
    char lp_multiplicity;
    char mu;
    int phi;
} num;

int primes[MAXV];
num nums[MAXV];

void sieve() {
    nums[1].least_prime = INT_MAX;
    nums[1].div_least_prime = 1;
    nums[1].lp_multiplicity = 0;
    nums[1].mu = 1;
    nums[1].phi = 1;

    for (int v = 2; v < MAXV; v++) {
        num* n = &nums[v];
        if (n->least_prime == 0) {
            n->least_prime = v;
            n->div_least_prime = 1;
            n->lp_multiplicity = 1;
            n->mu = -1;
            n->phi = v - 1;
            primes[v] = v;
        }
        for (int i = 0; i < MAXV; i++) {
            int p = primes[i];
            if (p > n->least_prime || v * p >= MAXV) break;
            num* np = &nums[v * p];
            np->least_prime = p;
            np->div_least_prime = v;
            np->lp_multiplicity = 1;
            np->mu = 0;
            np->phi = n->phi * p;
        }
    }
}

bool is_prime(int v) {
    return nums[v].least_prime == v;
}

int eliminate_least_prime(int v) {
    while (v > 1) {
        num* n = &nums[v];
        for (int m = n->lp_multiplicity; m > 0; m--) {
            v = n->div_least_prime;
        }
    }
    return v;
}

void factor(int v, int* res, int* res_size) {
    *res_size = 0;
    while (v > 1) {
        num* n = &nums[v];
        res[*res_size] = n->least_prime;
        (*res_size)++;
        v = eliminate_least_prime(v);
    }
}

void for_each_divisor_unordered(int v, void (*f)(int), int c) {
    if (v == 1) {
        f(c);
        return;
    }
    int w = eliminate_least_prime(v);
    for (int m = 0; m <= nums[v].lp_multiplicity; m++, c *= nums[v].least_prime) {
        for_each_divisor_unordered(w, f, c);
    }
}

void unordered_divisors(int v, int* res, int* res_size) {
    *res_size = 0;
    for_each_divisor_unordered(v, f, c) {
        res[*res_size] = d;
        (*res_size)++;
    }
}

ll ncr(int n, int r) {
    if (r < 0 || n < r) return 0;
    ll res = 1;
    for (int i = 1; i <= r; i++) {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

ll pow_mod(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    int N, K, Q;
    scanf("%d %d %d", &N, &K, &Q);
    int* a = (int*)malloc(N * sizeof(int));
    int* q = (int*)malloc(Q * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &q[i]);
    }

    ll ans = 0;
    int* ct = (int*)calloc(MAXV, sizeof(int));
    ll* coeff = (ll*)calloc(MAXV, sizeof(ll));

    sieve();

    for (int i = 0; i < N; i++) {
        ct[a[i]]++;
    }

    for (int g = 1; g < MAXV; g++) {
        for (int m = g, c = 1; m < MAXV; m += g, c++) {
            coeff[m] += g * nums[c].mu;
            if (c > 1) ct[g] += ct[m];
        }
        ans += coeff[g] * ncr(ct[g], K);
    }

    for (int i = 0; i < Q; i++) {
        int qv = q[i];
        int* factors = (int*)malloc(MAXV * sizeof(int));
        int factors_size;
        factor(qv, factors, &factors_size);
        for (int j = 0; j < factors_size; j++) {
            int d = factors[j];
            ans += coeff[d] * (ncr(ct[d] + 1, K) - ncr(ct[d], K));
            ct[d]++;
        }
        free(factors);
        printf("%lld\n", ans);
    }

    free(a);
    free(q);
    free(ct);
    free(coeff);

    return 0;
}
