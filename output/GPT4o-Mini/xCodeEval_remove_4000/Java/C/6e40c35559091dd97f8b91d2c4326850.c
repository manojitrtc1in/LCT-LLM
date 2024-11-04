#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define ITEMS 200

typedef struct {
    int *data;
    int size;
    int cap;
} IntegerList;

typedef struct {
    int m;
} Modular;

typedef struct {
    Modular mod;
} Power;

typedef struct {
    IntegerList coe;
    IntegerList p;
    IntegerList remainder;
    Power pow;
    int n;
} id9;

void IntegerList_init(IntegerList *list, int cap) {
    list->cap = cap;
    list->size = 0;
    list->data = (int *)malloc(cap * sizeof(int));
}

void IntegerList_add(IntegerList *list, int x) {
    if (list->size >= list->cap) {
        list->cap *= 2;
        list->data = (int *)realloc(list->data, list->cap * sizeof(int));
    }
    list->data[list->size++] = x;
}

void IntegerList_clear(IntegerList *list) {
    list->size = 0;
}

void Modular_init(Modular *mod, int m) {
    mod->m = m;
}

int Modular_valueOf(Modular *mod, int x) {
    x %= mod->m;
    if (x < 0) {
        x += mod->m;
    }
    return x;
}

int Modular_plus(Modular *mod, int x, int y) {
    return Modular_valueOf(mod, x + y);
}

int Modular_mul(Modular *mod, int x, int y) {
    return Modular_valueOf(mod, (long long)x * y);
}

void Power_init(Power *pow, Modular mod) {
    pow->mod = mod;
}

int Power_pow(Power *pow, int x, int n) {
    if (n == 0) return Modular_valueOf(&pow->mod, 1);
    long long r = Power_pow(pow, x, n >> 1);
    r = Modular_valueOf(&pow->mod, r * r);
    if (n & 1) r = Modular_valueOf(&pow->mod, r * x);
    return (int)r;
}

void id9_init(id9 *solver, IntegerList coe, Modular mod) {
    solver->coe = coe;
    solver->mod = mod;
    solver->n = coe.size;
    solver->remainder = (IntegerList){0};
    IntegerList_init(&solver->p, coe.size + 1);
    for (int i = solver->n - 1; i >= 0; i--) {
        IntegerList_add(&solver->p, Modular_valueOf(&mod, -coe.data[i]));
    }
    IntegerList_add(&solver->p, 1);
}

int id9_solve(id9 *solver, long k, IntegerList a) {
    if (k < a.size) {
        return a.data[(int)k];
    }
    // Placeholder for polynomial module logic
    return 0; // Replace with actual logic
}

void solve(long n, int k) {
    Modular mod;
    Modular_init(&mod, MOD);
    Power power;
    Power_init(&power, mod);

    int fib[ITEMS] = {1, 2};
    int a[ITEMS] = {0};
    for (int i = 2; i < ITEMS; i++) {
        fib[i] = Modular_plus(&mod, fib[i - 1], fib[i - 2]);
    }
    for (int i = 0; i < ITEMS; i++) {
        a[i] = Modular_mul(&mod, fib[i], Power_pow(&power, i + 1, k));
        if (i > 0) {
            a[i] = Modular_plus(&mod, a[i], a[i - 1]);
        }
    }

    IntegerList seq;
    IntegerList_init(&seq, ITEMS);
    for (int i = 0; i < ITEMS; i++) {
        IntegerList_add(&seq, a[i]);
    }

    id9 solver;
    id9_init(&solver, seq, mod);
    int ans = id9_solve(&solver, n - 1, seq);

    printf("%d\n", ans);
}

int main() {
    long n;
    int k;
    scanf("%ld %d", &n, &k);
    solve(n, k);
    return 0;
}
