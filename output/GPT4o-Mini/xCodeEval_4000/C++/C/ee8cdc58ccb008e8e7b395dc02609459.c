#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXMEM (200 * 1000 * 1024)
char _memory[MAXMEM];
size_t _ptr = 0;

void* operator_new(size_t _x) {
    _ptr += _x; 
    assert(_ptr < MAXMEM); 
    return _memory + _ptr - _x; 
}

void operator_delete(void*) noexcept {}

typedef long long ll;

ll MOD = 1e9 + 7;

typedef struct {
    ll value;
} Ring;

Ring create_ring(int _value) {
    Ring r;
    r.value = _value % MOD;
    return r;
}

Ring ring_pow(Ring x, ll p) {
    Ring r = create_ring(1);
    while (p) {
        if (p & 1) {
            r.value = (r.value * x.value) % MOD;
        }
        x.value = (x.value * x.value) % MOD;
        p /= 2;
    }
    return r;
}

Ring ring_inv(Ring x) {
    return ring_pow(x, MOD - 2);
}

Ring ring_mul(Ring a, Ring b) {
    a.value = (a.value * b.value) % MOD;
    return a;
}

Ring ring_add(Ring a, Ring b) {
    a.value = (a.value + b.value) % MOD;
    return a;
}

Ring ring_sub(Ring a, Ring b) {
    a.value = (a.value - b.value + MOD) % MOD;
    return a;
}

Ring ring_div(Ring a, Ring b) {
    return ring_mul(a, ring_inv(b));
}

Ring fact[100010];

void fast_scan(int *x) {
    scanf("%d", x);
}

void fast_print(const ll x) {
    printf("%lld", x);
}

void compute_factorials(int n) {
    fact[0] = create_ring(1);
    for (int i = 1; i <= n + 100; i++) {
        fact[i] = ring_mul(fact[i - 1], create_ring(i));
    }
}

Ring binom(int n, int k) {
    if (k > n) return create_ring(0);
    return ring_div(fact[n], ring_mul(fact[n - k], fact[k]));
}

int main() {
    int n;
    fast_scan(&n);
    compute_factorials(n);

    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fast_scan(&v[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 2; j * j <= v[i]; j++) {
            while (v[i] % j == 0 && (v[i] / j) % j == 0) {
                v[i] /= j;
                v[i] /= j;
            }
        }
    }

    int *cnt = (int *)calloc(100010, sizeof(int));
    for (int i = 0; i < n; i++) {
        cnt[v[i]]++;
    }

    int *c = (int *)malloc(100010 * sizeof(int));
    int c_size = 0;
    for (int i = 0; i < 100010; i++) {
        if (cnt[i] > 0) {
            c[c_size++] = cnt[i];
        }
    }

    Ring *dp = (Ring *)calloc(n + 10, sizeof(Ring));
    dp[0] = create_ring(1);

    for (int x = 0; x < c_size; x++) {
        Ring *ndp = (Ring *)calloc(n + 10, sizeof(Ring));
        for (int i = 0; i < n + 10; i++) {
            if (dp[i].value) {
                for (int j = 0; j < c[x]; j++) {
                    int dist = c[x] - j;
                    ndp[i + dist] = ring_add(ndp[i + dist], ring_mul(dp[i], binom(c[x] - 1, j)));
                }
            }
        }
        free(dp);
        dp = ndp;
    }

    int conds = n - c_size;
    Ring final = create_ring(0);
    Ring sign = create_ring(1);

    for (int i = 0; i <= conds; i++) {
        final = ring_add(final, ring_mul(sign, dp[n - i]));
        sign = ring_mul(create_ring(-1), sign);
    }

    for (int x = 0; x < c_size; x++) {
        final = ring_mul(final, fact[c[x]]);
    }

    fast_print(final.value);

    free(v);
    free(cnt);
    free(c);
    free(dp);
    return 0;
}
