#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXMEM 200 * 1000 * 1024
char _memory[MAXMEM];
size_t _ptr = 0;

void* operator new(size_t _x) {
    _ptr += _x;
    assert(_ptr < MAXMEM);
    return _memory + _ptr - _x;
}

void operator delete(void*) noexcept {}

typedef struct {
    int value;
} Ring;

Ring Ring_init() {
    Ring r;
    r.value = 0;
    return r;
}

Ring Ring_int(int _value) {
    Ring r;
    r.value = _value;
    return r;
}

Ring Ring_ll(long long _value) {
    Ring r;
    r.value = _value;
    return r;
}

Ring Ring_pow(Ring x, long long p) {
    Ring r = Ring_int(1);
    while (p) {
        if (p & 1) {
            r = Ring_mul(r, x);
        }
        x = Ring_mul(x, x);
        p /= 2;
    }
    return r;
}

Ring Ring_inv(Ring r) {
    return Ring_pow(r, MOD - 2);
}

Ring Ring_mul(Ring a, Ring b) {
    a.value *= b.value;
    a.value %= MOD;
    return a;
}

Ring Ring_add(Ring a, Ring b) {
    a.value += b.value;
    if (a.value >= MOD) {
        a.value -= MOD;
    }
    return a;
}

Ring Ring_sub(Ring a, Ring b) {
    a.value -= b.value;
    if (a.value < 0) {
        a.value += MOD;
    }
    return a;
}

Ring Ring_div(Ring a, Ring b) {
    a = Ring_mul(a, Ring_inv(b));
    return a;
}

int floor_mod(int a, int b) {
    a %= b;
    if (a < 0) {
        a += b;
    }
    return a;
}

Ring binom(int n, int k) {
    if (k > n) {
        return Ring_int(0);
    }
    Ring result = Ring_div(fact[n], Ring_mul(fact[n - k], fact[k]));
    return result;
}

Ring fact[110];

void init_fact() {
    fact[0] = Ring_int(1);
    for (int i = 1; i < 110; i++) {
        fact[i] = Ring_mul(fact[i - 1], Ring_int(i));
    }
}

void fast_scan_int(int* x) {
    scanf("%d", x);
}

void fast_scan_ll(long long* x) {
    scanf("%lld", x);
}

void fast_scan_string(char* x) {
    scanf("%s", x);
}

void fast_print_int(int x) {
    printf("%d", x);
}

void fast_print_ll(long long x) {
    printf("%lld", x);
}

void fast_print_string(char* x) {
    printf("%s", x);
}

void fast_print(Ring b) {
    fast_print_ll(b.value);
}

int main(int argc, char* argv[]) {
    init_fact();

    int n;
    fast_scan_int(&n);

    int* v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fast_scan_int(&v[i]);
    }

    int* cnt = (int*)calloc(100, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x = v[i];
        for (int j = 2; j * j <= x; j++) {
            while (x % j == 0 && (x / j) % j == 0) {
                x /= j;
                x /= j;
            }
        }
        cnt[x]++;
    }

    int* c = (int*)malloc(n * sizeof(int));
    int c_size = 0;
    for (int i = 0; i < 100; i++) {
        if (cnt[i] > 0) {
            c[c_size++] = cnt[i];
        }
    }

    Ring* dp = (Ring*)calloc(n + 10, sizeof(Ring));
    dp[0] = Ring_int(1);
    for (int i = 0; i < c_size; i++) {
        Ring* ndp = (Ring*)calloc(n + 10, sizeof(Ring));
        for (int j = 0; j < n + 10; j++) {
            if (dp[j].value) {
                for (int k = 0; k < c[i]; k++) {
                    int dist = c[i] - k;
                    ndp[j + dist] = Ring_add(ndp[j + dist], Ring_mul(Ring_mul(dp[j], binom(c[i] - 1, k)), binom(j + dist, dist)));
                }
            }
        }
        free(dp);
        dp = ndp;
    }

    int conds = n - c_size;

    Ring final = Ring_int(0);
    Ring sign = Ring_int(1);
    for (int i = 0; i <= conds; i++) {
        final = Ring_add(final, Ring_mul(sign, dp[n - i]));
        sign = Ring_mul(Ring_int(-1), sign);
    }
    for (int i = 0; i < c_size; i++) {
        final = Ring_mul(final, fact[c[i]]);
    }

    fast_print(final);
    printf("\n");

    free(v);
    free(cnt);
    free(c);
    free(dp);

    return 0;
}
