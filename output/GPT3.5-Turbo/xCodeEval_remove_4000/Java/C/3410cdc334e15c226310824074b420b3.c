#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005
#define MOD 998244353

typedef struct {
    int exp;
    int fact;
    int p;
    int pc;
    int *g;
} id17;

typedef struct {
    int *primes;
    int *isComp;
    int primeLength;
} id6;

typedef struct {
    int *fact;
    int *inv;
} Factorial;

typedef struct {
    int *inv;
} InverseNumber;

typedef struct {
    int *cache;
    int size;
} FastIO;

typedef struct {
    int *f;
    int *h;
} Task;

typedef struct {
    FastIO *io;
    int inf;
    int n;
    int m;
    int fW;
    int hW;
    int *inv;
    Task *task;
} id0;

int modular_valueOf(int x, int m) {
    x %= m;
    if (x < 0) {
        x += m;
    }
    return x;
}

int modular_mul(int x, int y, int m) {
    return modular_valueOf((long long)x * y, m);
}

int modular_plus(int x, int y, int m) {
    return modular_valueOf(x + y, m);
}

void id17_init(id17 *id, int p, int pc, int *g) {
    id->p = p;
    id->pc = pc;
    id->g = g;
    id->g[0] = 1;
    id->g[1] = 1;
    for (int i = 2; i <= pc; i++) {
        if (i % p == 0) {
            id->g[i] = id->g[i - 1];
        } else {
            id->g[i] = modular_mul(id->g[i - 1], i, MOD);
        }
    }
}

int id17_fact(id17 *id, long long m) {
    id->fact = 1;
    id->exp = 0;
    while (m > 1) {
        id->exp += m / id->p;
        id->fact = modular_mul(id->fact, id->g[id->pc], MOD);
        id->fact = modular_mul(id->fact, id->g[m % id->pc], MOD);
        m /= id->p;
    }
    return id->fact;
}

int id17_composite(id17 *id, long long m, long long n) {
    int v = id17_fact(id, m);
    int e = id->exp;
    id17_fact(id, n);
    v = modular_mul(v, id->fact, MOD);
    e -= id->exp;
    id17_fact(id, m - n);
    v = modular_mul(v, id->fact, MOD);
    e -= id->exp;
    v = modular_mul(v, modular_pow(id->p, e, MOD), MOD);
    return v;
}

void id6_init(id6 *id, int limit) {
    id->isComp = (int *)malloc((limit + 1) * sizeof(int));
    id->primes = (int *)malloc((limit + 1) * sizeof(int));
    id->primeLength = 0;
    memset(id->isComp, 0, (limit + 1) * sizeof(int));
    memset(id->primes, 0, (limit + 1) * sizeof(int));
    for (int i = 2; i <= limit; i++) {
        if (!id->isComp[i]) {
            id->primes[id->primeLength++] = i;
        }
        for (int j = 0, until = limit / i; j < id->primeLength && id->primes[j] <= until; j++) {
            int pi = id->primes[j] * i;
            id->isComp[pi] = 1;
            if (i % id->primes[j] == 0) {
                break;
            }
        }
    }
}

void Factorial_init(Factorial *factorial, InverseNumber *in, int limit) {
    factorial->fact = (int *)malloc((limit + 1) * sizeof(int));
    factorial->inv = (int *)malloc((limit + 1) * sizeof(int));
    memset(factorial->fact, 0, (limit + 1) * sizeof(int));
    memset(factorial->inv, 0, (limit + 1) * sizeof(int));
    factorial->fact[0] = factorial->inv[0] = 1;
    for (int i = 1; i <= limit; i++) {
        factorial->fact[i] = modular_mul(factorial->fact[i - 1], i, MOD);
        factorial->inv[i] = modular_mul(factorial->inv[i - 1], in->inv[i], MOD);
    }
}

void InverseNumber_init(InverseNumber *in, int *inv, int limit) {
    in->inv = inv;
    in->inv[1] = 1;
    int p = MOD;
    for (int i = 2; i <= limit; i++) {
        int k = p / i;
        int r = p % i;
        in->inv[i] = modular_mul(-k, in->inv[r], p);
    }
}

void FastIO_init(FastIO *io, int size) {
    io->cache = (int *)malloc(size * sizeof(int));
    io->size = 0;
}

void FastIO_flush(FastIO *io) {
    for (int i = 0; i < io->size; i++) {
        putchar(io->cache[i]);
    }
    io->size = 0;
}

void FastIO_append(FastIO *io, int x) {
    io->cache[io->size++] = x;
}

void Task_init(Task *task, int m) {
    task->f = (int *)malloc((m + 1) * sizeof(int));
    task->h = (int *)malloc((m + 1) * sizeof(int));
    memset(task->f, -1, (m + 1) * sizeof(int));
    memset(task->h, -1, (m + 1) * sizeof(int));
}

int Task_f(Task *task, int i, int k, int m, int fW, int hW, int *inv) {
    if (task->f[i * (m + 1) + k] == -1) {
        int j = (m - k) - i;
        int fixI = modular_plus(i, fW, MOD);
        int fixJ = modular_plus(hW, -j, MOD);
        task->f[i * (m + 1) + k] = 0;
        int inv_ij_m = inv[i - j + m];
        task->f[i * (m + 1) + k] = modular_plus(task->f[i * (m + 1) + k], modular_mul(modular_mul(modular_plus(fixI, 1, MOD), inv_ij_m, MOD), Task_f(task, i + 1, k - 1, m, fW, hW, inv), MOD), MOD);
        task->f[i * (m + 1) + k] = modular_plus(task->f[i * (m + 1) + k], modular_mul(modular_mul(fixJ, inv_ij_m, MOD), Task_f(task, i, k - 1, m, fW, hW, inv), MOD), MOD);
    }
    return task->f[i * (m + 1) + k];
}

int Task_h(Task *task, int i, int k, int m, int fW, int hW, int *inv) {
    if (task->h[i * (m + 1) + k] == -1) {
        int j = (m - k) - i;
        int fixI = modular_plus(i, fW, MOD);
        int fixJ = modular_plus(hW, -j, MOD);
        task->h[i * (m + 1) + k] = 0;
        int inv_ij_m = inv[i - j + m];
        task->h[i * (m + 1) + k] = modular_plus(task->h[i * (m + 1) + k], modular_mul(modular_mul(modular_plus(fixJ, -1, MOD), inv_ij_m, MOD), Task_h(task, i, k - 1, m, fW, hW, inv), MOD), MOD);
        task->h[i * (m + 1) + k] = modular_plus(task->h[i * (m + 1) + k], modular_mul(modular_mul(fixI, inv_ij_m, MOD), Task_h(task, i + 1, k - 1, m, fW, hW, inv), MOD), MOD);
    }
    return task->h[i * (m + 1) + k];
}

void id0_init(id0 *id, int inf, int n, int m, int fW, int hW, int *inv, Task *task) {
    id->inf = inf;
    id->n = n;
    id->m = m;
    id->fW = fW;
    id->hW = hW;
    id->inv = inv;
    id->task = task;
}

void id0_solve(id0 *id) {
    int n = id->n;
    int m = id->m;
    int fW = id->fW;
    int hW = id->hW;
    int *inv = id->inv;
    Task *task = id->task;
    int *a = (int *)malloc(n * sizeof(int));
    int *count = (int *)malloc(2 * sizeof(int));
    memset(count, 0, 2 * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        count[a[i] % 2]++;
    }
    int *w = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        if (a[i] % 2 == 0) {
            hW += w[i];
        } else {
            fW += w[i];
        }
    }
    for (int i = 0; i <= m; i++) {
        task->f[i] = 1;
        task->h[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            printf("%d\n", modular_mul(w[i], Task_f(task, 0, m, m, fW, hW, inv), MOD));
        } else {
            printf("%d\n", modular_mul(w[i], Task_h(task, 0, m, m, fW, hW, inv), MOD));
        }
    }
}

int main() {
    int inf = 100000000;
    int n, m;
    scanf("%d%d", &n, &m);
    id6 id6;
    id6_init(&id6, inf);
    int *inv = (int *)malloc((m * 2 + 1) * sizeof(int));
    InverseNumber in;
    InverseNumber_init(&in, inv, m * 2);
    Factorial factorial;
    Factorial_init(&factorial, &in, m * 2);
    id17 id17;
    id17_init(&id17, m, m * 2, (int *)malloc((m * 2 + 1) * sizeof(int)));
    id0 id0;
    Task task;
    Task_init(&task, m);
    id0_init(&id0, inf, n, m, 0, 0, inv, &task);
    id0_solve(&id0);
    return 0;
}
