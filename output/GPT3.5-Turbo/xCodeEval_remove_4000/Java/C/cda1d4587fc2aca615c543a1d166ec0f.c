#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 998244353
#define MAXN 5000

typedef struct {
    int m;
} Modular;

Modular new_Modular(int m) {
    Modular mod;
    mod.m = m;
    return mod;
}

int valueOf(Modular mod, int x) {
    x %= mod.m;
    if (x < 0) {
        x += mod.m;
    }
    return x;
}

int mul(Modular mod, int x, int y) {
    return valueOf(mod, (long long)x * y);
}

int plus(Modular mod, int x, int y) {
    return valueOf(mod, x + y);
}

Modular id3(Modular mod) {
    return new_Modular(mod.m - 1);
}

typedef struct {
    int *fact;
    int *inv;
    Modular modular;
} Factorial;

Factorial new_Factorial(int limit, Modular modular) {
    Factorial factorial;
    factorial.fact = (int *)malloc((limit + 1) * sizeof(int));
    factorial.inv = (int *)malloc((limit + 1) * sizeof(int));
    factorial.modular = modular;
    factorial.fact[0] = factorial.inv[0] = 1;
    for (int i = 1; i <= limit; i++) {
        factorial.fact[i] = mul(modular, factorial.fact[i - 1], i);
        factorial.inv[i] = mul(modular, factorial.inv[i - 1], -limit / i);
    }
    return factorial;
}

int fact(Factorial factorial, int n) {
    return factorial.fact[n];
}

int invFact(Factorial factorial, int n) {
    return factorial.inv[n];
}

typedef struct {
    Factorial factorial;
    Modular modular;
} Composite;

Composite new_Composite(int limit, Modular modular) {
    Composite composite;
    composite.factorial = new_Factorial(limit, modular);
    composite.modular = modular;
    return composite;
}

int composite(Composite composite, int m, int n) {
    if (n > m) {
        return 0;
    }
    return mul(composite.modular, mul(composite.modular, fact(composite.factorial, m), invFact(composite.factorial, n)), invFact(composite.factorial, m - n));
}

typedef struct {
    int *data;
    int size;
    int cap;
} IntegerList;

IntegerList new_IntegerList(int cap) {
    IntegerList list;
    list.data = (int *)malloc(cap * sizeof(int));
    list.size = 0;
    list.cap = cap;
    return list;
}

void remove(IntegerList *list, int l, int r) {
    if (l > r) {
        return;
    }
    if (r == list->size - 1) {
        list->size = l;
        return;
    } else {
        for (int i = r + 1; i < list->size; i++) {
            list->data[l + i - r - 1] = list->data[i];
        }
        list->size -= (r - l + 1);
    }
}

void ensureSpace(IntegerList *list, int req) {
    if (req > list->cap) {
        while (list->cap < req) {
            list->cap = fmax(list->cap + 10, 2 * list->cap);
        }
        list->data = (int *)realloc(list->data, list->cap * sizeof(int));
    }
}

int get(IntegerList *list, int i) {
    return list->data[i];
}

void add(IntegerList *list, int x) {
    ensureSpace(list, list->size + 1);
    list->data[list->size++] = x;
}

void addAll(IntegerList *list, int *x, int offset, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size + i] = x[offset + i];
    }
    list->size += len;
}

void addAll_IntegerList(IntegerList *list, IntegerList *other) {
    addAll(list, other->data, 0, other->size);
}

void expandWith(IntegerList *list, int x, int len) {
    ensureSpace(list, len);
    for (int i = 0; i < len; i++) {
        list->data[list->size + i] = x;
    }
    list->size += len;
}

void set(IntegerList *list, int i, int x) {
    list->data[i] = x;
}

int size(IntegerList *list) {
    return list->size;
}

int *toArray(IntegerList *list) {
    int *arr = (int *)malloc(list->size * sizeof(int));
    for (int i = 0; i < list->size; i++) {
        arr[i] = list->data[i];
    }
    return arr;
}

void clear(IntegerList *list) {
    list->size = 0;
}

typedef struct {
    double **realLevels;
    double **imgLevels;
} id10;

id10 new_id10() {
    id10 id;
    id.realLevels = (double **)malloc(30 * sizeof(double *));
    id.imgLevels = (double **)malloc(30 * sizeof(double *));
    for (int i = 0; i < 30; i++) {
        id.realLevels[i] = NULL;
        id.imgLevels[i] = NULL;
    }
    return id;
}

void prepareLevel(id10 *id, int i) {
    if (id->realLevels[i] == NULL) {
        id->realLevels[i] = (double *)malloc((1 << i) * sizeof(double));
        id->imgLevels[i] = (double *)malloc((1 << i) * sizeof(double));
        for (int j = 0, s = 1 << i; j < s; j++) {
            id->realLevels[i][j] = cos(M_PI / s * j);
            id->imgLevels[i][j] = sin(M_PI / s * j);
        }
    }
}

void dft(id10 *id, double **p, int m) {
    int n = 1 << m;

    int shift = 32 - __builtin_ctz(n);
    for (int i = 1; i < n; i++) {
        int j = __builtin_bitreverse(i << shift);
        if (i < j) {
            double tmp = (*p)[i];
            (*p)[i] = (*p)[j];
            (*p)[j] = tmp;
        }
    }

    double *t = (double *)malloc(2 * sizeof(double));
    for (int d = 0; d < m; d++) {
        int s = 1 << d;
        int s2 = s << 1;
        prepareLevel(id, d);
        for (int i = 0; i < n; i += s2) {
            for (int j = 0; j < s; j++) {
                int a = i + j;
                int b = a + s;
                double r1 = id->realLevels[d][j];
                double i1 = id->imgLevels[d][j];
                double r2 = (*p)[b];
                double i2 = (*p)[b + 1];
                double r = r1 * r2 - i1 * i2;
                double i = r1 * i2 + i1 * r2;
                (*p)[b] = (*p)[a] - r;
                (*p)[b + 1] = (*p)[a + 1] - i;
                (*p)[a] += r;
                (*p)[a + 1] += i;
            }
        }
    }
    free(t);
}

void idft(id10 *id, double **p, int m) {
    dft(id, p, m);

    int n = 1 << m;
    double invN = 1.0 / n;
    for (int i = 0; i < n; i++) {
        (*p)[i] *= invN;
    }
}

void add(double r1, double i1, double r2, double i2, double **r, int i) {
    (*r)[2 * i] = r1 + r2;
    (*r)[2 * i + 1] = i1 + i2;
}

void sub(double r1, double i1, double r2, double i2, double **r, int i) {
    (*r)[2 * i] = r1 - r2;
    (*r)[2 * i + 1] = i1 - i2;
}

void mul(double r1, double i1, double r2, double i2, double **r, int i) {
    (*r)[2 * i] = r1 * r2 - i1 * i2;
    (*r)[2 * i + 1] = r1 * i2 + i1 * r2;
}

void div(double r1, double i1, double r2, double **r, int i) {
    (*r)[2 * i] = r1 / r2;
    (*r)[2 * i + 1] = i1 / r2;
}

int *multiplyMod(int *a, int aLen, int *b, int bLen, int m) {
    int need = aLen + bLen - 1;
    int n = 1 << (int)ceil(log2(need));

    double *aReal = (double *)malloc(n * sizeof(double));
    double *aImag = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < aLen; i++) {
        int x = (a[i] % m + m) % m;
        aReal[i] = x & ((1 << 15) - 1);
        aImag[i] = x >> 15;
    }
    dft(&id, &aReal, (int)floor(log2(n)));
    dft(&id, &aImag, (int)floor(log2(n)));

    double *bReal = (double *)malloc(n * sizeof(double));
    double *bImag = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < bLen; i++) {
        int x = (b[i] % m + m) % m;
        bReal[i] = x & ((1 << 15) - 1);
        bImag[i] = x >> 15;
    }
    dft(&id, &bReal, (int)floor(log2(n)));
    dft(&id, &bImag, (int)floor(log2(n)));

    double *faReal = (double *)malloc(n * sizeof(double));
    double *faImag = (double *)malloc(n * sizeof(double));
    double *fbReal = (double *)malloc(n * sizeof(double));
    double *fbImag = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        int j = (n - i) & (n - 1);

        double id6 = (aReal[i] + aReal[j]) / 2;
        double id5 = (aImag[i] - aImag[j]) / 2;
        double id4 = (aImag[i] + aImag[j]) / 2;
        double id12 = (aReal[j] - aReal[i]) / 2;

        double id0 = (bReal[i] + bReal[j]) / 2;
        double id7 = (bImag[i] - bImag[j]) / 2;
        double id13 = (bImag[i] + bImag[j]) / 2;
        double id9 = (bReal[j] - bReal[i]) / 2;

        faReal[i] = id6 * id0 - id5 * id7 - id4 * id9 - id12 * id13;
        faImag[i] = id6 * id7 + id5 * id0 + id4 * id13 - id12 * id9;

        fbReal[i] = id6 * id13 - id5 * id9 + id4 * id0 - id12 * id7;
        fbImag[i] = id6 * id9 + id5 * id13 + id4 * id7 + id12 * id0;
    }

    idft(&id, &faReal, (int)floor(log2(n)));
    idft(&id, &faImag, (int)floor(log2(n)));
    idft(&id, &fbReal, (int)floor(log2(n)));
    idft(&id, &fbImag, (int)floor(log2(n)));

    int *res = (int *)malloc(need * sizeof(int));
    for (int i = 0; i < need; i++) {
        long long aa = (long long)(faReal[i] + 0.5);
        long long bb = (long long)(fbReal[i] + 0.5);
        long long cc = (long long)(faImag[i] + 0.5);
        res[i] = ((aa % m + ((bb % m) << 15) + ((cc % m) << 30)) % m + m) % m;
    }
    return res;
}

typedef struct {
    int n;
    int m;
    int k;
    Composite comp;
    Modular mod;
} FCards;

FCards new_FCards(int n, int m, int k, Composite comp, Modular mod) {
    FCards fc;
    fc.n = n;
    fc.m = m;
    fc.k = k;
    fc.comp = comp;
    fc.mod = mod;
    return fc;
}

int get(FCards *fc, int i) {
    return get(&fc->comp.factorial.fact, i);
}

void mul(IntegerList *a, IntegerList *b, IntegerList *c, Modular mod) {
    int rA = size(a) - 1;
    int rB = size(b) - 1;
    clear(c);
    expandWith(c, 0, rA + rB + 1);
    if (rA >= 64 && rB >= 64) {
        int *ans = multiplyMod(a->data, rA + 1, b->data, rB + 1, mod.m);
        clear(c);
        addAll(c, ans, 0, rA + rB + 1);
        free(ans);
        return;
    }
    for (int i = 0; i <= rA; i++) {
        for (int j = 0; j <= rB; j++) {
            c->data[i + j] = plus(mod, c->data[i + j], mul(mod, a->data[i], b->data[j]));
        }
    }
}

void trim(IntegerList *x) {
    if (size(x) > MAXN + 1) {
        remove(x, MAXN + 1, size(x) - 1);
    }
}

void mul(IntegerList *p, IntegerList *ans) {
    clear(ans);
    expandWith(ans, 0, size(p) + 1);

    int n = size(p);
    for (int i = 0; i < n; i++) {
        int val = p->data[i];
        ans->data[i] = plus(ans->data[i], val);
        ans->data[i + 1] = val;
    }

    trim(ans);
}

IntegerList pow(long long exp) {
    int ceil = (int)ceil(log2(MAXN + 1 + MAXN));
    IntegerList loop[2];
    loop[0] = new_IntegerList(1 << ceil);
    loop[1] = new_IntegerList(1 << ceil);
    add(&loop[0], 1);
    for (int i = (int)floor(log2(exp)); i >= 0; i--) {
        mul(&loop[0], &loop[0], &loop[1], mod);
        if (exp & (1LL << i)) {
            mul(&loop[0], &loop[1]);
        }
    }
    return loop[0];
}

void solve(FCards *fc, int testNumber, int n, int m, int k, int *xk, int *ans) {
    int id8[5001];
    for (int i = 0; i <= k; i++) {
        id8[i] = pow(i, k);
    }

    int res = 0;
    int bc[5001];
    for (int t = 0; t <= k; t++) {
        bc[t] = get(fc, t);
    }
    for (int t = 0; t <= k; t++) {
        int p1 = bc[t];
        int p2 = 0;
        for (int i = 0; i <= t; i++) {
            int contrib = composite(fc->comp, t, i);
            contrib = mul(fc->mod, contrib, xk[t - i]);
            if (i % 2 == 1) {
                contrib = valueOf(fc->mod, -contrib);
            }
            p2 = plus(fc->mod, p2, contrib);
        }
        int p3 = fc->mod.m - t;

        int contrib = mul(fc->mod, p1, p2);
        contrib = mul(fc->mod, contrib, p3);
        res = plus(fc->mod, res, contrib);
    }

    *ans = res;
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    Modular mod = new_Modular(MOD);
    Composite comp = new_Composite(MAXN, mod);
    FCards fc = new_FCards(n, m, k, comp, mod);

    int xk[5001];
    for (int i = 0; i <= k; i++) {
        xk[i] = pow(i, k);
    }

    int ans;
    solve(&fc, 1, n, m, k, xk, &ans);

    printf("%d\n", ans);

    return 0;
}
