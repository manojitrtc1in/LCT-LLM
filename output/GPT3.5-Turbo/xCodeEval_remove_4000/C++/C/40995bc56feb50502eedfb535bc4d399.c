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

num nums[MAXV];
int primes[MAXV];
int prime_count = 0;

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
            primes[prime_count++] = v;
        }
        for (int i = 0; i < prime_count; i++) {
            int p = primes[i];
            if (p > n->least_prime || v * p >= MAXV) break;
            num* np = &nums[v * p];
            np->least_prime = p;
            np->div_least_prime = v;
            np->lp_multiplicity = n->lp_multiplicity + 1;
            np->mu = 0;
            np->phi = n->phi * p;
        }
    }
}

bool is_prime(int v) {
    return nums[v].least_prime == v;
}

int eliminate_least_prime(int v) {
    while (nums[v].lp_multiplicity > 0) {
        v = nums[v].div_least_prime;
        nums[v].lp_multiplicity--;
    }
    return v;
}

void factor(int v, int* factors, int* factor_count) {
    *factor_count = 0;
    while (v > 1) {
        int least_prime = nums[v].least_prime;
        int lp_multiplicity = nums[v].lp_multiplicity;
        factors[*factor_count] = least_prime;
        factor_count++;
        v = eliminate_least_prime(v);
    }
}

void id0(int v, void (*f)(int), int c) {
    if (v == 1) {
        f(c);
        return;
    }
    int w = eliminate_least_prime(v);
    for (int m = 0; m <= nums[v].lp_multiplicity; m++, c *= nums[v].least_prime) {
        id0(w, f, c);
    }
}

void unordered_divisors(int v, int* divisors, int* divisor_count) {
    *divisor_count = 0;
    id0(v, ^(int d) {
        divisors[*divisor_count] = d;
        (*divisor_count)++;
    }, 1);
}

typedef struct {
    int v;
} modnum;

modnum modnum_init(int v) {
    modnum num;
    num.v = v % (int)1e9 + 7;
    if (num.v < 0) {
        num.v += (int)1e9 + 7;
    }
    return num;
}

modnum modnum_add(modnum a, modnum b) {
    a.v += b.v;
    if (a.v >= (int)1e9 + 7) {
        a.v -= (int)1e9 + 7;
    }
    return a;
}

modnum modnum_sub(modnum a, modnum b) {
    a.v -= b.v;
    if (a.v < 0) {
        a.v += (int)1e9 + 7;
    }
    return a;
}

modnum modnum_mul(modnum a, modnum b) {
    a.v = (ll)a.v * b.v % ((int)1e9 + 7);
    return a;
}

modnum modnum_pow(modnum a, int e) {
    modnum res;
    res.v = 1;
    while (e > 0) {
        if (e & 1) {
            res = modnum_mul(res, a);
        }
        a = modnum_mul(a, a);
        e >>= 1;
    }
    return res;
}

modnum modnum_inv(modnum a) {
    return modnum_pow(a, (int)1e9 + 7 - 2);
}

modnum modnum_div(modnum a, modnum b) {
    return modnum_mul(a, modnum_inv(b));
}

modnum modnum_ncr(int n, int r) {
    if (r < 0 || n < r) {
        return modnum_init(0);
    }
    modnum res = modnum_init(1);
    for (int i = 0; i < r; i++) {
        res = modnum_mul(res, modnum_init(n - i));
        res = modnum_div(res, modnum_init(i + 1));
    }
    return res;
}

modnum modnum_factorial(int n) {
    modnum res = modnum_init(1);
    for (int i = 2; i <= n; i++) {
        res = modnum_mul(res, modnum_init(i));
    }
    return res;
}

modnum modnum_inverse_factorial(int n) {
    modnum res = modnum_init(1);
    for (int i = n; i >= 2; i--) {
        res = modnum_mul(res, modnum_inv(modnum_init(i)));
    }
    return res;
}

modnum modnum_small_inv(int n) {
    return modnum_mul(modnum_factorial(n - 1), modnum_inverse_factorial(n));
}

void solve(int N, int K, int Q, int* a, int* q) {
    sieve();

    modnum ans = modnum_init(0);
    int ct[MAXV] = {0};
    modnum coeff[MAXV] = {0};

    for (int i = 0; i < N; i++) {
        ct[a[i]]++;
    }

    for (int g = 1; g < MAXV; g++) {
        for (int m = g, c = 1; m < MAXV; m += g, c++) {
            coeff[m] = modnum_add(coeff[m], modnum_mul(modnum_init(g), modnum_init(nums[c].mu)));
            if (c > 1) {
                ct[g] += ct[m];
            }
        }
        ans = modnum_add(ans, modnum_mul(coeff[g], modnum_ncr(ct[g], K)));
    }

    for (int i = 0; i < Q; i++) {
        int qv = q[i];
        int factors[MAXV];
        int factor_count;
        factor(qv, factors, &factor_count);
        for (int j = 0; j < factor_count; j++) {
            int d = factors[j];
            ans = modnum_add(ans, modnum_mul(coeff[d], modnum_sub(modnum_ncr(ct[d] + 1, K), modnum_ncr(ct[d], K))));
            ct[d]++;
        }
        printf("%lld\n", ans.v);
    }
}

int main() {
    int N, K, Q;
    scanf("%d %d %d", &N, &K, &Q);
    int a[N];
    int q[Q];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &q[i]);
    }
    solve(N, K, Q, a, q);
    return 0;
}
