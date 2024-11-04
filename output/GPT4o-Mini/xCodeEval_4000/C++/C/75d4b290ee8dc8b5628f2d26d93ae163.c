#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MOD7 1000000007
#define MOD9 1000000009
#define MODF 998244353

int mod = MOD7;

typedef struct {
    int *data;
    size_t size;
} Vector;

Vector create_vector(size_t size) {
    Vector vec;
    vec.data = (int *)malloc(size * sizeof(int));
    vec.size = size;
    return vec;
}

void free_vector(Vector *vec) {
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
}

typedef struct {
    int n;
} modint;

modint create_modint(long long n) {
    modint m;
    if (n >= 0 && n < mod) {
        m.n = n;
        return m;
    }
    n %= mod;
    if (n < 0) {
        n += mod;
    }
    m.n = n;
    return m;
}

modint modint_add(modint a, modint b) {
    return create_modint(a.n + b.n);
}

modint modint_sub(modint a, modint b) {
    return create_modint(a.n - b.n);
}

modint modint_mul(modint a, modint b) {
    return create_modint((long long)a.n * b.n % mod);
}

modint modint_div(modint a, modint b) {
    // Division by zero check omitted for brevity
    return modint_mul(a, modint_inverse(b));
}

modint modint_inverse(modint a) {
    long long x, y;
    long long g = gcd(a.n, mod, &x, &y);
    return create_modint(x);
}

int gcd(int a, int b, long long *x, long long *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int d = gcd(b % a, a, y, x);
    *y -= (b / a) * (*x);
    return d;
}

typedef struct {
    int type;
    int at;
    int dx;
    int v;
} Event;

int compare_events(const void *a, const void *b) {
    Event *eventA = (Event *)a;
    Event *eventB = (Event *)b;
    return (long long)eventA->dx * eventB->v < (long long)eventB->dx * eventA->v;
}

void solve() {
    int n;
    scanf("%d", &n);
    
    Vector x = create_vector(n);
    Vector v = create_vector(n);
    Vector p = create_vector(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x.data[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &v.data[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &p.data[i]);
    }

    mod = MODF;
    Vector pp[4 * n];
    Vector tmp[4 * n];
    bool allowed[n][4];
    memset(allowed, true, sizeof(allowed));

    // Initialize pp and tmp vectors
    for (int i = 0; i < 4 * n; i++) {
        pp[i] = create_vector(4);
        tmp[i] = create_vector(4);
    }

    // Initialize function
    void init(int root, int left, int right) {
        // Implementation omitted for brevity
    }

    init(0, 0, n);

    Event events[2 * n];
    int event_count = 0;

    for (int i = 1; i < n; i++) {
        events[event_count++] = (Event){2, i, x.data[i] - x.data[i - 1], v.data[i] + v.data[i - 1]};
        if (v.data[i] > v.data[i - 1]) {
            events[event_count++] = (Event){0, i, x.data[i] - x.data[i - 1], v.data[i] - v.data[i - 1]};
        } else if (v.data[i] < v.data[i - 1]) {
            events[event_count++] = (Event){3, i, x.data[i] - x.data[i - 1], v.data[i - 1] - v.data[i]};
        }
    }

    qsort(events, event_count, sizeof(Event), compare_events);

    modint answer = create_modint(0);
    for (int i = 0; i < event_count; i++) {
        // Query and recalculate logic omitted for brevity
    }

    printf("%d\n", answer.n);

    // Free allocated memory
    free_vector(&x);
    free_vector(&v);
    free_vector(&p);
    for (int i = 0; i < 4 * n; i++) {
        free_vector(&pp[i]);
        free_vector(&tmp[i]);
    }
}

int main() {
    solve();
    return 0;
}
